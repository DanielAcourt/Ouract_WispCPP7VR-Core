// Copyright (c) 2013-2026 Daniel Acourt. Version 36.4.4. Licensed under GPLv3 (See LICENSE). Last Updated: 2026-05-27

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameplayTagContainer.h"
#include "GameplayTagAssetInterface.h"
#include "Interaction/SovereignInterfaceMain.h"
#include "SovereignPawn.generated.h"

class USovereignSaveableEntityComponent;

UCLASS()
class WISPCPP7VR_API ASovereignPawn : public APawn, public IGameplayTagAssetInterface, public IInteractionInterface
{
	GENERATED_BODY()

public:
	ASovereignPawn();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// --- IInteractionInterface ---
	virtual class USovereignSaveableEntityComponent* GetSovereignSoul_Implementation() const override { return SaveDataComponent; }
	virtual bool CanBePossessed_Implementation() override { return bCanBePossessed; }
	virtual void OnInteract_Implementation(AActor* Interactor) override;
	virtual AActor* GetInhabitingSpirit_Implementation() override;
	virtual void RequestSoulEject_Implementation() override {}
	virtual USceneComponent* GetPossessionAttachmentComponent_Implementation() override;

	virtual void HandlePossessionLifecycle();

	// --- IGameplayTagAssetInterface ---
	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sovereign|SaveSystem")
	USovereignSaveableEntityComponent* SaveDataComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sovereign|Possession")
	bool bCanBePossessed = true;

	UFUNCTION()
	void MoveForward(float Value);

	UFUNCTION()
	void MoveRight(float Value);

	virtual void BeginPlay() override;
};
