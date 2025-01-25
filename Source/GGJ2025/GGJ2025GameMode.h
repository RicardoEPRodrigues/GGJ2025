// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "LevelSequenceActor.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/GameModeBase.h"
#include "GGJ2025GameMode.generated.h"

USTRUCT(BlueprintType)
struct FGGJ2025GameModeLevel
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Level = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TargetScore = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GameTimer = 200;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ULevelSequence* IntroSequence = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSubclassOf<UGameplayAbility>> StartingAbilities;
	
};


UCLASS(minimalapi)
class AGGJ2025GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGGJ2025GameMode();

	// Basic Attribute Set
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Game Mode", meta = (AllowPrivateAccess = "true"))
	float GameTimer = 200;
	
	// Basic Attribute Set
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Game Mode", meta = (AllowPrivateAccess = "true"))
	TArray<FGGJ2025GameModeLevel> LevelsInfo;

	// Current score
	UPROPERTY(BlueprintReadWrite, Category = "Score")
	int32 CurrentScore;

	// High score
	UPROPERTY(BlueprintReadWrite, Category = "Score")
	int32 HighScore;

	// Current level
	UPROPERTY(BlueprintReadWrite, Category = "Level")
	int32 CurrentLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSubclassOf<UGameplayAbility>> CurrentPlayerAbilities;

	// Function to update the score
	UFUNCTION(BlueprintCallable, Category = "Score")
	void AddToScore(int32 Points);

	// Function to save the high score
	UFUNCTION(BlueprintCallable, Category = "Save")
	void SaveHighScore();

	// Function to load the high score
	UFUNCTION(BlueprintCallable, Category = "Save")
	void LoadHighScore();

	// Function to save the high score
	UFUNCTION(BlueprintCallable, Category = "Save")
	void SaveLevel();

	// Function to load the high score
	UFUNCTION(BlueprintCallable, Category = "Save")
	void LoadHighLevel();

	// Function to load the high score
	UFUNCTION(BlueprintCallable, Category = "Save")
	void ResetCurretLevelData();
};



