// Fill out your copyright notice in the Description page of Project Settings.


#include "CheckCollisionThread.h"


#pragma region Main Thread Code
CheckCollisionThread::CheckCollisionThread()
{
    bIsRunningThread = false;
}

void CheckCollisionThread::CreateThread(APlayerCharacter* CharacterP)
{
    this->Character = CharacterP;

    UpdateThread = FRunnableThread::Create(this, TEXT("UpdateThread"));
}

CheckCollisionThread::~CheckCollisionThread()
{
    delete UpdateThread;
}

#pragma endregion

bool CheckCollisionThread::Init()
{
    return true;
}

uint32 CheckCollisionThread::Run()
{
    while (Character->GetVelocity().Size() != 0) {

    }
    return 0;
}

void CheckCollisionThread::Stop()
{
}

void CheckCollisionThread::Exit()
{
    UE_LOG(LogTemp, Warning, TEXT("Stopped"))
    bIsRunningThread = false;
    Character->GetUp();
    this->~CheckCollisionThread();
}
