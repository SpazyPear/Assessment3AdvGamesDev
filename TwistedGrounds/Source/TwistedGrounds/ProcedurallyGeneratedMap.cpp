// Fill out your copyright notice in the Description page of Project Settings.

#include "ProcedurallyGeneratedMap.h"
#include "EngineUtils.h"

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
	UKismetProceduralMeshLibrary::CalculateTangentsForMesh(Vertices, Triangles, UVCoords, Normals, Tangents);
	MeshComponent->CreateMeshSection(0, Vertices, Triangles, Normals, UVCoords, TArray<FColor>(), Tangents, true);

	for (TActorIterator<AProcedurallyGeneratedMap> AllMaps(GetWorld()); AllMaps; ++AllMaps) {
		(*AllMaps)->GetNeighbours();
	}
}

void AProcedurallyGeneratedMap::ClearMap() {
	MeshComponent->ClearAllMeshSections();
	Vertices.Empty();
	Triangles.Empty();
	UVCoords.Empty();
}

void AProcedurallyGeneratedMap::UpdateEdges()
{
	for (int32 i = 0; i < Width; i++) {
		if (Neighbours[0]) { //Sync top edge to map above
			Vertices[Vertices.Num() - Width + i].Z = Neighbours[0]->Vertices[i].Z;
		}

		if (Neighbours[1]) { //Sync bottom edge to map below
			Vertices[i].Z = Neighbours[1]->Vertices[Vertices.Num() - Width + i].Z;
		}
	}

	for (int32 i = 0; i < Height; i++) {
		if (Neighbours[2]) { //Sync left edge to map on the left
			Vertices[Width * (i + 1) - 1].Z = Neighbours[2]->Vertices[Width * i].Z;
		}

		if (Neighbours[3]) { //Sync right edge to map on the right
			Vertices[Width * i].Z = Neighbours[3]->Vertices[Width * (i + 1) - 1].Z;
		}
	}
	MeshComponent->UpdateMeshSection(0, Vertices, Normals, UVCoords, TArray<FColor>(), Tangents);
}

void AProcedurallyGeneratedMap::UpdateNeighbours()
{
	for (AProcedurallyGeneratedMap* Neighbour : Neighbours) {
		Neighbour->UpdateEdges();
	}
}

float AProcedurallyGeneratedMap::PerlinSample(float Axis, float Offset) {
	return (Axis + Offset) * PerlinRoughness;
}

void AProcedurallyGeneratedMap::GetNeighbours()
{
	if (Neighbours.Num() == 0) { //Allows the map to be generated with no problems in the editor.
		for (int32 i = 0; i < 4; i++) {
			Neighbours.Add(nullptr);
		}
	}

	bool bHasFullNeighbours = Neighbours[0] && Neighbours[1] && Neighbours[2] && Neighbours[3];
	if (bHasFullNeighbours) {
		return;
	}
	
	Neighbours.Empty();
	for (int32 i = 0; i < 4; i++) {
		Neighbours.Add(nullptr);
	}

	FVector Pos = GetActorLocation();
	int32 WIncrement = GridSize * (Width - 1);
	int32 HIncrement = GridSize * (Height - 1);

	TArray<FVector> NPos; //Short for NeighbourPositions
	NPos.Add(FVector(Pos.X, Pos.Y + HIncrement, 0)); //Top
	NPos.Add(FVector(Pos.X, Pos.Y - HIncrement, 0)); //Bottom
	NPos.Add(FVector(Pos.X + WIncrement, Pos.Y, 0)); //Left
	NPos.Add(FVector(Pos.X - WIncrement, Pos.Y, 0)); //Right

	for (TActorIterator<AProcedurallyGeneratedMap> Map(GetWorld()); Map; ++Map) {
		if (bHasFullNeighbours) {
			return;
		}

		FVector Loc = (*Map)->GetActorLocation();
		if (!NPos.Contains(Loc)) {
			continue;
		}

		for (int32 i = 0; i < NPos.Num(); i++) {
			if (NPos[i] == Loc) {
				Neighbours[i] = *Map;
			}
		}
	}
}
