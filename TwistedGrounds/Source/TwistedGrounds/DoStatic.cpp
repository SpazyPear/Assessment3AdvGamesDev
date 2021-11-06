// Fill out your copyright notice in the Description page of Project Settings.


#include "DoStatic.h"
#include "Engine/GameEngine.h"

int32 DoStatic::RoundDownToNearest(int32 Value, int32 Nearest)
{
	int32 PosValue = FMath::Abs(Value); //Mod goes towards 0, thus all values given to mod must be positive.
	int32 Result = PosValue - FMath::Fmod(PosValue, Nearest) + (Value < 0 ? Nearest : 0);
	return Value < 0 ? -Result : Result;
}

FColor DoStatic::RandomColour()
{
	int32 R = FMath::RandRange(0, 255);
	int32 G = FMath::RandRange(0, 255);
	int32 B = FMath::RandRange(0, 255);
	return FColor(R, G, B, 255);
}

void DoStatic::Print(int32 Verbosity, FString String)
{
	switch (Verbosity) {
	case ELogVerbosity::Display:
		UE_LOG(LogTemp, Display, TEXT("%s"), *String)
		return;
	case ELogVerbosity::Warning:
		UE_LOG(LogTemp, Warning, TEXT("%s"), *String)
		return;
	case ELogVerbosity::Error:
		UE_LOG(LogTemp, Error, TEXT("%s"), *String)
		return;
	case ELogVerbosity::Fatal:
		UE_LOG(LogTemp, Fatal, TEXT("%s"), *String)
		return;
	default:
		Print("#");
		Print("Unknown verbosity, use ELogVerbosity::Type or a number");
		Print("ELogVerbosity::Display or 4");
		Print("ELogVerbosity::Warning or 3 (Default)");
		Print("ELogVerbosity::Error or 2");
		Print("ELogVerbosity::Fatal or 1, THIS WILL CRASH THE ENGINE, USE WITH CAUTION!");
		Print(String);
		Print("#");
	}
}

void DoStatic::Print(FString String)
{
	Print(ELogVerbosity::Warning, String);
}

void DoStatic::PrintOnScreenDebugMessage(float Duration, FColor Colour, FString String)
{
	GEngine->AddOnScreenDebugMessage(-1, Duration, Colour, FString::Printf(TEXT("%s"), *String));
}

void DoStatic::PrintOnScreenDebugMessage(FColor Colour, FString String)
{
	PrintOnScreenDebugMessage(5, Colour, String);
}

void DoStatic::PrintOnScreenDebugMessage(float Duration, FString String)
{
	PrintOnScreenDebugMessage(Duration, RandomColour(), String);
}

void DoStatic::PrintOnScreenDebugMessage(FString String)
{
	PrintOnScreenDebugMessage(5, String);
}

FText DoStatic::CreateFText(FString String)
{
	return FText::FromString(FString::Printf(TEXT("%s"), *String));
}
