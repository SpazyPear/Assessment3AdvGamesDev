// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FHitResult;
struct FSculptInputInfo;
#ifdef TWISTEDGROUNDS_SculptComponent_generated_h
#error "SculptComponent.generated.h already included, missing '#pragma once' in SculptComponent.h"
#endif
#define TWISTEDGROUNDS_SculptComponent_generated_h

#define TwistedGrounds_Source_TwistedGrounds_SculptComponent_h_14_SPARSE_DATA
#define TwistedGrounds_Source_TwistedGrounds_SculptComponent_h_14_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSetHitResult) \
	{ \
		P_GET_STRUCT(FHitResult,Z_Param_HitResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetHitResult(Z_Param_HitResult); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSculptSingle) \
	{ \
		P_GET_STRUCT(FSculptInputInfo,Z_Param_ParamInputInfo); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->SculptSingle(Z_Param_ParamInputInfo); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSculptStop) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SculptStop(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSculptStart) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SculptStart(); \
		P_NATIVE_END; \
	}


#define TwistedGrounds_Source_TwistedGrounds_SculptComponent_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetHitResult) \
	{ \
		P_GET_STRUCT(FHitResult,Z_Param_HitResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetHitResult(Z_Param_HitResult); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSculptSingle) \
	{ \
		P_GET_STRUCT(FSculptInputInfo,Z_Param_ParamInputInfo); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->SculptSingle(Z_Param_ParamInputInfo); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSculptStop) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SculptStop(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSculptStart) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SculptStart(); \
		P_NATIVE_END; \
	}


#define TwistedGrounds_Source_TwistedGrounds_SculptComponent_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSculptComponent(); \
	friend struct Z_Construct_UClass_USculptComponent_Statics; \
public: \
	DECLARE_CLASS(USculptComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TwistedGrounds"), NO_API) \
	DECLARE_SERIALIZER(USculptComponent)


#define TwistedGrounds_Source_TwistedGrounds_SculptComponent_h_14_INCLASS \
private: \
	static void StaticRegisterNativesUSculptComponent(); \
	friend struct Z_Construct_UClass_USculptComponent_Statics; \
public: \
	DECLARE_CLASS(USculptComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TwistedGrounds"), NO_API) \
	DECLARE_SERIALIZER(USculptComponent)


#define TwistedGrounds_Source_TwistedGrounds_SculptComponent_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USculptComponent(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USculptComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USculptComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USculptComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USculptComponent(USculptComponent&&); \
	NO_API USculptComponent(const USculptComponent&); \
public:


#define TwistedGrounds_Source_TwistedGrounds_SculptComponent_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USculptComponent(USculptComponent&&); \
	NO_API USculptComponent(const USculptComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USculptComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USculptComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(USculptComponent)


#define TwistedGrounds_Source_TwistedGrounds_SculptComponent_h_14_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__SculptSettings() { return STRUCT_OFFSET(USculptComponent, SculptSettings); } \
	FORCEINLINE static uint32 __PPO__InputInfo() { return STRUCT_OFFSET(USculptComponent, InputInfo); } \
	FORCEINLINE static uint32 __PPO__SleepDistance() { return STRUCT_OFFSET(USculptComponent, SleepDistance); }


#define TwistedGrounds_Source_TwistedGrounds_SculptComponent_h_11_PROLOG
#define TwistedGrounds_Source_TwistedGrounds_SculptComponent_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TwistedGrounds_Source_TwistedGrounds_SculptComponent_h_14_PRIVATE_PROPERTY_OFFSET \
	TwistedGrounds_Source_TwistedGrounds_SculptComponent_h_14_SPARSE_DATA \
	TwistedGrounds_Source_TwistedGrounds_SculptComponent_h_14_RPC_WRAPPERS \
	TwistedGrounds_Source_TwistedGrounds_SculptComponent_h_14_INCLASS \
	TwistedGrounds_Source_TwistedGrounds_SculptComponent_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TwistedGrounds_Source_TwistedGrounds_SculptComponent_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TwistedGrounds_Source_TwistedGrounds_SculptComponent_h_14_PRIVATE_PROPERTY_OFFSET \
	TwistedGrounds_Source_TwistedGrounds_SculptComponent_h_14_SPARSE_DATA \
	TwistedGrounds_Source_TwistedGrounds_SculptComponent_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	TwistedGrounds_Source_TwistedGrounds_SculptComponent_h_14_INCLASS_NO_PURE_DECLS \
	TwistedGrounds_Source_TwistedGrounds_SculptComponent_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TWISTEDGROUNDS_API UClass* StaticClass<class USculptComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TwistedGrounds_Source_TwistedGrounds_SculptComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
