// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	

	
	
}



void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());
	if (PlayerTank) {

		//TODO move towards tank
		
		

		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		ControlledTank->FireAt();

		//TODO Fire when ready
	}
	
	
}



//void ATankAIController::AimToPlayer() {
	//auto PlayerLoc = PlayerTank->GetActorLocation();
	//ControlledTank()->AimAt(PlayerLoc);

//}