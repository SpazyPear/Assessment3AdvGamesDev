// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FSculptSettings;
struct FSculptInputInfo;
#ifdef TWISTEDGROUNDS_TerrainSection_generated_h
#error "TerrainSection.generated.h already included, missing '#pragma once' in TerrainSection.h"
#endif
#define TWISTEDGROUNDS_TerrainSection_generated_h

#define TwistedGrounds_Source_TwistedGrounds_TerrainSection_h_16_SPARSE_DATA
#define TwistedGrounds_Source_TwistedGrounds_TerrainSection_h_16_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execRequestSculpting) \
	{ \
		P_GET_STRUCT_REF(FSculptSettings,Z_Param_Out_Settings); \
		P_GET_STRUCT_REF(FSculptInputInfo,Z_Param_Out_InputInfo); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->RequestSculpting(Z_Param_Out_Settings,Z_Param_Out_InputInfo); \
		P_NATIVE_END; \
	}


#define TwistedGrounds_Source_TwistedGrounds_TerrainSection_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execRequestSculpting) \
	{ \
		P_GET_STRUCT_REF(FSculptSettings,Z_Param_Out_Settings); \
		P_GET_STRUCT_REF(FSculptInputInfo,Z_Param_Out_InputInfo); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->RequestSculpting(Z_Param_Out_Settings,Z_Param_Out_InputInfo); \
		P_NATIVE_END; \
	}


#define TwistedGrounds_Source_TwistedGrounds_TerrainSection_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATerrainSection(); \
	friend struct Z_Construct_UClass_ATerrainSection_Statics; \
public: \
	DECLARE_CLASS(ATerrainSection, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TwistedGrounds"), NO_API) \
	DECLARE_SERIALIZER(ATerrainSection)


#define TwistedGrounds_Source_TwistedGrounds_TerrainSection_h_16_INCLASS \
private: \
	static void StaticRegisterNativesATerrainSection(); \
	friend struct Z_Construct_UClass_ATerrainSection_Statics; \
public: \
	DECLARE_CLASS(ATerrainSection, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TwistedGrounds"), NO_API) \
	DECLARE_SERIALIZER(ATerrainSection)


#define TwistedGrounds_Source_TwistedGrounds_TerrainSection_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ATerrainSection(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ATerrainSection) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATerrainSection); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATerrainSection); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATerrainSection(ATerrainSection&&); \
	NO_API ATerrainSection(const ATerrainSection&); \
public:


#define TwistedGrounds_Source_TwistedGrounds_TerrainSection_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATerrainSection(ATerrainSection&&); \
	NO_API ATerrainSection(const ATerrainSection&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATerrainSection); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATerrainSection); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ATerrainSection)


#define TwistedGrounds_Source_TwistedGrounds_TerrainSection_h_16_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__SceneRoot() { return STRUCT_OFFSET(ATerrainSection, SceneRoot); } \
	FORCEINLINE static uint32 __PPO__RuntimeMeshComponent() { return STRUCT_OFFSET(ATerrainSection, RuntimeMeshComponent); } \
	FORCEINLINE static uint32 __PPO__ProceduralMeshComponent() { return STRUCT_OFFSET(ATerrainSection, ProceduralMeshComponent); } \
	FORCEINLINE static uint32 __PPO__RuntimeMeshComponentLOD1() { return STRUCT_OFFSET(ATerrainSection, RuntimeMeshComponentLOD1); } \
	FORCEINLINE static uint32 __PPO__ProceduralMeshComponentLOD1() { return STRUCT_OFFSET(ATerrainSection, ProceduralMeshComponentLOD1); } \
	FORCEINLINE static uint32 __PPO__RuntimeMeshComponentLOD2() { return STRUCT_OFFSET(ATerrainSection, RuntimeMeshComponentLOD2); } \
	FORCEINLINE static uint32 __PPO__ProceduralMeshComponentLOD2() { return STRUCT_OFFSET(ATerrainSection, ProceduralMeshComponentLOD2); } \
	FORCEINLINE static uint32 __PPO__RuntimeMeshComponentLOD3() { return STRUCT_OFFSET(ATerrainSection, RuntimeMeshComponentLOD3); } \
	FORCEINLINE static uint32 __PPO__ProceduralMeshComponentLOD3() { return STRUCT_OFFSET(ATerrainSection, ProceduralMeshComponentLOD3); } \
	FORCEINLINE static uint32 __PPO__RuntimeMeshComponentLOD4() { return STRUCT_OFFSET(ATerrainSection, RuntimeMeshComponentLOD4); } \
	FORCEINLINE static uint32 __PPO__ProceduralMeshComponentLOD4() { return STRUCT_OFFSET(ATerrainSection, ProceduralMeshComponentLOD4); } \
	FORCEINLINE static uint32 __PPO__OwningTerrain() { return STRUCT_OFFSET(ATerrainSection, OwningTerrain); }


#define TwistedGrounds_Source_TwistedGrounds_TerrainSection_h_13_PROLOG
#define TwistedGrounds_Source_TwistedGrounds_TerrainSection_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TwistedGrounds_Source_TwistedGrounds_TerrainSection_h_16_PRIVATE_PROPERTY_OFFSET \
	TwistedGrounds_Source_TwistedGrounds_TerrainSection_h_16_SPARSE_DATA \
	TwistedGrounds_Source_TwistedGrounds_TerrainSection_h_16_RPC_WRAPPERS \
	TwistedGrounds_Source_TwistedGrounds_TerrainSection_h_16_INCLASS \
	TwistedGrounds_Source_TwistedGrounds_TerrainSection_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TwistedGrounds_Source_TwistedGrounds_TerrainSection_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TwistedGrounds_Source_TwistedGrounds_TerrainSection_h_16_PRIVATE_PROPERTY_OFFSET \
	TwistedGrounds_Source_TwistedGrounds_TerrainSection_h_16_SPARSE_DATA \
	TwistedGrounds_Source_TwistedGrounds_TerrainSection_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	TwistedGrounds_Source_TwistedGrounds_TerrainSection_h_16_INCLASS_NO_PURE_DECLS \
	TwistedGrounds_Source_TwistedGrounds_TerrainSection_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TWISTEDGROUNDS_API UClass* StaticClass<class ATerrainSection>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TwistedGrounds_Source_TwistedGrounds_TerrainSection_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
