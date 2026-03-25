// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DataTables/SovereignDataTypes.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSovereignDataTypes() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FTableRowBase();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
UPackage* Z_Construct_UPackage__Script_WispCPP7VR();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignSpeciesData_NoRegister();
WISPCPP7VR_API UScriptStruct* Z_Construct_UScriptStruct_FSovereignItemRow();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FSovereignItemRow *************************************************
struct Z_Construct_UScriptStruct_FSovereignItemRow_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FSovereignItemRow); }
	static inline consteval int16 GetStructAlignment() { return alignof(FSovereignItemRow); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * FItemDefaults\n * The \"Baseline\" Row Structure for your Master Item Table.\n */" },
#endif
		{ "ModuleRelativePath", "Public/DataTables/SovereignDataTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "FItemDefaults\nThe \"Baseline\" Row Structure for your Master Item Table." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemTag_MetaData[] = {
		{ "Category", "Sovereign|Core" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// The primary identifier for the item\n" },
#endif
		{ "ModuleRelativePath", "Public/DataTables/SovereignDataTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The primary identifier for the item" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AdditionalMetadata_MetaData[] = {
		{ "Category", "Sovereign|Core" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Flexibility for the new system: handles attributes the system doesn't know yet\n" },
#endif
		{ "ModuleRelativePath", "Public/DataTables/SovereignDataTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Flexibility for the new system: handles attributes the system doesn't know yet" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DisplayName_MetaData[] = {
		{ "Category", "Sovereign|Core" },
		{ "ModuleRelativePath", "Public/DataTables/SovereignDataTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Weight_MetaData[] = {
		{ "Category", "Sovereign|Physics" },
		{ "ModuleRelativePath", "Public/DataTables/SovereignDataTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpeciesVesselData_MetaData[] = {
		{ "Category", "Sovereign|Evolution" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** * Connection to Advanced Species Data.\n\x09 * Used for Erisis (the elf) or specific biological entities like Isla.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/DataTables/SovereignDataTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Connection to Advanced Species Data.\nUsed for Erisis (the elf) or specific biological entities like Isla." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsBiologicalOrigin_MetaData[] = {
		{ "Category", "Sovereign|Evolution" },
		{ "ModuleRelativePath", "Public/DataTables/SovereignDataTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FSovereignItemRow constinit property declarations *****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ItemTag;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AdditionalMetadata;
	static const UECodeGen_Private::FTextPropertyParams NewProp_DisplayName;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Weight;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_SpeciesVesselData;
	static void NewProp_bIsBiologicalOrigin_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsBiologicalOrigin;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FSovereignItemRow constinit property declarations *******************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSovereignItemRow>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FSovereignItemRow_Statics
static_assert(std::is_polymorphic<FSovereignItemRow>() == std::is_polymorphic<FTableRowBase>(), "USTRUCT FSovereignItemRow cannot be polymorphic unless super FTableRowBase is polymorphic");
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FSovereignItemRow;
class UScriptStruct* FSovereignItemRow::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FSovereignItemRow.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FSovereignItemRow.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSovereignItemRow, (UObject*)Z_Construct_UPackage__Script_WispCPP7VR(), TEXT("SovereignItemRow"));
	}
	return Z_Registration_Info_UScriptStruct_FSovereignItemRow.OuterSingleton;
	}

// ********** Begin ScriptStruct FSovereignItemRow Property Definitions ****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSovereignItemRow_Statics::NewProp_ItemTag = { "ItemTag", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSovereignItemRow, ItemTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemTag_MetaData), NewProp_ItemTag_MetaData) }; // 517357616
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSovereignItemRow_Statics::NewProp_AdditionalMetadata = { "AdditionalMetadata", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSovereignItemRow, AdditionalMetadata), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AdditionalMetadata_MetaData), NewProp_AdditionalMetadata_MetaData) }; // 3438578166
const UECodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FSovereignItemRow_Statics::NewProp_DisplayName = { "DisplayName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSovereignItemRow, DisplayName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DisplayName_MetaData), NewProp_DisplayName_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSovereignItemRow_Statics::NewProp_Weight = { "Weight", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSovereignItemRow, Weight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Weight_MetaData), NewProp_Weight_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FSovereignItemRow_Statics::NewProp_SpeciesVesselData = { "SpeciesVesselData", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSovereignItemRow, SpeciesVesselData), Z_Construct_UClass_USovereignSpeciesData_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpeciesVesselData_MetaData), NewProp_SpeciesVesselData_MetaData) };
void Z_Construct_UScriptStruct_FSovereignItemRow_Statics::NewProp_bIsBiologicalOrigin_SetBit(void* Obj)
{
	((FSovereignItemRow*)Obj)->bIsBiologicalOrigin = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSovereignItemRow_Statics::NewProp_bIsBiologicalOrigin = { "bIsBiologicalOrigin", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FSovereignItemRow), &Z_Construct_UScriptStruct_FSovereignItemRow_Statics::NewProp_bIsBiologicalOrigin_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsBiologicalOrigin_MetaData), NewProp_bIsBiologicalOrigin_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSovereignItemRow_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSovereignItemRow_Statics::NewProp_ItemTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSovereignItemRow_Statics::NewProp_AdditionalMetadata,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSovereignItemRow_Statics::NewProp_DisplayName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSovereignItemRow_Statics::NewProp_Weight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSovereignItemRow_Statics::NewProp_SpeciesVesselData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSovereignItemRow_Statics::NewProp_bIsBiologicalOrigin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSovereignItemRow_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FSovereignItemRow Property Definitions ******************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSovereignItemRow_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_WispCPP7VR,
	Z_Construct_UScriptStruct_FTableRowBase,
	&NewStructOps,
	"SovereignItemRow",
	Z_Construct_UScriptStruct_FSovereignItemRow_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSovereignItemRow_Statics::PropPointers),
	sizeof(FSovereignItemRow),
	alignof(FSovereignItemRow),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSovereignItemRow_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSovereignItemRow_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FSovereignItemRow()
{
	if (!Z_Registration_Info_UScriptStruct_FSovereignItemRow.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FSovereignItemRow.InnerSingleton, Z_Construct_UScriptStruct_FSovereignItemRow_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FSovereignItemRow.InnerSingleton);
}
// ********** End ScriptStruct FSovereignItemRow ***************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_DataTables_SovereignDataTypes_h__Script_WispCPP7VR_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FSovereignItemRow::StaticStruct, Z_Construct_UScriptStruct_FSovereignItemRow_Statics::NewStructOps, TEXT("SovereignItemRow"),&Z_Registration_Info_UScriptStruct_FSovereignItemRow, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSovereignItemRow), 3775578053U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_DataTables_SovereignDataTypes_h__Script_WispCPP7VR_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_DataTables_SovereignDataTypes_h__Script_WispCPP7VR_797764438{
	TEXT("/Script/WispCPP7VR"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_DataTables_SovereignDataTypes_h__Script_WispCPP7VR_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_DataTables_SovereignDataTypes_h__Script_WispCPP7VR_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
