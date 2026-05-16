// Copyright (c) 2013-2025 Daniel Acourt. All Rights Reserved. Confidential & Proprietary.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Tests/AutomationCommon.h"
#include "Entities/SovereignBlackBoxComponent.h"
#include "Subsystems/SovereignBlackBoxSubsystem.h"
#include "SaveSystem/SovereignPSTAConfig.h"
#include "SaveSystem/SovereignBlackBoxExporter.h"
#include "Subsystems/SovereignBlackBoxHeartbeat.h"
#include "Subsystems/SovereignBlackBoxReplaySubsystem.h"
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
    void SafeDestroyActor(AActor* Actor);
END_DEFINE_SPEC(FSovereignBlackBoxSpec)

FString FSovereignBlackBoxSpec::GetBlackBoxFilePath() const
{
    if (!BBComp)
    {
        return FString();
    }
    return FPaths::ProjectSavedDir() / TEXT("BlackBox") / FString::Printf(TEXT("BB_%s.json"), *BBComp->EntityID.ToString());
}

bool FSovereignBlackBoxSpec::VerifyFileExists(const FString& FilePath) const
{
    if (FilePath.IsEmpty())
    {
        return false;
    }
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

void FSovereignBlackBoxSpec::SafeDestroyActor(AActor* Actor)
{
    if (Actor && IsValid(Actor) && !Actor->IsActorBeingDestroyed())
    {
        Actor->Destroy(false, false);
    }
}

void FSovereignBlackBoxSpec::Define()
{
    BeforeEach([this]()
    {
        // Use the existing editor world context instead of creating a transient one
        World = nullptr;
        if (GEngine && GEngine->GetWorldContexts().Num() > 0)
        {
            World = GEngine->GetWorldContexts()[0].World();
        }

        TestTrue("Test World should be valid", World != nullptr);
        if (!World) 
        {
            return;
        }

        BBSubsystem = World->GetSubsystem<USovereignBlackBoxSubsystem>();
        TestTrue("BlackBox subsystem should be valid", BBSubsystem != nullptr);

        // Create a simple test actor (not abstract)
        FActorSpawnParameters SpawnParams;
        SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
        TestActor = World->SpawnActor<AActor>(SpawnParams);
        TestTrue("Test actor should be spawned", TestActor != nullptr);

        if (!TestActor)
        {
            return;
        }

        // Create and attach the BlackBox component
        BBComp = NewObject<USovereignBlackBoxComponent>(TestActor);
        TestTrue("BlackBox component should be created", BBComp != nullptr);

        if (BBComp)
        {
            BBComp->RegisterComponent();
            BBComp->EntityID = FGuid::NewGuid();
        }
    });

    // ============================================================
    // CORE FUNCTIONALITY TESTS
    // ============================================================

    It("Should create BlackBox file on first snapshot", [this]()
    {
        // Arrange
        TestTrue("Setup should be valid", BBComp != nullptr && World != nullptr);
        if (!BBComp || !World) return;

        const FString FilePath = GetBlackBoxFilePath();
        CleanupBlackBoxFile(FilePath);

        // Act
        BBComp->RecordTruthSnapshot();

        // Assert
        TestTrue("BlackBox file should exist after first snapshot", VerifyFileExists(FilePath));
    });

    It("Should record valid JSON structure", [this]()
    {
        // Arrange
        TestTrue("Setup should be valid", BBComp != nullptr);
        if (!BBComp) return;

        const FString FilePath = GetBlackBoxFilePath();
        CleanupBlackBoxFile(FilePath);

        // Act
        BBComp->RecordTruthSnapshot();

        // Assert
        const TSharedPtr<FJsonObject> JsonObject = LoadJsonFile(FilePath);
        TestTrue("JSON should be parseable", JsonObject.IsValid());
        
        if (JsonObject.IsValid())
        {
            TestTrue("JSON should contain EntityID field", JsonObject->HasField(TEXT("EntityID")));
            TestTrue("JSON should contain Logs field", JsonObject->HasField(TEXT("Logs")));
        }
    });

    It("Should record events in JSON", [this]()
    {
        // Arrange
        TestTrue("Setup should be valid", BBComp != nullptr);
        if (!BBComp) return;

        const FString FilePath = GetBlackBoxFilePath();
        CleanupBlackBoxFile(FilePath);

        // Act
        BBComp->RecordEvent(TEXT("TestEvent"), TEXT("TestValue"));
        BBComp->RecordTruthSnapshot();

        // Assert
        const TSharedPtr<FJsonObject> JsonObject = LoadJsonFile(FilePath);
        TestTrue("JSON should be parseable", JsonObject.IsValid());

        if (JsonObject.IsValid())
        {
            const TArray<TSharedPtr<FJsonValue>>* Logs = nullptr;
            if (JsonObject->TryGetArrayField(TEXT("Logs"), Logs) && Logs)
            {
                bool bFoundEvent = false;
                for (const auto& LogVal : *Logs)
                {
                    const TSharedPtr<FJsonObject> LogEntry = LogVal->AsObject();
                    if (LogEntry && LogEntry->HasField(TEXT("Key")))
                    {
                        FString Key = LogEntry->GetStringField(TEXT("Key"));
                        if (Key == TEXT("TestEvent"))
                        {
                            bFoundEvent = true;
                            break;
                        }
                    }
                }
                TestTrue("Should have recorded the test event", bFoundEvent);
            }
        }
    });

    // ============================================================
    // CSV EXPORT TESTS
    // ============================================================

    It("Should export logs to CSV using Exporter", [this]()
    {
        // Arrange
        TestTrue("Setup should be valid", BBComp != nullptr);
        if (!BBComp) return;

        BBComp->RecordEvent(TEXT("ExportTestEvent"), TEXT("ExportTestData"));
        BBComp->RecordTruthSnapshot();

        // Act
        FString CsvPath;
        bool bSuccess = USovereignBlackBoxExporter::ExportEntityLogToCSV(BBComp->EntityID, CsvPath);

        // Assert
        TestTrue("CSV Export should be successful", bSuccess);
        TestTrue("CSV file should exist", VerifyFileExists(CsvPath));

        if (bSuccess && VerifyFileExists(CsvPath))
        {
            FString Content;
            if (FFileHelper::LoadFileToString(Content, *CsvPath))
            {
                TestTrue("CSV should contain event data", Content.Contains(TEXT("ExportTestEvent")));
            }
        }
    });

    // ============================================================
    // PSTA TESTS
    // ============================================================

    It("Should record PSTA dimension health correctly", [this]()
    {
        // Arrange
        TestTrue("Setup should be valid", BBComp != nullptr);
        if (!BBComp) return;

        USovereignPSTAConfig* Config = NewObject<USovereignPSTAConfig>();
        if (!Config) return;

        // Setup PSTA tag mapping for temperature
        FPSTATagMapping Mapping;
        Mapping.TagKey = TEXT("Telemetry.temp_c");
        Mapping.Dimension = EPSTADimension::Technical;
        Mapping.Weight = 1.0f;
        Mapping.RangeMin = 0.0f;
        Mapping.RangeMax = 100.0f;
        Config->TagMappings.Add(Mapping);

        // Setup dimension weights
        Config->DimensionWeights.Add(EPSTADimension::Technical, 1.0f);
        Config->DimensionWeights.Add(EPSTADimension::Psychological, 0.0f);
        Config->DimensionWeights.Add(EPSTADimension::Social, 0.0f);
        Config->DimensionWeights.Add(EPSTADimension::Administrative, 0.0f);

        BBComp->PSTAConfig = Config;

        const FString FilePath = GetBlackBoxFilePath();
        CleanupBlackBoxFile(FilePath);

        // Act
        BBComp->RecordTruthSnapshot();

        // Assert
        const TSharedPtr<FJsonObject> JsonObject = LoadJsonFile(FilePath);
        TestTrue("JSON should be valid", JsonObject.IsValid());

        if (JsonObject.IsValid())
        {
            const TArray<TSharedPtr<FJsonValue>>* Logs = nullptr;
            if (JsonObject->TryGetArrayField(TEXT("Logs"), Logs) && Logs)
            {
                bool bFoundDimension = false;
                for (const auto& LogVal : *Logs)
                {
                    const TSharedPtr<FJsonObject> LogEntry = LogVal->AsObject();
                    if (LogEntry && LogEntry->HasField(TEXT("Key")))
                    {
                        FString Key = LogEntry->GetStringField(TEXT("Key"));
                        // PSTA Di dimension keys should exist
                        if (Key.Contains(TEXT("PSTA.Di")))
                        {
                            bFoundDimension = true;
                            break;
                        }
                    }
                }
                TestTrue("Should have recorded PSTA dimension health", bFoundDimension);
            }
        }
    });

    // ============================================================
    // THRESHOLD TESTS
    // ============================================================

    It("Should track file changes on snapshots", [this]()
    {
        // Arrange
        TestTrue("Setup should be valid", BBComp != nullptr);
        if (!BBComp) return;

        const FString FilePath = GetBlackBoxFilePath();
        CleanupBlackBoxFile(FilePath);

        // Act - Take first snapshot
        BBComp->RecordTruthSnapshot();
        int64 FirstFileSize = FPlatformFileManager::Get().GetPlatformFile().FileSize(*FilePath);

        // Take another snapshot without changes
        BBComp->RecordTruthSnapshot();
        int64 SecondFileSize = FPlatformFileManager::Get().GetPlatformFile().FileSize(*FilePath);

        // Assert
        TestTrue("First snapshot should create file", FirstFileSize > 0);
        TestTrue("Second snapshot should exist", SecondFileSize > 0);
    });

    // ============================================================
    // INGESTION TESTS
    // ============================================================

    It("Should ingest external telemetry entries", [this]()
    {
        // Arrange
        TestTrue("Setup should be valid", BBComp != nullptr);
        if (!BBComp) return;

        FBlackBoxEntry Entry;
        Entry.Key = TEXT("ExternalTelemetry.test_value");
        Entry.Value = 42.5f;

        // Act
        BBComp->IngestBlackBoxEntry(Entry);
        BBComp->RecordTruthSnapshot();

        const FString FilePath = GetBlackBoxFilePath();

        // Assert
        const TSharedPtr<FJsonObject> JsonObject = LoadJsonFile(FilePath);
        TestTrue("JSON should be valid after ingestion", JsonObject.IsValid());

        if (JsonObject.IsValid())
        {
            const TArray<TSharedPtr<FJsonValue>>* Logs = nullptr;
            if (JsonObject->TryGetArrayField(TEXT("Logs"), Logs) && Logs)
            {
                bool bFoundIngested = false;
                for (const auto& LogVal : *Logs)
                {
                    const TSharedPtr<FJsonObject> LogEntry = LogVal->AsObject();
                    if (LogEntry && LogEntry->HasField(TEXT("Key")))
                    {
                        FString Key = LogEntry->GetStringField(TEXT("Key"));
                        if (Key == TEXT("ExternalTelemetry.test_value"))
                        {
                            bFoundIngested = true;
                            if (LogEntry->HasField(TEXT("Value")))
                            {
                                double Value = LogEntry->GetNumberField(TEXT("Value"));
                                TestEqual("Ingested value should match", Value, 42.5);
                            }
                            break;
                        }
                    }
                }
                TestTrue("Should have recorded ingested telemetry", bFoundIngested);
            }
        }
    });

    // ============================================================
    // HEARTBEAT TESTS
    // ============================================================

    It("Should register and tick via Heartbeat subsystem", [this]()
    {
        // Arrange
        TestTrue("Setup should be valid", BBComp != nullptr && World != nullptr);
        if (!BBComp || !World) return;

        USovereignBlackBoxHeartbeat* Heartbeat = World->GetSubsystem<USovereignBlackBoxHeartbeat>();
        TestTrue("Heartbeat subsystem should exist", Heartbeat != nullptr);
        
        if (!Heartbeat) return;

        BBComp->UpdateFrequency = EUpdateFrequency::Realtime;

        const FString FilePath = GetBlackBoxFilePath();
        CleanupBlackBoxFile(FilePath);

        // Act
        Heartbeat->RegisterComponent(BBComp, EUpdateFrequency::Realtime);
        Heartbeat->Tick(0.2f); // Simulate 200ms passing

        // Assert - Should have created a snapshot file
        TestTrue("Heartbeat should have triggered snapshot", VerifyFileExists(FilePath));
    });

    // ============================================================
    // SUBSYSTEM TESTS
    // ============================================================

    It("Should have valid BlackBox subsystem in world", [this]()
    {
        // Arrange & Act
        TestTrue("Setup should be valid", World != nullptr);
        if (!World) return;

        USovereignBlackBoxSubsystem* Subsystem = World->GetSubsystem<USovereignBlackBoxSubsystem>();

        // Assert
        TestTrue("BlackBox subsystem should be valid", Subsystem != nullptr);
    });

    It("Should have valid Replay subsystem in world", [this]()
    {
        // Arrange & Act
        TestTrue("Setup should be valid", World != nullptr);
        if (!World) return;

        USovereignBlackBoxReplaySubsystem* ReplaySubsystem = World->GetSubsystem<USovereignBlackBoxReplaySubsystem>();

        // Assert
        TestTrue("Replay subsystem should exist", ReplaySubsystem != nullptr);
    });

    // ============================================================
    // CLEANUP
    // ============================================================

    AfterEach([this]()
    {
        // Clean up the BlackBox file
        if (BBComp)
        {
            const FString FilePath = GetBlackBoxFilePath();
            CleanupBlackBoxFile(FilePath);
        }

        // Destroy test actor if it exists
        if (TestActor)
        {
            SafeDestroyActor(TestActor);
            TestActor = nullptr;
        }

        BBComp = nullptr;
        BBSubsystem = nullptr;
        // Don't destroy the World as we are using the global editor world
    });
}

#endif  // WITH_DEV_AUTOMATION_TESTS
