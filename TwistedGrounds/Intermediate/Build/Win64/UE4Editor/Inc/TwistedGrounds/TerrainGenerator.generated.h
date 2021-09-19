// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TWISTEDGROUNDS_TerrainGenerator_generated_h
#error "TerrainGenerator.generated.h already included, missing '#pragma once' in TerrainGenerator.h"
#endif
#define TWISTEDGROUNDS_TerrainGenerator_generated_h

#define TwistedGrounds_Source_TwistedGrounds_TerrainGenerator_h_19_SPARSE_DATA
#define TwistedGrounds_Source_TwistedGrounds_TerrainGenerator_h_19_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetComponentXY) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetComponentXY(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetQuadSize) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetQuadSize(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetSectionXY) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetSectionXY(); \
		P_NATIVE_END; \
	}


#define TwistedGrounds_Source_TwistedGrounds_TerrainGenerator_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetComponentXY) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetComponentXY(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetQuadSize) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetQuadSize(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetSectionXY) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetSectionXY(); \
		P_NATIVE_END; \
	}


#define TwistedGrounds_Source_TwistedGrounds_TerrainGenerator_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATerrainGenerator(); \
	friend struct Z_Construct_UClass_ATerrainGenerator_Statics; \
public: \
	DECLARE_CLASS(ATerrainGenerator, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TwistedGrounds"), NO_API) \
	DECLARE_SERIALIZER(ATerrainGenerator)


#define TwistedGrounds_Source_TwistedGrounds_TerrainGenerator_h_19_INCLASS \
private: \
	static void StaticRegisterNativesATerrainGenerator(); \
	friend struct Z_Construct_UClass_ATerrainGenerator_Statics; \
public: \
	DECLARE_CLASS(ATerrainGenerator, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TwistedGrounds"), NO_API) \
	DECLARE_SERIALIZER(ATerrainGenerator)


#define TwistedGrounds_Source_TwistedGrounds_TerrainGenerator_h_19_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ATerrainGenerator(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ATerrainGenerator) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATerrainGenerator); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATerrainGenerator); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATerrainGenerator(ATerrainGenerator&&); \
	NO_API ATerrainGenerator(const ATerrainGenerator&); \
public:


#define TwistedGrounds_Source_TwistedGrounds_TerrainGenerator_h_19_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATerrainGenerator(ATerrainGenerator&&); \
	NO_API ATerrainGenerator(const ATerrainGenerator&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATerrainGenerator); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATerrainGenerator); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ATerrainGenerator)


#define TwistedGrounds_Source_TwistedGrounds_TerrainGenerator_h_19_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__SceneRoot() { return STRUCT_OFFSET(ATerrainGenerator, SceneRoot); } \
	FORCEINLINE static uint32 __PPO__GlobalVertexData() { return STRUCT_OFFSET(ATerrainGenerator, GlobalVertexData); }


#define TwistedGrounds_Source_TwistedGrounds_TerrainGenerator_h_16_PROLOG
#define TwistedGrounds_Source_TwistedGrounds_TerrainGenerator_h_19_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TwistedGrounds_Source_TwistedGrounds_TerrainGenerator_h_19_PRIVATE_PROPERTY_OFFSET \
	TwistedGrounds_Source_TwistedGrounds_TerrainGenerator_h_19_SPARSE_DATA \
	TwistedGrounds_Source_TwistedGrounds_TerrainGenerator_h_19_RPC_WRAPPERS \
	TwistedGrounds_Source_TwistedGrounds_TerrainGenerator_h_19_INCLASS \
	TwistedGrounds_Source_TwistedGrounds_TerrainGenerator_h_19_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TwistedGrounds_Source_TwistedGrounds_TerrainGenerator_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TwistedGrounds_Source_TwistedGrounds_TerrainGenerator_h_19_PRIVATE_PROPERTY_OFFSET \
	TwistedGrounds_Source_TwistedGrounds_TerrainGenerator_h_19_SPARSE_DATA \
	TwistedGrounds_Source_TwistedGrounds_TerrainGenerator_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	TwistedGrounds_Source_TwistedGrounds_TerrainGenerator_h_19_INCLASS_NO_PURE_DECLS \
	TwistedGrounds_Source_TwistedGrounds_TerrainGenerator_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TWISTEDGROUNDS_API UClass* StaticClass<class ATerrainGenerator>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TwistedGrounds_Source_TwistedGrounds_TerrainGenerator_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
