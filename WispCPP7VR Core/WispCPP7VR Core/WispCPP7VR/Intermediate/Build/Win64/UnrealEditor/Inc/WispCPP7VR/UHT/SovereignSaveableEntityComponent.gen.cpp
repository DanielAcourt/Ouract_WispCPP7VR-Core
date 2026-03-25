// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Entities/SovereignSaveableEntityComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSovereignSaveableEntityComponent() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FDateTime();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
UPackage* Z_Construct_UPackage__Script_WispCPP7VR();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignSaveableEntityComponent();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignSaveableEntityComponent_NoRegister();
WISPCPP7VR_API UEnum* Z_Construct_UEnum_WispCPP7VR_ESovereignElement();
// ********** End Cross Module References **********************************************************

// ********** Begin Class USovereignSaveableEntityComponent Function AddUnknownTag *****************
struct Z_Construct_UFunction_USovereignSaveableEntityComponent_AddUnknownTag_Statics
{
	struct SovereignSaveableEntityComponent_eventAddUnknownTag_Parms
	{
		FString Key;
		FString Value;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|SaveSystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The Hub's way of handling data it doesn't recognize yet (Isla's unknown tags) */" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignSaveableEntityComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The Hub's way of handling data it doesn't recognize yet (Isla's unknown tags)" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function AddUnknownTag constinit property declarations *************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Key;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddUnknownTag constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddUnknownTag Property Definitions ************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USovereignSaveableEntityComponent_AddUnknownTag_Statics::NewProp_Key = { "Key", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignSaveableEntityComponent_eventAddUnknownTag_Parms, Key), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USovereignSaveableEntityComponent_AddUnknownTag_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignSaveableEntityComponent_eventAddUnknownTag_Parms, Value), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USovereignSaveableEntityComponent_AddUnknownTag_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignSaveableEntityComponent_AddUnknownTag_Statics::NewProp_Key,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignSaveableEntityComponent_AddUnknownTag_Statics::NewProp_Value,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignSaveableEntityComponent_AddUnknownTag_Statics::PropPointers) < 2048);
// ********** End Function AddUnknownTag Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USovereignSaveableEntityComponent_AddUnknownTag_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USovereignSaveableEntityComponent, nullptr, "AddUnknownTag", 	Z_Construct_UFunction_USovereignSaveableEntityComponent_AddUnknownTag_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignSaveableEntityComponent_AddUnknownTag_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USovereignSaveableEntityComponent_AddUnknownTag_Statics::SovereignSaveableEntityComponent_eventAddUnknownTag_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignSaveableEntityComponent_AddUnknownTag_Statics::Function_MetaDataParams), Z_Construct_UFunction_USovereignSaveableEntityComponent_AddUnknownTag_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USovereignSaveableEntityComponent_AddUnknownTag_Statics::SovereignSaveableEntityComponent_eventAddUnknownTag_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USovereignSaveableEntityComponent_AddUnknownTag()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USovereignSaveableEntityComponent_AddUnknownTag_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USovereignSaveableEntityComponent::execAddUnknownTag)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Key);
	P_GET_PROPERTY(FStrProperty,Z_Param_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AddUnknownTag(Z_Param_Key,Z_Param_Value);
	P_NATIVE_END;
}
// ********** End Class USovereignSaveableEntityComponent Function AddUnknownTag *******************

// ********** Begin Class USovereignSaveableEntityComponent Function ApplyMetaTags *****************
struct Z_Construct_UFunction_USovereignSaveableEntityComponent_ApplyMetaTags_Statics
{
	struct SovereignSaveableEntityComponent_eventApplyMetaTags_Parms
	{
		TMap<FString,FString> LoadedTags;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|SaveSystem" },
		{ "ModuleRelativePath", "Public/Entities/SovereignSaveableEntityComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ApplyMetaTags constinit property declarations *************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_LoadedTags_ValueProp;
	static const UECodeGen_Private::FStrPropertyParams NewProp_LoadedTags_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_LoadedTags;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ApplyMetaTags constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ApplyMetaTags Property Definitions ************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USovereignSaveableEntityComponent_ApplyMetaTags_Statics::NewProp_LoadedTags_ValueProp = { "LoadedTags", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USovereignSaveableEntityComponent_ApplyMetaTags_Statics::NewProp_LoadedTags_Key_KeyProp = { "LoadedTags_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_USovereignSaveableEntityComponent_ApplyMetaTags_Statics::NewProp_LoadedTags = { "LoadedTags", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignSaveableEntityComponent_eventApplyMetaTags_Parms, LoadedTags), EMapPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USovereignSaveableEntityComponent_ApplyMetaTags_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignSaveableEntityComponent_ApplyMetaTags_Statics::NewProp_LoadedTags_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignSaveableEntityComponent_ApplyMetaTags_Statics::NewProp_LoadedTags_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignSaveableEntityComponent_ApplyMetaTags_Statics::NewProp_LoadedTags,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignSaveableEntityComponent_ApplyMetaTags_Statics::PropPointers) < 2048);
// ********** End Function ApplyMetaTags Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USovereignSaveableEntityComponent_ApplyMetaTags_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USovereignSaveableEntityComponent, nullptr, "ApplyMetaTags", 	Z_Construct_UFunction_USovereignSaveableEntityComponent_ApplyMetaTags_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignSaveableEntityComponent_ApplyMetaTags_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USovereignSaveableEntityComponent_ApplyMetaTags_Statics::SovereignSaveableEntityComponent_eventApplyMetaTags_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignSaveableEntityComponent_ApplyMetaTags_Statics::Function_MetaDataParams), Z_Construct_UFunction_USovereignSaveableEntityComponent_ApplyMetaTags_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USovereignSaveableEntityComponent_ApplyMetaTags_Statics::SovereignSaveableEntityComponent_eventApplyMetaTags_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USovereignSaveableEntityComponent_ApplyMetaTags()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USovereignSaveableEntityComponent_ApplyMetaTags_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USovereignSaveableEntityComponent::execApplyMetaTags)
{
	P_GET_TMAP(FString,FString,Z_Param_LoadedTags);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ApplyMetaTags(Z_Param_LoadedTags);
	P_NATIVE_END;
}
// ********** End Class USovereignSaveableEntityComponent Function ApplyMetaTags *******************

// ********** Begin Class USovereignSaveableEntityComponent Function GetGUID ***********************
struct Z_Construct_UFunction_USovereignSaveableEntityComponent_GetGUID_Statics
{
	struct SovereignSaveableEntityComponent_eventGetGUID_Parms
	{
		FGuid ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Core" },
		{ "ModuleRelativePath", "Public/Entities/SovereignSaveableEntityComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetGUID constinit property declarations *******************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetGUID constinit property declarations *********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetGUID Property Definitions ******************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USovereignSaveableEntityComponent_GetGUID_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignSaveableEntityComponent_eventGetGUID_Parms, ReturnValue), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USovereignSaveableEntityComponent_GetGUID_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignSaveableEntityComponent_GetGUID_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignSaveableEntityComponent_GetGUID_Statics::PropPointers) < 2048);
// ********** End Function GetGUID Property Definitions ********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USovereignSaveableEntityComponent_GetGUID_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USovereignSaveableEntityComponent, nullptr, "GetGUID", 	Z_Construct_UFunction_USovereignSaveableEntityComponent_GetGUID_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignSaveableEntityComponent_GetGUID_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USovereignSaveableEntityComponent_GetGUID_Statics::SovereignSaveableEntityComponent_eventGetGUID_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54880401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignSaveableEntityComponent_GetGUID_Statics::Function_MetaDataParams), Z_Construct_UFunction_USovereignSaveableEntityComponent_GetGUID_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USovereignSaveableEntityComponent_GetGUID_Statics::SovereignSaveableEntityComponent_eventGetGUID_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USovereignSaveableEntityComponent_GetGUID()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USovereignSaveableEntityComponent_GetGUID_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USovereignSaveableEntityComponent::execGetGUID)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGuid*)Z_Param__Result=P_THIS->GetGUID();
	P_NATIVE_END;
}
// ********** End Class USovereignSaveableEntityComponent Function GetGUID *************************

// ********** Begin Class USovereignSaveableEntityComponent Function GetUnknownMetaTags ************
struct Z_Construct_UFunction_USovereignSaveableEntityComponent_GetUnknownMetaTags_Statics
{
	struct SovereignSaveableEntityComponent_eventGetUnknownMetaTags_Parms
	{
		TMap<FString,FString> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|SaveSystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** --- 5. DYNAMIC DNA (Meta Tags) --- */" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignSaveableEntityComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- 5. DYNAMIC DNA (Meta Tags) ---" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetUnknownMetaTags constinit property declarations ********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_ValueProp;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetUnknownMetaTags constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetUnknownMetaTags Property Definitions *******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USovereignSaveableEntityComponent_GetUnknownMetaTags_Statics::NewProp_ReturnValue_ValueProp = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USovereignSaveableEntityComponent_GetUnknownMetaTags_Statics::NewProp_ReturnValue_Key_KeyProp = { "ReturnValue_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_USovereignSaveableEntityComponent_GetUnknownMetaTags_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignSaveableEntityComponent_eventGetUnknownMetaTags_Parms, ReturnValue), EMapPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USovereignSaveableEntityComponent_GetUnknownMetaTags_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignSaveableEntityComponent_GetUnknownMetaTags_Statics::NewProp_ReturnValue_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignSaveableEntityComponent_GetUnknownMetaTags_Statics::NewProp_ReturnValue_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignSaveableEntityComponent_GetUnknownMetaTags_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignSaveableEntityComponent_GetUnknownMetaTags_Statics::PropPointers) < 2048);
// ********** End Function GetUnknownMetaTags Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USovereignSaveableEntityComponent_GetUnknownMetaTags_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USovereignSaveableEntityComponent, nullptr, "GetUnknownMetaTags", 	Z_Construct_UFunction_USovereignSaveableEntityComponent_GetUnknownMetaTags_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignSaveableEntityComponent_GetUnknownMetaTags_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USovereignSaveableEntityComponent_GetUnknownMetaTags_Statics::SovereignSaveableEntityComponent_eventGetUnknownMetaTags_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignSaveableEntityComponent_GetUnknownMetaTags_Statics::Function_MetaDataParams), Z_Construct_UFunction_USovereignSaveableEntityComponent_GetUnknownMetaTags_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USovereignSaveableEntityComponent_GetUnknownMetaTags_Statics::SovereignSaveableEntityComponent_eventGetUnknownMetaTags_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USovereignSaveableEntityComponent_GetUnknownMetaTags()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USovereignSaveableEntityComponent_GetUnknownMetaTags_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USovereignSaveableEntityComponent::execGetUnknownMetaTags)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TMap<FString,FString>*)Z_Param__Result=P_THIS->GetUnknownMetaTags();
	P_NATIVE_END;
}
// ********** End Class USovereignSaveableEntityComponent Function GetUnknownMetaTags **************

// ********** Begin Class USovereignSaveableEntityComponent Function ReceiveElementalEnergy ********
struct Z_Construct_UFunction_USovereignSaveableEntityComponent_ReceiveElementalEnergy_Statics
{
	struct SovereignSaveableEntityComponent_eventReceiveElementalEnergy_Parms
	{
		ESovereignElement EnergyType;
		float RawAmount;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Evolution" },
		{ "ModuleRelativePath", "Public/Entities/SovereignSaveableEntityComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ReceiveElementalEnergy constinit property declarations ****************
	static const UECodeGen_Private::FBytePropertyParams NewProp_EnergyType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_EnergyType;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RawAmount;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ReceiveElementalEnergy constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ReceiveElementalEnergy Property Definitions ***************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USovereignSaveableEntityComponent_ReceiveElementalEnergy_Statics::NewProp_EnergyType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USovereignSaveableEntityComponent_ReceiveElementalEnergy_Statics::NewProp_EnergyType = { "EnergyType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignSaveableEntityComponent_eventReceiveElementalEnergy_Parms, EnergyType), Z_Construct_UEnum_WispCPP7VR_ESovereignElement, METADATA_PARAMS(0, nullptr) }; // 4150726421
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USovereignSaveableEntityComponent_ReceiveElementalEnergy_Statics::NewProp_RawAmount = { "RawAmount", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignSaveableEntityComponent_eventReceiveElementalEnergy_Parms, RawAmount), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USovereignSaveableEntityComponent_ReceiveElementalEnergy_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignSaveableEntityComponent_ReceiveElementalEnergy_Statics::NewProp_EnergyType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignSaveableEntityComponent_ReceiveElementalEnergy_Statics::NewProp_EnergyType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignSaveableEntityComponent_ReceiveElementalEnergy_Statics::NewProp_RawAmount,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignSaveableEntityComponent_ReceiveElementalEnergy_Statics::PropPointers) < 2048);
// ********** End Function ReceiveElementalEnergy Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USovereignSaveableEntityComponent_ReceiveElementalEnergy_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USovereignSaveableEntityComponent, nullptr, "ReceiveElementalEnergy", 	Z_Construct_UFunction_USovereignSaveableEntityComponent_ReceiveElementalEnergy_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignSaveableEntityComponent_ReceiveElementalEnergy_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USovereignSaveableEntityComponent_ReceiveElementalEnergy_Statics::SovereignSaveableEntityComponent_eventReceiveElementalEnergy_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignSaveableEntityComponent_ReceiveElementalEnergy_Statics::Function_MetaDataParams), Z_Construct_UFunction_USovereignSaveableEntityComponent_ReceiveElementalEnergy_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USovereignSaveableEntityComponent_ReceiveElementalEnergy_Statics::SovereignSaveableEntityComponent_eventReceiveElementalEnergy_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USovereignSaveableEntityComponent_ReceiveElementalEnergy()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USovereignSaveableEntityComponent_ReceiveElementalEnergy_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USovereignSaveableEntityComponent::execReceiveElementalEnergy)
{
	P_GET_ENUM(ESovereignElement,Z_Param_EnergyType);
	P_GET_PROPERTY(FFloatProperty,Z_Param_RawAmount);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ReceiveElementalEnergy(ESovereignElement(Z_Param_EnergyType),Z_Param_RawAmount);
	P_NATIVE_END;
}
// ********** End Class USovereignSaveableEntityComponent Function ReceiveElementalEnergy **********

// ********** Begin Class USovereignSaveableEntityComponent ****************************************
FClassRegistrationInfo Z_Registration_Info_UClass_USovereignSaveableEntityComponent;
UClass* USovereignSaveableEntityComponent::GetPrivateStaticClass()
{
	using TClass = USovereignSaveableEntityComponent;
	if (!Z_Registration_Info_UClass_USovereignSaveableEntityComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SovereignSaveableEntityComponent"),
			Z_Registration_Info_UClass_USovereignSaveableEntityComponent.InnerSingleton,
			StaticRegisterNativesUSovereignSaveableEntityComponent,
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
	return Z_Registration_Info_UClass_USovereignSaveableEntityComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_USovereignSaveableEntityComponent_NoRegister()
{
	return USovereignSaveableEntityComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_USovereignSaveableEntityComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "Entities/SovereignSaveableEntityComponent.h" },
		{ "ModuleRelativePath", "Public/Entities/SovereignSaveableEntityComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EntityID_MetaData[] = {
		{ "Category", "Sovereign|Core" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** --- 1. IDENTITY --- */" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignSaveableEntityComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- 1. IDENTITY ---" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BirthTimestamp_MetaData[] = {
		{ "Category", "Sovereign|Core" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The exact moment this Soul was manifested in the world */" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignSaveableEntityComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The exact moment this Soul was manifested in the world" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUseManualBirthDate_MetaData[] = {
		{ "Category", "Sovereign|Identity" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** ANCESTRAL OVERRIDE: Use a custom date instead of the current time? */" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignSaveableEntityComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "ANCESTRAL OVERRIDE: Use a custom date instead of the current time?" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ManualBirthDate_MetaData[] = {
		{ "Category", "Sovereign|Identity" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Custom Date. Format: \"2017.03.23-16.00.00\" */" },
#endif
		{ "EditCondition", "bUseManualBirthDate" },
		{ "ModuleRelativePath", "Public/Entities/SovereignSaveableEntityComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Custom Date. Format: \"2017.03.23-16.00.00\"" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsFemale_MetaData[] = {
		{ "Category", "Sovereign|Biology" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** --- 2. LINEAGE & BREEDING --- */" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignSaveableEntityComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- 2. LINEAGE & BREEDING ---" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ParentID_MetaData[] = {
		{ "Category", "Sovereign|Biology" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Base idea , Important acts as a seed root to a class\n" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignSaveableEntityComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Base idea , Important acts as a seed root to a class" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MotherID_MetaData[] = {
		{ "Category", "Sovereign|Biology" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Optional if we want to store its mother code compared to its fathers so we can do pokemon like upgrading/breeding\n" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignSaveableEntityComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional if we want to store its mother code compared to its fathers so we can do pokemon like upgrading/breeding" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FatherID_MetaData[] = {
		{ "Category", "Sovereign|Biology" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Core now, We can combine the 2 stats in the near future when maing a baby\n" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignSaveableEntityComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Core now, We can combine the 2 stats in the near future when maing a baby" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OffspringCount_MetaData[] = {
		{ "Category", "Sovereign|Biology" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Can be useful as if they hit a limit they can break if item or just store a known log for Parents\n" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignSaveableEntityComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Can be useful as if they hit a limit they can break if item or just store a known log for Parents" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MatingHistory_MetaData[] = {
		{ "Category", "Sovereign|Biology" },
		{ "ModuleRelativePath", "Public/Entities/SovereignSaveableEntityComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LastMatingTimestamp_MetaData[] = {
		{ "Category", "Sovereign|Biology" },
		{ "ModuleRelativePath", "Public/Entities/SovereignSaveableEntityComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MatingCooldownDuration_MetaData[] = {
		{ "Category", "Sovereign|Biology" },
		{ "ModuleRelativePath", "Public/Entities/SovereignSaveableEntityComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AlignmentSocket_MetaData[] = {
		{ "Category", "Sovereign|Genetics" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** --- 3. THE TRIPLE-AXIS SYSTEM (The Soul, Body, and Spark) --- */// Axis 1: Alignment (Light vs Dark)\n" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignSaveableEntityComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- 3. THE TRIPLE-AXIS SYSTEM (The Soul, Body, and Spark) --- // Axis 1: Alignment (Light vs Dark)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BodySocket_MetaData[] = {
		{ "Category", "Sovereign|Genetics" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Axis 2: Physical Element (The Body - Fire, Water, Earth, Nature, Air)\n" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignSaveableEntityComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Axis 2: Physical Element (The Body - Fire, Water, Earth, Nature, Air)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MagicSocket_MetaData[] = {
		{ "Category", "Sovereign|Genetics" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Axis 3: Magic Essence (The Spark - Fairy, Dragon, Electric)\n" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignSaveableEntityComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Axis 3: Magic Essence (The Spark - Fairy, Dragon, Electric)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AlignmentInfluence_MetaData[] = {
		{ "Category", "Sovereign|Genetics" },
		{ "ClampMax", "100" },
		{ "ClampMin", "0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Influence levels for each axis (0-100)\n" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignSaveableEntityComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Influence levels for each axis (0-100)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BodyInfluence_MetaData[] = {
		{ "Category", "Sovereign|Genetics" },
		{ "ClampMax", "100" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/Entities/SovereignSaveableEntityComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MagicInfluence_MetaData[] = {
		{ "Category", "Sovereign|Genetics" },
		{ "ClampMax", "100" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/Entities/SovereignSaveableEntityComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaturityProgress_MetaData[] = {
		{ "Category", "Sovereign|Evolution" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** --- 4. EVOLUTION & ENERGY --- *///Ideally we need this maturity progress and current state to determine an object age deterministically\n" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignSaveableEntityComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- 4. EVOLUTION & ENERGY --- //Ideally we need this maturity progress and current state to determine an object age deterministically" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaturityRate_MetaData[] = {
		{ "Category", "Sovereign|Evolution" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//How quickly it ages based on a tick\n" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignSaveableEntityComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "How quickly it ages based on a tick" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UnknownMetaTags_MetaData[] = {
		{ "Category", "Sovereign|SaveSystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The storage for all manifested truths and elemental residuals */" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignSaveableEntityComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The storage for all manifested truths and elemental residuals" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class USovereignSaveableEntityComponent constinit property declarations ********
	static const UECodeGen_Private::FStructPropertyParams NewProp_EntityID;
	static const UECodeGen_Private::FStructPropertyParams NewProp_BirthTimestamp;
	static void NewProp_bUseManualBirthDate_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseManualBirthDate;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ManualBirthDate;
	static void NewProp_bIsFemale_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsFemale;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ParentID;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MotherID;
	static const UECodeGen_Private::FStructPropertyParams NewProp_FatherID;
	static const UECodeGen_Private::FIntPropertyParams NewProp_OffspringCount;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MatingHistory_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_MatingHistory;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LastMatingTimestamp;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MatingCooldownDuration;
	static const UECodeGen_Private::FBytePropertyParams NewProp_AlignmentSocket_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_AlignmentSocket;
	static const UECodeGen_Private::FBytePropertyParams NewProp_BodySocket_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_BodySocket;
	static const UECodeGen_Private::FBytePropertyParams NewProp_MagicSocket_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_MagicSocket;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AlignmentInfluence;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BodyInfluence;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MagicInfluence;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaturityProgress;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaturityRate;
	static const UECodeGen_Private::FStrPropertyParams NewProp_UnknownMetaTags_ValueProp;
	static const UECodeGen_Private::FStrPropertyParams NewProp_UnknownMetaTags_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_UnknownMetaTags;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class USovereignSaveableEntityComponent constinit property declarations **********
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("AddUnknownTag"), .Pointer = &USovereignSaveableEntityComponent::execAddUnknownTag },
		{ .NameUTF8 = UTF8TEXT("ApplyMetaTags"), .Pointer = &USovereignSaveableEntityComponent::execApplyMetaTags },
		{ .NameUTF8 = UTF8TEXT("GetGUID"), .Pointer = &USovereignSaveableEntityComponent::execGetGUID },
		{ .NameUTF8 = UTF8TEXT("GetUnknownMetaTags"), .Pointer = &USovereignSaveableEntityComponent::execGetUnknownMetaTags },
		{ .NameUTF8 = UTF8TEXT("ReceiveElementalEnergy"), .Pointer = &USovereignSaveableEntityComponent::execReceiveElementalEnergy },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_USovereignSaveableEntityComponent_AddUnknownTag, "AddUnknownTag" }, // 1394937497
		{ &Z_Construct_UFunction_USovereignSaveableEntityComponent_ApplyMetaTags, "ApplyMetaTags" }, // 1977365
		{ &Z_Construct_UFunction_USovereignSaveableEntityComponent_GetGUID, "GetGUID" }, // 1343087615
		{ &Z_Construct_UFunction_USovereignSaveableEntityComponent_GetUnknownMetaTags, "GetUnknownMetaTags" }, // 3680688764
		{ &Z_Construct_UFunction_USovereignSaveableEntityComponent_ReceiveElementalEnergy, "ReceiveElementalEnergy" }, // 2434253357
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USovereignSaveableEntityComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_USovereignSaveableEntityComponent_Statics

// ********** Begin Class USovereignSaveableEntityComponent Property Definitions *******************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_EntityID = { "EntityID", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignSaveableEntityComponent, EntityID), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EntityID_MetaData), NewProp_EntityID_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_BirthTimestamp = { "BirthTimestamp", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignSaveableEntityComponent, BirthTimestamp), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BirthTimestamp_MetaData), NewProp_BirthTimestamp_MetaData) };
void Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_bUseManualBirthDate_SetBit(void* Obj)
{
	((USovereignSaveableEntityComponent*)Obj)->bUseManualBirthDate = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_bUseManualBirthDate = { "bUseManualBirthDate", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(USovereignSaveableEntityComponent), &Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_bUseManualBirthDate_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUseManualBirthDate_MetaData), NewProp_bUseManualBirthDate_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_ManualBirthDate = { "ManualBirthDate", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignSaveableEntityComponent, ManualBirthDate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ManualBirthDate_MetaData), NewProp_ManualBirthDate_MetaData) };
void Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_bIsFemale_SetBit(void* Obj)
{
	((USovereignSaveableEntityComponent*)Obj)->bIsFemale = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_bIsFemale = { "bIsFemale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(USovereignSaveableEntityComponent), &Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_bIsFemale_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsFemale_MetaData), NewProp_bIsFemale_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_ParentID = { "ParentID", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignSaveableEntityComponent, ParentID), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ParentID_MetaData), NewProp_ParentID_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_MotherID = { "MotherID", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignSaveableEntityComponent, MotherID), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MotherID_MetaData), NewProp_MotherID_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_FatherID = { "FatherID", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignSaveableEntityComponent, FatherID), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FatherID_MetaData), NewProp_FatherID_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_OffspringCount = { "OffspringCount", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignSaveableEntityComponent, OffspringCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OffspringCount_MetaData), NewProp_OffspringCount_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_MatingHistory_Inner = { "MatingHistory", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_MatingHistory = { "MatingHistory", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignSaveableEntityComponent, MatingHistory), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MatingHistory_MetaData), NewProp_MatingHistory_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_LastMatingTimestamp = { "LastMatingTimestamp", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignSaveableEntityComponent, LastMatingTimestamp), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LastMatingTimestamp_MetaData), NewProp_LastMatingTimestamp_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_MatingCooldownDuration = { "MatingCooldownDuration", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignSaveableEntityComponent, MatingCooldownDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MatingCooldownDuration_MetaData), NewProp_MatingCooldownDuration_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_AlignmentSocket_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_AlignmentSocket = { "AlignmentSocket", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignSaveableEntityComponent, AlignmentSocket), Z_Construct_UEnum_WispCPP7VR_ESovereignElement, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AlignmentSocket_MetaData), NewProp_AlignmentSocket_MetaData) }; // 4150726421
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_BodySocket_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_BodySocket = { "BodySocket", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignSaveableEntityComponent, BodySocket), Z_Construct_UEnum_WispCPP7VR_ESovereignElement, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BodySocket_MetaData), NewProp_BodySocket_MetaData) }; // 4150726421
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_MagicSocket_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_MagicSocket = { "MagicSocket", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignSaveableEntityComponent, MagicSocket), Z_Construct_UEnum_WispCPP7VR_ESovereignElement, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MagicSocket_MetaData), NewProp_MagicSocket_MetaData) }; // 4150726421
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_AlignmentInfluence = { "AlignmentInfluence", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignSaveableEntityComponent, AlignmentInfluence), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AlignmentInfluence_MetaData), NewProp_AlignmentInfluence_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_BodyInfluence = { "BodyInfluence", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignSaveableEntityComponent, BodyInfluence), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BodyInfluence_MetaData), NewProp_BodyInfluence_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_MagicInfluence = { "MagicInfluence", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignSaveableEntityComponent, MagicInfluence), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MagicInfluence_MetaData), NewProp_MagicInfluence_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_MaturityProgress = { "MaturityProgress", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignSaveableEntityComponent, MaturityProgress), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaturityProgress_MetaData), NewProp_MaturityProgress_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_MaturityRate = { "MaturityRate", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignSaveableEntityComponent, MaturityRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaturityRate_MetaData), NewProp_MaturityRate_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_UnknownMetaTags_ValueProp = { "UnknownMetaTags", nullptr, (EPropertyFlags)0x0000000000020001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_UnknownMetaTags_Key_KeyProp = { "UnknownMetaTags_Key", nullptr, (EPropertyFlags)0x0000000000020001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_UnknownMetaTags = { "UnknownMetaTags", nullptr, (EPropertyFlags)0x0020080000020001, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignSaveableEntityComponent, UnknownMetaTags), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UnknownMetaTags_MetaData), NewProp_UnknownMetaTags_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_EntityID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_BirthTimestamp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_bUseManualBirthDate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_ManualBirthDate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_bIsFemale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_ParentID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_MotherID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_FatherID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_OffspringCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_MatingHistory_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_MatingHistory,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_LastMatingTimestamp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_MatingCooldownDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_AlignmentSocket_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_AlignmentSocket,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_BodySocket_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_BodySocket,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_MagicSocket_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_MagicSocket,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_AlignmentInfluence,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_BodyInfluence,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_MagicInfluence,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_MaturityProgress,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_MaturityRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_UnknownMetaTags_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_UnknownMetaTags_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::NewProp_UnknownMetaTags,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::PropPointers) < 2048);
// ********** End Class USovereignSaveableEntityComponent Property Definitions *********************
UObject* (*const Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_WispCPP7VR,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::ClassParams = {
	&USovereignSaveableEntityComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::Class_MetaDataParams)
};
void USovereignSaveableEntityComponent::StaticRegisterNativesUSovereignSaveableEntityComponent()
{
	UClass* Class = USovereignSaveableEntityComponent::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::Funcs));
}
UClass* Z_Construct_UClass_USovereignSaveableEntityComponent()
{
	if (!Z_Registration_Info_UClass_USovereignSaveableEntityComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USovereignSaveableEntityComponent.OuterSingleton, Z_Construct_UClass_USovereignSaveableEntityComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USovereignSaveableEntityComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, USovereignSaveableEntityComponent);
USovereignSaveableEntityComponent::~USovereignSaveableEntityComponent() {}
// ********** End Class USovereignSaveableEntityComponent ******************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Entities_SovereignSaveableEntityComponent_h__Script_WispCPP7VR_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_USovereignSaveableEntityComponent, USovereignSaveableEntityComponent::StaticClass, TEXT("USovereignSaveableEntityComponent"), &Z_Registration_Info_UClass_USovereignSaveableEntityComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USovereignSaveableEntityComponent), 1435244852U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Entities_SovereignSaveableEntityComponent_h__Script_WispCPP7VR_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Entities_SovereignSaveableEntityComponent_h__Script_WispCPP7VR_167138156{
	TEXT("/Script/WispCPP7VR"),
	Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Entities_SovereignSaveableEntityComponent_h__Script_WispCPP7VR_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Entities_SovereignSaveableEntityComponent_h__Script_WispCPP7VR_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
