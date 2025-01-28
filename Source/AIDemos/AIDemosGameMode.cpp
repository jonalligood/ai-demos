// Copyright Epic Games, Inc. All Rights Reserved.

#include "AIDemosGameMode.h"
#include "AIDemosPlayerController.h"
#include "AIDemosCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAIDemosGameMode::AAIDemosGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AAIDemosPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}