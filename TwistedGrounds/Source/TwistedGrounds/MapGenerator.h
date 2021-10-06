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

	UPROPERTY(EditAnywhere)
		float PerlinOffset;

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

	//These variables control the parameters of the procedurally generated maps
	UPROPERTY(EditAnywhere)
		int32 ChunkWidth;

	UPROPERTY(EditAnywhere)
		int32 ChunkHeight;

	UPROPERTY(EditAnywhere)
		float ChunkGridSize;

	UPROPERTY(EditAnywhere)
		float PerlinScale;

	UPROPERTY(EditAnywhere)
		float PerlinRoughness;
	//End

	virtual bool ShouldTickIfViewportsOnly() const override;

	UPROPERTY(EditAnywhere)
		bool bRegenerateMap;

	TArray<FVector> GlobalVertices;

private:
	TArray<APlayerCharacter*> Player;

	void SetMapParams(AProcedurallyGeneratedMap* Map, int32 OffsetX, int32 OffsetY);
	void CheckSurrounding(FVector Position); //Given a position, check the surrounding chunks
	void ClearMaps(); //Generates the initial map according to the offset.

	TArray<FVector> MapPoints; //The location of all the maps.
	int32 RoundDownToNearest(int32 Value, int32 Nearest); //Rounds up to the nearest
};
