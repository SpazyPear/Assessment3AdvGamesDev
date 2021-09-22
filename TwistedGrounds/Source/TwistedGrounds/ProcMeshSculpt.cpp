// Fill out your copyright notice in the Description page of Project Settings.


#include "ProcMeshSculpt.h"
#include "Kismet/GameplayStatics.h"
#include <ProceduralMeshComponent/Public/KismetProceduralMeshLibrary.h>

// Sets default values
AProcMeshSculpt::AProcMeshSculpt()
{
	// Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
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

	//Don't know where this would go, before or after the predict projectile path
	if (Thread->bRunningThread == false && Thread->TangentsQueue.Num() > 0) {
		Map->Tangents = Thread->TangentsQueue.Pop();
		Map->MeshComponent->UpdateMeshSection(0, Map->Vertices, Map->Normals, Map->UVCoords, TArray<FColor>(), Map->Tangents);

		UE_LOG(LogTemp, Warning, TEXT("ReUpdated"))
	}

	if (!Muzzle || !Camera) {
		UE_LOG(LogTemp, Warning, TEXT("No Muzzle or Camera"))
		return;
	}

	HitResult = TracePath(Muzzle->GetComponentLocation(), Camera->GetForwardVector() * 60000, Camera->GetOwner());

	HitSet = HitResult.GetActor() != nullptr;
	if (HitSet) {
		SetActorLocation(HitResult.ImpactPoint);
	}
}

void AProcMeshSculpt::Sculpt()
{
	if (!HitSet) {
		return;
	}

	int32 CalledCounter = 0;
	FHitResult* HitResultPtr = &HitResult;
	if (HitResultPtr) {
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
				// execute selected sculpt function for each vertex in radius
				//if (InputInfo.SculptInput != ESculptInput::ST_Stopped)
				//{
					float DistanceFraction = DistanceFromCenter / RadiusInVerts;

				//	case ESculptMode::ST_Sculpt:
						//VertexChangeHeight(CurrentIndex, DistanceFraction);
					CalledCounter++;

					VertexChangeHeight(DistanceFraction, CurrentIndex);
				//}

				//FVector SectionCoordinates = FVector(SectionIndex / (ComponentXY), SectionIndex % (ComponentXY), 0);

				//FVector SectionVertCoords = CurrentVertCoords - (SectionCoordinates * SectionXY - SectionCoordinates);
				//int32 SectionVertIndex = SectionVertCoords.X * SectionXY + SectionVertCoords.Y;

				//if (SectionVertCoords.X > SectionXY - 1 || SectionVertCoords.X < 0 || SectionVertCoords.Y > SectionXY - 1 || SectionVertCoords.Y < 0) { continue; }
				//if (!SectionProperties.SectionPosition.IsValidIndex(SectionVertIndex)) { continue; }

				//AddAffectedSections(SectionIndex, SectionVertIndex, OUT AffectedSections);
			}
		}

		// Update affected Normals
		for (int32 Vert : AffectedVertNormals)
		{
			//Normals[Vert] = CalculateVertexNormal(Vert);
		}

		// Update section directly or via Queue
		/*for (int32 Iter : AffectedSections)
		{
			if (!SectionActors.IsValidIndex(Iter)) { continue; }
			(Settings.bUseUpdateQueue && !SectionUpdateQueue.Contains(Iter)) ? (SectionUpdateQueue.Add(Iter)) : (SectionActors[Iter]->UpdateSection());
		}*/
		Map->MeshComponent->UpdateMeshSection(0, Map->Vertices, Map->Normals, Map->UVCoords, TArray<FColor>(), Map->Tangents);
		Thread->CreateThread(Map->MeshComponent, Map->Vertices, Map->Triangles, Map->UVCoords, Map->Normals);
	}
}

void AProcMeshSculpt::VertexChangeHeight(float DistanceFraction, int32 VertexIndex)
{
	float ScaledZStrength = 70;
	float Alpha = Curve->GetFloatValue(DistanceFraction) * 1;
	float ZValue = FMath::Lerp(70.0f, 0.f, Alpha) * 10;
	//UE_LOG(LogTemp, Warning, TEXT("Added %s"), *(FString::SanitizeFloat(ZValue)));
	Map->Vertices[VertexIndex] += (false) ? (FVector(0.f, 0.f, -ZValue)) : (FVector(0.f, 0.f, ZValue)); // invert
}
