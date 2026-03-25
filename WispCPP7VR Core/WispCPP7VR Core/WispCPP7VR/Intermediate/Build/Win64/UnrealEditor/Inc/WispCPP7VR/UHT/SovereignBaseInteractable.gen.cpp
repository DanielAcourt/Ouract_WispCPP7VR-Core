// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Entities/SovereignBaseInteractable.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSovereignBaseInteractable() {}

// ********** Begin Cross Module References ********************************************************
UPackage* Z_Construct_UPackage__Script_WispCPP7VR();
WISPCPP7VR_API UClass* Z_Construct_UClass_ASovereignBaseEntity();
WISPCPP7VR_API UClass* Z_Construct_UClass_ASovereignBaseInteractable();
WISPCPP7VR_API UClass* Z_Construct_UClass_ASovereignBaseInteractable_NoRegister();
WISPCPP7VR_API UClass* Z_Construct_UClass_UInteractionInterface_NoRegister();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ASovereignBaseInteractable ***********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_ASovereignBaseInteractable;
UClass* ASovereignBaseInteractable::GetPrivateStaticClass()
{
	using TClass = ASovereignBaseInteractable;
	if (!Z_Registration_Info_UClass_ASovereignBaseInteractable.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SovereignBaseInteractable"),
			Z_Registration_Info_UClass_ASovereignBaseInteractable.InnerSingleton,
			StaticRegisterNativesASovereignBaseInteractable,
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
	return Z_Registration_Info_UClass_ASovereignBaseInteractable.InnerSingleton;
}
UClass* Z_Construct_UClass_ASovereignBaseInteractable_NoRegister()
{
	return ASovereignBaseInteractable::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ASovereignBaseInteractable_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Entities/SovereignBaseInteractable.h" },
		{ "ModuleRelativePath", "Public/Entities/SovereignBaseInteractable.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsInteractable_MetaData[] = {
		{ "Category", "Sovereign|Interaction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Master interaction gate */" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignBaseInteractable.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Master interaction gate" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class ASovereignBaseInteractable constinit property declarations ***************
	static void NewProp_bIsInteractable_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsInteractable;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class ASovereignBaseInteractable constinit property declarations *****************
	static UObject* (*const DependentSingletons[])();
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASovereignBaseInteractable>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_ASovereignBaseInteractable_Statics

// ********** Begin Class ASovereignBaseInteractable Property Definitions **************************
void Z_Construct_UClass_ASovereignBaseInteractable_Statics::NewProp_bIsInteractable_SetBit(void* Obj)
{
	((ASovereignBaseInteractable*)Obj)->bIsInteractable = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASovereignBaseInteractable_Statics::NewProp_bIsInteractable = { "bIsInteractable", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ASovereignBaseInteractable), &Z_Construct_UClass_ASovereignBaseInteractable_Statics::NewProp_bIsInteractable_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsInteractable_MetaData), NewProp_bIsInteractable_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASovereignBaseInteractable_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASovereignBaseInteractable_Statics::NewProp_bIsInteractable,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASovereignBaseInteractable_Statics::PropPointers) < 2048);
// ********** End Class ASovereignBaseInteractable Property Definitions ****************************
UObject* (*const Z_Construct_UClass_ASovereignBaseInteractable_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ASovereignBaseEntity,
	(UObject* (*)())Z_Construct_UPackage__Script_WispCPP7VR,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASovereignBaseInteractable_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_ASovereignBaseInteractable_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UInteractionInterface_NoRegister, (int32)VTABLE_OFFSET(ASovereignBaseInteractable, IInteractionInterface), false },  // 1550710059
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_ASovereignBaseInteractable_Statics::ClassParams = {
	&ASovereignBaseInteractable::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ASovereignBaseInteractable_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ASovereignBaseInteractable_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x009000A5u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASovereignBaseInteractable_Statics::Class_MetaDataParams), Z_Construct_UClass_ASovereignBaseInteractable_Statics::Class_MetaDataParams)
};
void ASovereignBaseInteractable::StaticRegisterNativesASovereignBaseInteractable()
{
}
UClass* Z_Construct_UClass_ASovereignBaseInteractable()
{
	if (!Z_Registration_Info_UClass_ASovereignBaseInteractable.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASovereignBaseInteractable.OuterSingleton, Z_Construct_UClass_ASovereignBaseInteractable_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ASovereignBaseInteractable.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ASovereignBaseInteractable);
ASovereignBaseInteractable::~ASovereignBaseInteractable() {}
// ********** End Class ASovereignBaseInteractable *************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Entities_SovereignBaseInteractable_h__Script_WispCPP7VR_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ASovereignBaseInteractable, ASovereignBaseInteractable::StaticClass, TEXT("ASovereignBaseInteractable"), &Z_Registration_Info_UClass_ASovereignBaseInteractable, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASovereignBaseInteractable), 3975251932U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Entities_SovereignBaseInteractable_h__Script_WispCPP7VR_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Entities_SovereignBaseInteractable_h__Script_WispCPP7VR_1225997015{
	TEXT("/Script/WispCPP7VR"),
	Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Entities_SovereignBaseInteractable_h__Script_WispCPP7VR_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Entities_SovereignBaseInteractable_h__Script_WispCPP7VR_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
