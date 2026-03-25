// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SaveSystem/SovereignSpawnerUtils.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSovereignSpawnerUtils() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
UPackage* Z_Construct_UPackage__Script_WispCPP7VR();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignSpawnerUtils();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignSpawnerUtils_NoRegister();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignSpeciesData_NoRegister();
// ********** End Cross Module References **********************************************************

// ********** Begin Class USovereignSpawnerUtils Function CanBreed *********************************
struct Z_Construct_UFunction_USovereignSpawnerUtils_CanBreed_Statics
{
	struct SovereignSpawnerUtils_eventCanBreed_Parms
	{
		AActor* ParentA;
		AActor* ParentB;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Genetics" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** ?? COMPATIBILITY: Checks if two actors can produce offspring (Gender check, etc) */// Might need to exapand the logic so they are both type \"[plant} for example\n" },
#endif
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignSpawnerUtils.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "?? COMPATIBILITY: Checks if two actors can produce offspring (Gender check, etc) // Might need to exapand the logic so they are both type \"[plant} for example" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function CanBreed constinit property declarations ******************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ParentA;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ParentB;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CanBreed constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CanBreed Property Definitions *****************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USovereignSpawnerUtils_CanBreed_Statics::NewProp_ParentA = { "ParentA", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignSpawnerUtils_eventCanBreed_Parms, ParentA), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USovereignSpawnerUtils_CanBreed_Statics::NewProp_ParentB = { "ParentB", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignSpawnerUtils_eventCanBreed_Parms, ParentB), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_USovereignSpawnerUtils_CanBreed_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((SovereignSpawnerUtils_eventCanBreed_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USovereignSpawnerUtils_CanBreed_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SovereignSpawnerUtils_eventCanBreed_Parms), &Z_Construct_UFunction_USovereignSpawnerUtils_CanBreed_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USovereignSpawnerUtils_CanBreed_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignSpawnerUtils_CanBreed_Statics::NewProp_ParentA,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignSpawnerUtils_CanBreed_Statics::NewProp_ParentB,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignSpawnerUtils_CanBreed_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignSpawnerUtils_CanBreed_Statics::PropPointers) < 2048);
// ********** End Function CanBreed Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USovereignSpawnerUtils_CanBreed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USovereignSpawnerUtils, nullptr, "CanBreed", 	Z_Construct_UFunction_USovereignSpawnerUtils_CanBreed_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignSpawnerUtils_CanBreed_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USovereignSpawnerUtils_CanBreed_Statics::SovereignSpawnerUtils_eventCanBreed_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignSpawnerUtils_CanBreed_Statics::Function_MetaDataParams), Z_Construct_UFunction_USovereignSpawnerUtils_CanBreed_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USovereignSpawnerUtils_CanBreed_Statics::SovereignSpawnerUtils_eventCanBreed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USovereignSpawnerUtils_CanBreed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USovereignSpawnerUtils_CanBreed_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USovereignSpawnerUtils::execCanBreed)
{
	P_GET_OBJECT(AActor,Z_Param_ParentA);
	P_GET_OBJECT(AActor,Z_Param_ParentB);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=USovereignSpawnerUtils::CanBreed(Z_Param_ParentA,Z_Param_ParentB);
	P_NATIVE_END;
}
// ********** End Class USovereignSpawnerUtils Function CanBreed ***********************************

// ********** Begin Class USovereignSpawnerUtils Function GenerateMutatedTags **********************
struct Z_Construct_UFunction_USovereignSpawnerUtils_GenerateMutatedTags_Statics
{
	struct SovereignSpawnerUtils_eventGenerateMutatedTags_Parms
	{
		TMap<FString,FString> SourceTags;
		float MutationChance;
		TMap<FString,FString> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Genetics" },
		{ "CPP_Default_MutationChance", "0.050000" },
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignSpawnerUtils.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GenerateMutatedTags constinit property declarations *******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_SourceTags_ValueProp;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SourceTags_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_SourceTags;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MutationChance;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_ValueProp;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GenerateMutatedTags constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GenerateMutatedTags Property Definitions ******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USovereignSpawnerUtils_GenerateMutatedTags_Statics::NewProp_SourceTags_ValueProp = { "SourceTags", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USovereignSpawnerUtils_GenerateMutatedTags_Statics::NewProp_SourceTags_Key_KeyProp = { "SourceTags_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_USovereignSpawnerUtils_GenerateMutatedTags_Statics::NewProp_SourceTags = { "SourceTags", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignSpawnerUtils_eventGenerateMutatedTags_Parms, SourceTags), EMapPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USovereignSpawnerUtils_GenerateMutatedTags_Statics::NewProp_MutationChance = { "MutationChance", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignSpawnerUtils_eventGenerateMutatedTags_Parms, MutationChance), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USovereignSpawnerUtils_GenerateMutatedTags_Statics::NewProp_ReturnValue_ValueProp = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USovereignSpawnerUtils_GenerateMutatedTags_Statics::NewProp_ReturnValue_Key_KeyProp = { "ReturnValue_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_USovereignSpawnerUtils_GenerateMutatedTags_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignSpawnerUtils_eventGenerateMutatedTags_Parms, ReturnValue), EMapPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USovereignSpawnerUtils_GenerateMutatedTags_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignSpawnerUtils_GenerateMutatedTags_Statics::NewProp_SourceTags_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignSpawnerUtils_GenerateMutatedTags_Statics::NewProp_SourceTags_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignSpawnerUtils_GenerateMutatedTags_Statics::NewProp_SourceTags,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignSpawnerUtils_GenerateMutatedTags_Statics::NewProp_MutationChance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignSpawnerUtils_GenerateMutatedTags_Statics::NewProp_ReturnValue_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignSpawnerUtils_GenerateMutatedTags_Statics::NewProp_ReturnValue_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignSpawnerUtils_GenerateMutatedTags_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignSpawnerUtils_GenerateMutatedTags_Statics::PropPointers) < 2048);
// ********** End Function GenerateMutatedTags Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USovereignSpawnerUtils_GenerateMutatedTags_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USovereignSpawnerUtils, nullptr, "GenerateMutatedTags", 	Z_Construct_UFunction_USovereignSpawnerUtils_GenerateMutatedTags_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignSpawnerUtils_GenerateMutatedTags_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USovereignSpawnerUtils_GenerateMutatedTags_Statics::SovereignSpawnerUtils_eventGenerateMutatedTags_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignSpawnerUtils_GenerateMutatedTags_Statics::Function_MetaDataParams), Z_Construct_UFunction_USovereignSpawnerUtils_GenerateMutatedTags_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USovereignSpawnerUtils_GenerateMutatedTags_Statics::SovereignSpawnerUtils_eventGenerateMutatedTags_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USovereignSpawnerUtils_GenerateMutatedTags()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USovereignSpawnerUtils_GenerateMutatedTags_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USovereignSpawnerUtils::execGenerateMutatedTags)
{
	P_GET_TMAP(FString,FString,Z_Param_SourceTags);
	P_GET_PROPERTY(FFloatProperty,Z_Param_MutationChance);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TMap<FString,FString>*)Z_Param__Result=USovereignSpawnerUtils::GenerateMutatedTags(Z_Param_SourceTags,Z_Param_MutationChance);
	P_NATIVE_END;
}
// ********** End Class USovereignSpawnerUtils Function GenerateMutatedTags ************************

// ********** Begin Class USovereignSpawnerUtils Function GetEntityAncestry ************************
struct Z_Construct_UFunction_USovereignSpawnerUtils_GetEntityAncestry_Statics
{
	struct SovereignSpawnerUtils_eventGetEntityAncestry_Parms
	{
		AActor* TargetActor;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Debug" },
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignSpawnerUtils.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetEntityAncestry constinit property declarations *********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetActor;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetEntityAncestry constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetEntityAncestry Property Definitions ********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USovereignSpawnerUtils_GetEntityAncestry_Statics::NewProp_TargetActor = { "TargetActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignSpawnerUtils_eventGetEntityAncestry_Parms, TargetActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USovereignSpawnerUtils_GetEntityAncestry_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignSpawnerUtils_eventGetEntityAncestry_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USovereignSpawnerUtils_GetEntityAncestry_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignSpawnerUtils_GetEntityAncestry_Statics::NewProp_TargetActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignSpawnerUtils_GetEntityAncestry_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignSpawnerUtils_GetEntityAncestry_Statics::PropPointers) < 2048);
// ********** End Function GetEntityAncestry Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USovereignSpawnerUtils_GetEntityAncestry_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USovereignSpawnerUtils, nullptr, "GetEntityAncestry", 	Z_Construct_UFunction_USovereignSpawnerUtils_GetEntityAncestry_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignSpawnerUtils_GetEntityAncestry_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USovereignSpawnerUtils_GetEntityAncestry_Statics::SovereignSpawnerUtils_eventGetEntityAncestry_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignSpawnerUtils_GetEntityAncestry_Statics::Function_MetaDataParams), Z_Construct_UFunction_USovereignSpawnerUtils_GetEntityAncestry_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USovereignSpawnerUtils_GetEntityAncestry_Statics::SovereignSpawnerUtils_eventGetEntityAncestry_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USovereignSpawnerUtils_GetEntityAncestry()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USovereignSpawnerUtils_GetEntityAncestry_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USovereignSpawnerUtils::execGetEntityAncestry)
{
	P_GET_OBJECT(AActor,Z_Param_TargetActor);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=USovereignSpawnerUtils::GetEntityAncestry(Z_Param_TargetActor);
	P_NATIVE_END;
}
// ********** End Class USovereignSpawnerUtils Function GetEntityAncestry **************************

// ********** Begin Class USovereignSpawnerUtils Function ScanForMutations *************************
struct Z_Construct_UFunction_USovereignSpawnerUtils_ScanForMutations_Statics
{
	struct SovereignSpawnerUtils_eventScanForMutations_Parms
	{
		AActor* ChildActor;
		AActor* ParentActor;
		TArray<FString> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Genetics" },
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignSpawnerUtils.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ScanForMutations constinit property declarations **********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ChildActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ParentActor;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ScanForMutations constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ScanForMutations Property Definitions *********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USovereignSpawnerUtils_ScanForMutations_Statics::NewProp_ChildActor = { "ChildActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignSpawnerUtils_eventScanForMutations_Parms, ChildActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USovereignSpawnerUtils_ScanForMutations_Statics::NewProp_ParentActor = { "ParentActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignSpawnerUtils_eventScanForMutations_Parms, ParentActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USovereignSpawnerUtils_ScanForMutations_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_USovereignSpawnerUtils_ScanForMutations_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignSpawnerUtils_eventScanForMutations_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USovereignSpawnerUtils_ScanForMutations_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignSpawnerUtils_ScanForMutations_Statics::NewProp_ChildActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignSpawnerUtils_ScanForMutations_Statics::NewProp_ParentActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignSpawnerUtils_ScanForMutations_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignSpawnerUtils_ScanForMutations_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignSpawnerUtils_ScanForMutations_Statics::PropPointers) < 2048);
// ********** End Function ScanForMutations Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USovereignSpawnerUtils_ScanForMutations_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USovereignSpawnerUtils, nullptr, "ScanForMutations", 	Z_Construct_UFunction_USovereignSpawnerUtils_ScanForMutations_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignSpawnerUtils_ScanForMutations_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USovereignSpawnerUtils_ScanForMutations_Statics::SovereignSpawnerUtils_eventScanForMutations_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignSpawnerUtils_ScanForMutations_Statics::Function_MetaDataParams), Z_Construct_UFunction_USovereignSpawnerUtils_ScanForMutations_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USovereignSpawnerUtils_ScanForMutations_Statics::SovereignSpawnerUtils_eventScanForMutations_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USovereignSpawnerUtils_ScanForMutations()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USovereignSpawnerUtils_ScanForMutations_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USovereignSpawnerUtils::execScanForMutations)
{
	P_GET_OBJECT(AActor,Z_Param_ChildActor);
	P_GET_OBJECT(AActor,Z_Param_ParentActor);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FString>*)Z_Param__Result=USovereignSpawnerUtils::ScanForMutations(Z_Param_ChildActor,Z_Param_ParentActor);
	P_NATIVE_END;
}
// ********** End Class USovereignSpawnerUtils Function ScanForMutations ***************************

// ********** Begin Class USovereignSpawnerUtils Function SpawnEarnedEntity ************************
struct Z_Construct_UFunction_USovereignSpawnerUtils_SpawnEarnedEntity_Statics
{
	struct SovereignSpawnerUtils_eventSpawnEarnedEntity_Parms
	{
		UObject* WorldContextObject;
		const USovereignSpeciesData* SpeciesData;
		FTransform SpawnTransform;
		FGuid ParentID;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Spawner" },
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignSpawnerUtils.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpeciesData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SpawnEarnedEntity constinit property declarations *********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpeciesData;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpawnTransform;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ParentID;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SpawnEarnedEntity constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SpawnEarnedEntity Property Definitions ********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USovereignSpawnerUtils_SpawnEarnedEntity_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignSpawnerUtils_eventSpawnEarnedEntity_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USovereignSpawnerUtils_SpawnEarnedEntity_Statics::NewProp_SpeciesData = { "SpeciesData", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignSpawnerUtils_eventSpawnEarnedEntity_Parms, SpeciesData), Z_Construct_UClass_USovereignSpeciesData_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpeciesData_MetaData), NewProp_SpeciesData_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USovereignSpawnerUtils_SpawnEarnedEntity_Statics::NewProp_SpawnTransform = { "SpawnTransform", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignSpawnerUtils_eventSpawnEarnedEntity_Parms, SpawnTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USovereignSpawnerUtils_SpawnEarnedEntity_Statics::NewProp_ParentID = { "ParentID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignSpawnerUtils_eventSpawnEarnedEntity_Parms, ParentID), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USovereignSpawnerUtils_SpawnEarnedEntity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignSpawnerUtils_SpawnEarnedEntity_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignSpawnerUtils_SpawnEarnedEntity_Statics::NewProp_SpeciesData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignSpawnerUtils_SpawnEarnedEntity_Statics::NewProp_SpawnTransform,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignSpawnerUtils_SpawnEarnedEntity_Statics::NewProp_ParentID,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignSpawnerUtils_SpawnEarnedEntity_Statics::PropPointers) < 2048);
// ********** End Function SpawnEarnedEntity Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USovereignSpawnerUtils_SpawnEarnedEntity_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USovereignSpawnerUtils, nullptr, "SpawnEarnedEntity", 	Z_Construct_UFunction_USovereignSpawnerUtils_SpawnEarnedEntity_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignSpawnerUtils_SpawnEarnedEntity_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USovereignSpawnerUtils_SpawnEarnedEntity_Statics::SovereignSpawnerUtils_eventSpawnEarnedEntity_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignSpawnerUtils_SpawnEarnedEntity_Statics::Function_MetaDataParams), Z_Construct_UFunction_USovereignSpawnerUtils_SpawnEarnedEntity_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USovereignSpawnerUtils_SpawnEarnedEntity_Statics::SovereignSpawnerUtils_eventSpawnEarnedEntity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USovereignSpawnerUtils_SpawnEarnedEntity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USovereignSpawnerUtils_SpawnEarnedEntity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USovereignSpawnerUtils::execSpawnEarnedEntity)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_OBJECT(USovereignSpeciesData,Z_Param_SpeciesData);
	P_GET_STRUCT(FTransform,Z_Param_SpawnTransform);
	P_GET_STRUCT(FGuid,Z_Param_ParentID);
	P_FINISH;
	P_NATIVE_BEGIN;
	USovereignSpawnerUtils::SpawnEarnedEntity(Z_Param_WorldContextObject,Z_Param_SpeciesData,Z_Param_SpawnTransform,Z_Param_ParentID);
	P_NATIVE_END;
}
// ********** End Class USovereignSpawnerUtils Function SpawnEarnedEntity **************************

// ********** Begin Class USovereignSpawnerUtils Function SpawnEarnedEntityInherited ***************
struct Z_Construct_UFunction_USovereignSpawnerUtils_SpawnEarnedEntityInherited_Statics
{
	struct SovereignSpawnerUtils_eventSpawnEarnedEntityInherited_Parms
	{
		UObject* WorldContextObject;
		const USovereignSpeciesData* SpeciesData;
		FTransform SpawnTransform;
		AActor* ParentActor;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Spawner" },
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignSpawnerUtils.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpeciesData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SpawnEarnedEntityInherited constinit property declarations ************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpeciesData;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpawnTransform;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ParentActor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SpawnEarnedEntityInherited constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SpawnEarnedEntityInherited Property Definitions ***********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USovereignSpawnerUtils_SpawnEarnedEntityInherited_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignSpawnerUtils_eventSpawnEarnedEntityInherited_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USovereignSpawnerUtils_SpawnEarnedEntityInherited_Statics::NewProp_SpeciesData = { "SpeciesData", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignSpawnerUtils_eventSpawnEarnedEntityInherited_Parms, SpeciesData), Z_Construct_UClass_USovereignSpeciesData_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpeciesData_MetaData), NewProp_SpeciesData_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USovereignSpawnerUtils_SpawnEarnedEntityInherited_Statics::NewProp_SpawnTransform = { "SpawnTransform", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignSpawnerUtils_eventSpawnEarnedEntityInherited_Parms, SpawnTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USovereignSpawnerUtils_SpawnEarnedEntityInherited_Statics::NewProp_ParentActor = { "ParentActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignSpawnerUtils_eventSpawnEarnedEntityInherited_Parms, ParentActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USovereignSpawnerUtils_SpawnEarnedEntityInherited_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignSpawnerUtils_SpawnEarnedEntityInherited_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignSpawnerUtils_SpawnEarnedEntityInherited_Statics::NewProp_SpeciesData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignSpawnerUtils_SpawnEarnedEntityInherited_Statics::NewProp_SpawnTransform,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignSpawnerUtils_SpawnEarnedEntityInherited_Statics::NewProp_ParentActor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignSpawnerUtils_SpawnEarnedEntityInherited_Statics::PropPointers) < 2048);
// ********** End Function SpawnEarnedEntityInherited Property Definitions *************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USovereignSpawnerUtils_SpawnEarnedEntityInherited_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USovereignSpawnerUtils, nullptr, "SpawnEarnedEntityInherited", 	Z_Construct_UFunction_USovereignSpawnerUtils_SpawnEarnedEntityInherited_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignSpawnerUtils_SpawnEarnedEntityInherited_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USovereignSpawnerUtils_SpawnEarnedEntityInherited_Statics::SovereignSpawnerUtils_eventSpawnEarnedEntityInherited_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignSpawnerUtils_SpawnEarnedEntityInherited_Statics::Function_MetaDataParams), Z_Construct_UFunction_USovereignSpawnerUtils_SpawnEarnedEntityInherited_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USovereignSpawnerUtils_SpawnEarnedEntityInherited_Statics::SovereignSpawnerUtils_eventSpawnEarnedEntityInherited_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USovereignSpawnerUtils_SpawnEarnedEntityInherited()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USovereignSpawnerUtils_SpawnEarnedEntityInherited_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USovereignSpawnerUtils::execSpawnEarnedEntityInherited)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_OBJECT(USovereignSpeciesData,Z_Param_SpeciesData);
	P_GET_STRUCT(FTransform,Z_Param_SpawnTransform);
	P_GET_OBJECT(AActor,Z_Param_ParentActor);
	P_FINISH;
	P_NATIVE_BEGIN;
	USovereignSpawnerUtils::SpawnEarnedEntityInherited(Z_Param_WorldContextObject,Z_Param_SpeciesData,Z_Param_SpawnTransform,Z_Param_ParentActor);
	P_NATIVE_END;
}
// ********** End Class USovereignSpawnerUtils Function SpawnEarnedEntityInherited *****************

// ********** Begin Class USovereignSpawnerUtils Function SpawnHybridEntity ************************
struct Z_Construct_UFunction_USovereignSpawnerUtils_SpawnHybridEntity_Statics
{
	struct SovereignSpawnerUtils_eventSpawnHybridEntity_Parms
	{
		UObject* WorldContextObject;
		const USovereignSpeciesData* SpeciesData;
		FTransform SpawnTransform;
		AActor* Mother;
		AActor* Father;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Spawner" },
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignSpawnerUtils.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpeciesData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SpawnHybridEntity constinit property declarations *********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpeciesData;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpawnTransform;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Mother;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Father;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SpawnHybridEntity constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SpawnHybridEntity Property Definitions ********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USovereignSpawnerUtils_SpawnHybridEntity_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignSpawnerUtils_eventSpawnHybridEntity_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USovereignSpawnerUtils_SpawnHybridEntity_Statics::NewProp_SpeciesData = { "SpeciesData", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignSpawnerUtils_eventSpawnHybridEntity_Parms, SpeciesData), Z_Construct_UClass_USovereignSpeciesData_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpeciesData_MetaData), NewProp_SpeciesData_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USovereignSpawnerUtils_SpawnHybridEntity_Statics::NewProp_SpawnTransform = { "SpawnTransform", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignSpawnerUtils_eventSpawnHybridEntity_Parms, SpawnTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USovereignSpawnerUtils_SpawnHybridEntity_Statics::NewProp_Mother = { "Mother", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignSpawnerUtils_eventSpawnHybridEntity_Parms, Mother), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USovereignSpawnerUtils_SpawnHybridEntity_Statics::NewProp_Father = { "Father", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignSpawnerUtils_eventSpawnHybridEntity_Parms, Father), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USovereignSpawnerUtils_SpawnHybridEntity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignSpawnerUtils_SpawnHybridEntity_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignSpawnerUtils_SpawnHybridEntity_Statics::NewProp_SpeciesData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignSpawnerUtils_SpawnHybridEntity_Statics::NewProp_SpawnTransform,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignSpawnerUtils_SpawnHybridEntity_Statics::NewProp_Mother,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignSpawnerUtils_SpawnHybridEntity_Statics::NewProp_Father,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignSpawnerUtils_SpawnHybridEntity_Statics::PropPointers) < 2048);
// ********** End Function SpawnHybridEntity Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USovereignSpawnerUtils_SpawnHybridEntity_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USovereignSpawnerUtils, nullptr, "SpawnHybridEntity", 	Z_Construct_UFunction_USovereignSpawnerUtils_SpawnHybridEntity_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignSpawnerUtils_SpawnHybridEntity_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USovereignSpawnerUtils_SpawnHybridEntity_Statics::SovereignSpawnerUtils_eventSpawnHybridEntity_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignSpawnerUtils_SpawnHybridEntity_Statics::Function_MetaDataParams), Z_Construct_UFunction_USovereignSpawnerUtils_SpawnHybridEntity_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USovereignSpawnerUtils_SpawnHybridEntity_Statics::SovereignSpawnerUtils_eventSpawnHybridEntity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USovereignSpawnerUtils_SpawnHybridEntity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USovereignSpawnerUtils_SpawnHybridEntity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USovereignSpawnerUtils::execSpawnHybridEntity)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_OBJECT(USovereignSpeciesData,Z_Param_SpeciesData);
	P_GET_STRUCT(FTransform,Z_Param_SpawnTransform);
	P_GET_OBJECT(AActor,Z_Param_Mother);
	P_GET_OBJECT(AActor,Z_Param_Father);
	P_FINISH;
	P_NATIVE_BEGIN;
	USovereignSpawnerUtils::SpawnHybridEntity(Z_Param_WorldContextObject,Z_Param_SpeciesData,Z_Param_SpawnTransform,Z_Param_Mother,Z_Param_Father);
	P_NATIVE_END;
}
// ********** End Class USovereignSpawnerUtils Function SpawnHybridEntity **************************

// ********** Begin Class USovereignSpawnerUtils ***************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_USovereignSpawnerUtils;
UClass* USovereignSpawnerUtils::GetPrivateStaticClass()
{
	using TClass = USovereignSpawnerUtils;
	if (!Z_Registration_Info_UClass_USovereignSpawnerUtils.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SovereignSpawnerUtils"),
			Z_Registration_Info_UClass_USovereignSpawnerUtils.InnerSingleton,
			StaticRegisterNativesUSovereignSpawnerUtils,
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
	return Z_Registration_Info_UClass_USovereignSpawnerUtils.InnerSingleton;
}
UClass* Z_Construct_UClass_USovereignSpawnerUtils_NoRegister()
{
	return USovereignSpawnerUtils::GetPrivateStaticClass();
}
struct Z_Construct_UClass_USovereignSpawnerUtils_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Sovereign Utility Library\n * Handles the \"D&D\" style attribute inheritance and the Genetic Recombination system.\n */" },
#endif
		{ "IncludePath", "SaveSystem/SovereignSpawnerUtils.h" },
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignSpawnerUtils.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sovereign Utility Library\nHandles the \"D&D\" style attribute inheritance and the Genetic Recombination system." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class USovereignSpawnerUtils constinit property declarations *******************
// ********** End Class USovereignSpawnerUtils constinit property declarations *********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("CanBreed"), .Pointer = &USovereignSpawnerUtils::execCanBreed },
		{ .NameUTF8 = UTF8TEXT("GenerateMutatedTags"), .Pointer = &USovereignSpawnerUtils::execGenerateMutatedTags },
		{ .NameUTF8 = UTF8TEXT("GetEntityAncestry"), .Pointer = &USovereignSpawnerUtils::execGetEntityAncestry },
		{ .NameUTF8 = UTF8TEXT("ScanForMutations"), .Pointer = &USovereignSpawnerUtils::execScanForMutations },
		{ .NameUTF8 = UTF8TEXT("SpawnEarnedEntity"), .Pointer = &USovereignSpawnerUtils::execSpawnEarnedEntity },
		{ .NameUTF8 = UTF8TEXT("SpawnEarnedEntityInherited"), .Pointer = &USovereignSpawnerUtils::execSpawnEarnedEntityInherited },
		{ .NameUTF8 = UTF8TEXT("SpawnHybridEntity"), .Pointer = &USovereignSpawnerUtils::execSpawnHybridEntity },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_USovereignSpawnerUtils_CanBreed, "CanBreed" }, // 2682038676
		{ &Z_Construct_UFunction_USovereignSpawnerUtils_GenerateMutatedTags, "GenerateMutatedTags" }, // 720832913
		{ &Z_Construct_UFunction_USovereignSpawnerUtils_GetEntityAncestry, "GetEntityAncestry" }, // 2632258163
		{ &Z_Construct_UFunction_USovereignSpawnerUtils_ScanForMutations, "ScanForMutations" }, // 3663982667
		{ &Z_Construct_UFunction_USovereignSpawnerUtils_SpawnEarnedEntity, "SpawnEarnedEntity" }, // 588005970
		{ &Z_Construct_UFunction_USovereignSpawnerUtils_SpawnEarnedEntityInherited, "SpawnEarnedEntityInherited" }, // 1006433149
		{ &Z_Construct_UFunction_USovereignSpawnerUtils_SpawnHybridEntity, "SpawnHybridEntity" }, // 4169805556
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USovereignSpawnerUtils>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_USovereignSpawnerUtils_Statics
UObject* (*const Z_Construct_UClass_USovereignSpawnerUtils_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_WispCPP7VR,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USovereignSpawnerUtils_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USovereignSpawnerUtils_Statics::ClassParams = {
	&USovereignSpawnerUtils::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USovereignSpawnerUtils_Statics::Class_MetaDataParams), Z_Construct_UClass_USovereignSpawnerUtils_Statics::Class_MetaDataParams)
};
void USovereignSpawnerUtils::StaticRegisterNativesUSovereignSpawnerUtils()
{
	UClass* Class = USovereignSpawnerUtils::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_USovereignSpawnerUtils_Statics::Funcs));
}
UClass* Z_Construct_UClass_USovereignSpawnerUtils()
{
	if (!Z_Registration_Info_UClass_USovereignSpawnerUtils.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USovereignSpawnerUtils.OuterSingleton, Z_Construct_UClass_USovereignSpawnerUtils_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USovereignSpawnerUtils.OuterSingleton;
}
USovereignSpawnerUtils::USovereignSpawnerUtils(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, USovereignSpawnerUtils);
USovereignSpawnerUtils::~USovereignSpawnerUtils() {}
// ********** End Class USovereignSpawnerUtils *****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_SaveSystem_SovereignSpawnerUtils_h__Script_WispCPP7VR_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_USovereignSpawnerUtils, USovereignSpawnerUtils::StaticClass, TEXT("USovereignSpawnerUtils"), &Z_Registration_Info_UClass_USovereignSpawnerUtils, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USovereignSpawnerUtils), 4040420525U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_SaveSystem_SovereignSpawnerUtils_h__Script_WispCPP7VR_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_SaveSystem_SovereignSpawnerUtils_h__Script_WispCPP7VR_2026011342{
	TEXT("/Script/WispCPP7VR"),
	Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_SaveSystem_SovereignSpawnerUtils_h__Script_WispCPP7VR_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_SaveSystem_SovereignSpawnerUtils_h__Script_WispCPP7VR_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
