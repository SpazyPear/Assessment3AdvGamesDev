// Fill out your copyright notice in the Description page of Project Settings.


#include "ProcMeshSculpt.h"
#include "Kismet/GameplayStatics.h"
#include <ProceduralMeshComponent/Public/KismetProceduralMeshLibrary.h>
#include "DrawDebugHelpers.h"
#include "Kismet/KismetMathLibrary.h"
#include "MapGenerator.h"
#include "EngineUtils.h"
#include "DoStatic.h"

// Sets default values
AProcMeshSculpt::AProcMeshSculpt()
{
	// Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ScaledZStrength = 70;
	bInvert = false;

	TangentsToBeUpdated = 0;

	//Rename your variables! - Ryan
	//Player->bCapHeightR = false;
	CapDistance = false;
	CappedHeightIndex = 0;
	ShouldRearrange = true;
}

// Called when the game starts or when spawned
void AProcMeshSculpt::BeginPlay()
{
	Super::BeginPlay();
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
		DoStatic::Print("No Muzzle or Camera");
		return;
	}

	Raycast();

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
			TArray<DIRECTION> AffectedDirections;
			MiddleLocation = FVector(FMath::RoundToInt(RelativeHitLocation.X / CenterMap->GridSize), FMath::RoundToInt(RelativeHitLocation.Y / CenterMap->GridSize), 0);
			int32 CurrentIndex = CenterIndex + (Y * Map->Width) + X; // Gets the index in the currently hit map's vertex array

			int32 XIndex = CurrentIndex % Map->Width;
			int32 YIndex = FMath::FloorToInt(CurrentIndex / Map->Width);


			if (!CurrentMap->Vertices.IsValidIndex(CurrentIndex)) {

					if (Y + MiddleLocation.Y < 0) {

						YIndex = FMath::Abs(YIndex);
						XIndex = FMath::Abs(XIndex);
						int32 CurrentIndexCopy = ((Map->Width - YIndex) * Map->Width) + (Map->Width - XIndex);

						for (AProcedurallyGeneratedMap* HitMap : HitMaps) {

							if (HitMap->Vertices.IsValidIndex(CurrentIndexCopy) && HitMap != CenterMap) {

								if (CurrentMap->GetActorLocation().Y > HitMap->GetActorLocation().Y && CurrentMap->GetActorLocation().X == HitMap->GetActorLocation().X) {

									CurrentMap = HitMap;
									CurrentIndex = CurrentIndexCopy;
									bEdgeCase = true;
									LastDirection = DIRECTION::LEFT;
									AffectedDirections.Add(LastDirection);
									break;

								}
							}
						}
					}

					if (Y + MiddleLocation.Y >= Map->Width) {

						YIndex = FMath::Abs(YIndex);
						XIndex = FMath::Abs(XIndex);
						int32 CurrentIndexCopy = ((YIndex - Map->Width - 1) * Map->Width) + (XIndex);

						for (AProcedurallyGeneratedMap* HitMap : HitMaps) {

							if (HitMap->Vertices.IsValidIndex(CurrentIndexCopy) && HitMap != CenterMap) {

								if (CurrentMap->GetActorLocation().Y < HitMap->GetActorLocation().Y && CurrentMap->GetActorLocation().X == HitMap->GetActorLocation().X) {

									CurrentMap = HitMap;
									CurrentIndex = CurrentIndexCopy;
									bEdgeCase = true;
									LastDirection = DIRECTION::RIGHT;
									AffectedDirections.Add(LastDirection);
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
				int32 CurrentIndexCopy = ((YIndex) * Map->Width) + XIndex;

				if (bEdgeCase && LastDirection == DIRECTION::RIGHT) {
					CurrentIndexCopy -= FMath::Square(Map->Width);
				}

				for (AProcedurallyGeneratedMap* HitMap : HitMaps) {

					if (HitMap->Vertices.IsValidIndex(CurrentIndexCopy) && HitMap != CenterMap) {

						if (bEdgeCase) {
							if (!CheckDiagonal(LastDirection, DIRECTION::DOWN, CenterMap, HitMap, CurrentIndexCopy, CurrentIndex)) {
								continue;
							}
						}

						else if (!(CurrentMap->GetActorLocation().X > HitMap->GetActorLocation().X && CurrentMap->GetActorLocation().Y == HitMap->GetActorLocation().Y)) {
							continue;
						}

							CurrentMap = HitMap;
							CurrentIndex = CurrentIndexCopy;
							bEdgeCase = true;
							LastDirection = DIRECTION::DOWN;
							AffectedDirections.Add(LastDirection);
							break;


					}
				}
			}

			else if (X + MiddleLocation.X >= Map->Width) {

				YIndex = FMath::Abs(YIndex);
				XIndex = FMath::Abs(XIndex);
				int32 CurrentIndexCopy = ((YIndex) * Map->Width) + XIndex;
				if (bEdgeCase && LastDirection == DIRECTION::RIGHT) {
					CurrentIndexCopy -= FMath::Square(Map->Width);
				}

				for (AProcedurallyGeneratedMap* HitMap : HitMaps) {



					if (HitMap->Vertices.IsValidIndex(CurrentIndexCopy) && HitMap != CenterMap) {


							if (bEdgeCase) {
								if (!CheckDiagonal(LastDirection, DIRECTION::UP, CenterMap, HitMap, CurrentIndexCopy, CurrentIndex)) {
									continue;
								}
							}

							else if (!(CurrentMap->GetActorLocation().X < HitMap->GetActorLocation().X && CurrentMap->GetActorLocation().Y == HitMap->GetActorLocation().Y)) {
								continue;
							}

							CurrentMap = HitMap;
							CurrentIndex = CurrentIndexCopy;
							bEdgeCase = true;
							LastDirection = DIRECTION::UP;
							AffectedDirections.Add(LastDirection);
							break;

					}
				}
			}

			FVector CurrentVertCoords = FVector(
				FMath::RoundToInt(CurrentMap->Vertices[CurrentIndex].X / Map->GridSize),
				FMath::RoundToInt(CurrentMap->Vertices[CurrentIndex].Y / Map->GridSize),
				0);

			if (bEdgeCase) {

					if (AffectedDirections.Contains(DIRECTION::LEFT))
						CurrentVertCoords.Y -= Map->Width - 1;

					if (AffectedDirections.Contains(DIRECTION::RIGHT))
						CurrentVertCoords.Y += Map->Width - 1;

					if (AffectedDirections.Contains(DIRECTION::UP))
						CurrentVertCoords.X += Map->Width - 1;

					if (AffectedDirections.Contains(DIRECTION::DOWN))
						CurrentVertCoords.X -= Map->Width - 1;

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

bool AProcMeshSculpt::CheckDiagonal(DIRECTION LastDirection, DIRECTION NewDirection, AProcedurallyGeneratedMap* CurrentMap, AProcedurallyGeneratedMap* HitMap, int32& CurrentIndexCopy, int32 CurrentIndex)
{
	TArray<DIRECTION> Directions;
	Directions.Add(LastDirection);
	Directions.Add(NewDirection);
	int32 XIndex = FMath::Abs(CurrentIndex % Map->Width);
	int32 YIndex = FMath::Abs(FMath::FloorToInt(CurrentIndex / Map->Width));

	if (Directions.Contains(DIRECTION::UP) && Directions.Contains(DIRECTION::LEFT)) {
		if (CurrentMap->GetActorLocation().X < HitMap->GetActorLocation().X && CurrentMap->GetActorLocation().Y > HitMap->GetActorLocation().Y) {

			CurrentIndexCopy = CurrentIndex;
			return true;

		}

	}
	else if (Directions.Contains(DIRECTION::DOWN) && Directions.Contains(DIRECTION::LEFT)) {
		 if (CurrentMap->GetActorLocation().X > HitMap->GetActorLocation().X && CurrentMap->GetActorLocation().Y > HitMap->GetActorLocation().Y) {

			 CurrentIndexCopy = CurrentIndex;
			 return true;
		 }

	}
	else if (Directions.Contains(DIRECTION::UP) && Directions.Contains(DIRECTION::RIGHT)) {
		 if (CurrentMap->GetActorLocation().X < HitMap->GetActorLocation().X && CurrentMap->GetActorLocation().Y < HitMap->GetActorLocation().Y) {

			 CurrentIndexCopy = CurrentIndex;
			 return true;
		 }

	}
	else if (Directions.Contains(DIRECTION::DOWN) && Directions.Contains(DIRECTION::RIGHT)) {
		 if (CurrentMap->GetActorLocation().X > HitMap->GetActorLocation().X && CurrentMap->GetActorLocation().Y < HitMap->GetActorLocation().Y) {

			 CurrentIndexCopy = CurrentIndex;
			 return true;
		 }
	}
	return false;
}

void AProcMeshSculpt::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AProcedurallyGeneratedMap* HitMap = Cast<AProcedurallyGeneratedMap>(OtherActor);
	if (HitMap)
	HitMaps.Add(HitMap);
}

void AProcMeshSculpt::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
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
	HitResult = TracePath(Muzzle->GetComponentLocation(), Player->CameraFacingDirection * 60000, Camera->GetOwner());

	Map = Cast<AProcedurallyGeneratedMap>(HitResult.GetActor());
	SetActorHiddenInGame(!Map);
	if (Map) {
		SetActorLocation(HitResult.ImpactPoint);
	}
}

void AProcMeshSculpt::VertexChangeHeight(AProcedurallyGeneratedMap* CurrentMap, float DistanceFraction, int32 VertexIndex)
{

	if (CurrentMap->Vertices[VertexIndex].Z > CappedHeight && !Player->bCapHeightR) {
		CappedHeight = CurrentMap->Vertices[VertexIndex].Z;
		CappedHeightIndex = VertexIndex; //Keeps track of the max height vertex that has been sculpted since the sculpt began, so it can be capped if you hold E.

	}

	float Alpha = Curve->GetFloatValue(DistanceFraction) * 1; //Applies the distance fraction to a curve, so that the outer edges of the circle are more curved up to the center.
	float ZValue = FMath::Lerp(ScaledZStrength, 0.f, Alpha) * 10;

	if (CurrentMap->Vertices[VertexIndex].Z + ZValue > CappedHeight && Player->bCapHeightR) {
		return; //If holding Q, don't let the vertex exceed the capped height since you started holding.
	}

	CurrentMap->Vertices[VertexIndex] += (Player->bInvertR) ? (FVector(0.f, 0.f, -ZValue)) : (FVector(0.f, 0.f, ZValue)); // invert

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
