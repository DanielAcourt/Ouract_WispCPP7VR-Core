// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Components/SovereignControllerComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSovereignControllerComponent() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AController_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
UPackage* Z_Construct_UPackage__Script_WispCPP7VR();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignControllerComponent();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignControllerComponent_NoRegister();
// ********** End Cross Module References **********************************************************

// ********** Begin Class USovereignControllerComponent Function OnPossessed ***********************
struct Z_Construct_UFunction_USovereignControllerComponent_OnPossessed_Statics
{
	struct SovereignControllerComponent_eventOnPossessed_Parms
	{
		AController* NewController;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Possession" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Called when the parent Pawn is possessed by ANY controller */" },
#endif
		{ "ModuleRelativePath", "Public/Components/SovereignControllerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when the parent Pawn is possessed by ANY controller" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OnPossessed constinit property declarations ***************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NewController;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnPossessed constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnPossessed Property Definitions **************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USovereignControllerComponent_OnPossessed_Statics::NewProp_NewController = { "NewController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignControllerComponent_eventOnPossessed_Parms, NewController), Z_Construct_UClass_AController_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USovereignControllerComponent_OnPossessed_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignControllerComponent_OnPossessed_Statics::NewProp_NewController,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignControllerComponent_OnPossessed_Statics::PropPointers) < 2048);
// ********** End Function OnPossessed Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USovereignControllerComponent_OnPossessed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USovereignControllerComponent, nullptr, "OnPossessed", 	Z_Construct_UFunction_USovereignControllerComponent_OnPossessed_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignControllerComponent_OnPossessed_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USovereignControllerComponent_OnPossessed_Statics::SovereignControllerComponent_eventOnPossessed_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignControllerComponent_OnPossessed_Statics::Function_MetaDataParams), Z_Construct_UFunction_USovereignControllerComponent_OnPossessed_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USovereignControllerComponent_OnPossessed_Statics::SovereignControllerComponent_eventOnPossessed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USovereignControllerComponent_OnPossessed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USovereignControllerComponent_OnPossessed_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USovereignControllerComponent::execOnPossessed)
{
	P_GET_OBJECT(AController,Z_Param_NewController);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnPossessed(Z_Param_NewController);
	P_NATIVE_END;
}
// ********** End Class USovereignControllerComponent Function OnPossessed *************************

// ********** Begin Class USovereignControllerComponent Function OnUnpossessed *********************
struct Z_Construct_UFunction_USovereignControllerComponent_OnUnpossessed_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Possession" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Called when the parent Pawn is unpossessed */" },
#endif
		{ "ModuleRelativePath", "Public/Components/SovereignControllerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when the parent Pawn is unpossessed" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OnUnpossessed constinit property declarations *************************
// ********** End Function OnUnpossessed constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USovereignControllerComponent_OnUnpossessed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USovereignControllerComponent, nullptr, "OnUnpossessed", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignControllerComponent_OnUnpossessed_Statics::Function_MetaDataParams), Z_Construct_UFunction_USovereignControllerComponent_OnUnpossessed_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_USovereignControllerComponent_OnUnpossessed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USovereignControllerComponent_OnUnpossessed_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USovereignControllerComponent::execOnUnpossessed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnUnpossessed();
	P_NATIVE_END;
}
// ********** End Class USovereignControllerComponent Function OnUnpossessed ***********************

// ********** Begin Class USovereignControllerComponent ********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_USovereignControllerComponent;
UClass* USovereignControllerComponent::GetPrivateStaticClass()
{
	using TClass = USovereignControllerComponent;
	if (!Z_Registration_Info_UClass_USovereignControllerComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SovereignControllerComponent"),
			Z_Registration_Info_UClass_USovereignControllerComponent.InnerSingleton,
			StaticRegisterNativesUSovereignControllerComponent,
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
	return Z_Registration_Info_UClass_USovereignControllerComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_USovereignControllerComponent_NoRegister()
{
	return USovereignControllerComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_USovereignControllerComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "Components/SovereignControllerComponent.h" },
		{ "ModuleRelativePath", "Public/Components/SovereignControllerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsPlayerPossessed_MetaData[] = {
		{ "Category", "Sovereign|Possession" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Track if a human is currently controlling this vessel */" },
#endif
		{ "ModuleRelativePath", "Public/Components/SovereignControllerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Track if a human is currently controlling this vessel" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentController_MetaData[] = {
		{ "Category", "Sovereign|Possession" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Reference to the current controller (Player or AI) */" },
#endif
		{ "ModuleRelativePath", "Public/Components/SovereignControllerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Reference to the current controller (Player or AI)" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class USovereignControllerComponent constinit property declarations ************
	static void NewProp_bIsPlayerPossessed_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsPlayerPossessed;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CurrentController;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class USovereignControllerComponent constinit property declarations **************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("OnPossessed"), .Pointer = &USovereignControllerComponent::execOnPossessed },
		{ .NameUTF8 = UTF8TEXT("OnUnpossessed"), .Pointer = &USovereignControllerComponent::execOnUnpossessed },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_USovereignControllerComponent_OnPossessed, "OnPossessed" }, // 130297428
		{ &Z_Construct_UFunction_USovereignControllerComponent_OnUnpossessed, "OnUnpossessed" }, // 3799961532
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USovereignControllerComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_USovereignControllerComponent_Statics

// ********** Begin Class USovereignControllerComponent Property Definitions ***********************
void Z_Construct_UClass_USovereignControllerComponent_Statics::NewProp_bIsPlayerPossessed_SetBit(void* Obj)
{
	((USovereignControllerComponent*)Obj)->bIsPlayerPossessed = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USovereignControllerComponent_Statics::NewProp_bIsPlayerPossessed = { "bIsPlayerPossessed", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(USovereignControllerComponent), &Z_Construct_UClass_USovereignControllerComponent_Statics::NewProp_bIsPlayerPossessed_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsPlayerPossessed_MetaData), NewProp_bIsPlayerPossessed_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USovereignControllerComponent_Statics::NewProp_CurrentController = { "CurrentController", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignControllerComponent, CurrentController), Z_Construct_UClass_AController_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentController_MetaData), NewProp_CurrentController_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USovereignControllerComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignControllerComponent_Statics::NewProp_bIsPlayerPossessed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignControllerComponent_Statics::NewProp_CurrentController,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USovereignControllerComponent_Statics::PropPointers) < 2048);
// ********** End Class USovereignControllerComponent Property Definitions *************************
UObject* (*const Z_Construct_UClass_USovereignControllerComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_WispCPP7VR,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USovereignControllerComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USovereignControllerComponent_Statics::ClassParams = {
	&USovereignControllerComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_USovereignControllerComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_USovereignControllerComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USovereignControllerComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_USovereignControllerComponent_Statics::Class_MetaDataParams)
};
void USovereignControllerComponent::StaticRegisterNativesUSovereignControllerComponent()
{
	UClass* Class = USovereignControllerComponent::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_USovereignControllerComponent_Statics::Funcs));
}
UClass* Z_Construct_UClass_USovereignControllerComponent()
{
	if (!Z_Registration_Info_UClass_USovereignControllerComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USovereignControllerComponent.OuterSingleton, Z_Construct_UClass_USovereignControllerComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USovereignControllerComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, USovereignControllerComponent);
USovereignControllerComponent::~USovereignControllerComponent() {}
// ********** End Class USovereignControllerComponent **********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Components_SovereignControllerComponent_h__Script_WispCPP7VR_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_USovereignControllerComponent, USovereignControllerComponent::StaticClass, TEXT("USovereignControllerComponent"), &Z_Registration_Info_UClass_USovereignControllerComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USovereignControllerComponent), 1634097256U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Components_SovereignControllerComponent_h__Script_WispCPP7VR_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Components_SovereignControllerComponent_h__Script_WispCPP7VR_2128299180{
	TEXT("/Script/WispCPP7VR"),
	Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Components_SovereignControllerComponent_h__Script_WispCPP7VR_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Components_SovereignControllerComponent_h__Script_WispCPP7VR_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
