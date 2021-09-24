// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TwistedGrounds/SavedMap.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSavedMap() {}
// Cross Module References
	TWISTEDGROUNDS_API UClass* Z_Construct_UClass_USavedMap_NoRegister();
	TWISTEDGROUNDS_API UClass* Z_Construct_UClass_USavedMap();
	ENGINE_API UClass* Z_Construct_UClass_USaveGame();
	UPackage* Z_Construct_UPackage__Script_TwistedGrounds();
	PROCEDURALMESHCOMPONENT_API UScriptStruct* Z_Construct_UScriptStruct_FProcMeshTangent();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
// End Cross Module References
	void USavedMap::StaticRegisterNativesUSavedMap()
	{
	}
	UClass* Z_Construct_UClass_USavedMap_NoRegister()
	{
		return USavedMap::StaticClass();
	}
	struct Z_Construct_UClass_USavedMap_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Tangents_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Tangents;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Tangents_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Normals_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Normals;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Normals_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_UVCoords_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_UVCoords;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_UVCoords_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Triangles_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Triangles;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Triangles_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Vertices_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Vertices;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Vertices_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Name;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Index_MetaData[];
#endif
		static const UE4CodeGen_Private::FUInt32PropertyParams NewProp_Index;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USavedMap_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USaveGame,
		(UObject* (*)())Z_Construct_UPackage__Script_TwistedGrounds,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USavedMap_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SavedMap.h" },
		{ "ModuleRelativePath", "SavedMap.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USavedMap_Statics::NewProp_Tangents_MetaData[] = {
		{ "ModuleRelativePath", "SavedMap.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_USavedMap_Statics::NewProp_Tangents = { "Tangents", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USavedMap, Tangents), METADATA_PARAMS(Z_Construct_UClass_USavedMap_Statics::NewProp_Tangents_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USavedMap_Statics::NewProp_Tangents_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_USavedMap_Statics::NewProp_Tangents_Inner = { "Tangents", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FProcMeshTangent, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USavedMap_Statics::NewProp_Normals_MetaData[] = {
		{ "ModuleRelativePath", "SavedMap.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_USavedMap_Statics::NewProp_Normals = { "Normals", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USavedMap, Normals), METADATA_PARAMS(Z_Construct_UClass_USavedMap_Statics::NewProp_Normals_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USavedMap_Statics::NewProp_Normals_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_USavedMap_Statics::NewProp_Normals_Inner = { "Normals", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USavedMap_Statics::NewProp_UVCoords_MetaData[] = {
		{ "ModuleRelativePath", "SavedMap.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_USavedMap_Statics::NewProp_UVCoords = { "UVCoords", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USavedMap, UVCoords), METADATA_PARAMS(Z_Construct_UClass_USavedMap_Statics::NewProp_UVCoords_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USavedMap_Statics::NewProp_UVCoords_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_USavedMap_Statics::NewProp_UVCoords_Inner = { "UVCoords", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USavedMap_Statics::NewProp_Triangles_MetaData[] = {
		{ "ModuleRelativePath", "SavedMap.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_USavedMap_Statics::NewProp_Triangles = { "Triangles", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USavedMap, Triangles), METADATA_PARAMS(Z_Construct_UClass_USavedMap_Statics::NewProp_Triangles_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USavedMap_Statics::NewProp_Triangles_MetaData)) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_USavedMap_Statics::NewProp_Triangles_Inner = { "Triangles", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USavedMap_Statics::NewProp_Vertices_MetaData[] = {
		{ "ModuleRelativePath", "SavedMap.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_USavedMap_Statics::NewProp_Vertices = { "Vertices", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USavedMap, Vertices), METADATA_PARAMS(Z_Construct_UClass_USavedMap_Statics::NewProp_Vertices_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USavedMap_Statics::NewProp_Vertices_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_USavedMap_Statics::NewProp_Vertices_Inner = { "Vertices", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USavedMap_Statics::NewProp_Name_MetaData[] = {
		{ "Category", "Basic" },
		{ "ModuleRelativePath", "SavedMap.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_USavedMap_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000020001, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USavedMap, Name), METADATA_PARAMS(Z_Construct_UClass_USavedMap_Statics::NewProp_Name_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USavedMap_Statics::NewProp_Name_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USavedMap_Statics::NewProp_Index_MetaData[] = {
		{ "Category", "Basic" },
		{ "ModuleRelativePath", "SavedMap.h" },
	};
#endif
	const UE4CodeGen_Private::FUInt32PropertyParams Z_Construct_UClass_USavedMap_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000020001, UE4CodeGen_Private::EPropertyGenFlags::UInt32, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USavedMap, Index), METADATA_PARAMS(Z_Construct_UClass_USavedMap_Statics::NewProp_Index_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USavedMap_Statics::NewProp_Index_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USavedMap_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USavedMap_Statics::NewProp_Tangents,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USavedMap_Statics::NewProp_Tangents_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USavedMap_Statics::NewProp_Normals,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USavedMap_Statics::NewProp_Normals_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USavedMap_Statics::NewProp_UVCoords,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USavedMap_Statics::NewProp_UVCoords_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USavedMap_Statics::NewProp_Triangles,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USavedMap_Statics::NewProp_Triangles_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USavedMap_Statics::NewProp_Vertices,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USavedMap_Statics::NewProp_Vertices_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USavedMap_Statics::NewProp_Name,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USavedMap_Statics::NewProp_Index,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USavedMap_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USavedMap>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USavedMap_Statics::ClassParams = {
		&USavedMap::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_USavedMap_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_USavedMap_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_USavedMap_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USavedMap_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USavedMap()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USavedMap_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USavedMap, 499452566);
	template<> TWISTEDGROUNDS_API UClass* StaticClass<USavedMap>()
	{
		return USavedMap::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USavedMap(Z_Construct_UClass_USavedMap, &USavedMap::StaticClass, TEXT("/Script/TwistedGrounds"), TEXT("USavedMap"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USavedMap);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
