// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuWidget.h"
#include "DoStatic.h"

bool UMainMenuWidget::Initialize() {
	Super::Initialize();
	bool bSuccess = ButtonStart && ButtonTutorial && ButtonQuit;
	if (bSuccess) {
		ButtonStart->OnHovered.AddDynamic(this, &UMainMenuWidget::ButtonStartHover);
		ButtonStart->OnClicked.AddDynamic(this, &UMainMenuWidget::ButtonStartAction);

		ButtonTutorial->OnHovered.AddDynamic(this, &UMainMenuWidget::ButtonTutorialHover);
		ButtonTutorial->OnClicked.AddDynamic(this, &UMainMenuWidget::ButtonTutorialAction);

		ButtonQuit->OnHovered.AddDynamic(this, &UMainMenuWidget::QuitButtonHover);
		ButtonQuit->OnClicked.AddDynamic(this, &UMainMenuWidget::QuitButtonAction);
	}
	return bSuccess;
}

void UMainMenuWidget::ButtonStartHover()
{
	DoStatic::Print(4, "Start Button Hover");
}

void UMainMenuWidget::ButtonStartAction()
{
	DoStatic::Print("Start Button Pressed");
}

void UMainMenuWidget::ButtonTutorialHover()
{
	DoStatic::Print(4, "Tutorial Button Hover");
}

void UMainMenuWidget::ButtonTutorialAction()
{
	DoStatic::Print("Tutorial Button Pressed");
}

void UMainMenuWidget::QuitButtonHover()
{
	DoStatic::Print(4, "Quit Button Hover");
}

void UMainMenuWidget::QuitButtonAction()
{
	DoStatic::Print("Quit Button Pressed");
}
