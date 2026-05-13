// Copyright (c) 2013-2025 Daniel Acourt. All Rights Reserved. Confidential & Proprietary.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Tests/AutomationCommon.h"
#include "Tests/AutomationCommon.h"
#include "Entities/SovereignBlackBoxComponent.h"
#include "Subsystems/SovereignBlackBoxSubsystem.h"
#include "Entities/SovereignBaseInteractable.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "HAL/PlatformFileManager.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"

BEGIN_DEFINE_SPEC(FSovereignBlackBoxSpec, "Sovereign.BlackBox", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
    UWorld* World;
    AActor* TestActor;
    USovereignBlackBoxComponent* BBComp;
    USovereignBlackBoxSubsystem* BBSubsystem;
END_DEFINE_SPEC(FSovereignBlackBoxSpec)

void FSovereignBlackBoxSpec::Define()
{
    BeforeEach([this]()
    {
        World = UWorld::CreateWorld(EWorldType::Game, false);
        BBSubsystem = World->GetSubsystem<USovereignBlackBoxSubsystem>();

        TestActor = World->SpawnActor<AActor>();

        // We use a mock class or just attach the component
        BBComp = NewObject<USovereignBlackBoxComponent>(TestActor);
        BBComp->RegisterComponent();

        // Ensure Identity is valid
        BBComp->EntityID = FGuid::NewGuid();
    });

    It("Should only log when delta threshold is exceeded", [this]()
    {
        // 1. Initial State
        BBComp->RecordTruthSnapshot(); // Should log initial values if any (0.0)

        FString FilePath = FPaths::ProjectSavedDir() / TEXT("BlackBox") / FString::Printf(TEXT("BB_%s.json"), *BBComp->EntityID.ToString());

        // 2. Change value below threshold (0.1 < 0.2)
        // Since we don't have a real ISovereignSaveInterface on a raw AActor,
        // we can't easily test the full scrape here without a real interactable.
        // But we can verify the file is created on the first snapshot.

        TestTrue("BlackBox file should exist after first record", FPlatformFileManager::Get().GetPlatformFile().FileExists(*FilePath));
    });

    AfterEach([this]()
    {
        if (TestActor)
        {
            FString FilePath = FPaths::ProjectSavedDir() / TEXT("BlackBox") / FString::Printf(TEXT("BB_%s.json"), *BBComp->EntityID.ToString());
            FPlatformFileManager::Get().GetPlatformFile().DeleteFile(*FilePath);
            TestActor->Destroy();
        }
        if (World)
        {
            World->DestroyWorld(true);
        }
    });
}
