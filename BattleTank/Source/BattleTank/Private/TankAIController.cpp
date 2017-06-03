// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto PlayerTank = GetPlayerTank();

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("There are no humaN tank to target"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Player tank to aim is: %s"),*(PlayerTank->GetName()));
	}

	
	
}



void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank()) {

		//TODO move towards tank
		
		AimToPlayer();


		//TODO Fire when ready
	}
	
	
}


ATank* ATankAIController::GetControlledTank() const
{

	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{

	auto PlayerPawn = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());


	if (!PlayerPawn)
	{
		return nullptr;
	}
	else {
		return PlayerPawn;
	}
}

void ATankAIController::AimToPlayer() {
	auto PlayerLoc = GetPlayerTank()->GetActorLocation();
	GetControlledTank()->AimAt(PlayerLoc);

}