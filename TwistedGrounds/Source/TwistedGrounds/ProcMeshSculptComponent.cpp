// Fill out your copyright notice in the Description page of Project Settings.


#include "ProcMeshSculptComponent.h"
#include "Kismet/GameplayStatics.h"
#include <ProceduralMeshComponent/Public/KismetProceduralMeshLibrary.h>
#include "DrawDebugHelpers.h"
#include "Kismet/KismetMathLibrary.h"
#include "MapGenerator.h"
#include "EngineUtils.h"
#include "DoStatic.h"
#include "TwistedGroundsHUD.h"
#include "Net/UnrealNetwork.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/GameEngine.h"




// Sets default values
UProcMeshSculptComponent::UProcMeshSculptComponent()
{
	// Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryComponentTick.bCanEverTick = true;

	SculptState = SCULPTSTATECOMPONENT::IDLE;
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

}

// Called when the game starts or when spawned
void UProcMeshSculptComponent::BeginPlay()
{
	Super::BeginPlay();
	MaxAmmo = SculptAmmo;
	Map = nullptr;
	/*FRotator Rot = GetActorRotation();
	Rot.Pitch = 90;
	SetActorRelativeRotation(Rot);*/
	for (TActorIterator<AMapGenerator> It(GetWorld()); It; ++It) {
		MapGenerator = *It;
	}
	Collider = GetOwner()->FindComponentByClass<UBoxComponent>();
	Collider->SetGenerateOverlapEvents(true);
	Collider->OnComponentBeginOverlap.AddDynamic(this, &UProcMeshSculptComponent::OnOverlapBegin);
	Collider->OnComponentEndOverlap.AddDynamic(this, &UProcMeshSculptComponent::OnOverlapEnd);

}

// Called every frame
void UProcMeshSculptComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)

{
	//Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!Muzzle || !Camera) {
		DoStatic::Print("No Muzzle or Camera");
		return;
	}

	Raycast();
	CheckState(DeltaTime);
	RegenAmmo(DeltaTime);

	if (CapDistance) {

		if (!&HitResult && CapDistance) {

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

void UProcMeshSculptComponent::Sculpt()
{

	if (!Map || !&HitResult) {
		return;
	}
	if (GetOwner()->GetLocalRole() == ENetRole::ROLE_Authority) {
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, FString::Printf(TEXT("SculptState: %i"), SculptState));
	}
	FVector RelativeHitLocation = HitResult.ImpactPoint - Map->GetActorLocation();
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
			enum DIRECTIONCOMPONENT LastDirection;
			TArray<enum DIRECTIONCOMPONENT> AffectedDirections;
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
								LastDirection = DIRECTIONCOMPONENT::LEFT;
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
								LastDirection = DIRECTIONCOMPONENT::RIGHT;
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
				int32 CurrentIndexCopy = ((YIndex)*Map->Width) + XIndex;

				if (bEdgeCase && LastDirection == DIRECTIONCOMPONENT::RIGHT) {
					CurrentIndexCopy -= FMath::Square(Map->Width);
				}

				for (AProcedurallyGeneratedMap* HitMap : HitMaps) {

					if (HitMap->Vertices.IsValidIndex(CurrentIndexCopy) && HitMap != CenterMap) {

						if (bEdgeCase) {
							if (!CheckDiagonal(LastDirection, DIRECTIONCOMPONENT::DOWN, CenterMap, HitMap, CurrentIndexCopy, CurrentIndex)) {
								continue;
							}
						}

						else if (!(CurrentMap->GetActorLocation().X > HitMap->GetActorLocation().X && CurrentMap->GetActorLocation().Y == HitMap->GetActorLocation().Y)) {
							continue;
						}

						CurrentMap = HitMap;
						CurrentIndex = CurrentIndexCopy;
						bEdgeCase = true;
						LastDirection = DIRECTIONCOMPONENT::DOWN;
						AffectedDirections.Add(LastDirection);
						break;


					}
				}
			}

			else if (X + MiddleLocation.X >= Map->Width) {

				YIndex = FMath::Abs(YIndex);
				XIndex = FMath::Abs(XIndex);
				int32 CurrentIndexCopy = ((YIndex)*Map->Width) + XIndex;
				if (bEdgeCase && LastDirection == DIRECTIONCOMPONENT::RIGHT) {
					CurrentIndexCopy -= FMath::Square(Map->Width);
				}

				for (AProcedurallyGeneratedMap* HitMap : HitMaps) {



					if (HitMap->Vertices.IsValidIndex(CurrentIndexCopy) && HitMap != CenterMap) {


						if (bEdgeCase) {
							if (!CheckDiagonal(LastDirection, DIRECTIONCOMPONENT::UP, CenterMap, HitMap, CurrentIndexCopy, CurrentIndex)) {
								continue;
							}
						}

						else if (!(CurrentMap->GetActorLocation().X < HitMap->GetActorLocation().X && CurrentMap->GetActorLocation().Y == HitMap->GetActorLocation().Y)) {
							continue;
						}

						CurrentMap = HitMap;
						CurrentIndex = CurrentIndexCopy;
						bEdgeCase = true;
						LastDirection = DIRECTIONCOMPONENT::UP;
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

				if (AffectedDirections.Contains(DIRECTIONCOMPONENT::LEFT))
					CurrentVertCoords.Y -= Map->Width - 1;

				if (AffectedDirections.Contains(DIRECTIONCOMPONENT::RIGHT))
					CurrentVertCoords.Y += Map->Width - 1;

				if (AffectedDirections.Contains(DIRECTIONCOMPONENT::UP))
					CurrentVertCoords.X += Map->Width - 1;

				if (AffectedDirections.Contains(DIRECTIONCOMPONENT::DOWN))
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

void UProcMeshSculptComponent::ServerSculpt_Implementation()
{
	Sculpt();
	MulticastSculpt();
}

void UProcMeshSculptComponent::MulticastSculpt_Implementation()
{
	if (GetOwner()->GetLocalRole() == ENetRole::ROLE_Authority) {
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, FString::Printf(TEXT("authority")));

	}
	Sculpt();
}

void UProcMeshSculptComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UProcMeshSculptComponent, SculptState);
}

bool UProcMeshSculptComponent::CheckDiagonal(DIRECTIONCOMPONENT LastDirection, DIRECTIONCOMPONENT NewDirection, AProcedurallyGeneratedMap* CurrentMap, AProcedurallyGeneratedMap* HitMap, int32& CurrentIndexCopy, int32 CurrentIndex)
{
	TArray<DIRECTIONCOMPONENT> Directions;
	Directions.Add(LastDirection);
	Directions.Add(NewDirection);
	int32 XIndex = FMath::Abs(CurrentIndex % Map->Width);
	int32 YIndex = FMath::Abs(FMath::FloorToInt(CurrentIndex / Map->Width));

	if (Directions.Contains(DIRECTIONCOMPONENT::UP) && Directions.Contains(DIRECTIONCOMPONENT::LEFT)) {
		if (CurrentMap->GetActorLocation().X < HitMap->GetActorLocation().X && CurrentMap->GetActorLocation().Y > HitMap->GetActorLocation().Y) {

			CurrentIndexCopy = CurrentIndex;
			return true;

		}

	}
	else if (Directions.Contains(DIRECTIONCOMPONENT::DOWN) && Directions.Contains(DIRECTIONCOMPONENT::LEFT)) {
		if (CurrentMap->GetActorLocation().X > HitMap->GetActorLocation().X && CurrentMap->GetActorLocation().Y > HitMap->GetActorLocation().Y) {

			CurrentIndexCopy = CurrentIndex;
			return true;
		}

	}
	else if (Directions.Contains(DIRECTIONCOMPONENT::UP) && Directions.Contains(DIRECTIONCOMPONENT::RIGHT)) {
		if (CurrentMap->GetActorLocation().X < HitMap->GetActorLocation().X && CurrentMap->GetActorLocation().Y < HitMap->GetActorLocation().Y) {

			CurrentIndexCopy = CurrentIndex;
			return true;
		}

	}
	else if (Directions.Contains(DIRECTIONCOMPONENT::DOWN) && Directions.Contains(DIRECTIONCOMPONENT::RIGHT)) {
		if (CurrentMap->GetActorLocation().X > HitMap->GetActorLocation().X && CurrentMap->GetActorLocation().Y < HitMap->GetActorLocation().Y) {

			CurrentIndexCopy = CurrentIndex;
			return true;
		}
	}
	return false;
}

void UProcMeshSculptComponent::CheckState(float DeltaTime)
{
	switch (SculptState) {

	case SCULPTSTATECOMPONENT::IDLE:
		break;
	case SCULPTSTATECOMPONENT::ONGOING:
		if (SculptAmmo > 0.0f) {
			SculptAmmo -= AmmoCost * DeltaTime;
			ServerSculpt();
		}
		break;
	case SCULPTSTATECOMPONENT::STOPPED:
		SculptState = SCULPTSTATECOMPONENT::IDLE; //stub
	}
}

void UProcMeshSculptComponent::RegenAmmo(float DeltaTime)
{
	if (SculptState == SCULPTSTATECOMPONENT::IDLE && SculptAmmo < MaxAmmo) {
		SculptAmmo += AmmoRegen * DeltaTime;
		SculptAmmo = FMath::Clamp(SculptAmmo, 0.0f, MaxAmmo);
	}
	ATwistedGroundsHUD* HUD = Cast<ATwistedGroundsHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());
	if (HUD) {
		HUD->UpdateAmmoBar(SculptAmmo / MaxAmmo);
	}
}

void UProcMeshSculptComponent::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AProcedurallyGeneratedMap* HitMap = Cast<AProcedurallyGeneratedMap>(OtherActor);
	if (HitMap)
		HitMaps.Add(HitMap);
}

void UProcMeshSculptComponent::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	AProcedurallyGeneratedMap* HitMap = Cast<AProcedurallyGeneratedMap>(OtherActor);
	if (HitMap)
		HitMaps.Remove(HitMap);
}

void UProcMeshSculptComponent::UpdateTangents()
{

	for (AProcedurallyGeneratedMap* HitMap : AffectedTangents) {
		UKismetProceduralMeshLibrary::CalculateTangentsForMesh(HitMap->Vertices, HitMap->Triangles, HitMap->UVCoords, HitMap->Normals, HitMap->Tangents);
		HitMap->MeshComponent->UpdateMeshSection(0, HitMap->Vertices, HitMap->Normals, HitMap->UVCoords, TArray<FColor>(), HitMap->Tangents); //updates the tangents a little bit later so the player doesn't freeze everytime you sculpt.
	}
	AffectedTangents.Empty();

}

void UProcMeshSculptComponent::Raycast()
{
	HitResult = TracePath(Muzzle->GetComponentLocation(), Camera->GetForwardVector() * 60000, Camera->GetOwner());

	Map = Cast<AProcedurallyGeneratedMap>(HitResult.GetActor());
	//SetActorHiddenInGame(!Map);
	if (Map) {
		//SetWorldLocation(HitResult.ImpactPoint);
	}
}

void UProcMeshSculptComponent::UpdateAmmoBar()
{
	if (Player) {
		Player->UpdateAmmoBar(SculptAmmo / MaxAmmo);
	}
}

void UProcMeshSculptComponent::VertexChangeHeight(AProcedurallyGeneratedMap* CurrentMap, float DistanceFraction, int32 VertexIndex)
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


