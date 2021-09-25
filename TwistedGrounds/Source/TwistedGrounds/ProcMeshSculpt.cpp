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
	SculptAmmo = 10.0f;
	AmmoCost = 3.0f;
	AmmoRegen = 2.0f;
	TangentsToBeUpdated = 0;
	CapHeight = false;
	
}

// Called when the game starts or when spawned
void AProcMeshSculpt::BeginPlay()
{
	MaxAmmo = SculptAmmo;
	Super::BeginPlay();
	HitSet = false;
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
	CheckState(DeltaTime);
	RegenAmmo(DeltaTime);
	UpdateTangents();

	HitSet = HitResult.GetActor() != nullptr;
	if (HitSet) {
		SetActorHiddenInGame(false);
		SetActorLocation(HitResult.ImpactPoint);
	}
	else {
		SetActorHiddenInGame(true);
	}
}

void AProcMeshSculpt::Sculpt()
{
	if (!HitSet || !&HitResult) {
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("Strength: %f"), ScaledZStrength)
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

	
			if (DistanceFromCenter > RadiusExtended) { continue; }
			AffectedVertNormals.Add(CurrentIndex);

			if (DistanceFromCenter > RadiusInVerts) { continue; }

			float DistanceFraction = DistanceFromCenter / RadiusInVerts;
			CalledCounter++;
			VertexChangeHeight(DistanceFraction, CurrentIndex);
			
		}
	}
	
	TangentsToBeUpdated++;
	Map->MeshComponent->UpdateMeshSection(0, Map->Vertices, Map->Normals, Map->UVCoords, TArray<FColor>(), Map->Tangents);
	
}


void AProcMeshSculpt::CheckState(float DeltaTime)
{
	switch (SculptState) {

	case SCULPTSTATE::IDLE:
		break;
	case SCULPTSTATE::ONGOING:
		if (SculptAmmo > 0.0f) {
			SculptAmmo -= AmmoCost * DeltaTime;
			UE_LOG(LogTemp, Warning, TEXT("Ammo: %f"), SculptAmmo)
			Sculpt();
		}
		break;
	case SCULPTSTATE::STOPPED:
		SculptState = SCULPTSTATE::IDLE; //stub
	}
}

void AProcMeshSculpt::RegenAmmo(float DeltaTime)
{
	if (SculptState == SCULPTSTATE::IDLE && SculptAmmo < MaxAmmo) {
		SculptAmmo += AmmoRegen * DeltaTime;
		SculptAmmo = FMath::Clamp(SculptAmmo, 0.0f, MaxAmmo);
	}
}

void AProcMeshSculpt::UpdateTangents()
{
	if (TangentsToBeUpdated > 0) {
		UKismetProceduralMeshLibrary::CalculateTangentsForMesh(Map->Vertices, Map->Triangles, Map->UVCoords, Map->Normals, Map->Tangents);
		TangentsToBeUpdated--;
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
	if (Map->Vertices[VertexIndex].Z > CappedHeight && !CapHeight) {
		CappedHeight = Map->Vertices[VertexIndex].Z;
		
	}
	
	float Alpha = Curve->GetFloatValue(DistanceFraction) * 1;
	float ZValue = FMath::Lerp(ScaledZStrength, 0.f, Alpha) * 10;
	//ZValue /= ScaledZStrength;

	if (Map->Vertices[VertexIndex].Z + ZValue > CappedHeight && CapHeight) {
		return;
	}

	Map->Vertices[VertexIndex] += (bInvert) ? (FVector(0.f, 0.f, -ZValue)) : (FVector(0.f, 0.f, ZValue)); // invert
}
