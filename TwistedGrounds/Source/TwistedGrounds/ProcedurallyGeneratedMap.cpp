// Fill out your copyright notice in the Description page of Project Settings.

#include "ProcedurallyGeneratedMap.h"

// Sets default values
AProcedurallyGeneratedMap::AProcedurallyGeneratedMap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComponent = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("Mesh Component"));
	
	Width = 30;
	Height = 30;
	GridSize = 200;

	PerlinScale = 1000;
	PerlinRoughness = 0.1;
	bRegenerateMap = false;
}

// Called when the game starts or when spawned
void AProcedurallyGeneratedMap::BeginPlay()
{
	Super::BeginPlay();
	bRegenerateMap = !UGameplayStatics::DoesSaveGameExist(TEXT("SavedMap"), 0);
	if (!bRegenerateMap) {
		LoadMap();
	}
}

// Called every frame
void AProcedurallyGeneratedMap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bRegenerateMap) {
		ClearMap();
		GenerateMap();
		bRegenerateMap = false;
		SaveMap();
	}
}

void AProcedurallyGeneratedMap::GenerateMap() {
	float PerlinOffset = FMath::RandRange(-10000.0f, 10000.0f);
	for (int i = 0; i < Width * Height; i++) {
		int X = i % Width;
		int Y = i / Width;
		float Z = FMath::PerlinNoise2D(FVector2D(PerlinSample(X, PerlinOffset), PerlinSample(Y, PerlinOffset))) * PerlinScale;
		Vertices.Add(FVector(GridSize * X, GridSize * Y, Z));

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

void AProcedurallyGeneratedMap::ClearMap() {
	MeshComponent->ClearAllMeshSections();
	Vertices.Empty();
	Triangles.Empty();
	UVCoords.Empty();
}

float AProcedurallyGeneratedMap::PerlinSample(float Axis, float Offset) {
	return (Axis + Offset) * PerlinRoughness;
}

void AProcedurallyGeneratedMap::SaveMap() {
	USavedMap* Map = Cast<USavedMap>(UGameplayStatics::CreateSaveGameObject(USavedMap::StaticClass()));
	Map->Vertices = Vertices;
	Map->Triangles = Triangles;
	Map->UVCoords = UVCoords;
	Map->Normals = Normals;
	Map->Tangents = Tangents;
	UGameplayStatics::SaveGameToSlot(Map, TEXT("SavedMap"), 0);
	UE_LOG(LogTemp, Warning, TEXT("Saved Map"))
}

void AProcedurallyGeneratedMap::LoadMap() {
	USavedMap* Map = Cast<USavedMap>(UGameplayStatics::LoadGameFromSlot(TEXT("SavedMap"), 0));
	Vertices = Map->Vertices;
	Triangles = Map->Triangles;
	UVCoords = Map->UVCoords;
	Normals = Map->Normals;
	Tangents = Map->Tangents;
	UE_LOG(LogTemp, Warning, TEXT("Loaded Map"))
}

bool AProcedurallyGeneratedMap::ShouldTickIfViewportsOnly() const {
	return true;
}