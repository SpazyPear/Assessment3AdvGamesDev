// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "ProceduralMeshComponent.h"
#include "SavedMap.generated.h"

UCLASS()
class TWISTEDGROUNDS_API USavedMap : public USaveGame
{
	GENERATED_BODY()
	
public:
	USavedMap();

	UPROPERTY(VisibleAnywhere, Category = Basic)
		uint32 Index;

	UPROPERTY(VisibleAnywhere, Category = Basic)
		FString Name;

	UPROPERTY()
		TArray<FVector> Vertices;

	UPROPERTY()
		TArray<int32> Triangles;

	UPROPERTY()
		TArray<FVector2D> UVCoords;

	UPROPERTY()
		TArray<FVector> Normals;

	UPROPERTY()
		TArray<FProcMeshTangent> Tangents;
};
