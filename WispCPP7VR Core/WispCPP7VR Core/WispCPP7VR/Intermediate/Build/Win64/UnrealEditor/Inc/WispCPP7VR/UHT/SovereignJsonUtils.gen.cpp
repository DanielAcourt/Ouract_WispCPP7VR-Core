// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SaveSystem/SovereignJsonUtils.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSovereignJsonUtils() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
UPackage* Z_Construct_UPackage__Script_WispCPP7VR();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignJsonUtils();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignJsonUtils_NoRegister();
// ********** End Cross Module References **********************************************************

// ********** Begin Class USovereignJsonUtils Function LoadStringFromFile **************************
struct Z_Construct_UFunction_USovereignJsonUtils_LoadStringFromFile_Statics
{
	struct SovereignJsonUtils_eventLoadStringFromFile_Parms
	{
		FString FileName;
		FString OutContent;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|SaveSystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** * /** * WHY: To bring Player's garden back to life. \n     * WHAT: Finds a file by name and reads the text inside back into a string \n     * that our JSON parser can understand.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignJsonUtils.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* WHY: To bring Player's garden back to life.\nWHAT: Finds a file by name and reads the text inside back into a string\nthat our JSON parser can understand." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function LoadStringFromFile constinit property declarations ********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_FileName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_OutContent;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function LoadStringFromFile constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function LoadStringFromFile Property Definitions *******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USovereignJsonUtils_LoadStringFromFile_Statics::NewProp_FileName = { "FileName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignJsonUtils_eventLoadStringFromFile_Parms, FileName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USovereignJsonUtils_LoadStringFromFile_Statics::NewProp_OutContent = { "OutContent", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignJsonUtils_eventLoadStringFromFile_Parms, OutContent), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_USovereignJsonUtils_LoadStringFromFile_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((SovereignJsonUtils_eventLoadStringFromFile_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USovereignJsonUtils_LoadStringFromFile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SovereignJsonUtils_eventLoadStringFromFile_Parms), &Z_Construct_UFunction_USovereignJsonUtils_LoadStringFromFile_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USovereignJsonUtils_LoadStringFromFile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignJsonUtils_LoadStringFromFile_Statics::NewProp_FileName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignJsonUtils_LoadStringFromFile_Statics::NewProp_OutContent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignJsonUtils_LoadStringFromFile_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignJsonUtils_LoadStringFromFile_Statics::PropPointers) < 2048);
// ********** End Function LoadStringFromFile Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USovereignJsonUtils_LoadStringFromFile_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USovereignJsonUtils, nullptr, "LoadStringFromFile", 	Z_Construct_UFunction_USovereignJsonUtils_LoadStringFromFile_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignJsonUtils_LoadStringFromFile_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USovereignJsonUtils_LoadStringFromFile_Statics::SovereignJsonUtils_eventLoadStringFromFile_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignJsonUtils_LoadStringFromFile_Statics::Function_MetaDataParams), Z_Construct_UFunction_USovereignJsonUtils_LoadStringFromFile_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USovereignJsonUtils_LoadStringFromFile_Statics::SovereignJsonUtils_eventLoadStringFromFile_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USovereignJsonUtils_LoadStringFromFile()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USovereignJsonUtils_LoadStringFromFile_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USovereignJsonUtils::execLoadStringFromFile)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_FileName);
	P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_OutContent);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=USovereignJsonUtils::LoadStringFromFile(Z_Param_FileName,Z_Param_Out_OutContent);
	P_NATIVE_END;
}
// ********** End Class USovereignJsonUtils Function LoadStringFromFile ****************************

// ********** Begin Class USovereignJsonUtils Function SaveStringToFile ****************************
struct Z_Construct_UFunction_USovereignJsonUtils_SaveStringToFile_Statics
{
	struct SovereignJsonUtils_eventSaveStringToFile_Parms
	{
		FString FileName;
		FString Content;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|SaveSystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** * WHY: The \"Workhorse\" of the system.\n       * WHAT: Takes raw text (JSON) and pushes it to the hard drive.\n       * It handles the file pathing and folder creation automatically.\n       */" },
#endif
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignJsonUtils.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "WHY: The \"Workhorse\" of the system.\nWHAT: Takes raw text (JSON) and pushes it to the hard drive.\nIt handles the file pathing and folder creation automatically." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SaveStringToFile constinit property declarations **********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_FileName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Content;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SaveStringToFile constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SaveStringToFile Property Definitions *********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USovereignJsonUtils_SaveStringToFile_Statics::NewProp_FileName = { "FileName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignJsonUtils_eventSaveStringToFile_Parms, FileName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USovereignJsonUtils_SaveStringToFile_Statics::NewProp_Content = { "Content", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignJsonUtils_eventSaveStringToFile_Parms, Content), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_USovereignJsonUtils_SaveStringToFile_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((SovereignJsonUtils_eventSaveStringToFile_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USovereignJsonUtils_SaveStringToFile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SovereignJsonUtils_eventSaveStringToFile_Parms), &Z_Construct_UFunction_USovereignJsonUtils_SaveStringToFile_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USovereignJsonUtils_SaveStringToFile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignJsonUtils_SaveStringToFile_Statics::NewProp_FileName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignJsonUtils_SaveStringToFile_Statics::NewProp_Content,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignJsonUtils_SaveStringToFile_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignJsonUtils_SaveStringToFile_Statics::PropPointers) < 2048);
// ********** End Function SaveStringToFile Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USovereignJsonUtils_SaveStringToFile_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USovereignJsonUtils, nullptr, "SaveStringToFile", 	Z_Construct_UFunction_USovereignJsonUtils_SaveStringToFile_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignJsonUtils_SaveStringToFile_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USovereignJsonUtils_SaveStringToFile_Statics::SovereignJsonUtils_eventSaveStringToFile_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignJsonUtils_SaveStringToFile_Statics::Function_MetaDataParams), Z_Construct_UFunction_USovereignJsonUtils_SaveStringToFile_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USovereignJsonUtils_SaveStringToFile_Statics::SovereignJsonUtils_eventSaveStringToFile_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USovereignJsonUtils_SaveStringToFile()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USovereignJsonUtils_SaveStringToFile_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USovereignJsonUtils::execSaveStringToFile)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_FileName);
	P_GET_PROPERTY(FStrProperty,Z_Param_Content);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=USovereignJsonUtils::SaveStringToFile(Z_Param_FileName,Z_Param_Content);
	P_NATIVE_END;
}
// ********** End Class USovereignJsonUtils Function SaveStringToFile ******************************

// ********** Begin Class USovereignJsonUtils Function ValidateAndSave *****************************
struct Z_Construct_UFunction_USovereignJsonUtils_ValidateAndSave_Statics
{
	struct SovereignJsonUtils_eventValidateAndSave_Parms
	{
		FString FileName;
		FString Content;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|SaveSystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** * /** * WHY: Handles [2025-12-20] requirement for \"Unknown Tags.\"\n     * WHAT: Takes a flexible C++ Map (Key/Value pairs) and turns it into a \n     * structured JSON object that can be saved.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignJsonUtils.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* WHY: Handles [2025-12-20] requirement for \"Unknown Tags.\"\nWHAT: Takes a flexible C++ Map (Key/Value pairs) and turns it into a\nstructured JSON object that can be saved." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ValidateAndSave constinit property declarations ***********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_FileName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Content;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ValidateAndSave constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ValidateAndSave Property Definitions **********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USovereignJsonUtils_ValidateAndSave_Statics::NewProp_FileName = { "FileName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignJsonUtils_eventValidateAndSave_Parms, FileName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USovereignJsonUtils_ValidateAndSave_Statics::NewProp_Content = { "Content", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignJsonUtils_eventValidateAndSave_Parms, Content), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_USovereignJsonUtils_ValidateAndSave_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((SovereignJsonUtils_eventValidateAndSave_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USovereignJsonUtils_ValidateAndSave_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SovereignJsonUtils_eventValidateAndSave_Parms), &Z_Construct_UFunction_USovereignJsonUtils_ValidateAndSave_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USovereignJsonUtils_ValidateAndSave_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignJsonUtils_ValidateAndSave_Statics::NewProp_FileName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignJsonUtils_ValidateAndSave_Statics::NewProp_Content,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignJsonUtils_ValidateAndSave_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignJsonUtils_ValidateAndSave_Statics::PropPointers) < 2048);
// ********** End Function ValidateAndSave Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USovereignJsonUtils_ValidateAndSave_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USovereignJsonUtils, nullptr, "ValidateAndSave", 	Z_Construct_UFunction_USovereignJsonUtils_ValidateAndSave_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignJsonUtils_ValidateAndSave_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USovereignJsonUtils_ValidateAndSave_Statics::SovereignJsonUtils_eventValidateAndSave_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignJsonUtils_ValidateAndSave_Statics::Function_MetaDataParams), Z_Construct_UFunction_USovereignJsonUtils_ValidateAndSave_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USovereignJsonUtils_ValidateAndSave_Statics::SovereignJsonUtils_eventValidateAndSave_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USovereignJsonUtils_ValidateAndSave()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USovereignJsonUtils_ValidateAndSave_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USovereignJsonUtils::execValidateAndSave)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_FileName);
	P_GET_PROPERTY(FStrProperty,Z_Param_Content);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=USovereignJsonUtils::ValidateAndSave(Z_Param_FileName,Z_Param_Content);
	P_NATIVE_END;
}
// ********** End Class USovereignJsonUtils Function ValidateAndSave *******************************

// ********** Begin Class USovereignJsonUtils ******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_USovereignJsonUtils;
UClass* USovereignJsonUtils::GetPrivateStaticClass()
{
	using TClass = USovereignJsonUtils;
	if (!Z_Registration_Info_UClass_USovereignJsonUtils.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SovereignJsonUtils"),
			Z_Registration_Info_UClass_USovereignJsonUtils.InnerSingleton,
			StaticRegisterNativesUSovereignJsonUtils,
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
	return Z_Registration_Info_UClass_USovereignJsonUtils.InnerSingleton;
}
UClass* Z_Construct_UClass_USovereignJsonUtils_NoRegister()
{
	return USovereignJsonUtils::GetPrivateStaticClass();
}
struct Z_Construct_UClass_USovereignJsonUtils_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n* @class USovereignJsonUtils\n* @brief Global utility for serializing ABaseEntity data and file I / O.\n*/" },
#endif
		{ "IncludePath", "SaveSystem/SovereignJsonUtils.h" },
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignJsonUtils.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@class USovereignJsonUtils\n@brief Global utility for serializing ABaseEntity data and file I / O." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class USovereignJsonUtils constinit property declarations **********************
// ********** End Class USovereignJsonUtils constinit property declarations ************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("LoadStringFromFile"), .Pointer = &USovereignJsonUtils::execLoadStringFromFile },
		{ .NameUTF8 = UTF8TEXT("SaveStringToFile"), .Pointer = &USovereignJsonUtils::execSaveStringToFile },
		{ .NameUTF8 = UTF8TEXT("ValidateAndSave"), .Pointer = &USovereignJsonUtils::execValidateAndSave },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_USovereignJsonUtils_LoadStringFromFile, "LoadStringFromFile" }, // 2779751803
		{ &Z_Construct_UFunction_USovereignJsonUtils_SaveStringToFile, "SaveStringToFile" }, // 205597602
		{ &Z_Construct_UFunction_USovereignJsonUtils_ValidateAndSave, "ValidateAndSave" }, // 2336105283
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USovereignJsonUtils>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_USovereignJsonUtils_Statics
UObject* (*const Z_Construct_UClass_USovereignJsonUtils_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_WispCPP7VR,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USovereignJsonUtils_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USovereignJsonUtils_Statics::ClassParams = {
	&USovereignJsonUtils::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USovereignJsonUtils_Statics::Class_MetaDataParams), Z_Construct_UClass_USovereignJsonUtils_Statics::Class_MetaDataParams)
};
void USovereignJsonUtils::StaticRegisterNativesUSovereignJsonUtils()
{
	UClass* Class = USovereignJsonUtils::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_USovereignJsonUtils_Statics::Funcs));
}
UClass* Z_Construct_UClass_USovereignJsonUtils()
{
	if (!Z_Registration_Info_UClass_USovereignJsonUtils.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USovereignJsonUtils.OuterSingleton, Z_Construct_UClass_USovereignJsonUtils_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USovereignJsonUtils.OuterSingleton;
}
USovereignJsonUtils::USovereignJsonUtils(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, USovereignJsonUtils);
USovereignJsonUtils::~USovereignJsonUtils() {}
// ********** End Class USovereignJsonUtils ********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_SaveSystem_SovereignJsonUtils_h__Script_WispCPP7VR_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_USovereignJsonUtils, USovereignJsonUtils::StaticClass, TEXT("USovereignJsonUtils"), &Z_Registration_Info_UClass_USovereignJsonUtils, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USovereignJsonUtils), 1475340987U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_SaveSystem_SovereignJsonUtils_h__Script_WispCPP7VR_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_SaveSystem_SovereignJsonUtils_h__Script_WispCPP7VR_2530706067{
	TEXT("/Script/WispCPP7VR"),
	Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_SaveSystem_SovereignJsonUtils_h__Script_WispCPP7VR_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_SaveSystem_SovereignJsonUtils_h__Script_WispCPP7VR_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
