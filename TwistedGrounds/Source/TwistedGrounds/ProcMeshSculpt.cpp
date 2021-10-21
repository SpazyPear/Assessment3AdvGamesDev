// Fill out your copyright notice in the Description page of Project Settings.


#include "ProcMeshSculpt.h"
#include "Kismet/GameplayStatics.h"
#include <ProceduralMeshComponent/Public/KismetProceduralMeshLibrary.h>
#include "DrawDebugHelpers.h"
#include "Kismet/KismetMathLibrary.h"
#include "MapGenerator.h"
#include "EngineUtils.h"




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
	CapDistance = false;
	CappedHeightIndex = 0;
	ShouldRearrange = true;
	OverlappedVertices.Add(DIRECTION::LEFT, TArray<FVector>());
	OverlappedVertices.Add(DIRECTION::RIGHT, TArray<FVector>());
	OverlappedVertices.Add(DIRECTION::UP, TArray<FVector>());
	OverlappedVertices.Add(DIRECTION::DOWN, TArray<FVector>());
}

// Called when the game starts or when spawned
void AProcMeshSculpt::BeginPlay()
{
	Super::BeginPlay();
	MaxAmmo = SculptAmmo;
	Map = nullptr;
	FRotator Rot = GetActorRotation();
	Rot.Pitch = 90;
	SetActorRelativeRotation(Rot);
	for (TActorIterator<AMapGenerator> It(GetWorld()); It; ++It) {
		MapGenerator = *It;
	}
	Collider = FindComponentByClass<UBoxComponent>();
	Collider->SetGenerateOverlapEvents(true);
	Collider->OnComponentBeginOverlap.AddDynamic(this, &AProcMeshSculpt::OnOverlapBegin);
	Collider->OnComponentEndOverlap.AddDynamic(this, &AProcMeshSculpt::OnOverlapEnd);

	

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

	if (CapDistance) {

		FindNearestPointOnCurve();
		if (!&HitResult && CapDistance) {
			Origin.Z = OriginalOrigin.Z;
			CappedHeight = Origin.Z; //maybe why it jitters
		}
	}
	
	if (bNeedsUpdate) {
		for (AProcedurallyGeneratedMap* HitMap : AffectedTangents) {
			HitMap->MeshComponent->UpdateMeshSection(0, HitMap->Vertices, HitMap->Normals, HitMap->UVCoords, TArray<FColor>(), HitMap->Tangents);
		}
		bNeedsUpdate = false;
		UpdateTangents();
	} 
	
}

void AProcMeshSculpt::Sculpt()
{

	if (!Map || !&HitResult) {
		return;
	}
	FVector RelativeHitLocation = GetActorLocation() - Map->GetActorLocation();
	int32 VertsPerSide = ((Map->Width - 1) * 1 + 1);
	FVector MiddleLocation = FVector(FMath::RoundToInt(RelativeHitLocation.X / Map->GridSize), FMath::RoundToInt(RelativeHitLocation.Y / Map->GridSize), 0);
	int32 CenterIndex = MiddleLocation.Y * Map->Width + MiddleLocation.X;

	int32 RadiusInVerts = 500 / Map->GridSize;
	int32 RadiusExtended = RadiusInVerts + 1;
	AProcedurallyGeneratedMap* CenterMap = Map;
	bool bEdgeCase = false;
	for (int32 Y = -RadiusExtended; Y <= RadiusExtended; Y++) //Loop through a section of the mesh within a radius
	{
		for (int32 X = -RadiusExtended; X <= RadiusExtended; X++)
		{
			
			bEdgeCase = false;
			AProcedurallyGeneratedMap* CurrentMap = Map;
			DIRECTION LastDirection;
			MiddleLocation = FVector(FMath::RoundToInt(RelativeHitLocation.X / CenterMap->GridSize), FMath::RoundToInt(RelativeHitLocation.Y / CenterMap->GridSize), 0);
			int32 CurrentIndex = CenterIndex + (Y * Map->Width) + X; // Gets the index in the currently hit map's vertex array

			int32 XIndex = CurrentIndex % Map->Width;
			int32 YIndex = FMath::FloorToInt(CurrentIndex / Map->Width);
			if (!CurrentMap->Vertices.IsValidIndex(CurrentIndex)) {
					if (YIndex < 0) {

						YIndex = FMath::Abs(YIndex);
						XIndex = FMath::Abs(XIndex);
						int32 CurrentIndexCopy = ((Map->Width - YIndex) * Map->Width) + (Map->Width - 1 - XIndex);

						for (AProcedurallyGeneratedMap* HitMap : HitMaps) {

							if (HitMap->Vertices.IsValidIndex(CurrentIndexCopy) && HitMap != CenterMap) {
								if ((CurrentMap->GetActorLocation() - HitMap->GetActorLocation()).Y > 0) {

									CurrentMap = HitMap;
									CurrentIndex = CurrentIndexCopy;
									bEdgeCase = true;
									LastDirection = DIRECTION::LEFT;
									break;

								}
							}
						}
					}

				if (YIndex >= Map->Width) {

					YIndex = FMath::Abs(YIndex);
					XIndex = FMath::Abs(XIndex);
					int32 CurrentIndexCopy = CurrentIndex - FMath::Square(Map->Width);



					for (AProcedurallyGeneratedMap* HitMap : HitMaps) {

						if (HitMap->Vertices.IsValidIndex(CurrentIndexCopy) && HitMap != CenterMap) {

							if ((CurrentMap->GetActorLocation() - HitMap->GetActorLocation()).Y < 0) {

								CurrentMap = HitMap;
								CurrentIndex = CurrentIndexCopy;
								bEdgeCase = true;
								LastDirection = DIRECTION::RIGHT;
								break;

							}
						}
					}
				}

				if (!bEdgeCase) {
					continue;
				}

			}

			if (X + MiddleLocation.X < 0) {

				YIndex = FMath::Abs(YIndex);
				XIndex = FMath::Abs(XIndex);
				int32 CurrentIndexCopy = ((YIndex + 1) * Map->Width) + XIndex;



				for (AProcedurallyGeneratedMap* HitMap : HitMaps) {

					if (HitMap->Vertices.IsValidIndex(CurrentIndexCopy) && HitMap != CenterMap) {

						if ((CurrentMap->GetActorLocation() - HitMap->GetActorLocation()).X > 0) {

							CurrentMap = HitMap;
							CurrentIndex = CurrentIndexCopy;
							bEdgeCase = true;
							LastDirection = DIRECTION::DOWN;
							break;

						}
					}
				}
			}

			if (X + MiddleLocation.X >= Map->Width) {

				YIndex = FMath::Abs(YIndex);
				XIndex = FMath::Abs(XIndex);
				int32 CurrentIndexCopy = ((YIndex - 1) * Map->Width) + XIndex;



				for (AProcedurallyGeneratedMap* HitMap : HitMaps) {

					if (HitMap->Vertices.IsValidIndex(CurrentIndexCopy) && HitMap != CenterMap) {

						if ((CurrentMap->GetActorLocation() - HitMap->GetActorLocation()).X < 0) {

							CurrentMap = HitMap;
							CurrentIndex = CurrentIndexCopy;
							bEdgeCase = true;
							LastDirection = DIRECTION::UP;
							break;

						}
					}
				}
			}

			FVector CurrentVertCoords = FVector(
				FMath::RoundToInt(CurrentMap->Vertices[CurrentIndex].X / Map->GridSize),
				FMath::RoundToInt(CurrentMap->Vertices[CurrentIndex].Y / Map->GridSize),
				0);

				if (bEdgeCase) {

					switch (LastDirection) {

						case DIRECTION::LEFT:
							CurrentVertCoords.Y -= Map->Width - 1;
							break;
						case DIRECTION::RIGHT:
							CurrentVertCoords.Y += Map->Width - 1;
							break;
						case DIRECTION::UP:
							CurrentVertCoords.X += Map->Width - 1;
							break;
						case DIRECTION::DOWN:
							CurrentVertCoords.X -= Map->Width - 1;
							break;
					}
				}

			float DistanceFromCenter = FVector::Dist(MiddleLocation, CurrentVertCoords);

			if (DistanceFromCenter > RadiusExtended) { continue; }
			AffectedVertNormals.Add(CurrentIndex); //In future will update normals in real time too

			if (DistanceFromCenter > RadiusInVerts) { continue; } //Checks if the vertex is within the circle and not on the edges of the rectangle shape the loop creates

			if (CurrentMap && !AffectedTangents.Contains(CurrentMap)) { AffectedTangents.Add(CurrentMap); }

			float DistanceFraction = DistanceFromCenter / RadiusInVerts; //the closer to the middle of the circle the vertex is, the more it is affected.
			VertexChangeHeight(CurrentMap, DistanceFraction, CurrentIndex); //Change the height of the vertex
			

		}
	}

	TangentsToBeUpdated++;
	bNeedsUpdate = true;

}

void AProcMeshSculpt::CheckState(float DeltaTime)
{
	switch (SculptState) {

		case SCULPTSTATE::IDLE:
			break;
		case SCULPTSTATE::ONGOING:
			if (SculptAmmo > 0.0f) {
				SculptAmmo -= AmmoCost * DeltaTime;
				//UE_LOG(LogTemp, Warning, TEXT("Ammo: %f"), SculptAmmo)
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

void AProcMeshSculpt::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//UE_LOG(LogTemp, Warning, TEXT("Begin")) //Keeps track of maps currently in the circle, will be useful when making intersections between sections work.
	AProcedurallyGeneratedMap* HitMap = Cast<AProcedurallyGeneratedMap>(OtherActor);
	if (HitMap)
	HitMaps.Add(HitMap);
}

void AProcMeshSculpt::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	//UE_LOG(LogTemp, Warning, TEXT("End"))
	AProcedurallyGeneratedMap* HitMap = Cast<AProcedurallyGeneratedMap>(OtherActor);
	if (HitMap)
	HitMaps.Remove(HitMap);
}

void AProcMeshSculpt::UpdateTangents()
{

	for (AProcedurallyGeneratedMap* HitMap : AffectedTangents) {
			UKismetProceduralMeshLibrary::CalculateTangentsForMesh(HitMap->Vertices, HitMap->Triangles, HitMap->UVCoords, HitMap->Normals, HitMap->Tangents);
			HitMap->MeshComponent->UpdateMeshSection(0, HitMap->Vertices, HitMap->Normals, HitMap->UVCoords, TArray<FColor>(), HitMap->Tangents); //updates the tangents a little bit later so the player doesn't freeze everytime you sculpt.
	}
	AffectedTangents.Empty();
		
}

void AProcMeshSculpt::Raycast()
{
	HitResult = TracePath(Muzzle->GetComponentLocation(), Camera->GetForwardVector() * 60000, Camera->GetOwner());

	Map = Cast<AProcedurallyGeneratedMap>(HitResult.GetActor()); 
	SetActorHiddenInGame(!Map);
	if (Map) {
		SetActorLocation(HitResult.ImpactPoint);
	}
}

void AProcMeshSculpt::VertexChangeHeight(AProcedurallyGeneratedMap* CurrentMap, float DistanceFraction, int32 VertexIndex)
{

	if (CurrentMap->Vertices[VertexIndex].Z > CappedHeight && !CapHeight) {
		CappedHeight = CurrentMap->Vertices[VertexIndex].Z;
		CappedHeightIndex = VertexIndex; //Keeps track of the max height vertex that has been sculpted since the sculpt began, so it can be capped if you hold E.

	}

	float Alpha = Curve->GetFloatValue(DistanceFraction) * 1; //Applies the distance fraction to a curve, so that the outer edges of the circle are more curved up to the center.
	float ZValue = FMath::Lerp(ScaledZStrength, 0.f, Alpha) * 10;

	if (CurrentMap->Vertices[VertexIndex].Z + ZValue > CappedHeight && CapHeight) {
		return; //If holding Q, don't let the vertex exceed the capped height since you started holding.
	}

	CurrentMap->Vertices[VertexIndex] += (bInvert) ? (FVector(0.f, 0.f, -ZValue)) : (FVector(0.f, 0.f, ZValue)); // invert

	Origin.Z = CapDistance ? CappedHeight - 200 : Origin.Z; //For when holding F, the camera follows the point as it rises.

}

FVector AProcMeshSculpt::FindNearestPointOnCurve() //Snaps the camera to the nearest point on a straight perpendicular line in front of the player while holding F.
{
	FVector2D HitLocation = FVector2D(GetActorLocation().X, GetActorLocation().Y);

	FVector ClosestPoint;
	FMath::PointDistToLine(GetActorLocation(), Direction, Origin, ClosestPoint);
	FVector Forward = ClosestPoint - Player->GetActorLocation();
	FRotator Rot = UKismetMathLibrary::MakeRotFromZ(Forward);
	Rot.Roll = 0.0f;

	Player->FaceRotation(Rot);
	FVector ForwardCamera = ClosestPoint - Player->GetActorLocation();
	FRotator RotCamera = UKismetMathLibrary::MakeRotFromX(ForwardCamera);
	RotCamera.Roll = 0.0f;
	Camera->SetWorldRotation(RotCamera); 

	return ClosestPoint;
}

void AProcMeshSculpt::CreateCurve() //Creates the perpendicular line to be snapped to.
{
	PointsOnCurve.Empty();
	FVector2D HitLocation = FVector2D(GetActorLocation().X, GetActorLocation().Y);
	FVector2D PlayerLocation = FVector2D(Player->GetActorLocation().X, Player->GetActorLocation().Y);
	Center = FMath::Lerp(HitLocation, PlayerLocation, 0.5f);
	int32 VertsPerSide = ((Map->Width - 1) * 1 + 1);
	float Radius = FVector2D::Distance(Center, HitLocation);

	int32 Index = 0;
	FVector Previous;
	bool FlipCircle = false;

	Origin = GetActorLocation() - Player->GetActorRightVector() * 1000;
	OriginalOrigin = Origin;
	Direction = Player->GetActorRightVector();
	CapDistance = true;
}
