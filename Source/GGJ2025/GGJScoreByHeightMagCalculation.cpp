// Fill out your copyright notice in the Description page of Project Settings.


#include "GGJScoreByHeightMagCalculation.h"
#include "GGJFruitAttributeSet.h"

UGGJScoreByHeightMagCalculation::UGGJScoreByHeightMagCalculation()
{
    ScoreDef.AttributeToCapture = UGGJFruitAttributeSet::GetValueAttribute();
    ScoreDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
    ScoreDef.bSnapshot = false;

    MaxScoreDef.AttributeToCapture = UGGJFruitAttributeSet::GetMaxValueAttribute();
    MaxScoreDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
    MaxScoreDef.bSnapshot = false;

    RelevantAttributesToCapture.Add(ScoreDef);
    RelevantAttributesToCapture.Add(MaxScoreDef);

    InitialHeight = 0.0f;
}

float UGGJScoreByHeightMagCalculation::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{

    const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
    const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

    FAggregatorEvaluateParameters EvaluationParameters;

    EvaluationParameters.SourceTags = SourceTags;
    EvaluationParameters.TargetTags = TargetTags;

    AActor* Source = Spec.GetEffectContext().GetInstigator();
    FVector ActorLocation = Source->GetActorLocation();

    float CurrentFruitHeight = ActorLocation.Z;

    if (InitialHeight == 0.0f) {
        InitialHeight = CurrentFruitHeight;
        return 0.0f;
    }

    else if (CurrentFruitHeight == InitialHeight) 
    {
        return 0.0f;
    }
    
    else {

        // Here, we calculate score: for every 100 units of height, add 10 points
        float ScoreBasedOnHeight = (InitialHeight / CurrentFruitHeight) * 0.5f;

        float Score = 0.0f;
        GetCapturedAttributeMagnitude(ScoreDef, Spec, EvaluationParameters, Score);

        float MaxScore = 0.0f;
        GetCapturedAttributeMagnitude(MaxScoreDef, Spec, EvaluationParameters, MaxScore);

#if UE_BUILD_DEBUG

        UE_LOG(LogTemp, Display, TEXT("Initial Height : %f"), InitialHeight);
        UE_LOG(LogTemp, Display, TEXT("Current Height : %f"), CurrentFruitHeight);
        UE_LOG(LogTemp, Display, TEXT("Adding score : %f"), ScoreBasedOnHeight);
        UE_LOG(LogTemp, Display, TEXT("Current score : %f"), Score);
        UE_LOG(LogTemp, Display, TEXT("Max score : %f"), MaxScore);
#endif
        if (Score + ScoreBasedOnHeight < MaxScore) {
            return MaxScore;
        }
        return ScoreBasedOnHeight;

    }

}