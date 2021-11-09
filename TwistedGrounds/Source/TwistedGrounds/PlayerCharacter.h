// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/InputComponent.h"

#include "Camera/CameraComponent.h"
#include "Components/SceneComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "ProcMeshSculpt.h"
#include "DustClouds.h"
#include "MapGenerator.h"
#include "TwistedGroundsHUD.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "HealthComponent.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class TWISTEDGROUNDS_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere) float LookSensitivity;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float Value);
	void Strafe(float Value);
	void LookUp(float Value);
	void Turn(float Value);

	UCameraComponent* Camera;

	//Controlled by MapGenerator
	UPROPERTY(EditDefaultsOnly) TSubclassOf<ADustClouds> BigDustEmitterToSpawn;
	UPROPERTY(EditDefaultsOnly) TSubclassOf<ADustClouds> SmallDustEmitterToSpawn;
	UPROPERTY(EditDefaultsOnly) TSubclassOf<class AProcMeshSculpt> MeshSculptor;
	//End

	bool bIsSprinting;

	void SculptStart();

	void SculptEnd();

	void Invert();

	void CapHeight();

	void CapDistance();

	void Fire();

	void OnDeath();

	void Sprint();

	void GetUp();

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
	UPROPERTY(Replicated) FVector CameraFacingDirection;

private:
	ADustClouds* BigEmitter;
	ADustClouds* SmallEmitter;
	AMapGenerator* MapGen;
	FVector PrevPos;
	AProcMeshSculpt* Sculptor;
	ATwistedGroundsHUD* HUD;
	UHealthComponent* HealthComponent;

	UPROPERTY(EditDefaultsOnly) float SculptDepletionSpeed; //Measured in seconds.
	UPROPERTY(EditDefaultsOnly) float SculptCooldownSpeed; //Measured in seconds.
	
	void Slide();
	void UpdateSculptAmmo(float DeltaTime);

	UPROPERTY(EditDefaultsOnly, meta = (ClampMin = "0", ClampMax = "90"))
		float WalkableAngle;

	UPROPERTY(Replicated) bool bIsSculpting;

	UFUNCTION(Server, Reliable) void ServerSlide();
	UFUNCTION(Server, Reliable) void ServerSprint();
	UFUNCTION(Server, Reliable) void ServerToggleSculpting(bool Boolean);
	UFUNCTION(Server, Reliable) void ServerSyncCam(FVector Pos);
};
