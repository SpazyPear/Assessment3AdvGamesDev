// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TwistedGrounds/ProcMeshSculpt.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeProcMeshSculpt() {}
// Cross Module References
	TWISTEDGROUNDS_API UEnum* Z_Construct_UEnum_TwistedGrounds_SCULPTSTATE();
	UPackage* Z_Construct_UPackage__Script_TwistedGrounds();
	TWISTEDGROUNDS_API UClass* Z_Construct_UClass_AProcMeshSculpt_NoRegister();
	TWISTEDGROUNDS_API UClass* Z_Construct_UClass_AProcMeshSculpt();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	TWISTEDGROUNDS_API UFunction* Z_Construct_UFunction_AProcMeshSculpt_TracePath();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	TWISTEDGROUNDS_API UClass* Z_Construct_UClass_AProcedurallyGeneratedMap_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCurveFloat_NoRegister();
// End Cross Module References
	static UEnum* SCULPTSTATE_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_TwistedGrounds_SCULPTSTATE, Z_Construct_UPackage__Script_TwistedGrounds(), TEXT("SCULPTSTATE"));
		}
		return Singleton;
	}
	template<> TWISTEDGROUNDS_API UEnum* StaticEnum<SCULPTSTATE>()
	{
		return SCULPTSTATE_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_SCULPTSTATE(SCULPTSTATE_StaticEnum, TEXT("/Script/TwistedGrounds"), TEXT("SCULPTSTATE"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_TwistedGrounds_SCULPTSTATE_Hash() { return 3493829751U; }
	UEnum* Z_Construct_UEnum_TwistedGrounds_SCULPTSTATE()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_TwistedGrounds();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("SCULPTSTATE"), 0, Get_Z_Construct_UEnum_TwistedGrounds_SCULPTSTATE_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "SCULPTSTATE::IDLE", (int64)SCULPTSTATE::IDLE },
				{ "SCULPTSTATE::ONGOING", (int64)SCULPTSTATE::ONGOING },
				{ "SCULPTSTATE::STOPPED", (int64)SCULPTSTATE::STOPPED },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "IDLE.Name", "SCULPTSTATE::IDLE" },
				{ "ModuleRelativePath", "ProcMeshSculpt.h" },
				{ "ONGOING.Name", "SCULPTSTATE::ONGOING" },
				{ "STOPPED.Name", "SCULPTSTATE::STOPPED" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_TwistedGrounds,
				nullptr,
				"SCULPTSTATE",
				"SCULPTSTATE",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static FName NAME_AProcMeshSculpt_TracePath = FName(TEXT("TracePath"));
	FHitResult AProcMeshSculpt::TracePath(FVector StartPos, FVector LaunchVelocity, AActor* IgnoreActors)
	{
		ProcMeshSculpt_eventTracePath_Parms Parms;
		Parms.StartPos=StartPos;
		Parms.LaunchVelocity=LaunchVelocity;
		Parms.IgnoreActors=IgnoreActors;
		ProcessEvent(FindFunctionChecked(NAME_AProcMeshSculpt_TracePath),&Parms);
		return Parms.ReturnValue;
	}
	void AProcMeshSculpt::StaticRegisterNativesAProcMeshSculpt()
	{
	}
	struct Z_Construct_UFunction_AProcMeshSculpt_TracePath_Statics
	{
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_IgnoreActors;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_LaunchVelocity;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_StartPos;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AProcMeshSculpt_TracePath_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010008000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProcMeshSculpt_eventTracePath_Parms, ReturnValue), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AProcMeshSculpt_TracePath_Statics::NewProp_IgnoreActors = { "IgnoreActors", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProcMeshSculpt_eventTracePath_Parms, IgnoreActors), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AProcMeshSculpt_TracePath_Statics::NewProp_LaunchVelocity = { "LaunchVelocity", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProcMeshSculpt_eventTracePath_Parms, LaunchVelocity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AProcMeshSculpt_TracePath_Statics::NewProp_StartPos = { "StartPos", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProcMeshSculpt_eventTracePath_Parms, StartPos), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProcMeshSculpt_TracePath_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProcMeshSculpt_TracePath_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProcMeshSculpt_TracePath_Statics::NewProp_IgnoreActors,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProcMeshSculpt_TracePath_Statics::NewProp_LaunchVelocity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProcMeshSculpt_TracePath_Statics::NewProp_StartPos,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProcMeshSculpt_TracePath_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ProcMeshSculpt.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AProcMeshSculpt_TracePath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AProcMeshSculpt, nullptr, "TracePath", nullptr, nullptr, sizeof(ProcMeshSculpt_eventTracePath_Parms), Z_Construct_UFunction_AProcMeshSculpt_TracePath_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AProcMeshSculpt_TracePath_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08820800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AProcMeshSculpt_TracePath_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AProcMeshSculpt_TracePath_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AProcMeshSculpt_TracePath()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AProcMeshSculpt_TracePath_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AProcMeshSculpt_NoRegister()
	{
		return AProcMeshSculpt::StaticClass();
	}
	struct Z_Construct_UClass_AProcMeshSculpt_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Map_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Map;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Curve_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Curve;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ScaledZStrength_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ScaledZStrength;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HitResult_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_HitResult;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AProcMeshSculpt_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_TwistedGrounds,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AProcMeshSculpt_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AProcMeshSculpt_TracePath, "TracePath" }, // 416479275
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProcMeshSculpt_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ProcMeshSculpt.h" },
		{ "ModuleRelativePath", "ProcMeshSculpt.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProcMeshSculpt_Statics::NewProp_Map_MetaData[] = {
		{ "Category", "ProcMeshSculpt" },
		{ "ModuleRelativePath", "ProcMeshSculpt.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProcMeshSculpt_Statics::NewProp_Map = { "Map", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AProcMeshSculpt, Map), Z_Construct_UClass_AProcedurallyGeneratedMap_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AProcMeshSculpt_Statics::NewProp_Map_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AProcMeshSculpt_Statics::NewProp_Map_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProcMeshSculpt_Statics::NewProp_Curve_MetaData[] = {
		{ "Category", "ProcMeshSculpt" },
		{ "ModuleRelativePath", "ProcMeshSculpt.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProcMeshSculpt_Statics::NewProp_Curve = { "Curve", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AProcMeshSculpt, Curve), Z_Construct_UClass_UCurveFloat_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AProcMeshSculpt_Statics::NewProp_Curve_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AProcMeshSculpt_Statics::NewProp_Curve_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProcMeshSculpt_Statics::NewProp_ScaledZStrength_MetaData[] = {
		{ "Category", "ProcMeshSculpt" },
		{ "ModuleRelativePath", "ProcMeshSculpt.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AProcMeshSculpt_Statics::NewProp_ScaledZStrength = { "ScaledZStrength", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AProcMeshSculpt, ScaledZStrength), METADATA_PARAMS(Z_Construct_UClass_AProcMeshSculpt_Statics::NewProp_ScaledZStrength_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AProcMeshSculpt_Statics::NewProp_ScaledZStrength_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProcMeshSculpt_Statics::NewProp_HitResult_MetaData[] = {
		{ "Category", "ProcMeshSculpt" },
		{ "ModuleRelativePath", "ProcMeshSculpt.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AProcMeshSculpt_Statics::NewProp_HitResult = { "HitResult", nullptr, (EPropertyFlags)0x0010008000000004, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AProcMeshSculpt, HitResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(Z_Construct_UClass_AProcMeshSculpt_Statics::NewProp_HitResult_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AProcMeshSculpt_Statics::NewProp_HitResult_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AProcMeshSculpt_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProcMeshSculpt_Statics::NewProp_Map,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProcMeshSculpt_Statics::NewProp_Curve,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProcMeshSculpt_Statics::NewProp_ScaledZStrength,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProcMeshSculpt_Statics::NewProp_HitResult,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AProcMeshSculpt_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AProcMeshSculpt>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AProcMeshSculpt_Statics::ClassParams = {
		&AProcMeshSculpt::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AProcMeshSculpt_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AProcMeshSculpt_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AProcMeshSculpt_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AProcMeshSculpt_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AProcMeshSculpt()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AProcMeshSculpt_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AProcMeshSculpt, 4040447116);
	template<> TWISTEDGROUNDS_API UClass* StaticClass<AProcMeshSculpt>()
	{
		return AProcMeshSculpt::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AProcMeshSculpt(Z_Construct_UClass_AProcMeshSculpt, &AProcMeshSculpt::StaticClass, TEXT("/Script/TwistedGrounds"), TEXT("AProcMeshSculpt"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AProcMeshSculpt);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
