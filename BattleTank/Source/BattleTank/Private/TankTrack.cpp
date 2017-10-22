// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"


void UTankTrack::SetThrottle(float Throttle) 
{
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s Track speed %f"),*Name, Throttle);

	//TODO clamb actual throttle value so player cannot over-drive

	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

	AddForceAtLocation(ForceApplied,ForceLocation);


}

