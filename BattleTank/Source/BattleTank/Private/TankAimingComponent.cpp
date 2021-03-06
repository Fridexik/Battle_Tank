// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::AimAt(FVector HitLocation,float LaunchSpeed) {

	if (!Barrel) { return; }
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
		//calculate

	if (UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace

	))
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();


		MoveBarrel(AimDirection);
		MoveTurret(AimDirection);
		//UE_LOG(LogTemp, Warning, TEXT("Aiming in direction %s"), *AimDirection.Rotation().ToString());
	}
	else {
		MoveBarrel(FVector(0));
	}
		


}

void  UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet) 
{
	if (!BarrelToSet) { return; }
	Barrel = BarrelToSet;
	
}

void  UTankAimingComponent::SetTurretReference(UTankTurret* TurretToSet)
{
	if (!TurretToSet) { return; }
	Turret = TurretToSet;

}


void UTankAimingComponent::MoveBarrel(FVector AimDirection) {

	//Work-out difference between direction and rotation
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

	

	Barrel->Elevate(DeltaRotator.Pitch);
	
}

void UTankAimingComponent::MoveTurret(FVector AimDirection) {

	//Work-out difference between direction and rotation
	auto TurretRotator = Turret->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - TurretRotator;
	//UE_LOG(LogTemp, Warning, TEXT("test %s"), *DeltaRotator.ToString());
	Turret->Elevate(DeltaRotator.Yaw);
}