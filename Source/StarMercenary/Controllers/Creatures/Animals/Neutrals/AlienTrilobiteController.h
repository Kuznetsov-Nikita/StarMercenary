// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../../../../Creatures/Persons/Player/StarMercenaryPlayer.h"
#include "AIController.h"
#include "AlienTrilobiteController.generated.h"

/**
 * 
 */
UCLASS()
class STARMERCENARY_API AAlienTrilobiteController : public AAIController
{
	GENERATED_BODY()

public:
	AAlienTrilobiteController();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AI)
	float AISightRadius = 500.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AI)
	float AISightAge = 5.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AI)
	float AILoseSightRadius = AISightRadius + 50.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AI)
	float AIFieldOfView = 180.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AI)
	class UAISenseConfig_Sight* SightConfig;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = AI)
	AStarMercenaryPlayer* Player = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AI)
	bool bHasDetectedPlayer = false;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	virtual FRotator GetControlRotation() const override;

	UFUNCTION()
	virtual void OnPawnDetected(const TArray<AActor*>& DetectedPawns);
};
