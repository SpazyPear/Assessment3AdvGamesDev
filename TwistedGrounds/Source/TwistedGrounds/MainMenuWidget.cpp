// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuWidget.h"
#include "Kismet/KismetSystemLibrary.h"
#include "DoStatic.h"

bool UMainMenuWidget::Initialize() {
	Super::Initialize();

	bTutorialHidden = true;
	bool bSuccess = ButtonStart && ButtonTutorial && ButtonQuit && TutorialText;
	if (!bSuccess) {
		//Will crash the editor.
		DoStatic::Print(1, "The main menu widget failed to initialise, one of the widgets does not work.");
	}

	ButtonStart->OnClicked.AddDynamic(this, &UMainMenuWidget::ButtonStartAction);
	ButtonTutorial->OnClicked.AddDynamic(this, &UMainMenuWidget::ButtonTutorialAction);
	ButtonGoBack->OnClicked.AddDynamic(this, &UMainMenuWidget::ButtonTutorialAction);
	ButtonQuit->OnClicked.AddDynamic(this, &UMainMenuWidget::QuitButtonAction);

	FString Tutorial = FString::Printf(TEXT("WASD or Arrow keys to move."));
	Tutorial.Append("\nHold shift to sprint.");
	Tutorial.Append("\nSpace to jump.");
	Tutorial.Append("\nHold control to slide.");
	Tutorial.Append("\nLeft click to shoot. There is auto-reload, time your shots!");
	Tutorial.Append("\n\nHold the right mouse button down to sculpt the terrain. Obstuct the opponent's line of fire with this. Quick to use up and reload!");
	Tutorial.Append("\nWhile sculpting, hold:");
	Tutorial.Append("\n\t- E to dig.");
	Tutorial.Append("\n\t- Q to lock the height of the sculpting.");
	TutorialText->SetText(DoStatic::CreateFText(Tutorial));

	return bSuccess;
}

void UMainMenuWidget::ButtonStartAction()
{
	Cast<UMainGameInstance>(GetGameInstance())->ChangeToNormalInput();
	this->ConditionalBeginDestroy();
}

void UMainMenuWidget::ButtonTutorialAction()
{
	bTutorialHidden = !bTutorialHidden;
	ESlateVisibility Hidden = GetSlateVisibility(!bTutorialHidden);
	ESlateVisibility Opposite = GetSlateVisibility(bTutorialHidden);

	ButtonTutorial->SetVisibility(Hidden);
	ButtonGoBack->SetVisibility(Opposite);
	ButtonStart->SetVisibility(Hidden);
	ButtonQuit->SetVisibility(Hidden);
	TutorialText->SetVisibility(Opposite);
}

void UMainMenuWidget::QuitButtonAction()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), 0, EQuitPreference::Quit, false);
}

ESlateVisibility UMainMenuWidget::GetSlateVisibility(bool bHidden)
{
	return bHidden ? ESlateVisibility::Hidden : ESlateVisibility::Visible;
}
