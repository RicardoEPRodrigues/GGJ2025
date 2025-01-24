// Copyright Epic Games, Inc. All Rights Reserved.

#include "GGJ2025GameMode.h"
#include "GGJ2025Character.h"
#include "GGJSaveGame.h"
#include "GameFramework/SaveGame.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

AGGJ2025GameMode::AGGJ2025GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	CurrentScore = 0;
	HighScore = 0;
}

void AGGJ2025GameMode::AddToScore(int32 Points)
{
	CurrentScore += Points;

	// Check if we have a new high score
	if (CurrentScore > HighScore)
	{
		HighScore = CurrentScore;
	}
}

void AGGJ2025GameMode::SaveHighScore()
{
	// Create or access the SaveGame object
	UGGJSaveGame* SaveGameInstance = Cast<UGGJSaveGame>(UGameplayStatics::CreateSaveGameObject(UGGJSaveGame::StaticClass()));
	if (SaveGameInstance)
	{
		// Save the high score
		SaveGameInstance->HighScore = HighScore;
		// Cast to a custom save game class if needed
		UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("HighScoreSlot"), 0);
	}
}

void AGGJ2025GameMode::LoadHighScore()
{
	// Check if a save game exists in the specified slot
	if (UGameplayStatics::DoesSaveGameExist(TEXT("HighScoreSlot"), 0))
	{
		// Load the save game object from the slot
		if (UGGJSaveGame* SaveGameInstance = Cast<UGGJSaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("HighScoreSlot"), 0)))
		{
			// Retrieve the saved high score and assign it to the HighScore variable
			HighScore = SaveGameInstance->HighScore;
			UE_LOG(LogTemp, Log, TEXT("High score successfully loaded: %d"), HighScore);
		}
		else
		{
			// Log an error if the cast failed
			UE_LOG(LogTemp, Error, TEXT("Failed to load save game instance from slot."));
		}
	}
	else
	{
		// Log a message if no save game exists
		UE_LOG(LogTemp, Warning, TEXT("No save game found in HighScoreSlot. High score will be set to 0."));
		HighScore = 0; // Default to 0 if no save game exists
	}
}

void AGGJ2025GameMode::SaveLevel()
{
	// Create or access the SaveGame object
	UGGJSaveGame* SaveGameInstance = Cast<UGGJSaveGame>(UGameplayStatics::CreateSaveGameObject(UGGJSaveGame::StaticClass()));
	if (SaveGameInstance)
	{
		// Save the level
		SaveGameInstance->CurrentLevel = CurrentLevel;

		// Cast to a custom save game class if needed
		UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("HighScoreSlot"), 0);
	}
}

void AGGJ2025GameMode::LoadHighLevel()
{
	// Check if a save game exists in the specified slot
	if (UGameplayStatics::DoesSaveGameExist(TEXT("HighScoreSlot"), 0))
	{
		// Load the save game object from the slot
		if (UGGJSaveGame* SaveGameInstance = Cast<UGGJSaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("HighScoreSlot"), 0)))
		{
			// Retrieve the saved high score and assign it to the HighScore variable
			CurrentLevel = SaveGameInstance->CurrentLevel;
			HighScore = SaveGameInstance->HighScore;
			UE_LOG(LogTemp, Log, TEXT("High score successfully loaded: %d"), HighScore);
		}
		else
		{
			// Log an error if the cast failed
			UE_LOG(LogTemp, Error, TEXT("Failed to load save game instance from slot."));
		}
	}
	else
	{
		// Log a message if no save game exists
		UE_LOG(LogTemp, Warning, TEXT("No save game found in HighScoreSlot. High score will be set to 0."));
		HighScore = 0; // Default to 0 if no save game exists
		CurrentLevel = 0;
	}
}
