// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"

#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.h"
#include "OnlineSubsystem.h"

#include "MainGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class TWISTEDGROUNDS_API UMainGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	virtual void Init();
	UMainGameInstance(const FObjectInitializer& ObjectInitialize);

	UFUNCTION(BlueprintCallable)
		void LoadMenu();

	UFUNCTION(BlueprintCallable)
		void PlayGame();

	void CreateSession(FName SessionName);

private:
	TSubclassOf<UUserWidget> MainMenuWidgetClass;
	class UMainMenuWidget* Menu;
	IOnlineSubsystem* Subsystem;
	IOnlineSessionPtr SessionInterface;
	void OnCreateSessionComplete(FName SessionName, bool bSuccess);
	void JoinSession(int32 Id, FName SessionName);
};
