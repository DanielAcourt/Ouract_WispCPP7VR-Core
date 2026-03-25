// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Components/SovereignBioComponent.h"

#ifdef WISPCPP7VR_SovereignBioComponent_generated_h
#error "SovereignBioComponent.generated.h already included, missing '#pragma once' in SovereignBioComponent.h"
#endif
#define WISPCPP7VR_SovereignBioComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class USovereignBioComponent ***************************************************
struct Z_Construct_UClass_USovereignBioComponent_Statics;
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignBioComponent_NoRegister();

#define FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Components_SovereignBioComponent_h_28_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSovereignBioComponent(); \
	friend struct ::Z_Construct_UClass_USovereignBioComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend WISPCPP7VR_API UClass* ::Z_Construct_UClass_USovereignBioComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(USovereignBioComponent, USovereignBaseComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/WispCPP7VR"), Z_Construct_UClass_USovereignBioComponent_NoRegister) \
	DECLARE_SERIALIZER(USovereignBioComponent)


#define FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Components_SovereignBioComponent_h_28_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	USovereignBioComponent(USovereignBioComponent&&) = delete; \
	USovereignBioComponent(const USovereignBioComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USovereignBioComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USovereignBioComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(USovereignBioComponent) \
	NO_API virtual ~USovereignBioComponent();


#define FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Components_SovereignBioComponent_h_25_PROLOG
#define FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Components_SovereignBioComponent_h_28_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Components_SovereignBioComponent_h_28_INCLASS_NO_PURE_DECLS \
	FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Components_SovereignBioComponent_h_28_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class USovereignBioComponent;

// ********** End Class USovereignBioComponent *****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Components_SovereignBioComponent_h

// ********** Begin Enum ESovereignNutrient ********************************************************
#define FOREACH_ENUM_ESOVEREIGNNUTRIENT(op) \
	op(ESovereignNutrient::Carbs) \
	op(ESovereignNutrient::Proteins) \
	op(ESovereignNutrient::Fats) \
	op(ESovereignNutrient::Minerals) \
	op(ESovereignNutrient::QiEssence) 

enum class ESovereignNutrient : uint8;
template<> struct TIsUEnumClass<ESovereignNutrient> { enum { Value = true }; };
template<> WISPCPP7VR_NON_ATTRIBUTED_API UEnum* StaticEnum<ESovereignNutrient>();
// ********** End Enum ESovereignNutrient **********************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
