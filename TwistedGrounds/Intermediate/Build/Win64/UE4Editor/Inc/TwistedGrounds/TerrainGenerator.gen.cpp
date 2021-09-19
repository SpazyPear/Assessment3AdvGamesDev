// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TwistedGrounds/TerrainGenerator.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTerrainGenerator() {}
// Cross Module References
	TWISTEDGROUNDS_API UClass* Z_Construct_UClass_ATerrainGenerator_NoRegister();
	TWISTEDGROUNDS_API UClass* Z_Construct_UClass_ATerrainGenerator();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_TwistedGrounds();
	TWISTEDGROUNDS_API UFunction* Z_Construct_UFunction_ATerrainGenerator_GetComponentXY();
	TWISTEDGROUNDS_API UFunction* Z_Construct_UFunction_ATerrainGenerator_GetQuadSize();
	TWISTEDGROUNDS_API UFunction* Z_Construct_UFunction_ATerrainGenerator_GetSectionXY();
	TWISTEDGROUNDS_API UScriptStruct* Z_Construct_UScriptStruct_FVertexData();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCurveFloat_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	TWISTEDGROUNDS_API UClass* Z_Construct_UClass_ATerrainSection_NoRegister();
	TWISTEDGROUNDS_API UEnum* Z_Construct_UEnum_TwistedGrounds_ETerrainGeneration();
// End Cross Module References
	void ATerrainGenerator::StaticRegisterNativesATerrainGenerator()
	{
		UClass* Class = ATerrainGenerator::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetComponentXY", &ATerrainGenerator::execGetComponentXY },
			{ "GetQuadSize", &ATerrainGenerator::execGetQuadSize },
			{ "GetSectionXY", &ATerrainGenerator::execGetSectionXY },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ATerrainGenerator_GetComponentXY_Statics
	{
		struct TerrainGenerator_eventGetComponentXY_Parms
		{
			int32 ReturnValue;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ATerrainGenerator_GetComponentXY_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TerrainGenerator_eventGetComponentXY_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATerrainGenerator_GetComponentXY_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATerrainGenerator_GetComponentXY_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATerrainGenerator_GetComponentXY_Statics::Function_MetaDataParams[] = {
		{ "Category", "TerrainGeneration" },
		{ "ModuleRelativePath", "TerrainGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ATerrainGenerator_GetComponentXY_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATerrainGenerator, nullptr, "GetComponentXY", nullptr, nullptr, sizeof(TerrainGenerator_eventGetComponentXY_Parms), Z_Construct_UFunction_ATerrainGenerator_GetComponentXY_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATerrainGenerator_GetComponentXY_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATerrainGenerator_GetComponentXY_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATerrainGenerator_GetComponentXY_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATerrainGenerator_GetComponentXY()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ATerrainGenerator_GetComponentXY_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATerrainGenerator_GetQuadSize_Statics
	{
		struct TerrainGenerator_eventGetQuadSize_Parms
		{
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ATerrainGenerator_GetQuadSize_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TerrainGenerator_eventGetQuadSize_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATerrainGenerator_GetQuadSize_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATerrainGenerator_GetQuadSize_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATerrainGenerator_GetQuadSize_Statics::Function_MetaDataParams[] = {
		{ "Category", "TerrainGeneration" },
		{ "ModuleRelativePath", "TerrainGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ATerrainGenerator_GetQuadSize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATerrainGenerator, nullptr, "GetQuadSize", nullptr, nullptr, sizeof(TerrainGenerator_eventGetQuadSize_Parms), Z_Construct_UFunction_ATerrainGenerator_GetQuadSize_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATerrainGenerator_GetQuadSize_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATerrainGenerator_GetQuadSize_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATerrainGenerator_GetQuadSize_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATerrainGenerator_GetQuadSize()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ATerrainGenerator_GetQuadSize_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATerrainGenerator_GetSectionXY_Statics
	{
		struct TerrainGenerator_eventGetSectionXY_Parms
		{
			int32 ReturnValue;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ATerrainGenerator_GetSectionXY_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TerrainGenerator_eventGetSectionXY_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATerrainGenerator_GetSectionXY_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATerrainGenerator_GetSectionXY_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATerrainGenerator_GetSectionXY_Statics::Function_MetaDataParams[] = {
		{ "Category", "TerrainGeneration" },
		{ "Comment", "// Getters \n" },
		{ "ModuleRelativePath", "TerrainGenerator.h" },
		{ "ToolTip", "Getters" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ATerrainGenerator_GetSectionXY_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATerrainGenerator, nullptr, "GetSectionXY", nullptr, nullptr, sizeof(TerrainGenerator_eventGetSectionXY_Parms), Z_Construct_UFunction_ATerrainGenerator_GetSectionXY_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATerrainGenerator_GetSectionXY_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATerrainGenerator_GetSectionXY_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATerrainGenerator_GetSectionXY_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATerrainGenerator_GetSectionXY()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ATerrainGenerator_GetSectionXY_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ATerrainGenerator_NoRegister()
	{
		return ATerrainGenerator::StaticClass();
	}
	struct Z_Construct_UClass_ATerrainGenerator_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GlobalVertexData_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_GlobalVertexData;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_GlobalVertexData_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SceneRoot_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SceneRoot;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bUseOctave4_MetaData[];
#endif
		static void NewProp_bUseOctave4_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bUseOctave4;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bUseOctave3_MetaData[];
#endif
		static void NewProp_bUseOctave3_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bUseOctave3;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bUseOctave2_MetaData[];
#endif
		static void NewProp_bUseOctave2_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bUseOctave2;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Scale4_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Scale4;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Scale3_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Scale3;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Scale2_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Scale2;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Scale1_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Scale1;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Seed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Seed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NoiseMultiplier4_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_NoiseMultiplier4;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NoiseMultiplier3_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_NoiseMultiplier3;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NoiseMultiplier2_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_NoiseMultiplier2;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NoiseMultiplier1_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_NoiseMultiplier1;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VisibilityLOD4_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_VisibilityLOD4;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VisibilityLOD3_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_VisibilityLOD3;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VisibilityLOD2_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_VisibilityLOD2;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VisibilityLOD1_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_VisibilityLOD1;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VisibilityLOD0_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_VisibilityLOD0;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FactorLOD4_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_FactorLOD4;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FactorLOD3_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_FactorLOD3;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FactorLOD2_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_FactorLOD2;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FactorLOD1_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_FactorLOD1;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Curve_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Curve;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxZValueOffsetPerUpdate_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_MaxZValueOffsetPerUpdate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FillVertexDataTimerDelay_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_FillVertexDataTimerDelay;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CreateSectionTimerDelay_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_CreateSectionTimerDelay;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bUseTimerforGeneration_MetaData[];
#endif
		static void NewProp_bUseTimerforGeneration_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bUseTimerforGeneration;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LineTraceLength_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_LineTraceLength;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LineTraceHeightOffset_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_LineTraceHeightOffset;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ClassToSpawnAsSection_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_ClassToSpawnAsSection;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TerrainZ_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_TerrainZ;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_TerrainZ_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_QuadSize_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_QuadSize;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SectionXY_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_SectionXY;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ComponentXY_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ComponentXY;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATerrainGenerator_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_TwistedGrounds,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ATerrainGenerator_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ATerrainGenerator_GetComponentXY, "GetComponentXY" }, // 314396972
		{ &Z_Construct_UFunction_ATerrainGenerator_GetQuadSize, "GetQuadSize" }, // 4014267395
		{ &Z_Construct_UFunction_ATerrainGenerator_GetSectionXY, "GetSectionXY" }, // 4079621536
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainGenerator_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "TerrainGenerator.h" },
		{ "ModuleRelativePath", "TerrainGenerator.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_GlobalVertexData_MetaData[] = {
		{ "ModuleRelativePath", "TerrainGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_GlobalVertexData = { "GlobalVertexData", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATerrainGenerator, GlobalVertexData), METADATA_PARAMS(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_GlobalVertexData_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_GlobalVertexData_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_GlobalVertexData_Inner = { "GlobalVertexData", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVertexData, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_SceneRoot_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "TerrainGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_SceneRoot = { "SceneRoot", nullptr, (EPropertyFlags)0x00400000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATerrainGenerator, SceneRoot), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_SceneRoot_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_SceneRoot_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_bUseOctave4_MetaData[] = {
		{ "Category", "TerrainGeneration|Noise" },
		{ "ModuleRelativePath", "TerrainGenerator.h" },
	};
#endif
	void Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_bUseOctave4_SetBit(void* Obj)
	{
		((ATerrainGenerator*)Obj)->bUseOctave4 = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_bUseOctave4 = { "bUseOctave4", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ATerrainGenerator), &Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_bUseOctave4_SetBit, METADATA_PARAMS(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_bUseOctave4_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_bUseOctave4_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_bUseOctave3_MetaData[] = {
		{ "Category", "TerrainGeneration|Noise" },
		{ "ModuleRelativePath", "TerrainGenerator.h" },
	};
#endif
	void Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_bUseOctave3_SetBit(void* Obj)
	{
		((ATerrainGenerator*)Obj)->bUseOctave3 = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_bUseOctave3 = { "bUseOctave3", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ATerrainGenerator), &Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_bUseOctave3_SetBit, METADATA_PARAMS(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_bUseOctave3_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_bUseOctave3_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_bUseOctave2_MetaData[] = {
		{ "Category", "TerrainGeneration|Noise" },
		{ "ModuleRelativePath", "TerrainGenerator.h" },
	};
#endif
	void Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_bUseOctave2_SetBit(void* Obj)
	{
		((ATerrainGenerator*)Obj)->bUseOctave2 = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_bUseOctave2 = { "bUseOctave2", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ATerrainGenerator), &Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_bUseOctave2_SetBit, METADATA_PARAMS(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_bUseOctave2_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_bUseOctave2_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_Scale4_MetaData[] = {
		{ "Category", "TerrainGeneration|Noise" },
		{ "ModuleRelativePath", "TerrainGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_Scale4 = { "Scale4", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATerrainGenerator, Scale4), METADATA_PARAMS(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_Scale4_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_Scale4_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_Scale3_MetaData[] = {
		{ "Category", "TerrainGeneration|Noise" },
		{ "ModuleRelativePath", "TerrainGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_Scale3 = { "Scale3", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATerrainGenerator, Scale3), METADATA_PARAMS(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_Scale3_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_Scale3_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_Scale2_MetaData[] = {
		{ "Category", "TerrainGeneration|Noise" },
		{ "ModuleRelativePath", "TerrainGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_Scale2 = { "Scale2", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATerrainGenerator, Scale2), METADATA_PARAMS(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_Scale2_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_Scale2_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_Scale1_MetaData[] = {
		{ "Category", "TerrainGeneration|Noise" },
		{ "ModuleRelativePath", "TerrainGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_Scale1 = { "Scale1", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATerrainGenerator, Scale1), METADATA_PARAMS(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_Scale1_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_Scale1_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_Seed_MetaData[] = {
		{ "Category", "TerrainGeneration|Noise" },
		{ "ModuleRelativePath", "TerrainGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_Seed = { "Seed", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATerrainGenerator, Seed), METADATA_PARAMS(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_Seed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_Seed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_NoiseMultiplier4_MetaData[] = {
		{ "Category", "TerrainGeneration|Noise" },
		{ "ModuleRelativePath", "TerrainGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_NoiseMultiplier4 = { "NoiseMultiplier4", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATerrainGenerator, NoiseMultiplier4), METADATA_PARAMS(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_NoiseMultiplier4_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_NoiseMultiplier4_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_NoiseMultiplier3_MetaData[] = {
		{ "Category", "TerrainGeneration|Noise" },
		{ "ModuleRelativePath", "TerrainGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_NoiseMultiplier3 = { "NoiseMultiplier3", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATerrainGenerator, NoiseMultiplier3), METADATA_PARAMS(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_NoiseMultiplier3_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_NoiseMultiplier3_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_NoiseMultiplier2_MetaData[] = {
		{ "Category", "TerrainGeneration|Noise" },
		{ "ModuleRelativePath", "TerrainGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_NoiseMultiplier2 = { "NoiseMultiplier2", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATerrainGenerator, NoiseMultiplier2), METADATA_PARAMS(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_NoiseMultiplier2_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_NoiseMultiplier2_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_NoiseMultiplier1_MetaData[] = {
		{ "Category", "TerrainGeneration|Noise" },
		{ "ModuleRelativePath", "TerrainGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_NoiseMultiplier1 = { "NoiseMultiplier1", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATerrainGenerator, NoiseMultiplier1), METADATA_PARAMS(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_NoiseMultiplier1_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_NoiseMultiplier1_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_VisibilityLOD4_MetaData[] = {
		{ "Category", "TerrainGeneration|LOD" },
		{ "ModuleRelativePath", "TerrainGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_VisibilityLOD4 = { "VisibilityLOD4", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATerrainGenerator, VisibilityLOD4), METADATA_PARAMS(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_VisibilityLOD4_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_VisibilityLOD4_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_VisibilityLOD3_MetaData[] = {
		{ "Category", "TerrainGeneration|LOD" },
		{ "ModuleRelativePath", "TerrainGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_VisibilityLOD3 = { "VisibilityLOD3", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATerrainGenerator, VisibilityLOD3), METADATA_PARAMS(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_VisibilityLOD3_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_VisibilityLOD3_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_VisibilityLOD2_MetaData[] = {
		{ "Category", "TerrainGeneration|LOD" },
		{ "ModuleRelativePath", "TerrainGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_VisibilityLOD2 = { "VisibilityLOD2", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATerrainGenerator, VisibilityLOD2), METADATA_PARAMS(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_VisibilityLOD2_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_VisibilityLOD2_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_VisibilityLOD1_MetaData[] = {
		{ "Category", "TerrainGeneration|LOD" },
		{ "ModuleRelativePath", "TerrainGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_VisibilityLOD1 = { "VisibilityLOD1", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATerrainGenerator, VisibilityLOD1), METADATA_PARAMS(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_VisibilityLOD1_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_VisibilityLOD1_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_VisibilityLOD0_MetaData[] = {
		{ "Category", "TerrainGeneration|LOD" },
		{ "ModuleRelativePath", "TerrainGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_VisibilityLOD0 = { "VisibilityLOD0", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATerrainGenerator, VisibilityLOD0), METADATA_PARAMS(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_VisibilityLOD0_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_VisibilityLOD0_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_FactorLOD4_MetaData[] = {
		{ "Category", "TerrainGeneration|LOD" },
		{ "ModuleRelativePath", "TerrainGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_FactorLOD4 = { "FactorLOD4", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATerrainGenerator, FactorLOD4), METADATA_PARAMS(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_FactorLOD4_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_FactorLOD4_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_FactorLOD3_MetaData[] = {
		{ "Category", "TerrainGeneration|LOD" },
		{ "ModuleRelativePath", "TerrainGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_FactorLOD3 = { "FactorLOD3", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATerrainGenerator, FactorLOD3), METADATA_PARAMS(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_FactorLOD3_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_FactorLOD3_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_FactorLOD2_MetaData[] = {
		{ "Category", "TerrainGeneration|LOD" },
		{ "ModuleRelativePath", "TerrainGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_FactorLOD2 = { "FactorLOD2", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATerrainGenerator, FactorLOD2), METADATA_PARAMS(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_FactorLOD2_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_FactorLOD2_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_FactorLOD1_MetaData[] = {
		{ "Category", "TerrainGeneration|LOD" },
		{ "ModuleRelativePath", "TerrainGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_FactorLOD1 = { "FactorLOD1", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATerrainGenerator, FactorLOD1), METADATA_PARAMS(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_FactorLOD1_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_FactorLOD1_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_Curve_MetaData[] = {
		{ "Category", "TerrainGeneration|Sculpting" },
		{ "Comment", "// Define the falloff that is used when sculpting\n" },
		{ "ModuleRelativePath", "TerrainGenerator.h" },
		{ "ToolTip", "Define the falloff that is used when sculpting" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_Curve = { "Curve", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATerrainGenerator, Curve), Z_Construct_UClass_UCurveFloat_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_Curve_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_Curve_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_MaxZValueOffsetPerUpdate_MetaData[] = {
		{ "Category", "TerrainGeneration|Sculpting" },
		{ "Comment", "// Max difference in Z height when using \"Raise\" or \"Lower\" \n" },
		{ "ModuleRelativePath", "TerrainGenerator.h" },
		{ "ToolTip", "Max difference in Z height when using \"Raise\" or \"Lower\"" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_MaxZValueOffsetPerUpdate = { "MaxZValueOffsetPerUpdate", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATerrainGenerator, MaxZValueOffsetPerUpdate), METADATA_PARAMS(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_MaxZValueOffsetPerUpdate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_MaxZValueOffsetPerUpdate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_FillVertexDataTimerDelay_MetaData[] = {
		{ "Category", "TerrainGeneration|Timed" },
		{ "Comment", "// Delays X axis iteration when filling vertex data\n" },
		{ "ModuleRelativePath", "TerrainGenerator.h" },
		{ "ToolTip", "Delays X axis iteration when filling vertex data" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_FillVertexDataTimerDelay = { "FillVertexDataTimerDelay", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATerrainGenerator, FillVertexDataTimerDelay), METADATA_PARAMS(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_FillVertexDataTimerDelay_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_FillVertexDataTimerDelay_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_CreateSectionTimerDelay_MetaData[] = {
		{ "Category", "TerrainGeneration|Timed" },
		{ "Comment", "// Delays the spawning of sections to prevent freezing\n" },
		{ "ModuleRelativePath", "TerrainGenerator.h" },
		{ "ToolTip", "Delays the spawning of sections to prevent freezing" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_CreateSectionTimerDelay = { "CreateSectionTimerDelay", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATerrainGenerator, CreateSectionTimerDelay), METADATA_PARAMS(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_CreateSectionTimerDelay_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_CreateSectionTimerDelay_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_bUseTimerforGeneration_MetaData[] = {
		{ "Category", "TerrainGeneration|Timed" },
		{ "Comment", "// using a timer prevents the gamethread from freezing when generating terrain\n" },
		{ "ModuleRelativePath", "TerrainGenerator.h" },
		{ "ToolTip", "using a timer prevents the gamethread from freezing when generating terrain" },
	};
#endif
	void Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_bUseTimerforGeneration_SetBit(void* Obj)
	{
		((ATerrainGenerator*)Obj)->bUseTimerforGeneration = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_bUseTimerforGeneration = { "bUseTimerforGeneration", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ATerrainGenerator), &Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_bUseTimerforGeneration_SetBit, METADATA_PARAMS(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_bUseTimerforGeneration_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_bUseTimerforGeneration_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_LineTraceLength_MetaData[] = {
		{ "Category", "TerrainGeneration|LineTrace" },
		{ "Comment", "// How far trace reaches down from Generator Z to copy\n" },
		{ "ModuleRelativePath", "TerrainGenerator.h" },
		{ "ToolTip", "How far trace reaches down from Generator Z to copy" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_LineTraceLength = { "LineTraceLength", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATerrainGenerator, LineTraceLength), METADATA_PARAMS(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_LineTraceLength_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_LineTraceLength_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_LineTraceHeightOffset_MetaData[] = {
		{ "Category", "TerrainGeneration|LineTrace" },
		{ "Comment", "// Z Offset from copied height \n" },
		{ "ModuleRelativePath", "TerrainGenerator.h" },
		{ "ToolTip", "Z Offset from copied height" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_LineTraceHeightOffset = { "LineTraceHeightOffset", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATerrainGenerator, LineTraceHeightOffset), METADATA_PARAMS(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_LineTraceHeightOffset_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_LineTraceHeightOffset_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_ClassToSpawnAsSection_MetaData[] = {
		{ "Category", "TerrainGeneration|Setup" },
		{ "Comment", "// Define Class that will be spawned as section. \n" },
		{ "ModuleRelativePath", "TerrainGenerator.h" },
		{ "ToolTip", "Define Class that will be spawned as section." },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_ClassToSpawnAsSection = { "ClassToSpawnAsSection", nullptr, (EPropertyFlags)0x0014000000010001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATerrainGenerator, ClassToSpawnAsSection), Z_Construct_UClass_ATerrainSection_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_ClassToSpawnAsSection_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_ClassToSpawnAsSection_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_TerrainZ_MetaData[] = {
		{ "Category", "TerrainGeneration" },
		{ "ModuleRelativePath", "TerrainGenerator.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_TerrainZ = { "TerrainZ", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATerrainGenerator, TerrainZ), Z_Construct_UEnum_TwistedGrounds_ETerrainGeneration, METADATA_PARAMS(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_TerrainZ_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_TerrainZ_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_TerrainZ_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_QuadSize_MetaData[] = {
		{ "Category", "TerrainGeneration" },
		{ "Comment", "// Distance from one Vertex to another in cm\n" },
		{ "ModuleRelativePath", "TerrainGenerator.h" },
		{ "ToolTip", "Distance from one Vertex to another in cm" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_QuadSize = { "QuadSize", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATerrainGenerator, QuadSize), METADATA_PARAMS(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_QuadSize_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_QuadSize_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_SectionXY_MetaData[] = {
		{ "Category", "TerrainGeneration" },
		{ "Comment", "// Number of Vertices on each side of section\n" },
		{ "ModuleRelativePath", "TerrainGenerator.h" },
		{ "ToolTip", "Number of Vertices on each side of section" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_SectionXY = { "SectionXY", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATerrainGenerator, SectionXY), METADATA_PARAMS(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_SectionXY_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_SectionXY_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_ComponentXY_MetaData[] = {
		{ "Category", "TerrainGeneration" },
		{ "Comment", "// Number of Components/Sections on each side \n" },
		{ "ModuleRelativePath", "TerrainGenerator.h" },
		{ "ToolTip", "Number of Components/Sections on each side" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_ComponentXY = { "ComponentXY", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATerrainGenerator, ComponentXY), METADATA_PARAMS(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_ComponentXY_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_ComponentXY_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATerrainGenerator_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_GlobalVertexData,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_GlobalVertexData_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_SceneRoot,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_bUseOctave4,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_bUseOctave3,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_bUseOctave2,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_Scale4,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_Scale3,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_Scale2,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_Scale1,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_Seed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_NoiseMultiplier4,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_NoiseMultiplier3,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_NoiseMultiplier2,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_NoiseMultiplier1,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_VisibilityLOD4,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_VisibilityLOD3,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_VisibilityLOD2,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_VisibilityLOD1,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_VisibilityLOD0,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_FactorLOD4,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_FactorLOD3,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_FactorLOD2,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_FactorLOD1,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_Curve,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_MaxZValueOffsetPerUpdate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_FillVertexDataTimerDelay,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_CreateSectionTimerDelay,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_bUseTimerforGeneration,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_LineTraceLength,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_LineTraceHeightOffset,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_ClassToSpawnAsSection,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_TerrainZ,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_TerrainZ_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_QuadSize,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_SectionXY,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainGenerator_Statics::NewProp_ComponentXY,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATerrainGenerator_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATerrainGenerator>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ATerrainGenerator_Statics::ClassParams = {
		&ATerrainGenerator::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ATerrainGenerator_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ATerrainGenerator_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainGenerator_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ATerrainGenerator()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ATerrainGenerator_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ATerrainGenerator, 541103775);
	template<> TWISTEDGROUNDS_API UClass* StaticClass<ATerrainGenerator>()
	{
		return ATerrainGenerator::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ATerrainGenerator(Z_Construct_UClass_ATerrainGenerator, &ATerrainGenerator::StaticClass, TEXT("/Script/TwistedGrounds"), TEXT("ATerrainGenerator"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATerrainGenerator);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
