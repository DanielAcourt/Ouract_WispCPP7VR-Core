// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Components/SovereignElementComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSovereignElementComponent() {}

// ********** Begin Cross Module References ********************************************************
UPackage* Z_Construct_UPackage__Script_WispCPP7VR();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignBaseComponent();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignElementComponent();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignElementComponent_NoRegister();
// ********** End Cross Module References **********************************************************

// ********** Begin Class USovereignElementComponent ***********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_USovereignElementComponent;
UClass* USovereignElementComponent::GetPrivateStaticClass()
{
	using TClass = USovereignElementComponent;
	if (!Z_Registration_Info_UClass_USovereignElementComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SovereignElementComponent"),
			Z_Registration_Info_UClass_USovereignElementComponent.InnerSingleton,
			StaticRegisterNativesUSovereignElementComponent,
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
	return Z_Registration_Info_UClass_USovereignElementComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_USovereignElementComponent_NoRegister()
{
	return USovereignElementComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_USovereignElementComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "Components/SovereignElementComponent.h" },
		{ "ModuleRelativePath", "Public/Components/SovereignElementComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FireAffinity_MetaData[] = {
		{ "Category", "Sovereign|Resistances" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// --- 3. RESISTANCES (Defense Layers) ---\n" },
#endif
		{ "ModuleRelativePath", "Public/Components/SovereignElementComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- 3. RESISTANCES (Defense Layers) ---" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EarthAffinity_MetaData[] = {
		{ "Category", "Sovereign|Resistances" },
		{ "ModuleRelativePath", "Public/Components/SovereignElementComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WindAffinity_MetaData[] = {
		{ "Category", "Sovereign|Resistances" },
		{ "ModuleRelativePath", "Public/Components/SovereignElementComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WaterAffinity_MetaData[] = {
		{ "Category", "Sovereign|Resistances" },
		{ "ModuleRelativePath", "Public/Components/SovereignElementComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlowResistance_MetaData[] = {
		{ "Category", "Sovereign|Resistances" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Maybe electric?\n" },
#endif
		{ "ModuleRelativePath", "Public/Components/SovereignElementComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maybe electric?" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class USovereignElementComponent constinit property declarations ***************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FireAffinity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_EarthAffinity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WindAffinity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WaterAffinity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SlowResistance;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class USovereignElementComponent constinit property declarations *****************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USovereignElementComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_USovereignElementComponent_Statics

// ********** Begin Class USovereignElementComponent Property Definitions **************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USovereignElementComponent_Statics::NewProp_FireAffinity = { "FireAffinity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignElementComponent, FireAffinity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FireAffinity_MetaData), NewProp_FireAffinity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USovereignElementComponent_Statics::NewProp_EarthAffinity = { "EarthAffinity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignElementComponent, EarthAffinity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EarthAffinity_MetaData), NewProp_EarthAffinity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USovereignElementComponent_Statics::NewProp_WindAffinity = { "WindAffinity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignElementComponent, WindAffinity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WindAffinity_MetaData), NewProp_WindAffinity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USovereignElementComponent_Statics::NewProp_WaterAffinity = { "WaterAffinity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignElementComponent, WaterAffinity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WaterAffinity_MetaData), NewProp_WaterAffinity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USovereignElementComponent_Statics::NewProp_SlowResistance = { "SlowResistance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignElementComponent, SlowResistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlowResistance_MetaData), NewProp_SlowResistance_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USovereignElementComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignElementComponent_Statics::NewProp_FireAffinity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignElementComponent_Statics::NewProp_EarthAffinity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignElementComponent_Statics::NewProp_WindAffinity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignElementComponent_Statics::NewProp_WaterAffinity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignElementComponent_Statics::NewProp_SlowResistance,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USovereignElementComponent_Statics::PropPointers) < 2048);
// ********** End Class USovereignElementComponent Property Definitions ****************************
UObject* (*const Z_Construct_UClass_USovereignElementComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_USovereignBaseComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_WispCPP7VR,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USovereignElementComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USovereignElementComponent_Statics::ClassParams = {
	&USovereignElementComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_USovereignElementComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_USovereignElementComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USovereignElementComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_USovereignElementComponent_Statics::Class_MetaDataParams)
};
void USovereignElementComponent::StaticRegisterNativesUSovereignElementComponent()
{
}
UClass* Z_Construct_UClass_USovereignElementComponent()
{
	if (!Z_Registration_Info_UClass_USovereignElementComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USovereignElementComponent.OuterSingleton, Z_Construct_UClass_USovereignElementComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USovereignElementComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, USovereignElementComponent);
USovereignElementComponent::~USovereignElementComponent() {}
// ********** End Class USovereignElementComponent *************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Components_SovereignElementComponent_h__Script_WispCPP7VR_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_USovereignElementComponent, USovereignElementComponent::StaticClass, TEXT("USovereignElementComponent"), &Z_Registration_Info_UClass_USovereignElementComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USovereignElementComponent), 3034358219U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Components_SovereignElementComponent_h__Script_WispCPP7VR_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Components_SovereignElementComponent_h__Script_WispCPP7VR_2072755186{
	TEXT("/Script/WispCPP7VR"),
	Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Components_SovereignElementComponent_h__Script_WispCPP7VR_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Components_SovereignElementComponent_h__Script_WispCPP7VR_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
