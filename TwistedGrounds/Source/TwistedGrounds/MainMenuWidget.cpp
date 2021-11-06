// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuWidget.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "DoStatic.h"

bool UMainMenuWidget::Initialize() {
	Super::Initialize();
	bool bSuccess = ButtonStart && ButtonTutorial && ButtonQuit;
	if (bSuccess) {
		ButtonStart->OnClicked.AddDynamic(this, &UMainMenuWidget::ButtonStartAction);
		ButtonTutorial->OnClicked.AddDynamic(this, &UMainMenuWidget::ButtonTutorialAction);
		ButtonQuit->OnClicked.AddDynamic(this, &UMainMenuWidget::QuitButtonAction);
	}
	return bSuccess;
}

void UMainMenuWidget::ButtonStartAction()
{
	Cast<UMainGameInstance>(GetGameInstance())->CreateSession(TEXT("That one session"));
}

void UMainMenuWidget::ButtonTutorialAction()
{
	DoStatic::Print("Tutorial Button Pressed");
	
}

void UMainMenuWidget::QuitButtonAction()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), 0, EQuitPreference::Quit, false);
}
