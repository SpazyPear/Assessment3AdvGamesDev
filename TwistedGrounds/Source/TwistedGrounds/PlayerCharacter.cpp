// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "EngineUtils.h"
#include "DoStatic.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/CapsuleComponent.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Set default member variable values
	LookSensitivity = 1.0f;
	bIsSprinting = false;

	WalkableAngle = 45;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	//Initialise the camera variable
	Camera = FindComponentByClass<UCameraComponent>();
	HealthComponent = FindComponentByClass<UHealthComponent>();
	Sculptor = GetWorld()->SpawnActor<AProcMeshSculpt>(MeshSculptor, FVector::ZeroVector, FRotator::ZeroRotator);
	Sculptor->Player = this;
	Sculptor->Camera = Camera;
	Sculptor->Muzzle = Cast<USceneComponent>(GetDefaultSubobjectByName(TEXT("MuzzlePosition")));
	
	for (TActorIterator<AMapGenerator> Map(GetWorld()); Map; ++Map) {
		MapGen = *Map; //There should only be one map generator in the level.
	}

	FVector Pos = MapGen->RoundDownPosition(GetActorLocation());
	PrevPos = FVector(0, 0, 1); //Offset to force check surrounding.

	HUD = Cast<ATwistedGroundsHUD>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD());
	if (!HUD) {
		return;
	}
	GetCharacterMovement()->SetWalkableFloorAngle(WalkableAngle);
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (SmallEmitter) {
		SmallEmitter->SetActorLocation(Sculptor->GetActorLocation());
	}

	if (!HasAuthority()) {
		return;
	}
	
	FVector Pos = MapGen->RoundDownPosition(GetActorLocation());
	if (Pos != PrevPos) {
		PrevPos = Pos;
		MapGen->ServerCheckSurrounding(GetActorLocation());
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
	
	PlayerInputComponent->BindAction(TEXT("Sprint"), EInputEvent::IE_Pressed, this, &APlayerCharacter::Sprint);
	PlayerInputComponent->BindAction(TEXT("Sprint"), EInputEvent::IE_Released, this, &APlayerCharacter::Sprint);
	
	PlayerInputComponent->BindAction(TEXT("Fire"), EInputEvent::IE_Pressed, this, &APlayerCharacter::Fire);

	PlayerInputComponent->BindAction(TEXT("Slide"), EInputEvent::IE_Pressed, this, &APlayerCharacter::Slide);
	PlayerInputComponent->BindAction(TEXT("Slide"), EInputEvent::IE_Released, this, &APlayerCharacter::Slide);
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
	if (!Camera) {
		return;
	}

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

void APlayerCharacter::Sprint() {
	
	bIsSprinting = !bIsSprinting;
	GetCharacterMovement()->MaxWalkSpeed = bIsSprinting ? 900.0f : 500.0f;
	if (!HasAuthority()) { //Makes sprinting work on single and multiplayer.
		ServerSprint();
	}
}

void APlayerCharacter::ServerSprint_Implementation() {
	Sprint();
}

void APlayerCharacter::GetUp()
{
	USkeletalMeshComponent* SkeletalMesh = Cast<USkeletalMeshComponent>(GetMesh());
	SkeletalMesh->SetSimulatePhysics(false);
	SkeletalMesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly); //unchanged
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics); //??
}

void APlayerCharacter::Slide()
{
	UCharacterMovementComponent* Movement = GetCharacterMovement();
	Movement->SetWalkableFloorAngle(WalkableAngle - Movement->GetWalkableFloorAngle());
	ServerSlide();
}

void APlayerCharacter::ServerSlide_Implementation()
{
	UCharacterMovementComponent* Movement = GetCharacterMovement();
	Movement->SetWalkableFloorAngle(WalkableAngle - Movement->GetWalkableFloorAngle());
}

void APlayerCharacter::Invert()
{
	if (!Sculptor) {
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
	if (!Sculptor->CapDistance) {
		Sculptor->CreateCurve();
	}
	Sculptor->CapDistance = false;
}

void APlayerCharacter::UpdateAmmoBar(float Percent)
{
	if (HUD) {
		HUD->PlayerHUDWidget->UpdateAmmoBar(Percent);
	}
}

void APlayerCharacter::Fire()
{
	FHitResult HitResult = Sculptor->HitResult;
	AActor* HitActor = Cast<AActor>(HitResult.Actor);
	APlayerCharacter* HitCharacter = Cast<APlayerCharacter>(HitActor);
	if (HitCharacter) {
		HitCharacter->HealthComponent->OnTakeDamage(30.0f);
		if (HitCharacter->HealthComponent->HealthPercentageRemaining() == 0.0f) {
			USkeletalMeshComponent* SkeletalMesh = Cast<USkeletalMeshComponent>(HitCharacter->GetMesh());
			SkeletalMesh->SetSimulatePhysics(true);
			SkeletalMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
			SkeletalMesh->AddImpulse(Camera->GetForwardVector() * 10000, HitResult.BoneName, true);
			HitCharacter->GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
			
		}
	}
}
