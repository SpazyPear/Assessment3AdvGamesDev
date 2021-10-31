// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "ProcedurallyGeneratedMap.h"

#include "MapGenerator.generated.h"

UCLASS()
class TWISTEDGROUNDS_API AMapGenerator : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMapGenerator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//These variables are set from the editor
	////These variables spawn the needed actors and materials
	UPROPERTY(EditAnywhere)
		TSubclassOf<AProcedurallyGeneratedMap> PGMap;

	UPROPERTY(EditAnywhere)
		int32 ChunkRadius; //The chunk radius that surrounds the player
	////End

	////These variables control the parameters of the procedurally generated maps
	UPROPERTY(EditAnywhere)
		int32 ChunkWidth; //The width of each chunk

	UPROPERTY(EditAnywhere)
		int32 ChunkHeight; //The height of each chunk

	UPROPERTY(EditAnywhere)
		float ChunkGridSize; //The size of each chunk

	UPROPERTY(EditAnywhere)
		float PerlinScale;
	
	UPROPERTY(EditAnywhere)
		float PerlinOffset;

	UPROPERTY(EditAnywhere)
		float PerlinRoughness;
	////End

	////Allows the map to be generated in the editor
	virtual bool ShouldTickIfViewportsOnly() const override;

	UPROPERTY(EditAnywhere)
		bool bRegenerateMap;
	////End
	//End

	FVector RoundDownPosition(FVector Position); //Round down given position.
	void CheckSurrounding(FVector Position); //Given a position, check the surrounding chunks

private:
	int ActualW;
	int ActualH;
	int W; //Width of the chunk
	int H; //Height of the chunk

	//Sets the generated map's variables to the MapGenerator's
	void SetMapParams(AProcedurallyGeneratedMap* Map, int32 OffsetX, int32 OffsetY);
	void ClearMaps(); //Generates the initial map according to the offset.
	void UpdateProperties(); //Simply updates W, H, ActualW and ActualH.

	UPROPERTY()
		TArray<FVector> MapPoints; //The location of all the maps.
};
