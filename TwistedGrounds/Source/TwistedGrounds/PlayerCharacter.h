// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/InputComponent.h"

#include "Camera/CameraComponent.h"
#include "Components/SceneComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "DustClouds.h"
#include "MapGenerator.h"
#include "TwistedGroundsHUD.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "HealthComponent.h"
#include "PlayerCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSculptStart);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSculptEnd);

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

	//UPROPERTY(Replicated)
	UCameraComponent* Camera;

	//Controlled by MapGenerator
	UPROPERTY(EditDefaultsOnly) TSubclassOf<ADustClouds> BigDustEmitterToSpawn;
	UPROPERTY(EditDefaultsOnly) TSubclassOf<ADustClouds> SmallDustEmitterToSpawn;
	UPROPERTY(EditDefaultsOnly) TSubclassOf<class AProcMeshSculptActor> MeshSculptor;
	//End

	bool bIsSprinting;

	void CallSculptStart();

	void CallSculptEnd();

	void SculptStart();

	void SculptEnd();

	void Invert();

	void CapHeight();

	void UpdateAmmoBar(float Percent); //Updates the player's HUD

	void Fire();

	void OnDeath();

	void Sprint();

	void GetUp();

	UPROPERTY(Replicated)
	bool bSculpting;

	UFUNCTION(Server, Reliable)
		void ServerSculptStart();

	UFUNCTION(NetMulticast, Reliable)
		void MulticastSculptStart();

	UFUNCTION(Server, Reliable)
		void ServerSculptEnd();

	UFUNCTION(NetMulticast, Reliable)
		void MulticastSculptEnd();

	UFUNCTION(Server, Unreliable)
		void SetServerSculptorLocation(FVector Pos, APlayerCharacter* Character);

	UFUNCTION(NetMulticast, Unreliable)
		void SetMulticastSculptorLocation(FVector Pos, APlayerCharacter* Character);

	UFUNCTION(Server Reliable)
		void SetSculptingServer(bool boolean);

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	FVector SculptorLocation;

	FOnSculptStart SculptStartEvent;
	FOnSculptEnd SculptEndEvent;

private:
	ADustClouds* BigEmitter;
	ADustClouds* SmallEmitter;
	AMapGenerator* MapGen;
	FVector PrevPos;
	AProcMeshSculptActor* Sculptor;
	ATwistedGroundsHUD* HUD;
	UHealthComponent* HealthComponent;

	UPROPERTY(EditDefaultsOnly) float SculptDepletionSpeed; //Measured in seconds.
	UPROPERTY(EditDefaultsOnly) float SculptCooldownSpeed; //Measured in seconds.
	
	void Slide();
	void UpdateSculptAmmo(float DeltaTime);

	UPROPERTY(EditDefaultsOnly, meta = (ClampMin = "0", ClampMax = "90"))
		float WalkableAngle;

	UFUNCTION(Server, Reliable) void ServerSlide();
	UFUNCTION(Server, Reliable) void ServerSprint();
};
