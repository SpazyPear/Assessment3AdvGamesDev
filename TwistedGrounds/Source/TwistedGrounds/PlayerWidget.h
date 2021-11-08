// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Components/ProgressBar.h"

#include "PlayerWidget.generated.h"

UCLASS()
class TWISTEDGROUNDS_API UPlayerWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	void UpdateAmmoBar(float Percent);
	void UpdateSculptAmmoBar(float Percent);
	void UpdateHPBar(float Percent);

	bool bRecharging;

private:
	virtual bool Initialize() override;

	void SetBar(UProgressBar* Bar, float Percent);
	void SetBarColour(UProgressBar* Bar, float R, float G, float B);

	UPROPERTY(meta = (BindWidget)) UProgressBar* HPBar;
	UPROPERTY(meta = (BindWidget)) UProgressBar* AmmoBar;
	UPROPERTY(meta = (BindWidget)) UProgressBar* SculptAmmoBar;

	//Time it takes to fully recharge the gun.
	float CooldownTime;
};
