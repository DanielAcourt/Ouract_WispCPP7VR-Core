// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Components/SovereignQiComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSovereignQiComponent() {}

// ********** Begin Cross Module References ********************************************************
UPackage* Z_Construct_UPackage__Script_WispCPP7VR();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignBaseComponent();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignQiComponent();
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignQiComponent_NoRegister();
// ********** End Cross Module References **********************************************************

// ********** Begin Class USovereignQiComponent Function AbsorbElementalQi *************************
struct Z_Construct_UFunction_USovereignQiComponent_AbsorbElementalQi_Statics
{
	struct SovereignQiComponent_eventAbsorbElementalQi_Parms
	{
		FName Element;
		float Amount;
		float SourcePurity;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Qi" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** New function to handle specific elemental absorption */" },
#endif
		{ "ModuleRelativePath", "Public/Components/SovereignQiComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "New function to handle specific elemental absorption" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function AbsorbElementalQi constinit property declarations *********************
	static const UECodeGen_Private::FNamePropertyParams NewProp_Element;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Amount;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SourcePurity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AbsorbElementalQi constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AbsorbElementalQi Property Definitions ********************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_USovereignQiComponent_AbsorbElementalQi_Statics::NewProp_Element = { "Element", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignQiComponent_eventAbsorbElementalQi_Parms, Element), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USovereignQiComponent_AbsorbElementalQi_Statics::NewProp_Amount = { "Amount", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignQiComponent_eventAbsorbElementalQi_Parms, Amount), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USovereignQiComponent_AbsorbElementalQi_Statics::NewProp_SourcePurity = { "SourcePurity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignQiComponent_eventAbsorbElementalQi_Parms, SourcePurity), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USovereignQiComponent_AbsorbElementalQi_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignQiComponent_AbsorbElementalQi_Statics::NewProp_Element,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignQiComponent_AbsorbElementalQi_Statics::NewProp_Amount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignQiComponent_AbsorbElementalQi_Statics::NewProp_SourcePurity,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignQiComponent_AbsorbElementalQi_Statics::PropPointers) < 2048);
// ********** End Function AbsorbElementalQi Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USovereignQiComponent_AbsorbElementalQi_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USovereignQiComponent, nullptr, "AbsorbElementalQi", 	Z_Construct_UFunction_USovereignQiComponent_AbsorbElementalQi_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignQiComponent_AbsorbElementalQi_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USovereignQiComponent_AbsorbElementalQi_Statics::SovereignQiComponent_eventAbsorbElementalQi_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignQiComponent_AbsorbElementalQi_Statics::Function_MetaDataParams), Z_Construct_UFunction_USovereignQiComponent_AbsorbElementalQi_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USovereignQiComponent_AbsorbElementalQi_Statics::SovereignQiComponent_eventAbsorbElementalQi_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USovereignQiComponent_AbsorbElementalQi()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USovereignQiComponent_AbsorbElementalQi_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USovereignQiComponent::execAbsorbElementalQi)
{
	P_GET_PROPERTY(FNameProperty,Z_Param_Element);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Amount);
	P_GET_PROPERTY(FFloatProperty,Z_Param_SourcePurity);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AbsorbElementalQi(Z_Param_Element,Z_Param_Amount,Z_Param_SourcePurity);
	P_NATIVE_END;
}
// ********** End Class USovereignQiComponent Function AbsorbElementalQi ***************************

// ********** Begin Class USovereignQiComponent Function AbsorbQi **********************************
struct Z_Construct_UFunction_USovereignQiComponent_AbsorbQi_Statics
{
	struct SovereignQiComponent_eventAbsorbQi_Parms
	{
		float Amount;
		float SourcePurity;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Qi" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** * Adds Qi to the pool. Mixing different purities will shift the overall QiPurity.\n\x09 * @param Amount The amount of Qi to add.\n\x09 * @param SourcePurity The purity of the Qi being absorbed.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/Components/SovereignQiComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Adds Qi to the pool. Mixing different purities will shift the overall QiPurity.\n@param Amount The amount of Qi to add.\n@param SourcePurity The purity of the Qi being absorbed." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function AbsorbQi constinit property declarations ******************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Amount;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SourcePurity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AbsorbQi constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AbsorbQi Property Definitions *****************************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USovereignQiComponent_AbsorbQi_Statics::NewProp_Amount = { "Amount", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignQiComponent_eventAbsorbQi_Parms, Amount), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USovereignQiComponent_AbsorbQi_Statics::NewProp_SourcePurity = { "SourcePurity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignQiComponent_eventAbsorbQi_Parms, SourcePurity), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USovereignQiComponent_AbsorbQi_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignQiComponent_AbsorbQi_Statics::NewProp_Amount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignQiComponent_AbsorbQi_Statics::NewProp_SourcePurity,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignQiComponent_AbsorbQi_Statics::PropPointers) < 2048);
// ********** End Function AbsorbQi Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USovereignQiComponent_AbsorbQi_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USovereignQiComponent, nullptr, "AbsorbQi", 	Z_Construct_UFunction_USovereignQiComponent_AbsorbQi_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignQiComponent_AbsorbQi_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USovereignQiComponent_AbsorbQi_Statics::SovereignQiComponent_eventAbsorbQi_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignQiComponent_AbsorbQi_Statics::Function_MetaDataParams), Z_Construct_UFunction_USovereignQiComponent_AbsorbQi_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USovereignQiComponent_AbsorbQi_Statics::SovereignQiComponent_eventAbsorbQi_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USovereignQiComponent_AbsorbQi()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USovereignQiComponent_AbsorbQi_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USovereignQiComponent::execAbsorbQi)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Amount);
	P_GET_PROPERTY(FFloatProperty,Z_Param_SourcePurity);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AbsorbQi(Z_Param_Amount,Z_Param_SourcePurity);
	P_NATIVE_END;
}
// ********** End Class USovereignQiComponent Function AbsorbQi ************************************

// ********** Begin Class USovereignQiComponent Function ResetDensity ******************************
struct Z_Construct_UFunction_USovereignQiComponent_ResetDensity_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Qi" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Resets the accumulated density (usually called after an Evolution) */" },
#endif
		{ "ModuleRelativePath", "Public/Components/SovereignQiComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Resets the accumulated density (usually called after an Evolution)" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ResetDensity constinit property declarations **************************
// ********** End Function ResetDensity constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USovereignQiComponent_ResetDensity_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USovereignQiComponent, nullptr, "ResetDensity", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignQiComponent_ResetDensity_Statics::Function_MetaDataParams), Z_Construct_UFunction_USovereignQiComponent_ResetDensity_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_USovereignQiComponent_ResetDensity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USovereignQiComponent_ResetDensity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USovereignQiComponent::execResetDensity)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ResetDensity();
	P_NATIVE_END;
}
// ********** End Class USovereignQiComponent Function ResetDensity ********************************

// ********** Begin Class USovereignQiComponent Function SpendQi ***********************************
struct Z_Construct_UFunction_USovereignQiComponent_SpendQi_Statics
{
	struct SovereignQiComponent_eventSpendQi_Parms
	{
		float Amount;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Sovereign|Qi" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** * Spends Qi for actions.\n\x09 * @param Amount The raw cost. Purity will be applied to reduce this cost.\n\x09 * @return True if the entity had enough Qi to perform the action.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/Components/SovereignQiComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Spends Qi for actions.\n@param Amount The raw cost. Purity will be applied to reduce this cost.\n@return True if the entity had enough Qi to perform the action." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SpendQi constinit property declarations *******************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Amount;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SpendQi constinit property declarations *********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SpendQi Property Definitions ******************************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USovereignQiComponent_SpendQi_Statics::NewProp_Amount = { "Amount", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SovereignQiComponent_eventSpendQi_Parms, Amount), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_USovereignQiComponent_SpendQi_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((SovereignQiComponent_eventSpendQi_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USovereignQiComponent_SpendQi_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SovereignQiComponent_eventSpendQi_Parms), &Z_Construct_UFunction_USovereignQiComponent_SpendQi_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USovereignQiComponent_SpendQi_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignQiComponent_SpendQi_Statics::NewProp_Amount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USovereignQiComponent_SpendQi_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignQiComponent_SpendQi_Statics::PropPointers) < 2048);
// ********** End Function SpendQi Property Definitions ********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USovereignQiComponent_SpendQi_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USovereignQiComponent, nullptr, "SpendQi", 	Z_Construct_UFunction_USovereignQiComponent_SpendQi_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignQiComponent_SpendQi_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USovereignQiComponent_SpendQi_Statics::SovereignQiComponent_eventSpendQi_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USovereignQiComponent_SpendQi_Statics::Function_MetaDataParams), Z_Construct_UFunction_USovereignQiComponent_SpendQi_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USovereignQiComponent_SpendQi_Statics::SovereignQiComponent_eventSpendQi_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USovereignQiComponent_SpendQi()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USovereignQiComponent_SpendQi_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USovereignQiComponent::execSpendQi)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Amount);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->SpendQi(Z_Param_Amount);
	P_NATIVE_END;
}
// ********** End Class USovereignQiComponent Function SpendQi *************************************

// ********** Begin Class USovereignQiComponent ****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_USovereignQiComponent;
UClass* USovereignQiComponent::GetPrivateStaticClass()
{
	using TClass = USovereignQiComponent;
	if (!Z_Registration_Info_UClass_USovereignQiComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SovereignQiComponent"),
			Z_Registration_Info_UClass_USovereignQiComponent.InnerSingleton,
			StaticRegisterNativesUSovereignQiComponent,
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
	return Z_Registration_Info_UClass_USovereignQiComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_USovereignQiComponent_NoRegister()
{
	return USovereignQiComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_USovereignQiComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * USovereignQiComponent\n * Handles the \"Spiritual\" energy of the entity.\n * Manages Qi levels, Purity (quality), and Density (experience/evolution).\n */" },
#endif
		{ "IncludePath", "Components/SovereignQiComponent.h" },
		{ "ModuleRelativePath", "Public/Components/SovereignQiComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "USovereignQiComponent\nHandles the \"Spiritual\" energy of the entity.\nManages Qi levels, Purity (quality), and Density (experience/evolution)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentQi_MetaData[] = {
		{ "Category", "Sovereign|Qi" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current usable Qi in the pool */" },
#endif
		{ "ModuleRelativePath", "Public/Components/SovereignQiComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current usable Qi in the pool" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxQiCapacity_MetaData[] = {
		{ "Category", "Sovereign|Qi" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Maximum amount of Qi this vessel can hold */" },
#endif
		{ "ModuleRelativePath", "Public/Components/SovereignQiComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum amount of Qi this vessel can hold" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_QiPurity_MetaData[] = {
		{ "Category", "Sovereign|Qi" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** * Qi Purity (0.0 to 1.0).\n\x09 * Higher purity reduces the cost of spells and increases evolution speed.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/Components/SovereignQiComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Qi Purity (0.0 to 1.0).\nHigher purity reduces the cost of spells and increases evolution speed." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalQiAccumulated_MetaData[] = {
		{ "Category", "Sovereign|Qi" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** * Qi Density / Accumulated Qi.\n\x09 * This is your \"XP\". When this hits a threshold, the owner Evolves.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/Components/SovereignQiComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Qi Density / Accumulated Qi.\nThis is your \"XP\". When this hits a threshold, the owner Evolves." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpiritualAlignment_MetaData[] = {
		{ "Category", "Sovereign|Qi" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Spiritual Alignment: Positive = Light, Negative = Dark. 0 = Primal/Neutral. */" },
#endif
		{ "ModuleRelativePath", "Public/Components/SovereignQiComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Spiritual Alignment: Positive = Light, Negative = Dark. 0 = Primal/Neutral." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ElementalResonance_MetaData[] = {
		{ "Category", "Sovereign|Qi" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** * Elemental Resonance.\n\x09 * Keys: \"Fire\", \"Earth\", \"Water\", \"Wind\"\n\x09 * Values: Resonance levels.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/Components/SovereignQiComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Elemental Resonance.\nKeys: \"Fire\", \"Earth\", \"Water\", \"Wind\"\nValues: Resonance levels." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class USovereignQiComponent constinit property declarations ********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentQi;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxQiCapacity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_QiPurity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TotalQiAccumulated;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SpiritualAlignment;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ElementalResonance_ValueProp;
	static const UECodeGen_Private::FNamePropertyParams NewProp_ElementalResonance_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_ElementalResonance;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class USovereignQiComponent constinit property declarations **********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("AbsorbElementalQi"), .Pointer = &USovereignQiComponent::execAbsorbElementalQi },
		{ .NameUTF8 = UTF8TEXT("AbsorbQi"), .Pointer = &USovereignQiComponent::execAbsorbQi },
		{ .NameUTF8 = UTF8TEXT("ResetDensity"), .Pointer = &USovereignQiComponent::execResetDensity },
		{ .NameUTF8 = UTF8TEXT("SpendQi"), .Pointer = &USovereignQiComponent::execSpendQi },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_USovereignQiComponent_AbsorbElementalQi, "AbsorbElementalQi" }, // 2582577964
		{ &Z_Construct_UFunction_USovereignQiComponent_AbsorbQi, "AbsorbQi" }, // 2096854869
		{ &Z_Construct_UFunction_USovereignQiComponent_ResetDensity, "ResetDensity" }, // 4241092620
		{ &Z_Construct_UFunction_USovereignQiComponent_SpendQi, "SpendQi" }, // 554499319
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USovereignQiComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_USovereignQiComponent_Statics

// ********** Begin Class USovereignQiComponent Property Definitions *******************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USovereignQiComponent_Statics::NewProp_CurrentQi = { "CurrentQi", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignQiComponent, CurrentQi), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentQi_MetaData), NewProp_CurrentQi_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USovereignQiComponent_Statics::NewProp_MaxQiCapacity = { "MaxQiCapacity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignQiComponent, MaxQiCapacity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxQiCapacity_MetaData), NewProp_MaxQiCapacity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USovereignQiComponent_Statics::NewProp_QiPurity = { "QiPurity", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignQiComponent, QiPurity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_QiPurity_MetaData), NewProp_QiPurity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USovereignQiComponent_Statics::NewProp_TotalQiAccumulated = { "TotalQiAccumulated", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignQiComponent, TotalQiAccumulated), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalQiAccumulated_MetaData), NewProp_TotalQiAccumulated_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USovereignQiComponent_Statics::NewProp_SpiritualAlignment = { "SpiritualAlignment", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignQiComponent, SpiritualAlignment), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpiritualAlignment_MetaData), NewProp_SpiritualAlignment_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USovereignQiComponent_Statics::NewProp_ElementalResonance_ValueProp = { "ElementalResonance", nullptr, (EPropertyFlags)0x0000000000020001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_USovereignQiComponent_Statics::NewProp_ElementalResonance_Key_KeyProp = { "ElementalResonance_Key", nullptr, (EPropertyFlags)0x0000000000020001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_USovereignQiComponent_Statics::NewProp_ElementalResonance = { "ElementalResonance", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USovereignQiComponent, ElementalResonance), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ElementalResonance_MetaData), NewProp_ElementalResonance_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USovereignQiComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignQiComponent_Statics::NewProp_CurrentQi,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignQiComponent_Statics::NewProp_MaxQiCapacity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignQiComponent_Statics::NewProp_QiPurity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignQiComponent_Statics::NewProp_TotalQiAccumulated,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignQiComponent_Statics::NewProp_SpiritualAlignment,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignQiComponent_Statics::NewProp_ElementalResonance_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignQiComponent_Statics::NewProp_ElementalResonance_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USovereignQiComponent_Statics::NewProp_ElementalResonance,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USovereignQiComponent_Statics::PropPointers) < 2048);
// ********** End Class USovereignQiComponent Property Definitions *********************************
UObject* (*const Z_Construct_UClass_USovereignQiComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_USovereignBaseComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_WispCPP7VR,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USovereignQiComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USovereignQiComponent_Statics::ClassParams = {
	&USovereignQiComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_USovereignQiComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_USovereignQiComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USovereignQiComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_USovereignQiComponent_Statics::Class_MetaDataParams)
};
void USovereignQiComponent::StaticRegisterNativesUSovereignQiComponent()
{
	UClass* Class = USovereignQiComponent::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_USovereignQiComponent_Statics::Funcs));
}
UClass* Z_Construct_UClass_USovereignQiComponent()
{
	if (!Z_Registration_Info_UClass_USovereignQiComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USovereignQiComponent.OuterSingleton, Z_Construct_UClass_USovereignQiComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USovereignQiComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, USovereignQiComponent);
USovereignQiComponent::~USovereignQiComponent() {}
// ********** End Class USovereignQiComponent ******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Components_SovereignQiComponent_h__Script_WispCPP7VR_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_USovereignQiComponent, USovereignQiComponent::StaticClass, TEXT("USovereignQiComponent"), &Z_Registration_Info_UClass_USovereignQiComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USovereignQiComponent), 2882978381U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Components_SovereignQiComponent_h__Script_WispCPP7VR_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Components_SovereignQiComponent_h__Script_WispCPP7VR_2326502107{
	TEXT("/Script/WispCPP7VR"),
	Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Components_SovereignQiComponent_h__Script_WispCPP7VR_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Components_SovereignQiComponent_h__Script_WispCPP7VR_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
