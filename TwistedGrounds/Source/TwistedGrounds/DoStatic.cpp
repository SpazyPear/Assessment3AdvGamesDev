// Fill out your copyright notice in the Description page of Project Settings.


#include "DoStatic.h"
#include "Engine/GameEngine.h"

int32 DoStatic::RoundDownToNearest(int32 Value, int32 Nearest)
{
	int32 PosValue = FMath::Abs(Value); //Mod goes towards 0, thus all values given to mod must be positive.
	int32 Result = PosValue - FMath::Fmod(PosValue, Nearest) + (Value < 0 ? Nearest : 0);
	return Value < 0 ? -Result : Result;
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
		UE_LOG(LogTemp, Error, TEXT("#"))
		UE_LOG(LogTemp, Warning, TEXT("Unknown verbosity, use ELogVerbosity::Type or a number"))
		UE_LOG(LogTemp, Display, TEXT("ELogVerbosity::Display or 4 for normal colour"))
		UE_LOG(LogTemp, Warning, TEXT("ELogVerbosity::Warning or 3 for this colour"))
		UE_LOG(LogTemp, Error, TEXT("ELogVerbosity::Error or 2 for this colour"))
		UE_LOG(LogTemp, Error, TEXT("ELogVerbosity::Fatal or 1, THIS WILL CRASH THE GAME, USE WITH CAUTION!"))
		UE_LOG(LogTemp, Warning, TEXT("%s"), *String)
		UE_LOG(LogTemp, Error, TEXT("#"))
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
	int32 R = FMath::RandRange(0, 255);
	int32 G = FMath::RandRange(0, 255);
	int32 B = FMath::RandRange(0, 255);
	PrintOnScreenDebugMessage(Duration, FColor(R, G, B, 255), String);
}

void DoStatic::PrintOnScreenDebugMessage(FString String)
{
	PrintOnScreenDebugMessage(5, String);
}

FText DoStatic::CreateFText(FString String)
{
	return FText::FromString(FString::Printf(TEXT("%s"), *String));
}
