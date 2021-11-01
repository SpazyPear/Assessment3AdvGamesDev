// Fill out your copyright notice in the Description page of Project Settings.

#include "ProcedurallyGeneratedMap.h"
#include "MapGenerator.h"
#include "Async/AsyncWork.h"

// Sets default values
AProcedurallyGeneratedMap::AProcedurallyGeneratedMap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.

	PrimaryActorTick.bCanEverTick = true;

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

	bGenerateMeshSection = false;
}

// Called when the game starts or when spawned
void AProcedurallyGeneratedMap::BeginPlay()
{
	Super::BeginPlay();
}

bool AProcedurallyGeneratedMap::ShouldTickIfViewportsOnly() const
{
	return true;
}

// Called every frame
void AProcedurallyGeneratedMap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bGenerateMeshSection) {
		MeshComponent->CreateMeshSection(0, Vertices, Triangles, Normals, UVCoords, TArray<FColor>(), Tangents, true);
		bGenerateMeshSection = false;
	}
}

void AProcedurallyGeneratedMap::ClearMap() {
	MeshComponent->ClearAllMeshSections();
	Vertices.Empty();
	Triangles.Empty();
	UVCoords.Empty();
}

TArray<AProcedurallyGeneratedMap*> AProcedurallyGeneratedMap::GetNeighbours()
{
	FVector Pos = GetActorLocation();
	float W = (Width - 1) * GridSize;
	float H = (Height - 1) * GridSize;
	TArray<FVector> NeighbourPositions;
	NeighbourPositions.Add(FVector(Pos.X, Pos.Y + H, 0)); //Top
	NeighbourPositions.Add(FVector(Pos.X - W, Pos.Y, 0)); //Right
	NeighbourPositions.Add(FVector(Pos.X, Pos.Y - H, 0)); //Bottom
	NeighbourPositions.Add(FVector(Pos.X + W, Pos.Y, 0)); //Left

	TArray<AProcedurallyGeneratedMap*> Neighbours;
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

	return Neighbours;
}

void AProcedurallyGeneratedMap::InitiateMap(int32 W, int32 H, float GS, float PS, float PR, float PO, int32 OX, int32 OY)
{
	Width = W;
	Height = H;
	GridSize = GS;

	TArray<AProcedurallyGeneratedMap*> Neighbours = GetNeighbours();
	float Scale = PS;
	if (Neighbours.Num() > 0) {
		Scale = 0;
		int32 NeighbourCount = 0;
		for (AProcedurallyGeneratedMap* Neighbour : Neighbours) {
			if (Neighbour) {
				Scale += Neighbour->PerlinScale;
				NeighbourCount++;
			}
		}
		Scale /= NeighbourCount;
	}
	float Str = FMath::RandBool() ? FMath::FRandRange(10, 30) : 0;
	PerlinScale = Scale + (FMath::RandBool() ? Str : -Str);

	PerlinRoughness = PR;
	PerlinOffset = PO;
	OffsetX = OX;
	OffsetY = OY;
	(new FAutoDeleteAsyncTask<GenerateChunk>(this, Neighbours))->StartBackgroundTask();
}

float AProcedurallyGeneratedMap::PerlinSample(float Axis, float Offset) {
	return (Axis + Offset) * PerlinRoughness;
}