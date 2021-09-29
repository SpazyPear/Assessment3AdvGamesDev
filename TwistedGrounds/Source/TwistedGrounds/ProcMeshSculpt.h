// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DecalActor.h"

#include "Curves/CurveFloat.h"
#include "HAL/Runnable.h"
#include "UpdateMeshThread.h"

#include "Camera/CameraComponent.h"
#include "Components/SceneComponent.h"

#include "ProcedurallyGeneratedMap.h"
#include "ProcMeshSculpt.generated.h"

UENUM()
enum class SCULPTSTATE : uint8 {
	IDLE,
	ONGOING,
	STOPPED,
};

UCLASS()
class TWISTEDGROUNDS_API AProcMeshSculpt : public ADecalActor
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
	void Sculpt();

	UPROPERTY(EditAnywhere)
		float ScaledZStrength;

	UFUNCTION(BlueprintImplementableEvent)
		FHitResult TracePath(FVector StartPos, FVector LaunchVelocity, AActor* IgnoreActors);

	SCULPTSTATE SculptState;

	APawn* Player;

	bool bInvert;

	float CappedHeight;

	bool CapHeight;

	void CheckState(float DeltaTime);

	void RegenAmmo(float DeltaTime);

	FVector FindNearestPointOnCurve();

	void CreateCurve();

	TArray<FVector2D> PointsOnCurve;

	FVector2D Center;

	bool ResetCappedHeight;

	float CappedDistance;

	int32 CappedHeightIndex;

	bool CapDistance;

	FVector Origin;

	FVector Direction;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float SculptAmmo;

	UPROPERTY(BlueprintReadWrite)
		float MaxAmmo;

	UPROPERTY(EditAnywhere)
		float AmmoCost;

	UPROPERTY(EditAnywhere)
		float AmmoRegen;

	UPROPERTY(EditAnywhere)
		UCurveFloat* Curve;

	TArray<int32> AffectedVertNormals;

	UPROPERTY(EditAnywhere)
		AProcedurallyGeneratedMap* Map;

	bool HitSet;

	int32 TangentsToBeUpdated;

	void UpdateTangents();

	void Raycast();

	void EndWall();

	UCameraComponent* Camera;
	USceneComponent* Muzzle;
};
