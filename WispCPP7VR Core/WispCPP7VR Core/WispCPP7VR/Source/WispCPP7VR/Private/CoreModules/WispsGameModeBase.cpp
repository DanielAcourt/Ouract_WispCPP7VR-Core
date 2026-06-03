// Copyright (c) 2013-2026 Daniel Acourt. Version 36.4.4. Licensed under GPLv3 (See LICENSE). Last Updated: 2026-05-27

#include "CoreModules/WispsGameModeBase.h"
#include "Entities/SovereignPlayerWisp.h"
#include "UObject/ConstructorHelpers.h"
#include "DataTables/SovereignSpeciesData.h" 
#include "DataTables/SovereignDataTypes.h" 
#include "Engine/DataTable.h"

AWispsGameModeBase::AWispsGameModeBase()
{
    // Restored the _C suffix to ensure the class is correctly resolved
    static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprint/BP_PlayerWisp.BP_PlayerWisp_C"));

    if (PlayerPawnBPClass.Class != nullptr)
    {
        DefaultPawnClass = PlayerPawnBPClass.Class;
    }
    else
    {
        DefaultPawnClass = ASovereignPlayerWisp::StaticClass();
        UE_LOG(LogTemp, Error, TEXT("GameMode: Could not find BP_PlayerWisp. Falling back to C++ class."));
    }

    static ConstructorHelpers::FObjectFinder<UDataTable> TableObj(TEXT("/Game/Data/DT_SovereignItems"));
    if (TableObj.Succeeded())
    {
        ItemDataTable = TableObj.Object;
    }
}

USovereignSpeciesData* AWispsGameModeBase::GetSpeciesDataByTag(FGameplayTag SpeciesTag)
{
    if (!ItemDataTable)
    {
        UE_LOG(LogTemp, Error, TEXT("GameMode: ItemDataTable is NOT assigned!"));
        return nullptr;
    }

    static const FString ContextString(TEXT("Species Lookup"));
    TArray<FSovereignItemRow*> AllRows;
    ItemDataTable->GetAllRows<FSovereignItemRow>(ContextString, AllRows);

    for (FSovereignItemRow* Row : AllRows)
    {
        if (Row && Row->ItemTag.MatchesTagExact(SpeciesTag))
        {
            if (Row->bIsBiologicalOrigin && !Row->SpeciesVesselData.IsNull())
            {
                return Row->SpeciesVesselData.LoadSynchronous();
            }
        }
    }

    return nullptr;
}
