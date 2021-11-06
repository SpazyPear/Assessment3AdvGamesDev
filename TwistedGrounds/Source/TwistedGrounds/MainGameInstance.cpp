// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameInstance.h"

#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"

UMainGameInstance::UMainGameInstance(const FObjectInitializer& ObjectInitialize) {
	static ConstructorHelpers::FClassFinder<UUserWidget> HUDObject(TEXT("/Game/UI/MainMenu"));
	MainMenuWidgetClass = HUDObject.Class;
}

void UMainGameInstance::LoadMenu()
{
	if (!MainMenuWidgetClass) {
		return;
	}

	UMainMenuWidget* Menu = CreateWidget<UMainMenuWidget>(GetWorld(), MainMenuWidgetClass);
	if (!Menu) {
		return;
	}

	Menu->AddToViewport();

	FInputModeUIOnly InputMode;
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (PlayerController) {
		PlayerController->SetInputMode(InputMode);
		PlayerController->bShowMouseCursor = true;
	}
}

void UMainGameInstance::ChangeToNormalInput()
{
	FInputModeGameOnly InputMode;
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (PlayerController) {
		PlayerController->SetInputMode(InputMode);
		PlayerController->bShowMouseCursor = false;
	}
}
