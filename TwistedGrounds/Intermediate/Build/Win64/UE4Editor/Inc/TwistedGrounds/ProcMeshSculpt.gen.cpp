// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TwistedGrounds/ProcMeshSculpt.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeProcMeshSculpt() {}
// Cross Module References
	TWISTEDGROUNDS_API UClass* Z_Construct_UClass_AProcMeshSculpt_NoRegister();
	TWISTEDGROUNDS_API UClass* Z_Construct_UClass_AProcMeshSculpt();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_TwistedGrounds();
	TWISTEDGROUNDS_API UFunction* Z_Construct_UFunction_AProcMeshSculpt_Sculpt();
	TWISTEDGROUNDS_API UClass* Z_Construct_UClass_AProcedurallyGeneratedMap_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCurveFloat_NoRegister();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
// End Cross Module References
	void AProcMeshSculpt::StaticRegisterNativesAProcMeshSculpt()
	{
		UClass* Class = AProcMeshSculpt::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Sculpt", &AProcMeshSculpt::execSculpt },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AProcMeshSculpt_Sculpt_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProcMeshSculpt_Sculpt_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ProcMeshSculpt.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AProcMeshSculpt_Sculpt_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AProcMeshSculpt, nullptr, "Sculpt", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AProcMeshSculpt_Sculpt_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AProcMeshSculpt_Sculpt_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AProcMeshSculpt_Sculpt()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AProcMeshSculpt_Sculpt_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AProcMeshSculpt_NoRegister()
	{
		return AProcMeshSculpt::StaticClass();
	}
	struct Z_Construct_UClass_AProcMeshSculpt_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Map_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Map;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Curve_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Curve;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HitResult_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_HitResult;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AProcMeshSculpt_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_TwistedGrounds,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AProcMeshSculpt_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AProcMeshSculpt_Sculpt, "Sculpt" }, // 101463453
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProcMeshSculpt_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ProcMeshSculpt.h" },
		{ "ModuleRelativePath", "ProcMeshSculpt.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProcMeshSculpt_Statics::NewProp_Map_MetaData[] = {
		{ "Category", "ProcMeshSculpt" },
		{ "ModuleRelativePath", "ProcMeshSculpt.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProcMeshSculpt_Statics::NewProp_Map = { "Map", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AProcMeshSculpt, Map), Z_Construct_UClass_AProcedurallyGeneratedMap_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AProcMeshSculpt_Statics::NewProp_Map_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AProcMeshSculpt_Statics::NewProp_Map_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProcMeshSculpt_Statics::NewProp_Curve_MetaData[] = {
		{ "Category", "ProcMeshSculpt" },
		{ "ModuleRelativePath", "ProcMeshSculpt.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProcMeshSculpt_Statics::NewProp_Curve = { "Curve", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AProcMeshSculpt, Curve), Z_Construct_UClass_UCurveFloat_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AProcMeshSculpt_Statics::NewProp_Curve_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AProcMeshSculpt_Statics::NewProp_Curve_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProcMeshSculpt_Statics::NewProp_HitResult_MetaData[] = {
		{ "Category", "ProcMeshSculpt" },
		{ "ModuleRelativePath", "ProcMeshSculpt.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AProcMeshSculpt_Statics::NewProp_HitResult = { "HitResult", nullptr, (EPropertyFlags)0x0010008000000004, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AProcMeshSculpt, HitResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(Z_Construct_UClass_AProcMeshSculpt_Statics::NewProp_HitResult_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AProcMeshSculpt_Statics::NewProp_HitResult_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AProcMeshSculpt_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProcMeshSculpt_Statics::NewProp_Map,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProcMeshSculpt_Statics::NewProp_Curve,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProcMeshSculpt_Statics::NewProp_HitResult,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AProcMeshSculpt_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AProcMeshSculpt>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AProcMeshSculpt_Statics::ClassParams = {
		&AProcMeshSculpt::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AProcMeshSculpt_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AProcMeshSculpt_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AProcMeshSculpt_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AProcMeshSculpt_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AProcMeshSculpt()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AProcMeshSculpt_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AProcMeshSculpt, 2180463000);
	template<> TWISTEDGROUNDS_API UClass* StaticClass<AProcMeshSculpt>()
	{
		return AProcMeshSculpt::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AProcMeshSculpt(Z_Construct_UClass_AProcMeshSculpt, &AProcMeshSculpt::StaticClass, TEXT("/Script/TwistedGrounds"), TEXT("AProcMeshSculpt"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AProcMeshSculpt);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
