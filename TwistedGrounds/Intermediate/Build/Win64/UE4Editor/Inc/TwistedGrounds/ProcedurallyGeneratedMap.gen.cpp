// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TwistedGrounds/ProcedurallyGeneratedMap.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeProcedurallyGeneratedMap() {}
// Cross Module References
	TWISTEDGROUNDS_API UClass* Z_Construct_UClass_AProcedurallyGeneratedMap_NoRegister();
	TWISTEDGROUNDS_API UClass* Z_Construct_UClass_AProcedurallyGeneratedMap();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_TwistedGrounds();
	TWISTEDGROUNDS_API UFunction* Z_Construct_UFunction_AProcedurallyGeneratedMap_GenerateMap();
	PROCEDURALMESHCOMPONENT_API UClass* Z_Construct_UClass_UProceduralMeshComponent_NoRegister();
// End Cross Module References
	void AProcedurallyGeneratedMap::StaticRegisterNativesAProcedurallyGeneratedMap()
	{
		UClass* Class = AProcedurallyGeneratedMap::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GenerateMap", &AProcedurallyGeneratedMap::execGenerateMap },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AProcedurallyGeneratedMap_GenerateMap_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProcedurallyGeneratedMap_GenerateMap_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ProcedurallyGeneratedMap.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AProcedurallyGeneratedMap_GenerateMap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AProcedurallyGeneratedMap, nullptr, "GenerateMap", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AProcedurallyGeneratedMap_GenerateMap_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AProcedurallyGeneratedMap_GenerateMap_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AProcedurallyGeneratedMap_GenerateMap()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AProcedurallyGeneratedMap_GenerateMap_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AProcedurallyGeneratedMap_NoRegister()
	{
		return AProcedurallyGeneratedMap::StaticClass();
	}
	struct Z_Construct_UClass_AProcedurallyGeneratedMap_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MeshComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MeshComponent;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_TwistedGrounds,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AProcedurallyGeneratedMap_GenerateMap, "GenerateMap" }, // 1809689899
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ProcedurallyGeneratedMap.h" },
		{ "ModuleRelativePath", "ProcedurallyGeneratedMap.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_MeshComponent_MetaData[] = {
		{ "Category", "ProcedurallyGeneratedMap" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ProcedurallyGeneratedMap.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_MeshComponent = { "MeshComponent", nullptr, (EPropertyFlags)0x00100000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AProcedurallyGeneratedMap, MeshComponent), Z_Construct_UClass_UProceduralMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_MeshComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_MeshComponent_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::NewProp_MeshComponent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AProcedurallyGeneratedMap>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::ClassParams = {
		&AProcedurallyGeneratedMap::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AProcedurallyGeneratedMap()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AProcedurallyGeneratedMap_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AProcedurallyGeneratedMap, 1746893624);
	template<> TWISTEDGROUNDS_API UClass* StaticClass<AProcedurallyGeneratedMap>()
	{
		return AProcedurallyGeneratedMap::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AProcedurallyGeneratedMap(Z_Construct_UClass_AProcedurallyGeneratedMap, &AProcedurallyGeneratedMap::StaticClass, TEXT("/Script/TwistedGrounds"), TEXT("AProcedurallyGeneratedMap"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AProcedurallyGeneratedMap);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
