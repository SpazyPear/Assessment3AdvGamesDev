// Fill out your copyright notice in the Description page of Project Settings.


#include "PGRoom.h"
#include "KismetProceduralMeshLibrary.h"

// Sets default values
APGRoom::APGRoom()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComponent = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("Mesh Component"));
	Width = 5;
	Height = 5;
	GridSize = 100;
}

// Called when the game starts or when spawned
void APGRoom::BeginPlay()
{
	Super::BeginPlay();
	GenerateMap();
}

// Called every frame
void APGRoom::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APGRoom::GenerateMap() {
	float PerlinOffset = FMath::RandRange(-10000.0f, 10000.0f);
	for (int i = 0; i < Width * Height; i++) {
		int X = i % Width;
		int Y = i / Width;
		Vertices.Add(FVector(GridSize * X, GridSize * Y, 0));

		//If not at the top and left of the grid
		if (X < Width - 1 && Y < Height - 1) {
			Triangles.Add(i);
			Triangles.Add(i + Width);
			Triangles.Add(i + 1);
		}
		if (X != 0 && Y < Height - 1) { //If not at the bottom and right of the grid
			Triangles.Add(i);
			Triangles.Add(i + Width - 1);
			Triangles.Add(i + Width);
		}

		UVCoords.Add(FVector2D(X, Y));
	}
	UKismetProceduralMeshLibrary::CalculateTangentsForMesh(Vertices, Triangles, UVCoords, Normals, Tangents);
	MeshComponent->CreateMeshSection(0, Vertices, Triangles, Normals, UVCoords, TArray<FColor>(), Tangents, true);
}

void APGRoom::ClearMap() {
	MeshComponent->ClearAllMeshSections();
	Vertices.Empty();
	Triangles.Empty();
	UVCoords.Empty();
}