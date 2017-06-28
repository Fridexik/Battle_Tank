// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Fire.h"


// Sets default values for this component's properties
UFire::UFire()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UFire::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UFire::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UFire::FireTo(){
	UE_LOG(LogTemp, Warning, TEXT("Fire"));
}