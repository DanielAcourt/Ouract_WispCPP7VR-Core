// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Entities/SovereignPawn.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSovereignPawn() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UFloatingPawnMovement_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UPawnMovementComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_WispCPP7VR();
WISPCPP7VR_API UClass* Z_Construct_UClass_ASovereignBaseEntity();
WISPCPP7VR_API UClass* Z_Construct_UClass_ASovereignPawn();
WISPCPP7VR_API UClass* Z_Construct_UClass_ASovereignPawn_NoRegister();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ASovereignPawn ***********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_ASovereignPawn;
UClass* ASovereignPawn::GetPrivateStaticClass()
{
	using TClass = ASovereignPawn;
	if (!Z_Registration_Info_UClass_ASovereignPawn.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SovereignPawn"),
			Z_Registration_Info_UClass_ASovereignPawn.InnerSingleton,
			StaticRegisterNativesASovereignPawn,
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
	return Z_Registration_Info_UClass_ASovereignPawn.InnerSingleton;
}
UClass* Z_Construct_UClass_ASovereignPawn_NoRegister()
{
	return ASovereignPawn::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ASovereignPawn_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * ASovereignPawn: A 'Living' version of the Base Entity.\n * It has all the Soul/DNA logic of the BaseEntity, but adds Pawn capabilities\n * for Wisp Possession and Movement.\n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Entities/SovereignPawn.h" },
		{ "ModuleRelativePath", "Public/Entities/SovereignPawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "ASovereignPawn: A 'Living' version of the Base Entity.\nIt has all the Soul/DNA logic of the BaseEntity, but adds Pawn capabilities\nfor Wisp Possession and Movement." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MovementComponent_MetaData[] = {
		{ "Category", "Sovereign|Movement" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Components for movement - can be added here or in children (like Orc/Bird) */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Entities/SovereignPawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Components for movement - can be added here or in children (like Orc/Bird)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FloatingMovement_MetaData[] = {
		{ "Category", "Sovereign|Movement" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Simple movement for a floating/growing entity\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Entities/SovereignPawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Simple movement for a floating/growing entity" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class ASovereignPawn constinit property declarations ***************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MovementComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FloatingMovement;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class ASovereignPawn constinit property declarations *****************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASovereignPawn>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_ASovereignPawn_Statics

// ********** Begin Class ASovereignPawn Property Definitions **************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASovereignPawn_Statics::NewProp_MovementComponent = { "MovementComponent", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASovereignPawn, MovementComponent), Z_Construct_UClass_UPawnMovementComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MovementComponent_MetaData), NewProp_MovementComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASovereignPawn_Statics::NewProp_FloatingMovement = { "FloatingMovement", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASovereignPawn, FloatingMovement), Z_Construct_UClass_UFloatingPawnMovement_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FloatingMovement_MetaData), NewProp_FloatingMovement_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASovereignPawn_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASovereignPawn_Statics::NewProp_MovementComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASovereignPawn_Statics::NewProp_FloatingMovement,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASovereignPawn_Statics::PropPointers) < 2048);
// ********** End Class ASovereignPawn Property Definitions ****************************************
UObject* (*const Z_Construct_UClass_ASovereignPawn_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ASovereignBaseEntity,
	(UObject* (*)())Z_Construct_UPackage__Script_WispCPP7VR,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASovereignPawn_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ASovereignPawn_Statics::ClassParams = {
	&ASovereignPawn::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ASovereignPawn_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ASovereignPawn_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASovereignPawn_Statics::Class_MetaDataParams), Z_Construct_UClass_ASovereignPawn_Statics::Class_MetaDataParams)
};
void ASovereignPawn::StaticRegisterNativesASovereignPawn()
{
}
UClass* Z_Construct_UClass_ASovereignPawn()
{
	if (!Z_Registration_Info_UClass_ASovereignPawn.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASovereignPawn.OuterSingleton, Z_Construct_UClass_ASovereignPawn_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ASovereignPawn.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ASovereignPawn);
ASovereignPawn::~ASovereignPawn() {}
// ********** End Class ASovereignPawn *************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Entities_SovereignPawn_h__Script_WispCPP7VR_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ASovereignPawn, ASovereignPawn::StaticClass, TEXT("ASovereignPawn"), &Z_Registration_Info_UClass_ASovereignPawn, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASovereignPawn), 632725579U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Entities_SovereignPawn_h__Script_WispCPP7VR_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Entities_SovereignPawn_h__Script_WispCPP7VR_599322579{
	TEXT("/Script/WispCPP7VR"),
	Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Entities_SovereignPawn_h__Script_WispCPP7VR_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Danie_Unreal_Projects_2027_repo_Ouract_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Core_WispCPP7VR_Source_WispCPP7VR_Public_Entities_SovereignPawn_h__Script_WispCPP7VR_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
