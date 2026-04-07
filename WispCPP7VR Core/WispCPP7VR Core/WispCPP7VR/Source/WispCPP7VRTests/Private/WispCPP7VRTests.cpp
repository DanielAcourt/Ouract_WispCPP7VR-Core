// Copyright (c) 2013-2025 Daniel Acourt. All Rights Reserved. Confidential & Proprietary.

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"

/**
 * Test Module for WispCPP7VR Project
 * 
 * Handles automation tests for the SaveSystem and other core systems.
 * Follows the multi-agent development model defined in CONTRIBUTING.md
 */
class FWispCPP7VRTestsModule : public IModuleInterface
{
public:
    virtual void StartupModule() override
    {
        UE_LOG(LogTemp, Log, TEXT("WispCPP7VRTests Module: Startup"));
    }

    virtual void ShutdownModule() override
    {
        UE_LOG(LogTemp, Log, TEXT("WispCPP7VRTests Module: Shutdown"));
    }
};

IMPLEMENT_MODULE(FWispCPP7VRTestsModule, WispCPP7VRTests);