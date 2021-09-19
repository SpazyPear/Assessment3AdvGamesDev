// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TwistedGrounds/TerrainSection.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTerrainSection() {}
// Cross Module References
	TWISTEDGROUNDS_API UClass* Z_Construct_UClass_ATerrainSection_NoRegister();
	TWISTEDGROUNDS_API UClass* Z_Construct_UClass_ATerrainSection();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_TwistedGrounds();
	TWISTEDGROUNDS_API UFunction* Z_Construct_UFunction_ATerrainSection_RequestSculpting();
	TWISTEDGROUNDS_API UScriptStruct* Z_Construct_UScriptStruct_FSculptInputInfo();
	TWISTEDGROUNDS_API UScriptStruct* Z_Construct_UScriptStruct_FSculptSettings();
	TWISTEDGROUNDS_API UClass* Z_Construct_UClass_ATerrainGenerator_NoRegister();
	PROCEDURALMESHCOMPONENT_API UClass* Z_Construct_UClass_UProceduralMeshComponent_NoRegister();
	RUNTIMEMESHCOMPONENT_API UClass* Z_Construct_UClass_URuntimeMeshComponentStatic_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
// End Cross Module References
	void ATerrainSection::StaticRegisterNativesATerrainSection()
	{
		UClass* Class = ATerrainSection::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "RequestSculpting", &ATerrainSection::execRequestSculpting },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ATerrainSection_RequestSculpting_Statics
	{
		struct TerrainSection_eventRequestSculpting_Parms
		{
			FSculptSettings Settings;
			FSculptInputInfo InputInfo;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InputInfo_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_InputInfo;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Settings_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Settings;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATerrainSection_RequestSculpting_Statics::NewProp_InputInfo_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATerrainSection_RequestSculpting_Statics::NewProp_InputInfo = { "InputInfo", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TerrainSection_eventRequestSculpting_Parms, InputInfo), Z_Construct_UScriptStruct_FSculptInputInfo, METADATA_PARAMS(Z_Construct_UFunction_ATerrainSection_RequestSculpting_Statics::NewProp_InputInfo_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATerrainSection_RequestSculpting_Statics::NewProp_InputInfo_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATerrainSection_RequestSculpting_Statics::NewProp_Settings_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATerrainSection_RequestSculpting_Statics::NewProp_Settings = { "Settings", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TerrainSection_eventRequestSculpting_Parms, Settings), Z_Construct_UScriptStruct_FSculptSettings, METADATA_PARAMS(Z_Construct_UFunction_ATerrainSection_RequestSculpting_Statics::NewProp_Settings_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ATerrainSection_RequestSculpting_Statics::NewProp_Settings_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATerrainSection_RequestSculpting_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATerrainSection_RequestSculpting_Statics::NewProp_InputInfo,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATerrainSection_RequestSculpting_Statics::NewProp_Settings,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATerrainSection_RequestSculpting_Statics::Function_MetaDataParams[] = {
		{ "Category", "ProceduralMeshGeneration" },
		{ "ModuleRelativePath", "TerrainSection.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ATerrainSection_RequestSculpting_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATerrainSection, nullptr, "RequestSculpting", nullptr, nullptr, sizeof(TerrainSection_eventRequestSculpting_Parms), Z_Construct_UFunction_ATerrainSection_RequestSculpting_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATerrainSection_RequestSculpting_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATerrainSection_RequestSculpting_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATerrainSection_RequestSculpting_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATerrainSection_RequestSculpting()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ATerrainSection_RequestSculpting_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ATerrainSection_NoRegister()
	{
		return ATerrainSection::StaticClass();
	}
	struct Z_Construct_UClass_ATerrainSection_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OwningTerrain_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OwningTerrain;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ProceduralMeshComponentLOD4_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ProceduralMeshComponentLOD4;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RuntimeMeshComponentLOD4_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_RuntimeMeshComponentLOD4;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ProceduralMeshComponentLOD3_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ProceduralMeshComponentLOD3;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RuntimeMeshComponentLOD3_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_RuntimeMeshComponentLOD3;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ProceduralMeshComponentLOD2_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ProceduralMeshComponentLOD2;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RuntimeMeshComponentLOD2_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_RuntimeMeshComponentLOD2;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ProceduralMeshComponentLOD1_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ProceduralMeshComponentLOD1;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RuntimeMeshComponentLOD1_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_RuntimeMeshComponentLOD1;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ProceduralMeshComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ProceduralMeshComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RuntimeMeshComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_RuntimeMeshComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SceneRoot_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SceneRoot;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bUseRuntimeMeshComponent_MetaData[];
#endif
		static void NewProp_bUseRuntimeMeshComponent_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bUseRuntimeMeshComponent;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATerrainSection_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_TwistedGrounds,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ATerrainSection_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ATerrainSection_RequestSculpting, "RequestSculpting" }, // 20602250
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainSection_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "TerrainSection.h" },
		{ "ModuleRelativePath", "TerrainSection.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainSection_Statics::NewProp_OwningTerrain_MetaData[] = {
		{ "Category", "Sculpting" },
		{ "ModuleRelativePath", "TerrainSection.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATerrainSection_Statics::NewProp_OwningTerrain = { "OwningTerrain", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATerrainSection, OwningTerrain), Z_Construct_UClass_ATerrainGenerator_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATerrainSection_Statics::NewProp_OwningTerrain_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainSection_Statics::NewProp_OwningTerrain_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainSection_Statics::NewProp_ProceduralMeshComponentLOD4_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "TerrainSection.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATerrainSection_Statics::NewProp_ProceduralMeshComponentLOD4 = { "ProceduralMeshComponentLOD4", nullptr, (EPropertyFlags)0x00400000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATerrainSection, ProceduralMeshComponentLOD4), Z_Construct_UClass_UProceduralMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATerrainSection_Statics::NewProp_ProceduralMeshComponentLOD4_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainSection_Statics::NewProp_ProceduralMeshComponentLOD4_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainSection_Statics::NewProp_RuntimeMeshComponentLOD4_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "TerrainSection.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATerrainSection_Statics::NewProp_RuntimeMeshComponentLOD4 = { "RuntimeMeshComponentLOD4", nullptr, (EPropertyFlags)0x00400000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATerrainSection, RuntimeMeshComponentLOD4), Z_Construct_UClass_URuntimeMeshComponentStatic_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATerrainSection_Statics::NewProp_RuntimeMeshComponentLOD4_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainSection_Statics::NewProp_RuntimeMeshComponentLOD4_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainSection_Statics::NewProp_ProceduralMeshComponentLOD3_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "TerrainSection.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATerrainSection_Statics::NewProp_ProceduralMeshComponentLOD3 = { "ProceduralMeshComponentLOD3", nullptr, (EPropertyFlags)0x00400000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATerrainSection, ProceduralMeshComponentLOD3), Z_Construct_UClass_UProceduralMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATerrainSection_Statics::NewProp_ProceduralMeshComponentLOD3_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainSection_Statics::NewProp_ProceduralMeshComponentLOD3_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainSection_Statics::NewProp_RuntimeMeshComponentLOD3_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "TerrainSection.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATerrainSection_Statics::NewProp_RuntimeMeshComponentLOD3 = { "RuntimeMeshComponentLOD3", nullptr, (EPropertyFlags)0x00400000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATerrainSection, RuntimeMeshComponentLOD3), Z_Construct_UClass_URuntimeMeshComponentStatic_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATerrainSection_Statics::NewProp_RuntimeMeshComponentLOD3_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainSection_Statics::NewProp_RuntimeMeshComponentLOD3_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainSection_Statics::NewProp_ProceduralMeshComponentLOD2_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "TerrainSection.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATerrainSection_Statics::NewProp_ProceduralMeshComponentLOD2 = { "ProceduralMeshComponentLOD2", nullptr, (EPropertyFlags)0x00400000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATerrainSection, ProceduralMeshComponentLOD2), Z_Construct_UClass_UProceduralMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATerrainSection_Statics::NewProp_ProceduralMeshComponentLOD2_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainSection_Statics::NewProp_ProceduralMeshComponentLOD2_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainSection_Statics::NewProp_RuntimeMeshComponentLOD2_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "TerrainSection.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATerrainSection_Statics::NewProp_RuntimeMeshComponentLOD2 = { "RuntimeMeshComponentLOD2", nullptr, (EPropertyFlags)0x00400000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATerrainSection, RuntimeMeshComponentLOD2), Z_Construct_UClass_URuntimeMeshComponentStatic_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATerrainSection_Statics::NewProp_RuntimeMeshComponentLOD2_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainSection_Statics::NewProp_RuntimeMeshComponentLOD2_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainSection_Statics::NewProp_ProceduralMeshComponentLOD1_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "TerrainSection.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATerrainSection_Statics::NewProp_ProceduralMeshComponentLOD1 = { "ProceduralMeshComponentLOD1", nullptr, (EPropertyFlags)0x00400000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATerrainSection, ProceduralMeshComponentLOD1), Z_Construct_UClass_UProceduralMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATerrainSection_Statics::NewProp_ProceduralMeshComponentLOD1_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainSection_Statics::NewProp_ProceduralMeshComponentLOD1_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainSection_Statics::NewProp_RuntimeMeshComponentLOD1_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "TerrainSection.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATerrainSection_Statics::NewProp_RuntimeMeshComponentLOD1 = { "RuntimeMeshComponentLOD1", nullptr, (EPropertyFlags)0x00400000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATerrainSection, RuntimeMeshComponentLOD1), Z_Construct_UClass_URuntimeMeshComponentStatic_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATerrainSection_Statics::NewProp_RuntimeMeshComponentLOD1_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainSection_Statics::NewProp_RuntimeMeshComponentLOD1_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainSection_Statics::NewProp_ProceduralMeshComponent_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "TerrainSection.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATerrainSection_Statics::NewProp_ProceduralMeshComponent = { "ProceduralMeshComponent", nullptr, (EPropertyFlags)0x00400000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATerrainSection, ProceduralMeshComponent), Z_Construct_UClass_UProceduralMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATerrainSection_Statics::NewProp_ProceduralMeshComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainSection_Statics::NewProp_ProceduralMeshComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainSection_Statics::NewProp_RuntimeMeshComponent_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "TerrainSection.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATerrainSection_Statics::NewProp_RuntimeMeshComponent = { "RuntimeMeshComponent", nullptr, (EPropertyFlags)0x00400000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATerrainSection, RuntimeMeshComponent), Z_Construct_UClass_URuntimeMeshComponentStatic_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATerrainSection_Statics::NewProp_RuntimeMeshComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainSection_Statics::NewProp_RuntimeMeshComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainSection_Statics::NewProp_SceneRoot_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "TerrainSection.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATerrainSection_Statics::NewProp_SceneRoot = { "SceneRoot", nullptr, (EPropertyFlags)0x00400000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATerrainSection, SceneRoot), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATerrainSection_Statics::NewProp_SceneRoot_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainSection_Statics::NewProp_SceneRoot_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainSection_Statics::NewProp_bUseRuntimeMeshComponent_MetaData[] = {
		{ "Category", "ProceduralMeshGeneration" },
		{ "ModuleRelativePath", "TerrainSection.h" },
	};
#endif
	void Z_Construct_UClass_ATerrainSection_Statics::NewProp_bUseRuntimeMeshComponent_SetBit(void* Obj)
	{
		((ATerrainSection*)Obj)->bUseRuntimeMeshComponent = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ATerrainSection_Statics::NewProp_bUseRuntimeMeshComponent = { "bUseRuntimeMeshComponent", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ATerrainSection), &Z_Construct_UClass_ATerrainSection_Statics::NewProp_bUseRuntimeMeshComponent_SetBit, METADATA_PARAMS(Z_Construct_UClass_ATerrainSection_Statics::NewProp_bUseRuntimeMeshComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainSection_Statics::NewProp_bUseRuntimeMeshComponent_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATerrainSection_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainSection_Statics::NewProp_OwningTerrain,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainSection_Statics::NewProp_ProceduralMeshComponentLOD4,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainSection_Statics::NewProp_RuntimeMeshComponentLOD4,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainSection_Statics::NewProp_ProceduralMeshComponentLOD3,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainSection_Statics::NewProp_RuntimeMeshComponentLOD3,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainSection_Statics::NewProp_ProceduralMeshComponentLOD2,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainSection_Statics::NewProp_RuntimeMeshComponentLOD2,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainSection_Statics::NewProp_ProceduralMeshComponentLOD1,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainSection_Statics::NewProp_RuntimeMeshComponentLOD1,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainSection_Statics::NewProp_ProceduralMeshComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainSection_Statics::NewProp_RuntimeMeshComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainSection_Statics::NewProp_SceneRoot,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATerrainSection_Statics::NewProp_bUseRuntimeMeshComponent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATerrainSection_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATerrainSection>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ATerrainSection_Statics::ClassParams = {
		&ATerrainSection::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ATerrainSection_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainSection_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ATerrainSection_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainSection_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ATerrainSection()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ATerrainSection_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ATerrainSection, 660077154);
	template<> TWISTEDGROUNDS_API UClass* StaticClass<ATerrainSection>()
	{
		return ATerrainSection::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ATerrainSection(Z_Construct_UClass_ATerrainSection, &ATerrainSection::StaticClass, TEXT("/Script/TwistedGrounds"), TEXT("ATerrainSection"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATerrainSection);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
