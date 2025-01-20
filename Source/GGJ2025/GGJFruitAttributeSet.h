// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GGJFruitAttributeSet.generated.h"


/**
 * This macro defines a set of helper functions for accessing and initializing attributes.
 *
 */


#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName)\
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName,PropertyName)\
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName)\
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName)\
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class GGJ2025_API UGGJFruitAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly, Category = "Fruit Attributes")
	FGameplayAttributeData Value;
	ATTRIBUTE_ACCESSORS(UGGJFruitAttributeSet, Value);

	UPROPERTY(BlueprintReadOnly, Category = "Fruit Attributes")
	FGameplayAttributeData MaxValue;
	ATTRIBUTE_ACCESSORS(UGGJFruitAttributeSet, MaxValue);


	// Using this function to clamp the values
	virtual void PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const override;
};
