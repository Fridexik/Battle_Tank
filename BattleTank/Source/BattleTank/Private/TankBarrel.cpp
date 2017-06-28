// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"


void UTankBarrel::Elevate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;

	auto RawNewElevationClamped = FMath::Clamp(
		RawNewElevation,
		MinElevationDegree,
		MaxElevationDegree
	);
	
	SetRelativeRotation(FRotator(RawNewElevationClamped,0,0));
}



