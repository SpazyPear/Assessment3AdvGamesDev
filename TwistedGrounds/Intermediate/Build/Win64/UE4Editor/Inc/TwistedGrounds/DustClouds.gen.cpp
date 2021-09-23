// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TwistedGrounds/DustClouds.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDustClouds() {}
// Cross Module References
	TWISTEDGROUNDS_API UClass* Z_Construct_UClass_ADustClouds_NoRegister();
	TWISTEDGROUNDS_API UClass* Z_Construct_UClass_ADustClouds();
	ENGINE_API UClass* Z_Construct_UClass_AEmitter();
	UPackage* Z_Construct_UPackage__Script_TwistedGrounds();
// End Cross Module References
	void ADustClouds::StaticRegisterNativesADustClouds()
	{
	}
	UClass* Z_Construct_UClass_ADustClouds_NoRegister()
	{
		return ADustClouds::StaticClass();
	}
	struct Z_Construct_UClass_ADustClouds_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ADustClouds_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AEmitter,
		(UObject* (*)())Z_Construct_UPackage__Script_TwistedGrounds,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADustClouds_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Activation Components|Activation Input Collision Game|Damage" },
		{ "IncludePath", "DustClouds.h" },
		{ "ModuleRelativePath", "DustClouds.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ADustClouds_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADustClouds>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ADustClouds_Statics::ClassParams = {
		&ADustClouds::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ADustClouds_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ADustClouds_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ADustClouds()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ADustClouds_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ADustClouds, 3511508932);
	template<> TWISTEDGROUNDS_API UClass* StaticClass<ADustClouds>()
	{
		return ADustClouds::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ADustClouds(Z_Construct_UClass_ADustClouds, &ADustClouds::StaticClass, TEXT("/Script/TwistedGrounds"), TEXT("ADustClouds"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ADustClouds);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
