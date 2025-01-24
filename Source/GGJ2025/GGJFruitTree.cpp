// Fill out your copyright notice in the Description page of Project Settings.


#include "GGJFruitTree.h"

#include "Algo/RandomShuffle.h"


// Sets default values
AGGJFruitTree::AGGJFruitTree()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGGJFruitTree::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGGJFruitTree::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

FVector3f AGGJFruitTree::GetFruitSpawnPosition()
{
	// Returns the position within the circle
	FVector CenterPosition;
	CenterPosition = this->GetActorLocation();

	CenterPosition = CenterPosition + FVector(0, 0, SpawnHeight);

	float randomAngle = FMath::RandRange(0,360); 
	
	float X = CenterPosition.X + (SpawnCircleRadius * FMath::Cos(randomAngle));
	float Y = CenterPosition.Y + (SpawnCircleRadius * FMath::Sin(randomAngle));

	FVector3f SpawnPosition = FVector3f(X, Y, CenterPosition.Z);

	return SpawnPosition;	
}

