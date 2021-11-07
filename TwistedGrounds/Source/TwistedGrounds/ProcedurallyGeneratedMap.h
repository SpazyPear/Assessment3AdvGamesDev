// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Kismet/GameplayStatics.h"
#include "KismetProceduralMeshLibrary.h"
#include "ProceduralMeshComponent.h"

#include "ProcedurallyGeneratedMap.generated.h"

UCLASS()
class TWISTEDGROUNDS_API AProcedurallyGeneratedMap : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AProcedurallyGeneratedMap();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Controlled by MapGenerator
	UPROPERTY()
		int32 Width;

	UPROPERTY()
		int32 Height;

	UPROPERTY()
		float GridSize;

	UPROPERTY()
		UProceduralMeshComponent* MeshComponent;
	//End

	/// <summary>
	/// Initialise the map by passing in the essential variables.
	/// </summary>
	/// <param name="W">Width</param>
	/// <param name="H">Height</param>
	/// <param name="GS">GridSize</param>
	/// <param name="PS">PerlinScale</param>
	/// <param name="PR">PerlinRoughness</param>
	/// <param name="PO">PerlinOffset</param>
	/// <param name="OX">OffsetX</param>
	/// <param name="OY">OffsetY</param>
	/// <param name="PSO">PerlinScaleOffset</param>
	void InitiateMap(int32 W, int32 H, float GS, float PS, float PR, float PO, int32 OX, int32 OY, float PSO);

	UPROPERTY()
		TArray<FVector> Vertices;
	UPROPERTY()
		TArray<int32> Triangles;
	UPROPERTY()
		TArray<FVector2D> UVCoords;

	TArray<FVector> Normals;
	TArray<FProcMeshTangent> Tangents;

	float PerlinScale;

	UPROPERTY(EditDefaultsOnly)
		TArray<UMaterialInterface*> Biomes;

	int32 BiomeIndex;

private:
	float PerlinSample(float Axis, float Offset);
	void ClearMap();
	void GenerateMap();

	TArray<AProcedurallyGeneratedMap*> Neighbours;
	void UpdateNeighbours();
	void UpdateChunkEdge();

	//Controlled by MapGenerator
	float PerlinRoughness;
	float PerlinOffset;
	int32 OffsetX;
	int32 OffsetY;
	//End
};
