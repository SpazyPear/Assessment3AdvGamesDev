// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "EngineUtils.h"
#include "DoStatic.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Set default member variable values
	LookSensitivity = 1.0f;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	//Initialise the camera variable
	Camera = FindComponentByClass<UCameraComponent>();
	Sculptor = GetWorld()->SpawnActor<AProcMeshSculpt>(MeshSculptor, FVector::ZeroVector, FRotator::ZeroRotator);
	Sculptor->Player = this;
	Sculptor->Camera = Camera;
	Sculptor->Muzzle = Cast<USceneComponent>(GetDefaultSubobjectByName(TEXT("MuzzlePosition")));
	
	for (TActorIterator<AMapGenerator> Map(GetWorld()); Map; ++Map) {
		MapGen = *Map; //There should only be one map generator in the level.
	}

	FVector Pos = GetActorLocation();
	int32 X = DoStatic::RoundDownToNearest(Pos.X, MapGen->W);
	int32 Y = DoStatic::RoundDownToNearest(Pos.Y, MapGen->H);
	PrevPos = FVector(X - 1, Y - 1, 0); //Offset to force check surrounding.
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (SmallEmitter) {
		SmallEmitter->SetActorLocation(Sculptor->GetActorLocation());
	}

	FVector Pos = GetActorLocation();
	int32 X = DoStatic::RoundDownToNearest(Pos.X, MapGen->W);
	int32 Y = DoStatic::RoundDownToNearest(Pos.Y, MapGen->H);
	if (X != PrevPos.X || Y != PrevPos.Y) {
		PrevPos = FVector(X, Y, 0);
		MapGen->CheckSurrounding(Pos);
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
	if (!Sculptor || !Sculptor->Map) {
		return;
	}

	SmallEmitter = GetWorld()->SpawnActor<ADustClouds>(SmallDustEmitterToSpawn, Sculptor->GetActorLocation(), FRotator::ZeroRotator);
	Sculptor->SculptState = SCULPTSTATE::ONGOING;
}

void APlayerCharacter::SculptEnd()
{
	if (!Sculptor) {
		UE_LOG(LogTemp, Warning, TEXT("There is no reference for the MeshSculpt variable."))
		return;
	}

	if (SmallEmitter) {
		SmallEmitter->Destroy();
		SmallEmitter = nullptr;
		
	}
	if (Sculptor->SculptState == SCULPTSTATE::ONGOING) {
		BigEmitter = GetWorld()->SpawnActor<ADustClouds>(BigDustEmitterToSpawn, Sculptor->GetActorLocation(), FRotator::ZeroRotator);
		Sculptor->SculptState = SCULPTSTATE::STOPPED;
	}

	if (!Sculptor->CapHeight) {
		Sculptor->CappedHeight = -INFINITY;
	}
	
}

void APlayerCharacter::Invert()
{
	if (!Sculptor) {
		UE_LOG(LogTemp, Warning, TEXT("There is no reference for the MeshSculpt variable."))
		return;
	}
	Sculptor->bInvert = !Sculptor->bInvert;
}

void APlayerCharacter::CapHeight()
{
	Sculptor->CapHeight = !Sculptor->CapHeight;
}

void APlayerCharacter::CapDistance()
{
	if (Sculptor->CapDistance == false) {
		Sculptor->CreateCurve();
	}

	else {
		Sculptor->CapDistance = false;
	}
}
