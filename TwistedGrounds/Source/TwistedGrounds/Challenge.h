// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Challenge.generated.h"

/**
 * 
 */
UCLASS()
class TWISTEDGROUNDS_API UChallenge : public UAnimInstance
{
	GENERATED_BODY()
	public:
		UChallenge();
		void ToggleSprint();

	protected:
		UPROPERTY(EditInstanceOnly, BlueprintReadWrite)
			bool bIsSprinting;
};
