// Fill out your copyright notice in the Description page of Project Settings.


#include "ProcMeshSculpt.h"
#include "Kismet/GameplayStatics.h"
#include <ProceduralMeshComponent/Public/KismetProceduralMeshLibrary.h>
#include "DrawDebugHelpers.h"
#include "EngineUtils.h"
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
	FRotator Rot = GetActorRotation();
	Rot.Pitch = 90;
	SetActorRelativeRotation(Rot);
	for (TActorIterator<AMapGenerator> ActorIterator(GetWorld()); ActorIterator; ++ActorIterator) {
		GlobalVertices = &ActorIterator->GlobalVertices;
		MapGenerator = *ActorIterator;
	}
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
		if (!&HitResult && CapDistance) {
			Origin.Z = OriginalOrigin.Z;
			CappedHeight = Origin.Z;
		}
	}
}

void AProcMeshSculpt::Sculpt()
{
	if (!Map || !&HitResult) {
		return;
	}
	CurrentMap = Cast<AProcedurallyGeneratedMap>(HitResult.Actor);
	int32 CalledCounter = 0;
	FVector RelativeHitLocation = Player->GetActorLocation() - GetActorLocation(); //somethin
	int32 VertsPerSide = ((MapGenerator->ChunkWidth - 1) * 1 + 1);
	FVector MiddleLocation = FVector(FMath::RoundToInt(RelativeHitLocation.Y / MapGenerator->ChunkGridSize), FMath::RoundToInt(RelativeHitLocation.X / MapGenerator->ChunkGridSize), 0);
	int32 CenterIndex = MiddleLocation.X * VertsPerSide + MiddleLocation.Y;
	TArray<FVector> AffectedVertices; 
	int32 RadiusInVerts = 500 / MapGenerator->ChunkGridSize;
	int32 RadiusExtended = RadiusInVerts + 1;
	TArray<FVector> GlobalVerticesDereferenced = *GlobalVertices;
	float Up = -INFINITY;
	float Down = INFINITY;
	float Left = INFINITY;
	float Right = -INFINITY;
	FVector UpVector;
	FVector DownVector;
	FVector LeftVector;
	FVector RightVector;

	for (int32 Y = -RadiusExtended; Y <= RadiusExtended; Y++)
	{
		for (int32 X = -RadiusExtended; X <= RadiusExtended; X++)
		{
			// Continue loop if Vert doesn't exist
			int32 CurrentIndex = CenterIndex + (Y * MapGenerator->ChunkWidth) + X;
			if (!GlobalVertices->IsValidIndex(CurrentIndex)) { continue; }

			FVector CurrentVertCoords = FVector(
				FMath::RoundToInt(MapGenerator->GlobalVertices[CurrentIndex].Y / MapGenerator->ChunkGridSize),
				FMath::RoundToInt(MapGenerator->GlobalVertices[CurrentIndex].X / MapGenerator->ChunkGridSize),
				0);
			float DistanceFromCenter = FVector::Dist(MiddleLocation, CurrentVertCoords);

	
			if (DistanceFromCenter > RadiusExtended) { continue; }
			AffectedVertNormals.Add(CurrentIndex);

			if (DistanceFromCenter > RadiusInVerts) { continue; }

			float DistanceFraction = DistanceFromCenter / RadiusInVerts;
			CalledCounter++;
			VertexChangeHeight(DistanceFraction, CurrentIndex);

			if (CurrentVertCoords.X < Left) {
				LeftVector = CurrentVertCoords;
			}
			if (CurrentVertCoords.X > Right) {
				RightVector = CurrentVertCoords;
			}
			if (CurrentVertCoords.Y < Down) {
				DownVector = CurrentVertCoords;
			}
			if (CurrentVertCoords.Y > Up) {
				UpVector = CurrentVertCoords;
			}

			AffectedVertices.Add(MapGenerator->GlobalVertices[CurrentIndex]);
		}
	}
	TangentsToBeUpdated++;
	
	int32 X;
	int32 Y;
	
	for (Y = 0; Y < 3; Y++) {
		if (MapGenerator->Maps[Y].Find(Cast<AProcedurallyGeneratedMap>(HitResult.Actor), X)) {
			break;
		}
	}

	if (CurrentMap->Vertices.Contains(LeftVector) && MapGenerator->Maps[Y].IsValidIndex(X - 1)) {
		AffectedSections.Add(MapGenerator->Maps[Y][X - 1]);
	}
	if (CurrentMap->Vertices.Contains(RightVector) && MapGenerator->Maps[Y].IsValidIndex(X + 1)) {
		AffectedSections.Add(MapGenerator->Maps[Y + 1][X]);
	}
	if (CurrentMap->Vertices.Contains(UpVector) && MapGenerator->Maps[Y + 1].IsValidIndex(X)) {
		AffectedSections.Add(MapGenerator->Maps[Y + 1][X]);
	}
	if (CurrentMap->Vertices.Contains(DownVector) && MapGenerator->Maps[Y - 1].IsValidIndex(X)) {
		AffectedSections.Add(MapGenerator->Maps[Y - 1][X]);
	}
	for (AProcedurallyGeneratedMap* AffectedMap : AffectedSections) {
		AffectedMap->FindComponentByClass<UProceduralMeshComponent>()->UpdateMeshSection(0, CurrentMap->Vertices, CurrentMap->Normals, CurrentMap->UVCoords, TArray<FColor>(), CurrentMap->Tangents);
	}
	
}

bool AProcMeshSculpt::Contains(FVector Vertex)
{
	for (int32 Y = 0; Y < 3; Y++) {
		for (int32 X = 0; X < 3; X++) {
			
		}
	}
	return false;
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
		TArray<FProcMeshTangent> Tangents;
		UKismetProceduralMeshLibrary::CalculateTangentsForMesh(CurrentMap->Vertices, CurrentMap->Triangles, CurrentMap->UVCoords, CurrentMap->Normals, Tangents);
		TangentsToBeUpdated--;
		for (AProcedurallyGeneratedMap* AffectedMap : AffectedSections) {
			AffectedMap->FindComponentByClass<UProceduralMeshComponent>()->UpdateMeshSection(0, CurrentMap->Vertices, CurrentMap->Normals, CurrentMap->UVCoords, TArray<FColor>(), Tangents);
		}
		AffectedSections.Empty();
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
	UE_LOG(LogTemp, Warning, TEXT("Cap: %f"), CappedHeight)
	//UE_LOG(LogTemp, Warning, TEXT("Height: %f"), GlobalVertices[VertexIndex].Z)
	if (MapGenerator->GlobalVertices[VertexIndex].Z > CappedHeight && !CapHeight) {
		CappedHeight = MapGenerator->GlobalVertices[VertexIndex].Z;
		CappedHeightIndex = VertexIndex;
	}

	float Alpha = Curve->GetFloatValue(DistanceFraction) * 1;
	float ZValue = FMath::Lerp(ScaledZStrength, 0.f, Alpha) * 10;

	if (MapGenerator->GlobalVertices[VertexIndex].Z + ZValue > CappedHeight && CapHeight) {
		return;
	}

	MapGenerator->GlobalVertices[VertexIndex] += (bInvert) ? (FVector(0.f, 0.f, -ZValue)) : (FVector(0.f, 0.f, ZValue));
	
	FVector RelativeHitLocation = Player->GetActorLocation() - GetActorLocation();
	int32 VertsPerSide = ((CurrentMap->Width - 1) * 1 + 1);
	FVector MiddleLocation = FVector(FMath::RoundToInt(RelativeHitLocation.Y / CurrentMap->GridSize), FMath::RoundToInt(RelativeHitLocation.X / CurrentMap->GridSize), 0);
	int32 CenterIndex = MiddleLocation.X * VertsPerSide + MiddleLocation.Y;

	Origin.Z = CapDistance ? CappedHeight - 200 : Origin.Z;


	// POSSIBLY FORGOT TO COPY FROM OTHER BRANCH

}

FVector AProcMeshSculpt::FindNearestPointOnCurve()
{
	FVector2D HitLocation = FVector2D(GetActorLocation().X, GetActorLocation().Y);
	/*int32 VertsPerSide = ((MapGenerator->ChunkWidth - 1) * 1 + 1);
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
	int32 VertsPerSide = ((MapGenerator->ChunkWidth - 1) * 1 + 1);
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
			if (GlobalVertices.IsValidIndex(VertexIndex)) {
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
	OriginalOrigin = Origin;
	Direction = Player->GetActorRightVector();
	//DrawDebugLine(GetWorld(), GetActorLocation() - Player->GetActorRightVector() * 1000, Player->GetActorRightVector() * 1000 + GetActorLocation(), FColor(255, 0, 0), false, 5.0f);
	CapDistance = true;
}
