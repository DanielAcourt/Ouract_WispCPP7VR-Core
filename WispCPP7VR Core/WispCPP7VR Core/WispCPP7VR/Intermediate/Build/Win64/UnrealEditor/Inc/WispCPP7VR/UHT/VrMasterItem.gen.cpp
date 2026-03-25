// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VrMasterItem.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeVrMasterItem() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
UPackage* Z_Construct_UPackage__Script_WispCPP7VR();
WISPCPP7VR_API UClass* Z_Construct_UClass_UVrMasterItem();
WISPCPP7VR_API UClass* Z_Construct_UClass_UVrMasterItem_NoRegister();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UVrMasterItem ************************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UVrMasterItem;
UClass* UVrMasterItem::GetPrivateStaticClass()
{
	using TClass = UVrMasterItem;
	if (!Z_Registration_Info_UClass_UVrMasterItem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("VrMasterItem"),
			Z_Registration_Info_UClass_UVrMasterItem.InnerSingleton,
			StaticRegisterNativesUVrMasterItem,
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
	return Z_Registration_Info_UClass_UVrMasterItem.InnerSingleton;
}
UClass* Z_Construct_UClass_UVrMasterItem_NoRegister()
{
	return UVrMasterItem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UVrMasterItem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "VrMasterItem.h" },
		{ "ModuleRelativePath", "Public/VrMasterItem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UVrMasterItem constinit property declarations ****************************
// ********** End Class UVrMasterItem constinit property declarations ******************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVrMasterItem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UVrMasterItem_Statics
UObject* (*const Z_Construct_UClass_UVrMasterItem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_WispCPP7VR,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVrMasterItem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UVrMasterItem_Statics::ClassParams = {
	&UVrMasterItem::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVrMasterItem_Statics::Class_MetaDataParams), Z_Construct_UClass_UVrMasterItem_Statics::Class_MetaDataParams)
};
void UVrMasterItem::StaticRegisterNativesUVrMasterItem()
{
}
UClass* Z_Construct_UClass_UVrMasterItem()
{
	if (!Z_Registration_Info_UClass_UVrMasterItem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UVrMasterItem.OuterSingleton, Z_Construct_UClass_UVrMasterItem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UVrMasterItem.OuterSingleton;
}
UVrMasterItem::UVrMasterItem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UVrMasterItem);
UVrMasterItem::~UVrMasterItem() {}
// ********** End Class UVrMasterItem **************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_VrMasterItem_h__Script_WispCPP7VR_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UVrMasterItem, UVrMasterItem::StaticClass, TEXT("UVrMasterItem"), &Z_Registration_Info_UClass_UVrMasterItem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UVrMasterItem), 4103237731U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_VrMasterItem_h__Script_WispCPP7VR_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_VrMasterItem_h__Script_WispCPP7VR_2676911756{
	TEXT("/Script/WispCPP7VR"),
	Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_VrMasterItem_h__Script_WispCPP7VR_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_VrMasterItem_h__Script_WispCPP7VR_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
