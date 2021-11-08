// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DecalActor.h"

#include "Curves/CurveFloat.h"
#include "HAL/Runnable.h"
#include "UpdateMeshThread.h"

#include "PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/SceneComponent.h"
#include "Components/BoxComponent.h"
#include "ProcedurallyGeneratedMap.h"
#include "ProcMeshSculptActor.generated.h"

UENUM()
enum class SCULPTSTATEACTOR : uint8 {
	IDLE,
	ONGOING,
	STOPPED,
};

UENUM()
enum class DIRECTIONACTOR :uint8 {
	LEFT,
	RIGHT,
	UP,
	DOWN,
};

UCLASS()
class TWISTEDGROUNDS_API AProcMeshSculptActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AProcMeshSculptActor();

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	FHitResult HitResult;

	void VertexChangeHeight(AProcedurallyGeneratedMap* CurrentMap, float DistanceFraction, int32 VertexIndex);

	void Sculpt();

	UPROPERTY(EditAnywhere)
		float ScaledZStrength;

	UFUNCTION(BlueprintImplementableEvent)
		FHitResult TracePath(FVector StartPos, FVector LaunchVelocity, AActor* IgnoreActors);


	UPROPERTY(Replicated)
		SCULPTSTATEACTOR SculptState;

	class APlayerCharacter* Player;

	bool bInvert;

	float CappedHeight;

	bool CapHeight;

	void CheckState(float DeltaTime);

	void SetOwnerPlayer();

	void RegenAmmo(float DeltaTime);

	UFUNCTION()
		virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION(Server, Reliable)
		void ServerSculpt();

	UFUNCTION(NetMulticast, Reliable)
		void MulticastSculpt();

	UFUNCTION(Server, Reliable)
		void SetServerOwner();

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	bool CheckDiagonal(DIRECTIONACTOR LastDirection, DIRECTIONACTOR NewDirection, AProcedurallyGeneratedMap* CurrentMap, AProcedurallyGeneratedMap* HitMap, int32& CurrentIndexCopy, int32 CurrentIndex);

	void CreateCurve();

	bool ResetCappedHeight;

	int32 CappedHeightIndex;

	FVector Direction;

	float SculptAmmo;
	float MaxAmmo;
	float AmmoCost;
	float AmmoRegen;

	UPROPERTY(EditAnywhere)
		UCurveFloat* Curve;

	TArray<int32> AffectedVertNormals;

	UPROPERTY(Replicated)
	TArray<AProcedurallyGeneratedMap*> AffectedTangents;

	UPROPERTY(Replicated)
	AProcedurallyGeneratedMap* Map; //This can now dynamically change to any chunk

	int32 TangentsToBeUpdated;

	void UpdateTangents();

	void Raycast();

	UFUNCTION(Server, Reliable)
	void ServerSetPosition(FVector Pos);

	UCameraComponent* Camera;
	USceneComponent* Muzzle;
	class AMapGenerator* MapGenerator;

	UBoxComponent* Collider;

	UPROPERTY(Replicated)
	TArray<AProcedurallyGeneratedMap*> HitMaps;

	UPROPERTY(Replicated)
	bool bNeedsUpdate;

private:
	void UpdateAmmoBar();
};
