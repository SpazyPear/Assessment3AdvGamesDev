// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"


// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	//Set default member variable values
	LookSensitivity = 1.0f;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	//Initialise the camera variable
	Camera = FindComponentByClass<UCameraComponent>();
	MeshSculpt->Camera = Camera;
	MeshSculpt->Muzzle = Cast<USceneComponent>(GetDefaultSubobjectByName(TEXT("MuzzlePosition")));
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &APlayerCharacter::Strafe);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APlayerCharacter::LookUp);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &APlayerCharacter::Turn);

	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Sculpt"), EInputEvent::IE_Pressed, this, &APlayerCharacter::Sculpt);
}

void APlayerCharacter::MoveForward(float Value) 
{
	FRotator ForwardRotation = GetControlRotation();
	ForwardRotation.Roll = 0.0f;
	ForwardRotation.Pitch = 0.0f;
	AddMovementInput(ForwardRotation.Vector(), Value);
}

void APlayerCharacter::Strafe(float Value) 
{
	AddMovementInput(GetActorRightVector(), Value);
}

void APlayerCharacter::LookUp(float Value) 
{
	float NewPitch = Camera->GetRelativeRotation().Pitch + Value * LookSensitivity;
	NewPitch = NewPitch > 90 ? 90 : NewPitch;
	NewPitch = NewPitch < -90 ? -90 : NewPitch;

	FRotator CamRot = FRotator().ZeroRotator;
	CamRot.Pitch = NewPitch;
	Camera->SetRelativeRotation(CamRot);
}

void APlayerCharacter::Turn(float Value) 
{
	AddControllerYawInput(Value * LookSensitivity);
}

void APlayerCharacter::Sculpt()
{
	if (MeshSculpt) {
		MeshSculpt->Sculpt();
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("There is no reference for the MeshSculpt variable."))
	}
}
