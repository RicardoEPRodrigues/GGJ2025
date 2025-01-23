// Copyright Epic Games, Inc. All Rights Reserved.

#include "GGJ2025Character.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "AbilitySystemComponent.h"
#include "InputActionValue.h"
#include "GGJPlayerAttributeSet.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);


AGGJ2025Character::AGGJ2025Character()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-10.f, 0.f, 60.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	Mesh1P->SetRelativeLocation(FVector(-30.f, 0.f, -150.f));

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
}

void AGGJ2025Character::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(AbilitySystemComponent))
	{
		GGJPlayerAbilitySet = AbilitySystemComponent->GetSet<UGGJPlayerAttributeSet>();
	}
}

void AGGJ2025Character::ShowBubble()
{
	UE_LOG(LogTemp, Warning, TEXT("ShowBubble"));
	if (!IsValid(BubbleClass))
	{
		UE_LOG(LogTemp, Error, TEXT("BubbleClass is not valid"));
		return;
	}

	const FVector CameraLocation = FirstPersonCameraComponent->GetComponentLocation();
	const FVector CameraForward = FirstPersonCameraComponent->GetForwardVector();
	const FVector ZOffset = FVector(0.0f, 0.0f, 10.0f);

	const float Distance = 1000.0f;

	FVector BubbleLocation = CameraLocation + (CameraForward * Distance) + ZOffset;

	FVector BubbleScale = FVector(16.0f, 16.0f, 16.0f);
	FRotator BubbleRotation = FRotator(0.0f, 0.0f, 0.0f);

	FTransform BubbleTransform = FTransform(BubbleRotation.Quaternion(), BubbleLocation, BubbleScale);

	FActorSpawnParameters SpawnParams;
	SpawnParams.TransformScaleMethod = ESpawnActorScaleMethod::MultiplyWithRoot;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	
	AActor* BubbleUI = GetWorld()->SpawnActor(BubbleClass, &BubbleTransform, SpawnParams);
	if (IsValid(BubbleUI))
	{
		BubbleUI->SetActorScale3D(BubbleScale);
	}

	
}
