// Fill out your copyright notice in the Description page of Project Settings.


#include "MapGenerator.h"
#include "EngineUtils.h"

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
	ClearMaps(); //Generates the map first.

	//For now there is only one player.
	Player.Add(GetWorld()->SpawnActor<APlayerCharacter>(PlayerToSpawn, FVector(0, 0, 2000), FRotator::ZeroRotator));

	for (APlayerCharacter* EachPlayer : Player) {
		EachPlayer->MeshSculptor = Sculptor;
		EachPlayer->BigDustEmitterToSpawn = BigDustEmitter;
		EachPlayer->SmallDustEmitterToSpawn = SmallDustEmitter;
		EachPlayer->SetSculptor();
	}
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

	for (APlayerCharacter* EachPlayer : Player) {
		CheckSurrounding(EachPlayer->GetActorLocation());
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

void AMapGenerator::CheckSurrounding(FVector Position)
{
	//Remember the actual width of the generated map is one less due to edge cases.
	int ActualW = ChunkWidth - 1;
	int ActualH = ChunkHeight - 1;
	int W = ActualW * ChunkGridSize;
	int H = ActualH * ChunkGridSize;
	
	int StartX = RoundDownToNearest(Position.X, W) - W;
	int StartY = RoundDownToNearest(Position.Y, H) - H;

	for (int i = 0; i < 9; i++) {
		int XMult = (i % 3);
		int YMult = (i / 3);

		int X = StartX + W * XMult;
		int Y = StartY + H * YMult;
		FVector Loc = FVector(X, Y, 0);
		if (MapPoints.Contains(Loc)) { //If there is already a map there do nothing
			continue;
		}

		//Else Generate the map.
		AProcedurallyGeneratedMap* Map = GetWorld()->SpawnActor<AProcedurallyGeneratedMap>(PGMap, Loc, FRotator::ZeroRotator);

		int32 OffsetX = ActualW * XMult;
		int32 OffsetY = ActualW * YMult;
		if (Map) {
			SetMapParams(Map, OffsetX, OffsetY);
		}
		else {
			UE_LOG(LogTemp, Error, TEXT("THE MAP WAS NOT ABLE TO SPAWN"))
		}

		MapPoints.Add(Loc);
	}
}

void AMapGenerator::ClearMaps()
{
	for (TActorIterator<AProcedurallyGeneratedMap> EveryMap(GetWorld()); EveryMap; ++EveryMap) {
		(*EveryMap)->Destroy();
	}
}

int32 AMapGenerator::RoundDownToNearest(int32 Value, int32 Nearest)
{
	int32 Result = Value - FMath::Fmod(Value, Nearest);
	return Result;
}
