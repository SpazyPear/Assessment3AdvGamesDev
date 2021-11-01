// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Kismet/GameplayStatics.h"
#include "KismetProceduralMeshLibrary.h"
#include "ProceduralMeshComponent.h"
#include "EngineUtils.h"
#include "DoStatic.h"

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

	UPROPERTY(VisibleAnywhere)
		UProceduralMeshComponent* MeshComponent;
	//End

	void InitiateMap(int32 W, int32 H, float GS, float PS, float PR, float PO, int32 OX, int32 OY);

	UPROPERTY()
		TArray<FVector> Vertices;
	UPROPERTY()
		TArray<int32> Triangles;
	UPROPERTY()
		TArray<FVector2D> UVCoords;

	TArray<FVector> Normals;
	TArray<FProcMeshTangent> Tangents;
	float PerlinSample(float Axis, float Offset);

	//Controlled by MapGenerator
	float PerlinScale;
	float PerlinRoughness;
	float PerlinOffset;
	int32 OffsetX;
	int32 OffsetY;
	//End

	bool bGenerateMeshSection;

	virtual bool ShouldTickIfViewportsOnly() const override;

private:
	void ClearMap();

	TArray<AProcedurallyGeneratedMap*> GetNeighbours();
};

class GenerateChunk : public FNonAbandonableTask {
public:

	TArray<AProcedurallyGeneratedMap*> Neighbours;

	AProcedurallyGeneratedMap* MapRef;
	GenerateChunk(AProcedurallyGeneratedMap* Map, TArray<AProcedurallyGeneratedMap*> Neighbours)
	{
		MapRef = Map;
		this->Neighbours = Neighbours;
	}

	~GenerateChunk() {}

	FORCEINLINE TStatId GetStatId() const {
		RETURN_QUICK_DECLARE_CYCLE_STAT(GenerateChunk, STATGROUP_ThreadPoolAsyncTasks);
	}

	void DoWork() {
		GenerateInitialChunk();
		UpdateChunkEdge();
		UKismetProceduralMeshLibrary::CalculateTangentsForMesh(MapRef->Vertices, MapRef->Triangles, MapRef->UVCoords, MapRef->Normals, MapRef->Tangents);
		MapRef->bGenerateMeshSection = true;
	}

	void GenerateInitialChunk() {
		for (int i = 0; i < MapRef->Width * MapRef->Height; i++) {
			int X = i % MapRef->Width;
			int Y = i / MapRef->Width;
			float Z = FMath::PerlinNoise2D(
				FVector2D(
					MapRef->PerlinSample(X + MapRef->OffsetX, MapRef->PerlinOffset),
					MapRef->PerlinSample(Y + MapRef->OffsetY, MapRef->PerlinOffset)
				)
			) * MapRef->PerlinScale;

			MapRef->Vertices.Add(FVector(MapRef->GridSize * X, MapRef->GridSize * Y, Z));

			//If not at the top and left of the grid
			if (X < MapRef->Width - 1 && Y < MapRef->Height - 1) {
				MapRef->Triangles.Add(i);
				MapRef->Triangles.Add(i + MapRef->Width);
				MapRef->Triangles.Add(i + 1);
			}

			//If not at the bottom and right of the grid
			if (X != 0 && Y < MapRef->Height - 1) {
				MapRef->Triangles.Add(i);
				MapRef->Triangles.Add(i + MapRef->Width - 1);
				MapRef->Triangles.Add(i + MapRef->Width);
			}

			MapRef->UVCoords.Add(FVector2D(X, Y));
		}
		
	}

	void UpdateChunkEdge() {
		int32 W = MapRef->Width;
		int32 largestSide = W > MapRef->Height ? W : MapRef->Height;
		
		for (int i = 0; i < largestSide; i++) {
			if (i < W) {
				int32 TopIndex = MapRef->Vertices.Num() - W + i;
				int32 BottomIndex = i;
				//Bottom of current map, top of bottom map.
				MapRef->Vertices[BottomIndex].Z = Neighbours[2] ? Neighbours[2]->Vertices[TopIndex].Z : MapRef->Vertices[BottomIndex].Z;

				//Top of current map, bottom of top map.
				MapRef->Vertices[TopIndex].Z = Neighbours[0] ? Neighbours[0]->Vertices[BottomIndex].Z : MapRef->Vertices[TopIndex].Z;
			}

			if (i < MapRef->Height) {
				int32 RightIndex = W * i;
				int32 LeftIndex = RightIndex + W - 1;
				//Right of current map, left of right map.
				MapRef->Vertices[RightIndex].Z = Neighbours[1] ? Neighbours[1]->Vertices[LeftIndex].Z : MapRef->Vertices[RightIndex].Z;

				//Left of current map, right of left map.
				MapRef->Vertices[LeftIndex].Z = Neighbours[3] ? Neighbours[3]->Vertices[RightIndex].Z : MapRef->Vertices[LeftIndex].Z;
			}
		}
	}
};