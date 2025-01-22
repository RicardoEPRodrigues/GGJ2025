// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "GGJScoreByHeightMagCalculation.generated.h"

/**
 * 
 */
UCLASS()
class GGJ2025_API UGGJScoreByHeightMagCalculation : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()

	UGGJScoreByHeightMagCalculation();

	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;

	FGameplayEffectAttributeCaptureDefinition ScoreDef;
	FGameplayEffectAttributeCaptureDefinition MaxScoreDef;

	float mutable InitialHeight = 0.0f;
	
};
