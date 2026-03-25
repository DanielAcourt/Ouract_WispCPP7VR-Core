// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SaveSystem/SovereignGameData.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSovereignGameData() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FTableRowBase();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
UPackage* Z_Construct_UPackage__Script_WispCPP7VR();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignSpeciesData_NoRegister();
WISPCPP7VR_API UEnum* Z_Construct_UEnum_WispCPP7VR_ESovereignElement();
WISPCPP7VR_API UEnum* Z_Construct_UEnum_WispCPP7VR_ESovereignGrowthStage();
WISPCPP7VR_API UEnum* Z_Construct_UEnum_WispCPP7VR_EUpdateFrequency();
WISPCPP7VR_API UScriptStruct* Z_Construct_UScriptStruct_FEntitySaveData();
WISPCPP7VR_API UScriptStruct* Z_Construct_UScriptStruct_FItemDefaults();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FItemDefaults *****************************************************
struct Z_Construct_UScriptStruct_FItemDefaults_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FItemDefaults); }
	static inline consteval int16 GetStructAlignment() { return alignof(FItemDefaults); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Just type this line above the struct\n" },
#endif
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignGameData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Just type this line above the struct" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpeciesTag_MetaData[] = {
		{ "Category", "Sovereign|Identity" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// we need this gameplay to be made or matched in some way!\n//Can be called Gameplaytag and be more genic as its not specific to a species but anything in the engine we define\n" },
#endif
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignGameData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "we need this gameplay to be made or matched in some way!\nCan be called Gameplaytag and be more genic as its not specific to a species but anything in the engine we define" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpeciesVesselData_MetaData[] = {
		{ "Category", "Sovereign|Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// My first custom \"SpeciesClass\"\n// This should package things a bit nicer\n" },
#endif
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignGameData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "My first custom \"SpeciesClass\"\nThis should package things a bit nicer" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FItemDefaults constinit property declarations *********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpeciesTag;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpeciesVesselData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FItemDefaults constinit property declarations ***********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FItemDefaults>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FItemDefaults_Statics
static_assert(std::is_polymorphic<FItemDefaults>() == std::is_polymorphic<FTableRowBase>(), "USTRUCT FItemDefaults cannot be polymorphic unless super FTableRowBase is polymorphic");
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FItemDefaults;
class UScriptStruct* FItemDefaults::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FItemDefaults.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FItemDefaults.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FItemDefaults, (UObject*)Z_Construct_UPackage__Script_WispCPP7VR(), TEXT("ItemDefaults"));
	}
	return Z_Registration_Info_UScriptStruct_FItemDefaults.OuterSingleton;
	}

// ********** Begin ScriptStruct FItemDefaults Property Definitions ********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FItemDefaults_Statics::NewProp_SpeciesTag = { "SpeciesTag", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FItemDefaults, SpeciesTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpeciesTag_MetaData), NewProp_SpeciesTag_MetaData) }; // 517357616
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FItemDefaults_Statics::NewProp_SpeciesVesselData = { "SpeciesVesselData", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FItemDefaults, SpeciesVesselData), Z_Construct_UClass_USovereignSpeciesData_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpeciesVesselData_MetaData), NewProp_SpeciesVesselData_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FItemDefaults_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FItemDefaults_Statics::NewProp_SpeciesTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FItemDefaults_Statics::NewProp_SpeciesVesselData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FItemDefaults_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FItemDefaults Property Definitions **********************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FItemDefaults_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_WispCPP7VR,
	Z_Construct_UScriptStruct_FTableRowBase,
	&NewStructOps,
	"ItemDefaults",
	Z_Construct_UScriptStruct_FItemDefaults_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FItemDefaults_Statics::PropPointers),
	sizeof(FItemDefaults),
	alignof(FItemDefaults),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FItemDefaults_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FItemDefaults_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FItemDefaults()
{
	if (!Z_Registration_Info_UScriptStruct_FItemDefaults.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FItemDefaults.InnerSingleton, Z_Construct_UScriptStruct_FItemDefaults_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FItemDefaults.InnerSingleton);
}
// ********** End ScriptStruct FItemDefaults *******************************************************

// ********** Begin Enum ESovereignGrowthStage *****************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ESovereignGrowthStage;
static UEnum* ESovereignGrowthStage_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ESovereignGrowthStage.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ESovereignGrowthStage.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_WispCPP7VR_ESovereignGrowthStage, (UObject*)Z_Construct_UPackage__Script_WispCPP7VR(), TEXT("ESovereignGrowthStage"));
	}
	return Z_Registration_Info_UEnum_ESovereignGrowthStage.OuterSingleton;
}
template<> WISPCPP7VR_NON_ATTRIBUTED_API UEnum* StaticEnum<ESovereignGrowthStage>()
{
	return ESovereignGrowthStage_StaticEnum();
}
struct Z_Construct_UEnum_WispCPP7VR_ESovereignGrowthStage_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Adolescent.Comment", "// Juvenile/Young/Sapling\n" },
		{ "Adolescent.Name", "ESovereignGrowthStage::Adolescent" },
		{ "Adolescent.ToolTip", "Juvenile/Young/Sapling" },
		{ "Adult.Comment", "// Adolescent/Fledgling/Shrub\n" },
		{ "Adult.Name", "ESovereignGrowthStage::Adult" },
		{ "Adult.ToolTip", "Adolescent/Fledgling/Shrub" },
		{ "BlueprintType", "true" },
		{ "Deteriorating.Name", "ESovereignGrowthStage::Deteriorating" },
		{ "Elder.Comment", "// 6-9: The Beyond (High Power)\n" },
		{ "Elder.Name", "ESovereignGrowthStage::Elder" },
		{ "Elder.ToolTip", "6-9: The Beyond (High Power)" },
		{ "Eternal.Name", "ESovereignGrowthStage::Eternal" },
		{ "Godly.Comment", "// Peak Evolution Almost imposibble to have children\n" },
		{ "Godly.Name", "ESovereignGrowthStage::Godly" },
		{ "Godly.ToolTip", "Peak Evolution Almost imposibble to have children" },
		{ "GoldenCore.Name", "ESovereignGrowthStage::GoldenCore" },
		{ "Inception.Comment", "// 0-2: The Beginning (High Vulnerability)\n" },
		{ "Inception.Name", "ESovereignGrowthStage::Inception" },
		{ "Inception.ToolTip", "0-2: The Beginning (High Vulnerability)" },
		{ "Juvenile.Comment", "// 3-5: The Development (Rapid Growth)\n" },
		{ "Juvenile.Name", "ESovereignGrowthStage::Juvenile" },
		{ "Juvenile.ToolTip", "3-5: The Development (Rapid Growth)" },
		{ "Legendary.Name", "ESovereignGrowthStage::Legendary" },
		{ "Mature.Comment", "// Ancient/Venerable Can make babies but has a hit in chance and increased danger for females\n" },
		{ "Mature.Name", "ESovereignGrowthStage::Mature" },
		{ "Mature.ToolTip", "Ancient/Venerable Can make babies but has a hit in chance and increased danger for females" },
		{ "MAX.Comment", "// Cant Have children no matter the buffs or abilities can rebirth and use those stats in another form\n" },
		{ "MAX.Hidden", "" },
		{ "MAX.Name", "ESovereignGrowthStage::MAX" },
		{ "MAX.ToolTip", "Cant Have children no matter the buffs or abilities can rebirth and use those stats in another form" },
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignGameData.h" },
		{ "Mythical.Name", "ESovereignGrowthStage::Mythical" },
		{ "PrimalSpirit.Comment", "// Mythic (Replacing Seed1-3 with Tier labels) rare to have children\n" },
		{ "PrimalSpirit.Name", "ESovereignGrowthStage::PrimalSpirit" },
		{ "PrimalSpirit.ToolTip", "Mythic (Replacing Seed1-3 with Tier labels) rare to have children" },
		{ "Retired.Name", "ESovereignGrowthStage::Retired" },
		{ "Seed.Comment", "//Has mother and father\n" },
		{ "Seed.Name", "ESovereignGrowthStage::Seed" },
		{ "Seed.ToolTip", "Has mother and father" },
		{ "Sprout.Comment", "// Dormant/Egg\n" },
		{ "Sprout.Name", "ESovereignGrowthStage::Sprout" },
		{ "Sprout.ToolTip", "Dormant/Egg" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ESovereignGrowthStage::Inception", (int64)ESovereignGrowthStage::Inception },
		{ "ESovereignGrowthStage::Seed", (int64)ESovereignGrowthStage::Seed },
		{ "ESovereignGrowthStage::Sprout", (int64)ESovereignGrowthStage::Sprout },
		{ "ESovereignGrowthStage::Juvenile", (int64)ESovereignGrowthStage::Juvenile },
		{ "ESovereignGrowthStage::Adolescent", (int64)ESovereignGrowthStage::Adolescent },
		{ "ESovereignGrowthStage::Adult", (int64)ESovereignGrowthStage::Adult },
		{ "ESovereignGrowthStage::Elder", (int64)ESovereignGrowthStage::Elder },
		{ "ESovereignGrowthStage::Mature", (int64)ESovereignGrowthStage::Mature },
		{ "ESovereignGrowthStage::Retired", (int64)ESovereignGrowthStage::Retired },
		{ "ESovereignGrowthStage::Deteriorating", (int64)ESovereignGrowthStage::Deteriorating },
		{ "ESovereignGrowthStage::GoldenCore", (int64)ESovereignGrowthStage::GoldenCore },
		{ "ESovereignGrowthStage::Mythical", (int64)ESovereignGrowthStage::Mythical },
		{ "ESovereignGrowthStage::Legendary", (int64)ESovereignGrowthStage::Legendary },
		{ "ESovereignGrowthStage::PrimalSpirit", (int64)ESovereignGrowthStage::PrimalSpirit },
		{ "ESovereignGrowthStage::Eternal", (int64)ESovereignGrowthStage::Eternal },
		{ "ESovereignGrowthStage::Godly", (int64)ESovereignGrowthStage::Godly },
		{ "ESovereignGrowthStage::MAX", (int64)ESovereignGrowthStage::MAX },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_WispCPP7VR_ESovereignGrowthStage_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_WispCPP7VR_ESovereignGrowthStage_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_WispCPP7VR,
	nullptr,
	"ESovereignGrowthStage",
	"ESovereignGrowthStage",
	Z_Construct_UEnum_WispCPP7VR_ESovereignGrowthStage_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_WispCPP7VR_ESovereignGrowthStage_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_WispCPP7VR_ESovereignGrowthStage_Statics::Enum_MetaDataParams), Z_Construct_UEnum_WispCPP7VR_ESovereignGrowthStage_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_WispCPP7VR_ESovereignGrowthStage()
{
	if (!Z_Registration_Info_UEnum_ESovereignGrowthStage.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ESovereignGrowthStage.InnerSingleton, Z_Construct_UEnum_WispCPP7VR_ESovereignGrowthStage_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ESovereignGrowthStage.InnerSingleton;
}
// ********** End Enum ESovereignGrowthStage *******************************************************

// ********** Begin Enum EUpdateFrequency **********************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EUpdateFrequency;
static UEnum* EUpdateFrequency_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EUpdateFrequency.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EUpdateFrequency.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_WispCPP7VR_EUpdateFrequency, (UObject*)Z_Construct_UPackage__Script_WispCPP7VR(), TEXT("EUpdateFrequency"));
	}
	return Z_Registration_Info_UEnum_EUpdateFrequency.OuterSingleton;
}
template<> WISPCPP7VR_NON_ATTRIBUTED_API UEnum* StaticEnum<EUpdateFrequency>()
{
	return EUpdateFrequency_StaticEnum();
}
struct Z_Construct_UEnum_WispCPP7VR_EUpdateFrequency_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// --- 1. GLOBAL SCOPE ENUMS (This must be OUTSIDE of any class/struct) ---\n//Version 3.0 Expanded\n" },
#endif
		{ "Dormant.Comment", "//hour fice numbers\n" },
		{ "Dormant.DisplayName", "Only on Interaction (Events/Fences)" },
		{ "Dormant.Name", "EUpdateFrequency::Dormant" },
		{ "Dormant.ToolTip", "hour fice numbers" },
		{ "Faster.Comment", "//check my math\n" },
		{ "Faster.DisplayName", "Every Frame (Wisps/NPCS)" },
		{ "Faster.Name", "EUpdateFrequency::Faster" },
		{ "Faster.ToolTip", "check my math" },
		{ "Glacier.Comment", "//minute / Poissible bee level?\n" },
		{ "Glacier.DisplayName", "Every 360 Seconds (Geological/Rocks)" },
		{ "Glacier.Name", "EUpdateFrequency::Glacier" },
		{ "Glacier.ToolTip", "minute / Poissible bee level?" },
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignGameData.h" },
		{ "Realtime.DisplayName", "Every Frame (Wisps/NPCS)" },
		{ "Realtime.Name", "EUpdateFrequency::Realtime" },
		{ "Slow.Comment", "// active hunter more dexitiry\n" },
		{ "Slow.DisplayName", "Every 10 Seconds (Animals/Passive)" },
		{ "Slow.Name", "EUpdateFrequency::Slow" },
		{ "Slow.ToolTip", "active hunter more dexitiry" },
		{ "Slower.Comment", "//animals herbivor slow grazers\n" },
		{ "Slower.DisplayName", "Every 30 Seconds (Creatures/Bees)" },
		{ "Slower.Name", "EUpdateFrequency::Slower" },
		{ "Slower.ToolTip", "animals herbivor slow grazers" },
		{ "Slowest.Comment", "//30 seconds\n" },
		{ "Slowest.DisplayName", "Every 60 Seconds (Plants/Rocks)" },
		{ "Slowest.Name", "EUpdateFrequency::Slowest" },
		{ "Slowest.ToolTip", "30 seconds" },
		{ "Standard.Comment", "// Key things NPCS,Dragons Wisps etc very limted\n" },
		{ "Standard.DisplayName", "Every 1 Second (Animals/Active)" },
		{ "Standard.Name", "EUpdateFrequency::Standard" },
		{ "Standard.ToolTip", "Key things NPCS,Dragons Wisps etc very limted" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- 1. GLOBAL SCOPE ENUMS (This must be OUTSIDE of any class/struct) ---\nVersion 3.0 Expanded" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EUpdateFrequency::Faster", (int64)EUpdateFrequency::Faster },
		{ "EUpdateFrequency::Realtime", (int64)EUpdateFrequency::Realtime },
		{ "EUpdateFrequency::Standard", (int64)EUpdateFrequency::Standard },
		{ "EUpdateFrequency::Slow", (int64)EUpdateFrequency::Slow },
		{ "EUpdateFrequency::Slower", (int64)EUpdateFrequency::Slower },
		{ "EUpdateFrequency::Slowest", (int64)EUpdateFrequency::Slowest },
		{ "EUpdateFrequency::Glacier", (int64)EUpdateFrequency::Glacier },
		{ "EUpdateFrequency::Dormant", (int64)EUpdateFrequency::Dormant },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_WispCPP7VR_EUpdateFrequency_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_WispCPP7VR_EUpdateFrequency_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_WispCPP7VR,
	nullptr,
	"EUpdateFrequency",
	"EUpdateFrequency",
	Z_Construct_UEnum_WispCPP7VR_EUpdateFrequency_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_WispCPP7VR_EUpdateFrequency_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_WispCPP7VR_EUpdateFrequency_Statics::Enum_MetaDataParams), Z_Construct_UEnum_WispCPP7VR_EUpdateFrequency_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_WispCPP7VR_EUpdateFrequency()
{
	if (!Z_Registration_Info_UEnum_EUpdateFrequency.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EUpdateFrequency.InnerSingleton, Z_Construct_UEnum_WispCPP7VR_EUpdateFrequency_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EUpdateFrequency.InnerSingleton;
}
// ********** End Enum EUpdateFrequency ************************************************************

// ********** Begin Enum ESovereignElement *********************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ESovereignElement;
static UEnum* ESovereignElement_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ESovereignElement.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ESovereignElement.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_WispCPP7VR_ESovereignElement, (UObject*)Z_Construct_UPackage__Script_WispCPP7VR(), TEXT("ESovereignElement"));
	}
	return Z_Registration_Info_UEnum_ESovereignElement.OuterSingleton;
}
template<> WISPCPP7VR_NON_ATTRIBUTED_API UEnum* StaticEnum<ESovereignElement>()
{
	return ESovereignElement_StaticEnum();
}
struct Z_Construct_UEnum_WispCPP7VR_ESovereignElement_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Air.Name", "ESovereignElement::Air" },
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Should i conside this the bae lement and expirment?\n" },
#endif
		{ "Dark.Name", "ESovereignElement::Dark" },
		{ "Dragon.Name", "ESovereignElement::Dragon" },
		{ "Earth.Name", "ESovereignElement::Earth" },
		{ "Electric.Comment", "// Special\n" },
		{ "Electric.Name", "ESovereignElement::Electric" },
		{ "Electric.ToolTip", "Special" },
		{ "Fairy.Name", "ESovereignElement::Fairy" },
		{ "Fire.Comment", "// Core Natural\n" },
		{ "Fire.Name", "ESovereignElement::Fire" },
		{ "Fire.ToolTip", "Core Natural" },
		{ "Grey.Name", "ESovereignElement::Grey" },
		{ "Light.Comment", "// Alignment\n" },
		{ "Light.Name", "ESovereignElement::Light" },
		{ "Light.ToolTip", "Alignment" },
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignGameData.h" },
		{ "Nature.Name", "ESovereignElement::Nature" },
		{ "None.Name", "ESovereignElement::None" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Should i conside this the bae lement and expirment?" },
#endif
		{ "Water.Name", "ESovereignElement::Water" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ESovereignElement::None", (int64)ESovereignElement::None },
		{ "ESovereignElement::Light", (int64)ESovereignElement::Light },
		{ "ESovereignElement::Dark", (int64)ESovereignElement::Dark },
		{ "ESovereignElement::Grey", (int64)ESovereignElement::Grey },
		{ "ESovereignElement::Fire", (int64)ESovereignElement::Fire },
		{ "ESovereignElement::Water", (int64)ESovereignElement::Water },
		{ "ESovereignElement::Earth", (int64)ESovereignElement::Earth },
		{ "ESovereignElement::Nature", (int64)ESovereignElement::Nature },
		{ "ESovereignElement::Air", (int64)ESovereignElement::Air },
		{ "ESovereignElement::Electric", (int64)ESovereignElement::Electric },
		{ "ESovereignElement::Fairy", (int64)ESovereignElement::Fairy },
		{ "ESovereignElement::Dragon", (int64)ESovereignElement::Dragon },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_WispCPP7VR_ESovereignElement_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_WispCPP7VR_ESovereignElement_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_WispCPP7VR,
	nullptr,
	"ESovereignElement",
	"ESovereignElement",
	Z_Construct_UEnum_WispCPP7VR_ESovereignElement_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_WispCPP7VR_ESovereignElement_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_WispCPP7VR_ESovereignElement_Statics::Enum_MetaDataParams), Z_Construct_UEnum_WispCPP7VR_ESovereignElement_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_WispCPP7VR_ESovereignElement()
{
	if (!Z_Registration_Info_UEnum_ESovereignElement.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ESovereignElement.InnerSingleton, Z_Construct_UEnum_WispCPP7VR_ESovereignElement_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ESovereignElement.InnerSingleton;
}
// ********** End Enum ESovereignElement ***********************************************************

// ********** Begin ScriptStruct FEntitySaveData ***************************************************
struct Z_Construct_UScriptStruct_FEntitySaveData_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FEntitySaveData); }
	static inline consteval int16 GetStructAlignment() { return alignof(FEntitySaveData); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignGameData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MyGUID_MetaData[] = {
		{ "Category", "EntitySaveData" },
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignGameData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ParentID_MetaData[] = {
		{ "Category", "Sovereign|Lineage" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The GUID of the entity (Wisp, Plant, or Tool) that created this object. */" },
#endif
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignGameData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The GUID of the entity (Wisp, Plant, or Tool) that created this object." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MotherID_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// --- Optinial i might rethink this approach as a Seperate component to \"living things\" DO WE ADD THESE so early on?? ---\n" },
#endif
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignGameData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- Optinial i might rethink this approach as a Seperate component to \"living things\" DO WE ADD THESE so early on?? ---" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FatherID_MetaData[] = {
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignGameData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsFemale_MetaData[] = {
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignGameData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OffspringCount_MetaData[] = {
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignGameData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MatingHistory_MetaData[] = {
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignGameData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SavedGrowthStage_MetaData[] = {
		{ "Category", "Sovereign|SaveData" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Inside SovereignGameData.h\n" },
#endif
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignGameData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Inside SovereignGameData.h" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldTransform_MetaData[] = {
		{ "Category", "EntitySaveData" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Update the type name here!\n// -----------------\n" },
#endif
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignGameData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Update the type name here!" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClassPath_MetaData[] = {
		{ "Category", "Sovereign" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** * The blueprint path of the actor.\n     * Essential if Player needs to respawn an object that was deleted.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignGameData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The blueprint path of the actor.\nEssential if Player needs to respawn an object that was deleted." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SavedFrequency_MetaData[] = {
		{ "Category", "Sovereign" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// We save the frequency so the heartbeat restores correctly!\n" },
#endif
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignGameData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "We save the frequency so the heartbeat restores correctly!" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ElementalAffinities_MetaData[] = {
		{ "Category", "Sovereign|Elements" },
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignGameData.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FEntitySaveData constinit property declarations *******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_MyGUID;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ParentID;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MotherID;
	static const UECodeGen_Private::FStructPropertyParams NewProp_FatherID;
	static void NewProp_bIsFemale_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsFemale;
	static const UECodeGen_Private::FIntPropertyParams NewProp_OffspringCount;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MatingHistory_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_MatingHistory;
	static const UECodeGen_Private::FBytePropertyParams NewProp_SavedGrowthStage_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SavedGrowthStage;
	static const UECodeGen_Private::FStructPropertyParams NewProp_WorldTransform;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ClassPath;
	static const UECodeGen_Private::FBytePropertyParams NewProp_SavedFrequency_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SavedFrequency;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ElementalAffinities_ValueProp;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ElementalAffinities_Key_KeyProp_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ElementalAffinities_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_ElementalAffinities;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FEntitySaveData constinit property declarations *********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FEntitySaveData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FEntitySaveData_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FEntitySaveData;
class UScriptStruct* FEntitySaveData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FEntitySaveData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FEntitySaveData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FEntitySaveData, (UObject*)Z_Construct_UPackage__Script_WispCPP7VR(), TEXT("EntitySaveData"));
	}
	return Z_Registration_Info_UScriptStruct_FEntitySaveData.OuterSingleton;
	}

// ********** Begin ScriptStruct FEntitySaveData Property Definitions ******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FEntitySaveData_Statics::NewProp_MyGUID = { "MyGUID", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEntitySaveData, MyGUID), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MyGUID_MetaData), NewProp_MyGUID_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FEntitySaveData_Statics::NewProp_ParentID = { "ParentID", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEntitySaveData, ParentID), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ParentID_MetaData), NewProp_ParentID_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FEntitySaveData_Statics::NewProp_MotherID = { "MotherID", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEntitySaveData, MotherID), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MotherID_MetaData), NewProp_MotherID_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FEntitySaveData_Statics::NewProp_FatherID = { "FatherID", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEntitySaveData, FatherID), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FatherID_MetaData), NewProp_FatherID_MetaData) };
void Z_Construct_UScriptStruct_FEntitySaveData_Statics::NewProp_bIsFemale_SetBit(void* Obj)
{
	((FEntitySaveData*)Obj)->bIsFemale = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FEntitySaveData_Statics::NewProp_bIsFemale = { "bIsFemale", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FEntitySaveData), &Z_Construct_UScriptStruct_FEntitySaveData_Statics::NewProp_bIsFemale_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsFemale_MetaData), NewProp_bIsFemale_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FEntitySaveData_Statics::NewProp_OffspringCount = { "OffspringCount", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEntitySaveData, OffspringCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OffspringCount_MetaData), NewProp_OffspringCount_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FEntitySaveData_Statics::NewProp_MatingHistory_Inner = { "MatingHistory", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FEntitySaveData_Statics::NewProp_MatingHistory = { "MatingHistory", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEntitySaveData, MatingHistory), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MatingHistory_MetaData), NewProp_MatingHistory_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FEntitySaveData_Statics::NewProp_SavedGrowthStage_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FEntitySaveData_Statics::NewProp_SavedGrowthStage = { "SavedGrowthStage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEntitySaveData, SavedGrowthStage), Z_Construct_UEnum_WispCPP7VR_ESovereignGrowthStage, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SavedGrowthStage_MetaData), NewProp_SavedGrowthStage_MetaData) }; // 257630725
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FEntitySaveData_Statics::NewProp_WorldTransform = { "WorldTransform", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEntitySaveData, WorldTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldTransform_MetaData), NewProp_WorldTransform_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FEntitySaveData_Statics::NewProp_ClassPath = { "ClassPath", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEntitySaveData, ClassPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClassPath_MetaData), NewProp_ClassPath_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FEntitySaveData_Statics::NewProp_SavedFrequency_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FEntitySaveData_Statics::NewProp_SavedFrequency = { "SavedFrequency", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEntitySaveData, SavedFrequency), Z_Construct_UEnum_WispCPP7VR_EUpdateFrequency, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SavedFrequency_MetaData), NewProp_SavedFrequency_MetaData) }; // 2306381773
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FEntitySaveData_Statics::NewProp_ElementalAffinities_ValueProp = { "ElementalAffinities", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FEntitySaveData_Statics::NewProp_ElementalAffinities_Key_KeyProp_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FEntitySaveData_Statics::NewProp_ElementalAffinities_Key_KeyProp = { "ElementalAffinities_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_WispCPP7VR_ESovereignElement, METADATA_PARAMS(0, nullptr) }; // 4150726421
const UECodeGen_Private::FMapPropertyParams Z_Construct_UScriptStruct_FEntitySaveData_Statics::NewProp_ElementalAffinities = { "ElementalAffinities", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEntitySaveData, ElementalAffinities), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ElementalAffinities_MetaData), NewProp_ElementalAffinities_MetaData) }; // 4150726421
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FEntitySaveData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEntitySaveData_Statics::NewProp_MyGUID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEntitySaveData_Statics::NewProp_ParentID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEntitySaveData_Statics::NewProp_MotherID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEntitySaveData_Statics::NewProp_FatherID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEntitySaveData_Statics::NewProp_bIsFemale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEntitySaveData_Statics::NewProp_OffspringCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEntitySaveData_Statics::NewProp_MatingHistory_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEntitySaveData_Statics::NewProp_MatingHistory,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEntitySaveData_Statics::NewProp_SavedGrowthStage_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEntitySaveData_Statics::NewProp_SavedGrowthStage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEntitySaveData_Statics::NewProp_WorldTransform,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEntitySaveData_Statics::NewProp_ClassPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEntitySaveData_Statics::NewProp_SavedFrequency_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEntitySaveData_Statics::NewProp_SavedFrequency,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEntitySaveData_Statics::NewProp_ElementalAffinities_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEntitySaveData_Statics::NewProp_ElementalAffinities_Key_KeyProp_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEntitySaveData_Statics::NewProp_ElementalAffinities_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEntitySaveData_Statics::NewProp_ElementalAffinities,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEntitySaveData_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FEntitySaveData Property Definitions ********************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FEntitySaveData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_WispCPP7VR,
	nullptr,
	&NewStructOps,
	"EntitySaveData",
	Z_Construct_UScriptStruct_FEntitySaveData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEntitySaveData_Statics::PropPointers),
	sizeof(FEntitySaveData),
	alignof(FEntitySaveData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEntitySaveData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FEntitySaveData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FEntitySaveData()
{
	if (!Z_Registration_Info_UScriptStruct_FEntitySaveData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FEntitySaveData.InnerSingleton, Z_Construct_UScriptStruct_FEntitySaveData_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FEntitySaveData.InnerSingleton);
}
// ********** End ScriptStruct FEntitySaveData *****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_SaveSystem_SovereignGameData_h__Script_WispCPP7VR_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ ESovereignGrowthStage_StaticEnum, TEXT("ESovereignGrowthStage"), &Z_Registration_Info_UEnum_ESovereignGrowthStage, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 257630725U) },
		{ EUpdateFrequency_StaticEnum, TEXT("EUpdateFrequency"), &Z_Registration_Info_UEnum_EUpdateFrequency, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2306381773U) },
		{ ESovereignElement_StaticEnum, TEXT("ESovereignElement"), &Z_Registration_Info_UEnum_ESovereignElement, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 4150726421U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FItemDefaults::StaticStruct, Z_Construct_UScriptStruct_FItemDefaults_Statics::NewStructOps, TEXT("ItemDefaults"),&Z_Registration_Info_UScriptStruct_FItemDefaults, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FItemDefaults), 1205785032U) },
		{ FEntitySaveData::StaticStruct, Z_Construct_UScriptStruct_FEntitySaveData_Statics::NewStructOps, TEXT("EntitySaveData"),&Z_Registration_Info_UScriptStruct_FEntitySaveData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FEntitySaveData), 508845134U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_SaveSystem_SovereignGameData_h__Script_WispCPP7VR_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_SaveSystem_SovereignGameData_h__Script_WispCPP7VR_3703299976{
	TEXT("/Script/WispCPP7VR"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_SaveSystem_SovereignGameData_h__Script_WispCPP7VR_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_SaveSystem_SovereignGameData_h__Script_WispCPP7VR_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_SaveSystem_SovereignGameData_h__Script_WispCPP7VR_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_SaveSystem_SovereignGameData_h__Script_WispCPP7VR_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
