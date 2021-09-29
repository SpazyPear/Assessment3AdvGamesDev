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

#include "GameFramework/CharacterMovementComponent.h"
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
	UPROPERTY(EditAnywhere)
		float LookSensitivity;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float Value);
	void Strafe(float Value);
	void LookUp(float Value);
	void Turn(float Value);

	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ADustClouds> BigDustEmitterToSpawn;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ADustClouds> SmallDustEmitterToSpawn;

	UPROPERTY(EditAnywhere)
		AProcMeshSculpt* MeshSculpt;

	void SculptStart();

	void SculptEnd();

	void Invert();

	void CapHeight();

	void CapDistance();

private:
	ADustClouds* BigEmitter;
	ADustClouds* SmallEmitter;
};
