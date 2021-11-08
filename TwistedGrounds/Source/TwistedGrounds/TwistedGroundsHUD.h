// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"

#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "PlayerWidget.h"

#include "TwistedGroundsHUD.generated.h"

UCLASS()
class ATwistedGroundsHUD : public AHUD
{
	GENERATED_BODY()

public:
	ATwistedGroundsHUD();
	UPlayerWidget* PlayerHUDWidget;

private:
	TSubclassOf<UUserWidget> PlayerHUDClass;
	UProgressBar* AmmoBar;
	UProgressBar* HPBar;
};
