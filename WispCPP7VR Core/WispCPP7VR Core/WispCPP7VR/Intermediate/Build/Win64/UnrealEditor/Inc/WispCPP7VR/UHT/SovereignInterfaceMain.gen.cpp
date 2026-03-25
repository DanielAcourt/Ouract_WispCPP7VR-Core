// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Interaction/SovereignInterfaceMain.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSovereignInterfaceMain() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AController_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UMeshComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_WispCPP7VR();
WISPCPP7VR_API UClass* Z_Construct_UClass_UInteractionInterface();
WISPCPP7VR_API UClass* Z_Construct_UClass_UInteractionInterface_NoRegister();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignSaveableEntityComponent_NoRegister();
// ********** End Cross Module References **********************************************************

// ********** Begin Interface UInteractionInterface Function CanBePossessed ************************
struct InteractionInterface_eventCanBePossessed_Parms
{
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	InteractionInterface_eventCanBePossessed_Parms()
		: ReturnValue(false)
	{
	}
};
bool IInteractionInterface::CanBePossessed()
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_CanBePossessed instead.");
	InteractionInterface_eventCanBePossessed_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UInteractionInterface_CanBePossessed = FName(TEXT("CanBePossessed"));
bool IInteractionInterface::Execute_CanBePossessed(UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UInteractionInterface::StaticClass()));
	InteractionInterface_eventCanBePossessed_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UInteractionInterface_CanBePossessed);
	if (Func)
	{
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (IInteractionInterface*)(O->GetNativeInterfaceAddress(UInteractionInterface::StaticClass())))
	{
		Parms.ReturnValue = I->CanBePossessed_Implementation();
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UInteractionInterface_CanBePossessed_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Possession" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** NEW: Check if this entity can be inhabited by a Sovereign Spirit */" },
#endif
		{ "ModuleRelativePath", "Public/Interaction/SovereignInterfaceMain.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "NEW: Check if this entity can be inhabited by a Sovereign Spirit" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function CanBePossessed constinit property declarations ************************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CanBePossessed constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CanBePossessed Property Definitions ***********************************
void Z_Construct_UFunction_UInteractionInterface_CanBePossessed_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((InteractionInterface_eventCanBePossessed_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInteractionInterface_CanBePossessed_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(InteractionInterface_eventCanBePossessed_Parms), &Z_Construct_UFunction_UInteractionInterface_CanBePossessed_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInteractionInterface_CanBePossessed_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInteractionInterface_CanBePossessed_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractionInterface_CanBePossessed_Statics::PropPointers) < 2048);
// ********** End Function CanBePossessed Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractionInterface_CanBePossessed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInteractionInterface, nullptr, "CanBePossessed", 	Z_Construct_UFunction_UInteractionInterface_CanBePossessed_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractionInterface_CanBePossessed_Statics::PropPointers), 
sizeof(InteractionInterface_eventCanBePossessed_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractionInterface_CanBePossessed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractionInterface_CanBePossessed_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(InteractionInterface_eventCanBePossessed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInteractionInterface_CanBePossessed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractionInterface_CanBePossessed_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IInteractionInterface::execCanBePossessed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->CanBePossessed_Implementation();
	P_NATIVE_END;
}
// ********** End Interface UInteractionInterface Function CanBePossessed **************************

// ********** Begin Interface UInteractionInterface Function CanInteract ***************************
struct InteractionInterface_eventCanInteract_Parms
{
	AActor* Interactor;
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	InteractionInterface_eventCanInteract_Parms()
		: ReturnValue(false)
	{
	}
};
bool IInteractionInterface::CanInteract(AActor* Interactor)
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_CanInteract instead.");
	InteractionInterface_eventCanInteract_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UInteractionInterface_CanInteract = FName(TEXT("CanInteract"));
bool IInteractionInterface::Execute_CanInteract(UObject* O, AActor* Interactor)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UInteractionInterface::StaticClass()));
	InteractionInterface_eventCanInteract_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UInteractionInterface_CanInteract);
	if (Func)
	{
		Parms.Interactor=std::move(Interactor);
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (IInteractionInterface*)(O->GetNativeInterfaceAddress(UInteractionInterface::StaticClass())))
	{
		Parms.ReturnValue = I->CanInteract_Implementation(Interactor);
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UInteractionInterface_CanInteract_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Interaction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Returns true if the object is currently in a state where it can be touched. */" },
#endif
		{ "ModuleRelativePath", "Public/Interaction/SovereignInterfaceMain.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns true if the object is currently in a state where it can be touched." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function CanInteract constinit property declarations ***************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Interactor;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CanInteract constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CanInteract Property Definitions **************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInteractionInterface_CanInteract_Statics::NewProp_Interactor = { "Interactor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InteractionInterface_eventCanInteract_Parms, Interactor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UInteractionInterface_CanInteract_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((InteractionInterface_eventCanInteract_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInteractionInterface_CanInteract_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(InteractionInterface_eventCanInteract_Parms), &Z_Construct_UFunction_UInteractionInterface_CanInteract_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInteractionInterface_CanInteract_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInteractionInterface_CanInteract_Statics::NewProp_Interactor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInteractionInterface_CanInteract_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractionInterface_CanInteract_Statics::PropPointers) < 2048);
// ********** End Function CanInteract Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractionInterface_CanInteract_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInteractionInterface, nullptr, "CanInteract", 	Z_Construct_UFunction_UInteractionInterface_CanInteract_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractionInterface_CanInteract_Statics::PropPointers), 
sizeof(InteractionInterface_eventCanInteract_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractionInterface_CanInteract_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractionInterface_CanInteract_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(InteractionInterface_eventCanInteract_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInteractionInterface_CanInteract()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractionInterface_CanInteract_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IInteractionInterface::execCanInteract)
{
	P_GET_OBJECT(AActor,Z_Param_Interactor);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->CanInteract_Implementation(Z_Param_Interactor);
	P_NATIVE_END;
}
// ********** End Interface UInteractionInterface Function CanInteract *****************************

// ********** Begin Interface UInteractionInterface Function Evolve ********************************
void IInteractionInterface::Evolve()
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_Evolve instead.");
}
static FName NAME_UInteractionInterface_Evolve = FName(TEXT("Evolve"));
void IInteractionInterface::Execute_Evolve(UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UInteractionInterface::StaticClass()));
	UFunction* const Func = O->FindFunction(NAME_UInteractionInterface_Evolve);
	if (Func)
	{
		O->ProcessEvent(Func, NULL);
	}
	else if (auto I = (IInteractionInterface*)(O->GetNativeInterfaceAddress(UInteractionInterface::StaticClass())))
	{
		I->Evolve_Implementation();
	}
}
struct Z_Construct_UFunction_UInteractionInterface_Evolve_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Evolution" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Trigger the evolution process of the entity. */" },
#endif
		{ "ModuleRelativePath", "Public/Interaction/SovereignInterfaceMain.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Trigger the evolution process of the entity." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function Evolve constinit property declarations ********************************
// ********** End Function Evolve constinit property declarations **********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractionInterface_Evolve_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInteractionInterface, nullptr, "Evolve", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractionInterface_Evolve_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractionInterface_Evolve_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UInteractionInterface_Evolve()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractionInterface_Evolve_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IInteractionInterface::execEvolve)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Evolve_Implementation();
	P_NATIVE_END;
}
// ********** End Interface UInteractionInterface Function Evolve **********************************

// ********** Begin Interface UInteractionInterface Function GetInhabitingSpirit *******************
struct InteractionInterface_eventGetInhabitingSpirit_Parms
{
	AActor* ReturnValue;

	/** Constructor, initializes return property only **/
	InteractionInterface_eventGetInhabitingSpirit_Parms()
		: ReturnValue(NULL)
	{
	}
};
AActor* IInteractionInterface::GetInhabitingSpirit()
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetInhabitingSpirit instead.");
	InteractionInterface_eventGetInhabitingSpirit_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UInteractionInterface_GetInhabitingSpirit = FName(TEXT("GetInhabitingSpirit"));
AActor* IInteractionInterface::Execute_GetInhabitingSpirit(UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UInteractionInterface::StaticClass()));
	InteractionInterface_eventGetInhabitingSpirit_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UInteractionInterface_GetInhabitingSpirit);
	if (Func)
	{
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (IInteractionInterface*)(O->GetNativeInterfaceAddress(UInteractionInterface::StaticClass())))
	{
		Parms.ReturnValue = I->GetInhabitingSpirit_Implementation();
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UInteractionInterface_GetInhabitingSpirit_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Possession" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Returns the Wisp or Spirit currently residing in this vessel. */" },
#endif
		{ "ModuleRelativePath", "Public/Interaction/SovereignInterfaceMain.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the Wisp or Spirit currently residing in this vessel." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetInhabitingSpirit constinit property declarations *******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetInhabitingSpirit constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetInhabitingSpirit Property Definitions ******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInteractionInterface_GetInhabitingSpirit_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InteractionInterface_eventGetInhabitingSpirit_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInteractionInterface_GetInhabitingSpirit_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInteractionInterface_GetInhabitingSpirit_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractionInterface_GetInhabitingSpirit_Statics::PropPointers) < 2048);
// ********** End Function GetInhabitingSpirit Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractionInterface_GetInhabitingSpirit_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInteractionInterface, nullptr, "GetInhabitingSpirit", 	Z_Construct_UFunction_UInteractionInterface_GetInhabitingSpirit_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractionInterface_GetInhabitingSpirit_Statics::PropPointers), 
sizeof(InteractionInterface_eventGetInhabitingSpirit_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractionInterface_GetInhabitingSpirit_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractionInterface_GetInhabitingSpirit_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(InteractionInterface_eventGetInhabitingSpirit_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInteractionInterface_GetInhabitingSpirit()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractionInterface_GetInhabitingSpirit_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IInteractionInterface::execGetInhabitingSpirit)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(AActor**)Z_Param__Result=P_THIS->GetInhabitingSpirit_Implementation();
	P_NATIVE_END;
}
// ********** End Interface UInteractionInterface Function GetInhabitingSpirit *********************

// ********** Begin Interface UInteractionInterface Function GetInteractableName *******************
struct InteractionInterface_eventGetInteractableName_Parms
{
	FText ReturnValue;
};
FText IInteractionInterface::GetInteractableName()
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetInteractableName instead.");
	InteractionInterface_eventGetInteractableName_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UInteractionInterface_GetInteractableName = FName(TEXT("GetInteractableName"));
FText IInteractionInterface::Execute_GetInteractableName(UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UInteractionInterface::StaticClass()));
	InteractionInterface_eventGetInteractableName_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UInteractionInterface_GetInteractableName);
	if (Func)
	{
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (IInteractionInterface*)(O->GetNativeInterfaceAddress(UInteractionInterface::StaticClass())))
	{
		Parms.ReturnValue = I->GetInteractableName_Implementation();
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UInteractionInterface_GetInteractableName_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Interaction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// NEW: Allows the object to tell the UI what its name is\n" },
#endif
		{ "ModuleRelativePath", "Public/Interaction/SovereignInterfaceMain.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "NEW: Allows the object to tell the UI what its name is" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetInteractableName constinit property declarations *******************
	static const UECodeGen_Private::FTextPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetInteractableName constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetInteractableName Property Definitions ******************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UInteractionInterface_GetInteractableName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InteractionInterface_eventGetInteractableName_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInteractionInterface_GetInteractableName_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInteractionInterface_GetInteractableName_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractionInterface_GetInteractableName_Statics::PropPointers) < 2048);
// ********** End Function GetInteractableName Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractionInterface_GetInteractableName_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInteractionInterface, nullptr, "GetInteractableName", 	Z_Construct_UFunction_UInteractionInterface_GetInteractableName_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractionInterface_GetInteractableName_Statics::PropPointers), 
sizeof(InteractionInterface_eventGetInteractableName_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractionInterface_GetInteractableName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractionInterface_GetInteractableName_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(InteractionInterface_eventGetInteractableName_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInteractionInterface_GetInteractableName()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractionInterface_GetInteractableName_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IInteractionInterface::execGetInteractableName)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FText*)Z_Param__Result=P_THIS->GetInteractableName_Implementation();
	P_NATIVE_END;
}
// ********** End Interface UInteractionInterface Function GetInteractableName *********************

// ********** Begin Interface UInteractionInterface Function GetInteractionHint ********************
struct InteractionInterface_eventGetInteractionHint_Parms
{
	FString ReturnValue;
};
FString IInteractionInterface::GetInteractionHint()
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetInteractionHint instead.");
	InteractionInterface_eventGetInteractionHint_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UInteractionInterface_GetInteractionHint = FName(TEXT("GetInteractionHint"));
FString IInteractionInterface::Execute_GetInteractionHint(UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UInteractionInterface::StaticClass()));
	InteractionInterface_eventGetInteractionHint_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UInteractionInterface_GetInteractionHint);
	if (Func)
	{
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (IInteractionInterface*)(O->GetNativeInterfaceAddress(UInteractionInterface::StaticClass())))
	{
		Parms.ReturnValue = I->GetInteractionHint_Implementation();
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UInteractionInterface_GetInteractionHint_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Interaction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Returns a 'hint' string for the UI (e.g., \"Harvest\", \"Plant\", \"Save\"). */" },
#endif
		{ "ModuleRelativePath", "Public/Interaction/SovereignInterfaceMain.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns a 'hint' string for the UI (e.g., \"Harvest\", \"Plant\", \"Save\")." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetInteractionHint constinit property declarations ********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetInteractionHint constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetInteractionHint Property Definitions *******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UInteractionInterface_GetInteractionHint_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InteractionInterface_eventGetInteractionHint_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInteractionInterface_GetInteractionHint_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInteractionInterface_GetInteractionHint_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractionInterface_GetInteractionHint_Statics::PropPointers) < 2048);
// ********** End Function GetInteractionHint Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractionInterface_GetInteractionHint_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInteractionInterface, nullptr, "GetInteractionHint", 	Z_Construct_UFunction_UInteractionInterface_GetInteractionHint_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractionInterface_GetInteractionHint_Statics::PropPointers), 
sizeof(InteractionInterface_eventGetInteractionHint_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractionInterface_GetInteractionHint_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractionInterface_GetInteractionHint_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(InteractionInterface_eventGetInteractionHint_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInteractionInterface_GetInteractionHint()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractionInterface_GetInteractionHint_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IInteractionInterface::execGetInteractionHint)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GetInteractionHint_Implementation();
	P_NATIVE_END;
}
// ********** End Interface UInteractionInterface Function GetInteractionHint **********************

// ********** Begin Interface UInteractionInterface Function GetPossessionAttachmentComponent ******
struct InteractionInterface_eventGetPossessionAttachmentComponent_Parms
{
	USceneComponent* ReturnValue;

	/** Constructor, initializes return property only **/
	InteractionInterface_eventGetPossessionAttachmentComponent_Parms()
		: ReturnValue(NULL)
	{
	}
};
USceneComponent* IInteractionInterface::GetPossessionAttachmentComponent()
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetPossessionAttachmentComponent instead.");
	InteractionInterface_eventGetPossessionAttachmentComponent_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UInteractionInterface_GetPossessionAttachmentComponent = FName(TEXT("GetPossessionAttachmentComponent"));
USceneComponent* IInteractionInterface::Execute_GetPossessionAttachmentComponent(UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UInteractionInterface::StaticClass()));
	InteractionInterface_eventGetPossessionAttachmentComponent_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UInteractionInterface_GetPossessionAttachmentComponent);
	if (Func)
	{
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (IInteractionInterface*)(O->GetNativeInterfaceAddress(UInteractionInterface::StaticClass())))
	{
		Parms.ReturnValue = I->GetPossessionAttachmentComponent_Implementation();
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UInteractionInterface_GetPossessionAttachmentComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Possession" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** NEW: Returns the component to attach the spirit to when possessed */" },
#endif
		{ "ModuleRelativePath", "Public/Interaction/SovereignInterfaceMain.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "NEW: Returns the component to attach the spirit to when possessed" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetPossessionAttachmentComponent constinit property declarations ******
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPossessionAttachmentComponent constinit property declarations ********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPossessionAttachmentComponent Property Definitions *****************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInteractionInterface_GetPossessionAttachmentComponent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InteractionInterface_eventGetPossessionAttachmentComponent_Parms, ReturnValue), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInteractionInterface_GetPossessionAttachmentComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInteractionInterface_GetPossessionAttachmentComponent_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractionInterface_GetPossessionAttachmentComponent_Statics::PropPointers) < 2048);
// ********** End Function GetPossessionAttachmentComponent Property Definitions *******************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractionInterface_GetPossessionAttachmentComponent_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInteractionInterface, nullptr, "GetPossessionAttachmentComponent", 	Z_Construct_UFunction_UInteractionInterface_GetPossessionAttachmentComponent_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractionInterface_GetPossessionAttachmentComponent_Statics::PropPointers), 
sizeof(InteractionInterface_eventGetPossessionAttachmentComponent_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractionInterface_GetPossessionAttachmentComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractionInterface_GetPossessionAttachmentComponent_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(InteractionInterface_eventGetPossessionAttachmentComponent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInteractionInterface_GetPossessionAttachmentComponent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractionInterface_GetPossessionAttachmentComponent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IInteractionInterface::execGetPossessionAttachmentComponent)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(USceneComponent**)Z_Param__Result=P_THIS->GetPossessionAttachmentComponent_Implementation();
	P_NATIVE_END;
}
// ********** End Interface UInteractionInterface Function GetPossessionAttachmentComponent ********

// ********** Begin Interface UInteractionInterface Function GetPrimaryMesh ************************
struct InteractionInterface_eventGetPrimaryMesh_Parms
{
	UMeshComponent* ReturnValue;

	/** Constructor, initializes return property only **/
	InteractionInterface_eventGetPrimaryMesh_Parms()
		: ReturnValue(NULL)
	{
	}
};
UMeshComponent* IInteractionInterface::GetPrimaryMesh() const
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetPrimaryMesh instead.");
	InteractionInterface_eventGetPrimaryMesh_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UInteractionInterface_GetPrimaryMesh = FName(TEXT("GetPrimaryMesh"));
UMeshComponent* IInteractionInterface::Execute_GetPrimaryMesh(const UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UInteractionInterface::StaticClass()));
	InteractionInterface_eventGetPrimaryMesh_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UInteractionInterface_GetPrimaryMesh);
	if (Func)
	{
		const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (const IInteractionInterface*)(O->GetNativeInterfaceAddress(UInteractionInterface::StaticClass())))
	{
		Parms.ReturnValue = I->GetPrimaryMesh_Implementation();
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UInteractionInterface_GetPrimaryMesh_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Visuals" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Returns the primary mesh (Skeletal or Static) of this entity. */" },
#endif
		{ "ModuleRelativePath", "Public/Interaction/SovereignInterfaceMain.h" },
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
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInteractionInterface_GetPrimaryMesh_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InteractionInterface_eventGetPrimaryMesh_Parms, ReturnValue), Z_Construct_UClass_UMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInteractionInterface_GetPrimaryMesh_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInteractionInterface_GetPrimaryMesh_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractionInterface_GetPrimaryMesh_Statics::PropPointers) < 2048);
// ********** End Function GetPrimaryMesh Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractionInterface_GetPrimaryMesh_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInteractionInterface, nullptr, "GetPrimaryMesh", 	Z_Construct_UFunction_UInteractionInterface_GetPrimaryMesh_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractionInterface_GetPrimaryMesh_Statics::PropPointers), 
sizeof(InteractionInterface_eventGetPrimaryMesh_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractionInterface_GetPrimaryMesh_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractionInterface_GetPrimaryMesh_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(InteractionInterface_eventGetPrimaryMesh_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInteractionInterface_GetPrimaryMesh()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractionInterface_GetPrimaryMesh_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IInteractionInterface::execGetPrimaryMesh)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UMeshComponent**)Z_Param__Result=P_THIS->GetPrimaryMesh_Implementation();
	P_NATIVE_END;
}
// ********** End Interface UInteractionInterface Function GetPrimaryMesh **************************

// ********** Begin Interface UInteractionInterface Function GetSovereignSoul **********************
struct InteractionInterface_eventGetSovereignSoul_Parms
{
	USovereignSaveableEntityComponent* ReturnValue;

	/** Constructor, initializes return property only **/
	InteractionInterface_eventGetSovereignSoul_Parms()
		: ReturnValue(NULL)
	{
	}
};
USovereignSaveableEntityComponent* IInteractionInterface::GetSovereignSoul() const
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetSovereignSoul instead.");
	InteractionInterface_eventGetSovereignSoul_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UInteractionInterface_GetSovereignSoul = FName(TEXT("GetSovereignSoul"));
USovereignSaveableEntityComponent* IInteractionInterface::Execute_GetSovereignSoul(const UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UInteractionInterface::StaticClass()));
	InteractionInterface_eventGetSovereignSoul_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UInteractionInterface_GetSovereignSoul);
	if (Func)
	{
		const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (const IInteractionInterface*)(O->GetNativeInterfaceAddress(UInteractionInterface::StaticClass())))
	{
		Parms.ReturnValue = I->GetSovereignSoul_Implementation();
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UInteractionInterface_GetSovereignSoul_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Core" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** * THE MASTER KEY:\n\x09 * Returns the Sovereign Soul (The 'One Sense of Simulated Truth').\n\x09 * This allows the Wisp to read IDs, Tags, and Qi from any interactable object.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/Interaction/SovereignInterfaceMain.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "THE MASTER KEY:\nReturns the Sovereign Soul (The 'One Sense of Simulated Truth').\nThis allows the Wisp to read IDs, Tags, and Qi from any interactable object." },
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
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInteractionInterface_GetSovereignSoul_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InteractionInterface_eventGetSovereignSoul_Parms, ReturnValue), Z_Construct_UClass_USovereignSaveableEntityComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInteractionInterface_GetSovereignSoul_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInteractionInterface_GetSovereignSoul_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractionInterface_GetSovereignSoul_Statics::PropPointers) < 2048);
// ********** End Function GetSovereignSoul Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractionInterface_GetSovereignSoul_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInteractionInterface, nullptr, "GetSovereignSoul", 	Z_Construct_UFunction_UInteractionInterface_GetSovereignSoul_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractionInterface_GetSovereignSoul_Statics::PropPointers), 
sizeof(InteractionInterface_eventGetSovereignSoul_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractionInterface_GetSovereignSoul_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractionInterface_GetSovereignSoul_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(InteractionInterface_eventGetSovereignSoul_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInteractionInterface_GetSovereignSoul()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractionInterface_GetSovereignSoul_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IInteractionInterface::execGetSovereignSoul)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(USovereignSaveableEntityComponent**)Z_Param__Result=P_THIS->GetSovereignSoul_Implementation();
	P_NATIVE_END;
}
// ********** End Interface UInteractionInterface Function GetSovereignSoul ************************

// ********** Begin Interface UInteractionInterface Function IsSpiritEntity ************************
struct InteractionInterface_eventIsSpiritEntity_Parms
{
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	InteractionInterface_eventIsSpiritEntity_Parms()
		: ReturnValue(false)
	{
	}
};
bool IInteractionInterface::IsSpiritEntity()
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_IsSpiritEntity instead.");
	InteractionInterface_eventIsSpiritEntity_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UInteractionInterface_IsSpiritEntity = FName(TEXT("IsSpiritEntity"));
bool IInteractionInterface::Execute_IsSpiritEntity(UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UInteractionInterface::StaticClass()));
	InteractionInterface_eventIsSpiritEntity_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UInteractionInterface_IsSpiritEntity);
	if (Func)
	{
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (IInteractionInterface*)(O->GetNativeInterfaceAddress(UInteractionInterface::StaticClass())))
	{
		Parms.ReturnValue = I->IsSpiritEntity_Implementation();
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UInteractionInterface_IsSpiritEntity_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Possession" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Returns true if this actor itself is a Spirit or Wisp. */" },
#endif
		{ "ModuleRelativePath", "Public/Interaction/SovereignInterfaceMain.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns true if this actor itself is a Spirit or Wisp." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function IsSpiritEntity constinit property declarations ************************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsSpiritEntity constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsSpiritEntity Property Definitions ***********************************
void Z_Construct_UFunction_UInteractionInterface_IsSpiritEntity_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((InteractionInterface_eventIsSpiritEntity_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInteractionInterface_IsSpiritEntity_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(InteractionInterface_eventIsSpiritEntity_Parms), &Z_Construct_UFunction_UInteractionInterface_IsSpiritEntity_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInteractionInterface_IsSpiritEntity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInteractionInterface_IsSpiritEntity_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractionInterface_IsSpiritEntity_Statics::PropPointers) < 2048);
// ********** End Function IsSpiritEntity Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractionInterface_IsSpiritEntity_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInteractionInterface, nullptr, "IsSpiritEntity", 	Z_Construct_UFunction_UInteractionInterface_IsSpiritEntity_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractionInterface_IsSpiritEntity_Statics::PropPointers), 
sizeof(InteractionInterface_eventIsSpiritEntity_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractionInterface_IsSpiritEntity_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractionInterface_IsSpiritEntity_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(InteractionInterface_eventIsSpiritEntity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInteractionInterface_IsSpiritEntity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractionInterface_IsSpiritEntity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IInteractionInterface::execIsSpiritEntity)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsSpiritEntity_Implementation();
	P_NATIVE_END;
}
// ********** End Interface UInteractionInterface Function IsSpiritEntity **************************

// ********** Begin Interface UInteractionInterface Function OnBeginHover **************************
void IInteractionInterface::OnBeginHover()
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnBeginHover instead.");
}
static FName NAME_UInteractionInterface_OnBeginHover = FName(TEXT("OnBeginHover"));
void IInteractionInterface::Execute_OnBeginHover(UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UInteractionInterface::StaticClass()));
	UFunction* const Func = O->FindFunction(NAME_UInteractionInterface_OnBeginHover);
	if (Func)
	{
		O->ProcessEvent(Func, NULL);
	}
	else if (auto I = (IInteractionInterface*)(O->GetNativeInterfaceAddress(UInteractionInterface::StaticClass())))
	{
		I->OnBeginHover_Implementation();
	}
}
struct Z_Construct_UFunction_UInteractionInterface_OnBeginHover_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Interaction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** * The Master Interaction Command.\n\x09 * BlueprintNativeEvent allows C++ to handle the logic (Metabolical)\n\x09 * while Blueprints handle the visuals (UI/Emitters).\n\x09 */// Triggered when the Wisp or Bee looks at this object\n" },
#endif
		{ "ModuleRelativePath", "Public/Interaction/SovereignInterfaceMain.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The Master Interaction Command.\nBlueprintNativeEvent allows C++ to handle the logic (Metabolical)\nwhile Blueprints handle the visuals (UI/Emitters).\n        // Triggered when the Wisp or Bee looks at this object" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OnBeginHover constinit property declarations **************************
// ********** End Function OnBeginHover constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractionInterface_OnBeginHover_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInteractionInterface, nullptr, "OnBeginHover", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractionInterface_OnBeginHover_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractionInterface_OnBeginHover_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UInteractionInterface_OnBeginHover()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractionInterface_OnBeginHover_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IInteractionInterface::execOnBeginHover)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnBeginHover_Implementation();
	P_NATIVE_END;
}
// ********** End Interface UInteractionInterface Function OnBeginHover ****************************

// ********** Begin Interface UInteractionInterface Function OnEndHover ****************************
void IInteractionInterface::OnEndHover()
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnEndHover instead.");
}
static FName NAME_UInteractionInterface_OnEndHover = FName(TEXT("OnEndHover"));
void IInteractionInterface::Execute_OnEndHover(UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UInteractionInterface::StaticClass()));
	UFunction* const Func = O->FindFunction(NAME_UInteractionInterface_OnEndHover);
	if (Func)
	{
		O->ProcessEvent(Func, NULL);
	}
	else if (auto I = (IInteractionInterface*)(O->GetNativeInterfaceAddress(UInteractionInterface::StaticClass())))
	{
		I->OnEndHover_Implementation();
	}
}
struct Z_Construct_UFunction_UInteractionInterface_OnEndHover_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Interaction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Triggered when the focus is lost\n" },
#endif
		{ "ModuleRelativePath", "Public/Interaction/SovereignInterfaceMain.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Triggered when the focus is lost" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OnEndHover constinit property declarations ****************************
// ********** End Function OnEndHover constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractionInterface_OnEndHover_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInteractionInterface, nullptr, "OnEndHover", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractionInterface_OnEndHover_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractionInterface_OnEndHover_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UInteractionInterface_OnEndHover()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractionInterface_OnEndHover_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IInteractionInterface::execOnEndHover)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnEndHover_Implementation();
	P_NATIVE_END;
}
// ********** End Interface UInteractionInterface Function OnEndHover ******************************

// ********** Begin Interface UInteractionInterface Function OnInteract ****************************
struct InteractionInterface_eventOnInteract_Parms
{
	AActor* Interactor;
};
void IInteractionInterface::OnInteract(AActor* Interactor)
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnInteract instead.");
}
static FName NAME_UInteractionInterface_OnInteract = FName(TEXT("OnInteract"));
void IInteractionInterface::Execute_OnInteract(UObject* O, AActor* Interactor)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UInteractionInterface::StaticClass()));
	InteractionInterface_eventOnInteract_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UInteractionInterface_OnInteract);
	if (Func)
	{
		Parms.Interactor=std::move(Interactor);
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (IInteractionInterface*)(O->GetNativeInterfaceAddress(UInteractionInterface::StaticClass())))
	{
		I->OnInteract_Implementation(Interactor);
	}
}
struct Z_Construct_UFunction_UInteractionInterface_OnInteract_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Interaction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// The actual \"Action\" (Harvesting Qi, Opening Save Menu, etc.)\n" },
#endif
		{ "ModuleRelativePath", "Public/Interaction/SovereignInterfaceMain.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The actual \"Action\" (Harvesting Qi, Opening Save Menu, etc.)" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OnInteract constinit property declarations ****************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Interactor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnInteract constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnInteract Property Definitions ***************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInteractionInterface_OnInteract_Statics::NewProp_Interactor = { "Interactor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InteractionInterface_eventOnInteract_Parms, Interactor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInteractionInterface_OnInteract_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInteractionInterface_OnInteract_Statics::NewProp_Interactor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractionInterface_OnInteract_Statics::PropPointers) < 2048);
// ********** End Function OnInteract Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractionInterface_OnInteract_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInteractionInterface, nullptr, "OnInteract", 	Z_Construct_UFunction_UInteractionInterface_OnInteract_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractionInterface_OnInteract_Statics::PropPointers), 
sizeof(InteractionInterface_eventOnInteract_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractionInterface_OnInteract_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractionInterface_OnInteract_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(InteractionInterface_eventOnInteract_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInteractionInterface_OnInteract()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractionInterface_OnInteract_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IInteractionInterface::execOnInteract)
{
	P_GET_OBJECT(AActor,Z_Param_Interactor);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnInteract_Implementation(Z_Param_Interactor);
	P_NATIVE_END;
}
// ********** End Interface UInteractionInterface Function OnInteract ******************************

// ********** Begin Interface UInteractionInterface Function OnSecondaryInteract *******************
struct InteractionInterface_eventOnSecondaryInteract_Parms
{
	AActor* Interactor;
};
void IInteractionInterface::OnSecondaryInteract(AActor* Interactor)
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnSecondaryInteract instead.");
}
static FName NAME_UInteractionInterface_OnSecondaryInteract = FName(TEXT("OnSecondaryInteract"));
void IInteractionInterface::Execute_OnSecondaryInteract(UObject* O, AActor* Interactor)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UInteractionInterface::StaticClass()));
	InteractionInterface_eventOnSecondaryInteract_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UInteractionInterface_OnSecondaryInteract);
	if (Func)
	{
		Parms.Interactor=std::move(Interactor);
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (IInteractionInterface*)(O->GetNativeInterfaceAddress(UInteractionInterface::StaticClass())))
	{
		I->OnSecondaryInteract_Implementation(Interactor);
	}
}
struct Z_Construct_UFunction_UInteractionInterface_OnSecondaryInteract_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Interaction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** A second action (like Long Press or Trigger + Grip). */" },
#endif
		{ "ModuleRelativePath", "Public/Interaction/SovereignInterfaceMain.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A second action (like Long Press or Trigger + Grip)." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OnSecondaryInteract constinit property declarations *******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Interactor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnSecondaryInteract constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnSecondaryInteract Property Definitions ******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInteractionInterface_OnSecondaryInteract_Statics::NewProp_Interactor = { "Interactor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InteractionInterface_eventOnSecondaryInteract_Parms, Interactor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInteractionInterface_OnSecondaryInteract_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInteractionInterface_OnSecondaryInteract_Statics::NewProp_Interactor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractionInterface_OnSecondaryInteract_Statics::PropPointers) < 2048);
// ********** End Function OnSecondaryInteract Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractionInterface_OnSecondaryInteract_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInteractionInterface, nullptr, "OnSecondaryInteract", 	Z_Construct_UFunction_UInteractionInterface_OnSecondaryInteract_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractionInterface_OnSecondaryInteract_Statics::PropPointers), 
sizeof(InteractionInterface_eventOnSecondaryInteract_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractionInterface_OnSecondaryInteract_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractionInterface_OnSecondaryInteract_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(InteractionInterface_eventOnSecondaryInteract_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInteractionInterface_OnSecondaryInteract()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractionInterface_OnSecondaryInteract_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IInteractionInterface::execOnSecondaryInteract)
{
	P_GET_OBJECT(AActor,Z_Param_Interactor);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnSecondaryInteract_Implementation(Z_Param_Interactor);
	P_NATIVE_END;
}
// ********** End Interface UInteractionInterface Function OnSecondaryInteract *********************

// ********** Begin Interface UInteractionInterface Function RequestPossession *********************
struct InteractionInterface_eventRequestPossession_Parms
{
	AController* RequestingController;
};
void IInteractionInterface::RequestPossession(AController* RequestingController)
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_RequestPossession instead.");
}
static FName NAME_UInteractionInterface_RequestPossession = FName(TEXT("RequestPossession"));
void IInteractionInterface::Execute_RequestPossession(UObject* O, AController* RequestingController)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UInteractionInterface::StaticClass()));
	InteractionInterface_eventRequestPossession_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UInteractionInterface_RequestPossession);
	if (Func)
	{
		Parms.RequestingController=std::move(RequestingController);
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (IInteractionInterface*)(O->GetNativeInterfaceAddress(UInteractionInterface::StaticClass())))
	{
		I->RequestPossession_Implementation(RequestingController);
	}
}
struct Z_Construct_UFunction_UInteractionInterface_RequestPossession_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Possession" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** NEW: The command to initiate the Sovereign Trust Handover */" },
#endif
		{ "ModuleRelativePath", "Public/Interaction/SovereignInterfaceMain.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "NEW: The command to initiate the Sovereign Trust Handover" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RequestPossession constinit property declarations *********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RequestingController;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RequestPossession constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RequestPossession Property Definitions ********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInteractionInterface_RequestPossession_Statics::NewProp_RequestingController = { "RequestingController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InteractionInterface_eventRequestPossession_Parms, RequestingController), Z_Construct_UClass_AController_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInteractionInterface_RequestPossession_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInteractionInterface_RequestPossession_Statics::NewProp_RequestingController,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractionInterface_RequestPossession_Statics::PropPointers) < 2048);
// ********** End Function RequestPossession Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractionInterface_RequestPossession_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInteractionInterface, nullptr, "RequestPossession", 	Z_Construct_UFunction_UInteractionInterface_RequestPossession_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractionInterface_RequestPossession_Statics::PropPointers), 
sizeof(InteractionInterface_eventRequestPossession_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractionInterface_RequestPossession_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractionInterface_RequestPossession_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(InteractionInterface_eventRequestPossession_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInteractionInterface_RequestPossession()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractionInterface_RequestPossession_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IInteractionInterface::execRequestPossession)
{
	P_GET_OBJECT(AController,Z_Param_RequestingController);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RequestPossession_Implementation(Z_Param_RequestingController);
	P_NATIVE_END;
}
// ********** End Interface UInteractionInterface Function RequestPossession ***********************

// ********** Begin Interface UInteractionInterface Function RequestSoulEject **********************
void IInteractionInterface::RequestSoulEject()
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_RequestSoulEject instead.");
}
static FName NAME_UInteractionInterface_RequestSoulEject = FName(TEXT("RequestSoulEject"));
void IInteractionInterface::Execute_RequestSoulEject(UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UInteractionInterface::StaticClass()));
	UFunction* const Func = O->FindFunction(NAME_UInteractionInterface_RequestSoulEject);
	if (Func)
	{
		O->ProcessEvent(Func, NULL);
	}
	else if (auto I = (IInteractionInterface*)(O->GetNativeInterfaceAddress(UInteractionInterface::StaticClass())))
	{
		I->RequestSoulEject_Implementation();
	}
}
struct Z_Construct_UFunction_UInteractionInterface_RequestSoulEject_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Possession" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Command to the vessel to force the ejection of the residing spirit. */" },
#endif
		{ "ModuleRelativePath", "Public/Interaction/SovereignInterfaceMain.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Command to the vessel to force the ejection of the residing spirit." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RequestSoulEject constinit property declarations **********************
// ********** End Function RequestSoulEject constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInteractionInterface_RequestSoulEject_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInteractionInterface, nullptr, "RequestSoulEject", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInteractionInterface_RequestSoulEject_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInteractionInterface_RequestSoulEject_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UInteractionInterface_RequestSoulEject()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInteractionInterface_RequestSoulEject_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IInteractionInterface::execRequestSoulEject)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RequestSoulEject_Implementation();
	P_NATIVE_END;
}
// ********** End Interface UInteractionInterface Function RequestSoulEject ************************

// ********** Begin Interface UInteractionInterface ************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UInteractionInterface;
UClass* UInteractionInterface::GetPrivateStaticClass()
{
	using TClass = UInteractionInterface;
	if (!Z_Registration_Info_UClass_UInteractionInterface.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("InteractionInterface"),
			Z_Registration_Info_UClass_UInteractionInterface.InnerSingleton,
			StaticRegisterNativesUInteractionInterface,
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
	return Z_Registration_Info_UClass_UInteractionInterface.InnerSingleton;
}
UClass* Z_Construct_UClass_UInteractionInterface_NoRegister()
{
	return UInteractionInterface::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UInteractionInterface_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Interaction/SovereignInterfaceMain.h" },
	};
#endif // WITH_METADATA

// ********** Begin Interface UInteractionInterface constinit property declarations ****************
// ********** End Interface UInteractionInterface constinit property declarations ******************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("CanBePossessed"), .Pointer = &IInteractionInterface::execCanBePossessed },
		{ .NameUTF8 = UTF8TEXT("CanInteract"), .Pointer = &IInteractionInterface::execCanInteract },
		{ .NameUTF8 = UTF8TEXT("Evolve"), .Pointer = &IInteractionInterface::execEvolve },
		{ .NameUTF8 = UTF8TEXT("GetInhabitingSpirit"), .Pointer = &IInteractionInterface::execGetInhabitingSpirit },
		{ .NameUTF8 = UTF8TEXT("GetInteractableName"), .Pointer = &IInteractionInterface::execGetInteractableName },
		{ .NameUTF8 = UTF8TEXT("GetInteractionHint"), .Pointer = &IInteractionInterface::execGetInteractionHint },
		{ .NameUTF8 = UTF8TEXT("GetPossessionAttachmentComponent"), .Pointer = &IInteractionInterface::execGetPossessionAttachmentComponent },
		{ .NameUTF8 = UTF8TEXT("GetPrimaryMesh"), .Pointer = &IInteractionInterface::execGetPrimaryMesh },
		{ .NameUTF8 = UTF8TEXT("GetSovereignSoul"), .Pointer = &IInteractionInterface::execGetSovereignSoul },
		{ .NameUTF8 = UTF8TEXT("IsSpiritEntity"), .Pointer = &IInteractionInterface::execIsSpiritEntity },
		{ .NameUTF8 = UTF8TEXT("OnBeginHover"), .Pointer = &IInteractionInterface::execOnBeginHover },
		{ .NameUTF8 = UTF8TEXT("OnEndHover"), .Pointer = &IInteractionInterface::execOnEndHover },
		{ .NameUTF8 = UTF8TEXT("OnInteract"), .Pointer = &IInteractionInterface::execOnInteract },
		{ .NameUTF8 = UTF8TEXT("OnSecondaryInteract"), .Pointer = &IInteractionInterface::execOnSecondaryInteract },
		{ .NameUTF8 = UTF8TEXT("RequestPossession"), .Pointer = &IInteractionInterface::execRequestPossession },
		{ .NameUTF8 = UTF8TEXT("RequestSoulEject"), .Pointer = &IInteractionInterface::execRequestSoulEject },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UInteractionInterface_CanBePossessed, "CanBePossessed" }, // 358738529
		{ &Z_Construct_UFunction_UInteractionInterface_CanInteract, "CanInteract" }, // 583150166
		{ &Z_Construct_UFunction_UInteractionInterface_Evolve, "Evolve" }, // 3216816603
		{ &Z_Construct_UFunction_UInteractionInterface_GetInhabitingSpirit, "GetInhabitingSpirit" }, // 2410596038
		{ &Z_Construct_UFunction_UInteractionInterface_GetInteractableName, "GetInteractableName" }, // 2390886213
		{ &Z_Construct_UFunction_UInteractionInterface_GetInteractionHint, "GetInteractionHint" }, // 2873277800
		{ &Z_Construct_UFunction_UInteractionInterface_GetPossessionAttachmentComponent, "GetPossessionAttachmentComponent" }, // 3952237846
		{ &Z_Construct_UFunction_UInteractionInterface_GetPrimaryMesh, "GetPrimaryMesh" }, // 2287857974
		{ &Z_Construct_UFunction_UInteractionInterface_GetSovereignSoul, "GetSovereignSoul" }, // 379285860
		{ &Z_Construct_UFunction_UInteractionInterface_IsSpiritEntity, "IsSpiritEntity" }, // 3559346358
		{ &Z_Construct_UFunction_UInteractionInterface_OnBeginHover, "OnBeginHover" }, // 91311197
		{ &Z_Construct_UFunction_UInteractionInterface_OnEndHover, "OnEndHover" }, // 2537030150
		{ &Z_Construct_UFunction_UInteractionInterface_OnInteract, "OnInteract" }, // 2255943681
		{ &Z_Construct_UFunction_UInteractionInterface_OnSecondaryInteract, "OnSecondaryInteract" }, // 3874284939
		{ &Z_Construct_UFunction_UInteractionInterface_RequestPossession, "RequestPossession" }, // 729513794
		{ &Z_Construct_UFunction_UInteractionInterface_RequestSoulEject, "RequestSoulEject" }, // 1016449881
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IInteractionInterface>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UInteractionInterface_Statics
UObject* (*const Z_Construct_UClass_UInteractionInterface_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_WispCPP7VR,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInteractionInterface_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UInteractionInterface_Statics::ClassParams = {
	&UInteractionInterface::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInteractionInterface_Statics::Class_MetaDataParams), Z_Construct_UClass_UInteractionInterface_Statics::Class_MetaDataParams)
};
void UInteractionInterface::StaticRegisterNativesUInteractionInterface()
{
	UClass* Class = UInteractionInterface::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UInteractionInterface_Statics::Funcs));
}
UClass* Z_Construct_UClass_UInteractionInterface()
{
	if (!Z_Registration_Info_UClass_UInteractionInterface.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInteractionInterface.OuterSingleton, Z_Construct_UClass_UInteractionInterface_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UInteractionInterface.OuterSingleton;
}
UInteractionInterface::UInteractionInterface(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UInteractionInterface);
// ********** End Interface UInteractionInterface **************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Interaction_SovereignInterfaceMain_h__Script_WispCPP7VR_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UInteractionInterface, UInteractionInterface::StaticClass, TEXT("UInteractionInterface"), &Z_Registration_Info_UClass_UInteractionInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInteractionInterface), 1550710059U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Interaction_SovereignInterfaceMain_h__Script_WispCPP7VR_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Interaction_SovereignInterfaceMain_h__Script_WispCPP7VR_3431304828{
	TEXT("/Script/WispCPP7VR"),
	Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Interaction_SovereignInterfaceMain_h__Script_WispCPP7VR_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Interaction_SovereignInterfaceMain_h__Script_WispCPP7VR_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
