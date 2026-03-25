// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Entities/SovereignBaseEntity.h"

#ifdef WISPCPP7VR_SovereignBaseEntity_generated_h
#error "SovereignBaseEntity.generated.h already included, missing '#pragma once' in SovereignBaseEntity.h"
#endif
#define WISPCPP7VR_SovereignBaseEntity_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class USovereignSaveableEntityComponent;
class USovereignSpeciesData;
struct FGuid;

// ********** Begin Class ASovereignBaseEntity *****************************************************
#define FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Entities_SovereignBaseEntity_h_35_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execRefreshVisuals); \
	DECLARE_FUNCTION(execInitializeFromSovereignData); \
	DECLARE_FUNCTION(execIsReadyForMating); \
	DECLARE_FUNCTION(execAttemptMating); \
	DECLARE_FUNCTION(execGetSovereignID); \
	DECLARE_FUNCTION(execIngestSovereignTag); \
	DECLARE_FUNCTION(execGetSaveDataComponent);


struct Z_Construct_UClass_ASovereignBaseEntity_Statics;
WISPCPP7VR_API UClass* Z_Construct_UClass_ASovereignBaseEntity_NoRegister();

#define FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Entities_SovereignBaseEntity_h_35_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASovereignBaseEntity(); \
	friend struct ::Z_Construct_UClass_ASovereignBaseEntity_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend WISPCPP7VR_API UClass* ::Z_Construct_UClass_ASovereignBaseEntity_NoRegister(); \
public: \
	DECLARE_CLASS2(ASovereignBaseEntity, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/WispCPP7VR"), Z_Construct_UClass_ASovereignBaseEntity_NoRegister) \
	DECLARE_SERIALIZER(ASovereignBaseEntity) \
	virtual UObject* _getUObject() const override { return const_cast<ASovereignBaseEntity*>(this); }


#define FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Entities_SovereignBaseEntity_h_35_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	ASovereignBaseEntity(ASovereignBaseEntity&&) = delete; \
	ASovereignBaseEntity(const ASovereignBaseEntity&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASovereignBaseEntity); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASovereignBaseEntity); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASovereignBaseEntity) \
	NO_API virtual ~ASovereignBaseEntity();


#define FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Entities_SovereignBaseEntity_h_32_PROLOG
#define FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Entities_SovereignBaseEntity_h_35_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Entities_SovereignBaseEntity_h_35_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Entities_SovereignBaseEntity_h_35_INCLASS_NO_PURE_DECLS \
	FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Entities_SovereignBaseEntity_h_35_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ASovereignBaseEntity;

// ********** End Class ASovereignBaseEntity *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Entities_SovereignBaseEntity_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
