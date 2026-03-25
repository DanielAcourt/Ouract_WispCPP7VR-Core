// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SaveSystem/SovereignWorldSubsystem.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSovereignWorldSubsystem() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UWorldSubsystem();
UPackage* Z_Construct_UPackage__Script_WispCPP7VR();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignWorldSubsystem();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignWorldSubsystem_NoRegister();
// ********** End Cross Module References **********************************************************

// ********** Begin Class USovereignWorldSubsystem Function DeregisterEntity ***********************
struct Z_Construct_UFunction_USovereignWorldSubsystem_DeregisterEntity_Statics
{
	struct SovereignWorldSubsystem_eventDeregisterEntity_Parms
	{
		FGuid ID;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Registry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Removes an actor. Called by the Component on EndPlay. */" },
#endif
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignWorldSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Removes an actor. Called by the Component on EndPlay." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function DeregisterEntity constinit property declarations **********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ID;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function DeregisterEntity constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function DeregisterEntity Property Definitions *********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USovereignWorldSubsystem_DeregisterEntity_Statics::NewProp_ID = { "ID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignWorldSubsystem_eventDeregisterEntity_Parms, ID), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USovereignWorldSubsystem_DeregisterEntity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignWorldSubsystem_DeregisterEntity_Statics::NewProp_ID,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignWorldSubsystem_DeregisterEntity_Statics::PropPointers) < 2048);
// ********** End Function DeregisterEntity Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USovereignWorldSubsystem_DeregisterEntity_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USovereignWorldSubsystem, nullptr, "DeregisterEntity", 	Z_Construct_UFunction_USovereignWorldSubsystem_DeregisterEntity_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignWorldSubsystem_DeregisterEntity_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USovereignWorldSubsystem_DeregisterEntity_Statics::SovereignWorldSubsystem_eventDeregisterEntity_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignWorldSubsystem_DeregisterEntity_Statics::Function_MetaDataParams), Z_Construct_UFunction_USovereignWorldSubsystem_DeregisterEntity_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USovereignWorldSubsystem_DeregisterEntity_Statics::SovereignWorldSubsystem_eventDeregisterEntity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USovereignWorldSubsystem_DeregisterEntity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USovereignWorldSubsystem_DeregisterEntity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USovereignWorldSubsystem::execDeregisterEntity)
{
	P_GET_STRUCT(FGuid,Z_Param_ID);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DeregisterEntity(Z_Param_ID);
	P_NATIVE_END;
}
// ********** End Class USovereignWorldSubsystem Function DeregisterEntity *************************

// ********** Begin Class USovereignWorldSubsystem Function GetEntityByID **************************
struct Z_Construct_UFunction_USovereignWorldSubsystem_GetEntityByID_Statics
{
	struct SovereignWorldSubsystem_eventGetEntityByID_Parms
	{
		FGuid ID;
		AActor* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Registry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Finds an actor by its ID. */" },
#endif
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignWorldSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Finds an actor by its ID." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetEntityByID constinit property declarations *************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ID;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetEntityByID constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetEntityByID Property Definitions ************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USovereignWorldSubsystem_GetEntityByID_Statics::NewProp_ID = { "ID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignWorldSubsystem_eventGetEntityByID_Parms, ID), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USovereignWorldSubsystem_GetEntityByID_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignWorldSubsystem_eventGetEntityByID_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USovereignWorldSubsystem_GetEntityByID_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignWorldSubsystem_GetEntityByID_Statics::NewProp_ID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignWorldSubsystem_GetEntityByID_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignWorldSubsystem_GetEntityByID_Statics::PropPointers) < 2048);
// ********** End Function GetEntityByID Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USovereignWorldSubsystem_GetEntityByID_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USovereignWorldSubsystem, nullptr, "GetEntityByID", 	Z_Construct_UFunction_USovereignWorldSubsystem_GetEntityByID_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignWorldSubsystem_GetEntityByID_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USovereignWorldSubsystem_GetEntityByID_Statics::SovereignWorldSubsystem_eventGetEntityByID_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignWorldSubsystem_GetEntityByID_Statics::Function_MetaDataParams), Z_Construct_UFunction_USovereignWorldSubsystem_GetEntityByID_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USovereignWorldSubsystem_GetEntityByID_Statics::SovereignWorldSubsystem_eventGetEntityByID_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USovereignWorldSubsystem_GetEntityByID()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USovereignWorldSubsystem_GetEntityByID_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USovereignWorldSubsystem::execGetEntityByID)
{
	P_GET_STRUCT(FGuid,Z_Param_ID);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(AActor**)Z_Param__Result=P_THIS->GetEntityByID(Z_Param_ID);
	P_NATIVE_END;
}
// ********** End Class USovereignWorldSubsystem Function GetEntityByID ****************************

// ********** Begin Class USovereignWorldSubsystem Function GetFullRegistry ************************
struct Z_Construct_UFunction_USovereignWorldSubsystem_GetFullRegistry_Statics
{
	struct SovereignWorldSubsystem_eventGetFullRegistry_Parms
	{
		TMap<FGuid,AActor*> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Registry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Finds an actor by its Map. */" },
#endif
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignWorldSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Finds an actor by its Map." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetFullRegistry constinit property declarations ***********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_ValueProp;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetFullRegistry constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetFullRegistry Property Definitions **********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USovereignWorldSubsystem_GetFullRegistry_Statics::NewProp_ReturnValue_ValueProp = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USovereignWorldSubsystem_GetFullRegistry_Statics::NewProp_ReturnValue_Key_KeyProp = { "ReturnValue_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_USovereignWorldSubsystem_GetFullRegistry_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000008000582, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignWorldSubsystem_eventGetFullRegistry_Parms, ReturnValue), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USovereignWorldSubsystem_GetFullRegistry_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignWorldSubsystem_GetFullRegistry_Statics::NewProp_ReturnValue_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignWorldSubsystem_GetFullRegistry_Statics::NewProp_ReturnValue_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignWorldSubsystem_GetFullRegistry_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignWorldSubsystem_GetFullRegistry_Statics::PropPointers) < 2048);
// ********** End Function GetFullRegistry Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USovereignWorldSubsystem_GetFullRegistry_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USovereignWorldSubsystem, nullptr, "GetFullRegistry", 	Z_Construct_UFunction_USovereignWorldSubsystem_GetFullRegistry_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignWorldSubsystem_GetFullRegistry_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USovereignWorldSubsystem_GetFullRegistry_Statics::SovereignWorldSubsystem_eventGetFullRegistry_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignWorldSubsystem_GetFullRegistry_Statics::Function_MetaDataParams), Z_Construct_UFunction_USovereignWorldSubsystem_GetFullRegistry_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USovereignWorldSubsystem_GetFullRegistry_Statics::SovereignWorldSubsystem_eventGetFullRegistry_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USovereignWorldSubsystem_GetFullRegistry()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USovereignWorldSubsystem_GetFullRegistry_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USovereignWorldSubsystem::execGetFullRegistry)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TMap<FGuid,AActor*>*)Z_Param__Result=P_THIS->GetFullRegistry();
	P_NATIVE_END;
}
// ********** End Class USovereignWorldSubsystem Function GetFullRegistry **************************

// ********** Begin Class USovereignWorldSubsystem Function RegisterEntity *************************
struct Z_Construct_UFunction_USovereignWorldSubsystem_RegisterEntity_Statics
{
	struct SovereignWorldSubsystem_eventRegisterEntity_Parms
	{
		FGuid ID;
		AActor* Entity;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Registry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Registers an actor. Called by the Component on BeginPlay. */" },
#endif
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignWorldSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Registers an actor. Called by the Component on BeginPlay." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RegisterEntity constinit property declarations ************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ID;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Entity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RegisterEntity constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RegisterEntity Property Definitions ***********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USovereignWorldSubsystem_RegisterEntity_Statics::NewProp_ID = { "ID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignWorldSubsystem_eventRegisterEntity_Parms, ID), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USovereignWorldSubsystem_RegisterEntity_Statics::NewProp_Entity = { "Entity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignWorldSubsystem_eventRegisterEntity_Parms, Entity), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USovereignWorldSubsystem_RegisterEntity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignWorldSubsystem_RegisterEntity_Statics::NewProp_ID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignWorldSubsystem_RegisterEntity_Statics::NewProp_Entity,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignWorldSubsystem_RegisterEntity_Statics::PropPointers) < 2048);
// ********** End Function RegisterEntity Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USovereignWorldSubsystem_RegisterEntity_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USovereignWorldSubsystem, nullptr, "RegisterEntity", 	Z_Construct_UFunction_USovereignWorldSubsystem_RegisterEntity_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignWorldSubsystem_RegisterEntity_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USovereignWorldSubsystem_RegisterEntity_Statics::SovereignWorldSubsystem_eventRegisterEntity_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignWorldSubsystem_RegisterEntity_Statics::Function_MetaDataParams), Z_Construct_UFunction_USovereignWorldSubsystem_RegisterEntity_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USovereignWorldSubsystem_RegisterEntity_Statics::SovereignWorldSubsystem_eventRegisterEntity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USovereignWorldSubsystem_RegisterEntity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USovereignWorldSubsystem_RegisterEntity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USovereignWorldSubsystem::execRegisterEntity)
{
	P_GET_STRUCT(FGuid,Z_Param_ID);
	P_GET_OBJECT(AActor,Z_Param_Entity);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RegisterEntity(Z_Param_ID,Z_Param_Entity);
	P_NATIVE_END;
}
// ********** End Class USovereignWorldSubsystem Function RegisterEntity ***************************

// ********** Begin Class USovereignWorldSubsystem *************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_USovereignWorldSubsystem;
UClass* USovereignWorldSubsystem::GetPrivateStaticClass()
{
	using TClass = USovereignWorldSubsystem;
	if (!Z_Registration_Info_UClass_USovereignWorldSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SovereignWorldSubsystem"),
			Z_Registration_Info_UClass_USovereignWorldSubsystem.InnerSingleton,
			StaticRegisterNativesUSovereignWorldSubsystem,
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
	return Z_Registration_Info_UClass_USovereignWorldSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_USovereignWorldSubsystem_NoRegister()
{
	return USovereignWorldSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_USovereignWorldSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "SaveSystem/SovereignWorldSubsystem.h" },
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignWorldSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EntityRegistry_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The Master Map: This is the \"Phone Book\" for the garden. */" },
#endif
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignWorldSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The Master Map: This is the \"Phone Book\" for the garden." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class USovereignWorldSubsystem constinit property declarations *****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EntityRegistry_ValueProp;
	static const UECodeGen_Private::FStructPropertyParams NewProp_EntityRegistry_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_EntityRegistry;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class USovereignWorldSubsystem constinit property declarations *******************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("DeregisterEntity"), .Pointer = &USovereignWorldSubsystem::execDeregisterEntity },
		{ .NameUTF8 = UTF8TEXT("GetEntityByID"), .Pointer = &USovereignWorldSubsystem::execGetEntityByID },
		{ .NameUTF8 = UTF8TEXT("GetFullRegistry"), .Pointer = &USovereignWorldSubsystem::execGetFullRegistry },
		{ .NameUTF8 = UTF8TEXT("RegisterEntity"), .Pointer = &USovereignWorldSubsystem::execRegisterEntity },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_USovereignWorldSubsystem_DeregisterEntity, "DeregisterEntity" }, // 1282330077
		{ &Z_Construct_UFunction_USovereignWorldSubsystem_GetEntityByID, "GetEntityByID" }, // 4002378481
		{ &Z_Construct_UFunction_USovereignWorldSubsystem_GetFullRegistry, "GetFullRegistry" }, // 178521665
		{ &Z_Construct_UFunction_USovereignWorldSubsystem_RegisterEntity, "RegisterEntity" }, // 3907513629
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USovereignWorldSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_USovereignWorldSubsystem_Statics

// ********** Begin Class USovereignWorldSubsystem Property Definitions ****************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USovereignWorldSubsystem_Statics::NewProp_EntityRegistry_ValueProp = { "EntityRegistry", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USovereignWorldSubsystem_Statics::NewProp_EntityRegistry_Key_KeyProp = { "EntityRegistry_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_USovereignWorldSubsystem_Statics::NewProp_EntityRegistry = { "EntityRegistry", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignWorldSubsystem, EntityRegistry), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EntityRegistry_MetaData), NewProp_EntityRegistry_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USovereignWorldSubsystem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignWorldSubsystem_Statics::NewProp_EntityRegistry_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignWorldSubsystem_Statics::NewProp_EntityRegistry_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignWorldSubsystem_Statics::NewProp_EntityRegistry,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USovereignWorldSubsystem_Statics::PropPointers) < 2048);
// ********** End Class USovereignWorldSubsystem Property Definitions ******************************
UObject* (*const Z_Construct_UClass_USovereignWorldSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UWorldSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_WispCPP7VR,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USovereignWorldSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USovereignWorldSubsystem_Statics::ClassParams = {
	&USovereignWorldSubsystem::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_USovereignWorldSubsystem_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_USovereignWorldSubsystem_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USovereignWorldSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_USovereignWorldSubsystem_Statics::Class_MetaDataParams)
};
void USovereignWorldSubsystem::StaticRegisterNativesUSovereignWorldSubsystem()
{
	UClass* Class = USovereignWorldSubsystem::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_USovereignWorldSubsystem_Statics::Funcs));
}
UClass* Z_Construct_UClass_USovereignWorldSubsystem()
{
	if (!Z_Registration_Info_UClass_USovereignWorldSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USovereignWorldSubsystem.OuterSingleton, Z_Construct_UClass_USovereignWorldSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USovereignWorldSubsystem.OuterSingleton;
}
USovereignWorldSubsystem::USovereignWorldSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, USovereignWorldSubsystem);
USovereignWorldSubsystem::~USovereignWorldSubsystem() {}
// ********** End Class USovereignWorldSubsystem ***************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_SaveSystem_SovereignWorldSubsystem_h__Script_WispCPP7VR_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_USovereignWorldSubsystem, USovereignWorldSubsystem::StaticClass, TEXT("USovereignWorldSubsystem"), &Z_Registration_Info_UClass_USovereignWorldSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USovereignWorldSubsystem), 3703472708U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_SaveSystem_SovereignWorldSubsystem_h__Script_WispCPP7VR_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_SaveSystem_SovereignWorldSubsystem_h__Script_WispCPP7VR_3489787381{
	TEXT("/Script/WispCPP7VR"),
	Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_SaveSystem_SovereignWorldSubsystem_h__Script_WispCPP7VR_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_SaveSystem_SovereignWorldSubsystem_h__Script_WispCPP7VR_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
