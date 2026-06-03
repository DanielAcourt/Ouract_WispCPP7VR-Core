// Copyright (c) 2013-2026 Daniel Acourt. Version 36.4.4. Licensed under GPLv3 (See LICENSE). Last Updated: 2026-05-27

#include "Entities/SovereignBaseInteractable.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/Engine.h"
#include "GameFramework/PlayerController.h"
#include "Entities/SovereignSaveableEntityComponent.h"
#include "Entities/SovereignBaseCharacter.h"
#include "Entities/SovereignPlayerWisp.h"

ASovereignBaseInteractable::ASovereignBaseInteractable()
{
    PrimaryActorTick.bCanEverTick = false;

    if (EntityMesh)
    {
        EntityMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
        EntityMesh->SetCollisionResponseToAllChannels(ECR_Block);
        EntityMesh->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
        EntityMesh->SetRelativeLocation(FVector::ZeroVector);
    }

    if (!SaveDataComponent)
    {
        SaveDataComponent = CreateDefaultSubobject<USovereignSaveableEntityComponent>(TEXT("SovereignSoul"));
    }
}

bool ASovereignBaseInteractable::CanInteract_Implementation(AActor* Interactor)
{
    return bIsInteractable && IsValid(Interactor);
}

void ASovereignBaseInteractable::OnInteract_Implementation(AActor* Interactor)
{
    if (!CanInteract_Implementation(Interactor)) return;

    if (ASovereignBaseCharacter* BaseChar = Cast<ASovereignBaseCharacter>(Interactor))
    {
        BaseChar->OnActorSensed.Broadcast(this);
    }

    UE_LOG(LogTemp, Log, TEXT("INTERACTED: %s with %s"), Interactor ? *Interactor->GetName() : TEXT("Unknown"), *GetName());
}

void ASovereignBaseInteractable::OnBeginHover_Implementation() {}
void ASovereignBaseInteractable::OnEndHover_Implementation() {}

FText ASovereignBaseInteractable::GetInteractableName_Implementation()
{
    return FText::FromString(TEXT("Interactable Object"));
}

FString ASovereignBaseInteractable::GetInteractionHint_Implementation()
{
    return TEXT("Interact");
}

void ASovereignBaseInteractable::OnSecondaryInteract_Implementation(AActor* Interactor) {}

bool ASovereignBaseInteractable::CanBePossessed_Implementation()
{
    return bCanBePossessed;
}

void ASovereignBaseInteractable::RequestPossession_Implementation(AController* RequestingController)
{
    if (APlayerController* PC = Cast<APlayerController>(RequestingController))
    {
        if (CanBePossessed_Implementation())
        {
            this->EnableInput(PC);

            // Hardcoded input binding for unpossession from non-pawn vessels
            if (InputComponent)
            {
                InputComponent->BindKey(EKeys::F, IE_Pressed, this, &ASovereignBaseInteractable::HandlePossessionLifecycle);
            }

            UE_LOG(LogTemp, Warning, TEXT("Input Bridge established for non-pawn actor: %s"), *GetName());
        }
    }
}

void ASovereignBaseInteractable::RequestSoulEject_Implementation()
{
    this->DisableInput(GetWorld()->GetFirstPlayerController());
    UE_LOG(LogTemp, Log, TEXT("[%s] Input Bridge: Severed."), *GetName());
}

USceneComponent* ASovereignBaseInteractable::GetPossessionAttachmentComponent_Implementation()
{
    return EntityMesh;
}

TMap<FString, FString> ASovereignBaseInteractable::GetSaveData()
{
    TMap<FString, FString> Data;
    Data.Add(TEXT("Telemetry.temp_c"), FString::SanitizeFloat(TemperatureCelsius));
    Data.Add(TEXT("Telemetry.ph_val"), FString::SanitizeFloat(PhValue));
    Data.Add(TEXT("Telemetry.water_depth_mm"), FString::SanitizeFloat(WaterDepthMM));
    return Data;
}

void ASovereignBaseInteractable::RestoreSaveData(const TMap<FString, FString>& Data)
{
    if (const FString* Val = Data.Find(TEXT("Telemetry.temp_c"))) TemperatureCelsius = FCString::Atof(**Val);
    if (const FString* Val = Data.Find(TEXT("Telemetry.ph_val"))) PhValue = FCString::Atof(**Val);
    if (const FString* Val = Data.Find(TEXT("Telemetry.water_depth_mm"))) WaterDepthMM = FCString::Atof(**Val);
}
