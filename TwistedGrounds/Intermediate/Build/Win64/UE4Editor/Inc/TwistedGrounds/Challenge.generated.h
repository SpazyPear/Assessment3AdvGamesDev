// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TWISTEDGROUNDS_Challenge_generated_h
#error "Challenge.generated.h already included, missing '#pragma once' in Challenge.h"
#endif
#define TWISTEDGROUNDS_Challenge_generated_h

#define TwistedGrounds_Source_TwistedGrounds_Challenge_h_15_SPARSE_DATA
#define TwistedGrounds_Source_TwistedGrounds_Challenge_h_15_RPC_WRAPPERS
#define TwistedGrounds_Source_TwistedGrounds_Challenge_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define TwistedGrounds_Source_TwistedGrounds_Challenge_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUChallenge(); \
	friend struct Z_Construct_UClass_UChallenge_Statics; \
public: \
	DECLARE_CLASS(UChallenge, UAnimInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/TwistedGrounds"), NO_API) \
	DECLARE_SERIALIZER(UChallenge)


#define TwistedGrounds_Source_TwistedGrounds_Challenge_h_15_INCLASS \
private: \
	static void StaticRegisterNativesUChallenge(); \
	friend struct Z_Construct_UClass_UChallenge_Statics; \
public: \
	DECLARE_CLASS(UChallenge, UAnimInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/TwistedGrounds"), NO_API) \
	DECLARE_SERIALIZER(UChallenge)


#define TwistedGrounds_Source_TwistedGrounds_Challenge_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UChallenge(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UChallenge) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UChallenge); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UChallenge); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UChallenge(UChallenge&&); \
	NO_API UChallenge(const UChallenge&); \
public:


#define TwistedGrounds_Source_TwistedGrounds_Challenge_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UChallenge(UChallenge&&); \
	NO_API UChallenge(const UChallenge&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UChallenge); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UChallenge); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UChallenge)


#define TwistedGrounds_Source_TwistedGrounds_Challenge_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__bIsSprinting() { return STRUCT_OFFSET(UChallenge, bIsSprinting); }


#define TwistedGrounds_Source_TwistedGrounds_Challenge_h_12_PROLOG
#define TwistedGrounds_Source_TwistedGrounds_Challenge_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TwistedGrounds_Source_TwistedGrounds_Challenge_h_15_PRIVATE_PROPERTY_OFFSET \
	TwistedGrounds_Source_TwistedGrounds_Challenge_h_15_SPARSE_DATA \
	TwistedGrounds_Source_TwistedGrounds_Challenge_h_15_RPC_WRAPPERS \
	TwistedGrounds_Source_TwistedGrounds_Challenge_h_15_INCLASS \
	TwistedGrounds_Source_TwistedGrounds_Challenge_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TwistedGrounds_Source_TwistedGrounds_Challenge_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TwistedGrounds_Source_TwistedGrounds_Challenge_h_15_PRIVATE_PROPERTY_OFFSET \
	TwistedGrounds_Source_TwistedGrounds_Challenge_h_15_SPARSE_DATA \
	TwistedGrounds_Source_TwistedGrounds_Challenge_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	TwistedGrounds_Source_TwistedGrounds_Challenge_h_15_INCLASS_NO_PURE_DECLS \
	TwistedGrounds_Source_TwistedGrounds_Challenge_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TWISTEDGROUNDS_API UClass* StaticClass<class UChallenge>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TwistedGrounds_Source_TwistedGrounds_Challenge_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
