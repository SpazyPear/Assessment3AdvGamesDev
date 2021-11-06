// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"

#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.h"

#include "MainGameInstance.generated.h"

UCLASS()
class TWISTEDGROUNDS_API UMainGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UMainGameInstance(const FObjectInitializer& ObjectInitialize);

	UFUNCTION(BlueprintCallable)
		void LoadMenu();

	UFUNCTION(BlueprintCallable)
		void ChangeToNormalInput();

private:
	TSubclassOf<UUserWidget> MainMenuWidgetClass;
};
