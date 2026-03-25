// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Interaction/SovereignEntityInterface.h"

#ifdef WISPCPP7VR_SovereignEntityInterface_generated_h
#error "SovereignEntityInterface.generated.h already included, missing '#pragma once' in SovereignEntityInterface.h"
#endif
#define WISPCPP7VR_SovereignEntityInterface_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AController;
class UMeshComponent;
class USovereignSaveableEntityComponent;

// ********** Begin Interface USovereignEntityInterface ********************************************
#define FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Interaction_SovereignEntityInterface_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual UMeshComponent* GetPrimaryMesh_Implementation() const { return NULL; }; \
	virtual void OnWispExit_Implementation() {}; \
	virtual void OnWispEnter_Implementation(AController* WispController) {}; \
	virtual USovereignSaveableEntityComponent* GetSovereignSoul_Implementation() const { return NULL; }; \
	DECLARE_FUNCTION(execGetPrimaryMesh); \
	DECLARE_FUNCTION(execOnWispExit); \
	DECLARE_FUNCTION(execOnWispEnter); \
	DECLARE_FUNCTION(execGetSovereignSoul);


#define FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Interaction_SovereignEntityInterface_h_16_CALLBACK_WRAPPERS
struct Z_Construct_UClass_USovereignEntityInterface_Statics;
WISPCPP7VR_API UClass* Z_Construct_UClass_USovereignEntityInterface_NoRegister();

#define FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Interaction_SovereignEntityInterface_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	WISPCPP7VR_API USovereignEntityInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	USovereignEntityInterface(USovereignEntityInterface&&) = delete; \
	USovereignEntityInterface(const USovereignEntityInterface&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(WISPCPP7VR_API, USovereignEntityInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USovereignEntityInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USovereignEntityInterface) \
	virtual ~USovereignEntityInterface() = default;


#define FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Interaction_SovereignEntityInterface_h_16_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUSovereignEntityInterface(); \
	friend struct ::Z_Construct_UClass_USovereignEntityInterface_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend WISPCPP7VR_API UClass* ::Z_Construct_UClass_USovereignEntityInterface_NoRegister(); \
public: \
	DECLARE_CLASS2(USovereignEntityInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/WispCPP7VR"), Z_Construct_UClass_USovereignEntityInterface_NoRegister) \
	DECLARE_SERIALIZER(USovereignEntityInterface)


#define FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Interaction_SovereignEntityInterface_h_16_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Interaction_SovereignEntityInterface_h_16_GENERATED_UINTERFACE_BODY() \
	FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Interaction_SovereignEntityInterface_h_16_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Interaction_SovereignEntityInterface_h_16_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~ISovereignEntityInterface() {} \
public: \
	typedef USovereignEntityInterface UClassType; \
	typedef ISovereignEntityInterface ThisClass; \
	static UMeshComponent* Execute_GetPrimaryMesh(const UObject* O); \
	static USovereignSaveableEntityComponent* Execute_GetSovereignSoul(const UObject* O); \
	static void Execute_OnWispEnter(UObject* O, AController* WispController); \
	static void Execute_OnWispExit(UObject* O); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Interaction_SovereignEntityInterface_h_13_PROLOG
#define FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Interaction_SovereignEntityInterface_h_26_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Interaction_SovereignEntityInterface_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Interaction_SovereignEntityInterface_h_16_CALLBACK_WRAPPERS \
	FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Interaction_SovereignEntityInterface_h_16_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class USovereignEntityInterface;

// ********** End Interface USovereignEntityInterface **********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Interaction_SovereignEntityInterface_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
