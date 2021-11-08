// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DecalActor.h"
#include "Components/ActorComponent.h"

#include "Curves/CurveFloat.h"
#include "HAL/Runnable.h"
#include "UpdateMeshThread.h"

#include "PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/SceneComponent.h"
#include "Components/BoxComponent.h"
#include "ProcedurallyGeneratedMap.h"
#include "ProcMeshSculptComponent.generated.h"

enum class DIRECTIONCOMPONENT : uint8;

UENUM()
enum class SCULPTSTATECOMPONENT : uint8 {
	IDLE,
	ONGOING,
	STOPPED,
};

UENUM()
enum class DIRECTIONCOMPONENT : uint8 {
	LEFT,
	RIGHT,
	UP,
	DOWN,
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TWISTEDGROUNDS_API UProcMeshSculptComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	UProcMeshSculptComponent();

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintReadWrite)
		FHitResult HitResult;

	void VertexChangeHeight(AProcedurallyGeneratedMap* CurrentMap, float DistanceFraction, int32 VertexIndex);

	void Sculpt();

	UPROPERTY(EditAnywhere)
		float ScaledZStrength;

	UFUNCTION(BlueprintImplementableEvent)
		FHitResult TracePath(FVector StartPos, FVector LaunchVelocity, AActor* IgnoreActors);


	UPROPERTY(Replicated)
		SCULPTSTATECOMPONENT SculptState;

	class APlayerCharacter* Player;

	bool bInvert;

	float CappedHeight;

	bool CapHeight;

	void CheckState(float DeltaTime);

	void RegenAmmo(float DeltaTime);

	UFUNCTION()
		virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION(Server, Reliable)
		void ServerSculpt();

	UFUNCTION(NetMulticast, Reliable)
		void MulticastSculpt();

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;


	bool CheckDiagonal(DIRECTIONCOMPONENT NewDirection, DIRECTIONCOMPONENT LastDirection, AProcedurallyGeneratedMap* CurrentMap, AProcedurallyGeneratedMap* HitMap, int32& CurrentIndexCopy, int32 CurrentIndex);


	bool ResetCappedHeight;

	float CappedDistance;

	int32 CappedHeightIndex;

	bool CapDistance;

	bool ShouldRearrange;

	FVector Origin;

	FVector Direction;

	float SculptAmmo;
	float MaxAmmo;
	float AmmoCost;
	float AmmoRegen;

	UPROPERTY(EditAnywhere)
		UCurveFloat* Curve;

	TArray<int32> AffectedVertNormals;

	TArray<AProcedurallyGeneratedMap*> AffectedTangents;

	AProcedurallyGeneratedMap* Map; //This can now dynamically change to any chunk

	int32 TangentsToBeUpdated;

	void UpdateTangents();

	void Raycast();

	UCameraComponent* Camera;
	USceneComponent* Muzzle;
	class AMapGenerator* MapGenerator;

	UBoxComponent* Collider;

	TArray<AProcedurallyGeneratedMap*> HitMaps;

	bool bNeedsUpdate;

	TMap<DIRECTIONCOMPONENT, TArray<FVector>> OverlappedVertices;

private:
	void UpdateAmmoBar();
};
