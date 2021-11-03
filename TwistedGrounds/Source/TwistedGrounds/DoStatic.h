// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * As the name of the class implies, this is a simple class
 * where all the functions/procedures are static and public for use.
 * Meant to makes things easier to use.
 * 
 * It should never have an include file except the coreminimal
 * (UE4 placed it there).
 */
class TWISTEDGROUNDS_API DoStatic
{
public:
	/// <summary>
	/// Rounds the value given to the nearest number given.
	/// Note: If the value is a negative, it will go lower. Hence it will always round down.
	/// </summary>
	/// <param name="Value">The value to be rounded down.</param>
	/// <param name="Nearest">The value that Value will be rounded down to</param>
	/// <returns>Returns an int32 as once rounded down, it would be an integer</returns>
	static int32 RoundDownToNearest(int32 Value, int32 Nearest);

	/// <summary>
	/// A UE_LOG at warning level.
	/// </summary>
	/// <param name="S">String of what to print. Its format: FString::Printf("", *Args)</param>
	static void PrintWarning(FString S);

	/// <summary>
	/// Prints a message in a random colour onto the screen.
	/// </summary>
	/// <param name="Duration">How long it will last, defaults to 5 seconds</param>
	/// <param name="S">What should be displayed. Its format: FString::Printf("", *Args)</param>
	static void PrintOnScreenDebugMessage(float Duration, FString S);
	static void PrintOnScreenDebugMessage(FString S);
};
