// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Kismet/GameplayStatics.h"
#include "KismetProceduralMeshLibrary.h"
#include "ProceduralMeshComponent.h"
#include "MapGenerator.h"
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

	UPROPERTY(VisibleAnywhere)
		UProceduralMeshComponent* MeshComponent;

	//Controlled by MapGenerator
	int32 Width;
	int32 Height;
	float GridSize;
	int32 OffsetX;
	int32 OffsetY;
	//End

	static int32 MapIndexX;
	static int32 MapIndexY;

	TArray<FVector> Vertices;
	TArray<int32> Triangles;
	TArray<FVector2D> UVCoords;

	UFUNCTION(BlueprintCallable)
		void GenerateMap();

	void ClearMap();

	//Controlled by MapGenerator
	float PerlinScale;
	float PerlinRoughness;
	float PerlinOffset;
	//End

	AMapGenerator* MapGenerator;

	TArray<FVector> Normals;
	TArray<FProcMeshTangent> Tangents;

private:
	float PerlinSample(float Axis, float Offset);
};

int32 AProcedurallyGeneratedMap::MapIndexX = 0;
int32 AProcedurallyGeneratedMap::MapIndexY = 0;