// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TWISTEDGROUNDS_ProcedurallyGeneratedMap_generated_h
#error "ProcedurallyGeneratedMap.generated.h already included, missing '#pragma once' in ProcedurallyGeneratedMap.h"
#endif
#define TWISTEDGROUNDS_ProcedurallyGeneratedMap_generated_h

#define TwistedGrounds_Source_TwistedGrounds_ProcedurallyGeneratedMap_h_13_SPARSE_DATA
#define TwistedGrounds_Source_TwistedGrounds_ProcedurallyGeneratedMap_h_13_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGenerateMap) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->GenerateMap(); \
		P_NATIVE_END; \
	}


#define TwistedGrounds_Source_TwistedGrounds_ProcedurallyGeneratedMap_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGenerateMap) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->GenerateMap(); \
		P_NATIVE_END; \
	}


#define TwistedGrounds_Source_TwistedGrounds_ProcedurallyGeneratedMap_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAProcedurallyGeneratedMap(); \
	friend struct Z_Construct_UClass_AProcedurallyGeneratedMap_Statics; \
public: \
	DECLARE_CLASS(AProcedurallyGeneratedMap, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TwistedGrounds"), NO_API) \
	DECLARE_SERIALIZER(AProcedurallyGeneratedMap)


#define TwistedGrounds_Source_TwistedGrounds_ProcedurallyGeneratedMap_h_13_INCLASS \
private: \
	static void StaticRegisterNativesAProcedurallyGeneratedMap(); \
	friend struct Z_Construct_UClass_AProcedurallyGeneratedMap_Statics; \
public: \
	DECLARE_CLASS(AProcedurallyGeneratedMap, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TwistedGrounds"), NO_API) \
	DECLARE_SERIALIZER(AProcedurallyGeneratedMap)


#define TwistedGrounds_Source_TwistedGrounds_ProcedurallyGeneratedMap_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AProcedurallyGeneratedMap(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AProcedurallyGeneratedMap) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AProcedurallyGeneratedMap); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProcedurallyGeneratedMap); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AProcedurallyGeneratedMap(AProcedurallyGeneratedMap&&); \
	NO_API AProcedurallyGeneratedMap(const AProcedurallyGeneratedMap&); \
public:


#define TwistedGrounds_Source_TwistedGrounds_ProcedurallyGeneratedMap_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AProcedurallyGeneratedMap(AProcedurallyGeneratedMap&&); \
	NO_API AProcedurallyGeneratedMap(const AProcedurallyGeneratedMap&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AProcedurallyGeneratedMap); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProcedurallyGeneratedMap); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AProcedurallyGeneratedMap)


#define TwistedGrounds_Source_TwistedGrounds_ProcedurallyGeneratedMap_h_13_PRIVATE_PROPERTY_OFFSET
#define TwistedGrounds_Source_TwistedGrounds_ProcedurallyGeneratedMap_h_10_PROLOG
#define TwistedGrounds_Source_TwistedGrounds_ProcedurallyGeneratedMap_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TwistedGrounds_Source_TwistedGrounds_ProcedurallyGeneratedMap_h_13_PRIVATE_PROPERTY_OFFSET \
	TwistedGrounds_Source_TwistedGrounds_ProcedurallyGeneratedMap_h_13_SPARSE_DATA \
	TwistedGrounds_Source_TwistedGrounds_ProcedurallyGeneratedMap_h_13_RPC_WRAPPERS \
	TwistedGrounds_Source_TwistedGrounds_ProcedurallyGeneratedMap_h_13_INCLASS \
	TwistedGrounds_Source_TwistedGrounds_ProcedurallyGeneratedMap_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TwistedGrounds_Source_TwistedGrounds_ProcedurallyGeneratedMap_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TwistedGrounds_Source_TwistedGrounds_ProcedurallyGeneratedMap_h_13_PRIVATE_PROPERTY_OFFSET \
	TwistedGrounds_Source_TwistedGrounds_ProcedurallyGeneratedMap_h_13_SPARSE_DATA \
	TwistedGrounds_Source_TwistedGrounds_ProcedurallyGeneratedMap_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	TwistedGrounds_Source_TwistedGrounds_ProcedurallyGeneratedMap_h_13_INCLASS_NO_PURE_DECLS \
	TwistedGrounds_Source_TwistedGrounds_ProcedurallyGeneratedMap_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TWISTEDGROUNDS_API UClass* StaticClass<class AProcedurallyGeneratedMap>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TwistedGrounds_Source_TwistedGrounds_ProcedurallyGeneratedMap_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
