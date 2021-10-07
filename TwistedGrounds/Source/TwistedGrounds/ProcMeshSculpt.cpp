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
	//UpdateTangents();

	if (CapDistance) {

		FindNearestPointOnCurve();
		if (!&HitResult && CapDistance) {
			Origin.Z = OriginalOrigin.Z;
			CappedHeight = Origin.Z; //maybe why it jitters
		}
	}
	
	//UE_LOG(LogTemp, Warning, TEXT("Map: %f"), HitMaps.Num())
	
	if (bNeedsUpdate) {
		for (AProcedurallyGeneratedMap* HitMap : HitMaps) {
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
	
	if (ShouldRearrange) {
		TArray<FVector> GlobalVerticesCopy;
		int32 Y = 0;
		int32 Width = 30;
		int32 i = 0;
		int32 Across = 0;
		int32 Crossed = 0;
		while (Y < 3 * Width) {

			if (Across == (Width * 3 - 1)) {

				Y++;
				i = (Width)*Y;
				Across = 0;
				Crossed = 0;

			}
			else if (Across == Width - 1 || Across == 2*Width - 1) {
				i += FMath::Square(Width) - Width + 1;
				Across++;
				
			}
			else {
				Across++;
			}
			
			GlobalVerticesCopy.Add(MapGenerator->GlobalVertices[i]);
			
			i++;
		}

		MapGenerator->GlobalVertices = GlobalVerticesCopy;
		ShouldRearrange = false;
	}

	int32 CalledCounter = 0;
	FVector RelativeHitLocation = GetActorLocation();
	int32 VertsPerSide = ((MapGenerator->ChunkWidth - 1) * 1 + 1);
	FVector MiddleLocation = FVector(FMath::RoundToInt(RelativeHitLocation.Y / MapGenerator->ChunkGridSize), FMath::RoundToInt(RelativeHitLocation.X / MapGenerator->ChunkGridSize), 0);
	int32 CenterIndex = MiddleLocation.X * VertsPerSide + MiddleLocation.Y;
	int32 RadiusInVerts = 500 / MapGenerator->ChunkGridSize;
	int32 RadiusExtended = RadiusInVerts + 1;

	for (int32 Y = -RadiusExtended; Y <= RadiusExtended; Y++)
	{
		for (int32 X = -RadiusExtended; X <= RadiusExtended; X++)
		{
			// Continue loop if Vert doesn't exist
			int32 CurrentIndex = CenterIndex + (Y * MapGenerator->ChunkWidth) + X;
			if (!MapGenerator->GlobalVertices.IsValidIndex(CurrentIndex)) { continue; }

			FVector CurrentVertCoords = FVector(
				FMath::RoundToInt(MapGenerator->GlobalVertices[CurrentIndex].Y / MapGenerator->ChunkGridSize),
				FMath::RoundToInt(MapGenerator->GlobalVertices[CurrentIndex].X / MapGenerator->ChunkGridSize),
				0);
			float DistanceFromCenter = FVector::Dist(MiddleLocation, CurrentVertCoords);

			if (DistanceFromCenter > RadiusInVerts) { continue; }

			float DistanceFraction = DistanceFromCenter / RadiusInVerts;
			CalledCounter++;
			VertexChangeHeight(DistanceFraction, CurrentIndex);
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
	UE_LOG(LogTemp, Warning, TEXT("Begin"))
	AProcedurallyGeneratedMap* HitMap = Cast<AProcedurallyGeneratedMap>(OtherActor);
	if (HitMap)
	HitMaps.Add(HitMap);
}

void AProcMeshSculpt::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("End"))
	AProcedurallyGeneratedMap* HitMap = Cast<AProcedurallyGeneratedMap>(OtherActor);
	if (HitMap)
	HitMaps.Remove(HitMap);
}

void AProcMeshSculpt::UpdateTangents()
{
	/*if (TangentsToBeUpdated > 0) {
		UKismetProceduralMeshLibrary::CalculateTangentsForMesh(, Map->Triangles, Map->UVCoords, Map->Normals, Map->Tangents);
		TangentsToBeUpdated--;
		Map->MeshComponent->UpdateMeshSection(0, MapGenerator->GlobalVertices, Map->Normals, Map->UVCoords, TArray<FColor>(), Map->Tangents);

		UE_LOG(LogTemp, Warning, TEXT("ReUpdated"))
	}*/

		for (AProcedurallyGeneratedMap* HitMap : HitMaps) {
			UKismetProceduralMeshLibrary::CalculateTangentsForMesh(HitMap->Vertices, HitMap->Triangles, HitMap->UVCoords, HitMap->Normals, HitMap->Tangents);
			HitMap->MeshComponent->UpdateMeshSection(0, HitMap->Vertices, HitMap->Normals, HitMap->UVCoords, TArray<FColor>(), HitMap->Tangents);
			
		}
		
	
}

void AProcMeshSculpt::Raycast()
{
	HitResult = TracePath(Muzzle->GetComponentLocation(), Camera->GetForwardVector() * 60000, Camera->GetOwner());

	Map = Cast<AProcedurallyGeneratedMap>(HitResult.GetActor()); //
	SetActorHiddenInGame(!Map);
	if (Map) {
		SetActorLocation(HitResult.ImpactPoint);
	}
}

void AProcMeshSculpt::EndWall()
{
	FVector Forward = Player->GetActorForwardVector();
	FRotator Rot = UKismetMathLibrary::MakeRotFromZ(Forward);
	Rot = FRotator(0, 0, 0);
	Player->SetActorRotation(Rot);
	FVector ForwardCamera = Camera->GetOwner()->GetActorLocation();
	FRotator RotCamera = UKismetMathLibrary::MakeRotFromY(ForwardCamera);
	RotCamera = FRotator(0, 0, 0);
	Camera->SetRelativeRotation(RotCamera);
}

void AProcMeshSculpt::VertexChangeHeight(float DistanceFraction, int32 VertexIndex)
{
	//UE_LOG(LogTemp, Warning, TEXT("Cap: %f"), CappedHeight)
	//UE_LOG(LogTemp, Warning, TEXT("Height: %f"), MapGenerator->GlobalVertices[VertexIndex].Z)

	UE_LOG(LogTemp, Warning, TEXT("Vert Coord: %s %s"), *MapGenerator->GlobalVertices[VertexIndex].ToString(), *Map->GetName())
	
	if (MapGenerator->GlobalVertices[VertexIndex].Z > CappedHeight && !CapHeight) {
		CappedHeight = MapGenerator->GlobalVertices[VertexIndex].Z;
		CappedHeightIndex = VertexIndex;
	}

	float Alpha = Curve->GetFloatValue(DistanceFraction) * 1;
	float ZValue = FMath::Lerp(ScaledZStrength, 0.f, Alpha) * 10;

	if (MapGenerator->GlobalVertices[VertexIndex].Z + ZValue > CappedHeight && CapHeight) {
		return;
	}
	int32 Index;
	Map->Vertices.Find(MapGenerator->GlobalVertices[VertexIndex], Index);
	if (Index == -1) {
		for (AProcedurallyGeneratedMap* HitMap : HitMaps) {
			HitMap->Vertices.Find(MapGenerator->GlobalVertices[VertexIndex], Index);
			if (Index != -1) {
 				Map->Vertices[Index] += (bInvert) ? (FVector(0.f, 0.f, -ZValue)) : (FVector(0.f, 0.f, ZValue));
				break;
			}
		}
	}
	else {
 		Map->Vertices[Index] += (bInvert) ? (FVector(0.f, 0.f, -ZValue)) : (FVector(0.f, 0.f, ZValue));
	}
	
	MapGenerator->GlobalVertices[VertexIndex] += (bInvert) ? (FVector(0.f, 0.f, -ZValue)) : (FVector(0.f, 0.f, ZValue)); // invert
	
	Origin.Z = CapDistance ? CappedHeight - 200 : Origin.Z;

}

FVector AProcMeshSculpt::FindNearestPointOnCurve()
{
	FVector2D HitLocation = FVector2D(GetActorLocation().X, GetActorLocation().Y);

	FVector ClosestPoint;
	FMath::PointDistToLine(GetActorLocation(), Direction, Origin, ClosestPoint);
	//UE_LOG(LogTemp, Warning, TEXT("Closest Point: %s"), *ClosestPoint.ToString())
	FVector Forward = ClosestPoint - Player->GetActorLocation();
	FRotator Rot = UKismetMathLibrary::MakeRotFromZ(Forward);
	Rot.Roll = 0.0f;
	//UE_LOG(LogTemp, Warning, TEXT("Rotation: %s"), *Rot.ToString())

	Player->FaceRotation(Rot);
	FVector ForwardCamera = ClosestPoint - Player->GetActorLocation();
	FRotator RotCamera = UKismetMathLibrary::MakeRotFromX(ForwardCamera);
	RotCamera.Roll = 0.0f;
	Camera->SetWorldRotation(RotCamera);

	return ClosestPoint;
}

void AProcMeshSculpt::CreateCurve()
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
	//DrawDebugLine(GetWorld(), GetActorLocation() - Player->GetActorRightVector() * 1000, Player->GetActorRightVector() * 1000 + GetActorLocation(), FColor(255, 0, 0), false, 5.0f);
	CapDistance = true;
}
