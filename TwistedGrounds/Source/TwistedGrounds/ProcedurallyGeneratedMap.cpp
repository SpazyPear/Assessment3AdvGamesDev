// Fill out your copyright notice in the Description page of Project Settings.

#include "ProcedurallyGeneratedMap.h"
#include "MapGenerator.h"
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

	bGenerateMeshSection = false;
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
	if (bGenerateMeshSection) {
		bGenerateMeshSection = false;
		UKismetProceduralMeshLibrary::CalculateTangentsForMesh(Vertices, Triangles, UVCoords, Normals, Tangents);
		MeshComponent->CreateMeshSection(0, Vertices, Triangles, Normals, UVCoords, TArray<FColor>(), Tangents, true);
	}
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
}

void AProcedurallyGeneratedMap::ClearMap() {
	MeshComponent->ClearAllMeshSections();
	Vertices.Empty();
	Triangles.Empty();
	UVCoords.Empty();
}

void AProcedurallyGeneratedMap::InitiateMap(int32 W, int32 H, float GS, float PS, float PR, float PO, int32 OX, int32 OY)
{
	Width = W;
	Height = H;
	GridSize = GS;
	PerlinScale = PS;
	PerlinRoughness = PR;
	PerlinOffset = PO;
	OffsetX = OX;
	OffsetY = OY;
	GenerateMap();
}

float AProcedurallyGeneratedMap::PerlinSample(float Axis, float Offset) {
	return (Axis + Offset) * PerlinRoughness;
}