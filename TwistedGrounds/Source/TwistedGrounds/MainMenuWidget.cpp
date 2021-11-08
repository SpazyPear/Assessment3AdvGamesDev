// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuWidget.h"
#include "Kismet/KismetSystemLibrary.h"
#include "DoStatic.h"

bool UMainMenuWidget::Initialize() {
	Super::Initialize();

	bTutorialHidden = true;
	bool bSuccess = ButtonStart && ButtonTutorial && ButtonQuit;
	bSuccess = bSuccess && TutorialText && ButtonTutorialText;
	if (bSuccess) {
		ButtonStart->OnClicked.AddDynamic(this, &UMainMenuWidget::ButtonStartAction);
		ButtonTutorial->OnClicked.AddDynamic(this, &UMainMenuWidget::ButtonTutorialAction);
		ButtonQuit->OnClicked.AddDynamic(this, &UMainMenuWidget::QuitButtonAction);

		TutorialText->SetText(DoStatic::CreateFText("WASD or Arrow keys to move.\nHold shift to sprint.\nSpace to jump.\nControl to slide.\n\nLeft click to shoot.\nRight click to sculpt the terrain.\nWhile sculpting, hold:\n\t- E to dig.\n\t- Q to lock the height of the sculpting."));
	}
	else {
		//Will crash the editor.
		DoStatic::Print(1, "The main menu widget failed to initialise, one of the widgets does not work.");
	}
	return bSuccess;
}

void UMainMenuWidget::ButtonStartAction()
{
	Cast<UMainGameInstance>(GetGameInstance())->ChangeToNormalInput();
	this->ConditionalBeginDestroy();
}

void UMainMenuWidget::ButtonTutorialAction()
{
	FlipToTutorial();
}

void UMainMenuWidget::QuitButtonAction()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), 0, EQuitPreference::Quit, false);
}

void UMainMenuWidget::FlipToTutorial()
{
	bTutorialHidden = !bTutorialHidden;
	ButtonTutorialText->SetText(DoStatic::CreateFText(bTutorialHidden ? "How To Play" : "Go Back"));
	ButtonStart->SetVisibility(GetSlateVisibility(!bTutorialHidden));
	ButtonQuit->SetVisibility(GetSlateVisibility(!bTutorialHidden));
	TutorialText->SetVisibility(GetSlateVisibility(bTutorialHidden));
}

ESlateVisibility UMainMenuWidget::GetSlateVisibility(bool bHidden)
{
	return bHidden ? ESlateVisibility::Hidden : ESlateVisibility::Visible;
}
