// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWispCPP7VR_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");	WISPCPP7VR_API UFunction* Z_Construct_UDelegateFunction_WispCPP7VR_OnActorSensed__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_WispCPP7VR;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_WispCPP7VR()
	{
		if (!Z_Registration_Info_UPackage__Script_WispCPP7VR.OuterSingleton)
		{
		static UObject* (*const SingletonFuncArray[])() = {
			(UObject* (*)())Z_Construct_UDelegateFunction_WispCPP7VR_OnActorSensed__DelegateSignature,
		};
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/WispCPP7VR",
			SingletonFuncArray,
			UE_ARRAY_COUNT(SingletonFuncArray),
			PKG_CompiledIn | 0x00000000,
			0x1CFAFF86,
			0x2343E28E,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_WispCPP7VR.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_WispCPP7VR.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_WispCPP7VR(Z_Construct_UPackage__Script_WispCPP7VR, TEXT("/Script/WispCPP7VR"), Z_Registration_Info_UPackage__Script_WispCPP7VR, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x1CFAFF86, 0x2343E28E));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
