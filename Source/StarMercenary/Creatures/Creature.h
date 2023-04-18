// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Components/HealthComponent.h"
#include "Delegates/Delegate.h"
#include "GameFramework/Character.h"
#include "Creature.generated.h"

DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_FourParams(FTakeAnyHealSignature, ACreature, OnTakeAnyHeal, AActor*, HealedActor, float, Heal, class AController*, InstigatedBy, AActor*, HealCauser);

UCLASS()
class STARMERCENARY_API ACreature : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACreature();

	UPROPERTY(BlueprintAssignable, Category = "Game|Heal")
	FTakeAnyHealSignature OnTakeAnyHeal;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UHealthComponent* Health;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/** Handles moving forward/backward */
	void MoveForward(float Val);

	/** Handles stafing movement, left and right */
	void MoveRight(float Val);
};
