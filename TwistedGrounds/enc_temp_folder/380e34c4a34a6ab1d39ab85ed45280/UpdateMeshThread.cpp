// Fill out your copyright notice in the Description page of Project Settings.


#include "UpdateMeshThread.h"
#include "GenericPlatform/GenericPlatformProcess.h"

#pragma region Main Thread Code

UpdateMeshThread::UpdateMeshThread() //if youre gonna do the editing here too, make these pointers
{
	
	//UpdateThread = FRunnableThread::Create(this, TEXT("UpdateThread"));
}

UpdateMeshThread::~UpdateMeshThread()
{
	if (UpdateThread)
	{
		UpdateThread->Kill();
		delete UpdateThread;
	}
}

void UpdateMeshThread::CreateThread(UProceduralMeshComponent* MeshComponentP, TArray<FVector> VerticesP, TArray<int32> TrianglesP, TArray<FVector2D> UVCoordsP, TArray<FVector> NormalsP)
{
	this->Vertices = VerticesP;

	this->Triangles = TrianglesP;

	this->UVCoords = UVCoordsP;

	this->Normals = NormalsP;

	this->MeshComponent = MeshComponentP;

	UpdateThread = FRunnableThread::Create(this, TEXT("UpdateThread"));
}


#pragma endregion

bool UpdateMeshThread::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("Thread Initialized"))

		// Return false if you want to abort the thread
		return true;
}

uint32 UpdateMeshThread::Run()
{
	// Peform your processor intensive task here. In this example, a neverending
	// task is created, which will only end when Stop is called.
	
	bRunningThread = true;
	UE_LOG(LogTemp, Warning, TEXT("Thread Running"))
	CalculateTangents();

	return 0;
}

void UpdateMeshThread::Stop()
{
	// Clean up memory usage here, and make sure the Run() function stops soon
	// The main thread will be stopped until this finishes!

	// For this example, we just need to terminate the while loop
	UE_LOG(LogTemp, Warning, TEXT("Thread Stopped"))
	
}

void UpdateMeshThread::Exit()
{
	UE_LOG(LogTemp, Warning, TEXT("Thread Stopped"))
	bRunningThread = false;
}



void UpdateMeshThread::CalculateTangents()
{
	UKismetProceduralMeshLibrary::CalculateTangentsForMesh(Vertices, Triangles, UVCoords, Normals, Tangents);
}
