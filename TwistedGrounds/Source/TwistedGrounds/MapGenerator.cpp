// Fill out your copyright notice in the Description page of Project Settings.


#include "MapGenerator.h"

// Sets default values
AMapGenerator::AMapGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Parameters to control the ProcedurallyGeneratedMap
	ChunkWidth = 30;
	ChunkHeight = 30;
	ChunkGridSize = 200;

	PerlinOffset = FMath::RandRange(-10000.0f, 10000.0f);
	PerlinScale = 1000;
	PerlinRoughness = 0.1;
	//End

	bRegenerateMap = false;
}

// Called when the game starts or when spawned
void AMapGenerator::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMapGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bRegenerateMap && PGMap) {
		bRegenerateMap = false;


		FVector SpawnLoc = FVector(0, 0, 0);
		AProcedurallyGeneratedMap* Map = GetWorld()->SpawnActor<AProcedurallyGeneratedMap>(PGMap, SpawnLoc, FRotator::ZeroRotator);
		SetMapParams(Map, 0, 0);

		float X = ChunkWidth * ChunkGridSize - ChunkGridSize;
		float Y = ChunkHeight * ChunkGridSize - ChunkGridSize;

		SpawnLoc = FVector(X, 0, 0);
		Map = GetWorld()->SpawnActor<AProcedurallyGeneratedMap>(PGMap, SpawnLoc, FRotator::ZeroRotator);
		SetMapParams(Map, ChunkWidth - 1, 0);
	}
}

bool AMapGenerator::ShouldTickIfViewportsOnly() const
{
	return true;
}

void AMapGenerator::SetMapParams(AProcedurallyGeneratedMap* Map, int32 OffsetX, int32 OffsetY)
{
	if (!Map) {
		return;
	}

	Map->Width = ChunkWidth;
	Map->Height = ChunkHeight;
	Map->GridSize = ChunkGridSize;
	Map->PerlinScale = PerlinScale;
	Map->PerlinRoughness = PerlinRoughness;
	Map->PerlinOffset = PerlinOffset;
	Map->OffsetX = OffsetX;
	Map->OffsetY = OffsetY;
	Map->GenerateMap();
	Map->MeshComponent->SetMaterial(0, PGMaterial);
}
