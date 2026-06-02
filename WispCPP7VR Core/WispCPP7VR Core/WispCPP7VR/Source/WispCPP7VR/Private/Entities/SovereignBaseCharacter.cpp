// Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.4. Licensed under GPLv3 (See LICENSE). Last Updated: 2025-05-22

#include "Entities/SovereignBaseCharacter.h"
#include "Entities/SovereignPlayerWisp.h"
#include "Components/SovereignAttributeComponent.h"
#include "Components/SovereignQiComponent.h"
#include "Components/SovereignElementComponent.h"
#include "Components/SovereignControllerComponent.h"
#include "Components/SovereignSaveableEntityComponent.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"

ASovereignBaseCharacter::ASovereignBaseCharacter()
{
	// Character-specific component initialization
	AttributeComponent = CreateDefaultSubobject<USovereignAttributeComponent>(TEXT("AttributeComponent"));
	QiComponent = CreateDefaultSubobject<USovereignQiComponent>(TEXT("QiComponent"));
	ElementComponent = CreateDefaultSubobject<USovereignElementComponent>(TEXT("ElementComponent"));
	ControlComponent = CreateDefaultSubobject<USovereignControllerComponent>(TEXT("ControlComponent"));

	// Map the inherited EntityMesh to the Character Mesh
	if (GetMesh())
	{
		EntityMesh->SetupAttachment(GetMesh());
	}
}

void ASovereignBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ASovereignBaseCharacter::Evolve()
{
	UE_LOG(LogTemp, Log, TEXT("Base Character Evolving..."));
}

void ASovereignBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
