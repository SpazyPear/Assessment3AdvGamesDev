// Fill out your copyright notice in the Description page of Project Settings.


#include "ProcMeshSculpt.h"
#include "Kismet/GameplayStatics.h"
#include <ProceduralMeshComponent/Public/KismetProceduralMeshLibrary.h>
#include "DrawDebugHelpers.h"
#include "Kismet/KismetMathLibrary.h"



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
	
}

// Called when the game starts or when spawned
void AProcMeshSculpt::BeginPlay()
{
	Super::BeginPlay();
	MaxAmmo = SculptAmmo;
	Map = nullptr;
	Player = GetWorld()->GetFirstPlayerController()->GetPawn();
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

	if (CapDistance) {
		FindNearestPointOnCurve();
	}
}

void AProcMeshSculpt::Sculpt()
{
	if (!Map || !&HitResult) {
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

	Map = Cast<AProcedurallyGeneratedMap>(HitResult.GetActor());
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
	if (Map->Vertices[VertexIndex].Z > CappedHeight && !CapHeight) {
		CappedHeight = Map->Vertices[VertexIndex].Z;
		CappedHeightIndex = VertexIndex;
	}
	
	float Alpha = Curve->GetFloatValue(DistanceFraction) * 1;
	float ZValue = FMath::Lerp(ScaledZStrength, 0.f, Alpha) * 10;

	if (Map->Vertices[VertexIndex].Z + ZValue > CappedHeight && CapHeight) {
		return;
	}

	
	Map->Vertices[VertexIndex] += (bInvert) ? (FVector(0.f, 0.f, -ZValue)) : (FVector(0.f, 0.f, ZValue)); // invert
}

FVector AProcMeshSculpt::FindNearestPointOnCurve()
{
	FVector2D HitLocation = FVector2D(GetActorLocation().X, GetActorLocation().Y);
	/*int32 VertsPerSide = ((Map->Width - 1) * 1 + 1);
	float Radius = FVector2D::Distance(Center, HitLocation);
	int32 L = 0;
	int32 R = PointsOnCurve.Num() - 1;
	float MinDistance = 0.0f;
	FVector2D ClosestPoint;
	while (L <= R) {
		float m = (L + R) / 2;
		float Distance = FVector2D::Distance(PointsOnCurve[m], HitLocation);
		if (Distance < MinDistance) {
			MinDistance = Distance;
			ClosestPoint = PointsOnCurve[m];
			L = m + 1;
		}
		else if (Distance > MinDistance) {
			R = m - 1;
		}
		else {
			MinDistance = Distance;
			ClosestPoint = PointsOnCurve[m];
			break;
		}
	}
	if (&ClosestPoint == nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("Closest Point Not Found"))
		return FVector2D();
	}
	UE_LOG(LogTemp, Warning, TEXT("Closest Point: %s"), *ClosestPoint.ToString()) */
	FVector ClosestPoint;
	FMath::PointDistToLine(GetActorLocation(), Direction, Origin, ClosestPoint);
	UE_LOG(LogTemp, Warning, TEXT("Closest Point: %s"), *ClosestPoint.ToString())
	FVector Forward = ClosestPoint - Player->GetActorLocation();
	FRotator Rot = UKismetMathLibrary::MakeRotFromZ(Forward);
	Rot.Roll = 0.0f;
	UE_LOG(LogTemp, Warning, TEXT("Rotation: %s"), *Rot.ToString())
	
	Player->FaceRotation(Rot);
	FVector ForwardCamera = ClosestPoint - Player->GetActorLocation();
	FRotator RotCamera = UKismetMathLibrary::MakeRotFromX(ForwardCamera);
	RotCamera.Roll = 0.0f;
	UE_LOG(LogTemp, Warning, TEXT("Rotation: %s"), *RotCamera.ToString())
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

	/*for (auto LoopCount = 0; LoopCount <= 1; LoopCount++) {
		for (auto points = -10; points < 10; points++) {
			 int32 x = Center.X + points * 100;
			float y = FMath::Sqrt(FMath::Square(Radius) - FMath::Square(x - Center.X)) + Center.Y;
			UE_LOG(LogTemp, Warning, TEXT("Start: %i"), points);
			if (!y) {
				continue;
			}
			FVector2D NewPoint = FVector2D(x, y);
			y = FlipCircle ? y - 4 * FMath::PointDistToLine(FVector(NewPoint.X, NewPoint.Y, 0), FVector(1, 0, 0), FVector(Center.X, Center.Y, 0)) : y;
			
			FVector VertexLocation = FVector(FMath::RoundToInt(NewPoint.Y / Map->GridSize), FMath::RoundToInt(NewPoint.X / Map->GridSize), 0);
			FVector Start;
			int32 VertexIndex = VertexLocation.X * VertsPerSide + VertexLocation.Y;
			if (Map->Vertices.IsValidIndex(VertexIndex)) {
				Start = FVector(NewPoint.X, NewPoint.Y, 400);
			}
			else {
				continue;
			}
			if (PointsOnCurve.Num() > 0) {

				if (&Start) {
					UE_LOG(LogTemp, Warning, TEXT("Start: %s"), *Start.ToString());
					DrawDebugLine(GetWorld(), Start, Previous, FColor(255, 0, 0), false, 5.0f);
				}
			}
			PointsOnCurve.Add(NewPoint);
			Previous = Start;
			Index++; 
		} 
		FlipCircle = true;
	} */

	Origin = GetActorLocation() - Player->GetActorRightVector() * 1000;
	Direction = Player->GetActorRightVector();
	//DrawDebugLine(GetWorld(), GetActorLocation() - Player->GetActorRightVector() * 1000, Player->GetActorRightVector() * 1000 + GetActorLocation(), FColor(255, 0, 0), false, 5.0f);
	CapDistance = true;
}
