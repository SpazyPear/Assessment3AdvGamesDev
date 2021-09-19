// Copyright 2016 Andreas Schoch (aka Minaosis). All Rights Reserved.
#include "SculptComponent.h"
#include "TerrainSection.h"
#include "TimerManager.h"
#include "Engine/World.h"




USculptComponent::USculptComponent()
{
	//bWantsBeginPlay = false;
	PrimaryComponentTick.bCanEverTick = false;
}


void USculptComponent::SculptStart()
{
	InputInfo.SculptInput = ESculptInput::ST_Started;
	InputInfo.StartLocation = HitResultOwner.Location;
	GetWorld()->GetTimerManager().SetTimer(SculptTimerHandle, this, &USculptComponent::Sculpt, GetWorld()->DeltaTimeSeconds, true);
	FString name = GetOwner()->GetName();
	UE_LOG(LogTemp, Warning, TEXT("Owner Name: %s"), *name)
}


void USculptComponent::SculptStop()
{
	InputInfo.SculptInput = ESculptInput::ST_Stopped;
	GetWorld()->GetTimerManager().PauseTimer(SculptTimerHandle);
	Sculpt();
}


bool USculptComponent::SculptSingle(FSculptInputInfo ParamInputInfo)
{
	// Cast to owner of hit section
	ATerrainSection* HitSection = dynamic_cast<ATerrainSection*>(HitResultOwner.GetActor());
	if (!HitSection) { return false; }

	HitSection->RequestSculpting(SculptSettings, ParamInputInfo);
	return true;
}


void USculptComponent::Sculpt()
{
	InputInfo.CurrentLocation = HitResultOwner.Location;
	if (InSleepDistance()) { return; }
	if (InputInfo.SculptInput == ESculptInput::ST_Stopped) { return; }

	// Cast to owner of hit section
	ATerrainSection* HitSection = dynamic_cast<ATerrainSection*>(HitResultOwner.GetActor());
	if (!HitSection) { return; }

	HitSection->RequestSculpting(SculptSettings, InputInfo);
	if (InputInfo.SculptInput == ESculptInput::ST_Started) { InputInfo.SculptInput = ESculptInput::ST_Ongoing; }
}


bool USculptComponent::InSleepDistance()
{
	if (FVector::Dist(InputInfo.LastLocation, InputInfo.CurrentLocation) < SleepDistance) { return true; }
	InputInfo.LastLocation = InputInfo.CurrentLocation;
	return false;
}