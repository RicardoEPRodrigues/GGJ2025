// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GGJFruitTree.generated.h"

UCLASS()
class GGJ2025_API AGGJFruitTree : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGGJFruitTree();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Basic Attribute Set
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tree")
	float SpawnCircleRadius;

	// Basic Attribute Set
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tree")
	float SpawnHeight;

	UFUNCTION(BlueprintCallable, Category = "Tree")
	FVector3f GetFruitSpawnPosition();
};
