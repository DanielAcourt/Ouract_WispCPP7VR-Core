// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SaveSystem/SovereignGameData.h"

#ifdef WISPCPP7VR_SovereignGameData_generated_h
#error "SovereignGameData.generated.h already included, missing '#pragma once' in SovereignGameData.h"
#endif
#define WISPCPP7VR_SovereignGameData_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin ScriptStruct FItemDefaults *****************************************************
struct Z_Construct_UScriptStruct_FItemDefaults_Statics;
#define FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_SaveSystem_SovereignGameData_h_26_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FItemDefaults_Statics; \
	WISPCPP7VR_API static class UScriptStruct* StaticStruct(); \
	typedef FTableRowBase Super;


struct FItemDefaults;
// ********** End ScriptStruct FItemDefaults *******************************************************

// ********** Begin ScriptStruct FEntitySaveData ***************************************************
struct Z_Construct_UScriptStruct_FEntitySaveData_Statics;
#define FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_SaveSystem_SovereignGameData_h_113_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FEntitySaveData_Statics; \
	WISPCPP7VR_API static class UScriptStruct* StaticStruct();


struct FEntitySaveData;
// ********** End ScriptStruct FEntitySaveData *****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_SaveSystem_SovereignGameData_h

// ********** Begin Enum ESovereignGrowthStage *****************************************************
#define FOREACH_ENUM_ESOVEREIGNGROWTHSTAGE(op) \
	op(ESovereignGrowthStage::Inception) \
	op(ESovereignGrowthStage::Seed) \
	op(ESovereignGrowthStage::Sprout) \
	op(ESovereignGrowthStage::Juvenile) \
	op(ESovereignGrowthStage::Adolescent) \
	op(ESovereignGrowthStage::Adult) \
	op(ESovereignGrowthStage::Elder) \
	op(ESovereignGrowthStage::Mature) \
	op(ESovereignGrowthStage::Retired) \
	op(ESovereignGrowthStage::Deteriorating) \
	op(ESovereignGrowthStage::GoldenCore) \
	op(ESovereignGrowthStage::Mythical) \
	op(ESovereignGrowthStage::Legendary) \
	op(ESovereignGrowthStage::PrimalSpirit) \
	op(ESovereignGrowthStage::Eternal) \
	op(ESovereignGrowthStage::Godly) 

enum class ESovereignGrowthStage : uint8;
template<> struct TIsUEnumClass<ESovereignGrowthStage> { enum { Value = true }; };
template<> WISPCPP7VR_NON_ATTRIBUTED_API UEnum* StaticEnum<ESovereignGrowthStage>();
// ********** End Enum ESovereignGrowthStage *******************************************************

// ********** Begin Enum EUpdateFrequency **********************************************************
#define FOREACH_ENUM_EUPDATEFREQUENCY(op) \
	op(EUpdateFrequency::Faster) \
	op(EUpdateFrequency::Realtime) \
	op(EUpdateFrequency::Standard) \
	op(EUpdateFrequency::Slow) \
	op(EUpdateFrequency::Slower) \
	op(EUpdateFrequency::Slowest) \
	op(EUpdateFrequency::Glacier) \
	op(EUpdateFrequency::Dormant) 

enum class EUpdateFrequency : uint8;
template<> struct TIsUEnumClass<EUpdateFrequency> { enum { Value = true }; };
template<> WISPCPP7VR_NON_ATTRIBUTED_API UEnum* StaticEnum<EUpdateFrequency>();
// ********** End Enum EUpdateFrequency ************************************************************

// ********** Begin Enum ESovereignElement *********************************************************
#define FOREACH_ENUM_ESOVEREIGNELEMENT(op) \
	op(ESovereignElement::None) \
	op(ESovereignElement::Light) \
	op(ESovereignElement::Dark) \
	op(ESovereignElement::Grey) \
	op(ESovereignElement::Fire) \
	op(ESovereignElement::Water) \
	op(ESovereignElement::Earth) \
	op(ESovereignElement::Nature) \
	op(ESovereignElement::Air) \
	op(ESovereignElement::Electric) \
	op(ESovereignElement::Fairy) \
	op(ESovereignElement::Dragon) 

enum class ESovereignElement : uint8;
template<> struct TIsUEnumClass<ESovereignElement> { enum { Value = true }; };
template<> WISPCPP7VR_NON_ATTRIBUTED_API UEnum* StaticEnum<ESovereignElement>();
// ********** End Enum ESovereignElement ***********************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
