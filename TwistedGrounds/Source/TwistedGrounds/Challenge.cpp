// Fill out your copyright notice in the Description page of Project Settings.


#include "Challenge.h"

UChallenge::UChallenge() {
	bIsSprinting = false;
}

void UChallenge::ToggleSprint() {
	bIsSprinting = !bIsSprinting;
}