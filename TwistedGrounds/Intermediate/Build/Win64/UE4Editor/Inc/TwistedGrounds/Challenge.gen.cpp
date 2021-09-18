// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TwistedGrounds/Challenge.h"
#include "Engine/Classes/Components/SkeletalMeshComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeChallenge() {}
// Cross Module References
	TWISTEDGROUNDS_API UClass* Z_Construct_UClass_UChallenge_NoRegister();
	TWISTEDGROUNDS_API UClass* Z_Construct_UClass_UChallenge();
	ENGINE_API UClass* Z_Construct_UClass_UAnimInstance();
	UPackage* Z_Construct_UPackage__Script_TwistedGrounds();
// End Cross Module References
	void UChallenge::StaticRegisterNativesUChallenge()
	{
	}
	UClass* Z_Construct_UClass_UChallenge_NoRegister()
	{
		return UChallenge::StaticClass();
	}
	struct Z_Construct_UClass_UChallenge_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIsSprinting_MetaData[];
#endif
		static void NewProp_bIsSprinting_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsSprinting;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UChallenge_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAnimInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_TwistedGrounds,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UChallenge_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "AnimInstance" },
		{ "IncludePath", "Challenge.h" },
		{ "ModuleRelativePath", "Challenge.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UChallenge_Statics::NewProp_bIsSprinting_MetaData[] = {
		{ "Category", "Challenge" },
		{ "ModuleRelativePath", "Challenge.h" },
	};
#endif
	void Z_Construct_UClass_UChallenge_Statics::NewProp_bIsSprinting_SetBit(void* Obj)
	{
		((UChallenge*)Obj)->bIsSprinting = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UChallenge_Statics::NewProp_bIsSprinting = { "bIsSprinting", nullptr, (EPropertyFlags)0x0020080000000805, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UChallenge), &Z_Construct_UClass_UChallenge_Statics::NewProp_bIsSprinting_SetBit, METADATA_PARAMS(Z_Construct_UClass_UChallenge_Statics::NewProp_bIsSprinting_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UChallenge_Statics::NewProp_bIsSprinting_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UChallenge_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UChallenge_Statics::NewProp_bIsSprinting,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UChallenge_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UChallenge>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UChallenge_Statics::ClassParams = {
		&UChallenge::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UChallenge_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UChallenge_Statics::PropPointers),
		0,
		0x009000A8u,
		METADATA_PARAMS(Z_Construct_UClass_UChallenge_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UChallenge_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UChallenge()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UChallenge_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UChallenge, 1304521274);
	template<> TWISTEDGROUNDS_API UClass* StaticClass<UChallenge>()
	{
		return UChallenge::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UChallenge(Z_Construct_UClass_UChallenge, &UChallenge::StaticClass, TEXT("/Script/TwistedGrounds"), TEXT("UChallenge"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UChallenge);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
