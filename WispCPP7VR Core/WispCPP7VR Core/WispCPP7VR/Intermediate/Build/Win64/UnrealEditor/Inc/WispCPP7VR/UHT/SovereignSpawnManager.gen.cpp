// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Subsystems/SovereignSpawnManager.h"
#include "Engine/GameInstance.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSovereignSpawnManager() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
UPackage* Z_Construct_UPackage__Script_WispCPP7VR();
WISPCPP7VR_API UClass* Z_Construct_UClass_ASovereignBaseEntity_NoRegister();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignSpawnManager();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignSpawnManager_NoRegister();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignSpeciesData_NoRegister();
WISPCPP7VR_API UScriptStruct* Z_Construct_UScriptStruct_FSpawnRequest();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FSpawnRequest *****************************************************
struct Z_Construct_UScriptStruct_FSpawnRequest_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FSpawnRequest); }
	static inline consteval int16 GetStructAlignment() { return alignof(FSpawnRequest); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** * FSpawnRequest: A 'Data Package' that holds all the instructions needed to create a lifeform.\n * This is queued so the engine can process it without hitching (Asynchronous loading).\n */" },
#endif
		{ "ModuleRelativePath", "Public/Subsystems/SovereignSpawnManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "FSpawnRequest: A 'Data Package' that holds all the instructions needed to create a lifeform.\nThis is queued so the engine can process it without hitching (Asynchronous loading)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RequestID_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Unique ID for this specific spawn attempt, used for tracking in the queue */" },
#endif
		{ "ModuleRelativePath", "Public/Subsystems/SovereignSpawnManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Unique ID for this specific spawn attempt, used for tracking in the queue" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpeciesData_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The 'Genetic Template' from your Directory Scanner/Registry (Oak, Bee, Dragon) */" },
#endif
		{ "ModuleRelativePath", "Public/Subsystems/SovereignSpawnManager.h" },
		{ "NativeConst", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The 'Genetic Template' from your Directory Scanner/Registry (Oak, Bee, Dragon)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Transform_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Where in the 3D Chunk this entity should appear */" },
#endif
		{ "ModuleRelativePath", "Public/Subsystems/SovereignSpawnManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Where in the 3D Chunk this entity should appear" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ParentID_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** * Refers to the 'Gene Seed' transform.\n\x09 * Note: Using FTransform for a ParentID is unusual; typically this would be a GUID\n\x09 * or a link to a static DNA table.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/Subsystems/SovereignSpawnManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Refers to the 'Gene Seed' transform.\nNote: Using FTransform for a ParentID is unusual; typically this would be a GUID\nor a link to a static DNA table." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MotherID_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The GUID of the biological Mother. Essential for lineage and trait inheritance. */" },
#endif
		{ "ModuleRelativePath", "Public/Subsystems/SovereignSpawnManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The GUID of the biological Mother. Essential for lineage and trait inheritance." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FatherID_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The GUID of the biological Father. Allows for multi-parent trait mixing. */" },
#endif
		{ "ModuleRelativePath", "Public/Subsystems/SovereignSpawnManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The GUID of the biological Father. Allows for multi-parent trait mixing." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InitialMetadata_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** * The 'Truth' Payload: This is the TMap of key-value pairs from your JSON.\n\x09\x09 * It carries the 'Sandwich' tags, Qi levels, and health from the last save.\n\x09\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/Subsystems/SovereignSpawnManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The 'Truth' Payload: This is the TMap of key-value pairs from your JSON.\nIt carries the 'Sandwich' tags, Qi levels, and health from the last save." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FSpawnRequest constinit property declarations *********************
	static const UECodeGen_Private::FIntPropertyParams NewProp_RequestID;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpeciesData;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Transform;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ParentID;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MotherID;
	static const UECodeGen_Private::FStructPropertyParams NewProp_FatherID;
	static const UECodeGen_Private::FStrPropertyParams NewProp_InitialMetadata_ValueProp;
	static const UECodeGen_Private::FStrPropertyParams NewProp_InitialMetadata_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_InitialMetadata;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FSpawnRequest constinit property declarations ***********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSpawnRequest>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FSpawnRequest_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FSpawnRequest;
class UScriptStruct* FSpawnRequest::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FSpawnRequest.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FSpawnRequest.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSpawnRequest, (UObject*)Z_Construct_UPackage__Script_WispCPP7VR(), TEXT("SpawnRequest"));
	}
	return Z_Registration_Info_UScriptStruct_FSpawnRequest.OuterSingleton;
	}

// ********** Begin ScriptStruct FSpawnRequest Property Definitions ********************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSpawnRequest_Statics::NewProp_RequestID = { "RequestID", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSpawnRequest, RequestID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RequestID_MetaData), NewProp_RequestID_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FSpawnRequest_Statics::NewProp_SpeciesData = { "SpeciesData", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSpawnRequest, SpeciesData), Z_Construct_UClass_USovereignSpeciesData_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpeciesData_MetaData), NewProp_SpeciesData_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSpawnRequest_Statics::NewProp_Transform = { "Transform", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSpawnRequest, Transform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Transform_MetaData), NewProp_Transform_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSpawnRequest_Statics::NewProp_ParentID = { "ParentID", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSpawnRequest, ParentID), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ParentID_MetaData), NewProp_ParentID_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSpawnRequest_Statics::NewProp_MotherID = { "MotherID", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSpawnRequest, MotherID), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MotherID_MetaData), NewProp_MotherID_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSpawnRequest_Statics::NewProp_FatherID = { "FatherID", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSpawnRequest, FatherID), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FatherID_MetaData), NewProp_FatherID_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSpawnRequest_Statics::NewProp_InitialMetadata_ValueProp = { "InitialMetadata", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSpawnRequest_Statics::NewProp_InitialMetadata_Key_KeyProp = { "InitialMetadata_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UScriptStruct_FSpawnRequest_Statics::NewProp_InitialMetadata = { "InitialMetadata", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSpawnRequest, InitialMetadata), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InitialMetadata_MetaData), NewProp_InitialMetadata_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSpawnRequest_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSpawnRequest_Statics::NewProp_RequestID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSpawnRequest_Statics::NewProp_SpeciesData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSpawnRequest_Statics::NewProp_Transform,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSpawnRequest_Statics::NewProp_ParentID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSpawnRequest_Statics::NewProp_MotherID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSpawnRequest_Statics::NewProp_FatherID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSpawnRequest_Statics::NewProp_InitialMetadata_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSpawnRequest_Statics::NewProp_InitialMetadata_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSpawnRequest_Statics::NewProp_InitialMetadata,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSpawnRequest_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FSpawnRequest Property Definitions **********************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSpawnRequest_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_WispCPP7VR,
	nullptr,
	&NewStructOps,
	"SpawnRequest",
	Z_Construct_UScriptStruct_FSpawnRequest_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSpawnRequest_Statics::PropPointers),
	sizeof(FSpawnRequest),
	alignof(FSpawnRequest),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSpawnRequest_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSpawnRequest_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FSpawnRequest()
{
	if (!Z_Registration_Info_UScriptStruct_FSpawnRequest.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FSpawnRequest.InnerSingleton, Z_Construct_UScriptStruct_FSpawnRequest_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FSpawnRequest.InnerSingleton);
}
// ********** End ScriptStruct FSpawnRequest *******************************************************

// ********** Begin Class USovereignSpawnManager Function RequestSpawn *****************************
struct Z_Construct_UFunction_USovereignSpawnManager_RequestSpawn_Statics
{
	struct SovereignSpawnManager_eventRequestSpawn_Parms
	{
		const USovereignSpeciesData* SpeciesData;
		FTransform Transform;
		FGuid MotherID;
		FGuid FatherID;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Spawning" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** * The Primary Command: Use this to tell the machine to create an entity.\n\x09 * This is what your JSON parser calls for every entry in the \"Entities\" array.\n\x09 */" },
#endif
		{ "CPP_Default_FatherID", "()" },
		{ "ModuleRelativePath", "Public/Subsystems/SovereignSpawnManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The Primary Command: Use this to tell the machine to create an entity.\nThis is what your JSON parser calls for every entry in the \"Entities\" array." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpeciesData_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Transform_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MotherID_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FatherID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RequestSpawn constinit property declarations **************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpeciesData;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Transform;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MotherID;
	static const UECodeGen_Private::FStructPropertyParams NewProp_FatherID;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RequestSpawn constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RequestSpawn Property Definitions *************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USovereignSpawnManager_RequestSpawn_Statics::NewProp_SpeciesData = { "SpeciesData", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignSpawnManager_eventRequestSpawn_Parms, SpeciesData), Z_Construct_UClass_USovereignSpeciesData_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpeciesData_MetaData), NewProp_SpeciesData_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USovereignSpawnManager_RequestSpawn_Statics::NewProp_Transform = { "Transform", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignSpawnManager_eventRequestSpawn_Parms, Transform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Transform_MetaData), NewProp_Transform_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USovereignSpawnManager_RequestSpawn_Statics::NewProp_MotherID = { "MotherID", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignSpawnManager_eventRequestSpawn_Parms, MotherID), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MotherID_MetaData), NewProp_MotherID_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USovereignSpawnManager_RequestSpawn_Statics::NewProp_FatherID = { "FatherID", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignSpawnManager_eventRequestSpawn_Parms, FatherID), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FatherID_MetaData), NewProp_FatherID_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USovereignSpawnManager_RequestSpawn_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignSpawnManager_RequestSpawn_Statics::NewProp_SpeciesData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignSpawnManager_RequestSpawn_Statics::NewProp_Transform,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignSpawnManager_RequestSpawn_Statics::NewProp_MotherID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignSpawnManager_RequestSpawn_Statics::NewProp_FatherID,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignSpawnManager_RequestSpawn_Statics::PropPointers) < 2048);
// ********** End Function RequestSpawn Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USovereignSpawnManager_RequestSpawn_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USovereignSpawnManager, nullptr, "RequestSpawn", 	Z_Construct_UFunction_USovereignSpawnManager_RequestSpawn_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignSpawnManager_RequestSpawn_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USovereignSpawnManager_RequestSpawn_Statics::SovereignSpawnManager_eventRequestSpawn_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignSpawnManager_RequestSpawn_Statics::Function_MetaDataParams), Z_Construct_UFunction_USovereignSpawnManager_RequestSpawn_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USovereignSpawnManager_RequestSpawn_Statics::SovereignSpawnManager_eventRequestSpawn_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USovereignSpawnManager_RequestSpawn()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USovereignSpawnManager_RequestSpawn_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USovereignSpawnManager::execRequestSpawn)
{
	P_GET_OBJECT(USovereignSpeciesData,Z_Param_SpeciesData);
	P_GET_STRUCT_REF(FTransform,Z_Param_Out_Transform);
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_MotherID);
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_FatherID);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RequestSpawn(Z_Param_SpeciesData,Z_Param_Out_Transform,Z_Param_Out_MotherID,Z_Param_Out_FatherID);
	P_NATIVE_END;
}
// ********** End Class USovereignSpawnManager Function RequestSpawn *******************************

// ********** Begin Class USovereignSpawnManager ***************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_USovereignSpawnManager;
UClass* USovereignSpawnManager::GetPrivateStaticClass()
{
	using TClass = USovereignSpawnManager;
	if (!Z_Registration_Info_UClass_USovereignSpawnManager.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SovereignSpawnManager"),
			Z_Registration_Info_UClass_USovereignSpawnManager.InnerSingleton,
			StaticRegisterNativesUSovereignSpawnManager,
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
	return Z_Registration_Info_UClass_USovereignSpawnManager.InnerSingleton;
}
UClass* Z_Construct_UClass_USovereignSpawnManager_NoRegister()
{
	return USovereignSpawnManager::GetPrivateStaticClass();
}
struct Z_Construct_UClass_USovereignSpawnManager_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * USovereignSpawnManager: The 'Factory' that manufactures Sovereign Souls.\n * It manages the SpawnQueue to ensure that thousands of entities don't crash the game\n * by trying to spawn all at the exact same frame.\n */" },
#endif
		{ "IncludePath", "Subsystems/SovereignSpawnManager.h" },
		{ "ModuleRelativePath", "Public/Subsystems/SovereignSpawnManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "USovereignSpawnManager: The 'Factory' that manufactures Sovereign Souls.\nIt manages the SpawnQueue to ensure that thousands of entities don't crash the game\nby trying to spawn all at the exact same frame." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnQueue_MetaData[] = {
		{ "ModuleRelativePath", "Public/Subsystems/SovereignSpawnManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FallbackUnknownClass_MetaData[] = {
		{ "Category", "Sovereign|Spawning" },
		{ "ModuleRelativePath", "Public/Subsystems/SovereignSpawnManager.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class USovereignSpawnManager constinit property declarations *******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpawnQueue_ValueProp;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SpawnQueue_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_SpawnQueue;
	static const UECodeGen_Private::FClassPropertyParams NewProp_FallbackUnknownClass;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class USovereignSpawnManager constinit property declarations *********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("RequestSpawn"), .Pointer = &USovereignSpawnManager::execRequestSpawn },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_USovereignSpawnManager_RequestSpawn, "RequestSpawn" }, // 1980029119
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USovereignSpawnManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_USovereignSpawnManager_Statics

// ********** Begin Class USovereignSpawnManager Property Definitions ******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USovereignSpawnManager_Statics::NewProp_SpawnQueue_ValueProp = { "SpawnQueue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FSpawnRequest, METADATA_PARAMS(0, nullptr) }; // 2899264497
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_USovereignSpawnManager_Statics::NewProp_SpawnQueue_Key_KeyProp = { "SpawnQueue_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_USovereignSpawnManager_Statics::NewProp_SpawnQueue = { "SpawnQueue", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignSpawnManager, SpawnQueue), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnQueue_MetaData), NewProp_SpawnQueue_MetaData) }; // 2899264497
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_USovereignSpawnManager_Statics::NewProp_FallbackUnknownClass = { "FallbackUnknownClass", nullptr, (EPropertyFlags)0x0044000000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignSpawnManager, FallbackUnknownClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_ASovereignBaseEntity_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FallbackUnknownClass_MetaData), NewProp_FallbackUnknownClass_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USovereignSpawnManager_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignSpawnManager_Statics::NewProp_SpawnQueue_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignSpawnManager_Statics::NewProp_SpawnQueue_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignSpawnManager_Statics::NewProp_SpawnQueue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignSpawnManager_Statics::NewProp_FallbackUnknownClass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USovereignSpawnManager_Statics::PropPointers) < 2048);
// ********** End Class USovereignSpawnManager Property Definitions ********************************
UObject* (*const Z_Construct_UClass_USovereignSpawnManager_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_WispCPP7VR,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USovereignSpawnManager_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USovereignSpawnManager_Statics::ClassParams = {
	&USovereignSpawnManager::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_USovereignSpawnManager_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_USovereignSpawnManager_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USovereignSpawnManager_Statics::Class_MetaDataParams), Z_Construct_UClass_USovereignSpawnManager_Statics::Class_MetaDataParams)
};
void USovereignSpawnManager::StaticRegisterNativesUSovereignSpawnManager()
{
	UClass* Class = USovereignSpawnManager::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_USovereignSpawnManager_Statics::Funcs));
}
UClass* Z_Construct_UClass_USovereignSpawnManager()
{
	if (!Z_Registration_Info_UClass_USovereignSpawnManager.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USovereignSpawnManager.OuterSingleton, Z_Construct_UClass_USovereignSpawnManager_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USovereignSpawnManager.OuterSingleton;
}
USovereignSpawnManager::USovereignSpawnManager() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, USovereignSpawnManager);
USovereignSpawnManager::~USovereignSpawnManager() {}
// ********** End Class USovereignSpawnManager *****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Subsystems_SovereignSpawnManager_h__Script_WispCPP7VR_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FSpawnRequest::StaticStruct, Z_Construct_UScriptStruct_FSpawnRequest_Statics::NewStructOps, TEXT("SpawnRequest"),&Z_Registration_Info_UScriptStruct_FSpawnRequest, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSpawnRequest), 2899264497U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_USovereignSpawnManager, USovereignSpawnManager::StaticClass, TEXT("USovereignSpawnManager"), &Z_Registration_Info_UClass_USovereignSpawnManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USovereignSpawnManager), 1281225869U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Subsystems_SovereignSpawnManager_h__Script_WispCPP7VR_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Subsystems_SovereignSpawnManager_h__Script_WispCPP7VR_412639739{
	TEXT("/Script/WispCPP7VR"),
	Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Subsystems_SovereignSpawnManager_h__Script_WispCPP7VR_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Subsystems_SovereignSpawnManager_h__Script_WispCPP7VR_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Subsystems_SovereignSpawnManager_h__Script_WispCPP7VR_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Subsystems_SovereignSpawnManager_h__Script_WispCPP7VR_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
