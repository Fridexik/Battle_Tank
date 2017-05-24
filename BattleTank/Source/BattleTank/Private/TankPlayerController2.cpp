// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
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
	UE_LOG(LogTemp, Warning, TEXT("TUDDD"));
	AimTowardsCrosshair();

}

ATank* ATankPlayerController2::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


void ATankPlayerController2::AimTowardsCrosshair()
{
}





