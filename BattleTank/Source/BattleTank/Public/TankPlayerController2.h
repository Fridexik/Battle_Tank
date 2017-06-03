// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "GameFramework/PlayerController.h"
#include "TankPlayerController2.generated.h" //must be last include


class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController2 : public APlayerController
{
	GENERATED_BODY()
	
public:
	
	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:
	ATank* GetControlledTank() const;

	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector&) const;

	bool GetLookVectorHitLocation(FVector,FVector&) const;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000;
	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;
	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33333;

	
};
