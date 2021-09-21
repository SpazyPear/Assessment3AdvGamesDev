// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Curves/CurveFloat.h"
#include "HAL/Runnable.h"
#include "UpdateMeshThread.h"
#include "ProcedurallyGeneratedMap.h"
#include "ProcMeshSculpt.generated.h"

UCLASS()
class TWISTEDGROUNDS_API AProcMeshSculpt : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProcMeshSculpt();

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(BlueprintReadWrite)
		FHitResult HitResult;

	void VertexChangeHeight(float DistanceFraction, int32 VertexIndex);

	UFUNCTION(BlueprintCallable)
		void Sculpt();

	UPROPERTY(EditAnywhere)
		UCurveFloat* Curve;

	TArray<int32> AffectedVertNormals;

	UpdateMeshThread* Thread;

	UPROPERTY(EditAnywhere)
		AProcedurallyGeneratedMap* Map;
};
