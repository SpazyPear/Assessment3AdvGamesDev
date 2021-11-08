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
	void UpdateNeighbours();

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	//Controlled by MapGenerator
	UPROPERTY(Replicated) int32 Width;
	UPROPERTY(Replicated) int32 Height;
	UPROPERTY(Replicated) float GridSize;
	UPROPERTY(Replicated) float PerlinScale;
	UPROPERTY(Replicated) float PerlinScaleOffset;
	UPROPERTY(Replicated) float PerlinRoughness;
	UPROPERTY(Replicated) float PerlinOffset;
	UPROPERTY(Replicated) int32 OffsetX;
	UPROPERTY(Replicated) int32 OffsetY;
	UPROPERTY(Replicated) int32 BiomeIndex;
	UPROPERTY(Replicated) AProcedurallyGeneratedMap* Top; //Could be a TArray but not sure if TArray can be replicated
	UPROPERTY(Replicated) AProcedurallyGeneratedMap* Right;
	UPROPERTY(Replicated) AProcedurallyGeneratedMap* Bottom;
	UPROPERTY(Replicated) AProcedurallyGeneratedMap* Left;
	//End

	UPROPERTY() UProceduralMeshComponent* MeshComponent;
	UPROPERTY() TArray<FVector> Vertices;
	UPROPERTY() TArray<int32> Triangles;
	UPROPERTY() TArray<FVector2D> UVCoords;

	TArray<FVector> Normals;
	TArray<FProcMeshTangent> Tangents;

	UPROPERTY(EditDefaultsOnly) TArray<UMaterialInterface*> Biomes;

	UFUNCTION(NetMulticast, Reliable)
		void NetMulticastGenerateMap();

private:
	float PerlinSample(float Axis, float Offset);
	void ClearMap();
	void UpdateMapValues();
	void UpdateChunkEdge();

};
