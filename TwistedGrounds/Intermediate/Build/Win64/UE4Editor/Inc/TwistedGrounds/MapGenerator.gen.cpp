// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TwistedGrounds/MapGenerator.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMapGenerator() {}
// Cross Module References
	TWISTEDGROUNDS_API UClass* Z_Construct_UClass_AMapGenerator_NoRegister();
	TWISTEDGROUNDS_API UClass* Z_Construct_UClass_AMapGenerator();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_TwistedGrounds();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	TWISTEDGROUNDS_API UClass* Z_Construct_UClass_AProcMeshSculpt_NoRegister();
	TWISTEDGROUNDS_API UClass* Z_Construct_UClass_ADustClouds_NoRegister();
	TWISTEDGROUNDS_API UClass* Z_Construct_UClass_APlayerCharacter_NoRegister();
	TWISTEDGROUNDS_API UClass* Z_Construct_UClass_AProcedurallyGeneratedMap_NoRegister();
// End Cross Module References
	void AMapGenerator::StaticRegisterNativesAMapGenerator()
	{
	}
	UClass* Z_Construct_UClass_AMapGenerator_NoRegister()
	{
		return AMapGenerator::StaticClass();
	}
	struct Z_Construct_UClass_AMapGenerator_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bRegenerateMap_MetaData[];
#endif
		static void NewProp_bRegenerateMap_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bRegenerateMap;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PerlinRoughness_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_PerlinRoughness;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PerlinScale_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_PerlinScale;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ChunkGridSize_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ChunkGridSize;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ChunkHeight_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ChunkHeight;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ChunkWidth_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ChunkWidth;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ChunkRadius_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ChunkRadius;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PGMaterial_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PGMaterial;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Sculptor_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_Sculptor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SmallDustEmitter_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_SmallDustEmitter;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BigDustEmitter_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_BigDustEmitter;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PlayerToSpawn_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_PlayerToSpawn;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PGMap_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_PGMap;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PerlinOffset_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_PerlinOffset;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMapGenerator_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_TwistedGrounds,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMapGenerator_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "MapGenerator.h" },
		{ "ModuleRelativePath", "MapGenerator.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMapGenerator_Statics::NewProp_bRegenerateMap_MetaData[] = {
		{ "Category", "MapGenerator" },
		{ "ModuleRelativePath", "MapGenerator.h" },
	};
#endif
	void Z_Construct_UClass_AMapGenerator_Statics::NewProp_bRegenerateMap_SetBit(void* Obj)
	{
		((AMapGenerator*)Obj)->bRegenerateMap = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMapGenerator_Statics::NewProp_bRegenerateMap = { "bRegenerateMap", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMapGenerator), &Z_Construct_UClass_AMapGenerator_Statics::NewProp_bRegenerateMap_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMapGenerator_Statics::NewProp_bRegenerateMap_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMapGenerator_Statics::NewProp_bRegenerateMap_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMapGenerator_Statics::NewProp_PerlinRoughness_MetaData[] = {
		{ "Category", "MapGenerator" },
		{ "ModuleRelativePath", "MapGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMapGenerator_Statics::NewProp_PerlinRoughness = { "PerlinRoughness", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMapGenerator, PerlinRoughness), METADATA_PARAMS(Z_Construct_UClass_AMapGenerator_Statics::NewProp_PerlinRoughness_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMapGenerator_Statics::NewProp_PerlinRoughness_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMapGenerator_Statics::NewProp_PerlinScale_MetaData[] = {
		{ "Category", "MapGenerator" },
		{ "Comment", "//The size of each chunk\n" },
		{ "ModuleRelativePath", "MapGenerator.h" },
		{ "ToolTip", "The size of each chunk" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMapGenerator_Statics::NewProp_PerlinScale = { "PerlinScale", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMapGenerator, PerlinScale), METADATA_PARAMS(Z_Construct_UClass_AMapGenerator_Statics::NewProp_PerlinScale_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMapGenerator_Statics::NewProp_PerlinScale_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMapGenerator_Statics::NewProp_ChunkGridSize_MetaData[] = {
		{ "Category", "MapGenerator" },
		{ "Comment", "//The height of each chunk\n" },
		{ "ModuleRelativePath", "MapGenerator.h" },
		{ "ToolTip", "The height of each chunk" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMapGenerator_Statics::NewProp_ChunkGridSize = { "ChunkGridSize", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMapGenerator, ChunkGridSize), METADATA_PARAMS(Z_Construct_UClass_AMapGenerator_Statics::NewProp_ChunkGridSize_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMapGenerator_Statics::NewProp_ChunkGridSize_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMapGenerator_Statics::NewProp_ChunkHeight_MetaData[] = {
		{ "Category", "MapGenerator" },
		{ "Comment", "//The width of each chunk\n" },
		{ "ModuleRelativePath", "MapGenerator.h" },
		{ "ToolTip", "The width of each chunk" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AMapGenerator_Statics::NewProp_ChunkHeight = { "ChunkHeight", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMapGenerator, ChunkHeight), METADATA_PARAMS(Z_Construct_UClass_AMapGenerator_Statics::NewProp_ChunkHeight_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMapGenerator_Statics::NewProp_ChunkHeight_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMapGenerator_Statics::NewProp_ChunkWidth_MetaData[] = {
		{ "Category", "MapGenerator" },
		{ "Comment", "//These variables control the parameters of the procedurally generated maps\n" },
		{ "ModuleRelativePath", "MapGenerator.h" },
		{ "ToolTip", "These variables control the parameters of the procedurally generated maps" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AMapGenerator_Statics::NewProp_ChunkWidth = { "ChunkWidth", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMapGenerator, ChunkWidth), METADATA_PARAMS(Z_Construct_UClass_AMapGenerator_Statics::NewProp_ChunkWidth_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMapGenerator_Statics::NewProp_ChunkWidth_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMapGenerator_Statics::NewProp_ChunkRadius_MetaData[] = {
		{ "Category", "MapGenerator" },
		{ "ModuleRelativePath", "MapGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AMapGenerator_Statics::NewProp_ChunkRadius = { "ChunkRadius", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMapGenerator, ChunkRadius), METADATA_PARAMS(Z_Construct_UClass_AMapGenerator_Statics::NewProp_ChunkRadius_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMapGenerator_Statics::NewProp_ChunkRadius_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMapGenerator_Statics::NewProp_PGMaterial_MetaData[] = {
		{ "Category", "MapGenerator" },
		{ "ModuleRelativePath", "MapGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMapGenerator_Statics::NewProp_PGMaterial = { "PGMaterial", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMapGenerator, PGMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMapGenerator_Statics::NewProp_PGMaterial_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMapGenerator_Statics::NewProp_PGMaterial_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMapGenerator_Statics::NewProp_Sculptor_MetaData[] = {
		{ "Category", "MapGenerator" },
		{ "ModuleRelativePath", "MapGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AMapGenerator_Statics::NewProp_Sculptor = { "Sculptor", nullptr, (EPropertyFlags)0x0014000000000001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMapGenerator, Sculptor), Z_Construct_UClass_AProcMeshSculpt_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AMapGenerator_Statics::NewProp_Sculptor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMapGenerator_Statics::NewProp_Sculptor_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMapGenerator_Statics::NewProp_SmallDustEmitter_MetaData[] = {
		{ "Category", "MapGenerator" },
		{ "ModuleRelativePath", "MapGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AMapGenerator_Statics::NewProp_SmallDustEmitter = { "SmallDustEmitter", nullptr, (EPropertyFlags)0x0014000000000001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMapGenerator, SmallDustEmitter), Z_Construct_UClass_ADustClouds_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AMapGenerator_Statics::NewProp_SmallDustEmitter_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMapGenerator_Statics::NewProp_SmallDustEmitter_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMapGenerator_Statics::NewProp_BigDustEmitter_MetaData[] = {
		{ "Category", "MapGenerator" },
		{ "ModuleRelativePath", "MapGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AMapGenerator_Statics::NewProp_BigDustEmitter = { "BigDustEmitter", nullptr, (EPropertyFlags)0x0014000000000001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMapGenerator, BigDustEmitter), Z_Construct_UClass_ADustClouds_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AMapGenerator_Statics::NewProp_BigDustEmitter_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMapGenerator_Statics::NewProp_BigDustEmitter_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMapGenerator_Statics::NewProp_PlayerToSpawn_MetaData[] = {
		{ "Category", "MapGenerator" },
		{ "ModuleRelativePath", "MapGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AMapGenerator_Statics::NewProp_PlayerToSpawn = { "PlayerToSpawn", nullptr, (EPropertyFlags)0x0014000000000001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMapGenerator, PlayerToSpawn), Z_Construct_UClass_APlayerCharacter_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AMapGenerator_Statics::NewProp_PlayerToSpawn_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMapGenerator_Statics::NewProp_PlayerToSpawn_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMapGenerator_Statics::NewProp_PGMap_MetaData[] = {
		{ "Category", "MapGenerator" },
		{ "ModuleRelativePath", "MapGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AMapGenerator_Statics::NewProp_PGMap = { "PGMap", nullptr, (EPropertyFlags)0x0014000000000001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMapGenerator, PGMap), Z_Construct_UClass_AProcedurallyGeneratedMap_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AMapGenerator_Statics::NewProp_PGMap_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMapGenerator_Statics::NewProp_PGMap_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMapGenerator_Statics::NewProp_PerlinOffset_MetaData[] = {
		{ "Category", "MapGenerator" },
		{ "ModuleRelativePath", "MapGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMapGenerator_Statics::NewProp_PerlinOffset = { "PerlinOffset", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMapGenerator, PerlinOffset), METADATA_PARAMS(Z_Construct_UClass_AMapGenerator_Statics::NewProp_PerlinOffset_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMapGenerator_Statics::NewProp_PerlinOffset_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMapGenerator_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMapGenerator_Statics::NewProp_bRegenerateMap,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMapGenerator_Statics::NewProp_PerlinRoughness,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMapGenerator_Statics::NewProp_PerlinScale,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMapGenerator_Statics::NewProp_ChunkGridSize,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMapGenerator_Statics::NewProp_ChunkHeight,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMapGenerator_Statics::NewProp_ChunkWidth,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMapGenerator_Statics::NewProp_ChunkRadius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMapGenerator_Statics::NewProp_PGMaterial,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMapGenerator_Statics::NewProp_Sculptor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMapGenerator_Statics::NewProp_SmallDustEmitter,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMapGenerator_Statics::NewProp_BigDustEmitter,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMapGenerator_Statics::NewProp_PlayerToSpawn,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMapGenerator_Statics::NewProp_PGMap,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMapGenerator_Statics::NewProp_PerlinOffset,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMapGenerator_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMapGenerator>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMapGenerator_Statics::ClassParams = {
		&AMapGenerator::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AMapGenerator_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AMapGenerator_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AMapGenerator_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMapGenerator_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMapGenerator()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMapGenerator_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMapGenerator, 399673471);
	template<> TWISTEDGROUNDS_API UClass* StaticClass<AMapGenerator>()
	{
		return AMapGenerator::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMapGenerator(Z_Construct_UClass_AMapGenerator, &AMapGenerator::StaticClass, TEXT("/Script/TwistedGrounds"), TEXT("AMapGenerator"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMapGenerator);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
