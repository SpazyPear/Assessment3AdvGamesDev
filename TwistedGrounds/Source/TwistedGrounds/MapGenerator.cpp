// Fill out your copyright notice in the Description page of Project Settings.


#include "MapGenerator.h"
#include "EngineUtils.h"
#include "Async/AsyncWork.h"

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
	
}

// Called every frame
void AMapGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bRegenerateMap) {
		bRegenerateMap = false;
		ClearMaps();
		CheckSurrounding(FVector(0, 0, 0));
	}

	for (int32 i = 0; i < Players.Num(); i++) {
		FVector PlayerPos = Players[i]->GetActorLocation();
		PlayerPos.X = RoundDownToNearest(PlayerPos.X, W);
		PlayerPos.Y = RoundDownToNearest(PlayerPos.Y, H);
		if (PlayerPos.X != PlayerPrevPos[i].X || PlayerPos.Y != PlayerPrevPos[i].Y) {
			PlayerPrevPos[i] = PlayerPos;
			CheckSurrounding(Players[i]->GetActorLocation());
		}
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

	Map->InitiateMap(ChunkWidth, ChunkHeight, ChunkGridSize, PerlinScale, PerlinRoughness, PerlinOffset, OffsetX, OffsetY);
}

void AMapGenerator::CheckSurrounding(FVector Position)
{
	//Remember the actual width of the generated map is one less due to edge cases.
	ActualW = ChunkWidth - 1;
	ActualH = ChunkHeight - 1;
	W = ActualW * ChunkGridSize; //Width of the chunk
	H = ActualH * ChunkGridSize; //Height of the chunk

	float HalfRadius = ChunkRadius / 2; //Half of the radius
	float StartX = RoundDownToNearest(Position.X, W) - W * HalfRadius;
	float StartY = RoundDownToNearest(Position.Y, H) - H * HalfRadius;
	
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
		//(new FAutoDeleteAsyncTask<GenerateChunk>(this, Map, OffsetX, OffsetY))->StartBackgroundTask();
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

int32 AMapGenerator::RoundDownToNearest(int32 Value, int32 Nearest)
{
	int32 PosValue = FMath::Abs(Value); //Mod goes towards 0, thus all values given to mod must be positive.
	int32 Result = PosValue - FMath::Fmod(PosValue, Nearest) + (Value < 0 ? Nearest : 0);
	return Value < 0 ? -Result : Result;
}
