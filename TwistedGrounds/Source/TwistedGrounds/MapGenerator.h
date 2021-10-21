// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "ProcedurallyGeneratedMap.h"
#include "PlayerCharacter.h"

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
		TSubclassOf<APlayerCharacter> PlayerToSpawn;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ADustClouds> BigDustEmitter;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ADustClouds> SmallDustEmitter;

	UPROPERTY(EditAnywhere)
		TSubclassOf<AProcMeshSculpt> Sculptor;

	UPROPERTY(EditAnywhere)
		UMaterialInterface* PGMaterial;

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

private:
	TArray<APlayerCharacter*> Player; //An array to keep track of all players.

	//Sets the generated map's variables to the MapGenerator's
	void SetMapParams(AProcedurallyGeneratedMap* Map, int32 OffsetX, int32 OffsetY);
	void CheckSurrounding(FVector Position); //Given a position, check the surrounding chunks
	void ClearMaps(); //Generates the initial map according to the offset.

	UPROPERTY()
		TArray<FVector> MapPoints; //The location of all the maps.

	int32 RoundDownToNearest(int32 Value, int32 Nearest); //Always rounds down to the nearest
};
