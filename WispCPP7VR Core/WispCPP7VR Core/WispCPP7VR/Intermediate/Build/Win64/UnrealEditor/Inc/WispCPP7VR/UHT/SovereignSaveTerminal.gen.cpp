// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Entities/SovereignSaveTerminal.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSovereignSaveTerminal() {}

// ********** Begin Cross Module References ********************************************************
UPackage* Z_Construct_UPackage__Script_WispCPP7VR();
WISPCPP7VR_API UClass* Z_Construct_UClass_ASovereignBaseInteractable();
WISPCPP7VR_API UClass* Z_Construct_UClass_ASovereignSaveTerminal();
WISPCPP7VR_API UClass* Z_Construct_UClass_ASovereignSaveTerminal_NoRegister();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ASovereignSaveTerminal Function Editor_RefreshSavedCount *****************
struct Z_Construct_UFunction_ASovereignSaveTerminal_Editor_RefreshSavedCount_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Sovereign|Debug" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** * Peeks into the save file and updates the displayed count\n     * without actually spawning or changing anything in the garden.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignSaveTerminal.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Peeks into the save file and updates the displayed count\nwithout actually spawning or changing anything in the garden." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function Editor_RefreshSavedCount constinit property declarations **************
// ********** End Function Editor_RefreshSavedCount constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASovereignSaveTerminal_Editor_RefreshSavedCount_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ASovereignSaveTerminal, nullptr, "Editor_RefreshSavedCount", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASovereignSaveTerminal_Editor_RefreshSavedCount_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASovereignSaveTerminal_Editor_RefreshSavedCount_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_ASovereignSaveTerminal_Editor_RefreshSavedCount()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASovereignSaveTerminal_Editor_RefreshSavedCount_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASovereignSaveTerminal::execEditor_RefreshSavedCount)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Editor_RefreshSavedCount();
	P_NATIVE_END;
}
// ********** End Class ASovereignSaveTerminal Function Editor_RefreshSavedCount *******************

// ********** Begin Class ASovereignSaveTerminal Function Editor_TriggerLoad ***********************
struct Z_Construct_UFunction_ASovereignSaveTerminal_Editor_TriggerLoad_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Sovereign|Debug" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// NEW: The Load Button for the Editor\n" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignSaveTerminal.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "NEW: The Load Button for the Editor" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function Editor_TriggerLoad constinit property declarations ********************
// ********** End Function Editor_TriggerLoad constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASovereignSaveTerminal_Editor_TriggerLoad_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ASovereignSaveTerminal, nullptr, "Editor_TriggerLoad", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASovereignSaveTerminal_Editor_TriggerLoad_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASovereignSaveTerminal_Editor_TriggerLoad_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_ASovereignSaveTerminal_Editor_TriggerLoad()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASovereignSaveTerminal_Editor_TriggerLoad_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASovereignSaveTerminal::execEditor_TriggerLoad)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Editor_TriggerLoad();
	P_NATIVE_END;
}
// ********** End Class ASovereignSaveTerminal Function Editor_TriggerLoad *************************

// ********** Begin Class ASovereignSaveTerminal Function Editor_TriggerSave ***********************
struct Z_Construct_UFunction_ASovereignSaveTerminal_Editor_TriggerSave_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Sovereign|Debug" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** * Bakes the current world state to a file immediately.\n     * This creates a button in the Editor Details panel!\n     * These ideally need to be editor only or deleted later\n     */" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignSaveTerminal.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Bakes the current world state to a file immediately.\nThis creates a button in the Editor Details panel!\nThese ideally need to be editor only or deleted later" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function Editor_TriggerSave constinit property declarations ********************
// ********** End Function Editor_TriggerSave constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASovereignSaveTerminal_Editor_TriggerSave_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ASovereignSaveTerminal, nullptr, "Editor_TriggerSave", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASovereignSaveTerminal_Editor_TriggerSave_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASovereignSaveTerminal_Editor_TriggerSave_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_ASovereignSaveTerminal_Editor_TriggerSave()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASovereignSaveTerminal_Editor_TriggerSave_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASovereignSaveTerminal::execEditor_TriggerSave)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Editor_TriggerSave();
	P_NATIVE_END;
}
// ********** End Class ASovereignSaveTerminal Function Editor_TriggerSave *************************

// ********** Begin Class ASovereignSaveTerminal ***************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_ASovereignSaveTerminal;
UClass* ASovereignSaveTerminal::GetPrivateStaticClass()
{
	using TClass = ASovereignSaveTerminal;
	if (!Z_Registration_Info_UClass_ASovereignSaveTerminal.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SovereignSaveTerminal"),
			Z_Registration_Info_UClass_ASovereignSaveTerminal.InnerSingleton,
			StaticRegisterNativesASovereignSaveTerminal,
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
	return Z_Registration_Info_UClass_ASovereignSaveTerminal.InnerSingleton;
}
UClass* Z_Construct_UClass_ASovereignSaveTerminal_NoRegister()
{
	return ASovereignSaveTerminal::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ASovereignSaveTerminal_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Entities/SovereignSaveTerminal.h" },
		{ "ModuleRelativePath", "Public/Entities/SovereignSaveTerminal.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetSlotName_MetaData[] = {
		{ "Category", "Sovereign|Save" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The name of the file this stone writes to. */" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignSaveTerminal.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The name of the file this stone writes to." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bOverrideToJson_MetaData[] = {
		{ "Category", "Sovereign|Save" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Should we use JSON for this specific stone? (Allows Isla to mod this stone's output) */" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignSaveTerminal.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Should we use JSON for this specific stone? (Allows Isla to mod this stone's output)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LastOperationEntityCount_MetaData[] = {
		{ "Category", "Sovereign|Save Status" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Shows how many objects were found/processed in the last operation. */" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignSaveTerminal.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shows how many objects were found/processed in the last operation." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class ASovereignSaveTerminal constinit property declarations *******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_TargetSlotName;
	static void NewProp_bOverrideToJson_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOverrideToJson;
	static const UECodeGen_Private::FIntPropertyParams NewProp_LastOperationEntityCount;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class ASovereignSaveTerminal constinit property declarations *********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("Editor_RefreshSavedCount"), .Pointer = &ASovereignSaveTerminal::execEditor_RefreshSavedCount },
		{ .NameUTF8 = UTF8TEXT("Editor_TriggerLoad"), .Pointer = &ASovereignSaveTerminal::execEditor_TriggerLoad },
		{ .NameUTF8 = UTF8TEXT("Editor_TriggerSave"), .Pointer = &ASovereignSaveTerminal::execEditor_TriggerSave },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ASovereignSaveTerminal_Editor_RefreshSavedCount, "Editor_RefreshSavedCount" }, // 681331534
		{ &Z_Construct_UFunction_ASovereignSaveTerminal_Editor_TriggerLoad, "Editor_TriggerLoad" }, // 4192851462
		{ &Z_Construct_UFunction_ASovereignSaveTerminal_Editor_TriggerSave, "Editor_TriggerSave" }, // 1903173019
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASovereignSaveTerminal>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_ASovereignSaveTerminal_Statics

// ********** Begin Class ASovereignSaveTerminal Property Definitions ******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_ASovereignSaveTerminal_Statics::NewProp_TargetSlotName = { "TargetSlotName", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASovereignSaveTerminal, TargetSlotName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetSlotName_MetaData), NewProp_TargetSlotName_MetaData) };
void Z_Construct_UClass_ASovereignSaveTerminal_Statics::NewProp_bOverrideToJson_SetBit(void* Obj)
{
	((ASovereignSaveTerminal*)Obj)->bOverrideToJson = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASovereignSaveTerminal_Statics::NewProp_bOverrideToJson = { "bOverrideToJson", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ASovereignSaveTerminal), &Z_Construct_UClass_ASovereignSaveTerminal_Statics::NewProp_bOverrideToJson_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bOverrideToJson_MetaData), NewProp_bOverrideToJson_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ASovereignSaveTerminal_Statics::NewProp_LastOperationEntityCount = { "LastOperationEntityCount", nullptr, (EPropertyFlags)0x0020080000020015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASovereignSaveTerminal, LastOperationEntityCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LastOperationEntityCount_MetaData), NewProp_LastOperationEntityCount_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASovereignSaveTerminal_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASovereignSaveTerminal_Statics::NewProp_TargetSlotName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASovereignSaveTerminal_Statics::NewProp_bOverrideToJson,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASovereignSaveTerminal_Statics::NewProp_LastOperationEntityCount,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASovereignSaveTerminal_Statics::PropPointers) < 2048);
// ********** End Class ASovereignSaveTerminal Property Definitions ********************************
UObject* (*const Z_Construct_UClass_ASovereignSaveTerminal_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ASovereignBaseInteractable,
	(UObject* (*)())Z_Construct_UPackage__Script_WispCPP7VR,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASovereignSaveTerminal_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ASovereignSaveTerminal_Statics::ClassParams = {
	&ASovereignSaveTerminal::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ASovereignSaveTerminal_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ASovereignSaveTerminal_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASovereignSaveTerminal_Statics::Class_MetaDataParams), Z_Construct_UClass_ASovereignSaveTerminal_Statics::Class_MetaDataParams)
};
void ASovereignSaveTerminal::StaticRegisterNativesASovereignSaveTerminal()
{
	UClass* Class = ASovereignSaveTerminal::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_ASovereignSaveTerminal_Statics::Funcs));
}
UClass* Z_Construct_UClass_ASovereignSaveTerminal()
{
	if (!Z_Registration_Info_UClass_ASovereignSaveTerminal.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASovereignSaveTerminal.OuterSingleton, Z_Construct_UClass_ASovereignSaveTerminal_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ASovereignSaveTerminal.OuterSingleton;
}
ASovereignSaveTerminal::ASovereignSaveTerminal() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ASovereignSaveTerminal);
ASovereignSaveTerminal::~ASovereignSaveTerminal() {}
// ********** End Class ASovereignSaveTerminal *****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Entities_SovereignSaveTerminal_h__Script_WispCPP7VR_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ASovereignSaveTerminal, ASovereignSaveTerminal::StaticClass, TEXT("ASovereignSaveTerminal"), &Z_Registration_Info_UClass_ASovereignSaveTerminal, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASovereignSaveTerminal), 3967730661U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Entities_SovereignSaveTerminal_h__Script_WispCPP7VR_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Entities_SovereignSaveTerminal_h__Script_WispCPP7VR_2410842329{
	TEXT("/Script/WispCPP7VR"),
	Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Entities_SovereignSaveTerminal_h__Script_WispCPP7VR_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Entities_SovereignSaveTerminal_h__Script_WispCPP7VR_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
