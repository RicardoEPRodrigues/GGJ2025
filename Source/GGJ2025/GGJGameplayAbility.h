// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GGJGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class GGJ2025_API UGGJGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GGJ")
	FString Name = "";
};
