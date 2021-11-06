// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "HAL/RunnableThread.h"
#include "HAL/Runnable.h"
#include <KismetProceduralMeshLibrary.h>
#include "CoreMinimal.h"
#include "PlayerCharacter.h"

/**
 * 
 */
class TWISTEDGROUNDS_API CheckCollisionThread : public FRunnable
{
public:
	CheckCollisionThread();
	virtual ~CheckCollisionThread() override;

	bool Init() override;
	uint32 Run() override;
	void Stop() override;
	void Exit() override;

	void CreateThread(APlayerCharacter* CharacterP);

	bool bIsRunningThread;

	APlayerCharacter* Character;

private:
	FRunnableThread* UpdateThread;


};
