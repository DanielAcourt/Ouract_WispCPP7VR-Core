// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Interaction/SovereignInterfaceMain.h"

#ifdef WISPCPP7VR_SovereignInterfaceMain_generated_h
#error "SovereignInterfaceMain.generated.h already included, missing '#pragma once' in SovereignInterfaceMain.h"
#endif
#define WISPCPP7VR_SovereignInterfaceMain_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class AController;
class UMeshComponent;
class USceneComponent;
class USovereignSaveableEntityComponent;

// ********** Begin Interface UInteractionInterface ************************************************
#define FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Interaction_SovereignInterfaceMain_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual UMeshComponent* GetPrimaryMesh_Implementation() const { return NULL; }; \
	virtual void Evolve_Implementation() {}; \
	virtual void RequestSoulEject_Implementation() {}; \
	virtual bool IsSpiritEntity_Implementation() { return false; }; \
	virtual AActor* GetInhabitingSpirit_Implementation() { return NULL; }; \
	virtual USceneComponent* GetPossessionAttachmentComponent_Implementation() { return NULL; }; \
	virtual void RequestPossession_Implementation(AController* RequestingController) {}; \
	virtual bool CanBePossessed_Implementation() { return false; }; \
	virtual void OnSecondaryInteract_Implementation(AActor* Interactor) {}; \
	virtual FString GetInteractionHint_Implementation() { return TEXT(""); }; \
	virtual FText GetInteractableName_Implementation() { return FText::GetEmpty(); }; \
	virtual void OnInteract_Implementation(AActor* Interactor) {}; \
	virtual bool CanInteract_Implementation(AActor* Interactor) { return false; }; \
	virtual void OnEndHover_Implementation() {}; \
	virtual void OnBeginHover_Implementation() {}; \
	virtual USovereignSaveableEntityComponent* GetSovereignSoul_Implementation() const { return NULL; }; \
	DECLARE_FUNCTION(execGetPrimaryMesh); \
	DECLARE_FUNCTION(execEvolve); \
	DECLARE_FUNCTION(execRequestSoulEject); \
	DECLARE_FUNCTION(execIsSpiritEntity); \
	DECLARE_FUNCTION(execGetInhabitingSpirit); \
	DECLARE_FUNCTION(execGetPossessionAttachmentComponent); \
	DECLARE_FUNCTION(execRequestPossession); \
	DECLARE_FUNCTION(execCanBePossessed); \
	DECLARE_FUNCTION(execOnSecondaryInteract); \
	DECLARE_FUNCTION(execGetInteractionHint); \
	DECLARE_FUNCTION(execGetInteractableName); \
	DECLARE_FUNCTION(execOnInteract); \
	DECLARE_FUNCTION(execCanInteract); \
	DECLARE_FUNCTION(execOnEndHover); \
	DECLARE_FUNCTION(execOnBeginHover); \
	DECLARE_FUNCTION(execGetSovereignSoul);


#define FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Interaction_SovereignInterfaceMain_h_13_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UInteractionInterface_Statics;
WISPCPP7VR_API UClass* Z_Construct_UClass_UInteractionInterface_NoRegister();

#define FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Interaction_SovereignInterfaceMain_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	WISPCPP7VR_API UInteractionInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UInteractionInterface(UInteractionInterface&&) = delete; \
	UInteractionInterface(const UInteractionInterface&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(WISPCPP7VR_API, UInteractionInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInteractionInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInteractionInterface) \
	virtual ~UInteractionInterface() = default;


#define FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Interaction_SovereignInterfaceMain_h_13_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUInteractionInterface(); \
	friend struct ::Z_Construct_UClass_UInteractionInterface_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend WISPCPP7VR_API UClass* ::Z_Construct_UClass_UInteractionInterface_NoRegister(); \
public: \
	DECLARE_CLASS2(UInteractionInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/WispCPP7VR"), Z_Construct_UClass_UInteractionInterface_NoRegister) \
	DECLARE_SERIALIZER(UInteractionInterface)


#define FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Interaction_SovereignInterfaceMain_h_13_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Interaction_SovereignInterfaceMain_h_13_GENERATED_UINTERFACE_BODY() \
	FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Interaction_SovereignInterfaceMain_h_13_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Interaction_SovereignInterfaceMain_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IInteractionInterface() {} \
public: \
	typedef UInteractionInterface UClassType; \
	typedef IInteractionInterface ThisClass; \
	static bool Execute_CanBePossessed(UObject* O); \
	static bool Execute_CanInteract(UObject* O, AActor* Interactor); \
	static void Execute_Evolve(UObject* O); \
	static AActor* Execute_GetInhabitingSpirit(UObject* O); \
	static FText Execute_GetInteractableName(UObject* O); \
	static FString Execute_GetInteractionHint(UObject* O); \
	static USceneComponent* Execute_GetPossessionAttachmentComponent(UObject* O); \
	static UMeshComponent* Execute_GetPrimaryMesh(const UObject* O); \
	static USovereignSaveableEntityComponent* Execute_GetSovereignSoul(const UObject* O); \
	static bool Execute_IsSpiritEntity(UObject* O); \
	static void Execute_OnBeginHover(UObject* O); \
	static void Execute_OnEndHover(UObject* O); \
	static void Execute_OnInteract(UObject* O, AActor* Interactor); \
	static void Execute_OnSecondaryInteract(UObject* O, AActor* Interactor); \
	static void Execute_RequestPossession(UObject* O, AController* RequestingController); \
	static void Execute_RequestSoulEject(UObject* O); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Interaction_SovereignInterfaceMain_h_10_PROLOG
#define FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Interaction_SovereignInterfaceMain_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Interaction_SovereignInterfaceMain_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Interaction_SovereignInterfaceMain_h_13_CALLBACK_WRAPPERS \
	FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Interaction_SovereignInterfaceMain_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UInteractionInterface;

// ********** End Interface UInteractionInterface **************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Interaction_SovereignInterfaceMain_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
