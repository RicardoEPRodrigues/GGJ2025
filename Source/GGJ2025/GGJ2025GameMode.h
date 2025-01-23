// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GGJ2025GameMode.generated.h"

UCLASS(minimalapi)
class AGGJ2025GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGGJ2025GameMode();

	// Basic Attribute Set
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Game Mode", meta = (AllowPrivateAccess = "true"))
	float GameTimer = 200;
};



