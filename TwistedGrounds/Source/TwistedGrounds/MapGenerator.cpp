// Fill out your copyright notice in the Description page of Project Settings.


#include "MapGenerator.h"
#include "EngineUtils.h"
#include "DoStatic.h"

// Sets default values
AMapGenerator::AMapGenerator()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Parameters to control the ProcedurallyGeneratedMap
	ChunkRadius = 3;
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
	UpdateProperties();
}

// Called every frame
void AMapGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bRegenerateMap) {
		bRegenerateMap = false;
		ClearMaps();
		UpdateProperties();
		CheckSurrounding(FVector(0, 0, 0));
	}
}

bool AMapGenerator::ShouldTickIfViewportsOnly() const
{
	return true;
}

void AMapGenerator::UpdateProperties() {
	//Remember the actual width of the generated map is one less due to edge cases.
	ActualW = ChunkWidth - 1;
	ActualH = ChunkHeight - 1;
	W = ActualW * ChunkGridSize; //Width of the chunk
	H = ActualH * ChunkGridSize; //Height of the chunk
}

void AMapGenerator::SetMapParams(AProcedurallyGeneratedMap* Map, int32 OffsetX, int32 OffsetY)
{
	if (!Map) {
		return;
	}

	Map->InitiateMap(ChunkWidth, ChunkHeight, ChunkGridSize, PerlinScale, PerlinRoughness, PerlinOffset, OffsetX, OffsetY);
}

FVector AMapGenerator::RoundDownPosition(FVector Position) {
	float X = DoStatic::RoundDownToNearest(Position.X, W);
	float Y = DoStatic::RoundDownToNearest(Position.Y, H);
	return FVector(X, Y, 0);
}

void AMapGenerator::CheckSurrounding(FVector Position)
{
	float HalfRadius = ChunkRadius / 2; //Half of the radius
	FVector Pos = RoundDownPosition(Position);
	float StartX = Pos.X - W * HalfRadius;
	float StartY = Pos.Y - H * HalfRadius;
	
	for (int i = 0; i < ChunkRadius * ChunkRadius; i++) {
		int XMult = (i % ChunkRadius);
		int YMult = (i / ChunkRadius);

		int X = StartX + W * XMult;
		int Y = StartY + H * YMult;
		FVector Loc = FVector(X, Y, 0);
		if (MapPoints.Contains(Loc)) { //If there is a location, it would most likely mean there is a map
			continue;
		}

		//Else Generate the map.
		AProcedurallyGeneratedMap* Map = GetWorld()->SpawnActor<AProcedurallyGeneratedMap>(PGMap, Loc, FRotator::ZeroRotator);
		int32 OffsetX = ActualW * (X / W); //X offset for perlin noise
		int32 OffsetY = ActualH * (Y / H); //Y offset for perlin noise
		SetMapParams(Map, OffsetX, OffsetY);
		MapPoints.Add(Loc); //Save the location of the map
	}
}

void AMapGenerator::ClearMaps()
{
	for (TActorIterator<AProcedurallyGeneratedMap> EveryMap(GetWorld()); EveryMap; ++EveryMap) {
		(*EveryMap)->Destroy();
	}
	MapPoints.Empty(); //Emptied so that a new map can be generated there.
}
