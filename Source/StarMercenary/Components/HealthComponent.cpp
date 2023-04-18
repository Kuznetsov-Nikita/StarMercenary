// Fill out your copyright notice in the Description page of Project Settings.


#include "../Creatures/Creature.h"
#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	DefaultHitPoints = 100.0;
	HitPoints = DefaultHitPoints;
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	AActor* Owner = GetOwner();

	if (Owner)
	{
		Owner->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::TakeDamage);

		ACreature* OwnerCreature = Cast<ACreature>(Owner);

		if (OwnerCreature)
		{
			OwnerCreature->OnTakeAnyHeal.AddDynamic(this, &UHealthComponent::TakeHeal);
		}
	}
}

void UHealthComponent::TakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	if (Damage <= 0)
	{
		return;
	}

	HitPoints = FMath::Clamp(HitPoints - Damage, 0.0f, DefaultHitPoints);
}

void UHealthComponent::TakeHeal(AActor* HealedActor, float Heal, AController* InstigatedBy, AActor* HealCauser)
{
	if (Heal <= 0)
	{
		return;
	}

	HitPoints = FMath::Clamp(HitPoints + Heal, 0.0f, DefaultHitPoints);
}

