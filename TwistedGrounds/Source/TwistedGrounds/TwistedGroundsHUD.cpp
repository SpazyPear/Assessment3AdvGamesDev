// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "TwistedGroundsHUD.h"
#include "UObject/ConstructorHelpers.h"

ATwistedGroundsHUD::ATwistedGroundsHUD()
{
	static ConstructorHelpers::FClassFinder<UUserWidget> PlayerHUDObject(TEXT("/Game/UI/PlayerHUD"));
	PlayerHUDClass = PlayerHUDObject.Class;
	if (!PlayerHUDClass) {
		return;
	}

	PlayerHUDWidget = Cast<UPlayerWidget>(CreateWidget<UUserWidget>(GetWorld(), PlayerHUDClass));
	if (!PlayerHUDWidget) {
		return;
	}

	PlayerHUDWidget->AddToViewport();
}
