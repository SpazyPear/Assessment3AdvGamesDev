// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "TwistedGroundsHUD.h"
#include "Engine/Canvas.h"
#include "Engine/Texture2D.h"
#include "TextureResource.h"
#include "CanvasItem.h"
#include "UObject/ConstructorHelpers.h"

ATwistedGroundsHUD::ATwistedGroundsHUD()
{
	// Set the crosshair texture
	static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("/Game/Textures/HUD/FirstPersonCrosshair"));
	CrosshairTex = CrosshairTexObj.Object;

	static ConstructorHelpers::FClassFinder<UUserWidget> PlayerHUDObject(TEXT("/Game/UI/HUD"));
	PlayerHUDClass = PlayerHUDObject.Class;
	if (!PlayerHUDClass) {
		return;
	}
	CurrentPlayerHUDWidget = CreateWidget<UUserWidget>(GetWorld(), PlayerHUDClass);
	if (!CurrentPlayerHUDWidget) {
		return;
	}
	CurrentPlayerHUDWidget->AddToViewport();
	AmmoBar = Cast<UProgressBar>(CurrentPlayerHUDWidget->GetWidgetFromName(TEXT("AmmoBar")));
}


void ATwistedGroundsHUD::DrawHUD()
{
	Super::DrawHUD();

	// Draw very simple crosshair

	// find center of the Canvas
	const FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);

	// offset by half the texture's dimensions so that the center of the texture aligns with the center of the Canvas
	const FVector2D CrosshairDrawPosition( (Center.X),
										   (Center.Y + 20.0f));

	// draw the crosshair
	FCanvasTileItem TileItem( CrosshairDrawPosition, CrosshairTex->Resource, FLinearColor::White);
	TileItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem( TileItem );
}

void ATwistedGroundsHUD::UpdateAmmoBar(float Percent)
{
	if (!AmmoBar) {
		return;
	}
	AmmoBar->SetPercent(Percent);
}
