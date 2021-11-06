// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"

#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"

#include "TwistedGroundsHUD.generated.h"

UCLASS()
class ATwistedGroundsHUD : public AHUD
{
	GENERATED_BODY()

public:
	ATwistedGroundsHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;
	void UpdateAmmoBar(float Percent);
	void UpdateHPBar(float Percent);

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

	TSubclassOf<UUserWidget> PlayerHUDClass;
	UUserWidget* CurrentPlayerHUDWidget;
	UProgressBar* AmmoBar;
	UProgressBar* HPBar;
};
