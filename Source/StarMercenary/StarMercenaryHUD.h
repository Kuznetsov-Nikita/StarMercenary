// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "StarMercenaryHUD.generated.h"

UCLASS()
class AStarMercenaryHUD : public AHUD
{
	GENERATED_BODY()

public:
	AStarMercenaryHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

