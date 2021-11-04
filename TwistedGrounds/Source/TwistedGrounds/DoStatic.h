// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * As the name of the class implies, this is a simple class
 * where all the functions/procedures are static and public for use.
 * Meant to makes things easier to use.
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
	/// A UE_LOG at given verbosity level. Defaults to Warning.
	/// Use either ELogVerbosity::Type or the correct number.
	/// </summary>
	/// <param name="Verbosity">Allowed verbosity: Display (4), Warning (3), Error (2), Fatal (1)</param>
	/// <param name="String"> What should be displayed. A ordinary string works, if arguments are needed use: FString::Printf(TEXT(""), *Args)</param>
	static void Print(int32 Verbosity, FString String);
	static void Print(FString String);

	/// <summary>
	/// Prints a message in a random colour onto the screen.
	/// </summary>
	/// <param name="Duration">How long it will last, defaults to 5 seconds</param>
	/// <param name="Colour">The colour of the text</param>
	/// <param name="String"> What should be displayed. A ordinary string works, if arguments are needed use: FString::Printf(TEXT(""), *Args)</param>
	static void PrintOnScreenDebugMessage(float Duration, FColor Colour, FString String);
	static void PrintOnScreenDebugMessage(FColor Colour, FString String);
	static void PrintOnScreenDebugMessage(float Duration, FString String);
	static void PrintOnScreenDebugMessage(FString String);
};
