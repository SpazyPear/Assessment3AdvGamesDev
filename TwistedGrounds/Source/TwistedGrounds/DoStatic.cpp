// Fill out your copyright notice in the Description page of Project Settings.


#include "DoStatic.h"

int32 DoStatic::RoundDownToNearest(int32 Value, int32 Nearest)
{
	int32 PosValue = FMath::Abs(Value); //Mod goes towards 0, thus all values given to mod must be positive.
	int32 Result = PosValue - FMath::Fmod(PosValue, Nearest) + (Value < 0 ? Nearest : 0);
	return Value < 0 ? -Result : Result;
}

void DoStatic::PrintWarning(FString S)
{
	UE_LOG(LogTemp, Warning, TEXT("%s"), *S)
}
