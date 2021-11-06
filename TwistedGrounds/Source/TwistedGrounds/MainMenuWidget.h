// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Components/Button.h"
#include "MainGameInstance.h"

#include "MainMenuWidget.generated.h"

UCLASS()
class TWISTEDGROUNDS_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
private:
	virtual bool Initialize() override;

	UPROPERTY(meta = (BindWidget))
		UButton* ButtonStart;

	UPROPERTY(meta = (BindWidget))
		UButton* ButtonTutorial;

	UPROPERTY(meta = (BindWidget))
		UButton* ButtonQuit;

	UFUNCTION()
		void ButtonStartAction();

	UFUNCTION()
		void ButtonTutorialAction();

	UFUNCTION()
		void QuitButtonAction();
};
