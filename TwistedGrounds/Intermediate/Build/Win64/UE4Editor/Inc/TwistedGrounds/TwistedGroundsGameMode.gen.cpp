// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TwistedGrounds/TwistedGroundsGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTwistedGroundsGameMode() {}
// Cross Module References
	TWISTEDGROUNDS_API UClass* Z_Construct_UClass_ATwistedGroundsGameMode_NoRegister();
	TWISTEDGROUNDS_API UClass* Z_Construct_UClass_ATwistedGroundsGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_TwistedGrounds();
// End Cross Module References
	void ATwistedGroundsGameMode::StaticRegisterNativesATwistedGroundsGameMode()
	{
	}
	UClass* Z_Construct_UClass_ATwistedGroundsGameMode_NoRegister()
	{
		return ATwistedGroundsGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ATwistedGroundsGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATwistedGroundsGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_TwistedGrounds,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATwistedGroundsGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "TwistedGroundsGameMode.h" },
		{ "ModuleRelativePath", "TwistedGroundsGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATwistedGroundsGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATwistedGroundsGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ATwistedGroundsGameMode_Statics::ClassParams = {
		&ATwistedGroundsGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_ATwistedGroundsGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ATwistedGroundsGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ATwistedGroundsGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ATwistedGroundsGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ATwistedGroundsGameMode, 1821946198);
	template<> TWISTEDGROUNDS_API UClass* StaticClass<ATwistedGroundsGameMode>()
	{
		return ATwistedGroundsGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ATwistedGroundsGameMode(Z_Construct_UClass_ATwistedGroundsGameMode, &ATwistedGroundsGameMode::StaticClass, TEXT("/Script/TwistedGrounds"), TEXT("ATwistedGroundsGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATwistedGroundsGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
