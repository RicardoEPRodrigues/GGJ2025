// Fill out your copyright notice in the Description page of Project Settings.

#include "GGJFruitActor.h"
#include "AbilitySystemComponent.h"
#include "GGJFruitAttributeSet.h"


// Sets default values
AGGJFruitActor::AGGJFruitActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
}

// Called when the game starts or when spawned
void AGGJFruitActor::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(AbilitySystemComponent)) {
		FruitAttributeSet = AbilitySystemComponent->GetSet<UGGJFruitAttributeSet>();
	}
	
}

// Called every frame
void AGGJFruitActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

