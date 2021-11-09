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

	/// <summary>
	/// Set the intial values for generation of the map.
	/// </summary>
	/// <param name="W">Width</param>
	/// <param name="H">Height</param>
	/// <param name="GS">GridSize</param>
	/// <param name="PS">PerlinScale</param>
	/// <param name="PSO">PerlinScaleOffset</param>
	/// <param name="PR">PerlinRoughness</param>
	/// <param name="PO">PerlinOffset</param>
	/// <param name="OX">OffsetX</param>
	/// <param name="OY">OffsetY</param>
	void SetMapValues(int32 W, int32 H, float GS, float PS, float PSO, float PR, float PO, int32 OX, int32 OY);
	void GenerateMap();
	
	UFUNCTION(NetMulticast, Reliable)
		void NetMulticastGenerateMap();

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	//Controlled by MapGenerator
	UPROPERTY(Replicated) int32 Width;
	UPROPERTY(Replicated) int32 Height;
	UPROPERTY(Replicated) float GridSize;
	UPROPERTY(Replicated) float PerlinScale;
	UPROPERTY(Replicated) float PerlinRoughness;
	UPROPERTY(Replicated) float PerlinOffset;
	UPROPERTY(Replicated) int32 OffsetX;
	UPROPERTY(Replicated) int32 OffsetY;
	//End

	UPROPERTY(Replicated) int32 BiomeIndex;
	UPROPERTY(Replicated) AProcedurallyGeneratedMap* Top; //Could be a TArray but not sure if TArray can be replicated
	UPROPERTY(Replicated) AProcedurallyGeneratedMap* Right;
	UPROPERTY(Replicated) AProcedurallyGeneratedMap* Bottom;
	UPROPERTY(Replicated) AProcedurallyGeneratedMap* Left;

	UPROPERTY() UProceduralMeshComponent* MeshComponent;
	UPROPERTY() TArray<FVector> Vertices;
	UPROPERTY() TArray<int32> Triangles;
	UPROPERTY() TArray<FVector2D> UVCoords;

	TArray<FVector> Normals;
	TArray<FProcMeshTangent> Tangents;

	UPROPERTY(EditDefaultsOnly) TArray<UMaterialInterface*> Biomes;

private:
	float PerlinSample(float Axis, float Offset);
	void ClearMap();
	void UpdateNeighbours();
	void UpdateMapValues(float PSO);
	void UpdateChunkEdge();

	bool bUpdateMap;
};

class GenerateChunk : public FNonAbandonableTask {
public:
	AProcedurallyGeneratedMap* MapRef;

	GenerateChunk(AProcedurallyGeneratedMap* Map) {
		MapRef = Map;
	}

	~GenerateChunk() {}

	FORCEINLINE TStatId GetStatId() const {
		RETURN_QUICK_DECLARE_CYCLE_STAT(GenerateChunk, STATGROUP_ThreadPoolAsyncTasks);
	}

	void DoWork() {
		MapRef->GenerateMap();
	}
};