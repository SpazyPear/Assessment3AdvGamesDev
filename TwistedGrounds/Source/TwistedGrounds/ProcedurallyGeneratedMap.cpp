// Fill out your copyright notice in the Description page of Project Settings.

#include "ProcedurallyGeneratedMap.h"
#include "MapGenerator.h"
#include "EngineUtils.h"
#include "DoStatic.h"
#include "Net/UnrealNetwork.h"

// Sets default values
AProcedurallyGeneratedMap::AProcedurallyGeneratedMap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
	bAlwaysRelevant = true;

	MeshComponent = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("Mesh Component"));
	SetRootComponent(MeshComponent);

	Width = 30;
	Height = 30;
	GridSize = 200;
	PerlinScale = 1000;
	PerlinRoughness = 0.1;
	PerlinOffset = FMath::RandRange(-10000.0f, 10000.0f);
	OffsetX = 0;
	OffsetY = 0;

	BiomeIndex = 0;
	Top = nullptr;
	Right = nullptr;
	Bottom = nullptr;
	Left = nullptr;

	bUpdateMap = false;
}

// Called when the game starts or when spawned
void AProcedurallyGeneratedMap::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AProcedurallyGeneratedMap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bUpdateMap) {
		bUpdateMap = false;
		UKismetProceduralMeshLibrary::CalculateTangentsForMesh(Vertices, Triangles, UVCoords, Normals, Tangents);
		MeshComponent->CreateMeshSection(0, Vertices, Triangles, Normals, UVCoords, TArray<FColor>(), Tangents, true);
		//PrimaryActorTick.bCanEverTick = false;
	}
}

void AProcedurallyGeneratedMap::SetMapValues(int32 W, int32 H, float GS, float PS, float PSO, float PR, float PO, int32 OX, int32 OY)
{
	Width = W;
	Height = H;
	GridSize = GS;

	PerlinScale = PS;
	UpdateNeighbours(); //factor the neighbours
	UpdateMapValues(PSO);

	PerlinRoughness = PR;
	PerlinOffset = PO;
	OffsetX = OX;
	OffsetY = OY;
}

void AProcedurallyGeneratedMap::UpdateNeighbours()
{
	if (Top && Right && Bottom && Left) {
		return;
	}

	FVector Pos = GetActorLocation();
	float W = (Width - 1) * GridSize;
	float H = (Height - 1) * GridSize;
	TArray<FVector> NeighbourPositions;
	NeighbourPositions.Add(FVector(Pos.X, Pos.Y + H, 0)); //Top
	NeighbourPositions.Add(FVector(Pos.X - W, Pos.Y, 0)); //Right
	NeighbourPositions.Add(FVector(Pos.X, Pos.Y - H, 0)); //Bottom
	NeighbourPositions.Add(FVector(Pos.X + W, Pos.Y, 0)); //Left

	for (TActorIterator<AProcedurallyGeneratedMap> EachMap(GetWorld()); EachMap; ++EachMap) {
		FVector MapPos = (*EachMap)->GetActorLocation();
		if (!NeighbourPositions.Contains(MapPos)) {
			continue;
		}

		Top = MapPos.Y > Pos.Y ? *EachMap : Top;
		Right = MapPos.X < Pos.X ? *EachMap : Right;
		Bottom = MapPos.Y < Pos.Y ? *EachMap : Bottom;
		Left = MapPos.X > Pos.X ? *EachMap : Left;

		if (Top && Right && Bottom && Left) {
			return;
		}
	}
}

void AProcedurallyGeneratedMap::UpdateMapValues(float PSO)
{
	float Scale = 0;
	int32 NeighbourCount = 0;
	TArray<int32> SurroundingBiomes;
	TArray<AProcedurallyGeneratedMap*> Neighbours;
	Neighbours.Add(Top);
	Neighbours.Add(Left);
	Neighbours.Add(Bottom);
	Neighbours.Add(Right);

	for (AProcedurallyGeneratedMap* Neighbour : Neighbours) {
		if (!Neighbour) {
			SurroundingBiomes.Add(0); //Default biome
			continue;
		}
		Scale += Neighbour->PerlinScale;
		SurroundingBiomes.Add(Neighbour->BiomeIndex);
		NeighbourCount++;
	}
	Scale += PerlinScale;
	Scale /= ++NeighbourCount;
	PerlinScale = Scale + (FMath::RandBool() ? PSO : -PSO);

	BiomeIndex = 0;
	if (SurroundingBiomes.Contains(1) && SurroundingBiomes.Contains(2)) {} //Do nothing
	else if (SurroundingBiomes.Contains(1)) {
		BiomeIndex = FMath::RandBool() ? 1 : BiomeIndex;
	}
	else if (SurroundingBiomes.Contains(2)) {
		BiomeIndex = FMath::RandBool() ? 2 : BiomeIndex;
	}
	else {
		BiomeIndex = FMath::Rand() % 3;
	}
}

void AProcedurallyGeneratedMap::UpdateChunkEdge()
{
	int32 largestSide = Width > Height ? Width : Height;
	for (int i = 0; i < largestSide; i++) {
		if (i < Width) {
			int32 TopIndex = Vertices.Num() - Width + i;
			int32 BottomIndex = i;
			//Bottom of current map, top of bottom map.
			Vertices[BottomIndex].Z = Bottom ? Bottom->Vertices[TopIndex].Z : Vertices[BottomIndex].Z;

			//Top of current map, bottom of top map.
			Vertices[TopIndex].Z = Top? Top->Vertices[BottomIndex].Z : Vertices[TopIndex].Z;
		}

		if (i < Height) {
			int32 RightIndex = Width * i;
			int32 LeftIndex = RightIndex + Width - 1;
			//Right of current map, left of right map.
			Vertices[RightIndex].Z = Right ? Right->Vertices[LeftIndex].Z : Vertices[RightIndex].Z;

			//Left of current map, right of left map.
			Vertices[LeftIndex].Z = Left ? Left->Vertices[RightIndex].Z : Vertices[LeftIndex].Z;
		}
	}
}

void AProcedurallyGeneratedMap::NetMulticastGenerateMap_Implementation() {
	(new FAutoDeleteAsyncTask<GenerateChunk>(this))->StartBackgroundTask();
}

void AProcedurallyGeneratedMap::GenerateMap()
{
	for (int i = 0; i < Width * Height; i++) {
		int X = i % Width;
		int Y = i / Width;
		float Z = FMath::PerlinNoise2D(FVector2D(PerlinSample(X + OffsetX, PerlinOffset), PerlinSample(Y + OffsetY, PerlinOffset))) * PerlinScale;
		Vertices.Add(FVector(GridSize * X, GridSize * Y, Z));

		//If not at the top and left of the grid
		if (X < Width - 1 && Y < Height - 1) {
			Triangles.Add(i);
			Triangles.Add(i + Width);
			Triangles.Add(i + 1);
		}

		//If not at the bottom and right of the grid
		if (X != 0 && Y < Height - 1) {
			Triangles.Add(i);
			Triangles.Add(i + Width - 1);
			Triangles.Add(i + Width);
		}

		UVCoords.Add(FVector2D(X, Y));
	}
	UpdateChunkEdge();
	UKismetProceduralMeshLibrary::CalculateTangentsForMesh(Vertices, Triangles, UVCoords, Normals, Tangents);
	MeshComponent->SetMaterial(0, Biomes[BiomeIndex]);
	bUpdateMap = true;
}

float AProcedurallyGeneratedMap::PerlinSample(float Axis, float Offset) {
	return (Axis + Offset) * PerlinRoughness;
}

void AProcedurallyGeneratedMap::ClearMap() {
	MeshComponent->ClearAllMeshSections();
	Vertices.Empty();
	Triangles.Empty();
	UVCoords.Empty();
}

void AProcedurallyGeneratedMap::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AProcedurallyGeneratedMap, Width);
	DOREPLIFETIME(AProcedurallyGeneratedMap, Height);
	DOREPLIFETIME(AProcedurallyGeneratedMap, GridSize);
	DOREPLIFETIME(AProcedurallyGeneratedMap, PerlinScale);
	DOREPLIFETIME(AProcedurallyGeneratedMap, PerlinRoughness);
	DOREPLIFETIME(AProcedurallyGeneratedMap, PerlinOffset);
	DOREPLIFETIME(AProcedurallyGeneratedMap, OffsetX);
	DOREPLIFETIME(AProcedurallyGeneratedMap, OffsetY);
	DOREPLIFETIME(AProcedurallyGeneratedMap, BiomeIndex);
	DOREPLIFETIME(AProcedurallyGeneratedMap, Top);
	DOREPLIFETIME(AProcedurallyGeneratedMap, Right);
	DOREPLIFETIME(AProcedurallyGeneratedMap, Bottom);
	DOREPLIFETIME(AProcedurallyGeneratedMap, Left);
}
