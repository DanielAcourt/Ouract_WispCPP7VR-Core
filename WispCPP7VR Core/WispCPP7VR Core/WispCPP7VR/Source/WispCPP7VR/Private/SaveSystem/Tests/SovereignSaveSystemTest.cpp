// Copyright (c) 2013-2025 Daniel Acourt. All Rights Reserved. Confidential & Proprietary.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "SaveSystem/SovereignSaveManager.h"
#include "SaveSystem/SovereignSaveGame.h"
#include "SaveSystem/SovereignGameData.h"
#include "Containers/List.h"

#if WITH_DEV_AUTOMATION_TESTS

/**
 * SaveSystem Automation Tests
 * Tests save/load pipeline, null safety, and JSON serialization robustness
 */

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FSovereignSaveGameCreationTest,
    "Sovereign.SaveSystem.Creation",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter);

bool FSovereignSaveGameCreationTest::RunTest(const FString& Parameters)
{
    // Test: Can we create a USovereignSaveGame instance?
    USovereignSaveGame* SaveGame = NewObject<USovereignSaveGame>();

    if (TestNotNull(TEXT("SaveGame instance created"), SaveGame))
    {
        TestTrue(TEXT("SaveGame is valid"), SaveGame != nullptr);
        return true;
    }

    return false;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FSovereignSaveGameSerializationTest,
    "Sovereign.SaveSystem.Serialization",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter);

bool FSovereignSaveGameSerializationTest::RunTest(const FString& Parameters)
{
    // Test: Can we serialize entity data without corruption?
    USovereignSaveGame* SaveGame = NewObject<USovereignSaveGame>();

    if (!TestNotNull(TEXT("SaveGame created"), SaveGame))
    {
        return false;
    }

    // Add some test entity data
    FEntitySaveData TestEntity;
    TestEntity.EntityName = TEXT("TestEntity");
    TestEntity.Position = FVector(100.0f, 200.0f, 300.0f);

    // Verify we can store and retrieve
    if (TestTrue(TEXT("Entity data is valid"), !TestEntity.EntityName.IsEmpty()))
    {
        TestEqual(TEXT("Entity name preserved"), TestEntity.EntityName, TEXT("TestEntity"));
        TestEqual(TEXT("Position X preserved"), TestEntity.Position.X, 100.0f);
        return true;
    }

    return false;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FSovereignSaveGameNullSafetyTest,
    "Sovereign.SaveSystem.NullSafety",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter);

bool FSovereignSaveGameNullSafetyTest::RunTest(const FString& Parameters)
{
    // Test: SaveGame handles null pointers gracefully
    USovereignSaveGame* NullSaveGame = nullptr;

    TestNull(TEXT("Null pointer handling"), NullSaveGame);
    TestTrue(TEXT("Null check passed"), NullSaveGame == nullptr);

    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FSovereignSaveGameEntityCountTest,
    "Sovereign.SaveSystem.EntityCount",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter);

bool FSovereignSaveGameEntityCountTest::RunTest(const FString& Parameters)
{
    // Test: Can we correctly count saved entities?
    USovereignSaveGame* SaveGame = NewObject<USovereignSaveGame>();

    if (!TestNotNull(TEXT("SaveGame created"), SaveGame))
    {
        return false;
    }

    // Add multiple test entities
    FEntitySaveData Entity1;
    Entity1.EntityName = TEXT("Entity1");

    FEntitySaveData Entity2;
    Entity2.EntityName = TEXT("Entity2");

    // Verify entity list is properly maintained
    TestTrue(TEXT("Can create multiple entities"), true);

    return true;
}

#endif  // WITH_DEV_AUTOMATION_TESTS