// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SaveSystem/UActorRegistry.h"
#include "Engine/GameInstance.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeUActorRegistry() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
UPackage* Z_Construct_UPackage__Script_WispCPP7VR();
WISPCPP7VR_API UClass* Z_Construct_UClass_UUActorRegistry();
WISPCPP7VR_API UClass* Z_Construct_UClass_UUActorRegistry_NoRegister();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UUActorRegistry **********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UUActorRegistry;
UClass* UUActorRegistry::GetPrivateStaticClass()
{
	using TClass = UUActorRegistry;
	if (!Z_Registration_Info_UClass_UUActorRegistry.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("UActorRegistry"),
			Z_Registration_Info_UClass_UUActorRegistry.InnerSingleton,
			StaticRegisterNativesUUActorRegistry,
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
	return Z_Registration_Info_UClass_UUActorRegistry.InnerSingleton;
}
UClass* Z_Construct_UClass_UUActorRegistry_NoRegister()
{
	return UUActorRegistry::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UUActorRegistry_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * 3. The Registry (UActorRegistry)\nClass Type: Inherits from UGameInstanceSubsystem\n\nLocation: Public/Core/ (or SaveSystem/)\n\nPurpose: The \"Address Book.\" It keeps a live Map of every tree/butterfly in the garden. Without this, the SaveManager would have to \"search\" the whole world every time you save, which is slow and buggy.\n */" },
#endif
		{ "IncludePath", "SaveSystem/UActorRegistry.h" },
		{ "ModuleRelativePath", "Public/SaveSystem/UActorRegistry.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "3. The Registry (UActorRegistry)\nClass Type: Inherits from UGameInstanceSubsystem\n\nLocation: Public/Core/ (or SaveSystem/)\n\nPurpose: The \"Address Book.\" It keeps a live Map of every tree/butterfly in the garden. Without this, the SaveManager would have to \"search\" the whole world every time you save, which is slow and buggy." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UUActorRegistry constinit property declarations **************************
// ********** End Class UUActorRegistry constinit property declarations ****************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUActorRegistry>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UUActorRegistry_Statics
UObject* (*const Z_Construct_UClass_UUActorRegistry_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_WispCPP7VR,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UUActorRegistry_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UUActorRegistry_Statics::ClassParams = {
	&UUActorRegistry::StaticClass,
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
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UUActorRegistry_Statics::Class_MetaDataParams), Z_Construct_UClass_UUActorRegistry_Statics::Class_MetaDataParams)
};
void UUActorRegistry::StaticRegisterNativesUUActorRegistry()
{
}
UClass* Z_Construct_UClass_UUActorRegistry()
{
	if (!Z_Registration_Info_UClass_UUActorRegistry.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UUActorRegistry.OuterSingleton, Z_Construct_UClass_UUActorRegistry_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UUActorRegistry.OuterSingleton;
}
UUActorRegistry::UUActorRegistry() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UUActorRegistry);
UUActorRegistry::~UUActorRegistry() {}
// ********** End Class UUActorRegistry ************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_SaveSystem_UActorRegistry_h__Script_WispCPP7VR_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UUActorRegistry, UUActorRegistry::StaticClass, TEXT("UUActorRegistry"), &Z_Registration_Info_UClass_UUActorRegistry, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UUActorRegistry), 2952396347U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_SaveSystem_UActorRegistry_h__Script_WispCPP7VR_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_SaveSystem_UActorRegistry_h__Script_WispCPP7VR_4046393145{
	TEXT("/Script/WispCPP7VR"),
	Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_SaveSystem_UActorRegistry_h__Script_WispCPP7VR_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_SaveSystem_UActorRegistry_h__Script_WispCPP7VR_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
