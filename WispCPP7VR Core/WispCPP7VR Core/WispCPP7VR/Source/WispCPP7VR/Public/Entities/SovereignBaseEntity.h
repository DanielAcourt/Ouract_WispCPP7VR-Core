// Copyright (c) 2013-2026 Daniel Acourt. Version 36.4.4. Licensed under GPLv3 (See LICENSE). Last Updated: 2026-05-27

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "GameplayTagAssetInterface.h"
#include "Interaction/SovereignInterfaceMain.h"
#include "InputActionValue.h"
#include "SovereignBaseEntity.generated.h"

class USovereignSaveableEntityComponent;
class UStaticMeshComponent;

/**
 * ASovereignBaseEntity
 * The root AActor for all Sovereign-aware objects in the world.
 * Provides the "Soul" component and basic interface compliance.
 * As of v36.4.4, mating/growth logic is handled by the SaveDataComponent (The Soul).
 */
UCLASS()
class WISPCPP7VR_API ASovereignBaseEntity : public AActor, public IGameplayTagAssetInterface, public IInteractionInterface
{
	GENERATED_BODY()

public:
	ASovereignBaseEntity();

	// --- IInteractionInterface ---
	virtual class USovereignSaveableEntityComponent* GetSovereignSoul_Implementation() const override { return SaveDataComponent; }
	virtual bool CanBePossessed_Implementation() override { return bCanBePossessed; }
	virtual void OnInteract_Implementation(AActor* Interactor) override;
	virtual AActor* GetInhabitingSpirit_Implementation() override;
	virtual void RequestSoulEject_Implementation() override;
	virtual USceneComponent* GetPossessionAttachmentComponent_Implementation() override;

	virtual void HandlePossessionLifecycle();
	virtual void Evolve() {}

	// --- IGameplayTagAssetInterface ---
	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|SaveSystem")
	USovereignSaveableEntityComponent* SaveDataComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|Visuals")
	UStaticMeshComponent* EntityMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Possession")
	bool bCanBePossessed = true;

	virtual void BeginPlay() override;
};
