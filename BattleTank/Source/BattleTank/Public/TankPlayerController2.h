// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController2.generated.h" //must be last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController2 : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank* GetControlledTank() const;

	void AimTowardsCrosshair();
	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	
};
