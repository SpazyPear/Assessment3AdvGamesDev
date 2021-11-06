// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"
#include "Engine/GameEngine.h"
#include "Net/UnrealNetwork.h"
#include "Kismet/GameplayStatics.h"
#include "TwistedGroundsHUD.h"
#include "PlayerCharacter.h"
#include "CheckCollisionThread.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	MaxHealth = 100.0f;
	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = MaxHealth;
	
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	/*
	if (GEngine && GetOwner()->GetLocalRole() == ROLE_AutonomousProxy)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, FString::Printf(TEXT("Current Health: %f"), CurrentHealth));
	}
	*/
}

void UHealthComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UHealthComponent, CurrentHealth);
}

void UHealthComponent::OnTakeDamage(float Damage)
{
	CurrentHealth -= Damage;
	if (CurrentHealth <= 0.0f)
	{
		CurrentHealth = 0;
		OnDeath();
	}
}

void UHealthComponent::OnDeath()
{
	CheckCollisionThread* ThreadHandler = new CheckCollisionThread();
	ThreadHandler->CreateThread(Cast<APlayerCharacter>(GetOwner()));
}

float UHealthComponent::HealthPercentageRemaining()
{
	return CurrentHealth/MaxHealth * 100.0f;
}

void UHealthComponent::UpdateHealthBar()
{
	if (GetOwner()->GetLocalRole() == ROLE_AutonomousProxy)
	{
		ATwistedGroundsHUD* PlayerHUD = Cast<ATwistedGroundsHUD>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD());
		if (PlayerHUD)
		{
			PlayerHUD->SetPlayerHealthBarPercent(CurrentHealth / MaxHealth);
		}
	}
}

