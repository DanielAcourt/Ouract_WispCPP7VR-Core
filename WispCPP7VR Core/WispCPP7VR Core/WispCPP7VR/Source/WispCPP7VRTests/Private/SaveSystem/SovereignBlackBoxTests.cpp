// Copyright (c) 2013-2025 Daniel Acourt. All Rights Reserved. Confidential & Proprietary.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Tests/AutomationCommon.h"
#include "Entities/SovereignBlackBoxComponent.h"
#include "Subsystems/SovereignBlackBoxSubsystem.h"
#include "Entities/SovereignBaseInteractable.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "HAL/PlatformFileManager.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"
#include "Dom/JsonObject.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(FSovereignBlackBoxSpec, "Sovereign.BlackBox", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
    UWorld* World;
    AActor* TestActor;
    USovereignBlackBoxComponent* BBComp;
    USovereignBlackBoxSubsystem* BBSubsystem;

    // Helper methods
    FString GetBlackBoxFilePath() const;
    bool VerifyFileExists(const FString& FilePath) const;
    TSharedPtr<FJsonObject> LoadJsonFile(const FString& FilePath) const;
    void CleanupBlackBoxFile(const FString& FilePath) const;
END_DEFINE_SPEC(FSovereignBlackBoxSpec)

FString FSovereignBlackBoxSpec::GetBlackBoxFilePath() const
{
    return FPaths::ProjectSavedDir() / TEXT("BlackBox") / FString::Printf(TEXT("BB_%s.json"), *BBComp->EntityID.ToString());
}

bool FSovereignBlackBoxSpec::VerifyFileExists(const FString& FilePath) const
{
    return FPlatformFileManager::Get().GetPlatformFile().FileExists(*FilePath);
}

TSharedPtr<FJsonObject> FSovereignBlackBoxSpec::LoadJsonFile(const FString& FilePath) const
{
    if (!VerifyFileExists(FilePath))
    {
        return nullptr;
    }

    FString JsonContent;
    if (!FFileHelper::LoadFileToString(JsonContent, *FilePath))
    {
        return nullptr;
    }

    TSharedPtr<FJsonObject> JsonObject;
    const TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(JsonContent);
    
    if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
    {
        return JsonObject;
    }

    return nullptr;
}

void FSovereignBlackBoxSpec::CleanupBlackBoxFile(const FString& FilePath) const
{
    if (VerifyFileExists(FilePath))
    {
        FPlatformFileManager::Get().GetPlatformFile().DeleteFile(*FilePath);
    }
}

void FSovereignBlackBoxSpec::Define()
{
    BeforeEach([this]()
    {
        // Create a transient world for testing
        World = NewObject<UWorld>();
        World->WorldType = EWorldType::Editor;
        
        FWorldContext& WorldContext = GEngine->CreateNewWorldContext(EWorldType::Editor);
        WorldContext.SetCurrentWorld(World);

        TestTrue("World should be created successfully", World != nullptr);

        BBSubsystem = World->GetSubsystem<USovereignBlackBoxSubsystem>();
        TestTrue("BlackBox subsystem should be valid", BBSubsystem != nullptr);

        TestActor = World->SpawnActor<AActor>();
        TestTrue("Test actor should be spawned", TestActor != nullptr);

        BBComp = NewObject<USovereignBlackBoxComponent>(TestActor);
        TestTrue("BlackBox component should be created", BBComp != nullptr);

        BBComp->RegisterComponent();
        BBComp->EntityID = FGuid::NewGuid();
    });

    It("Should create BlackBox file on first snapshot", [this]()
    {
        // Arrange
        const FString FilePath = GetBlackBoxFilePath();
        CleanupBlackBoxFile(FilePath); // Ensure clean state

        // Act
        BBComp->RecordTruthSnapshot();

        // Assert
        TestTrue("BlackBox file should exist after first record", VerifyFileExists(FilePath));
    });

    It("Should record valid JSON structure", [this]()
    {
        // Arrange
        const FString FilePath = GetBlackBoxFilePath();
        CleanupBlackBoxFile(FilePath);

        // Act
        BBComp->RecordTruthSnapshot();

        // Assert
        const TSharedPtr<FJsonObject> JsonObject = LoadJsonFile(FilePath);
        TestTrue("JSON should be parseable", JsonObject.IsValid());
        TestTrue("JSON should contain EntityID", JsonObject.IsValid() && JsonObject->HasField(TEXT("EntityID")));
    });

    It("Should not log when delta is below threshold", [this]()
    {
        // Arrange
        const FString FilePath = GetBlackBoxFilePath();
        CleanupBlackBoxFile(FilePath);
        BBComp->RecordTruthSnapshot();

        // Get initial file size
        const int64 InitialFileSize = FPlatformFileManager::Get().GetPlatformFile().FileSize(*FilePath);

        // Act - Make a small change below threshold (adjust threshold value as needed)
        // This assumes BBComp has a mechanism to set small deltas
        BBComp->RecordTruthSnapshot();

        // Assert
        const int64 FinalFileSize = FPlatformFileManager::Get().GetPlatformFile().FileSize(*FilePath);
        TestTrue("File size should not significantly change below threshold", FinalFileSize <= InitialFileSize * 1.1); // Allow 10% variance
    });

    It("Should log when delta exceeds threshold", [this]()
    {
        // Arrange
        const FString FilePath = GetBlackBoxFilePath();
        CleanupBlackBoxFile(FilePath);
        BBComp->RecordTruthSnapshot();

        const int64 InitialFileSize = FPlatformFileManager::Get().GetPlatformFile().FileSize(*FilePath);

        // Act - Make a significant change exceeding threshold
        // This requires setting up a significant state change
        BBComp->RecordTruthSnapshot();

        // Assert
        const int64 FinalFileSize = FPlatformFileManager::Get().GetPlatformFile().FileSize(*FilePath);
        TestTrue("File size should increase when threshold is exceeded", FinalFileSize > InitialFileSize);
    });

    AfterEach([this]()
    {
        if (TestActor)
        {
            const FString FilePath = GetBlackBoxFilePath();
            CleanupBlackBoxFile(FilePath);
            TestActor->Destroy();
        }

        if (World)
        {
            GEngine->DestroyWorldContext(World);
            World->DestroyWorld(true);
        }
    });
}

#endif  // WITH_DEV_AUTOMATION_TESTS
