// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STARMERCENARY_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	float DefaultHitPoints;

	UPROPERTY(BlueprintReadOnly)
	float HitPoints;

	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void TakeDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

	UFUNCTION(BlueprintCallable)
	void TakeHeal(AActor* HealedActor, float Heal, class AController* InstigatedBy, AActor* HealCauser);
};
