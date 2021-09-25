// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "TwistedGroundsGameMode.h"
#include "TwistedGroundsHUD.h"
#include "UObject/ConstructorHelpers.h"

ATwistedGroundsGameMode::ATwistedGroundsGameMode()
	: Super()
{
	// use our custom HUD class
	HUDClass = ATwistedGroundsHUD::StaticClass();
}
