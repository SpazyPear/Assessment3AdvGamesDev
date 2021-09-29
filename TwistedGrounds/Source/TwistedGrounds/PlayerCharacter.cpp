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
	if (SmallEmitter) {
		SmallEmitter->SetActorLocation(MeshSculpt->GetActorLocation());
	}
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
	PlayerInputComponent->BindAction(TEXT("Sculpt"), EInputEvent::IE_Pressed, this, &APlayerCharacter::SculptStart);
	PlayerInputComponent->BindAction(TEXT("Sculpt"), EInputEvent::IE_Released, this, &APlayerCharacter::SculptEnd);
	PlayerInputComponent->BindAction(TEXT("Invert"), EInputEvent::IE_Pressed, this, &APlayerCharacter::Invert);
	PlayerInputComponent->BindAction(TEXT("Invert"), EInputEvent::IE_Released, this, &APlayerCharacter::Invert);
	PlayerInputComponent->BindAction(TEXT("CapHeight"), EInputEvent::IE_Pressed, this, &APlayerCharacter::CapHeight);
	PlayerInputComponent->BindAction(TEXT("CapHeight"), EInputEvent::IE_Released, this, &APlayerCharacter::CapHeight);
	PlayerInputComponent->BindAction(TEXT("CapDistance"), EInputEvent::IE_Pressed, this, &APlayerCharacter::CapDistance);
	PlayerInputComponent->BindAction(TEXT("CapDistance"), EInputEvent::IE_Released, this, &APlayerCharacter::CapDistance);
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

void APlayerCharacter::SculptStart()
{
	if (!MeshSculpt) {
		UE_LOG(LogTemp, Warning, TEXT("There is no reference for the MeshSculpt variable."))
		return;
	}
	if (!MeshSculpt->HitSet) {
		return;
	}
	SmallEmitter = GetWorld()->SpawnActor<ADustClouds>(SmallDustEmitterToSpawn, MeshSculpt->GetActorLocation(), FRotator::ZeroRotator);
	MeshSculpt->SculptState = SCULPTSTATE::ONGOING;
}

void APlayerCharacter::SculptEnd()
{
	if (!MeshSculpt) {
		UE_LOG(LogTemp, Warning, TEXT("There is no reference for the MeshSculpt variable."))
		return;
	}

	if (SmallEmitter) {
		SmallEmitter->Destroy();
		SmallEmitter = nullptr;
		
	}
	if (MeshSculpt->SculptState == SCULPTSTATE::ONGOING) {
		BigEmitter = GetWorld()->SpawnActor<ADustClouds>(BigDustEmitterToSpawn, MeshSculpt->GetActorLocation(), FRotator::ZeroRotator);
		MeshSculpt->SculptState = SCULPTSTATE::STOPPED;
	}
	
}

void APlayerCharacter::Invert()
{
	if (!MeshSculpt) {
		UE_LOG(LogTemp, Warning, TEXT("There is no reference for the MeshSculpt variable."))
		return;
	}
	MeshSculpt->bInvert = !MeshSculpt->bInvert;
}

void APlayerCharacter::CapHeight()
{
	MeshSculpt->CapHeight = !MeshSculpt->CapHeight;
	if (!MeshSculpt->CapHeight) {
		MeshSculpt->CappedHeight = MIN_flt;
	}
}

void APlayerCharacter::CapDistance()
{
	if (MeshSculpt->CapDistance == false) {
		MeshSculpt->CreateCurve();
	}

	else {
		MeshSculpt->CapDistance = false;
		//MeshSculpt->EndWall();
	}
}
