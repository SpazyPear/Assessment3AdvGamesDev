// Fill out your copyright notice in the Description page of Project Settings.


#include "ProcMeshSculpt.h"
#include "Math/UnrealMathUtility.h"
#include <ProceduralMeshComponent/Public/KismetProceduralMeshLibrary.h>


// Sets default values
AProcMeshSculpt::AProcMeshSculpt()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComponent = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("Mesh Component"));
	PerlinOffset = FMath::RandRange(-10000.0f, 10000.0f);
	bRegenerateMap = false;
}

// Called when the game starts or when spawned
void AProcMeshSculpt::BeginPlay()
{
	Super::BeginPlay();
	ClearMap();
	GenerateMap();

	Thread = new UpdateMeshThread();
}

// Called every frame
void AProcMeshSculpt::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bRegenerateMap) {
		bRegenerateMap = false;
		ClearMap();
		GenerateMap();
	}

	if (Thread->bRunningThread == false && Thread->TangentsQueue.Num() > 0) {
		this->Tangents = Thread->TangentsQueue.Pop();
		MeshComponent->UpdateMeshSection(0, Vertices, Normals, UVCoords, TArray<FColor>(), Tangents);
		
		UE_LOG(LogTemp, Warning, TEXT("ReUpdated"))
	}
	

}

void AProcMeshSculpt::GenerateMap()
{
	FString PerlinOffsetString = FString::SanitizeFloat(PerlinOffset);
	for (auto h = 0; h < Height; h++) {
		for (auto w = 0; w < Width; w++) {
			Vertices.Add(FVector(w * GridSize, h * GridSize, FMath::PerlinNoise2D(FVector2D(w * PerlinRoughness + PerlinOffset, h * PerlinRoughness + PerlinOffset)) * PerlinScale));
		}
	}

	for (auto Vertex : Vertices) {
		UVCoords.Add(FVector2D(Vertex.X / GridSize, Vertex.Y / GridSize));
	}

	for (auto h = 0; h < Height - 1; h++) {
		for (auto w = 0; w < Width - 1; w++) {
			Triangles.Add((h * Width) + w);
			Triangles.Add(((h + 1) * Width) + w);
			Triangles.Add((h * Width) + w + 1);
			Triangles.Add((h * Width) + w + 1);
			Triangles.Add(((h + 1) * Width) + w);
			Triangles.Add(((h + 1) * Width) + w + 1);
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("Rand %s"), *PerlinOffsetString);
	UKismetProceduralMeshLibrary::CalculateTangentsForMesh(Vertices, Triangles, UVCoords, Normals, Tangents);
	MeshComponent->CreateMeshSection(0, Vertices, Triangles, Normals, UVCoords, TArray<FColor>(), Tangents, true);
	UE_LOG(LogTemp, Warning, TEXT("Vertices Count: %i | UVCoords Count: %i Triangles Count: %i"), Vertices.Num(), UVCoords.Num(), Triangles.Num());


}

void AProcMeshSculpt::ClearMap()
{
	PerlinOffset = FMath::RandRange(-10000.0f, 10000.0f);
	Triangles.Empty();
	Vertices.Empty();
	UVCoords.Empty();
	MeshComponent->ClearAllMeshSections();
}

bool AProcMeshSculpt::ShouldTickIfViewportsOnly() const
{

	return false;
}

void AProcMeshSculpt::Sculpt()
{
	int32 CalledCounter = 0;
	FHitResult* HitResultPtr = &HitResult;
	if (HitResultPtr != nullptr) {
		FVector MiddleVertexLocation = HitResult.Location;
		UProceduralMeshComponent* mesh = MeshComponent;
		FVector RelativeHitLocation = MiddleVertexLocation - GetActorLocation();
		int32 VertsPerSide = ((Width - 1) * 1 + 1);
		FVector MiddleLocation = FVector(FMath::RoundToInt(RelativeHitLocation.Y / GridSize), FMath::RoundToInt(RelativeHitLocation.X / GridSize), 0);
		int32 CenterIndex = MiddleLocation.X * VertsPerSide + MiddleLocation.Y;


		int32 RadiusInVerts = 500 / GridSize;
		int32 RadiusExtended = RadiusInVerts + 1;

		for (int32 Y = -RadiusExtended; Y <= RadiusExtended; Y++)
		{
			for (int32 X = -RadiusExtended; X <= RadiusExtended; X++)
			{
				// Continue loop if Vert doesn't exist
				int32 CurrentIndex = CenterIndex + (Y * Width) + X;
				if (!Vertices.IsValidIndex(CurrentIndex)) { continue; }

				FVector CurrentVertCoords = FVector(
					FMath::RoundToInt(Vertices[CurrentIndex].Y / GridSize),
					FMath::RoundToInt(Vertices[CurrentIndex].X / GridSize),
					0);
				float DistanceFromCenter = FVector::Dist(MiddleLocation, CurrentVertCoords);
				UE_LOG(LogTemp, Warning, TEXT("Distance: %f, Hit Location: %s, CurrentVertCoords: %s"), DistanceFromCenter, *(MiddleLocation.ToString()), *(CurrentVertCoords.ToString()));

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


		mesh->UpdateMeshSection(0, Vertices, Normals, UVCoords, TArray<FColor>(), Tangents);
		Thread->CreateThread(MeshComponent, Vertices, Triangles, UVCoords, Normals);
	
	}

}

void AProcMeshSculpt::VertexChangeHeight(float DistanceFraction, int32 VertexIndex)
{
	float ScaledZStrength = 70;
	float Alpha = Curve->GetFloatValue(DistanceFraction) * 1;
	float ZValue = FMath::Lerp(70.0f, 0.f, Alpha) * 10;
	//UE_LOG(LogTemp, Warning, TEXT("Added %s"), *(FString::SanitizeFloat(ZValue)));
	Vertices[VertexIndex] += (false) ? (FVector(0.f, 0.f, -ZValue)) : (FVector(0.f, 0.f, ZValue)); // invert
}

