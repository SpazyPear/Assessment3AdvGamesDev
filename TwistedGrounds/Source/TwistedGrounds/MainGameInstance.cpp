// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameInstance.h"

#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "OnlineSessionSettings.h"

#include "DoStatic.h"

UMainGameInstance::UMainGameInstance(const FObjectInitializer& ObjectInitialize) {
	static ConstructorHelpers::FClassFinder<UUserWidget> HUDObject(TEXT("/Game/UI/MainMenu"));
	MainMenuWidgetClass = HUDObject.Class;
}

void UMainGameInstance::Init()
{
	Subsystem = IOnlineSubsystem::Get();
	if (!Subsystem) {
		return;
	}

	SessionInterface = Subsystem->GetSessionInterface();
	SessionInterface->OnCreateSessionCompleteDelegates.AddUObject(this, &UMainGameInstance::OnCreateSessionComplete);
}

void UMainGameInstance::LoadMenu()
{
	if (!MainMenuWidgetClass) {
		return;
	}

	UMainMenuWidget* MainMenu = CreateWidget<UMainMenuWidget>(GetWorld(), MainMenuWidgetClass);
	if (!MainMenu) {
		return;
	}

	MainMenu->AddToViewport();

	FInputModeUIOnly InputMode;
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputMode.SetWidgetToFocus(MainMenu->TakeWidget());

	APlayerController* Player = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (Player) {
		Player->SetInputMode(InputMode);
		Player->bShowMouseCursor = true;
	}
}

void UMainGameInstance::PlayGame()
{
	FInputModeGameOnly InputMode;

	APlayerController* Player = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (Player) {
		Player->SetInputMode(InputMode);
		Player->bShowMouseCursor = false;
	}
}

void UMainGameInstance::CreateSession(FName SessionName)
{
	if (!SessionInterface.IsValid()) {
		return;
	}

	FNamedOnlineSession* Session = SessionInterface->GetNamedSession(SessionName);
	if (Session) { //If session exists
		int32 NumConnections = Session->NumOpenPublicConnections;
		if (NumConnections < 2) {
			DoStatic::Print("Joining Session");
			JoinSession(NumConnections, SessionName);
			return;
		}
		DoStatic::Print("Destroying Session");
		SessionInterface->DestroySession(SessionName);
	}

	FOnlineSessionSettings SessionSettings;
	SessionSettings.bIsLANMatch = true;
	SessionSettings.NumPublicConnections = 2;
	SessionSettings.bShouldAdvertise = true;

	SessionInterface->CreateSession(0, SessionName, SessionSettings);
	//Join session is done on OnCreateSessionComplete.
}

void UMainGameInstance::JoinSession(int32 Id, FName SessionName) {
	FOnlineSessionSearchResult SearchResult;
	SessionInterface->JoinSession(Id, SessionName, SearchResult);
	UGameplayStatics::OpenLevel(GetWorld(), "/Game/Maps/Overworld");
}

void UMainGameInstance::OnCreateSessionComplete(FName SessionName, bool bSuccess)
{
	DoStatic::Print(bSuccess ? "Session Created Successfully" : "Session was not Created");
	if (bSuccess) {
		JoinSession(0, SessionName);
	}
	else {
		SessionInterface->DestroySession(SessionName);
	}
}
