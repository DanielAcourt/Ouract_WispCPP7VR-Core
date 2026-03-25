// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Interaction/SovereignSaveInterface.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSovereignSaveInterface() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
UPackage* Z_Construct_UPackage__Script_WispCPP7VR();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignSaveInterface();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignSaveInterface_NoRegister();
// ********** End Cross Module References **********************************************************

// ********** Begin Interface USovereignSaveInterface **********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_USovereignSaveInterface;
UClass* USovereignSaveInterface::GetPrivateStaticClass()
{
	using TClass = USovereignSaveInterface;
	if (!Z_Registration_Info_UClass_USovereignSaveInterface.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SovereignSaveInterface"),
			Z_Registration_Info_UClass_USovereignSaveInterface.InnerSingleton,
			StaticRegisterNativesUSovereignSaveInterface,
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
	return Z_Registration_Info_UClass_USovereignSaveInterface.InnerSingleton;
}
UClass* Z_Construct_UClass_USovereignSaveInterface_NoRegister()
{
	return USovereignSaveInterface::GetPrivateStaticClass();
}
struct Z_Construct_UClass_USovereignSaveInterface_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Interaction/SovereignSaveInterface.h" },
	};
#endif // WITH_METADATA

// ********** Begin Interface USovereignSaveInterface constinit property declarations **************
// ********** End Interface USovereignSaveInterface constinit property declarations ****************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ISovereignSaveInterface>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_USovereignSaveInterface_Statics
UObject* (*const Z_Construct_UClass_USovereignSaveInterface_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_WispCPP7VR,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USovereignSaveInterface_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USovereignSaveInterface_Statics::ClassParams = {
	&USovereignSaveInterface::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x000840A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USovereignSaveInterface_Statics::Class_MetaDataParams), Z_Construct_UClass_USovereignSaveInterface_Statics::Class_MetaDataParams)
};
void USovereignSaveInterface::StaticRegisterNativesUSovereignSaveInterface()
{
}
UClass* Z_Construct_UClass_USovereignSaveInterface()
{
	if (!Z_Registration_Info_UClass_USovereignSaveInterface.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USovereignSaveInterface.OuterSingleton, Z_Construct_UClass_USovereignSaveInterface_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USovereignSaveInterface.OuterSingleton;
}
USovereignSaveInterface::USovereignSaveInterface(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, USovereignSaveInterface);
// ********** End Interface USovereignSaveInterface ************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Interaction_SovereignSaveInterface_h__Script_WispCPP7VR_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_USovereignSaveInterface, USovereignSaveInterface::StaticClass, TEXT("USovereignSaveInterface"), &Z_Registration_Info_UClass_USovereignSaveInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USovereignSaveInterface), 1312168332U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Interaction_SovereignSaveInterface_h__Script_WispCPP7VR_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Interaction_SovereignSaveInterface_h__Script_WispCPP7VR_1262619964{
	TEXT("/Script/WispCPP7VR"),
	Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Interaction_SovereignSaveInterface_h__Script_WispCPP7VR_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Interaction_SovereignSaveInterface_h__Script_WispCPP7VR_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
