// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SaveSystem/SovereignActorRegistry.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSovereignActorRegistry() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UWorldSubsystem();
UPackage* Z_Construct_UPackage__Script_WispCPP7VR();
WISPCPP7VR_API UClass* Z_Construct_UClass_UActorRegistry();
WISPCPP7VR_API UClass* Z_Construct_UClass_UActorRegistry_NoRegister();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UActorRegistry Function FindActor ****************************************
struct Z_Construct_UFunction_UActorRegistry_FindActor_Statics
{
	struct ActorRegistry_eventFindActor_Parms
	{
		FGuid ID;
		AActor* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Registry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Finds a specific actor using its unique Passport ID (GUID) */" },
#endif
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignActorRegistry.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Finds a specific actor using its unique Passport ID (GUID)" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function FindActor constinit property declarations *****************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ID;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function FindActor constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function FindActor Property Definitions ****************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UActorRegistry_FindActor_Statics::NewProp_ID = { "ID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ActorRegistry_eventFindActor_Parms, ID), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UActorRegistry_FindActor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ActorRegistry_eventFindActor_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UActorRegistry_FindActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UActorRegistry_FindActor_Statics::NewProp_ID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UActorRegistry_FindActor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UActorRegistry_FindActor_Statics::PropPointers) < 2048);
// ********** End Function FindActor Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UActorRegistry_FindActor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UActorRegistry, nullptr, "FindActor", 	Z_Construct_UFunction_UActorRegistry_FindActor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UActorRegistry_FindActor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UActorRegistry_FindActor_Statics::ActorRegistry_eventFindActor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UActorRegistry_FindActor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UActorRegistry_FindActor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UActorRegistry_FindActor_Statics::ActorRegistry_eventFindActor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UActorRegistry_FindActor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UActorRegistry_FindActor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UActorRegistry::execFindActor)
{
	P_GET_STRUCT(FGuid,Z_Param_ID);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(AActor**)Z_Param__Result=P_THIS->FindActor(Z_Param_ID);
	P_NATIVE_END;
}
// ********** End Class UActorRegistry Function FindActor ******************************************

// ********** Begin Class UActorRegistry Function GetTrackedActorsAsList ***************************
struct Z_Construct_UFunction_UActorRegistry_GetTrackedActorsAsList_Statics
{
	struct ActorRegistry_eventGetTrackedActorsAsList_Parms
	{
		TArray<AActor*> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Registry" },
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignActorRegistry.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetTrackedActorsAsList constinit property declarations ****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetTrackedActorsAsList constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetTrackedActorsAsList Property Definitions ***************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UActorRegistry_GetTrackedActorsAsList_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UActorRegistry_GetTrackedActorsAsList_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ActorRegistry_eventGetTrackedActorsAsList_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UActorRegistry_GetTrackedActorsAsList_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UActorRegistry_GetTrackedActorsAsList_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UActorRegistry_GetTrackedActorsAsList_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UActorRegistry_GetTrackedActorsAsList_Statics::PropPointers) < 2048);
// ********** End Function GetTrackedActorsAsList Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UActorRegistry_GetTrackedActorsAsList_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UActorRegistry, nullptr, "GetTrackedActorsAsList", 	Z_Construct_UFunction_UActorRegistry_GetTrackedActorsAsList_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UActorRegistry_GetTrackedActorsAsList_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UActorRegistry_GetTrackedActorsAsList_Statics::ActorRegistry_eventGetTrackedActorsAsList_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UActorRegistry_GetTrackedActorsAsList_Statics::Function_MetaDataParams), Z_Construct_UFunction_UActorRegistry_GetTrackedActorsAsList_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UActorRegistry_GetTrackedActorsAsList_Statics::ActorRegistry_eventGetTrackedActorsAsList_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UActorRegistry_GetTrackedActorsAsList()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UActorRegistry_GetTrackedActorsAsList_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UActorRegistry::execGetTrackedActorsAsList)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<AActor*>*)Z_Param__Result=P_THIS->GetTrackedActorsAsList();
	P_NATIVE_END;
}
// ********** End Class UActorRegistry Function GetTrackedActorsAsList *****************************

// ********** Begin Class UActorRegistry Function RegisterActor ************************************
struct Z_Construct_UFunction_UActorRegistry_RegisterActor_Statics
{
	struct ActorRegistry_eventRegisterActor_Parms
	{
		FGuid ID;
		AActor* Actor;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Registry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** * Adds an actor to the live tracking system.\n     * Called by SovereignBaseEntity in BeginPlay.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignActorRegistry.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Adds an actor to the live tracking system.\nCalled by SovereignBaseEntity in BeginPlay." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RegisterActor constinit property declarations *************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ID;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Actor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RegisterActor constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RegisterActor Property Definitions ************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UActorRegistry_RegisterActor_Statics::NewProp_ID = { "ID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ActorRegistry_eventRegisterActor_Parms, ID), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UActorRegistry_RegisterActor_Statics::NewProp_Actor = { "Actor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ActorRegistry_eventRegisterActor_Parms, Actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UActorRegistry_RegisterActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UActorRegistry_RegisterActor_Statics::NewProp_ID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UActorRegistry_RegisterActor_Statics::NewProp_Actor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UActorRegistry_RegisterActor_Statics::PropPointers) < 2048);
// ********** End Function RegisterActor Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UActorRegistry_RegisterActor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UActorRegistry, nullptr, "RegisterActor", 	Z_Construct_UFunction_UActorRegistry_RegisterActor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UActorRegistry_RegisterActor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UActorRegistry_RegisterActor_Statics::ActorRegistry_eventRegisterActor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UActorRegistry_RegisterActor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UActorRegistry_RegisterActor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UActorRegistry_RegisterActor_Statics::ActorRegistry_eventRegisterActor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UActorRegistry_RegisterActor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UActorRegistry_RegisterActor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UActorRegistry::execRegisterActor)
{
	P_GET_STRUCT(FGuid,Z_Param_ID);
	P_GET_OBJECT(AActor,Z_Param_Actor);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RegisterActor(Z_Param_ID,Z_Param_Actor);
	P_NATIVE_END;
}
// ********** End Class UActorRegistry Function RegisterActor **************************************

// ********** Begin Class UActorRegistry Function UnregisterActor **********************************
struct Z_Construct_UFunction_UActorRegistry_UnregisterActor_Statics
{
	struct ActorRegistry_eventUnregisterActor_Parms
	{
		FGuid ID;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Registry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** * Removes an actor from tracking.\n     * Called by SovereignBaseEntity in EndPlay.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignActorRegistry.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Removes an actor from tracking.\nCalled by SovereignBaseEntity in EndPlay." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function UnregisterActor constinit property declarations ***********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ID;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function UnregisterActor constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function UnregisterActor Property Definitions **********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UActorRegistry_UnregisterActor_Statics::NewProp_ID = { "ID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ActorRegistry_eventUnregisterActor_Parms, ID), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UActorRegistry_UnregisterActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UActorRegistry_UnregisterActor_Statics::NewProp_ID,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UActorRegistry_UnregisterActor_Statics::PropPointers) < 2048);
// ********** End Function UnregisterActor Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UActorRegistry_UnregisterActor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UActorRegistry, nullptr, "UnregisterActor", 	Z_Construct_UFunction_UActorRegistry_UnregisterActor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UActorRegistry_UnregisterActor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UActorRegistry_UnregisterActor_Statics::ActorRegistry_eventUnregisterActor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UActorRegistry_UnregisterActor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UActorRegistry_UnregisterActor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UActorRegistry_UnregisterActor_Statics::ActorRegistry_eventUnregisterActor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UActorRegistry_UnregisterActor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UActorRegistry_UnregisterActor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UActorRegistry::execUnregisterActor)
{
	P_GET_STRUCT(FGuid,Z_Param_ID);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UnregisterActor(Z_Param_ID);
	P_NATIVE_END;
}
// ********** End Class UActorRegistry Function UnregisterActor ************************************

// ********** Begin Class UActorRegistry ***********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UActorRegistry;
UClass* UActorRegistry::GetPrivateStaticClass()
{
	using TClass = UActorRegistry;
	if (!Z_Registration_Info_UClass_UActorRegistry.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ActorRegistry"),
			Z_Registration_Info_UClass_UActorRegistry.InnerSingleton,
			StaticRegisterNativesUActorRegistry,
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
	return Z_Registration_Info_UClass_UActorRegistry.InnerSingleton;
}
UClass* Z_Construct_UClass_UActorRegistry_NoRegister()
{
	return UActorRegistry::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UActorRegistry_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "SaveSystem/SovereignActorRegistry.h" },
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignActorRegistry.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TrackedActors_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** * Using TWeakObjectPtr prevents crashes if an Actor is destroyed\n     * without UnregisterActor being called.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/SaveSystem/SovereignActorRegistry.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Using TWeakObjectPtr prevents crashes if an Actor is destroyed\nwithout UnregisterActor being called." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UActorRegistry constinit property declarations ***************************
	static const UECodeGen_Private::FWeakObjectPropertyParams NewProp_TrackedActors_ValueProp;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TrackedActors_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_TrackedActors;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UActorRegistry constinit property declarations *****************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("FindActor"), .Pointer = &UActorRegistry::execFindActor },
		{ .NameUTF8 = UTF8TEXT("GetTrackedActorsAsList"), .Pointer = &UActorRegistry::execGetTrackedActorsAsList },
		{ .NameUTF8 = UTF8TEXT("RegisterActor"), .Pointer = &UActorRegistry::execRegisterActor },
		{ .NameUTF8 = UTF8TEXT("UnregisterActor"), .Pointer = &UActorRegistry::execUnregisterActor },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UActorRegistry_FindActor, "FindActor" }, // 2363002233
		{ &Z_Construct_UFunction_UActorRegistry_GetTrackedActorsAsList, "GetTrackedActorsAsList" }, // 3974075069
		{ &Z_Construct_UFunction_UActorRegistry_RegisterActor, "RegisterActor" }, // 289146737
		{ &Z_Construct_UFunction_UActorRegistry_UnregisterActor, "UnregisterActor" }, // 1770856208
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UActorRegistry>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UActorRegistry_Statics

// ********** Begin Class UActorRegistry Property Definitions **************************************
const UECodeGen_Private::FWeakObjectPropertyParams Z_Construct_UClass_UActorRegistry_Statics::NewProp_TrackedActors_ValueProp = { "TrackedActors", nullptr, (EPropertyFlags)0x0004000000000000, UECodeGen_Private::EPropertyGenFlags::WeakObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UActorRegistry_Statics::NewProp_TrackedActors_Key_KeyProp = { "TrackedActors_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UActorRegistry_Statics::NewProp_TrackedActors = { "TrackedActors", nullptr, (EPropertyFlags)0x0044000000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UActorRegistry, TrackedActors), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TrackedActors_MetaData), NewProp_TrackedActors_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UActorRegistry_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UActorRegistry_Statics::NewProp_TrackedActors_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UActorRegistry_Statics::NewProp_TrackedActors_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UActorRegistry_Statics::NewProp_TrackedActors,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UActorRegistry_Statics::PropPointers) < 2048);
// ********** End Class UActorRegistry Property Definitions ****************************************
UObject* (*const Z_Construct_UClass_UActorRegistry_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UWorldSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_WispCPP7VR,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UActorRegistry_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UActorRegistry_Statics::ClassParams = {
	&UActorRegistry::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UActorRegistry_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UActorRegistry_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UActorRegistry_Statics::Class_MetaDataParams), Z_Construct_UClass_UActorRegistry_Statics::Class_MetaDataParams)
};
void UActorRegistry::StaticRegisterNativesUActorRegistry()
{
	UClass* Class = UActorRegistry::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UActorRegistry_Statics::Funcs));
}
UClass* Z_Construct_UClass_UActorRegistry()
{
	if (!Z_Registration_Info_UClass_UActorRegistry.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UActorRegistry.OuterSingleton, Z_Construct_UClass_UActorRegistry_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UActorRegistry.OuterSingleton;
}
UActorRegistry::UActorRegistry() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UActorRegistry);
UActorRegistry::~UActorRegistry() {}
// ********** End Class UActorRegistry *************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_SaveSystem_SovereignActorRegistry_h__Script_WispCPP7VR_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UActorRegistry, UActorRegistry::StaticClass, TEXT("UActorRegistry"), &Z_Registration_Info_UClass_UActorRegistry, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UActorRegistry), 305840176U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_SaveSystem_SovereignActorRegistry_h__Script_WispCPP7VR_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_SaveSystem_SovereignActorRegistry_h__Script_WispCPP7VR_3545500838{
	TEXT("/Script/WispCPP7VR"),
	Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_SaveSystem_SovereignActorRegistry_h__Script_WispCPP7VR_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_SaveSystem_SovereignActorRegistry_h__Script_WispCPP7VR_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
