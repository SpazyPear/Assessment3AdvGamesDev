// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TWISTEDGROUNDS_ProcMeshSculpt_generated_h
#error "ProcMeshSculpt.generated.h already included, missing '#pragma once' in ProcMeshSculpt.h"
#endif
#define TWISTEDGROUNDS_ProcMeshSculpt_generated_h

#define TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h_17_SPARSE_DATA
#define TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h_17_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSculpt) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Sculpt(); \
		P_NATIVE_END; \
	}


#define TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSculpt) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Sculpt(); \
		P_NATIVE_END; \
	}


#define TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAProcMeshSculpt(); \
	friend struct Z_Construct_UClass_AProcMeshSculpt_Statics; \
public: \
	DECLARE_CLASS(AProcMeshSculpt, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TwistedGrounds"), NO_API) \
	DECLARE_SERIALIZER(AProcMeshSculpt)


#define TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h_17_INCLASS \
private: \
	static void StaticRegisterNativesAProcMeshSculpt(); \
	friend struct Z_Construct_UClass_AProcMeshSculpt_Statics; \
public: \
	DECLARE_CLASS(AProcMeshSculpt, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TwistedGrounds"), NO_API) \
	DECLARE_SERIALIZER(AProcMeshSculpt)


#define TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AProcMeshSculpt(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AProcMeshSculpt) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AProcMeshSculpt); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProcMeshSculpt); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AProcMeshSculpt(AProcMeshSculpt&&); \
	NO_API AProcMeshSculpt(const AProcMeshSculpt&); \
public:


#define TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AProcMeshSculpt(AProcMeshSculpt&&); \
	NO_API AProcMeshSculpt(const AProcMeshSculpt&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AProcMeshSculpt); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProcMeshSculpt); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AProcMeshSculpt)


#define TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h_17_PRIVATE_PROPERTY_OFFSET
#define TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h_14_PROLOG
#define TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h_17_PRIVATE_PROPERTY_OFFSET \
	TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h_17_SPARSE_DATA \
	TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h_17_RPC_WRAPPERS \
	TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h_17_INCLASS \
	TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h_17_PRIVATE_PROPERTY_OFFSET \
	TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h_17_SPARSE_DATA \
	TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h_17_INCLASS_NO_PURE_DECLS \
	TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TWISTEDGROUNDS_API UClass* StaticClass<class AProcMeshSculpt>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
