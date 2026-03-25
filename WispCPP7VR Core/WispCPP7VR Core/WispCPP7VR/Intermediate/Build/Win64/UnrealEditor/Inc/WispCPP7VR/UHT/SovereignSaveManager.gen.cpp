// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SaveSystem/SovereignSaveManager.h"
#include "Engine/GameInstance.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSovereignSaveManager() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
UPackage* Z_Construct_UPackage__Script_WispCPP7VR();
WISPCPP7VR_API UClass* Z_Construct_UClass_USaveManager();
WISPCPP7VR_API UClass* Z_Construct_UClass_USaveManager_NoRegister();
// ********** End Cross Module References **********************************************************

// ********** Begin Class USaveManager Function GetSavedEntityCount ********************************
struct Z_Construct_UFunction_USaveManager_GetSavedEntityCount_Statics
{
	struct SaveManager_eventGetSavedEntityCount_Parms
	{
		FString SlotName;
		bool bIsJson;
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|SaveSystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** * Peeks into a save slot and returns the number of entities stored within.\n * Does NOT spawn or change the world state.\n */" },
#endif
		{ "CPP_Default_bIsJson", "true" },
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignSaveManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Peeks into a save slot and returns the number of entities stored within.\nDoes NOT spawn or change the world state." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetSavedEntityCount constinit property declarations *******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_SlotName;
	static void NewProp_bIsJson_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsJson;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSavedEntityCount constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSavedEntityCount Property Definitions ******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USaveManager_GetSavedEntityCount_Statics::NewProp_SlotName = { "SlotName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SaveManager_eventGetSavedEntityCount_Parms, SlotName), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_USaveManager_GetSavedEntityCount_Statics::NewProp_bIsJson_SetBit(void* Obj)
{
	((SaveManager_eventGetSavedEntityCount_Parms*)Obj)->bIsJson = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USaveManager_GetSavedEntityCount_Statics::NewProp_bIsJson = { "bIsJson", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SaveManager_eventGetSavedEntityCount_Parms), &Z_Construct_UFunction_USaveManager_GetSavedEntityCount_Statics::NewProp_bIsJson_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USaveManager_GetSavedEntityCount_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SaveManager_eventGetSavedEntityCount_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USaveManager_GetSavedEntityCount_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USaveManager_GetSavedEntityCount_Statics::NewProp_SlotName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USaveManager_GetSavedEntityCount_Statics::NewProp_bIsJson,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USaveManager_GetSavedEntityCount_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USaveManager_GetSavedEntityCount_Statics::PropPointers) < 2048);
// ********** End Function GetSavedEntityCount Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USaveManager_GetSavedEntityCount_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USaveManager, nullptr, "GetSavedEntityCount", 	Z_Construct_UFunction_USaveManager_GetSavedEntityCount_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USaveManager_GetSavedEntityCount_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USaveManager_GetSavedEntityCount_Statics::SaveManager_eventGetSavedEntityCount_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USaveManager_GetSavedEntityCount_Statics::Function_MetaDataParams), Z_Construct_UFunction_USaveManager_GetSavedEntityCount_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USaveManager_GetSavedEntityCount_Statics::SaveManager_eventGetSavedEntityCount_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USaveManager_GetSavedEntityCount()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USaveManager_GetSavedEntityCount_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USaveManager::execGetSavedEntityCount)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_SlotName);
	P_GET_UBOOL(Z_Param_bIsJson);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetSavedEntityCount(Z_Param_SlotName,Z_Param_bIsJson);
	P_NATIVE_END;
}
// ********** End Class USaveManager Function GetSavedEntityCount **********************************

// ********** Begin Class USaveManager Function LoadWorldState *************************************
struct Z_Construct_UFunction_USaveManager_LoadWorldState_Statics
{
	struct SaveManager_eventLoadWorldState_Parms
	{
		FString SlotName;
		bool bAsJson;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|SaveSystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** * @param SlotName File name\n     * @param bAsJson If true, looks for .json. If false, looks for .sav\n     */" },
#endif
		{ "CPP_Default_bAsJson", "true" },
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignSaveManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@param SlotName File name\n@param bAsJson If true, looks for .json. If false, looks for .sav" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function LoadWorldState constinit property declarations ************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_SlotName;
	static void NewProp_bAsJson_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAsJson;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function LoadWorldState constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function LoadWorldState Property Definitions ***********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USaveManager_LoadWorldState_Statics::NewProp_SlotName = { "SlotName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SaveManager_eventLoadWorldState_Parms, SlotName), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_USaveManager_LoadWorldState_Statics::NewProp_bAsJson_SetBit(void* Obj)
{
	((SaveManager_eventLoadWorldState_Parms*)Obj)->bAsJson = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USaveManager_LoadWorldState_Statics::NewProp_bAsJson = { "bAsJson", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SaveManager_eventLoadWorldState_Parms), &Z_Construct_UFunction_USaveManager_LoadWorldState_Statics::NewProp_bAsJson_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USaveManager_LoadWorldState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USaveManager_LoadWorldState_Statics::NewProp_SlotName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USaveManager_LoadWorldState_Statics::NewProp_bAsJson,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USaveManager_LoadWorldState_Statics::PropPointers) < 2048);
// ********** End Function LoadWorldState Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USaveManager_LoadWorldState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USaveManager, nullptr, "LoadWorldState", 	Z_Construct_UFunction_USaveManager_LoadWorldState_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USaveManager_LoadWorldState_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USaveManager_LoadWorldState_Statics::SaveManager_eventLoadWorldState_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USaveManager_LoadWorldState_Statics::Function_MetaDataParams), Z_Construct_UFunction_USaveManager_LoadWorldState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USaveManager_LoadWorldState_Statics::SaveManager_eventLoadWorldState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USaveManager_LoadWorldState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USaveManager_LoadWorldState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USaveManager::execLoadWorldState)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_SlotName);
	P_GET_UBOOL(Z_Param_bAsJson);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->LoadWorldState(Z_Param_SlotName,Z_Param_bAsJson);
	P_NATIVE_END;
}
// ********** End Class USaveManager Function LoadWorldState ***************************************

// ********** Begin Class USaveManager Function SaveWorldState *************************************
struct Z_Construct_UFunction_USaveManager_SaveWorldState_Statics
{
	struct SaveManager_eventSaveWorldState_Parms
	{
		FString SlotName;
		bool bAsJson;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|SaveSystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** * @param SlotName File name\n         * @param bAsJson If true, writes a readable .json. If false, writes a binary .sav\n         */" },
#endif
		{ "CPP_Default_bAsJson", "true" },
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignSaveManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@param SlotName File name\n@param bAsJson If true, writes a readable .json. If false, writes a binary .sav" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SaveWorldState constinit property declarations ************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_SlotName;
	static void NewProp_bAsJson_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAsJson;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SaveWorldState constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SaveWorldState Property Definitions ***********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USaveManager_SaveWorldState_Statics::NewProp_SlotName = { "SlotName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SaveManager_eventSaveWorldState_Parms, SlotName), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_USaveManager_SaveWorldState_Statics::NewProp_bAsJson_SetBit(void* Obj)
{
	((SaveManager_eventSaveWorldState_Parms*)Obj)->bAsJson = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USaveManager_SaveWorldState_Statics::NewProp_bAsJson = { "bAsJson", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SaveManager_eventSaveWorldState_Parms), &Z_Construct_UFunction_USaveManager_SaveWorldState_Statics::NewProp_bAsJson_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USaveManager_SaveWorldState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USaveManager_SaveWorldState_Statics::NewProp_SlotName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USaveManager_SaveWorldState_Statics::NewProp_bAsJson,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USaveManager_SaveWorldState_Statics::PropPointers) < 2048);
// ********** End Function SaveWorldState Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USaveManager_SaveWorldState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USaveManager, nullptr, "SaveWorldState", 	Z_Construct_UFunction_USaveManager_SaveWorldState_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USaveManager_SaveWorldState_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USaveManager_SaveWorldState_Statics::SaveManager_eventSaveWorldState_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USaveManager_SaveWorldState_Statics::Function_MetaDataParams), Z_Construct_UFunction_USaveManager_SaveWorldState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USaveManager_SaveWorldState_Statics::SaveManager_eventSaveWorldState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USaveManager_SaveWorldState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USaveManager_SaveWorldState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USaveManager::execSaveWorldState)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_SlotName);
	P_GET_UBOOL(Z_Param_bAsJson);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SaveWorldState(Z_Param_SlotName,Z_Param_bAsJson);
	P_NATIVE_END;
}
// ********** End Class USaveManager Function SaveWorldState ***************************************

// ********** Begin Class USaveManager *************************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_USaveManager;
UClass* USaveManager::GetPrivateStaticClass()
{
	using TClass = USaveManager;
	if (!Z_Registration_Info_UClass_USaveManager.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SaveManager"),
			Z_Registration_Info_UClass_USaveManager.InnerSingleton,
			StaticRegisterNativesUSaveManager,
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
	return Z_Registration_Info_UClass_USaveManager.InnerSingleton;
}
UClass* Z_Construct_UClass_USaveManager_NoRegister()
{
	return USaveManager::GetPrivateStaticClass();
}
struct Z_Construct_UClass_USaveManager_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "SaveSystem/SovereignSaveManager.h" },
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignSaveManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUseJsonByDefault_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Sovereign|Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Acts as switch between saving to a json file or saving to unreal default uSavegameobject Binary system\n" },
#endif
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignSaveManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Acts as switch between saving to a json file or saving to unreal default uSavegameobject Binary system" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class USaveManager constinit property declarations *****************************
	static void NewProp_bUseJsonByDefault_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseJsonByDefault;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class USaveManager constinit property declarations *******************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetSavedEntityCount"), .Pointer = &USaveManager::execGetSavedEntityCount },
		{ .NameUTF8 = UTF8TEXT("LoadWorldState"), .Pointer = &USaveManager::execLoadWorldState },
		{ .NameUTF8 = UTF8TEXT("SaveWorldState"), .Pointer = &USaveManager::execSaveWorldState },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_USaveManager_GetSavedEntityCount, "GetSavedEntityCount" }, // 3452078706
		{ &Z_Construct_UFunction_USaveManager_LoadWorldState, "LoadWorldState" }, // 2120352203
		{ &Z_Construct_UFunction_USaveManager_SaveWorldState, "SaveWorldState" }, // 823131302
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USaveManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_USaveManager_Statics

// ********** Begin Class USaveManager Property Definitions ****************************************
void Z_Construct_UClass_USaveManager_Statics::NewProp_bUseJsonByDefault_SetBit(void* Obj)
{
	((USaveManager*)Obj)->bUseJsonByDefault = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USaveManager_Statics::NewProp_bUseJsonByDefault = { "bUseJsonByDefault", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(USaveManager), &Z_Construct_UClass_USaveManager_Statics::NewProp_bUseJsonByDefault_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUseJsonByDefault_MetaData), NewProp_bUseJsonByDefault_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USaveManager_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USaveManager_Statics::NewProp_bUseJsonByDefault,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USaveManager_Statics::PropPointers) < 2048);
// ********** End Class USaveManager Property Definitions ******************************************
UObject* (*const Z_Construct_UClass_USaveManager_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_WispCPP7VR,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USaveManager_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USaveManager_Statics::ClassParams = {
	&USaveManager::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_USaveManager_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_USaveManager_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USaveManager_Statics::Class_MetaDataParams), Z_Construct_UClass_USaveManager_Statics::Class_MetaDataParams)
};
void USaveManager::StaticRegisterNativesUSaveManager()
{
	UClass* Class = USaveManager::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_USaveManager_Statics::Funcs));
}
UClass* Z_Construct_UClass_USaveManager()
{
	if (!Z_Registration_Info_UClass_USaveManager.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USaveManager.OuterSingleton, Z_Construct_UClass_USaveManager_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USaveManager.OuterSingleton;
}
USaveManager::USaveManager() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, USaveManager);
USaveManager::~USaveManager() {}
// ********** End Class USaveManager ***************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_SaveSystem_SovereignSaveManager_h__Script_WispCPP7VR_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_USaveManager, USaveManager::StaticClass, TEXT("USaveManager"), &Z_Registration_Info_UClass_USaveManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USaveManager), 1352182876U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_SaveSystem_SovereignSaveManager_h__Script_WispCPP7VR_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_SaveSystem_SovereignSaveManager_h__Script_WispCPP7VR_307204607{
	TEXT("/Script/WispCPP7VR"),
	Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_SaveSystem_SovereignSaveManager_h__Script_WispCPP7VR_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_SaveSystem_SovereignSaveManager_h__Script_WispCPP7VR_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
