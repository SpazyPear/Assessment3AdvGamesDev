// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TwistedGrounds/SculptComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSculptComponent() {}
// Cross Module References
	TWISTEDGROUNDS_API UClass* Z_Construct_UClass_USculptComponent_NoRegister();
	TWISTEDGROUNDS_API UClass* Z_Construct_UClass_USculptComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_TwistedGrounds();
	TWISTEDGROUNDS_API UFunction* Z_Construct_UFunction_USculptComponent_SculptSingle();
	TWISTEDGROUNDS_API UScriptStruct* Z_Construct_UScriptStruct_FSculptInputInfo();
	TWISTEDGROUNDS_API UFunction* Z_Construct_UFunction_USculptComponent_SculptStart();
	TWISTEDGROUNDS_API UFunction* Z_Construct_UFunction_USculptComponent_SculptStop();
	TWISTEDGROUNDS_API UFunction* Z_Construct_UFunction_USculptComponent_SetHitResult();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	TWISTEDGROUNDS_API UScriptStruct* Z_Construct_UScriptStruct_FSculptSettings();
// End Cross Module References
	void USculptComponent::StaticRegisterNativesUSculptComponent()
	{
		UClass* Class = USculptComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "SculptSingle", &USculptComponent::execSculptSingle },
			{ "SculptStart", &USculptComponent::execSculptStart },
			{ "SculptStop", &USculptComponent::execSculptStop },
			{ "SetHitResult", &USculptComponent::execSetHitResult },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USculptComponent_SculptSingle_Statics
	{
		struct SculptComponent_eventSculptSingle_Parms
		{
			FSculptInputInfo ParamInputInfo;
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ParamInputInfo;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_USculptComponent_SculptSingle_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SculptComponent_eventSculptSingle_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USculptComponent_SculptSingle_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SculptComponent_eventSculptSingle_Parms), &Z_Construct_UFunction_USculptComponent_SculptSingle_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USculptComponent_SculptSingle_Statics::NewProp_ParamInputInfo = { "ParamInputInfo", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SculptComponent_eventSculptSingle_Parms, ParamInputInfo), Z_Construct_UScriptStruct_FSculptInputInfo, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USculptComponent_SculptSingle_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USculptComponent_SculptSingle_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USculptComponent_SculptSingle_Statics::NewProp_ParamInputInfo,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USculptComponent_SculptSingle_Statics::Function_MetaDataParams[] = {
		{ "Category", "Sculpting" },
		{ "Comment", "// Use this if you want to implement sculpt behaviour yourself.\n" },
		{ "ModuleRelativePath", "SculptComponent.h" },
		{ "ToolTip", "Use this if you want to implement sculpt behaviour yourself." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USculptComponent_SculptSingle_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USculptComponent, nullptr, "SculptSingle", nullptr, nullptr, sizeof(SculptComponent_eventSculptSingle_Parms), Z_Construct_UFunction_USculptComponent_SculptSingle_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USculptComponent_SculptSingle_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USculptComponent_SculptSingle_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USculptComponent_SculptSingle_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USculptComponent_SculptSingle()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USculptComponent_SculptSingle_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USculptComponent_SculptStart_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USculptComponent_SculptStart_Statics::Function_MetaDataParams[] = {
		{ "Category", "Sculpting" },
		{ "Comment", "// starts sculpting action till it gets stopped by \"SculptStop\"\n" },
		{ "ModuleRelativePath", "SculptComponent.h" },
		{ "ToolTip", "starts sculpting action till it gets stopped by \"SculptStop\"" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USculptComponent_SculptStart_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USculptComponent, nullptr, "SculptStart", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USculptComponent_SculptStart_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USculptComponent_SculptStart_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USculptComponent_SculptStart()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USculptComponent_SculptStart_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USculptComponent_SculptStop_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USculptComponent_SculptStop_Statics::Function_MetaDataParams[] = {
		{ "Category", "Sculpting" },
		{ "Comment", "// Stops sculpting action\n" },
		{ "ModuleRelativePath", "SculptComponent.h" },
		{ "ToolTip", "Stops sculpting action" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USculptComponent_SculptStop_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USculptComponent, nullptr, "SculptStop", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USculptComponent_SculptStop_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USculptComponent_SculptStop_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USculptComponent_SculptStop()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USculptComponent_SculptStop_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USculptComponent_SetHitResult_Statics
	{
		struct SculptComponent_eventSetHitResult_Parms
		{
			FHitResult HitResult;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_HitResult;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USculptComponent_SetHitResult_Statics::NewProp_HitResult = { "HitResult", nullptr, (EPropertyFlags)0x0010008000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SculptComponent_eventSetHitResult_Parms, HitResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USculptComponent_SetHitResult_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USculptComponent_SetHitResult_Statics::NewProp_HitResult,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USculptComponent_SetHitResult_Statics::Function_MetaDataParams[] = {
		{ "Category", "Sculpting" },
		{ "Comment", "// Has to be called from owner class\n" },
		{ "ModuleRelativePath", "SculptComponent.h" },
		{ "ToolTip", "Has to be called from owner class" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USculptComponent_SetHitResult_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USculptComponent, nullptr, "SetHitResult", nullptr, nullptr, sizeof(SculptComponent_eventSetHitResult_Parms), Z_Construct_UFunction_USculptComponent_SetHitResult_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USculptComponent_SetHitResult_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USculptComponent_SetHitResult_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USculptComponent_SetHitResult_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USculptComponent_SetHitResult()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USculptComponent_SetHitResult_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_USculptComponent_NoRegister()
	{
		return USculptComponent::StaticClass();
	}
	struct Z_Construct_UClass_USculptComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SleepDistance_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_SleepDistance;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InputInfo_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_InputInfo;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SculptSettings_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_SculptSettings;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USculptComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_TwistedGrounds,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USculptComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USculptComponent_SculptSingle, "SculptSingle" }, // 3863880586
		{ &Z_Construct_UFunction_USculptComponent_SculptStart, "SculptStart" }, // 246173253
		{ &Z_Construct_UFunction_USculptComponent_SculptStop, "SculptStop" }, // 3714525650
		{ &Z_Construct_UFunction_USculptComponent_SetHitResult, "SetHitResult" }, // 3965208325
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USculptComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "SculptComponent.h" },
		{ "ModuleRelativePath", "SculptComponent.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USculptComponent_Statics::NewProp_SleepDistance_MetaData[] = {
		{ "Category", "Sculpting" },
		{ "Comment", "// Distance you have to move away from previous sculpt location to send next sculpt request\n" },
		{ "ModuleRelativePath", "SculptComponent.h" },
		{ "ToolTip", "Distance you have to move away from previous sculpt location to send next sculpt request" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USculptComponent_Statics::NewProp_SleepDistance = { "SleepDistance", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USculptComponent, SleepDistance), METADATA_PARAMS(Z_Construct_UClass_USculptComponent_Statics::NewProp_SleepDistance_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USculptComponent_Statics::NewProp_SleepDistance_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USculptComponent_Statics::NewProp_InputInfo_MetaData[] = {
		{ "Category", "Sculpting" },
		{ "ModuleRelativePath", "SculptComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_USculptComponent_Statics::NewProp_InputInfo = { "InputInfo", nullptr, (EPropertyFlags)0x0020080000020015, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USculptComponent, InputInfo), Z_Construct_UScriptStruct_FSculptInputInfo, METADATA_PARAMS(Z_Construct_UClass_USculptComponent_Statics::NewProp_InputInfo_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USculptComponent_Statics::NewProp_InputInfo_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USculptComponent_Statics::NewProp_SculptSettings_MetaData[] = {
		{ "Category", "Sculpting" },
		{ "ModuleRelativePath", "SculptComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_USculptComponent_Statics::NewProp_SculptSettings = { "SculptSettings", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USculptComponent, SculptSettings), Z_Construct_UScriptStruct_FSculptSettings, METADATA_PARAMS(Z_Construct_UClass_USculptComponent_Statics::NewProp_SculptSettings_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USculptComponent_Statics::NewProp_SculptSettings_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USculptComponent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USculptComponent_Statics::NewProp_SleepDistance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USculptComponent_Statics::NewProp_InputInfo,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USculptComponent_Statics::NewProp_SculptSettings,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USculptComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USculptComponent>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USculptComponent_Statics::ClassParams = {
		&USculptComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_USculptComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_USculptComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_USculptComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USculptComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USculptComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USculptComponent_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USculptComponent, 1324325754);
	template<> TWISTEDGROUNDS_API UClass* StaticClass<USculptComponent>()
	{
		return USculptComponent::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USculptComponent(Z_Construct_UClass_USculptComponent, &USculptComponent::StaticClass, TEXT("/Script/TwistedGrounds"), TEXT("USculptComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USculptComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
