// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DataTables/SovereignSpeciesData.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSovereignSpeciesData() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UPrimaryDataAsset();
ENGINE_API UClass* Z_Construct_UClass_UStreamableRenderAsset_NoRegister();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
UPackage* Z_Construct_UPackage__Script_WispCPP7VR();
WISPCPP7VR_API UClass* Z_Construct_UClass_ASovereignBaseEntity_NoRegister();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignSpeciesData();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignSpeciesData_NoRegister();
WISPCPP7VR_API UScriptStruct* Z_Construct_UScriptStruct_FSovereignGrowthStage();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FSovereignGrowthStage *********************************************
struct Z_Construct_UScriptStruct_FSovereignGrowthStage_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FSovereignGrowthStage); }
	static inline consteval int16 GetStructAlignment() { return alignof(FSovereignGrowthStage); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** * The Unique Tag for this species (e.g., Species.Plant.Oak).\n     * This is what the Save System looks for to know which asset to load.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/DataTables/SovereignSpeciesData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The Unique Tag for this species (e.g., Species.Plant.Oak).\nThis is what the Save System looks for to know which asset to load." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StageMesh_MetaData[] = {
		{ "Category", "Sovereign|Growth" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The 3D model for this specific stage (Static or Skeletal) */" },
#endif
		{ "ModuleRelativePath", "Public/DataTables/SovereignSpeciesData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The 3D model for this specific stage (Static or Skeletal)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VisualScale_MetaData[] = {
		{ "Category", "Sovereign|Growth" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** NEW: Scaling factor for this stage (1.0 = Default) */" },
#endif
		{ "ModuleRelativePath", "Public/DataTables/SovereignSpeciesData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "NEW: Scaling factor for this stage (1.0 = Default)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BaseStrength_MetaData[] = {
		{ "Category", "Attributes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// PHYSICAL ATTRIBUTES (The 'Advanced' data)\n" },
#endif
		{ "ModuleRelativePath", "Public/DataTables/SovereignSpeciesData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "PHYSICAL ATTRIBUTES (The 'Advanced' data)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BaseConstitution_MetaData[] = {
		{ "Category", "Attributes" },
		{ "ModuleRelativePath", "Public/DataTables/SovereignSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BaseAgility_MetaData[] = {
		{ "Category", "Attributes" },
		{ "ModuleRelativePath", "Public/DataTables/SovereignSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MetabolicRate_MetaData[] = {
		{ "Category", "Attributes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// How much food/water/energy this stage consumes\n" },
#endif
		{ "ModuleRelativePath", "Public/DataTables/SovereignSpeciesData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "How much food/water/energy this stage consumes" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FSovereignGrowthStage constinit property declarations *************
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_StageMesh;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_VisualScale;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BaseStrength;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BaseConstitution;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BaseAgility;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MetabolicRate;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FSovereignGrowthStage constinit property declarations ***************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSovereignGrowthStage>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FSovereignGrowthStage_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FSovereignGrowthStage;
class UScriptStruct* FSovereignGrowthStage::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FSovereignGrowthStage.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FSovereignGrowthStage.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSovereignGrowthStage, (UObject*)Z_Construct_UPackage__Script_WispCPP7VR(), TEXT("SovereignGrowthStage"));
	}
	return Z_Registration_Info_UScriptStruct_FSovereignGrowthStage.OuterSingleton;
	}

// ********** Begin ScriptStruct FSovereignGrowthStage Property Definitions ************************
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FSovereignGrowthStage_Statics::NewProp_StageMesh = { "StageMesh", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSovereignGrowthStage, StageMesh), Z_Construct_UClass_UStreamableRenderAsset_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StageMesh_MetaData), NewProp_StageMesh_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSovereignGrowthStage_Statics::NewProp_VisualScale = { "VisualScale", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSovereignGrowthStage, VisualScale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VisualScale_MetaData), NewProp_VisualScale_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSovereignGrowthStage_Statics::NewProp_BaseStrength = { "BaseStrength", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSovereignGrowthStage, BaseStrength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BaseStrength_MetaData), NewProp_BaseStrength_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSovereignGrowthStage_Statics::NewProp_BaseConstitution = { "BaseConstitution", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSovereignGrowthStage, BaseConstitution), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BaseConstitution_MetaData), NewProp_BaseConstitution_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSovereignGrowthStage_Statics::NewProp_BaseAgility = { "BaseAgility", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSovereignGrowthStage, BaseAgility), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BaseAgility_MetaData), NewProp_BaseAgility_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSovereignGrowthStage_Statics::NewProp_MetabolicRate = { "MetabolicRate", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSovereignGrowthStage, MetabolicRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MetabolicRate_MetaData), NewProp_MetabolicRate_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSovereignGrowthStage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSovereignGrowthStage_Statics::NewProp_StageMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSovereignGrowthStage_Statics::NewProp_VisualScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSovereignGrowthStage_Statics::NewProp_BaseStrength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSovereignGrowthStage_Statics::NewProp_BaseConstitution,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSovereignGrowthStage_Statics::NewProp_BaseAgility,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSovereignGrowthStage_Statics::NewProp_MetabolicRate,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSovereignGrowthStage_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FSovereignGrowthStage Property Definitions **************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSovereignGrowthStage_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_WispCPP7VR,
	nullptr,
	&NewStructOps,
	"SovereignGrowthStage",
	Z_Construct_UScriptStruct_FSovereignGrowthStage_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSovereignGrowthStage_Statics::PropPointers),
	sizeof(FSovereignGrowthStage),
	alignof(FSovereignGrowthStage),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSovereignGrowthStage_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSovereignGrowthStage_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FSovereignGrowthStage()
{
	if (!Z_Registration_Info_UScriptStruct_FSovereignGrowthStage.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FSovereignGrowthStage.InnerSingleton, Z_Construct_UScriptStruct_FSovereignGrowthStage_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FSovereignGrowthStage.InnerSingleton);
}
// ********** End ScriptStruct FSovereignGrowthStage ***********************************************

// ********** Begin Class USovereignSpeciesData ****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_USovereignSpeciesData;
UClass* USovereignSpeciesData::GetPrivateStaticClass()
{
	using TClass = USovereignSpeciesData;
	if (!Z_Registration_Info_UClass_USovereignSpeciesData.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SovereignSpeciesData"),
			Z_Registration_Info_UClass_USovereignSpeciesData.InnerSingleton,
			StaticRegisterNativesUSovereignSpeciesData,
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
	return Z_Registration_Info_UClass_USovereignSpeciesData.InnerSingleton;
}
UClass* Z_Construct_UClass_USovereignSpeciesData_NoRegister()
{
	return USovereignSpeciesData::GetPrivateStaticClass();
}
struct Z_Construct_UClass_USovereignSpeciesData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** * USovereignSpeciesData\n * The 'Template' for an entire species.\n */" },
#endif
		{ "IncludePath", "DataTables/SovereignSpeciesData.h" },
		{ "ModuleRelativePath", "Public/DataTables/SovereignSpeciesData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "USovereignSpeciesData\nThe 'Template' for an entire species." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpeciesName_MetaData[] = {
		{ "Category", "Identity" },
		{ "ModuleRelativePath", "Public/DataTables/SovereignSpeciesData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpeciesTag_MetaData[] = {
		{ "Category", "Identity" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** * The Unique Tag for this species (e.g., Species.Plant.Oak).\n     * This is the bridge to Isla's Save System [2025-12-20].\n     */" },
#endif
		{ "ModuleRelativePath", "Public/DataTables/SovereignSpeciesData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The Unique Tag for this species (e.g., Species.Plant.Oak).\nThis is the bridge to Isla's Save System [2025-12-20]." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GrowthStages_MetaData[] = {
		{ "Category", "Evolution" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The 8 growth stages (or however many you need) */" },
#endif
		{ "ModuleRelativePath", "Public/DataTables/SovereignSpeciesData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The 8 growth stages (or however many you need)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxGrowthStages_MetaData[] = {
		{ "Category", "Evolution" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The 8 growth stages (or however many you need) */" },
#endif
		{ "ModuleRelativePath", "Public/DataTables/SovereignSpeciesData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The 8 growth stages (or however many you need)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IdentitySignature_MetaData[] = {
		{ "Category", "Identity" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The Unique Identity Signature for this species. */" },
#endif
		{ "ModuleRelativePath", "Public/DataTables/SovereignSpeciesData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The Unique Identity Signature for this species." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCanFly_MetaData[] = {
		{ "Category", "Movement" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Default movement mode (Flying for Bees, Stationary for Oak) */" },
#endif
		{ "ModuleRelativePath", "Public/DataTables/SovereignSpeciesData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Default movement mode (Flying for Bees, Stationary for Oak)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCanMove_MetaData[] = {
		{ "Category", "Movement" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Default movement mode (Flying for Bees, Stationary for Oak) */" },
#endif
		{ "ModuleRelativePath", "Public/DataTables/SovereignSpeciesData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Default movement mode (Flying for Bees, Stationary for Oak)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsBiological_MetaData[] = {
		{ "Category", "Movement" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Default movement mode (Flying for Bees, Stationary for Oak) */" },
#endif
		{ "ModuleRelativePath", "Public/DataTables/SovereignSpeciesData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Default movement mode (Flying for Bees, Stationary for Oak)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActorClass_MetaData[] = {
		{ "Category", "Spawning" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The Actor Class to spawn for this species. */" },
#endif
		{ "ModuleRelativePath", "Public/DataTables/SovereignSpeciesData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The Actor Class to spawn for this species." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class USovereignSpeciesData constinit property declarations ********************
	static const UECodeGen_Private::FTextPropertyParams NewProp_SpeciesName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpeciesTag;
	static const UECodeGen_Private::FStructPropertyParams NewProp_GrowthStages_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_GrowthStages;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MaxGrowthStages_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_MaxGrowthStages;
	static const UECodeGen_Private::FStructPropertyParams NewProp_IdentitySignature;
	static void NewProp_bCanFly_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCanFly;
	static void NewProp_bCanMove_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCanMove;
	static void NewProp_bIsBiological_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsBiological;
	static const UECodeGen_Private::FSoftClassPropertyParams NewProp_ActorClass;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class USovereignSpeciesData constinit property declarations **********************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USovereignSpeciesData>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_USovereignSpeciesData_Statics

// ********** Begin Class USovereignSpeciesData Property Definitions *******************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_USovereignSpeciesData_Statics::NewProp_SpeciesName = { "SpeciesName", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignSpeciesData, SpeciesName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpeciesName_MetaData), NewProp_SpeciesName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USovereignSpeciesData_Statics::NewProp_SpeciesTag = { "SpeciesTag", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignSpeciesData, SpeciesTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpeciesTag_MetaData), NewProp_SpeciesTag_MetaData) }; // 517357616
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USovereignSpeciesData_Statics::NewProp_GrowthStages_Inner = { "GrowthStages", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FSovereignGrowthStage, METADATA_PARAMS(0, nullptr) }; // 2739091894
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_USovereignSpeciesData_Statics::NewProp_GrowthStages = { "GrowthStages", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignSpeciesData, GrowthStages), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GrowthStages_MetaData), NewProp_GrowthStages_MetaData) }; // 2739091894
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USovereignSpeciesData_Statics::NewProp_MaxGrowthStages_Inner = { "MaxGrowthStages", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FSovereignGrowthStage, METADATA_PARAMS(0, nullptr) }; // 2739091894
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_USovereignSpeciesData_Statics::NewProp_MaxGrowthStages = { "MaxGrowthStages", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignSpeciesData, MaxGrowthStages), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxGrowthStages_MetaData), NewProp_MaxGrowthStages_MetaData) }; // 2739091894
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USovereignSpeciesData_Statics::NewProp_IdentitySignature = { "IdentitySignature", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignSpeciesData, IdentitySignature), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IdentitySignature_MetaData), NewProp_IdentitySignature_MetaData) }; // 517357616
void Z_Construct_UClass_USovereignSpeciesData_Statics::NewProp_bCanFly_SetBit(void* Obj)
{
	((USovereignSpeciesData*)Obj)->bCanFly = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USovereignSpeciesData_Statics::NewProp_bCanFly = { "bCanFly", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(USovereignSpeciesData), &Z_Construct_UClass_USovereignSpeciesData_Statics::NewProp_bCanFly_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCanFly_MetaData), NewProp_bCanFly_MetaData) };
void Z_Construct_UClass_USovereignSpeciesData_Statics::NewProp_bCanMove_SetBit(void* Obj)
{
	((USovereignSpeciesData*)Obj)->bCanMove = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USovereignSpeciesData_Statics::NewProp_bCanMove = { "bCanMove", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(USovereignSpeciesData), &Z_Construct_UClass_USovereignSpeciesData_Statics::NewProp_bCanMove_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCanMove_MetaData), NewProp_bCanMove_MetaData) };
void Z_Construct_UClass_USovereignSpeciesData_Statics::NewProp_bIsBiological_SetBit(void* Obj)
{
	((USovereignSpeciesData*)Obj)->bIsBiological = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USovereignSpeciesData_Statics::NewProp_bIsBiological = { "bIsBiological", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(USovereignSpeciesData), &Z_Construct_UClass_USovereignSpeciesData_Statics::NewProp_bIsBiological_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsBiological_MetaData), NewProp_bIsBiological_MetaData) };
const UECodeGen_Private::FSoftClassPropertyParams Z_Construct_UClass_USovereignSpeciesData_Statics::NewProp_ActorClass = { "ActorClass", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftClass, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignSpeciesData, ActorClass), Z_Construct_UClass_ASovereignBaseEntity_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActorClass_MetaData), NewProp_ActorClass_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USovereignSpeciesData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignSpeciesData_Statics::NewProp_SpeciesName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignSpeciesData_Statics::NewProp_SpeciesTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignSpeciesData_Statics::NewProp_GrowthStages_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignSpeciesData_Statics::NewProp_GrowthStages,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignSpeciesData_Statics::NewProp_MaxGrowthStages_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignSpeciesData_Statics::NewProp_MaxGrowthStages,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignSpeciesData_Statics::NewProp_IdentitySignature,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignSpeciesData_Statics::NewProp_bCanFly,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignSpeciesData_Statics::NewProp_bCanMove,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignSpeciesData_Statics::NewProp_bIsBiological,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignSpeciesData_Statics::NewProp_ActorClass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USovereignSpeciesData_Statics::PropPointers) < 2048);
// ********** End Class USovereignSpeciesData Property Definitions *********************************
UObject* (*const Z_Construct_UClass_USovereignSpeciesData_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UPrimaryDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_WispCPP7VR,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USovereignSpeciesData_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USovereignSpeciesData_Statics::ClassParams = {
	&USovereignSpeciesData::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_USovereignSpeciesData_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_USovereignSpeciesData_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USovereignSpeciesData_Statics::Class_MetaDataParams), Z_Construct_UClass_USovereignSpeciesData_Statics::Class_MetaDataParams)
};
void USovereignSpeciesData::StaticRegisterNativesUSovereignSpeciesData()
{
}
UClass* Z_Construct_UClass_USovereignSpeciesData()
{
	if (!Z_Registration_Info_UClass_USovereignSpeciesData.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USovereignSpeciesData.OuterSingleton, Z_Construct_UClass_USovereignSpeciesData_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USovereignSpeciesData.OuterSingleton;
}
USovereignSpeciesData::USovereignSpeciesData(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, USovereignSpeciesData);
USovereignSpeciesData::~USovereignSpeciesData() {}
// ********** End Class USovereignSpeciesData ******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_DataTables_SovereignSpeciesData_h__Script_WispCPP7VR_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FSovereignGrowthStage::StaticStruct, Z_Construct_UScriptStruct_FSovereignGrowthStage_Statics::NewStructOps, TEXT("SovereignGrowthStage"),&Z_Registration_Info_UScriptStruct_FSovereignGrowthStage, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSovereignGrowthStage), 2739091894U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_USovereignSpeciesData, USovereignSpeciesData::StaticClass, TEXT("USovereignSpeciesData"), &Z_Registration_Info_UClass_USovereignSpeciesData, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USovereignSpeciesData), 3529628418U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_DataTables_SovereignSpeciesData_h__Script_WispCPP7VR_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_DataTables_SovereignSpeciesData_h__Script_WispCPP7VR_2703704525{
	TEXT("/Script/WispCPP7VR"),
	Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_DataTables_SovereignSpeciesData_h__Script_WispCPP7VR_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_DataTables_SovereignSpeciesData_h__Script_WispCPP7VR_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_DataTables_SovereignSpeciesData_h__Script_WispCPP7VR_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_DataTables_SovereignSpeciesData_h__Script_WispCPP7VR_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
