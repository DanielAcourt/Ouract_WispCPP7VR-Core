// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SaveSystem/SovereignSaveGame.h"
#include "SaveSystem/SovereignGameData.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSovereignSaveGame() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FDateTime();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
ENGINE_API UClass* Z_Construct_UClass_USaveGame();
UPackage* Z_Construct_UPackage__Script_WispCPP7VR();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignSaveGame();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignSaveGame_NoRegister();
WISPCPP7VR_API UScriptStruct* Z_Construct_UScriptStruct_FEntitySaveData();
WISPCPP7VR_API UScriptStruct* Z_Construct_UScriptStruct_FSovereignActorData();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FSovereignActorData ***********************************************
struct Z_Construct_UScriptStruct_FSovereignActorData_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FSovereignActorData); }
	static inline consteval int16 GetStructAlignment() { return alignof(FSovereignActorData); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignSaveGame.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EntityID_MetaData[] = {
		{ "Category", "Sovereign" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// The unique ID we generated in the Component\n" },
#endif
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignSaveGame.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The unique ID we generated in the Component" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClassPath_MetaData[] = {
		{ "Category", "Sovereign" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// The blueprint path so we can respawn this object if it's missing\n" },
#endif
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignSaveGame.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The blueprint path so we can respawn this object if it's missing" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MetaTags_MetaData[] = {
		{ "Category", "Sovereign" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// The \"Unknown Tags\" we harvested (e.g., \"GrowthStage:5\")\n" },
#endif
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignSaveGame.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The \"Unknown Tags\" we harvested (e.g., \"GrowthStage:5\")" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Transform_MetaData[] = {
		{ "Category", "Sovereign" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// The physical location/rotation in the world\n" },
#endif
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignSaveGame.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The physical location/rotation in the world" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FSovereignActorData constinit property declarations ***************
	static const UECodeGen_Private::FStructPropertyParams NewProp_EntityID;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ClassPath;
	static const UECodeGen_Private::FStrPropertyParams NewProp_MetaTags_ValueProp;
	static const UECodeGen_Private::FStrPropertyParams NewProp_MetaTags_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_MetaTags;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Transform;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FSovereignActorData constinit property declarations *****************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSovereignActorData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FSovereignActorData_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FSovereignActorData;
class UScriptStruct* FSovereignActorData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FSovereignActorData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FSovereignActorData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSovereignActorData, (UObject*)Z_Construct_UPackage__Script_WispCPP7VR(), TEXT("SovereignActorData"));
	}
	return Z_Registration_Info_UScriptStruct_FSovereignActorData.OuterSingleton;
	}

// ********** Begin ScriptStruct FSovereignActorData Property Definitions **************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSovereignActorData_Statics::NewProp_EntityID = { "EntityID", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSovereignActorData, EntityID), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EntityID_MetaData), NewProp_EntityID_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSovereignActorData_Statics::NewProp_ClassPath = { "ClassPath", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSovereignActorData, ClassPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClassPath_MetaData), NewProp_ClassPath_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSovereignActorData_Statics::NewProp_MetaTags_ValueProp = { "MetaTags", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSovereignActorData_Statics::NewProp_MetaTags_Key_KeyProp = { "MetaTags_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UScriptStruct_FSovereignActorData_Statics::NewProp_MetaTags = { "MetaTags", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSovereignActorData, MetaTags), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MetaTags_MetaData), NewProp_MetaTags_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSovereignActorData_Statics::NewProp_Transform = { "Transform", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSovereignActorData, Transform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Transform_MetaData), NewProp_Transform_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSovereignActorData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSovereignActorData_Statics::NewProp_EntityID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSovereignActorData_Statics::NewProp_ClassPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSovereignActorData_Statics::NewProp_MetaTags_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSovereignActorData_Statics::NewProp_MetaTags_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSovereignActorData_Statics::NewProp_MetaTags,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSovereignActorData_Statics::NewProp_Transform,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSovereignActorData_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FSovereignActorData Property Definitions ****************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSovereignActorData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_WispCPP7VR,
	nullptr,
	&NewStructOps,
	"SovereignActorData",
	Z_Construct_UScriptStruct_FSovereignActorData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSovereignActorData_Statics::PropPointers),
	sizeof(FSovereignActorData),
	alignof(FSovereignActorData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSovereignActorData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSovereignActorData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FSovereignActorData()
{
	if (!Z_Registration_Info_UScriptStruct_FSovereignActorData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FSovereignActorData.InnerSingleton, Z_Construct_UScriptStruct_FSovereignActorData_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FSovereignActorData.InnerSingleton);
}
// ********** End ScriptStruct FSovereignActorData *************************************************

// ********** Begin Class USovereignSaveGame *******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_USovereignSaveGame;
UClass* USovereignSaveGame::GetPrivateStaticClass()
{
	using TClass = USovereignSaveGame;
	if (!Z_Registration_Info_UClass_USovereignSaveGame.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SovereignSaveGame"),
			Z_Registration_Info_UClass_USovereignSaveGame.InnerSingleton,
			StaticRegisterNativesUSovereignSaveGame,
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
	return Z_Registration_Info_UClass_USovereignSaveGame.InnerSingleton;
}
UClass* Z_Construct_UClass_USovereignSaveGame_NoRegister()
{
	return USovereignSaveGame::GetPrivateStaticClass();
}
struct Z_Construct_UClass_USovereignSaveGame_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n  * @class USovereignSaveGame\n  * @brief The \"Suitcase\" file that gets written to the hard drive.\n  */" },
#endif
		{ "IncludePath", "SaveSystem/SovereignSaveGame.h" },
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignSaveGame.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@class USovereignSaveGame\n@brief The \"Suitcase\" file that gets written to the hard drive." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SavedActors_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// The master list of every saved entity in the world\n" },
#endif
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignSaveGame.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The master list of every saved entity in the world" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SaveSlotName_MetaData[] = {
		{ "Category", "Sovereign" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// High-level metadata (Optional but helpful for Isla)\n" },
#endif
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignSaveGame.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "High-level metadata (Optional but helpful for Isla)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SaveTime_MetaData[] = {
		{ "Category", "Sovereign" },
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignSaveGame.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class USovereignSaveGame constinit property declarations ***********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_SavedActors_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_SavedActors;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SaveSlotName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SaveTime;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class USovereignSaveGame constinit property declarations *************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USovereignSaveGame>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_USovereignSaveGame_Statics

// ********** Begin Class USovereignSaveGame Property Definitions **********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USovereignSaveGame_Statics::NewProp_SavedActors_Inner = { "SavedActors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FEntitySaveData, METADATA_PARAMS(0, nullptr) }; // 508845134
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_USovereignSaveGame_Statics::NewProp_SavedActors = { "SavedActors", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignSaveGame, SavedActors), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SavedActors_MetaData), NewProp_SavedActors_MetaData) }; // 508845134
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_USovereignSaveGame_Statics::NewProp_SaveSlotName = { "SaveSlotName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignSaveGame, SaveSlotName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SaveSlotName_MetaData), NewProp_SaveSlotName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USovereignSaveGame_Statics::NewProp_SaveTime = { "SaveTime", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignSaveGame, SaveTime), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SaveTime_MetaData), NewProp_SaveTime_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USovereignSaveGame_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignSaveGame_Statics::NewProp_SavedActors_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignSaveGame_Statics::NewProp_SavedActors,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignSaveGame_Statics::NewProp_SaveSlotName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignSaveGame_Statics::NewProp_SaveTime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USovereignSaveGame_Statics::PropPointers) < 2048);
// ********** End Class USovereignSaveGame Property Definitions ************************************
UObject* (*const Z_Construct_UClass_USovereignSaveGame_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_USaveGame,
	(UObject* (*)())Z_Construct_UPackage__Script_WispCPP7VR,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USovereignSaveGame_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USovereignSaveGame_Statics::ClassParams = {
	&USovereignSaveGame::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_USovereignSaveGame_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_USovereignSaveGame_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USovereignSaveGame_Statics::Class_MetaDataParams), Z_Construct_UClass_USovereignSaveGame_Statics::Class_MetaDataParams)
};
void USovereignSaveGame::StaticRegisterNativesUSovereignSaveGame()
{
}
UClass* Z_Construct_UClass_USovereignSaveGame()
{
	if (!Z_Registration_Info_UClass_USovereignSaveGame.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USovereignSaveGame.OuterSingleton, Z_Construct_UClass_USovereignSaveGame_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USovereignSaveGame.OuterSingleton;
}
USovereignSaveGame::USovereignSaveGame(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, USovereignSaveGame);
USovereignSaveGame::~USovereignSaveGame() {}
// ********** End Class USovereignSaveGame *********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_SaveSystem_SovereignSaveGame_h__Script_WispCPP7VR_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FSovereignActorData::StaticStruct, Z_Construct_UScriptStruct_FSovereignActorData_Statics::NewStructOps, TEXT("SovereignActorData"),&Z_Registration_Info_UScriptStruct_FSovereignActorData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSovereignActorData), 1273195180U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_USovereignSaveGame, USovereignSaveGame::StaticClass, TEXT("USovereignSaveGame"), &Z_Registration_Info_UClass_USovereignSaveGame, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USovereignSaveGame), 2752099106U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_SaveSystem_SovereignSaveGame_h__Script_WispCPP7VR_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_SaveSystem_SovereignSaveGame_h__Script_WispCPP7VR_1077741743{
	TEXT("/Script/WispCPP7VR"),
	Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_SaveSystem_SovereignSaveGame_h__Script_WispCPP7VR_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_SaveSystem_SovereignSaveGame_h__Script_WispCPP7VR_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_SaveSystem_SovereignSaveGame_h__Script_WispCPP7VR_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_SaveSystem_SovereignSaveGame_h__Script_WispCPP7VR_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
