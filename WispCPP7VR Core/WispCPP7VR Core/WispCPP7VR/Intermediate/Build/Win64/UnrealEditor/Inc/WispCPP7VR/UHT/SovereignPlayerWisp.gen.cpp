// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Entities/SovereignPlayerWisp.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSovereignPlayerWisp() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
NIAGARA_API UClass* Z_Construct_UClass_UNiagaraComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_WispCPP7VR();
WISPCPP7VR_API UClass* Z_Construct_UClass_ASovereignBaseCharacter();
WISPCPP7VR_API UClass* Z_Construct_UClass_ASovereignPlayerWisp();
WISPCPP7VR_API UClass* Z_Construct_UClass_ASovereignPlayerWisp_NoRegister();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ASovereignPlayerWisp Function AttemptPossession **************************
struct Z_Construct_UFunction_ASovereignPlayerWisp_AttemptPossession_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Possession" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// --- Wisp Logic ---\n" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignPlayerWisp.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- Wisp Logic ---" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function AttemptPossession constinit property declarations *********************
// ********** End Function AttemptPossession constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASovereignPlayerWisp_AttemptPossession_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ASovereignPlayerWisp, nullptr, "AttemptPossession", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASovereignPlayerWisp_AttemptPossession_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASovereignPlayerWisp_AttemptPossession_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_ASovereignPlayerWisp_AttemptPossession()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASovereignPlayerWisp_AttemptPossession_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASovereignPlayerWisp::execAttemptPossession)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AttemptPossession();
	P_NATIVE_END;
}
// ********** End Class ASovereignPlayerWisp Function AttemptPossession ****************************

// ********** Begin Class ASovereignPlayerWisp Function EjectFromHost ******************************
struct Z_Construct_UFunction_ASovereignPlayerWisp_EjectFromHost_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Possession" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Pops the Wisp out of the current host */" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignPlayerWisp.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Pops the Wisp out of the current host" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function EjectFromHost constinit property declarations *************************
// ********** End Function EjectFromHost constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASovereignPlayerWisp_EjectFromHost_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ASovereignPlayerWisp, nullptr, "EjectFromHost", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASovereignPlayerWisp_EjectFromHost_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASovereignPlayerWisp_EjectFromHost_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_ASovereignPlayerWisp_EjectFromHost()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASovereignPlayerWisp_EjectFromHost_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASovereignPlayerWisp::execEjectFromHost)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->EjectFromHost();
	P_NATIVE_END;
}
// ********** End Class ASovereignPlayerWisp Function EjectFromHost ********************************

// ********** Begin Class ASovereignPlayerWisp Function Evolve_Implementation **********************
struct Z_Construct_UFunction_ASovereignPlayerWisp_Evolve_Implementation_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Evolve" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Declaring Evolve here fixes Error C2509 */" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignPlayerWisp.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Declaring Evolve here fixes Error C2509" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function Evolve_Implementation constinit property declarations *****************
// ********** End Function Evolve_Implementation constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASovereignPlayerWisp_Evolve_Implementation_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ASovereignPlayerWisp, nullptr, "Evolve_Implementation", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASovereignPlayerWisp_Evolve_Implementation_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASovereignPlayerWisp_Evolve_Implementation_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_ASovereignPlayerWisp_Evolve_Implementation()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASovereignPlayerWisp_Evolve_Implementation_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASovereignPlayerWisp::execEvolve_Implementation)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Evolve_Implementation();
	P_NATIVE_END;
}
// ********** End Class ASovereignPlayerWisp Function Evolve_Implementation ************************

// ********** Begin Class ASovereignPlayerWisp Function GetSpiritForwardVector *********************
struct Z_Construct_UFunction_ASovereignPlayerWisp_GetSpiritForwardVector_Statics
{
	struct SovereignPlayerWisp_eventGetSpiritForwardVector_Parms
	{
		FVector ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Senses" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Returns the direction the Spirit is currently 'focusing' */" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignPlayerWisp.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the direction the Spirit is currently 'focusing'" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetSpiritForwardVector constinit property declarations ****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSpiritForwardVector constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSpiritForwardVector Property Definitions ***************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASovereignPlayerWisp_GetSpiritForwardVector_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignPlayerWisp_eventGetSpiritForwardVector_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASovereignPlayerWisp_GetSpiritForwardVector_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASovereignPlayerWisp_GetSpiritForwardVector_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ASovereignPlayerWisp_GetSpiritForwardVector_Statics::PropPointers) < 2048);
// ********** End Function GetSpiritForwardVector Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASovereignPlayerWisp_GetSpiritForwardVector_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ASovereignPlayerWisp, nullptr, "GetSpiritForwardVector", 	Z_Construct_UFunction_ASovereignPlayerWisp_GetSpiritForwardVector_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_ASovereignPlayerWisp_GetSpiritForwardVector_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_ASovereignPlayerWisp_GetSpiritForwardVector_Statics::SovereignPlayerWisp_eventGetSpiritForwardVector_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASovereignPlayerWisp_GetSpiritForwardVector_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASovereignPlayerWisp_GetSpiritForwardVector_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ASovereignPlayerWisp_GetSpiritForwardVector_Statics::SovereignPlayerWisp_eventGetSpiritForwardVector_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ASovereignPlayerWisp_GetSpiritForwardVector()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASovereignPlayerWisp_GetSpiritForwardVector_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASovereignPlayerWisp::execGetSpiritForwardVector)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector*)Z_Param__Result=P_THIS->GetSpiritForwardVector();
	P_NATIVE_END;
}
// ********** End Class ASovereignPlayerWisp Function GetSpiritForwardVector ***********************

// ********** Begin Class ASovereignPlayerWisp Function IsPossessing *******************************
struct Z_Construct_UFunction_ASovereignPlayerWisp_IsPossessing_Statics
{
	struct SovereignPlayerWisp_eventIsPossessing_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Possession" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Ideally we want a bool stored on the wisp to know if it is possessing anything\n" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignPlayerWisp.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ideally we want a bool stored on the wisp to know if it is possessing anything" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function IsPossessing constinit property declarations **************************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsPossessing constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsPossessing Property Definitions *************************************
void Z_Construct_UFunction_ASovereignPlayerWisp_IsPossessing_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((SovereignPlayerWisp_eventIsPossessing_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASovereignPlayerWisp_IsPossessing_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SovereignPlayerWisp_eventIsPossessing_Parms), &Z_Construct_UFunction_ASovereignPlayerWisp_IsPossessing_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASovereignPlayerWisp_IsPossessing_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASovereignPlayerWisp_IsPossessing_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ASovereignPlayerWisp_IsPossessing_Statics::PropPointers) < 2048);
// ********** End Function IsPossessing Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASovereignPlayerWisp_IsPossessing_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ASovereignPlayerWisp, nullptr, "IsPossessing", 	Z_Construct_UFunction_ASovereignPlayerWisp_IsPossessing_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_ASovereignPlayerWisp_IsPossessing_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_ASovereignPlayerWisp_IsPossessing_Statics::SovereignPlayerWisp_eventIsPossessing_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASovereignPlayerWisp_IsPossessing_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASovereignPlayerWisp_IsPossessing_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ASovereignPlayerWisp_IsPossessing_Statics::SovereignPlayerWisp_eventIsPossessing_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ASovereignPlayerWisp_IsPossessing()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASovereignPlayerWisp_IsPossessing_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASovereignPlayerWisp::execIsPossessing)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsPossessing();
	P_NATIVE_END;
}
// ********** End Class ASovereignPlayerWisp Function IsPossessing *********************************

// ********** Begin Class ASovereignPlayerWisp Function TogglAutoSensing ***************************
struct Z_Construct_UFunction_ASovereignPlayerWisp_TogglAutoSensing_Statics
{
	struct SovereignPlayerWisp_eventTogglAutoSensing_Parms
	{
		bool bNewState;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Senses" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Function to flip the switch */" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignPlayerWisp.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Function to flip the switch" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function TogglAutoSensing constinit property declarations **********************
	static void NewProp_bNewState_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bNewState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function TogglAutoSensing constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function TogglAutoSensing Property Definitions *********************************
void Z_Construct_UFunction_ASovereignPlayerWisp_TogglAutoSensing_Statics::NewProp_bNewState_SetBit(void* Obj)
{
	((SovereignPlayerWisp_eventTogglAutoSensing_Parms*)Obj)->bNewState = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASovereignPlayerWisp_TogglAutoSensing_Statics::NewProp_bNewState = { "bNewState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SovereignPlayerWisp_eventTogglAutoSensing_Parms), &Z_Construct_UFunction_ASovereignPlayerWisp_TogglAutoSensing_Statics::NewProp_bNewState_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASovereignPlayerWisp_TogglAutoSensing_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASovereignPlayerWisp_TogglAutoSensing_Statics::NewProp_bNewState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ASovereignPlayerWisp_TogglAutoSensing_Statics::PropPointers) < 2048);
// ********** End Function TogglAutoSensing Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASovereignPlayerWisp_TogglAutoSensing_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ASovereignPlayerWisp, nullptr, "TogglAutoSensing", 	Z_Construct_UFunction_ASovereignPlayerWisp_TogglAutoSensing_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_ASovereignPlayerWisp_TogglAutoSensing_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_ASovereignPlayerWisp_TogglAutoSensing_Statics::SovereignPlayerWisp_eventTogglAutoSensing_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASovereignPlayerWisp_TogglAutoSensing_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASovereignPlayerWisp_TogglAutoSensing_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ASovereignPlayerWisp_TogglAutoSensing_Statics::SovereignPlayerWisp_eventTogglAutoSensing_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ASovereignPlayerWisp_TogglAutoSensing()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASovereignPlayerWisp_TogglAutoSensing_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASovereignPlayerWisp::execTogglAutoSensing)
{
	P_GET_UBOOL(Z_Param_bNewState);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->TogglAutoSensing(Z_Param_bNewState);
	P_NATIVE_END;
}
// ********** End Class ASovereignPlayerWisp Function TogglAutoSensing *****************************

// ********** Begin Class ASovereignPlayerWisp *****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_ASovereignPlayerWisp;
UClass* ASovereignPlayerWisp::GetPrivateStaticClass()
{
	using TClass = ASovereignPlayerWisp;
	if (!Z_Registration_Info_UClass_ASovereignPlayerWisp.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SovereignPlayerWisp"),
			Z_Registration_Info_UClass_ASovereignPlayerWisp.InnerSingleton,
			StaticRegisterNativesASovereignPlayerWisp,
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
	return Z_Registration_Info_UClass_ASovereignPlayerWisp.InnerSingleton;
}
UClass* Z_Construct_UClass_ASovereignPlayerWisp_NoRegister()
{
	return ASovereignPlayerWisp::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ASovereignPlayerWisp_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Entities/SovereignPlayerWisp.h" },
		{ "ModuleRelativePath", "Public/Entities/SovereignPlayerWisp.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsAutoSensingEnabled_MetaData[] = {
		{ "Category", "Sovereign|Senses" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//User Settings\n//Trigger Automatic Raycast\n" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignPlayerWisp.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "User Settings\nTrigger Automatic Raycast" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpiritEffect_MetaData[] = {
		{ "Category", "Sovereign|Vfx" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Visuals for the Wisp - Declared ONLY ONCE now */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Entities/SovereignPlayerWisp.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Visuals for the Wisp - Declared ONLY ONCE now" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractionDistance_MetaData[] = {
		{ "Category", "Sovereign|Input" },
		{ "ModuleRelativePath", "Public/Entities/SovereignPlayerWisp.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PossessionTraceRadius_MetaData[] = {
		{ "Category", "Sovereign|Possession" },
		{ "ModuleRelativePath", "Public/Entities/SovereignPlayerWisp.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_QiDrainRate_MetaData[] = {
		{ "Category", "Sovereign|Core" },
		{ "ModuleRelativePath", "Public/Entities/SovereignPlayerWisp.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EjectAction_MetaData[] = {
		{ "Category", "Sovereign|Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The Input Action for Ejecting */" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignPlayerWisp.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The Input Action for Ejecting" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsPossessing_MetaData[] = {
		{ "Category", "Sovereign|Possession" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Gameplay Truth: Are we currently acting as a Soul for a Vessel? */" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignPlayerWisp.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Gameplay Truth: Are we currently acting as a Soul for a Vessel?" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentHost_MetaData[] = {
		{ "Category", "Sovereign|Possession" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Direct reference to the current Host for fast access to Metadata/Stats */" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignPlayerWisp.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Direct reference to the current Host for fast access to Metadata/Stats" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class ASovereignPlayerWisp constinit property declarations *********************
	static void NewProp_bIsAutoSensingEnabled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsAutoSensingEnabled;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpiritEffect;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InteractionDistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PossessionTraceRadius;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_QiDrainRate;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EjectAction;
	static void NewProp_bIsPossessing_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsPossessing;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CurrentHost;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class ASovereignPlayerWisp constinit property declarations ***********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("AttemptPossession"), .Pointer = &ASovereignPlayerWisp::execAttemptPossession },
		{ .NameUTF8 = UTF8TEXT("EjectFromHost"), .Pointer = &ASovereignPlayerWisp::execEjectFromHost },
		{ .NameUTF8 = UTF8TEXT("Evolve_Implementation"), .Pointer = &ASovereignPlayerWisp::execEvolve_Implementation },
		{ .NameUTF8 = UTF8TEXT("GetSpiritForwardVector"), .Pointer = &ASovereignPlayerWisp::execGetSpiritForwardVector },
		{ .NameUTF8 = UTF8TEXT("IsPossessing"), .Pointer = &ASovereignPlayerWisp::execIsPossessing },
		{ .NameUTF8 = UTF8TEXT("TogglAutoSensing"), .Pointer = &ASovereignPlayerWisp::execTogglAutoSensing },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ASovereignPlayerWisp_AttemptPossession, "AttemptPossession" }, // 3358311526
		{ &Z_Construct_UFunction_ASovereignPlayerWisp_EjectFromHost, "EjectFromHost" }, // 1546190829
		{ &Z_Construct_UFunction_ASovereignPlayerWisp_Evolve_Implementation, "Evolve_Implementation" }, // 1708530436
		{ &Z_Construct_UFunction_ASovereignPlayerWisp_GetSpiritForwardVector, "GetSpiritForwardVector" }, // 2393159047
		{ &Z_Construct_UFunction_ASovereignPlayerWisp_IsPossessing, "IsPossessing" }, // 3851968842
		{ &Z_Construct_UFunction_ASovereignPlayerWisp_TogglAutoSensing, "TogglAutoSensing" }, // 1814787727
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASovereignPlayerWisp>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_ASovereignPlayerWisp_Statics

// ********** Begin Class ASovereignPlayerWisp Property Definitions ********************************
void Z_Construct_UClass_ASovereignPlayerWisp_Statics::NewProp_bIsAutoSensingEnabled_SetBit(void* Obj)
{
	((ASovereignPlayerWisp*)Obj)->bIsAutoSensingEnabled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASovereignPlayerWisp_Statics::NewProp_bIsAutoSensingEnabled = { "bIsAutoSensingEnabled", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ASovereignPlayerWisp), &Z_Construct_UClass_ASovereignPlayerWisp_Statics::NewProp_bIsAutoSensingEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsAutoSensingEnabled_MetaData), NewProp_bIsAutoSensingEnabled_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASovereignPlayerWisp_Statics::NewProp_SpiritEffect = { "SpiritEffect", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASovereignPlayerWisp, SpiritEffect), Z_Construct_UClass_UNiagaraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpiritEffect_MetaData), NewProp_SpiritEffect_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASovereignPlayerWisp_Statics::NewProp_InteractionDistance = { "InteractionDistance", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASovereignPlayerWisp, InteractionDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractionDistance_MetaData), NewProp_InteractionDistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASovereignPlayerWisp_Statics::NewProp_PossessionTraceRadius = { "PossessionTraceRadius", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASovereignPlayerWisp, PossessionTraceRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PossessionTraceRadius_MetaData), NewProp_PossessionTraceRadius_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASovereignPlayerWisp_Statics::NewProp_QiDrainRate = { "QiDrainRate", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASovereignPlayerWisp, QiDrainRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_QiDrainRate_MetaData), NewProp_QiDrainRate_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASovereignPlayerWisp_Statics::NewProp_EjectAction = { "EjectAction", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASovereignPlayerWisp, EjectAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EjectAction_MetaData), NewProp_EjectAction_MetaData) };
void Z_Construct_UClass_ASovereignPlayerWisp_Statics::NewProp_bIsPossessing_SetBit(void* Obj)
{
	((ASovereignPlayerWisp*)Obj)->bIsPossessing = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASovereignPlayerWisp_Statics::NewProp_bIsPossessing = { "bIsPossessing", nullptr, (EPropertyFlags)0x0020080000020815, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ASovereignPlayerWisp), &Z_Construct_UClass_ASovereignPlayerWisp_Statics::NewProp_bIsPossessing_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsPossessing_MetaData), NewProp_bIsPossessing_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASovereignPlayerWisp_Statics::NewProp_CurrentHost = { "CurrentHost", nullptr, (EPropertyFlags)0x0020080000020815, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASovereignPlayerWisp, CurrentHost), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentHost_MetaData), NewProp_CurrentHost_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASovereignPlayerWisp_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASovereignPlayerWisp_Statics::NewProp_bIsAutoSensingEnabled,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASovereignPlayerWisp_Statics::NewProp_SpiritEffect,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASovereignPlayerWisp_Statics::NewProp_InteractionDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASovereignPlayerWisp_Statics::NewProp_PossessionTraceRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASovereignPlayerWisp_Statics::NewProp_QiDrainRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASovereignPlayerWisp_Statics::NewProp_EjectAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASovereignPlayerWisp_Statics::NewProp_bIsPossessing,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASovereignPlayerWisp_Statics::NewProp_CurrentHost,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASovereignPlayerWisp_Statics::PropPointers) < 2048);
// ********** End Class ASovereignPlayerWisp Property Definitions **********************************
UObject* (*const Z_Construct_UClass_ASovereignPlayerWisp_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ASovereignBaseCharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_WispCPP7VR,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASovereignPlayerWisp_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ASovereignPlayerWisp_Statics::ClassParams = {
	&ASovereignPlayerWisp::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ASovereignPlayerWisp_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ASovereignPlayerWisp_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASovereignPlayerWisp_Statics::Class_MetaDataParams), Z_Construct_UClass_ASovereignPlayerWisp_Statics::Class_MetaDataParams)
};
void ASovereignPlayerWisp::StaticRegisterNativesASovereignPlayerWisp()
{
	UClass* Class = ASovereignPlayerWisp::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_ASovereignPlayerWisp_Statics::Funcs));
}
UClass* Z_Construct_UClass_ASovereignPlayerWisp()
{
	if (!Z_Registration_Info_UClass_ASovereignPlayerWisp.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASovereignPlayerWisp.OuterSingleton, Z_Construct_UClass_ASovereignPlayerWisp_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ASovereignPlayerWisp.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ASovereignPlayerWisp);
ASovereignPlayerWisp::~ASovereignPlayerWisp() {}
// ********** End Class ASovereignPlayerWisp *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Entities_SovereignPlayerWisp_h__Script_WispCPP7VR_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ASovereignPlayerWisp, ASovereignPlayerWisp::StaticClass, TEXT("ASovereignPlayerWisp"), &Z_Registration_Info_UClass_ASovereignPlayerWisp, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASovereignPlayerWisp), 1719990969U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Entities_SovereignPlayerWisp_h__Script_WispCPP7VR_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Entities_SovereignPlayerWisp_h__Script_WispCPP7VR_1235657285{
	TEXT("/Script/WispCPP7VR"),
	Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Entities_SovereignPlayerWisp_h__Script_WispCPP7VR_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Entities_SovereignPlayerWisp_h__Script_WispCPP7VR_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
