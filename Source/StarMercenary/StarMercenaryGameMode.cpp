// Copyright Epic Games, Inc. All Rights Reserved.

#include "StarMercenaryGameMode.h"
#include "StarMercenaryHUD.h"
//#include "StarMercenaryCharacter.h"
#include "Creatures/Persons/Player/StarMercenaryPlayer.h"
#include "UObject/ConstructorHelpers.h"

AStarMercenaryGameMode::AStarMercenaryGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/StarMercenary/Creatures/Persons/Player/BP_Player"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AStarMercenaryHUD::StaticClass();
}
