// Fill out your copyright notice in the Description page of Project Settings.


#include "GGJPlayerAttributeSet.h"

// Clamping Stamina Values
void UGGJPlayerAttributeSet::PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const
{
    if (Attribute.AttributeName == "Stamina") {
        if (NewValue > MaxStamina.GetBaseValue()) {
            NewValue = MaxStamina.GetBaseValue();
        }

        else if (NewValue < 0)
            NewValue = 0;
    }
}
