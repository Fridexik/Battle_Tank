// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"
//forward declaration
class UTankBarrel; 
class UTankTurret;

//Hold barrels properties
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void SetBarrelReference(UTankBarrel* BarrelToSet);
	void SetTurretReference(UTankTurret* TurretToSet);
	void MoveBarrel(FVector AimDirection);
	void MoveTurret(FVector AimDirection);
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	void AimAt(FVector HitLocation,float LaunchSpeed);
	

private:
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;
};
