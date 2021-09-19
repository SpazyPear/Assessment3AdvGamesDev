// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HAL/RunnableThread.h"
#include "HAL/Runnable.h"
#include <KismetProceduralMeshLibrary.h>

/**
 * 
 */


class TWISTEDGROUNDS_API UpdateMeshThread : public FRunnable
{
public:

	UpdateMeshThread();

	virtual ~UpdateMeshThread() override;

	bool Init() override; // Do your setup here, allocate memory, ect.
	uint32 Run() override; // Main data processing happens here
	void Stop() override; // Clean up any memory you allocated here
	void Exit() override;

	TArray<FVector> Vertices;

	TArray<int32> Triangles;

	TArray<FVector2D> UVCoords;

	TArray<FVector> Normals;

	TArray<FProcMeshTangent> Tangents;

	UProceduralMeshComponent* MeshComponent;

	void CreateThread(UProceduralMeshComponent* MeshComponentP, TArray<FVector> VerticesP, TArray<int32> TrianglesP, TArray<FVector2D> UVCoordsP, TArray<FVector> NormalsP);

	bool bRunningThread;
	
private:

	FRunnableThread* UpdateThread;

	

	void CalculateTangents();

};
