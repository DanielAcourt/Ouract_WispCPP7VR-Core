// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Components/SovereignBioComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSovereignBioComponent() {}

// ********** Begin Cross Module References ********************************************************
UPackage* Z_Construct_UPackage__Script_WispCPP7VR();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignBaseComponent();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignBioComponent();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignBioComponent_NoRegister();
WISPCPP7VR_API UEnum* Z_Construct_UEnum_WispCPP7VR_ESovereignNutrient();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum ESovereignNutrient ********************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ESovereignNutrient;
static UEnum* ESovereignNutrient_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ESovereignNutrient.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ESovereignNutrient.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_WispCPP7VR_ESovereignNutrient, (UObject*)Z_Construct_UPackage__Script_WispCPP7VR(), TEXT("ESovereignNutrient"));
	}
	return Z_Registration_Info_UEnum_ESovereignNutrient.OuterSingleton;
}
template<> WISPCPP7VR_NON_ATTRIBUTED_API UEnum* StaticEnum<ESovereignNutrient>()
{
	return ESovereignNutrient_StaticEnum();
}
struct Z_Construct_UEnum_WispCPP7VR_ESovereignNutrient_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Carbs.DisplayName", "Carbohydrates" },
		{ "Carbs.Name", "ESovereignNutrient::Carbs" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// --- GLOBAL SCOPE: Defined for engine-wide visibility ---\n" },
#endif
		{ "Fats.DisplayName", "Fats" },
		{ "Fats.Name", "ESovereignNutrient::Fats" },
		{ "MAX.Hidden", "" },
		{ "MAX.Name", "ESovereignNutrient::MAX" },
		{ "Minerals.DisplayName", "Minerals" },
		{ "Minerals.Name", "ESovereignNutrient::Minerals" },
		{ "ModuleRelativePath", "Public/Components/SovereignBioComponent.h" },
		{ "Proteins.DisplayName", "Proteins" },
		{ "Proteins.Name", "ESovereignNutrient::Proteins" },
		{ "QiEssence.DisplayName", "Qi Essence" },
		{ "QiEssence.Name", "ESovereignNutrient::QiEssence" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- GLOBAL SCOPE: Defined for engine-wide visibility ---" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ESovereignNutrient::Carbs", (int64)ESovereignNutrient::Carbs },
		{ "ESovereignNutrient::Proteins", (int64)ESovereignNutrient::Proteins },
		{ "ESovereignNutrient::Fats", (int64)ESovereignNutrient::Fats },
		{ "ESovereignNutrient::Minerals", (int64)ESovereignNutrient::Minerals },
		{ "ESovereignNutrient::QiEssence", (int64)ESovereignNutrient::QiEssence },
		{ "ESovereignNutrient::MAX", (int64)ESovereignNutrient::MAX },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_WispCPP7VR_ESovereignNutrient_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_WispCPP7VR_ESovereignNutrient_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_WispCPP7VR,
	nullptr,
	"ESovereignNutrient",
	"ESovereignNutrient",
	Z_Construct_UEnum_WispCPP7VR_ESovereignNutrient_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_WispCPP7VR_ESovereignNutrient_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_WispCPP7VR_ESovereignNutrient_Statics::Enum_MetaDataParams), Z_Construct_UEnum_WispCPP7VR_ESovereignNutrient_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_WispCPP7VR_ESovereignNutrient()
{
	if (!Z_Registration_Info_UEnum_ESovereignNutrient.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ESovereignNutrient.InnerSingleton, Z_Construct_UEnum_WispCPP7VR_ESovereignNutrient_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ESovereignNutrient.InnerSingleton;
}
// ********** End Enum ESovereignNutrient **********************************************************

// ********** Begin Class USovereignBioComponent ***************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_USovereignBioComponent;
UClass* USovereignBioComponent::GetPrivateStaticClass()
{
	using TClass = USovereignBioComponent;
	if (!Z_Registration_Info_UClass_USovereignBioComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SovereignBioComponent"),
			Z_Registration_Info_UClass_USovereignBioComponent.InnerSingleton,
			StaticRegisterNativesUSovereignBioComponent,
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
	return Z_Registration_Info_UClass_USovereignBioComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_USovereignBioComponent_NoRegister()
{
	return USovereignBioComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_USovereignBioComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Sovereign" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * The Biological Engine of the Sovereign Soul.\n * Handles metabolism, growth (Mass/Density), and survival vitals.\n */" },
#endif
		{ "IncludePath", "Components/SovereignBioComponent.h" },
		{ "ModuleRelativePath", "Public/Components/SovereignBioComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The Biological Engine of the Sovereign Soul.\nHandles metabolism, growth (Mass/Density), and survival vitals." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NutrientReserves_MetaData[] = {
		{ "Category", "Sovereign|Bio Vitals" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// --- NUTRITION SYSTEM ---\n" },
#endif
		{ "ModuleRelativePath", "Public/Components/SovereignBioComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- NUTRITION SYSTEM ---" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Mass_MetaData[] = {
		{ "Category", "Sovereign|Bio Core" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// --- BIOLOGICAL ATTRIBUTES (The Growth Loop) ---\n" },
#endif
		{ "ModuleRelativePath", "Public/Components/SovereignBioComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- BIOLOGICAL ATTRIBUTES (The Growth Loop) ---" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MassExperience_MetaData[] = {
		{ "Category", "Sovereign|Bio Core" },
		{ "ModuleRelativePath", "Public/Components/SovereignBioComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Density_MetaData[] = {
		{ "Category", "Sovereign|Bio Core" },
		{ "ModuleRelativePath", "Public/Components/SovereignBioComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DensityExperience_MetaData[] = {
		{ "Category", "Sovereign|Bio Core" },
		{ "ModuleRelativePath", "Public/Components/SovereignBioComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentStaminaRegen_MetaData[] = {
		{ "Category", "Sovereign|Bio Core" },
		{ "ModuleRelativePath", "Public/Components/SovereignBioComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentStaminaRegenExperience_MetaData[] = {
		{ "Category", "Sovereign|Bio Core" },
		{ "ModuleRelativePath", "Public/Components/SovereignBioComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Hunger_MetaData[] = {
		{ "Category", "Sovereign|Bio Vitals" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// --- SURVIVAL VITALS (0.0 to 100.0) ---\n" },
#endif
		{ "ModuleRelativePath", "Public/Components/SovereignBioComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- SURVIVAL VITALS (0.0 to 100.0) ---" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Hydration_MetaData[] = {
		{ "Category", "Sovereign|Bio Vitals" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Take Nutrients from soil, Animals or plants. It consumes dead or dying mass basically.\n" },
#endif
		{ "ModuleRelativePath", "Public/Components/SovereignBioComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Take Nutrients from soil, Animals or plants. It consumes dead or dying mass basically." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Fatigue_MetaData[] = {
		{ "Category", "Sovereign|Bio Vitals" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Takes liquids not just water\n" },
#endif
		{ "ModuleRelativePath", "Public/Components/SovereignBioComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Takes liquids not just water" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Tiredness_MetaData[] = {
		{ "Category", "Sovereign|Bio Vitals" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Physical drain higher levels means more wearin, idling brings this to 0\n" },
#endif
		{ "ModuleRelativePath", "Public/Components/SovereignBioComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Physical drain higher levels means more wearin, idling brings this to 0" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Toxicity_MetaData[] = {
		{ "Category", "Sovereign|Bio Vitals" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// sleeping reduces this\n" },
#endif
		{ "ModuleRelativePath", "Public/Components/SovereignBioComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "sleeping reduces this" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WasteLevel_MetaData[] = {
		{ "Category", "Sovereign|Bio Vitals" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Damge over time\n//Needs  a way to wear down the posien over time with healing, rest anitdotes. Version 3.5\n" },
#endif
		{ "ModuleRelativePath", "Public/Components/SovereignBioComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Damge over time\nNeeds  a way to wear down the posien over time with healing, rest anitdotes. Version 3.5" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StateDrain_MetaData[] = {
		{ "Category", "Sovereign|Bio Vitals" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// --- METABOLIC MODIFIERS ---\n" },
#endif
		{ "ModuleRelativePath", "Public/Components/SovereignBioComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- METABOLIC MODIFIERS ---" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TemperatureShift_MetaData[] = {
		{ "Category", "Sovereign|Bio Vitals" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// 0 = Idle, >0 = Action-based burn\n" },
#endif
		{ "ModuleRelativePath", "Public/Components/SovereignBioComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "0 = Idle, >0 = Action-based burn" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Entropy_MetaData[] = {
		{ "Category", "Sovereign|Bio Nature Cycle" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// -1 (Freezing) to 1 (Burning)\n" },
#endif
		{ "ModuleRelativePath", "Public/Components/SovereignBioComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "-1 (Freezing) to 1 (Burning)" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class USovereignBioComponent constinit property declarations *******************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_NutrientReserves_ValueProp;
	static const UECodeGen_Private::FBytePropertyParams NewProp_NutrientReserves_Key_KeyProp_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NutrientReserves_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_NutrientReserves;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Mass;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_MassExperience;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Density;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_DensityExperience;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentStaminaRegen;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_CurrentStaminaRegenExperience;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Hunger;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Hydration;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Fatigue;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Tiredness;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Toxicity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WasteLevel;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_StateDrain;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TemperatureShift;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Entropy;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class USovereignBioComponent constinit property declarations *********************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USovereignBioComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_USovereignBioComponent_Statics

// ********** Begin Class USovereignBioComponent Property Definitions ******************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USovereignBioComponent_Statics::NewProp_NutrientReserves_ValueProp = { "NutrientReserves", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_USovereignBioComponent_Statics::NewProp_NutrientReserves_Key_KeyProp_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_USovereignBioComponent_Statics::NewProp_NutrientReserves_Key_KeyProp = { "NutrientReserves_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_WispCPP7VR_ESovereignNutrient, METADATA_PARAMS(0, nullptr) }; // 3343922586
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_USovereignBioComponent_Statics::NewProp_NutrientReserves = { "NutrientReserves", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignBioComponent, NutrientReserves), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NutrientReserves_MetaData), NewProp_NutrientReserves_MetaData) }; // 3343922586
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_USovereignBioComponent_Statics::NewProp_Mass = { "Mass", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignBioComponent, Mass), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Mass_MetaData), NewProp_Mass_MetaData) };
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UClass_USovereignBioComponent_Statics::NewProp_MassExperience = { "MassExperience", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignBioComponent, MassExperience), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MassExperience_MetaData), NewProp_MassExperience_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_USovereignBioComponent_Statics::NewProp_Density = { "Density", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignBioComponent, Density), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Density_MetaData), NewProp_Density_MetaData) };
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UClass_USovereignBioComponent_Statics::NewProp_DensityExperience = { "DensityExperience", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignBioComponent, DensityExperience), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DensityExperience_MetaData), NewProp_DensityExperience_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_USovereignBioComponent_Statics::NewProp_CurrentStaminaRegen = { "CurrentStaminaRegen", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignBioComponent, CurrentStaminaRegen), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentStaminaRegen_MetaData), NewProp_CurrentStaminaRegen_MetaData) };
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UClass_USovereignBioComponent_Statics::NewProp_CurrentStaminaRegenExperience = { "CurrentStaminaRegenExperience", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignBioComponent, CurrentStaminaRegenExperience), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentStaminaRegenExperience_MetaData), NewProp_CurrentStaminaRegenExperience_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USovereignBioComponent_Statics::NewProp_Hunger = { "Hunger", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignBioComponent, Hunger), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Hunger_MetaData), NewProp_Hunger_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USovereignBioComponent_Statics::NewProp_Hydration = { "Hydration", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignBioComponent, Hydration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Hydration_MetaData), NewProp_Hydration_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USovereignBioComponent_Statics::NewProp_Fatigue = { "Fatigue", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignBioComponent, Fatigue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Fatigue_MetaData), NewProp_Fatigue_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USovereignBioComponent_Statics::NewProp_Tiredness = { "Tiredness", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignBioComponent, Tiredness), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Tiredness_MetaData), NewProp_Tiredness_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USovereignBioComponent_Statics::NewProp_Toxicity = { "Toxicity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignBioComponent, Toxicity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Toxicity_MetaData), NewProp_Toxicity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USovereignBioComponent_Statics::NewProp_WasteLevel = { "WasteLevel", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignBioComponent, WasteLevel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WasteLevel_MetaData), NewProp_WasteLevel_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USovereignBioComponent_Statics::NewProp_StateDrain = { "StateDrain", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignBioComponent, StateDrain), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StateDrain_MetaData), NewProp_StateDrain_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USovereignBioComponent_Statics::NewProp_TemperatureShift = { "TemperatureShift", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignBioComponent, TemperatureShift), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TemperatureShift_MetaData), NewProp_TemperatureShift_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USovereignBioComponent_Statics::NewProp_Entropy = { "Entropy", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignBioComponent, Entropy), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Entropy_MetaData), NewProp_Entropy_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USovereignBioComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignBioComponent_Statics::NewProp_NutrientReserves_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignBioComponent_Statics::NewProp_NutrientReserves_Key_KeyProp_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignBioComponent_Statics::NewProp_NutrientReserves_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignBioComponent_Statics::NewProp_NutrientReserves,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignBioComponent_Statics::NewProp_Mass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignBioComponent_Statics::NewProp_MassExperience,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignBioComponent_Statics::NewProp_Density,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignBioComponent_Statics::NewProp_DensityExperience,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignBioComponent_Statics::NewProp_CurrentStaminaRegen,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignBioComponent_Statics::NewProp_CurrentStaminaRegenExperience,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignBioComponent_Statics::NewProp_Hunger,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignBioComponent_Statics::NewProp_Hydration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignBioComponent_Statics::NewProp_Fatigue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignBioComponent_Statics::NewProp_Tiredness,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignBioComponent_Statics::NewProp_Toxicity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignBioComponent_Statics::NewProp_WasteLevel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignBioComponent_Statics::NewProp_StateDrain,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignBioComponent_Statics::NewProp_TemperatureShift,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignBioComponent_Statics::NewProp_Entropy,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USovereignBioComponent_Statics::PropPointers) < 2048);
// ********** End Class USovereignBioComponent Property Definitions ********************************
UObject* (*const Z_Construct_UClass_USovereignBioComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_USovereignBaseComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_WispCPP7VR,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USovereignBioComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USovereignBioComponent_Statics::ClassParams = {
	&USovereignBioComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_USovereignBioComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_USovereignBioComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USovereignBioComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_USovereignBioComponent_Statics::Class_MetaDataParams)
};
void USovereignBioComponent::StaticRegisterNativesUSovereignBioComponent()
{
}
UClass* Z_Construct_UClass_USovereignBioComponent()
{
	if (!Z_Registration_Info_UClass_USovereignBioComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USovereignBioComponent.OuterSingleton, Z_Construct_UClass_USovereignBioComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USovereignBioComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, USovereignBioComponent);
USovereignBioComponent::~USovereignBioComponent() {}
// ********** End Class USovereignBioComponent *****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Components_SovereignBioComponent_h__Script_WispCPP7VR_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ ESovereignNutrient_StaticEnum, TEXT("ESovereignNutrient"), &Z_Registration_Info_UEnum_ESovereignNutrient, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3343922586U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_USovereignBioComponent, USovereignBioComponent::StaticClass, TEXT("USovereignBioComponent"), &Z_Registration_Info_UClass_USovereignBioComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USovereignBioComponent), 206904119U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Components_SovereignBioComponent_h__Script_WispCPP7VR_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Components_SovereignBioComponent_h__Script_WispCPP7VR_797155893{
	TEXT("/Script/WispCPP7VR"),
	Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Components_SovereignBioComponent_h__Script_WispCPP7VR_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Components_SovereignBioComponent_h__Script_WispCPP7VR_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Components_SovereignBioComponent_h__Script_WispCPP7VR_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Components_SovereignBioComponent_h__Script_WispCPP7VR_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
