// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankPlayerController2.h"



void ATankPlayerController2::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();

	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController2 not possest any BP"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController2  possest %s BP"), *(ControlledTank->GetName()));
	}
}

// Called every frame
void ATankPlayerController2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();

}

ATank* ATankPlayerController2::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


void ATankPlayerController2::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation))
	{
		GetControlledTank()->AimAt(HitLocation);
	}

	

}


bool ATankPlayerController2::GetSightRayHitLocation(FVector& HitLocation) const
{
	//find crossHair in pixel coordinate
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D (ViewportSizeX * CrossHairXLocation , ViewportSizeY * CrossHairYLocation);

	//deproject location
	FVector CameraWorldLocation;
	FVector LookDirection;

	if (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection)) 
	{
		GetLookVectorHitLocation(LookDirection,HitLocation);

	}
	
	return true;
}

bool ATankPlayerController2::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility


	))
	{
		HitLocation = HitResult.Location;
		return true;
	}
	else {
	HitLocation = FVector(0);
}
	return false;

}

