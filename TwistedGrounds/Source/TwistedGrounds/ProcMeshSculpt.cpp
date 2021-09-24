// Fill out your copyright notice in the Description page of Project Settings.


#include "ProcMeshSculpt.h"
#include "Kismet/GameplayStatics.h"
#include <ProceduralMeshComponent/Public/KismetProceduralMeshLibrary.h>

// Sets default values
AProcMeshSculpt::AProcMeshSculpt()
{
	// Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SculptState = SCULPTSTATE::IDLE;
	ScaledZStrength = 70;
	bInvert = false;
}

// Called when the game starts or when spawned
void AProcMeshSculpt::BeginPlay()
{
	Super::BeginPlay();
	HitSet = false;
	Thread = new UpdateMeshThread();
}

// Called every frame
void AProcMeshSculpt::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!Muzzle || !Camera) {
		UE_LOG(LogTemp, Warning, TEXT("No Muzzle or Camera"))
		return;
	}

	Raycast();
	CheckState();

	HitResult = TracePath(Muzzle->GetComponentLocation(), Camera->GetForwardVector() * 60000, Camera->GetOwner());

	HitSet = HitResult.GetActor() != nullptr;
	if (HitSet) {
		SetActorLocation(HitResult.ImpactPoint);
	}
}

void AProcMeshSculpt::Sculpt()
{
	if (!HitSet || !&HitResult) {
		return;
	}

	int32 CalledCounter = 0;
	FVector RelativeHitLocation = GetActorLocation();
	int32 VertsPerSide = ((Map->Width - 1) * 1 + 1);
	FVector MiddleLocation = FVector(FMath::RoundToInt(RelativeHitLocation.Y / Map->GridSize), FMath::RoundToInt(RelativeHitLocation.X / Map->GridSize), 0);
	int32 CenterIndex = MiddleLocation.X * VertsPerSide + MiddleLocation.Y;

	int32 RadiusInVerts = 500 / Map->GridSize;
	int32 RadiusExtended = RadiusInVerts + 1;

	for (int32 Y = -RadiusExtended; Y <= RadiusExtended; Y++)
	{
		for (int32 X = -RadiusExtended; X <= RadiusExtended; X++)
		{
			// Continue loop if Vert doesn't exist
			int32 CurrentIndex = CenterIndex + (Y * Map->Width) + X;
			if (!Map->Vertices.IsValidIndex(CurrentIndex)) { continue; }

			FVector CurrentVertCoords = FVector(
				FMath::RoundToInt(Map->Vertices[CurrentIndex].Y / Map->GridSize),
				FMath::RoundToInt(Map->Vertices[CurrentIndex].X / Map->GridSize),
				0);
			float DistanceFromCenter = FVector::Dist(MiddleLocation, CurrentVertCoords);

			// affected normals are added to array, and calculated after loop
			if (DistanceFromCenter > RadiusExtended) { /*CalculateVertexNormal(CurrentIndex);*/ continue; }
			AffectedVertNormals.Add(CurrentIndex);

			// Check real radius
			if (DistanceFromCenter > RadiusInVerts) { /*CalculateVertexNormal(CurrentIndex);*/ continue; }

			float DistanceFraction = DistanceFromCenter / RadiusInVerts;
			CalledCounter++;
			VertexChangeHeight(DistanceFraction, CurrentIndex);
		}
	}

	// Update affected Normals
	for (int32 Vert : AffectedVertNormals)
	{
		//Normals[Vert] = CalculateVertexNormal(Vert);
	}


	Map->MeshComponent->UpdateMeshSection(0, Map->Vertices, Map->Normals, Map->UVCoords, TArray<FColor>(), Map->Tangents);
	//Thread->CreateThread(Map->MeshComponent, Map->Vertices, Map->Triangles, Map->UVCoords, Map->Normals);
}

void AProcMeshSculpt::CheckState()
{
	switch (SculptState) {

	case SCULPTSTATE::IDLE:
		break;
	case SCULPTSTATE::ONGOING:
		Sculpt();
		break;
	}
}

void AProcMeshSculpt::UpdateTangents()
{
	if (Thread->bRunningThread == false && Thread->TangentsQueue.Num() > 0) {
		Map->Tangents = Thread->TangentsQueue.Pop();
		Map->MeshComponent->UpdateMeshSection(0, Map->Vertices, Map->Normals, Map->UVCoords, TArray<FColor>(), Map->Tangents);

		UE_LOG(LogTemp, Warning, TEXT("ReUpdated"))
	}
}

void AProcMeshSculpt::Raycast()
{
	HitResult = TracePath(Muzzle->GetComponentLocation(), Camera->GetForwardVector() * 60000, Camera->GetOwner());

	HitSet = HitResult.GetActor() != nullptr;
	if (HitSet) {
		SetActorLocation(HitResult.ImpactPoint);
	}
}

void AProcMeshSculpt::VertexChangeHeight(float DistanceFraction, int32 VertexIndex)
{
	float Alpha = Curve->GetFloatValue(DistanceFraction) * 1;
	float ZValue = FMath::Lerp(70.0f, 0.f, Alpha) * 10;
	//UE_LOG(LogTemp, Warning, TEXT("Added %s"), *(FString::SanitizeFloat(ZValue)));
	Map->Vertices[VertexIndex] += (bInvert) ? (FVector(0.f, 0.f, -ZValue/ScaledZStrength)) : (FVector(0.f, 0.f, ZValue/ScaledZStrength)); // invert
}
