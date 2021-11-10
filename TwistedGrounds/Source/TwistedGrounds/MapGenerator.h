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
	UPROPERTY(EditAnywhere) TSubclassOf<AProcedurallyGeneratedMap> PGMap;
	UPROPERTY(EditAnywhere) int32 ChunkRadius; //The chunk radius that surrounds the player
	////End

	////These variables control the parameters of the procedurally generated maps
	UPROPERTY(EditAnywhere) int32 ChunkWidth; //The width of each chunk
	UPROPERTY(EditAnywhere) int32 ChunkHeight; //The height of each chunk
	UPROPERTY(EditAnywhere) float ChunkGridSize; //The size of each chunk
	UPROPERTY(EditAnywhere) float PerlinScale;
	UPROPERTY(EditAnywhere) float PerlinOffset;
	UPROPERTY(EditAnywhere) float PerlinRoughness;
	////End

	UPROPERTY(EditAnywhere) bool bRegenerateMap; //Allows the map to be generated in the editor
	//End

	virtual bool ShouldTickIfViewportsOnly() const override;

	FVector RoundDownPosition(FVector Position); //Gets a position and rounds it down.

	//Since Procedural mesh component cannot be replicated, both client and server need to use this.
	//This is highly inefficient but it is the only viable option. No replication needed as all clients need
	//to do this to stay synced up.
	UFUNCTION(Server, Reliable)
		void ServerCheckSurrounding(FVector Position); //Given a position, check the surrounding chunks

private:
	int W; //Width of the chunk
	int H; //Height of the chunk
	int ActualW;
	int ActualH;

	void ClearMaps(); //Generates the initial map according to the offset.
	void UpdateValues();
	void CheckSurrounding(FVector Position, bool bOnServer);

	UPROPERTY() TArray<FVector> MapPoints; //The location of all the maps.
};