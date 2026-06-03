// Copyright (c) 2013-2026 Daniel Acourt. Version 36.4.4. Licensed under GPLv3 (See LICENSE). Last Updated: 2026-05-27

#include "Entities/SovereignBaseEntity.h"
#include "Entities/SovereignSaveableEntityComponent.h"
#include "Entities/SovereignPlayerWisp.h"
#include "Components/StaticMeshComponent.h"

ASovereignBaseEntity::ASovereignBaseEntity()
{
	PrimaryActorTick.bCanEverTick = false;

	SaveDataComponent = CreateDefaultSubobject<USovereignSaveableEntityComponent>(TEXT("SaveDataComponent"));

	EntityMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EntityMesh"));
	RootComponent = EntityMesh;

	bCanBePossessed = false; // Default for raw actors
}

void ASovereignBaseEntity::BeginPlay()
{
	Super::BeginPlay();
	if (SaveDataComponent)
	{
		SaveDataComponent->InitializeSoul();
	}
}

void ASovereignBaseEntity::OnInteract_Implementation(AActor* Interactor)
{
	UE_LOG(LogTemp, Log, TEXT("%s interacted with Sovereign Entity %s"), Interactor ? *Interactor->GetName() : TEXT("Unknown"), *GetName());
}

AActor* ASovereignBaseEntity::GetInhabitingSpirit_Implementation()
{
	TArray<AActor*> AttachedActors;
	GetAttachedActors(AttachedActors, true);
	for (AActor* Actor : AttachedActors)
	{
		if (Actor && Actor->Implements<UInteractionInterface>())
		{
			if (IInteractionInterface::Execute_IsSpiritEntity(Actor)) return Actor;
		}
	}
	return nullptr;
}

void ASovereignBaseEntity::RequestSoulEject_Implementation()
{
	// Non-pawns use EnableInput, so we must DisableInput on eject
	this->DisableInput(GetWorld()->GetFirstPlayerController());
	UE_LOG(LogTemp, Log, TEXT("[%s] Input Bridge: Severed."), *GetName());
}

USceneComponent* ASovereignBaseEntity::GetPossessionAttachmentComponent_Implementation()
{
	return EntityMesh;
}

void ASovereignBaseEntity::HandlePossessionLifecycle()
{
	AActor* Spirit = IInteractionInterface::Execute_GetInhabitingSpirit(this);
	if (Spirit)
	{
		if (ASovereignPlayerWisp* Wisp = Cast<ASovereignPlayerWisp>(Spirit))
		{
			Wisp->EjectFromHost();
		}
	}
}

void ASovereignBaseEntity::GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const
{
	TagContainer = FGameplayTagContainer();
	if (SaveDataComponent && SaveDataComponent->SpeciesTag.IsValid())
	{
		TagContainer.AddTag(SaveDataComponent->SpeciesTag);
	}
}
