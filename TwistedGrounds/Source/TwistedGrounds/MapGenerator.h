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

	UPROPERTY(EditAnywhere)
		float PerlinOffset;

	UPROPERTY(EditAnywhere)
		TSubclassOf<AProcedurallyGeneratedMap> PGMap;

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

	virtual bool ShouldTickIfViewportsOnly() const override;

	UPROPERTY(EditAnywhere)
		bool bRegenerateMap;

private:
	void SetMapParams(AProcedurallyGeneratedMap* Map, int32 OffsetX, int32 OffsetY);
};
