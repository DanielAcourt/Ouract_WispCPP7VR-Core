// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Components/SovereignBaseComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSovereignBaseComponent() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
UPackage* Z_Construct_UPackage__Script_WispCPP7VR();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignBaseComponent();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignBaseComponent_NoRegister();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignSaveInterface_NoRegister();
// ********** End Cross Module References **********************************************************

// ********** Begin Class USovereignBaseComponent **************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_USovereignBaseComponent;
UClass* USovereignBaseComponent::GetPrivateStaticClass()
{
	using TClass = USovereignBaseComponent;
	if (!Z_Registration_Info_UClass_USovereignBaseComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SovereignBaseComponent"),
			Z_Registration_Info_UClass_USovereignBaseComponent.InnerSingleton,
			StaticRegisterNativesUSovereignBaseComponent,
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
	return Z_Registration_Info_UClass_USovereignBaseComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_USovereignBaseComponent_NoRegister()
{
	return USovereignBaseComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_USovereignBaseComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "Components/SovereignBaseComponent.h" },
		{ "ModuleRelativePath", "Public/Components/SovereignBaseComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class USovereignBaseComponent constinit property declarations ******************
// ********** End Class USovereignBaseComponent constinit property declarations ********************
	static UObject* (*const DependentSingletons[])();
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USovereignBaseComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_USovereignBaseComponent_Statics
UObject* (*const Z_Construct_UClass_USovereignBaseComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_WispCPP7VR,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USovereignBaseComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_USovereignBaseComponent_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_USovereignSaveInterface_NoRegister, (int32)VTABLE_OFFSET(USovereignBaseComponent, ISovereignSaveInterface), false },  // 1312168332
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_USovereignBaseComponent_Statics::ClassParams = {
	&USovereignBaseComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	UE_ARRAY_COUNT(InterfaceParams),
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USovereignBaseComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_USovereignBaseComponent_Statics::Class_MetaDataParams)
};
void USovereignBaseComponent::StaticRegisterNativesUSovereignBaseComponent()
{
}
UClass* Z_Construct_UClass_USovereignBaseComponent()
{
	if (!Z_Registration_Info_UClass_USovereignBaseComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USovereignBaseComponent.OuterSingleton, Z_Construct_UClass_USovereignBaseComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USovereignBaseComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, USovereignBaseComponent);
USovereignBaseComponent::~USovereignBaseComponent() {}
// ********** End Class USovereignBaseComponent ****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Components_SovereignBaseComponent_h__Script_WispCPP7VR_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_USovereignBaseComponent, USovereignBaseComponent::StaticClass, TEXT("USovereignBaseComponent"), &Z_Registration_Info_UClass_USovereignBaseComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USovereignBaseComponent), 334955253U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Components_SovereignBaseComponent_h__Script_WispCPP7VR_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Components_SovereignBaseComponent_h__Script_WispCPP7VR_3707409779{
	TEXT("/Script/WispCPP7VR"),
	Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Components_SovereignBaseComponent_h__Script_WispCPP7VR_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Components_SovereignBaseComponent_h__Script_WispCPP7VR_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
