// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Entities/SovereignBaseEntity.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSovereignBaseEntity() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APawn();
ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
GAMEPLAYTAGS_API UClass* Z_Construct_UClass_UGameplayTagAssetInterface_NoRegister();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
UPackage* Z_Construct_UPackage__Script_WispCPP7VR();
WISPCPP7VR_API UClass* Z_Construct_UClass_ASovereignBaseEntity();
WISPCPP7VR_API UClass* Z_Construct_UClass_ASovereignBaseEntity_NoRegister();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignEntityInterface_NoRegister();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignSaveableEntityComponent_NoRegister();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignSpeciesData_NoRegister();
WISPCPP7VR_API UEnum* Z_Construct_UEnum_WispCPP7VR_EUpdateFrequency();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ASovereignBaseEntity Function AttemptMating ******************************
struct Z_Construct_UFunction_ASovereignBaseEntity_AttemptMating_Statics
{
	struct SovereignBaseEntity_eventAttemptMating_Parms
	{
		AActor* PotentialPartner;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Gameplay" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** * TRIGGER MATING: Checks compatibility and spawns a child if successful.\n\x09 * Can be called from VR Overlap events or Interaction buttons.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignBaseEntity.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "TRIGGER MATING: Checks compatibility and spawns a child if successful.\nCan be called from VR Overlap events or Interaction buttons." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function AttemptMating constinit property declarations *************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PotentialPartner;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AttemptMating constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AttemptMating Property Definitions ************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASovereignBaseEntity_AttemptMating_Statics::NewProp_PotentialPartner = { "PotentialPartner", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignBaseEntity_eventAttemptMating_Parms, PotentialPartner), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASovereignBaseEntity_AttemptMating_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASovereignBaseEntity_AttemptMating_Statics::NewProp_PotentialPartner,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ASovereignBaseEntity_AttemptMating_Statics::PropPointers) < 2048);
// ********** End Function AttemptMating Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASovereignBaseEntity_AttemptMating_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ASovereignBaseEntity, nullptr, "AttemptMating", 	Z_Construct_UFunction_ASovereignBaseEntity_AttemptMating_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_ASovereignBaseEntity_AttemptMating_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_ASovereignBaseEntity_AttemptMating_Statics::SovereignBaseEntity_eventAttemptMating_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASovereignBaseEntity_AttemptMating_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASovereignBaseEntity_AttemptMating_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ASovereignBaseEntity_AttemptMating_Statics::SovereignBaseEntity_eventAttemptMating_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ASovereignBaseEntity_AttemptMating()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASovereignBaseEntity_AttemptMating_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASovereignBaseEntity::execAttemptMating)
{
	P_GET_OBJECT(AActor,Z_Param_PotentialPartner);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AttemptMating(Z_Param_PotentialPartner);
	P_NATIVE_END;
}
// ********** End Class ASovereignBaseEntity Function AttemptMating ********************************

// ********** Begin Class ASovereignBaseEntity Function GetSaveDataComponent ***********************
struct Z_Construct_UFunction_ASovereignBaseEntity_GetSaveDataComponent_Statics
{
	struct SovereignBaseEntity_eventGetSaveDataComponent_Parms
	{
		USovereignSaveableEntityComponent* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Soul" },
		{ "ModuleRelativePath", "Public/Entities/SovereignBaseEntity.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetSaveDataComponent constinit property declarations ******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSaveDataComponent constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSaveDataComponent Property Definitions *****************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASovereignBaseEntity_GetSaveDataComponent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignBaseEntity_eventGetSaveDataComponent_Parms, ReturnValue), Z_Construct_UClass_USovereignSaveableEntityComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASovereignBaseEntity_GetSaveDataComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASovereignBaseEntity_GetSaveDataComponent_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ASovereignBaseEntity_GetSaveDataComponent_Statics::PropPointers) < 2048);
// ********** End Function GetSaveDataComponent Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASovereignBaseEntity_GetSaveDataComponent_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ASovereignBaseEntity, nullptr, "GetSaveDataComponent", 	Z_Construct_UFunction_ASovereignBaseEntity_GetSaveDataComponent_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_ASovereignBaseEntity_GetSaveDataComponent_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_ASovereignBaseEntity_GetSaveDataComponent_Statics::SovereignBaseEntity_eventGetSaveDataComponent_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASovereignBaseEntity_GetSaveDataComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASovereignBaseEntity_GetSaveDataComponent_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ASovereignBaseEntity_GetSaveDataComponent_Statics::SovereignBaseEntity_eventGetSaveDataComponent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ASovereignBaseEntity_GetSaveDataComponent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASovereignBaseEntity_GetSaveDataComponent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASovereignBaseEntity::execGetSaveDataComponent)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(USovereignSaveableEntityComponent**)Z_Param__Result=P_THIS->GetSaveDataComponent();
	P_NATIVE_END;
}
// ********** End Class ASovereignBaseEntity Function GetSaveDataComponent *************************

// ********** Begin Class ASovereignBaseEntity Function GetSovereignID *****************************
struct Z_Construct_UFunction_ASovereignBaseEntity_GetSovereignID_Statics
{
	struct SovereignBaseEntity_eventGetSovereignID_Parms
	{
		FGuid ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Entity" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Returns the unique Save System ID for this specific entity */" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignBaseEntity.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the unique Save System ID for this specific entity" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetSovereignID constinit property declarations ************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSovereignID constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSovereignID Property Definitions ***********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASovereignBaseEntity_GetSovereignID_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignBaseEntity_eventGetSovereignID_Parms, ReturnValue), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASovereignBaseEntity_GetSovereignID_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASovereignBaseEntity_GetSovereignID_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ASovereignBaseEntity_GetSovereignID_Statics::PropPointers) < 2048);
// ********** End Function GetSovereignID Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASovereignBaseEntity_GetSovereignID_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ASovereignBaseEntity, nullptr, "GetSovereignID", 	Z_Construct_UFunction_ASovereignBaseEntity_GetSovereignID_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_ASovereignBaseEntity_GetSovereignID_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_ASovereignBaseEntity_GetSovereignID_Statics::SovereignBaseEntity_eventGetSovereignID_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASovereignBaseEntity_GetSovereignID_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASovereignBaseEntity_GetSovereignID_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ASovereignBaseEntity_GetSovereignID_Statics::SovereignBaseEntity_eventGetSovereignID_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ASovereignBaseEntity_GetSovereignID()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASovereignBaseEntity_GetSovereignID_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASovereignBaseEntity::execGetSovereignID)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGuid*)Z_Param__Result=P_THIS->GetSovereignID();
	P_NATIVE_END;
}
// ********** End Class ASovereignBaseEntity Function GetSovereignID *******************************

// ********** Begin Class ASovereignBaseEntity Function IngestSovereignTag *************************
struct Z_Construct_UFunction_ASovereignBaseEntity_IngestSovereignTag_Statics
{
	struct SovereignBaseEntity_eventIngestSovereignTag_Parms
	{
		FString IncomingTagString;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Tags" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The Gameplay Tags that this Enity is checking against. */" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignBaseEntity.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The Gameplay Tags that this Enity is checking against." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function IngestSovereignTag constinit property declarations ********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_IncomingTagString;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IngestSovereignTag constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IngestSovereignTag Property Definitions *******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASovereignBaseEntity_IngestSovereignTag_Statics::NewProp_IncomingTagString = { "IncomingTagString", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignBaseEntity_eventIngestSovereignTag_Parms, IncomingTagString), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASovereignBaseEntity_IngestSovereignTag_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASovereignBaseEntity_IngestSovereignTag_Statics::NewProp_IncomingTagString,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ASovereignBaseEntity_IngestSovereignTag_Statics::PropPointers) < 2048);
// ********** End Function IngestSovereignTag Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASovereignBaseEntity_IngestSovereignTag_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ASovereignBaseEntity, nullptr, "IngestSovereignTag", 	Z_Construct_UFunction_ASovereignBaseEntity_IngestSovereignTag_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_ASovereignBaseEntity_IngestSovereignTag_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_ASovereignBaseEntity_IngestSovereignTag_Statics::SovereignBaseEntity_eventIngestSovereignTag_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASovereignBaseEntity_IngestSovereignTag_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASovereignBaseEntity_IngestSovereignTag_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ASovereignBaseEntity_IngestSovereignTag_Statics::SovereignBaseEntity_eventIngestSovereignTag_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ASovereignBaseEntity_IngestSovereignTag()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASovereignBaseEntity_IngestSovereignTag_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASovereignBaseEntity::execIngestSovereignTag)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_IncomingTagString);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->IngestSovereignTag(Z_Param_IncomingTagString);
	P_NATIVE_END;
}
// ********** End Class ASovereignBaseEntity Function IngestSovereignTag ***************************

// ********** Begin Class ASovereignBaseEntity Function InitializeFromSovereignData ****************
struct Z_Construct_UFunction_ASovereignBaseEntity_InitializeFromSovereignData_Statics
{
	struct SovereignBaseEntity_eventInitializeFromSovereignData_Parms
	{
		USovereignSpeciesData* InData;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Identity" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Logic to update the entity based on new Species Data */" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignBaseEntity.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Logic to update the entity based on new Species Data" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function InitializeFromSovereignData constinit property declarations ***********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function InitializeFromSovereignData constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function InitializeFromSovereignData Property Definitions **********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASovereignBaseEntity_InitializeFromSovereignData_Statics::NewProp_InData = { "InData", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignBaseEntity_eventInitializeFromSovereignData_Parms, InData), Z_Construct_UClass_USovereignSpeciesData_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASovereignBaseEntity_InitializeFromSovereignData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASovereignBaseEntity_InitializeFromSovereignData_Statics::NewProp_InData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ASovereignBaseEntity_InitializeFromSovereignData_Statics::PropPointers) < 2048);
// ********** End Function InitializeFromSovereignData Property Definitions ************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASovereignBaseEntity_InitializeFromSovereignData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ASovereignBaseEntity, nullptr, "InitializeFromSovereignData", 	Z_Construct_UFunction_ASovereignBaseEntity_InitializeFromSovereignData_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_ASovereignBaseEntity_InitializeFromSovereignData_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_ASovereignBaseEntity_InitializeFromSovereignData_Statics::SovereignBaseEntity_eventInitializeFromSovereignData_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASovereignBaseEntity_InitializeFromSovereignData_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASovereignBaseEntity_InitializeFromSovereignData_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ASovereignBaseEntity_InitializeFromSovereignData_Statics::SovereignBaseEntity_eventInitializeFromSovereignData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ASovereignBaseEntity_InitializeFromSovereignData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASovereignBaseEntity_InitializeFromSovereignData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASovereignBaseEntity::execInitializeFromSovereignData)
{
	P_GET_OBJECT(USovereignSpeciesData,Z_Param_InData);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializeFromSovereignData(Z_Param_InData);
	P_NATIVE_END;
}
// ********** End Class ASovereignBaseEntity Function InitializeFromSovereignData ******************

// ********** Begin Class ASovereignBaseEntity Function IsReadyForMating ***************************
struct Z_Construct_UFunction_ASovereignBaseEntity_IsReadyForMating_Statics
{
	struct SovereignBaseEntity_eventIsReadyForMating_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Gameplay" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional: Check if this entity is currently able to breed */" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignBaseEntity.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional: Check if this entity is currently able to breed" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function IsReadyForMating constinit property declarations **********************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsReadyForMating constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsReadyForMating Property Definitions *********************************
void Z_Construct_UFunction_ASovereignBaseEntity_IsReadyForMating_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((SovereignBaseEntity_eventIsReadyForMating_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASovereignBaseEntity_IsReadyForMating_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SovereignBaseEntity_eventIsReadyForMating_Parms), &Z_Construct_UFunction_ASovereignBaseEntity_IsReadyForMating_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASovereignBaseEntity_IsReadyForMating_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASovereignBaseEntity_IsReadyForMating_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ASovereignBaseEntity_IsReadyForMating_Statics::PropPointers) < 2048);
// ********** End Function IsReadyForMating Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASovereignBaseEntity_IsReadyForMating_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ASovereignBaseEntity, nullptr, "IsReadyForMating", 	Z_Construct_UFunction_ASovereignBaseEntity_IsReadyForMating_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_ASovereignBaseEntity_IsReadyForMating_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_ASovereignBaseEntity_IsReadyForMating_Statics::SovereignBaseEntity_eventIsReadyForMating_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASovereignBaseEntity_IsReadyForMating_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASovereignBaseEntity_IsReadyForMating_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ASovereignBaseEntity_IsReadyForMating_Statics::SovereignBaseEntity_eventIsReadyForMating_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ASovereignBaseEntity_IsReadyForMating()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASovereignBaseEntity_IsReadyForMating_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASovereignBaseEntity::execIsReadyForMating)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsReadyForMating();
	P_NATIVE_END;
}
// ********** End Class ASovereignBaseEntity Function IsReadyForMating *****************************

// ********** Begin Class ASovereignBaseEntity Function RefreshVisuals *****************************
struct Z_Construct_UFunction_ASovereignBaseEntity_RefreshVisuals_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Visuals" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Swaps the Mesh based on the current Growth Stage index */" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignBaseEntity.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Swaps the Mesh based on the current Growth Stage index" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshVisuals constinit property declarations ************************
// ********** End Function RefreshVisuals constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASovereignBaseEntity_RefreshVisuals_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ASovereignBaseEntity, nullptr, "RefreshVisuals", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASovereignBaseEntity_RefreshVisuals_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASovereignBaseEntity_RefreshVisuals_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_ASovereignBaseEntity_RefreshVisuals()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASovereignBaseEntity_RefreshVisuals_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASovereignBaseEntity::execRefreshVisuals)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshVisuals();
	P_NATIVE_END;
}
// ********** End Class ASovereignBaseEntity Function RefreshVisuals *******************************

// ********** Begin Class ASovereignBaseEntity *****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_ASovereignBaseEntity;
UClass* ASovereignBaseEntity::GetPrivateStaticClass()
{
	using TClass = ASovereignBaseEntity;
	if (!Z_Registration_Info_UClass_ASovereignBaseEntity.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SovereignBaseEntity"),
			Z_Registration_Info_UClass_ASovereignBaseEntity.InnerSingleton,
			StaticRegisterNativesASovereignBaseEntity,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_ASovereignBaseEntity.InnerSingleton;
}
UClass* Z_Construct_UClass_ASovereignBaseEntity_NoRegister()
{
	return ASovereignBaseEntity::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ASovereignBaseEntity_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//The problem with this current approach is i start by inheriting from ACharacter,\n// what we reaslly need is a base which is AActor and APawn and has this interaction.\n// But not the mating and more Advance options\n" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Entities/SovereignBaseEntity.h" },
		{ "ModuleRelativePath", "Public/Entities/SovereignBaseEntity.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The problem with this current approach is i start by inheriting from ACharacter,\n what we reaslly need is a base which is AActor and APawn and has this interaction.\n But not the mating and more Advance options" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IdentitySignature_MetaData[] = {
		{ "Category", "Sovereign|Identity" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The Unique Identity Signature for this class. */" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignBaseEntity.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The Unique Identity Signature for this class." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GameplayTags_MetaData[] = {
		{ "Category", "Sovereign|Identity" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The Gameplay Tags for this entity. */" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignBaseEntity.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The Gameplay Tags for this entity." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCanBePossessed_MetaData[] = {
		{ "Category", "Sovereign|Possession" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Can this entity be possessed by a Sovereign Spirit? */" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignBaseEntity.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Can this entity be possessed by a Sovereign Spirit?" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EntityMesh_MetaData[] = {
		{ "Category", "Sovereign|Visuals" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The physical body of the entity (The Oak Tree, the Bee, etc.) */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Entities/SovereignBaseEntity.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The physical body of the entity (The Oak Tree, the Bee, etc.)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SaveDataComponent_MetaData[] = {
		{ "Category", "Sovereign|SaveSystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The Soul of the Actor: Contains the GUID and Metadata tags (Isla's unknown tags) */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Entities/SovereignBaseEntity.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The Soul of the Actor: Contains the GUID and Metadata tags (Isla's unknown tags)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GrowthMeshes_MetaData[] = {
		{ "Category", "Sovereign|Visuals" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Array of 8 meshes representing the growth stages (0-7) */" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignBaseEntity.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Array of 8 meshes representing the growth stages (0-7)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TrustSignature_MetaData[] = {
		{ "Category", "Sovereign|Security" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Add the TrustSignature back here if you want to solve that C2039 error properly\n" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignBaseEntity.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Add the TrustSignature back here if you want to solve that C2039 error properly" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VisualScale_MetaData[] = {
		{ "Category", "Sovereign|Growth" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** 1.0 is default size. 2.0 is double size. Allows for growth without new meshes. */" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignBaseEntity.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "1.0 is default size. 2.0 is double size. Allows for growth without new meshes." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BaseConstitution_MetaData[] = {
		{ "Category", "Sovereign|Growth" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Base health/stamina multiplier for this stage */" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignBaseEntity.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Base health/stamina multiplier for this stage" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpeciesData_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Sovereign|Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The \"Advanced\" data asset defining growth stages, health, and species attributes */// Note: class keyword here handles the forward declaration inline\n" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignBaseEntity.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The \"Advanced\" data asset defining growth stages, health, and species attributes // Note: class keyword here handles the forward declaration inline" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentGrowthStage_MetaData[] = {
		{ "Category", "Sovereign|Growth" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Which of the 8 growth stages are we currently in? (0 to 7) */" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignBaseEntity.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Which of the 8 growth stages are we currently in? (0 to 7)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UpdateFrequency_MetaData[] = {
		{ "Category", "Sovereign|Performance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** How often this entity processes logic */" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignBaseEntity.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "How often this entity processes logic" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUseManualBirthDate_MetaData[] = {
		{ "Category", "Sovereign|Identity" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** If true, the Soul uses the ManualBirthDate instead of the current time on first spawn */" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignBaseEntity.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If true, the Soul uses the ManualBirthDate instead of the current time on first spawn" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ManualBirthDate_MetaData[] = {
		{ "Category", "Sovereign|Identity" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Format: \"2017.03.23-16.00.00\" (Year.Month.Day-Hour.Minute.Second) */" },
#endif
		{ "EditCondition", "bUseManualBirthDate" },
		{ "ModuleRelativePath", "Public/Entities/SovereignBaseEntity.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Format: \"2017.03.23-16.00.00\" (Year.Month.Day-Hour.Minute.Second)" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class ASovereignBaseEntity constinit property declarations *********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_IdentitySignature;
	static const UECodeGen_Private::FStructPropertyParams NewProp_GameplayTags;
	static void NewProp_bCanBePossessed_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCanBePossessed;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EntityMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SaveDataComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_GrowthMeshes_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_GrowthMeshes;
	static const UECodeGen_Private::FIntPropertyParams NewProp_TrustSignature;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_VisualScale;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BaseConstitution;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpeciesData;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentGrowthStage;
	static const UECodeGen_Private::FBytePropertyParams NewProp_UpdateFrequency_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_UpdateFrequency;
	static void NewProp_bUseManualBirthDate_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseManualBirthDate;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ManualBirthDate;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class ASovereignBaseEntity constinit property declarations ***********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("AttemptMating"), .Pointer = &ASovereignBaseEntity::execAttemptMating },
		{ .NameUTF8 = UTF8TEXT("GetSaveDataComponent"), .Pointer = &ASovereignBaseEntity::execGetSaveDataComponent },
		{ .NameUTF8 = UTF8TEXT("GetSovereignID"), .Pointer = &ASovereignBaseEntity::execGetSovereignID },
		{ .NameUTF8 = UTF8TEXT("IngestSovereignTag"), .Pointer = &ASovereignBaseEntity::execIngestSovereignTag },
		{ .NameUTF8 = UTF8TEXT("InitializeFromSovereignData"), .Pointer = &ASovereignBaseEntity::execInitializeFromSovereignData },
		{ .NameUTF8 = UTF8TEXT("IsReadyForMating"), .Pointer = &ASovereignBaseEntity::execIsReadyForMating },
		{ .NameUTF8 = UTF8TEXT("RefreshVisuals"), .Pointer = &ASovereignBaseEntity::execRefreshVisuals },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ASovereignBaseEntity_AttemptMating, "AttemptMating" }, // 948027991
		{ &Z_Construct_UFunction_ASovereignBaseEntity_GetSaveDataComponent, "GetSaveDataComponent" }, // 3638764824
		{ &Z_Construct_UFunction_ASovereignBaseEntity_GetSovereignID, "GetSovereignID" }, // 1671418424
		{ &Z_Construct_UFunction_ASovereignBaseEntity_IngestSovereignTag, "IngestSovereignTag" }, // 2575035036
		{ &Z_Construct_UFunction_ASovereignBaseEntity_InitializeFromSovereignData, "InitializeFromSovereignData" }, // 2585064635
		{ &Z_Construct_UFunction_ASovereignBaseEntity_IsReadyForMating, "IsReadyForMating" }, // 3724174879
		{ &Z_Construct_UFunction_ASovereignBaseEntity_RefreshVisuals, "RefreshVisuals" }, // 1855883511
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASovereignBaseEntity>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_ASovereignBaseEntity_Statics

// ********** Begin Class ASovereignBaseEntity Property Definitions ********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ASovereignBaseEntity_Statics::NewProp_IdentitySignature = { "IdentitySignature", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASovereignBaseEntity, IdentitySignature), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IdentitySignature_MetaData), NewProp_IdentitySignature_MetaData) }; // 517357616
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ASovereignBaseEntity_Statics::NewProp_GameplayTags = { "GameplayTags", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASovereignBaseEntity, GameplayTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GameplayTags_MetaData), NewProp_GameplayTags_MetaData) }; // 3438578166
void Z_Construct_UClass_ASovereignBaseEntity_Statics::NewProp_bCanBePossessed_SetBit(void* Obj)
{
	((ASovereignBaseEntity*)Obj)->bCanBePossessed = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASovereignBaseEntity_Statics::NewProp_bCanBePossessed = { "bCanBePossessed", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ASovereignBaseEntity), &Z_Construct_UClass_ASovereignBaseEntity_Statics::NewProp_bCanBePossessed_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCanBePossessed_MetaData), NewProp_bCanBePossessed_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASovereignBaseEntity_Statics::NewProp_EntityMesh = { "EntityMesh", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASovereignBaseEntity, EntityMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EntityMesh_MetaData), NewProp_EntityMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASovereignBaseEntity_Statics::NewProp_SaveDataComponent = { "SaveDataComponent", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASovereignBaseEntity, SaveDataComponent), Z_Construct_UClass_USovereignSaveableEntityComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SaveDataComponent_MetaData), NewProp_SaveDataComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASovereignBaseEntity_Statics::NewProp_GrowthMeshes_Inner = { "GrowthMeshes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ASovereignBaseEntity_Statics::NewProp_GrowthMeshes = { "GrowthMeshes", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASovereignBaseEntity, GrowthMeshes), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GrowthMeshes_MetaData), NewProp_GrowthMeshes_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ASovereignBaseEntity_Statics::NewProp_TrustSignature = { "TrustSignature", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASovereignBaseEntity, TrustSignature), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TrustSignature_MetaData), NewProp_TrustSignature_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASovereignBaseEntity_Statics::NewProp_VisualScale = { "VisualScale", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASovereignBaseEntity, VisualScale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VisualScale_MetaData), NewProp_VisualScale_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASovereignBaseEntity_Statics::NewProp_BaseConstitution = { "BaseConstitution", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASovereignBaseEntity, BaseConstitution), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BaseConstitution_MetaData), NewProp_BaseConstitution_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASovereignBaseEntity_Statics::NewProp_SpeciesData = { "SpeciesData", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASovereignBaseEntity, SpeciesData), Z_Construct_UClass_USovereignSpeciesData_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpeciesData_MetaData), NewProp_SpeciesData_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ASovereignBaseEntity_Statics::NewProp_CurrentGrowthStage = { "CurrentGrowthStage", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASovereignBaseEntity, CurrentGrowthStage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentGrowthStage_MetaData), NewProp_CurrentGrowthStage_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_ASovereignBaseEntity_Statics::NewProp_UpdateFrequency_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_ASovereignBaseEntity_Statics::NewProp_UpdateFrequency = { "UpdateFrequency", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASovereignBaseEntity, UpdateFrequency), Z_Construct_UEnum_WispCPP7VR_EUpdateFrequency, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UpdateFrequency_MetaData), NewProp_UpdateFrequency_MetaData) }; // 2306381773
void Z_Construct_UClass_ASovereignBaseEntity_Statics::NewProp_bUseManualBirthDate_SetBit(void* Obj)
{
	((ASovereignBaseEntity*)Obj)->bUseManualBirthDate = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASovereignBaseEntity_Statics::NewProp_bUseManualBirthDate = { "bUseManualBirthDate", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ASovereignBaseEntity), &Z_Construct_UClass_ASovereignBaseEntity_Statics::NewProp_bUseManualBirthDate_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUseManualBirthDate_MetaData), NewProp_bUseManualBirthDate_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_ASovereignBaseEntity_Statics::NewProp_ManualBirthDate = { "ManualBirthDate", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASovereignBaseEntity, ManualBirthDate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ManualBirthDate_MetaData), NewProp_ManualBirthDate_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASovereignBaseEntity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASovereignBaseEntity_Statics::NewProp_IdentitySignature,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASovereignBaseEntity_Statics::NewProp_GameplayTags,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASovereignBaseEntity_Statics::NewProp_bCanBePossessed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASovereignBaseEntity_Statics::NewProp_EntityMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASovereignBaseEntity_Statics::NewProp_SaveDataComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASovereignBaseEntity_Statics::NewProp_GrowthMeshes_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASovereignBaseEntity_Statics::NewProp_GrowthMeshes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASovereignBaseEntity_Statics::NewProp_TrustSignature,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASovereignBaseEntity_Statics::NewProp_VisualScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASovereignBaseEntity_Statics::NewProp_BaseConstitution,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASovereignBaseEntity_Statics::NewProp_SpeciesData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASovereignBaseEntity_Statics::NewProp_CurrentGrowthStage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASovereignBaseEntity_Statics::NewProp_UpdateFrequency_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASovereignBaseEntity_Statics::NewProp_UpdateFrequency,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASovereignBaseEntity_Statics::NewProp_bUseManualBirthDate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASovereignBaseEntity_Statics::NewProp_ManualBirthDate,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASovereignBaseEntity_Statics::PropPointers) < 2048);
// ********** End Class ASovereignBaseEntity Property Definitions **********************************
UObject* (*const Z_Construct_UClass_ASovereignBaseEntity_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APawn,
	(UObject* (*)())Z_Construct_UPackage__Script_WispCPP7VR,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASovereignBaseEntity_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_ASovereignBaseEntity_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UGameplayTagAssetInterface_NoRegister, (int32)VTABLE_OFFSET(ASovereignBaseEntity, IGameplayTagAssetInterface), false },  // 4215201248
	{ Z_Construct_UClass_USovereignEntityInterface_NoRegister, (int32)VTABLE_OFFSET(ASovereignBaseEntity, ISovereignEntityInterface), false },  // 3695919034
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_ASovereignBaseEntity_Statics::ClassParams = {
	&ASovereignBaseEntity::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ASovereignBaseEntity_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ASovereignBaseEntity_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASovereignBaseEntity_Statics::Class_MetaDataParams), Z_Construct_UClass_ASovereignBaseEntity_Statics::Class_MetaDataParams)
};
void ASovereignBaseEntity::StaticRegisterNativesASovereignBaseEntity()
{
	UClass* Class = ASovereignBaseEntity::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_ASovereignBaseEntity_Statics::Funcs));
}
UClass* Z_Construct_UClass_ASovereignBaseEntity()
{
	if (!Z_Registration_Info_UClass_ASovereignBaseEntity.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASovereignBaseEntity.OuterSingleton, Z_Construct_UClass_ASovereignBaseEntity_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ASovereignBaseEntity.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ASovereignBaseEntity);
ASovereignBaseEntity::~ASovereignBaseEntity() {}
// ********** End Class ASovereignBaseEntity *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Entities_SovereignBaseEntity_h__Script_WispCPP7VR_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ASovereignBaseEntity, ASovereignBaseEntity::StaticClass, TEXT("ASovereignBaseEntity"), &Z_Registration_Info_UClass_ASovereignBaseEntity, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASovereignBaseEntity), 1784492022U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Entities_SovereignBaseEntity_h__Script_WispCPP7VR_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Entities_SovereignBaseEntity_h__Script_WispCPP7VR_2255897859{
	TEXT("/Script/WispCPP7VR"),
	Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Entities_SovereignBaseEntity_h__Script_WispCPP7VR_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Entities_SovereignBaseEntity_h__Script_WispCPP7VR_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
