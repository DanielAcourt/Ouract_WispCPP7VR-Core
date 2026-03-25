// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Interaction/SovereignEntityInterface.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSovereignEntityInterface() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
ENGINE_API UClass* Z_Construct_UClass_AController_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UMeshComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_WispCPP7VR();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignEntityInterface();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignEntityInterface_NoRegister();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignSaveableEntityComponent_NoRegister();
// ********** End Cross Module References **********************************************************

// ********** Begin Interface USovereignEntityInterface Function GetPrimaryMesh ********************
struct SovereignEntityInterface_eventGetPrimaryMesh_Parms
{
	UMeshComponent* ReturnValue;

	/** Constructor, initializes return property only **/
	SovereignEntityInterface_eventGetPrimaryMesh_Parms()
		: ReturnValue(NULL)
	{
	}
};
UMeshComponent* ISovereignEntityInterface::GetPrimaryMesh() const
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetPrimaryMesh instead.");
	SovereignEntityInterface_eventGetPrimaryMesh_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_USovereignEntityInterface_GetPrimaryMesh = FName(TEXT("GetPrimaryMesh"));
UMeshComponent* ISovereignEntityInterface::Execute_GetPrimaryMesh(const UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(USovereignEntityInterface::StaticClass()));
	SovereignEntityInterface_eventGetPrimaryMesh_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_USovereignEntityInterface_GetPrimaryMesh);
	if (Func)
	{
		const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (const ISovereignEntityInterface*)(O->GetNativeInterfaceAddress(USovereignEntityInterface::StaticClass())))
	{
		Parms.ReturnValue = I->GetPrimaryMesh_Implementation();
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_USovereignEntityInterface_GetPrimaryMesh_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Interface" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Returns the primary mesh (Skeletal or Static) of this entity. */" },
#endif
		{ "ModuleRelativePath", "Public/Interaction/SovereignEntityInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the primary mesh (Skeletal or Static) of this entity." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetPrimaryMesh constinit property declarations ************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPrimaryMesh constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPrimaryMesh Property Definitions ***********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USovereignEntityInterface_GetPrimaryMesh_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignEntityInterface_eventGetPrimaryMesh_Parms, ReturnValue), Z_Construct_UClass_UMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USovereignEntityInterface_GetPrimaryMesh_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignEntityInterface_GetPrimaryMesh_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignEntityInterface_GetPrimaryMesh_Statics::PropPointers) < 2048);
// ********** End Function GetPrimaryMesh Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USovereignEntityInterface_GetPrimaryMesh_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USovereignEntityInterface, nullptr, "GetPrimaryMesh", 	Z_Construct_UFunction_USovereignEntityInterface_GetPrimaryMesh_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignEntityInterface_GetPrimaryMesh_Statics::PropPointers), 
sizeof(SovereignEntityInterface_eventGetPrimaryMesh_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignEntityInterface_GetPrimaryMesh_Statics::Function_MetaDataParams), Z_Construct_UFunction_USovereignEntityInterface_GetPrimaryMesh_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(SovereignEntityInterface_eventGetPrimaryMesh_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USovereignEntityInterface_GetPrimaryMesh()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USovereignEntityInterface_GetPrimaryMesh_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ISovereignEntityInterface::execGetPrimaryMesh)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UMeshComponent**)Z_Param__Result=P_THIS->GetPrimaryMesh_Implementation();
	P_NATIVE_END;
}
// ********** End Interface USovereignEntityInterface Function GetPrimaryMesh **********************

// ********** Begin Interface USovereignEntityInterface Function GetSovereignSoul ******************
struct SovereignEntityInterface_eventGetSovereignSoul_Parms
{
	USovereignSaveableEntityComponent* ReturnValue;

	/** Constructor, initializes return property only **/
	SovereignEntityInterface_eventGetSovereignSoul_Parms()
		: ReturnValue(NULL)
	{
	}
};
USovereignSaveableEntityComponent* ISovereignEntityInterface::GetSovereignSoul() const
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetSovereignSoul instead.");
	SovereignEntityInterface_eventGetSovereignSoul_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_USovereignEntityInterface_GetSovereignSoul = FName(TEXT("GetSovereignSoul"));
USovereignSaveableEntityComponent* ISovereignEntityInterface::Execute_GetSovereignSoul(const UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(USovereignEntityInterface::StaticClass()));
	SovereignEntityInterface_eventGetSovereignSoul_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_USovereignEntityInterface_GetSovereignSoul);
	if (Func)
	{
		const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (const ISovereignEntityInterface*)(O->GetNativeInterfaceAddress(USovereignEntityInterface::StaticClass())))
	{
		Parms.ReturnValue = I->GetSovereignSoul_Implementation();
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_USovereignEntityInterface_GetSovereignSoul_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Interface" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Returns the Sovereign Soul (The 'One Sense of Simulated Truth'). */" },
#endif
		{ "ModuleRelativePath", "Public/Interaction/SovereignEntityInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the Sovereign Soul (The 'One Sense of Simulated Truth')." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetSovereignSoul constinit property declarations **********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSovereignSoul constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSovereignSoul Property Definitions *********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USovereignEntityInterface_GetSovereignSoul_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignEntityInterface_eventGetSovereignSoul_Parms, ReturnValue), Z_Construct_UClass_USovereignSaveableEntityComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USovereignEntityInterface_GetSovereignSoul_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignEntityInterface_GetSovereignSoul_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignEntityInterface_GetSovereignSoul_Statics::PropPointers) < 2048);
// ********** End Function GetSovereignSoul Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USovereignEntityInterface_GetSovereignSoul_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USovereignEntityInterface, nullptr, "GetSovereignSoul", 	Z_Construct_UFunction_USovereignEntityInterface_GetSovereignSoul_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignEntityInterface_GetSovereignSoul_Statics::PropPointers), 
sizeof(SovereignEntityInterface_eventGetSovereignSoul_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignEntityInterface_GetSovereignSoul_Statics::Function_MetaDataParams), Z_Construct_UFunction_USovereignEntityInterface_GetSovereignSoul_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(SovereignEntityInterface_eventGetSovereignSoul_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USovereignEntityInterface_GetSovereignSoul()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USovereignEntityInterface_GetSovereignSoul_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ISovereignEntityInterface::execGetSovereignSoul)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(USovereignSaveableEntityComponent**)Z_Param__Result=P_THIS->GetSovereignSoul_Implementation();
	P_NATIVE_END;
}
// ********** End Interface USovereignEntityInterface Function GetSovereignSoul ********************

// ********** Begin Interface USovereignEntityInterface Function OnWispEnter ***********************
struct SovereignEntityInterface_eventOnWispEnter_Parms
{
	AController* WispController;
};
void ISovereignEntityInterface::OnWispEnter(AController* WispController)
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnWispEnter instead.");
}
static FName NAME_USovereignEntityInterface_OnWispEnter = FName(TEXT("OnWispEnter"));
void ISovereignEntityInterface::Execute_OnWispEnter(UObject* O, AController* WispController)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(USovereignEntityInterface::StaticClass()));
	SovereignEntityInterface_eventOnWispEnter_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_USovereignEntityInterface_OnWispEnter);
	if (Func)
	{
		Parms.WispController=std::move(WispController);
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (ISovereignEntityInterface*)(O->GetNativeInterfaceAddress(USovereignEntityInterface::StaticClass())))
	{
		I->OnWispEnter_Implementation(WispController);
	}
}
struct Z_Construct_UFunction_USovereignEntityInterface_OnWispEnter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Interface" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The Handshake for the Wisp (Replaces native 'Possess' for non-pawns). */" },
#endif
		{ "ModuleRelativePath", "Public/Interaction/SovereignEntityInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The Handshake for the Wisp (Replaces native 'Possess' for non-pawns)." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OnWispEnter constinit property declarations ***************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WispController;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnWispEnter constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnWispEnter Property Definitions **************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USovereignEntityInterface_OnWispEnter_Statics::NewProp_WispController = { "WispController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignEntityInterface_eventOnWispEnter_Parms, WispController), Z_Construct_UClass_AController_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USovereignEntityInterface_OnWispEnter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignEntityInterface_OnWispEnter_Statics::NewProp_WispController,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignEntityInterface_OnWispEnter_Statics::PropPointers) < 2048);
// ********** End Function OnWispEnter Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USovereignEntityInterface_OnWispEnter_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USovereignEntityInterface, nullptr, "OnWispEnter", 	Z_Construct_UFunction_USovereignEntityInterface_OnWispEnter_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignEntityInterface_OnWispEnter_Statics::PropPointers), 
sizeof(SovereignEntityInterface_eventOnWispEnter_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignEntityInterface_OnWispEnter_Statics::Function_MetaDataParams), Z_Construct_UFunction_USovereignEntityInterface_OnWispEnter_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(SovereignEntityInterface_eventOnWispEnter_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USovereignEntityInterface_OnWispEnter()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USovereignEntityInterface_OnWispEnter_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ISovereignEntityInterface::execOnWispEnter)
{
	P_GET_OBJECT(AController,Z_Param_WispController);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnWispEnter_Implementation(Z_Param_WispController);
	P_NATIVE_END;
}
// ********** End Interface USovereignEntityInterface Function OnWispEnter *************************

// ********** Begin Interface USovereignEntityInterface Function OnWispExit ************************
void ISovereignEntityInterface::OnWispExit()
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnWispExit instead.");
}
static FName NAME_USovereignEntityInterface_OnWispExit = FName(TEXT("OnWispExit"));
void ISovereignEntityInterface::Execute_OnWispExit(UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(USovereignEntityInterface::StaticClass()));
	UFunction* const Func = O->FindFunction(NAME_USovereignEntityInterface_OnWispExit);
	if (Func)
	{
		O->ProcessEvent(Func, NULL);
	}
	else if (auto I = (ISovereignEntityInterface*)(O->GetNativeInterfaceAddress(USovereignEntityInterface::StaticClass())))
	{
		I->OnWispExit_Implementation();
	}
}
struct Z_Construct_UFunction_USovereignEntityInterface_OnWispExit_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Interface" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** When the Wisps Exits An Actor or character. */" },
#endif
		{ "ModuleRelativePath", "Public/Interaction/SovereignEntityInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "When the Wisps Exits An Actor or character." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OnWispExit constinit property declarations ****************************
// ********** End Function OnWispExit constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USovereignEntityInterface_OnWispExit_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USovereignEntityInterface, nullptr, "OnWispExit", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignEntityInterface_OnWispExit_Statics::Function_MetaDataParams), Z_Construct_UFunction_USovereignEntityInterface_OnWispExit_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_USovereignEntityInterface_OnWispExit()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USovereignEntityInterface_OnWispExit_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ISovereignEntityInterface::execOnWispExit)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnWispExit_Implementation();
	P_NATIVE_END;
}
// ********** End Interface USovereignEntityInterface Function OnWispExit **************************

// ********** Begin Interface USovereignEntityInterface ********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_USovereignEntityInterface;
UClass* USovereignEntityInterface::GetPrivateStaticClass()
{
	using TClass = USovereignEntityInterface;
	if (!Z_Registration_Info_UClass_USovereignEntityInterface.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SovereignEntityInterface"),
			Z_Registration_Info_UClass_USovereignEntityInterface.InnerSingleton,
			StaticRegisterNativesUSovereignEntityInterface,
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
	return Z_Registration_Info_UClass_USovereignEntityInterface.InnerSingleton;
}
UClass* Z_Construct_UClass_USovereignEntityInterface_NoRegister()
{
	return USovereignEntityInterface::GetPrivateStaticClass();
}
struct Z_Construct_UClass_USovereignEntityInterface_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Interaction/SovereignEntityInterface.h" },
	};
#endif // WITH_METADATA

// ********** Begin Interface USovereignEntityInterface constinit property declarations ************
// ********** End Interface USovereignEntityInterface constinit property declarations **************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetPrimaryMesh"), .Pointer = &ISovereignEntityInterface::execGetPrimaryMesh },
		{ .NameUTF8 = UTF8TEXT("GetSovereignSoul"), .Pointer = &ISovereignEntityInterface::execGetSovereignSoul },
		{ .NameUTF8 = UTF8TEXT("OnWispEnter"), .Pointer = &ISovereignEntityInterface::execOnWispEnter },
		{ .NameUTF8 = UTF8TEXT("OnWispExit"), .Pointer = &ISovereignEntityInterface::execOnWispExit },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_USovereignEntityInterface_GetPrimaryMesh, "GetPrimaryMesh" }, // 1645354504
		{ &Z_Construct_UFunction_USovereignEntityInterface_GetSovereignSoul, "GetSovereignSoul" }, // 109368548
		{ &Z_Construct_UFunction_USovereignEntityInterface_OnWispEnter, "OnWispEnter" }, // 3742868223
		{ &Z_Construct_UFunction_USovereignEntityInterface_OnWispExit, "OnWispExit" }, // 440962929
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ISovereignEntityInterface>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_USovereignEntityInterface_Statics
UObject* (*const Z_Construct_UClass_USovereignEntityInterface_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_WispCPP7VR,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USovereignEntityInterface_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USovereignEntityInterface_Statics::ClassParams = {
	&USovereignEntityInterface::StaticClass,
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
	0x000840A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USovereignEntityInterface_Statics::Class_MetaDataParams), Z_Construct_UClass_USovereignEntityInterface_Statics::Class_MetaDataParams)
};
void USovereignEntityInterface::StaticRegisterNativesUSovereignEntityInterface()
{
	UClass* Class = USovereignEntityInterface::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_USovereignEntityInterface_Statics::Funcs));
}
UClass* Z_Construct_UClass_USovereignEntityInterface()
{
	if (!Z_Registration_Info_UClass_USovereignEntityInterface.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USovereignEntityInterface.OuterSingleton, Z_Construct_UClass_USovereignEntityInterface_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USovereignEntityInterface.OuterSingleton;
}
USovereignEntityInterface::USovereignEntityInterface(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, USovereignEntityInterface);
// ********** End Interface USovereignEntityInterface **********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Interaction_SovereignEntityInterface_h__Script_WispCPP7VR_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_USovereignEntityInterface, USovereignEntityInterface::StaticClass, TEXT("USovereignEntityInterface"), &Z_Registration_Info_UClass_USovereignEntityInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USovereignEntityInterface), 3695919034U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Interaction_SovereignEntityInterface_h__Script_WispCPP7VR_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Interaction_SovereignEntityInterface_h__Script_WispCPP7VR_544384137{
	TEXT("/Script/WispCPP7VR"),
	Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Interaction_SovereignEntityInterface_h__Script_WispCPP7VR_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Interaction_SovereignEntityInterface_h__Script_WispCPP7VR_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
