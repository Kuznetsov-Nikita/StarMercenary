// Fill out your copyright notice in the Description page of Project Settings.


#include "AlienTrilobiteController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include <Runtime/Engine/Classes/Kismet/KismetMathLibrary.h>
#include "NavigationSystem.h"

AAlienTrilobiteController::AAlienTrilobiteController()
{
	PrimaryActorTick.bCanEverTick = true;

	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));
	SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("PerceptionComponent")));

	SightConfig->SightRadius = AISightRadius;
	SightConfig->SetMaxAge(AISightAge);
	SightConfig->LoseSightRadius = AILoseSightRadius;
	SightConfig->PeripheralVisionAngleDegrees = AIFieldOfView;

	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;

	GetPerceptionComponent()->SetDominantSense(*SightConfig->GetSenseImplementation());
	GetPerceptionComponent()->OnPerceptionUpdated.AddDynamic(this, &AAlienTrilobiteController::OnPawnDetected);
	GetPerceptionComponent()->ConfigureSense(*SightConfig);
}

void AAlienTrilobiteController::BeginPlay()
{
	Super::BeginPlay();
}

void AAlienTrilobiteController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

FRotator AAlienTrilobiteController::GetControlRotation() const
{
	if (GetPawn() == nullptr)
	{
		return FRotator(0.0f, 0.0f, 0.0f);
	}

	return FRotator(0.0f, GetPawn()->GetActorRotation().Yaw, 0.0f);
}

void AAlienTrilobiteController::OnPawnDetected(const TArray<AActor*>& DetectedPawns)
{
	if (DetectedPawns.Num() > 0)
	{
		for (int i = 0; i < DetectedPawns.Num(); ++i)
		{
			AStarMercenaryPlayer* DetectedPawn = Cast<AStarMercenaryPlayer>(DetectedPawns[i]);
			if (DetectedPawn != nullptr)
			{
				Player = DetectedPawn;

				if (FVector::Distance(Player->GetActorLocation(), GetPawn()->GetActorLocation()) > AILoseSightRadius)
				{
					bHasDetectedPlayer = false;
				}
				else
				{
					bHasDetectedPlayer = true;
				}
				break;
			}
		}
	}
}
