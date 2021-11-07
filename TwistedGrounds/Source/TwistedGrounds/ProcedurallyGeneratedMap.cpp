// Fill out your copyright notice in the Description page of Project Settings.

#include "ProcedurallyGeneratedMap.h"
#include "MapGenerator.h"
#include "EngineUtils.h"
#include "DoStatic.h"

// Sets default values
AProcedurallyGeneratedMap::AProcedurallyGeneratedMap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.

	PrimaryActorTick.bCanEverTick = false; //THIS IS SET TO FALSE, SET TO TRUE IF TICK IS NEEDED.

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
	//PrimaryActorTick.bCanEverTick is set to False!
}

void AProcedurallyGeneratedMap::GenerateMap() {
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
	MeshComponent->CreateMeshSection(0, Vertices, Triangles, Normals, UVCoords, TArray<FColor>(), Tangents, true);
}

void AProcedurallyGeneratedMap::UpdateNeighbours()
{
	Neighbours.Empty();
	FVector Pos = GetActorLocation();
	float W = (Width - 1) * GridSize;
	float H = (Height - 1) * GridSize;
	TArray<FVector> NeighbourPositions;
	NeighbourPositions.Add(FVector(Pos.X, Pos.Y + H, 0)); //Top
	NeighbourPositions.Add(FVector(Pos.X - W, Pos.Y, 0)); //Right
	NeighbourPositions.Add(FVector(Pos.X, Pos.Y - H, 0)); //Bottom
	NeighbourPositions.Add(FVector(Pos.X + W, Pos.Y, 0)); //Left

	for (int i = 0; i < 4; i++) {
		Neighbours.Add(nullptr);
	}

	for (TActorIterator<AProcedurallyGeneratedMap> EachMap(GetWorld()); EachMap; ++EachMap) {
		FVector MapPos = (*EachMap)->GetActorLocation();
		if (!NeighbourPositions.Contains(MapPos)) {
			continue;
		}

		if (MapPos.Y > Pos.Y) { //Top
			Neighbours[0] = *EachMap;
		}
		else if (MapPos.X < Pos.X) { //Right
			Neighbours[1] = *EachMap;
		}
		else if (MapPos.Y < Pos.Y) { //Bottom
			Neighbours[2] = *EachMap;
		}
		else if (MapPos.X > Pos.X) {
			Neighbours[3] = *EachMap; //Left
		}

		if (Neighbours[0] && Neighbours[1] && Neighbours[2] && Neighbours[3]) {
			break;
		}
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
			Vertices[BottomIndex].Z = Neighbours[2] ? Neighbours[2]->Vertices[TopIndex].Z : Vertices[BottomIndex].Z;

			//Top of current map, bottom of top map.
			Vertices[TopIndex].Z = Neighbours[0] ? Neighbours[0]->Vertices[BottomIndex].Z : Vertices[TopIndex].Z;
		}

		if (i < Height) {
			int32 RightIndex = Width * i;
			int32 LeftIndex = RightIndex + Width - 1;
			//Right of current map, left of right map.
			Vertices[RightIndex].Z = Neighbours[1] ? Neighbours[1]->Vertices[LeftIndex].Z : Vertices[RightIndex].Z;

			//Left of current map, right of left map.
			Vertices[LeftIndex].Z = Neighbours[3] ? Neighbours[3]->Vertices[RightIndex].Z : Vertices[LeftIndex].Z;
		}
	}
}

void AProcedurallyGeneratedMap::ClearMap() {
	MeshComponent->ClearAllMeshSections();
	Vertices.Empty();
	Triangles.Empty();
	UVCoords.Empty();
}

void AProcedurallyGeneratedMap::InitiateMap(int32 W, int32 H, float GS, float PS, float PR, float PO, int32 OX, int32 OY, float PSO)
{
	Width = W;
	Height = H;
	GridSize = GS;

	UpdateNeighbours();
	float Scale = 0;
	int32 NeighbourCount = 0;
	TArray<int32> SurroundingBiomes;
	for (AProcedurallyGeneratedMap* Neighbour : Neighbours) {
		if (!Neighbour) {
			SurroundingBiomes.Add(0); //Default biome
			continue;
		}
		Scale += Neighbour->PerlinScale;
		SurroundingBiomes.Add(Neighbour->BiomeIndex);
		NeighbourCount++;
	}
	Scale += PS;
	Scale /= ++NeighbourCount;
	PerlinScale = Scale + (FMath::RandBool() ? PSO : -PSO);

	PerlinRoughness = PR;
	PerlinOffset = PO;
	OffsetX = OX;
	OffsetY = OY;
	GenerateMap();

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

	MeshComponent->SetMaterial(0, Biomes[BiomeIndex]);
}

float AProcedurallyGeneratedMap::PerlinSample(float Axis, float Offset) {
	return (Axis + Offset) * PerlinRoughness;
}