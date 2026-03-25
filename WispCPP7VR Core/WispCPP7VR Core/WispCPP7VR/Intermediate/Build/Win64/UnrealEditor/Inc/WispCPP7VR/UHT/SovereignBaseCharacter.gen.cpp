// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Entities/SovereignBaseCharacter.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSovereignBaseCharacter() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
UPackage* Z_Construct_UPackage__Script_WispCPP7VR();
WISPCPP7VR_API UClass* Z_Construct_UClass_ASovereignBaseCharacter();
WISPCPP7VR_API UClass* Z_Construct_UClass_ASovereignBaseCharacter_NoRegister();
WISPCPP7VR_API UClass* Z_Construct_UClass_UInteractionInterface_NoRegister();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignAttributeComponent_NoRegister();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignControllerComponent_NoRegister();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignElementComponent_NoRegister();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignEntityInterface_NoRegister();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignQiComponent_NoRegister();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignSaveableEntityComponent_NoRegister();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignSpeciesData_NoRegister();
WISPCPP7VR_API UFunction* Z_Construct_UDelegateFunction_WispCPP7VR_OnActorSensed__DelegateSignature();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FOnActorSensed ********************************************************
struct Z_Construct_UDelegateFunction_WispCPP7VR_OnActorSensed__DelegateSignature_Statics
{
	struct _Script_WispCPP7VR_eventOnActorSensed_Parms
	{
		AActor* SensedActor;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// This creates a custom event node for your Blueprints\n" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignBaseCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "This creates a custom event node for your Blueprints" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Delegate FOnActorSensed constinit property declarations ************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SensedActor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FOnActorSensed constinit property declarations **************************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FOnActorSensed Property Definitions ***********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_WispCPP7VR_OnActorSensed__DelegateSignature_Statics::NewProp_SensedActor = { "SensedActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_WispCPP7VR_eventOnActorSensed_Parms, SensedActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_WispCPP7VR_OnActorSensed__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_WispCPP7VR_OnActorSensed__DelegateSignature_Statics::NewProp_SensedActor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_WispCPP7VR_OnActorSensed__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FOnActorSensed Property Definitions *************************************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_WispCPP7VR_OnActorSensed__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_WispCPP7VR, nullptr, "OnActorSensed__DelegateSignature", 	Z_Construct_UDelegateFunction_WispCPP7VR_OnActorSensed__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_WispCPP7VR_OnActorSensed__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_WispCPP7VR_OnActorSensed__DelegateSignature_Statics::_Script_WispCPP7VR_eventOnActorSensed_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_WispCPP7VR_OnActorSensed__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_WispCPP7VR_OnActorSensed__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_WispCPP7VR_OnActorSensed__DelegateSignature_Statics::_Script_WispCPP7VR_eventOnActorSensed_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_WispCPP7VR_OnActorSensed__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_WispCPP7VR_OnActorSensed__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnActorSensed_DelegateWrapper(const FMulticastScriptDelegate& OnActorSensed, AActor* SensedActor)
{
	struct _Script_WispCPP7VR_eventOnActorSensed_Parms
	{
		AActor* SensedActor;
	};
	_Script_WispCPP7VR_eventOnActorSensed_Parms Parms;
	Parms.SensedActor=SensedActor;
	OnActorSensed.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnActorSensed **********************************************************

// ********** Begin Class ASovereignBaseCharacter Function GetSensedActor **************************
struct Z_Construct_UFunction_ASovereignBaseCharacter_GetSensedActor_Statics
{
	struct SovereignBaseCharacter_eventGetSensedActor_Parms
	{
		AActor* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Performs a sphere trace to find the actor the player is looking at this is the i think wrong way to do this Blueprint callable */" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignBaseCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Performs a sphere trace to find the actor the player is looking at this is the i think wrong way to do this Blueprint callable" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetSensedActor constinit property declarations ************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSensedActor constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSensedActor Property Definitions ***********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASovereignBaseCharacter_GetSensedActor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignBaseCharacter_eventGetSensedActor_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASovereignBaseCharacter_GetSensedActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASovereignBaseCharacter_GetSensedActor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ASovereignBaseCharacter_GetSensedActor_Statics::PropPointers) < 2048);
// ********** End Function GetSensedActor Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASovereignBaseCharacter_GetSensedActor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ASovereignBaseCharacter, nullptr, "GetSensedActor", 	Z_Construct_UFunction_ASovereignBaseCharacter_GetSensedActor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_ASovereignBaseCharacter_GetSensedActor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_ASovereignBaseCharacter_GetSensedActor_Statics::SovereignBaseCharacter_eventGetSensedActor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASovereignBaseCharacter_GetSensedActor_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASovereignBaseCharacter_GetSensedActor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ASovereignBaseCharacter_GetSensedActor_Statics::SovereignBaseCharacter_eventGetSensedActor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ASovereignBaseCharacter_GetSensedActor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASovereignBaseCharacter_GetSensedActor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASovereignBaseCharacter::execGetSensedActor)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(AActor**)Z_Param__Result=P_THIS->GetSensedActor();
	P_NATIVE_END;
}
// ********** End Class ASovereignBaseCharacter Function GetSensedActor ****************************

// ********** Begin Class ASovereignBaseCharacter **************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_ASovereignBaseCharacter;
UClass* ASovereignBaseCharacter::GetPrivateStaticClass()
{
	using TClass = ASovereignBaseCharacter;
	if (!Z_Registration_Info_UClass_ASovereignBaseCharacter.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SovereignBaseCharacter"),
			Z_Registration_Info_UClass_ASovereignBaseCharacter.InnerSingleton,
			StaticRegisterNativesASovereignBaseCharacter,
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
	return Z_Registration_Info_UClass_ASovereignBaseCharacter.InnerSingleton;
}
UClass* Z_Construct_UClass_ASovereignBaseCharacter_NoRegister()
{
	return ASovereignBaseCharacter::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ASovereignBaseCharacter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * ASovereignBaseCharacter\n * The 'Master Vessel' for everything from Erisis to Dragons.\n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Entities/SovereignBaseCharacter.h" },
		{ "ModuleRelativePath", "Public/Entities/SovereignBaseCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "ASovereignBaseCharacter\nThe 'Master Vessel' for everything from Erisis to Dragons." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnActorSensed_MetaData[] = {
		{ "Category", "Sovereign|Senses" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// This allows you to bind logic in BP (e.g., highlighting a wisp when you look at it)\n" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignBaseCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "This allows you to bind logic in BP (e.g., highlighting a wisp when you look at it)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpeciesData_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Sovereign|Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The \"Advanced\" data asset defining growth stages, health, and species attributes */" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignBaseCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The \"Advanced\" data asset defining growth stages, health, and species attributes" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentGrowthStage_MetaData[] = {
		{ "Category", "Sovereign|Growth" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Which of the 8 growth stages are we currently in? (0 to 7) */" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignBaseCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Which of the 8 growth stages are we currently in? (0 to 7)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SaveDataComponent_MetaData[] = {
		{ "Category", "Sovereign|SaveSystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Every Sovereign Entity needs the Soul Hub */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Entities/SovereignBaseCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Every Sovereign Entity needs the Soul Hub" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCanBePossessed_MetaData[] = {
		{ "Category", "Sovereign|Possession" },
		{ "ModuleRelativePath", "Public/Entities/SovereignBaseCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttributeComponent_MetaData[] = {
		{ "Category", "Sovereign|Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Entities/SovereignBaseCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_QiComponent_MetaData[] = {
		{ "Category", "Sovereign|Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Renamed to match Wisp code\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Entities/SovereignBaseCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Renamed to match Wisp code" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ElementComponent_MetaData[] = {
		{ "Category", "Sovereign|Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Added this! The Wisp needs it.\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Entities/SovereignBaseCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Added this! The Wisp needs it." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ControlComponent_MetaData[] = {
		{ "Category", "Sovereign|Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Entities/SovereignBaseCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultMappingContext_MetaData[] = {
		{ "Category", "Sovereign|Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Input Assets - Assign these in the Character Blueprint */" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignBaseCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Input Assets - Assign these in the Character Blueprint" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveAction_MetaData[] = {
		{ "Category", "Sovereign|Input" },
		{ "ModuleRelativePath", "Public/Entities/SovereignBaseCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LookAction_MetaData[] = {
		{ "Category", "Sovereign|Input" },
		{ "ModuleRelativePath", "Public/Entities/SovereignBaseCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractAction_MetaData[] = {
		{ "Category", "Sovereign|Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Handles all Interaction Between 2 entities\n" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignBaseCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handles all Interaction Between 2 entities" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PossessAction_MetaData[] = {
		{ "Category", "Sovereign|Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Checks if player can Possess or i possessing\n" },
#endif
		{ "ModuleRelativePath", "Public/Entities/SovereignBaseCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Checks if player can Possess or i possessing" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class ASovereignBaseCharacter constinit property declarations ******************
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnActorSensed;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpeciesData;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentGrowthStage;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SaveDataComponent;
	static void NewProp_bCanBePossessed_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCanBePossessed;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AttributeComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_QiComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ElementComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ControlComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DefaultMappingContext;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MoveAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LookAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InteractAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PossessAction;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class ASovereignBaseCharacter constinit property declarations ********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetSensedActor"), .Pointer = &ASovereignBaseCharacter::execGetSensedActor },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ASovereignBaseCharacter_GetSensedActor, "GetSensedActor" }, // 3755901682
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASovereignBaseCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_ASovereignBaseCharacter_Statics

// ********** Begin Class ASovereignBaseCharacter Property Definitions *****************************
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_ASovereignBaseCharacter_Statics::NewProp_OnActorSensed = { "OnActorSensed", nullptr, (EPropertyFlags)0x0010100010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASovereignBaseCharacter, OnActorSensed), Z_Construct_UDelegateFunction_WispCPP7VR_OnActorSensed__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnActorSensed_MetaData), NewProp_OnActorSensed_MetaData) }; // 798658853
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASovereignBaseCharacter_Statics::NewProp_SpeciesData = { "SpeciesData", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASovereignBaseCharacter, SpeciesData), Z_Construct_UClass_USovereignSpeciesData_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpeciesData_MetaData), NewProp_SpeciesData_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ASovereignBaseCharacter_Statics::NewProp_CurrentGrowthStage = { "CurrentGrowthStage", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASovereignBaseCharacter, CurrentGrowthStage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentGrowthStage_MetaData), NewProp_CurrentGrowthStage_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASovereignBaseCharacter_Statics::NewProp_SaveDataComponent = { "SaveDataComponent", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASovereignBaseCharacter, SaveDataComponent), Z_Construct_UClass_USovereignSaveableEntityComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SaveDataComponent_MetaData), NewProp_SaveDataComponent_MetaData) };
void Z_Construct_UClass_ASovereignBaseCharacter_Statics::NewProp_bCanBePossessed_SetBit(void* Obj)
{
	((ASovereignBaseCharacter*)Obj)->bCanBePossessed = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASovereignBaseCharacter_Statics::NewProp_bCanBePossessed = { "bCanBePossessed", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ASovereignBaseCharacter), &Z_Construct_UClass_ASovereignBaseCharacter_Statics::NewProp_bCanBePossessed_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCanBePossessed_MetaData), NewProp_bCanBePossessed_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASovereignBaseCharacter_Statics::NewProp_AttributeComponent = { "AttributeComponent", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASovereignBaseCharacter, AttributeComponent), Z_Construct_UClass_USovereignAttributeComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttributeComponent_MetaData), NewProp_AttributeComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASovereignBaseCharacter_Statics::NewProp_QiComponent = { "QiComponent", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASovereignBaseCharacter, QiComponent), Z_Construct_UClass_USovereignQiComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_QiComponent_MetaData), NewProp_QiComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASovereignBaseCharacter_Statics::NewProp_ElementComponent = { "ElementComponent", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASovereignBaseCharacter, ElementComponent), Z_Construct_UClass_USovereignElementComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ElementComponent_MetaData), NewProp_ElementComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASovereignBaseCharacter_Statics::NewProp_ControlComponent = { "ControlComponent", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASovereignBaseCharacter, ControlComponent), Z_Construct_UClass_USovereignControllerComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ControlComponent_MetaData), NewProp_ControlComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASovereignBaseCharacter_Statics::NewProp_DefaultMappingContext = { "DefaultMappingContext", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASovereignBaseCharacter, DefaultMappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultMappingContext_MetaData), NewProp_DefaultMappingContext_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASovereignBaseCharacter_Statics::NewProp_MoveAction = { "MoveAction", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASovereignBaseCharacter, MoveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveAction_MetaData), NewProp_MoveAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASovereignBaseCharacter_Statics::NewProp_LookAction = { "LookAction", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASovereignBaseCharacter, LookAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LookAction_MetaData), NewProp_LookAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASovereignBaseCharacter_Statics::NewProp_InteractAction = { "InteractAction", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASovereignBaseCharacter, InteractAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractAction_MetaData), NewProp_InteractAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASovereignBaseCharacter_Statics::NewProp_PossessAction = { "PossessAction", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASovereignBaseCharacter, PossessAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PossessAction_MetaData), NewProp_PossessAction_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASovereignBaseCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASovereignBaseCharacter_Statics::NewProp_OnActorSensed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASovereignBaseCharacter_Statics::NewProp_SpeciesData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASovereignBaseCharacter_Statics::NewProp_CurrentGrowthStage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASovereignBaseCharacter_Statics::NewProp_SaveDataComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASovereignBaseCharacter_Statics::NewProp_bCanBePossessed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASovereignBaseCharacter_Statics::NewProp_AttributeComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASovereignBaseCharacter_Statics::NewProp_QiComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASovereignBaseCharacter_Statics::NewProp_ElementComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASovereignBaseCharacter_Statics::NewProp_ControlComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASovereignBaseCharacter_Statics::NewProp_DefaultMappingContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASovereignBaseCharacter_Statics::NewProp_MoveAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASovereignBaseCharacter_Statics::NewProp_LookAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASovereignBaseCharacter_Statics::NewProp_InteractAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASovereignBaseCharacter_Statics::NewProp_PossessAction,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASovereignBaseCharacter_Statics::PropPointers) < 2048);
// ********** End Class ASovereignBaseCharacter Property Definitions *******************************
UObject* (*const Z_Construct_UClass_ASovereignBaseCharacter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_WispCPP7VR,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASovereignBaseCharacter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_ASovereignBaseCharacter_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UInteractionInterface_NoRegister, (int32)VTABLE_OFFSET(ASovereignBaseCharacter, IInteractionInterface), false },  // 1550710059
	{ Z_Construct_UClass_USovereignEntityInterface_NoRegister, (int32)VTABLE_OFFSET(ASovereignBaseCharacter, ISovereignEntityInterface), false },  // 3695919034
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_ASovereignBaseCharacter_Statics::ClassParams = {
	&ASovereignBaseCharacter::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ASovereignBaseCharacter_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ASovereignBaseCharacter_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASovereignBaseCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_ASovereignBaseCharacter_Statics::Class_MetaDataParams)
};
void ASovereignBaseCharacter::StaticRegisterNativesASovereignBaseCharacter()
{
	UClass* Class = ASovereignBaseCharacter::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_ASovereignBaseCharacter_Statics::Funcs));
}
UClass* Z_Construct_UClass_ASovereignBaseCharacter()
{
	if (!Z_Registration_Info_UClass_ASovereignBaseCharacter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASovereignBaseCharacter.OuterSingleton, Z_Construct_UClass_ASovereignBaseCharacter_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ASovereignBaseCharacter.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ASovereignBaseCharacter);
ASovereignBaseCharacter::~ASovereignBaseCharacter() {}
// ********** End Class ASovereignBaseCharacter ****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Entities_SovereignBaseCharacter_h__Script_WispCPP7VR_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ASovereignBaseCharacter, ASovereignBaseCharacter::StaticClass, TEXT("ASovereignBaseCharacter"), &Z_Registration_Info_UClass_ASovereignBaseCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASovereignBaseCharacter), 227047447U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Entities_SovereignBaseCharacter_h__Script_WispCPP7VR_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Entities_SovereignBaseCharacter_h__Script_WispCPP7VR_1717339315{
	TEXT("/Script/WispCPP7VR"),
	Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Entities_SovereignBaseCharacter_h__Script_WispCPP7VR_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Entities_SovereignBaseCharacter_h__Script_WispCPP7VR_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
