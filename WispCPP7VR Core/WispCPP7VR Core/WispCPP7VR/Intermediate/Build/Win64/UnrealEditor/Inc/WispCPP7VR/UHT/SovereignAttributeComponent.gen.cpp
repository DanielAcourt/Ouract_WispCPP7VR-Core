// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Components/SovereignAttributeComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSovereignAttributeComponent() {}

// ********** Begin Cross Module References ********************************************************
UPackage* Z_Construct_UPackage__Script_WispCPP7VR();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignAttributeComponent();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignAttributeComponent_NoRegister();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignBaseComponent();
// ********** End Cross Module References **********************************************************

// ********** Begin Class USovereignAttributeComponent Function GetMaxHealth ***********************
struct Z_Construct_UFunction_USovereignAttributeComponent_GetMaxHealth_Statics
{
	struct SovereignAttributeComponent_eventGetMaxHealth_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Calculations" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Helper to get Max Health based on Constitution and Maturity */" },
#endif
		{ "ModuleRelativePath", "Public/Components/SovereignAttributeComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Helper to get Max Health based on Constitution and Maturity" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetMaxHealth constinit property declarations **************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetMaxHealth constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetMaxHealth Property Definitions *************************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USovereignAttributeComponent_GetMaxHealth_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignAttributeComponent_eventGetMaxHealth_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USovereignAttributeComponent_GetMaxHealth_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignAttributeComponent_GetMaxHealth_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignAttributeComponent_GetMaxHealth_Statics::PropPointers) < 2048);
// ********** End Function GetMaxHealth Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USovereignAttributeComponent_GetMaxHealth_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USovereignAttributeComponent, nullptr, "GetMaxHealth", 	Z_Construct_UFunction_USovereignAttributeComponent_GetMaxHealth_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignAttributeComponent_GetMaxHealth_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USovereignAttributeComponent_GetMaxHealth_Statics::SovereignAttributeComponent_eventGetMaxHealth_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignAttributeComponent_GetMaxHealth_Statics::Function_MetaDataParams), Z_Construct_UFunction_USovereignAttributeComponent_GetMaxHealth_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USovereignAttributeComponent_GetMaxHealth_Statics::SovereignAttributeComponent_eventGetMaxHealth_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USovereignAttributeComponent_GetMaxHealth()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USovereignAttributeComponent_GetMaxHealth_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USovereignAttributeComponent::execGetMaxHealth)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetMaxHealth();
	P_NATIVE_END;
}
// ********** End Class USovereignAttributeComponent Function GetMaxHealth *************************

// ********** Begin Class USovereignAttributeComponent Function SyncStatsFromEntity ****************
struct Z_Construct_UFunction_USovereignAttributeComponent_SyncStatsFromEntity_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Attributes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** * Pulls base stats from the Owner's SaveDataComponent.\n\x09 * Essential for ensuring Humans, Plants, and Dragons have different starting potential.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/Components/SovereignAttributeComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Pulls base stats from the Owner's SaveDataComponent.\nEssential for ensuring Humans, Plants, and Dragons have different starting potential." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SyncStatsFromEntity constinit property declarations *******************
// ********** End Function SyncStatsFromEntity constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USovereignAttributeComponent_SyncStatsFromEntity_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USovereignAttributeComponent, nullptr, "SyncStatsFromEntity", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignAttributeComponent_SyncStatsFromEntity_Statics::Function_MetaDataParams), Z_Construct_UFunction_USovereignAttributeComponent_SyncStatsFromEntity_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_USovereignAttributeComponent_SyncStatsFromEntity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USovereignAttributeComponent_SyncStatsFromEntity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USovereignAttributeComponent::execSyncStatsFromEntity)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SyncStatsFromEntity();
	P_NATIVE_END;
}
// ********** End Class USovereignAttributeComponent Function SyncStatsFromEntity ******************

// ********** Begin Class USovereignAttributeComponent *********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_USovereignAttributeComponent;
UClass* USovereignAttributeComponent::GetPrivateStaticClass()
{
	using TClass = USovereignAttributeComponent;
	if (!Z_Registration_Info_UClass_USovereignAttributeComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SovereignAttributeComponent"),
			Z_Registration_Info_UClass_USovereignAttributeComponent.InnerSingleton,
			StaticRegisterNativesUSovereignAttributeComponent,
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
	return Z_Registration_Info_UClass_USovereignAttributeComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_USovereignAttributeComponent_NoRegister()
{
	return USovereignAttributeComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_USovereignAttributeComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * USovereignAttributeComponent\n * Handles the D&D-style physical and mental vessel stats.\n * Values are synced from the SaveDataComponent to allow dynamic species scaling.\n */" },
#endif
		{ "IncludePath", "Components/SovereignAttributeComponent.h" },
		{ "ModuleRelativePath", "Public/Components/SovereignAttributeComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "USovereignAttributeComponent\nHandles the D&D-style physical and mental vessel stats.\nValues are synced from the SaveDataComponent to allow dynamic species scaling." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Strength_MetaData[] = {
		{ "Category", "Sovereign|Core Attributes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// --- 1. CORE ATTRIBUTES (Infinite Accumulator Logic) ---\n" },
#endif
		{ "ModuleRelativePath", "Public/Components/SovereignAttributeComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- 1. CORE ATTRIBUTES (Infinite Accumulator Logic) ---" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StrengthExperience_MetaData[] = {
		{ "Category", "Sovereign|Core Attributes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// The Prestige Level\n" },
#endif
		{ "ModuleRelativePath", "Public/Components/SovereignAttributeComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The Prestige Level" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Dexterity_MetaData[] = {
		{ "Category", "Sovereign|Core Attributes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// The Scientific Accumulator\n" },
#endif
		{ "ModuleRelativePath", "Public/Components/SovereignAttributeComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The Scientific Accumulator" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DexterityExperience_MetaData[] = {
		{ "Category", "Sovereign|Core Attributes" },
		{ "ModuleRelativePath", "Public/Components/SovereignAttributeComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Constitution_MetaData[] = {
		{ "Category", "Sovereign|Core Attributes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Fixed typo and duplicate\n" },
#endif
		{ "ModuleRelativePath", "Public/Components/SovereignAttributeComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fixed typo and duplicate" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ConstitutionExperience_MetaData[] = {
		{ "Category", "Sovereign|Core Attributes" },
		{ "ModuleRelativePath", "Public/Components/SovereignAttributeComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Intelligence_MetaData[] = {
		{ "Category", "Sovereign|Core Attributes" },
		{ "ModuleRelativePath", "Public/Components/SovereignAttributeComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IntelligenceExperience_MetaData[] = {
		{ "Category", "Sovereign|Core Attributes" },
		{ "ModuleRelativePath", "Public/Components/SovereignAttributeComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Wisdom_MetaData[] = {
		{ "Category", "Sovereign|Core Attributes" },
		{ "ModuleRelativePath", "Public/Components/SovereignAttributeComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WisdomExperience_MetaData[] = {
		{ "Category", "Sovereign|Core Attributes" },
		{ "ModuleRelativePath", "Public/Components/SovereignAttributeComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Charisma_MetaData[] = {
		{ "Category", "Sovereign|Core Attributes" },
		{ "ModuleRelativePath", "Public/Components/SovereignAttributeComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharismaExperience_MetaData[] = {
		{ "Category", "Sovereign|Core Attributes" },
		{ "ModuleRelativePath", "Public/Components/SovereignAttributeComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Luck_MetaData[] = {
		{ "Category", "Sovereign|Core Attributes" },
		{ "ModuleRelativePath", "Public/Components/SovereignAttributeComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LuckExperience_MetaData[] = {
		{ "Category", "Sovereign|Core Attributes" },
		{ "ModuleRelativePath", "Public/Components/SovereignAttributeComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ArmourClass_MetaData[] = {
		{ "Category", "Sovereign|Core Attributes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Derived from Dexterity and Equipment */" },
#endif
		{ "ModuleRelativePath", "Public/Components/SovereignAttributeComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Derived from Dexterity and Equipment" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentHealth_MetaData[] = {
		{ "Category", "Sovereign|Realtime Attributes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// --- 2. USABLE RESOURCES (Real-time Bars) ---\n" },
#endif
		{ "ModuleRelativePath", "Public/Components/SovereignAttributeComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- 2. USABLE RESOURCES (Real-time Bars) ---" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PhysicalResistance_MetaData[] = {
		{ "Category", "Sovereign|Resistances" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// --- 3. RESISTANCES (Innate Vessel Defense) ---\n// Kept here as base values before gear modifications.\n" },
#endif
		{ "ModuleRelativePath", "Public/Components/SovereignAttributeComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- 3. RESISTANCES (Innate Vessel Defense) ---\nKept here as base values before gear modifications." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MagicalResistance_MetaData[] = {
		{ "Category", "Sovereign|Resistances" },
		{ "ModuleRelativePath", "Public/Components/SovereignAttributeComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MentalResistance_MetaData[] = {
		{ "Category", "Sovereign|Resistances" },
		{ "ModuleRelativePath", "Public/Components/SovereignAttributeComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PoisonResistance_MetaData[] = {
		{ "Category", "Sovereign|Resistances" },
		{ "ModuleRelativePath", "Public/Components/SovereignAttributeComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlowResistance_MetaData[] = {
		{ "Category", "Sovereign|Resistances" },
		{ "ModuleRelativePath", "Public/Components/SovereignAttributeComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class USovereignAttributeComponent constinit property declarations *************
	static const UECodeGen_Private::FIntPropertyParams NewProp_Strength;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_StrengthExperience;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Dexterity;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_DexterityExperience;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Constitution;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_ConstitutionExperience;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Intelligence;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_IntelligenceExperience;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Wisdom;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_WisdomExperience;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Charisma;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_CharismaExperience;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Luck;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_LuckExperience;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ArmourClass;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentHealth;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PhysicalResistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MagicalResistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MentalResistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PoisonResistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SlowResistance;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class USovereignAttributeComponent constinit property declarations ***************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetMaxHealth"), .Pointer = &USovereignAttributeComponent::execGetMaxHealth },
		{ .NameUTF8 = UTF8TEXT("SyncStatsFromEntity"), .Pointer = &USovereignAttributeComponent::execSyncStatsFromEntity },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_USovereignAttributeComponent_GetMaxHealth, "GetMaxHealth" }, // 2759184631
		{ &Z_Construct_UFunction_USovereignAttributeComponent_SyncStatsFromEntity, "SyncStatsFromEntity" }, // 743212855
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USovereignAttributeComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_USovereignAttributeComponent_Statics

// ********** Begin Class USovereignAttributeComponent Property Definitions ************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_USovereignAttributeComponent_Statics::NewProp_Strength = { "Strength", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignAttributeComponent, Strength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Strength_MetaData), NewProp_Strength_MetaData) };
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UClass_USovereignAttributeComponent_Statics::NewProp_StrengthExperience = { "StrengthExperience", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignAttributeComponent, StrengthExperience), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StrengthExperience_MetaData), NewProp_StrengthExperience_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_USovereignAttributeComponent_Statics::NewProp_Dexterity = { "Dexterity", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignAttributeComponent, Dexterity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Dexterity_MetaData), NewProp_Dexterity_MetaData) };
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UClass_USovereignAttributeComponent_Statics::NewProp_DexterityExperience = { "DexterityExperience", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignAttributeComponent, DexterityExperience), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DexterityExperience_MetaData), NewProp_DexterityExperience_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_USovereignAttributeComponent_Statics::NewProp_Constitution = { "Constitution", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignAttributeComponent, Constitution), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Constitution_MetaData), NewProp_Constitution_MetaData) };
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UClass_USovereignAttributeComponent_Statics::NewProp_ConstitutionExperience = { "ConstitutionExperience", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignAttributeComponent, ConstitutionExperience), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ConstitutionExperience_MetaData), NewProp_ConstitutionExperience_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_USovereignAttributeComponent_Statics::NewProp_Intelligence = { "Intelligence", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignAttributeComponent, Intelligence), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Intelligence_MetaData), NewProp_Intelligence_MetaData) };
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UClass_USovereignAttributeComponent_Statics::NewProp_IntelligenceExperience = { "IntelligenceExperience", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignAttributeComponent, IntelligenceExperience), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IntelligenceExperience_MetaData), NewProp_IntelligenceExperience_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_USovereignAttributeComponent_Statics::NewProp_Wisdom = { "Wisdom", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignAttributeComponent, Wisdom), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Wisdom_MetaData), NewProp_Wisdom_MetaData) };
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UClass_USovereignAttributeComponent_Statics::NewProp_WisdomExperience = { "WisdomExperience", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignAttributeComponent, WisdomExperience), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WisdomExperience_MetaData), NewProp_WisdomExperience_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_USovereignAttributeComponent_Statics::NewProp_Charisma = { "Charisma", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignAttributeComponent, Charisma), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Charisma_MetaData), NewProp_Charisma_MetaData) };
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UClass_USovereignAttributeComponent_Statics::NewProp_CharismaExperience = { "CharismaExperience", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignAttributeComponent, CharismaExperience), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharismaExperience_MetaData), NewProp_CharismaExperience_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_USovereignAttributeComponent_Statics::NewProp_Luck = { "Luck", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignAttributeComponent, Luck), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Luck_MetaData), NewProp_Luck_MetaData) };
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UClass_USovereignAttributeComponent_Statics::NewProp_LuckExperience = { "LuckExperience", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignAttributeComponent, LuckExperience), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LuckExperience_MetaData), NewProp_LuckExperience_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_USovereignAttributeComponent_Statics::NewProp_ArmourClass = { "ArmourClass", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignAttributeComponent, ArmourClass), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ArmourClass_MetaData), NewProp_ArmourClass_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USovereignAttributeComponent_Statics::NewProp_CurrentHealth = { "CurrentHealth", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignAttributeComponent, CurrentHealth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentHealth_MetaData), NewProp_CurrentHealth_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USovereignAttributeComponent_Statics::NewProp_PhysicalResistance = { "PhysicalResistance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignAttributeComponent, PhysicalResistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PhysicalResistance_MetaData), NewProp_PhysicalResistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USovereignAttributeComponent_Statics::NewProp_MagicalResistance = { "MagicalResistance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignAttributeComponent, MagicalResistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MagicalResistance_MetaData), NewProp_MagicalResistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USovereignAttributeComponent_Statics::NewProp_MentalResistance = { "MentalResistance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignAttributeComponent, MentalResistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MentalResistance_MetaData), NewProp_MentalResistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USovereignAttributeComponent_Statics::NewProp_PoisonResistance = { "PoisonResistance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignAttributeComponent, PoisonResistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PoisonResistance_MetaData), NewProp_PoisonResistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USovereignAttributeComponent_Statics::NewProp_SlowResistance = { "SlowResistance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignAttributeComponent, SlowResistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlowResistance_MetaData), NewProp_SlowResistance_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USovereignAttributeComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignAttributeComponent_Statics::NewProp_Strength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignAttributeComponent_Statics::NewProp_StrengthExperience,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignAttributeComponent_Statics::NewProp_Dexterity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignAttributeComponent_Statics::NewProp_DexterityExperience,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignAttributeComponent_Statics::NewProp_Constitution,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignAttributeComponent_Statics::NewProp_ConstitutionExperience,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignAttributeComponent_Statics::NewProp_Intelligence,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignAttributeComponent_Statics::NewProp_IntelligenceExperience,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignAttributeComponent_Statics::NewProp_Wisdom,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignAttributeComponent_Statics::NewProp_WisdomExperience,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignAttributeComponent_Statics::NewProp_Charisma,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignAttributeComponent_Statics::NewProp_CharismaExperience,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignAttributeComponent_Statics::NewProp_Luck,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignAttributeComponent_Statics::NewProp_LuckExperience,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignAttributeComponent_Statics::NewProp_ArmourClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignAttributeComponent_Statics::NewProp_CurrentHealth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignAttributeComponent_Statics::NewProp_PhysicalResistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignAttributeComponent_Statics::NewProp_MagicalResistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignAttributeComponent_Statics::NewProp_MentalResistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignAttributeComponent_Statics::NewProp_PoisonResistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignAttributeComponent_Statics::NewProp_SlowResistance,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USovereignAttributeComponent_Statics::PropPointers) < 2048);
// ********** End Class USovereignAttributeComponent Property Definitions **************************
UObject* (*const Z_Construct_UClass_USovereignAttributeComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_USovereignBaseComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_WispCPP7VR,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USovereignAttributeComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USovereignAttributeComponent_Statics::ClassParams = {
	&USovereignAttributeComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_USovereignAttributeComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_USovereignAttributeComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USovereignAttributeComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_USovereignAttributeComponent_Statics::Class_MetaDataParams)
};
void USovereignAttributeComponent::StaticRegisterNativesUSovereignAttributeComponent()
{
	UClass* Class = USovereignAttributeComponent::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_USovereignAttributeComponent_Statics::Funcs));
}
UClass* Z_Construct_UClass_USovereignAttributeComponent()
{
	if (!Z_Registration_Info_UClass_USovereignAttributeComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USovereignAttributeComponent.OuterSingleton, Z_Construct_UClass_USovereignAttributeComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USovereignAttributeComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, USovereignAttributeComponent);
USovereignAttributeComponent::~USovereignAttributeComponent() {}
// ********** End Class USovereignAttributeComponent ***********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Components_SovereignAttributeComponent_h__Script_WispCPP7VR_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_USovereignAttributeComponent, USovereignAttributeComponent::StaticClass, TEXT("USovereignAttributeComponent"), &Z_Registration_Info_UClass_USovereignAttributeComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USovereignAttributeComponent), 2363568475U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Components_SovereignAttributeComponent_h__Script_WispCPP7VR_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Components_SovereignAttributeComponent_h__Script_WispCPP7VR_2594981195{
	TEXT("/Script/WispCPP7VR"),
	Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Components_SovereignAttributeComponent_h__Script_WispCPP7VR_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Components_SovereignAttributeComponent_h__Script_WispCPP7VR_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
