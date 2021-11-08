// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerWidget.h"
#include "DoStatic.h"

bool UPlayerWidget::Initialize() {
	Super::Initialize();
	bRecharging = false;
	bLowSculptAmmo = false;

	CooldownTime = 1.0 / 3; //e.g. 3 seconds cooldown time
	bool bSuccess = HPBar && AmmoBar && SculptAmmoBar;
	if (!bSuccess) {
		DoStatic::Print(1, "There is a missing widget or something for the PlayerWidget class."); //Will crash.
	}
	return bSuccess;
}

void UPlayerWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	
	if (bRecharging) {
		UpdateAmmoBar(InDeltaTime * CooldownTime);
	}
}

void UPlayerWidget::SetBar(UProgressBar* Bar, float Percent)
{
	if (Bar) {
		Bar->SetPercent(FMath::Clamp(Percent, 0.0f, 1.0f));
	}
}

void UPlayerWidget::SetBarColour(UProgressBar* Bar, float R, float G, float B)
{
	if (Bar) {
		Bar->SetFillColorAndOpacity(FLinearColor(R, G, B));
	}
}

void UPlayerWidget::UpdateAmmoBar(float Amount)
{
	SetAmmoBar(AmmoBar->Percent + Amount);
}

void UPlayerWidget::SetAmmoBar(float Percent)
{
	SetBar(AmmoBar, Percent);
	bRecharging = bRecharging && AmmoBar->Percent < 1 || AmmoBar->Percent < 0.01;
	SetBarColour(AmmoBar, 0, bRecharging ? 0 : 0.5, 1); //Ammobar changes colour from light to dark blue when recharging
}

void UPlayerWidget::UpdateSculptAmmoBar(float Amount)
{
	SetSculptAmmoBar(SculptAmmoBar->Percent + Amount);
}

void UPlayerWidget::SetSculptAmmoBar(float Percent)
{
	SetBar(SculptAmmoBar, Percent);
	SculptAmmoBar->SetFillColorAndOpacity(FLinearColor::LerpUsingHSV(FLinearColor(0.65, 0.16, 0.16), FLinearColor(1, 0.65, 0), SculptAmmoBar->Percent));
	bLowSculptAmmo = SculptAmmoBar->Percent == 0;
}

void UPlayerWidget::UpdateHPBar(float Amount)
{
	SetHPBar(HPBar->Percent + Amount);
}

void UPlayerWidget::SetHPBar(float Percent)
{
	SetBar(HPBar, Percent);
	
	//Green when >= 50% HP, Red when <= 25% HP, Yellow in between. This is hard to read...
	float Per = HPBar->Percent;
	SetBarColour(HPBar, Per >= 0.5 ? 0 : 1, Per >= 0.25 ? 1 : 0, 0);
}
