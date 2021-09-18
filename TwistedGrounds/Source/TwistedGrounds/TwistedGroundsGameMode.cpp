// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "TwistedGroundsGameMode.h"
#include "TwistedGroundsHUD.h"
#include "TwistedGroundsCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATwistedGroundsGameMode::ATwistedGroundsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	//DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ATwistedGroundsHUD::StaticClass();
}
