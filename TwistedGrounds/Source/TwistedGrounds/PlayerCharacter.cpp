// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "EngineUtils.h"
#include "DoStatic.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "ProcMeshSculptActor.h"
#include <Runtime/Engine/Public/Net/UnrealNetwork.h>

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Set default member variable values
	LookSensitivity = 1.0f;
	bIsSprinting = false;

	SculptDepletionSpeed = 1.5; // example: 3 seconds to go from full to empty.
	SculptCooldownSpeed = 2; //example: 2 seconds cooldown from empty to full.

	WalkableAngle = 45;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	Camera = FindComponentByClass<UCameraComponent>();
	HealthComponent = FindComponentByClass<UHealthComponent>();
	FActorSpawnParameters SpawnParams = FActorSpawnParameters();
	SpawnParams.bNoFail = true;
	//Sculptor = Cast<UProcMeshSculptActor>(GetDefaultSubobjectByName(TEXT("Sculptor")));
	Sculptor = GetWorld()->SpawnActor<AProcMeshSculptActor>(MeshSculptor, FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
	Sculptor->Player = this;
	Sculptor->Camera = Camera;
	Sculptor->Muzzle = Cast<USceneComponent>(GetDefaultSubobjectByName(TEXT("MuzzlePosition")));

	if (GetLocalRole() == ROLE_Authority)
	Sculptor->SetOwner(this);
	
	for (TActorIterator<AMapGenerator> Map(GetWorld()); Map; ++Map) {
		MapGen = *Map; //There should only be one map generator in the level.
	}

	FVector Pos = MapGen->RoundDownPosition(GetActorLocation());
	PrevPos = FVector(0, 0, 1); //Offset to force check surrounding.

	SculptDepletionSpeed = 1.0f / SculptDepletionSpeed;
	SculptCooldownSpeed = 1.0f / SculptCooldownSpeed;

	HUD = Cast<ATwistedGroundsHUD>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD());
	GetCharacterMovement()->SetWalkableFloorAngle(WalkableAngle);
	if (!HUD) {
		return;
	}
	UpdateAmmoBar(1);

	if (GetLocalRole() == ENetRole::ROLE_SimulatedProxy) {
		USkeletalMeshComponent* BodyMesh = GetMesh();
		USkeletalMeshComponent* BodyGunMesh = Cast<USkeletalMeshComponent>(GetDefaultSubobjectByName(TEXT("MeshGun")));
		USkeletalMeshComponent* ArmsMesh = Cast<USkeletalMeshComponent>(GetDefaultSubobjectByName(TEXT("Arms")));
		USkeletalMeshComponent* ArmsGun = Cast<USkeletalMeshComponent>(GetDefaultSubobjectByName(TEXT("Gun")));
		if (BodyMesh && BodyGunMesh && ArmsMesh && ArmsGun) {
			BodyMesh->SetVisibility(true);
			BodyGunMesh->SetVisibility(true);
			ArmsMesh->SetVisibility(false);
			ArmsGun->SetVisibility(false);
		}
		else {
			return;
		}
	}
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);
	if (SmallEmitter) {
		SmallEmitter->SetActorLocation(Sculptor->GetActorLocation());
	}

	UpdateSculptAmmo(DeltaTime);

	if (!HasAuthority()) {
		return;
	}
	
	FVector Pos = MapGen->RoundDownPosition(GetActorLocation());
	if (Pos != PrevPos) {
		PrevPos = Pos;
		MapGen->ServerCheckSurrounding(GetActorLocation());
	}

	if (GetLocalRole() == ROLE_Authority) {
		UE_LOG(LogTemp, Warning, TEXT("Camera: %s"), *Camera->GetRelativeRotation().ToString())
	}

	if (GetLocalRole() == ROLE_AutonomousProxy) {
		SetServerSculptorLocation(Sculptor->GetActorLocation(), this);
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
	PlayerInputComponent->BindAction(TEXT("Sculpt"), EInputEvent::IE_Pressed, this, &APlayerCharacter::CallSculptStart);
	PlayerInputComponent->BindAction(TEXT("Sculpt"), EInputEvent::IE_Released, this, &APlayerCharacter::CallSculptEnd);
	PlayerInputComponent->BindAction(TEXT("Invert"), EInputEvent::IE_Pressed, this, &APlayerCharacter::Invert);
	PlayerInputComponent->BindAction(TEXT("Invert"), EInputEvent::IE_Released, this, &APlayerCharacter::Invert);
	
	PlayerInputComponent->BindAction(TEXT("CapHeight"), EInputEvent::IE_Pressed, this, &APlayerCharacter::CapHeight);
	PlayerInputComponent->BindAction(TEXT("CapHeight"), EInputEvent::IE_Released, this, &APlayerCharacter::CapHeight);
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

	//if (GetLocalRole() == ROLE_AutonomousProxy) {
		Camera->SetRelativeRotation(CamRot);
		//SetServerRotation(CamRot);
	//}
	
}

void APlayerCharacter::Turn(float Value)
{
	AddControllerYawInput(Value * LookSensitivity);
}

void APlayerCharacter::CallSculptStart()
{
	//SculptStartEvent.Broadcast();
	SculptStart();
	ServerSculptStart();
	
}

void APlayerCharacter::CallSculptEnd()
{
	SculptEnd();
	ServerSculptEnd();
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
	else {
		return;
	}

	BigEmitter = GetWorld()->SpawnActor<ADustClouds>(BigDustEmitterToSpawn, Sculptor->GetActorLocation(), FRotator::ZeroRotator);
	Sculptor->SculptState = SCULPTSTATE::STOPPED;

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
	if (GetLocalRole() == ROLE_AutonomousProxy) {
		ServerSlide();
	}
}

void APlayerCharacter::UpdateSculptAmmo(float DeltaTime)
{
	if (!IsLocallyControlled() || !HUD) {
		return;
	}

	switch (Sculptor->SculptState) {
	case SCULPTSTATE::ONGOING:
		HUD->PlayerHUDWidget->UpdateSculptAmmoBar(-SculptDepletionSpeed * DeltaTime);
		if (HUD->PlayerHUDWidget->bLowSculptAmmo) {
			SculptEnd();
		}
		return;
		
	default:
		HUD->PlayerHUDWidget->UpdateSculptAmmoBar(SculptCooldownSpeed * DeltaTime);
	}
}

void APlayerCharacter::ServerSlide_Implementation()
{
	UCharacterMovementComponent* Movement = GetCharacterMovement();
	Movement->SetWalkableFloorAngle(WalkableAngle - Movement->GetWalkableFloorAngle());
}

void APlayerCharacter::SetServerRotation_Implementation(FRotator Rot)
{
	Camera->SetRelativeRotation(Rot);
}

void APlayerCharacter::SetServerSculptorLocation_Implementation(FVector Pos, APlayerCharacter* Character)
{
	if (this == Character) //coaeke
	Sculptor->SetActorLocation(Pos);
}

void APlayerCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	//DOREPLIFETIME(APlayerCharacter, Camera);
	//DOREPLIFETIME(APlayerCharacter, CameraPos);
}

void APlayerCharacter::SetClientRotation_Implementation(FRotator Rot, APlayerCharacter* Player)
{
	if (this != Player)
	Camera->SetRelativeRotation(Rot);
	
}

void APlayerCharacter::ServerSculptEnd_Implementation()
{
	SculptEnd();
	MulticastSculptEnd();
}

void APlayerCharacter::MulticastSculptEnd_Implementation()
{
	if (GetLocalRole() == ROLE_SimulatedProxy) {
		SculptEnd();
	}
}

void APlayerCharacter::MulticastSculptStart_Implementation()
{
	if (GetLocalRole() == ROLE_SimulatedProxy) {
		SculptStart();
	}
}

void APlayerCharacter::ServerSculptStart_Implementation()
{
	SculptStart();
	MulticastSculptStart();
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

void APlayerCharacter::UpdateAmmoBar(float Percent)
{
	if (HUD->PlayerHUDWidget->bRecharging) {
		return;
	}
	HUD->PlayerHUDWidget->UpdateAmmoBar(-0.2);
}

void APlayerCharacter::Fire()
{
	if (&Sculptor->HitResult) {
		FHitResult HitResult = Sculptor->HitResult;
		AActor* HitActor = Cast<AActor>(HitResult.Actor);
		APlayerCharacter* HitCharacter = Cast<APlayerCharacter>(HitActor);
		if (HitCharacter) {

			USkeletalMeshComponent* SkeletalMesh = Cast<USkeletalMeshComponent>(HitCharacter->GetMesh());

			if (HitCharacter->HealthComponent->HealthPercentageRemaining() == 0.0f && SkeletalMesh) {

				SkeletalMesh->SetSimulatePhysics(true);
				SkeletalMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
				SkeletalMesh->AddImpulse(Camera->GetForwardVector() * 10000, HitResult.BoneName, true);
				HitCharacter->GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
			}
			else {
				HitCharacter->HealthComponent->OnTakeDamage(30.0f);
			}
		}
	}
}
