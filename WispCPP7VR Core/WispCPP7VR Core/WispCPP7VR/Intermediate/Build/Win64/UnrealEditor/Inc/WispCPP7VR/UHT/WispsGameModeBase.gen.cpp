// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CoreModules/WispsGameModeBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeWispsGameModeBase() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
ENGINE_API UClass* Z_Construct_UClass_UDataTable_NoRegister();
UPackage* Z_Construct_UPackage__Script_WispCPP7VR();
WISPCPP7VR_API UClass* Z_Construct_UClass_AWispsGameModeBase();
WISPCPP7VR_API UClass* Z_Construct_UClass_AWispsGameModeBase_NoRegister();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AWispsGameModeBase *******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AWispsGameModeBase;
UClass* AWispsGameModeBase::GetPrivateStaticClass()
{
	using TClass = AWispsGameModeBase;
	if (!Z_Registration_Info_UClass_AWispsGameModeBase.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("WispsGameModeBase"),
			Z_Registration_Info_UClass_AWispsGameModeBase.InnerSingleton,
			StaticRegisterNativesAWispsGameModeBase,
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
	return Z_Registration_Info_UClass_AWispsGameModeBase.InnerSingleton;
}
UClass* Z_Construct_UClass_AWispsGameModeBase_NoRegister()
{
	return AWispsGameModeBase::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AWispsGameModeBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "CoreModules/WispsGameModeBase.h" },
		{ "ModuleRelativePath", "Public/CoreModules/WispsGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemDataTable_MetaData[] = {
		{ "Category", "Sovereign|Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Global reference to your Species/Item Data Table */" },
#endif
		{ "ModuleRelativePath", "Public/CoreModules/WispsGameModeBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Global reference to your Species/Item Data Table" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class AWispsGameModeBase constinit property declarations ***********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemDataTable;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class AWispsGameModeBase constinit property declarations *************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AWispsGameModeBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AWispsGameModeBase_Statics

// ********** Begin Class AWispsGameModeBase Property Definitions **********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWispsGameModeBase_Statics::NewProp_ItemDataTable = { "ItemDataTable", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWispsGameModeBase, ItemDataTable), Z_Construct_UClass_UDataTable_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemDataTable_MetaData), NewProp_ItemDataTable_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AWispsGameModeBase_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWispsGameModeBase_Statics::NewProp_ItemDataTable,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AWispsGameModeBase_Statics::PropPointers) < 2048);
// ********** End Class AWispsGameModeBase Property Definitions ************************************
UObject* (*const Z_Construct_UClass_AWispsGameModeBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_WispCPP7VR,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AWispsGameModeBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AWispsGameModeBase_Statics::ClassParams = {
	&AWispsGameModeBase::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AWispsGameModeBase_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AWispsGameModeBase_Statics::PropPointers),
	0,
	0x009002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AWispsGameModeBase_Statics::Class_MetaDataParams), Z_Construct_UClass_AWispsGameModeBase_Statics::Class_MetaDataParams)
};
void AWispsGameModeBase::StaticRegisterNativesAWispsGameModeBase()
{
}
UClass* Z_Construct_UClass_AWispsGameModeBase()
{
	if (!Z_Registration_Info_UClass_AWispsGameModeBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AWispsGameModeBase.OuterSingleton, Z_Construct_UClass_AWispsGameModeBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AWispsGameModeBase.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AWispsGameModeBase);
AWispsGameModeBase::~AWispsGameModeBase() {}
// ********** End Class AWispsGameModeBase *********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_CoreModules_WispsGameModeBase_h__Script_WispCPP7VR_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AWispsGameModeBase, AWispsGameModeBase::StaticClass, TEXT("AWispsGameModeBase"), &Z_Registration_Info_UClass_AWispsGameModeBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AWispsGameModeBase), 1100264557U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_CoreModules_WispsGameModeBase_h__Script_WispCPP7VR_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_CoreModules_WispsGameModeBase_h__Script_WispCPP7VR_3457610537{
	TEXT("/Script/WispCPP7VR"),
	Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_CoreModules_WispsGameModeBase_h__Script_WispCPP7VR_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_CoreModules_WispsGameModeBase_h__Script_WispCPP7VR_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
