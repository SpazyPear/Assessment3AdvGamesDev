// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FHitResult;
struct FVector;
#ifdef TWISTEDGROUNDS_ProcMeshSculpt_generated_h
#error "ProcMeshSculpt.generated.h already included, missing '#pragma once' in ProcMeshSculpt.h"
#endif
#define TWISTEDGROUNDS_ProcMeshSculpt_generated_h

#define TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h_36_SPARSE_DATA
#define TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h_36_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnOverlapEnd) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnOverlapEnd(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnOverlapBegin) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComponent); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnOverlapBegin(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComponent,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	}


#define TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h_36_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnOverlapEnd) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnOverlapEnd(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnOverlapBegin) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComponent); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnOverlapBegin(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComponent,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	}


#define TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h_36_EVENT_PARMS \
	struct ProcMeshSculpt_eventTracePath_Parms \
	{ \
		FVector StartPos; \
		FVector LaunchVelocity; \
		AActor* IgnoreActors; \
		FHitResult ReturnValue; \
	};


#define TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h_36_CALLBACK_WRAPPERS
#define TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h_36_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAProcMeshSculpt(); \
	friend struct Z_Construct_UClass_AProcMeshSculpt_Statics; \
public: \
	DECLARE_CLASS(AProcMeshSculpt, ADecalActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TwistedGrounds"), NO_API) \
	DECLARE_SERIALIZER(AProcMeshSculpt)


#define TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h_36_INCLASS \
private: \
	static void StaticRegisterNativesAProcMeshSculpt(); \
	friend struct Z_Construct_UClass_AProcMeshSculpt_Statics; \
public: \
	DECLARE_CLASS(AProcMeshSculpt, ADecalActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TwistedGrounds"), NO_API) \
	DECLARE_SERIALIZER(AProcMeshSculpt)


#define TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h_36_STANDARD_CONSTRUCTORS \
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


#define TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h_36_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AProcMeshSculpt(AProcMeshSculpt&&); \
	NO_API AProcMeshSculpt(const AProcMeshSculpt&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AProcMeshSculpt); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProcMeshSculpt); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AProcMeshSculpt)


#define TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h_36_PRIVATE_PROPERTY_OFFSET
#define TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h_33_PROLOG \
	TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h_36_EVENT_PARMS


#define TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h_36_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h_36_PRIVATE_PROPERTY_OFFSET \
	TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h_36_SPARSE_DATA \
	TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h_36_RPC_WRAPPERS \
	TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h_36_CALLBACK_WRAPPERS \
	TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h_36_INCLASS \
	TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h_36_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h_36_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h_36_PRIVATE_PROPERTY_OFFSET \
	TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h_36_SPARSE_DATA \
	TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h_36_RPC_WRAPPERS_NO_PURE_DECLS \
	TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h_36_CALLBACK_WRAPPERS \
	TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h_36_INCLASS_NO_PURE_DECLS \
	TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h_36_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TWISTEDGROUNDS_API UClass* StaticClass<class AProcMeshSculpt>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TwistedGrounds_Source_TwistedGrounds_ProcMeshSculpt_h


#define FOREACH_ENUM_DIRECTION(op) \
	op(DIRECTION::LEFT) \
	op(DIRECTION::RIGHT) \
	op(DIRECTION::UP) \
	op(DIRECTION::DOWN) 

enum class DIRECTION : uint8;
template<> TWISTEDGROUNDS_API UEnum* StaticEnum<DIRECTION>();

#define FOREACH_ENUM_SCULPTSTATE(op) \
	op(SCULPTSTATE::IDLE) \
	op(SCULPTSTATE::ONGOING) \
	op(SCULPTSTATE::STOPPED) 

enum class SCULPTSTATE : uint8;
template<> TWISTEDGROUNDS_API UEnum* StaticEnum<SCULPTSTATE>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
