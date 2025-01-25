// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "AbilitySystemComponent.h"
#include "GGJSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class GGJ2025_API UGGJSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	// High score variable
	UPROPERTY(BlueprintReadWrite, Category = "SaveData")
	int32 HighScore;

	// High score variable
	UPROPERTY(BlueprintReadWrite, Category = "SaveData")
	int32 CurrentLevel;

	UPROPERTY(BlueprintReadWrite, Category = "SaveData")
	TArray<TSubclassOf<UGameplayAbility>> PlayerAbilities;

	// Constructor
	UGGJSaveGame();
};
