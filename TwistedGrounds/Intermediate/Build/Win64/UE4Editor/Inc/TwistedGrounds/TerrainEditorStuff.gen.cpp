// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TwistedGrounds/TerrainEditorStuff.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTerrainEditorStuff() {}
// Cross Module References
	TWISTEDGROUNDS_API UEnum* Z_Construct_UEnum_TwistedGrounds_ETerrainGeneration();
	UPackage* Z_Construct_UPackage__Script_TwistedGrounds();
	TWISTEDGROUNDS_API UEnum* Z_Construct_UEnum_TwistedGrounds_ESculptInput();
	TWISTEDGROUNDS_API UEnum* Z_Construct_UEnum_TwistedGrounds_ESculptMode();
	TWISTEDGROUNDS_API UEnum* Z_Construct_UEnum_TwistedGrounds_ESectionPosition();
	TWISTEDGROUNDS_API UScriptStruct* Z_Construct_UScriptStruct_FSculptInputInfo();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	TWISTEDGROUNDS_API UScriptStruct* Z_Construct_UScriptStruct_FSculptSettings();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FColor();
	TWISTEDGROUNDS_API UScriptStruct* Z_Construct_UScriptStruct_FSectionProperties();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	TWISTEDGROUNDS_API UScriptStruct* Z_Construct_UScriptStruct_FVertexData();
	TWISTEDGROUNDS_API UClass* Z_Construct_UClass_ATerrainEditorStuff_NoRegister();
	TWISTEDGROUNDS_API UClass* Z_Construct_UClass_ATerrainEditorStuff();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
// End Cross Module References
	static UEnum* ETerrainGeneration_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_TwistedGrounds_ETerrainGeneration, Z_Construct_UPackage__Script_TwistedGrounds(), TEXT("ETerrainGeneration"));
		}
		return Singleton;
	}
	template<> TWISTEDGROUNDS_API UEnum* StaticEnum<ETerrainGeneration>()
	{
		return ETerrainGeneration_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ETerrainGeneration(ETerrainGeneration_StaticEnum, TEXT("/Script/TwistedGrounds"), TEXT("ETerrainGeneration"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_TwistedGrounds_ETerrainGeneration_Hash() { return 4090270912U; }
	UEnum* Z_Construct_UEnum_TwistedGrounds_ETerrainGeneration()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_TwistedGrounds();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ETerrainGeneration"), 0, Get_Z_Construct_UEnum_TwistedGrounds_ETerrainGeneration_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ETerrainGeneration::TG_LineTrace", (int64)ETerrainGeneration::TG_LineTrace },
				{ "ETerrainGeneration::TG_Flat", (int64)ETerrainGeneration::TG_Flat },
				{ "ETerrainGeneration::TG_Noise", (int64)ETerrainGeneration::TG_Noise },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "TerrainEditorStuff.h" },
				{ "TG_Flat.DisplayName", "Flat" },
				{ "TG_Flat.Name", "ETerrainGeneration::TG_Flat" },
				{ "TG_LineTrace.DisplayName", "LineTrace" },
				{ "TG_LineTrace.Name", "ETerrainGeneration::TG_LineTrace" },
				{ "TG_Noise.DisplayName", "Noise" },
				{ "TG_Noise.Name", "ETerrainGeneration::TG_Noise" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_TwistedGrounds,
				nullptr,
				"ETerrainGeneration",
				"ETerrainGeneration",
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
	static UEnum* ESculptInput_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_TwistedGrounds_ESculptInput, Z_Construct_UPackage__Script_TwistedGrounds(), TEXT("ESculptInput"));
		}
		return Singleton;
	}
	template<> TWISTEDGROUNDS_API UEnum* StaticEnum<ESculptInput>()
	{
		return ESculptInput_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ESculptInput(ESculptInput_StaticEnum, TEXT("/Script/TwistedGrounds"), TEXT("ESculptInput"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_TwistedGrounds_ESculptInput_Hash() { return 3564760108U; }
	UEnum* Z_Construct_UEnum_TwistedGrounds_ESculptInput()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_TwistedGrounds();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ESculptInput"), 0, Get_Z_Construct_UEnum_TwistedGrounds_ESculptInput_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ESculptInput::ST_Started", (int64)ESculptInput::ST_Started },
				{ "ESculptInput::ST_Ongoing", (int64)ESculptInput::ST_Ongoing },
				{ "ESculptInput::ST_Stopped", (int64)ESculptInput::ST_Stopped },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "TerrainEditorStuff.h" },
				{ "ST_Ongoing.DisplayName", "Ongoing" },
				{ "ST_Ongoing.Name", "ESculptInput::ST_Ongoing" },
				{ "ST_Started.DisplayName", "Started" },
				{ "ST_Started.Name", "ESculptInput::ST_Started" },
				{ "ST_Stopped.DisplayName", "Stopped" },
				{ "ST_Stopped.Name", "ESculptInput::ST_Stopped" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_TwistedGrounds,
				nullptr,
				"ESculptInput",
				"ESculptInput",
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
	static UEnum* ESculptMode_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_TwistedGrounds_ESculptMode, Z_Construct_UPackage__Script_TwistedGrounds(), TEXT("ESculptMode"));
		}
		return Singleton;
	}
	template<> TWISTEDGROUNDS_API UEnum* StaticEnum<ESculptMode>()
	{
		return ESculptMode_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ESculptMode(ESculptMode_StaticEnum, TEXT("/Script/TwistedGrounds"), TEXT("ESculptMode"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_TwistedGrounds_ESculptMode_Hash() { return 612302160U; }
	UEnum* Z_Construct_UEnum_TwistedGrounds_ESculptMode()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_TwistedGrounds();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ESculptMode"), 0, Get_Z_Construct_UEnum_TwistedGrounds_ESculptMode_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ESculptMode::ST_Sculpt", (int64)ESculptMode::ST_Sculpt },
				{ "ESculptMode::ST_Flatten", (int64)ESculptMode::ST_Flatten },
				{ "ESculptMode::ST_Smooth", (int64)ESculptMode::ST_Smooth },
				{ "ESculptMode::ST_Noise", (int64)ESculptMode::ST_Noise },
				{ "ESculptMode::ST_Paint", (int64)ESculptMode::ST_Paint },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "TerrainEditorStuff.h" },
				{ "ST_Flatten.DisplayName", "Flatten" },
				{ "ST_Flatten.Name", "ESculptMode::ST_Flatten" },
				{ "ST_Noise.DisplayName", "Noise" },
				{ "ST_Noise.Name", "ESculptMode::ST_Noise" },
				{ "ST_Paint.DisplayName", "Paint" },
				{ "ST_Paint.Name", "ESculptMode::ST_Paint" },
				{ "ST_Sculpt.DisplayName", "Sculpt" },
				{ "ST_Sculpt.Name", "ESculptMode::ST_Sculpt" },
				{ "ST_Smooth.DisplayName", "Smooth" },
				{ "ST_Smooth.Name", "ESculptMode::ST_Smooth" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_TwistedGrounds,
				nullptr,
				"ESculptMode",
				"ESculptMode",
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
	static UEnum* ESectionPosition_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_TwistedGrounds_ESectionPosition, Z_Construct_UPackage__Script_TwistedGrounds(), TEXT("ESectionPosition"));
		}
		return Singleton;
	}
	template<> TWISTEDGROUNDS_API UEnum* StaticEnum<ESectionPosition>()
	{
		return ESectionPosition_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ESectionPosition(ESectionPosition_StaticEnum, TEXT("/Script/TwistedGrounds"), TEXT("ESectionPosition"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_TwistedGrounds_ESectionPosition_Hash() { return 963355947U; }
	UEnum* Z_Construct_UEnum_TwistedGrounds_ESectionPosition()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_TwistedGrounds();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ESectionPosition"), 0, Get_Z_Construct_UEnum_TwistedGrounds_ESectionPosition_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ESectionPosition::SB_NotOnBorder", (int64)ESectionPosition::SB_NotOnBorder },
				{ "ESectionPosition::SB_BorderLeft", (int64)ESectionPosition::SB_BorderLeft },
				{ "ESectionPosition::SB_BorderRight", (int64)ESectionPosition::SB_BorderRight },
				{ "ESectionPosition::SB_BorderTop", (int64)ESectionPosition::SB_BorderTop },
				{ "ESectionPosition::SB_BorderBottom", (int64)ESectionPosition::SB_BorderBottom },
				{ "ESectionPosition::SB_EdgeTopLeft", (int64)ESectionPosition::SB_EdgeTopLeft },
				{ "ESectionPosition::SB_EdgeTopRight", (int64)ESectionPosition::SB_EdgeTopRight },
				{ "ESectionPosition::SB_EdgeBottomLeft", (int64)ESectionPosition::SB_EdgeBottomLeft },
				{ "ESectionPosition::SB_EdgeBottomRight", (int64)ESectionPosition::SB_EdgeBottomRight },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Comment", "/*\nI made this class only to store the Structs and Enums that are needed in multiple classes\nI tried adding only a header and even making a static library, but failed at both.\nSo in the meantime, this has to do the job\n*/" },
				{ "ModuleRelativePath", "TerrainEditorStuff.h" },
				{ "SB_BorderBottom.DisplayName", "BorderBottom" },
				{ "SB_BorderBottom.Name", "ESectionPosition::SB_BorderBottom" },
				{ "SB_BorderLeft.DisplayName", "BorderLeft" },
				{ "SB_BorderLeft.Name", "ESectionPosition::SB_BorderLeft" },
				{ "SB_BorderRight.DisplayName", "BorderRight" },
				{ "SB_BorderRight.Name", "ESectionPosition::SB_BorderRight" },
				{ "SB_BorderTop.DisplayName", "BorderTop" },
				{ "SB_BorderTop.Name", "ESectionPosition::SB_BorderTop" },
				{ "SB_EdgeBottomLeft.DisplayName", "EdgeBottomLeft" },
				{ "SB_EdgeBottomLeft.Name", "ESectionPosition::SB_EdgeBottomLeft" },
				{ "SB_EdgeBottomRight.DisplayName", "EdgeBottomRight" },
				{ "SB_EdgeBottomRight.Name", "ESectionPosition::SB_EdgeBottomRight" },
				{ "SB_EdgeTopLeft.DisplayName", "EdgeTopLeft" },
				{ "SB_EdgeTopLeft.Name", "ESectionPosition::SB_EdgeTopLeft" },
				{ "SB_EdgeTopRight.DisplayName", "EdgeTopRight" },
				{ "SB_EdgeTopRight.Name", "ESectionPosition::SB_EdgeTopRight" },
				{ "SB_NotOnBorder.DisplayName", "NotOnBorder" },
				{ "SB_NotOnBorder.Name", "ESectionPosition::SB_NotOnBorder" },
				{ "ToolTip", "I made this class only to store the Structs and Enums that are needed in multiple classes\nI tried adding only a header and even making a static library, but failed at both.\nSo in the meantime, this has to do the job" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_TwistedGrounds,
				nullptr,
				"ESectionPosition",
				"ESectionPosition",
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
class UScriptStruct* FSculptInputInfo::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern TWISTEDGROUNDS_API uint32 Get_Z_Construct_UScriptStruct_FSculptInputInfo_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FSculptInputInfo, Z_Construct_UPackage__Script_TwistedGrounds(), TEXT("SculptInputInfo"), sizeof(FSculptInputInfo), Get_Z_Construct_UScriptStruct_FSculptInputInfo_Hash());
	}
	return Singleton;
}
template<> TWISTEDGROUNDS_API UScriptStruct* StaticStruct<FSculptInputInfo>()
{
	return FSculptInputInfo::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FSculptInputInfo(FSculptInputInfo::StaticStruct, TEXT("/Script/TwistedGrounds"), TEXT("SculptInputInfo"), false, nullptr, nullptr);
static struct FScriptStruct_TwistedGrounds_StaticRegisterNativesFSculptInputInfo
{
	FScriptStruct_TwistedGrounds_StaticRegisterNativesFSculptInputInfo()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("SculptInputInfo")),new UScriptStruct::TCppStructOps<FSculptInputInfo>);
	}
} ScriptStruct_TwistedGrounds_StaticRegisterNativesFSculptInputInfo;
	struct Z_Construct_UScriptStruct_FSculptInputInfo_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LastLocation_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_LastLocation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CurrentLocation_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_CurrentLocation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_StartLocation_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_StartLocation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SculptInput_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_SculptInput;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_SculptInput_Underlying;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSculptInputInfo_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "TerrainEditorStuff.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FSculptInputInfo_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSculptInputInfo>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSculptInputInfo_Statics::NewProp_LastLocation_MetaData[] = {
		{ "Category", "Sculpting" },
		{ "Comment", "// The last location that the sculpt component send an update request\n" },
		{ "ModuleRelativePath", "TerrainEditorStuff.h" },
		{ "ToolTip", "The last location that the sculpt component send an update request" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSculptInputInfo_Statics::NewProp_LastLocation = { "LastLocation", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSculptInputInfo, LastLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FSculptInputInfo_Statics::NewProp_LastLocation_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSculptInputInfo_Statics::NewProp_LastLocation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSculptInputInfo_Statics::NewProp_CurrentLocation_MetaData[] = {
		{ "Category", "Sculpting" },
		{ "Comment", "// The location the sculpting actor requests to sculpt\n" },
		{ "ModuleRelativePath", "TerrainEditorStuff.h" },
		{ "ToolTip", "The location the sculpting actor requests to sculpt" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSculptInputInfo_Statics::NewProp_CurrentLocation = { "CurrentLocation", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSculptInputInfo, CurrentLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FSculptInputInfo_Statics::NewProp_CurrentLocation_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSculptInputInfo_Statics::NewProp_CurrentLocation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSculptInputInfo_Statics::NewProp_StartLocation_MetaData[] = {
		{ "Category", "Sculpting" },
		{ "Comment", "//Sculpt location when sculpting actor just triggered the sculpt function\n" },
		{ "ModuleRelativePath", "TerrainEditorStuff.h" },
		{ "ToolTip", "Sculpt location when sculpting actor just triggered the sculpt function" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSculptInputInfo_Statics::NewProp_StartLocation = { "StartLocation", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSculptInputInfo, StartLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FSculptInputInfo_Statics::NewProp_StartLocation_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSculptInputInfo_Statics::NewProp_StartLocation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSculptInputInfo_Statics::NewProp_SculptInput_MetaData[] = {
		{ "Category", "Sculpting" },
		{ "Comment", "// was input trigger just pressed, is ongoing or released\n" },
		{ "ModuleRelativePath", "TerrainEditorStuff.h" },
		{ "ToolTip", "was input trigger just pressed, is ongoing or released" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FSculptInputInfo_Statics::NewProp_SculptInput = { "SculptInput", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSculptInputInfo, SculptInput), Z_Construct_UEnum_TwistedGrounds_ESculptInput, METADATA_PARAMS(Z_Construct_UScriptStruct_FSculptInputInfo_Statics::NewProp_SculptInput_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSculptInputInfo_Statics::NewProp_SculptInput_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FSculptInputInfo_Statics::NewProp_SculptInput_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSculptInputInfo_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSculptInputInfo_Statics::NewProp_LastLocation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSculptInputInfo_Statics::NewProp_CurrentLocation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSculptInputInfo_Statics::NewProp_StartLocation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSculptInputInfo_Statics::NewProp_SculptInput,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSculptInputInfo_Statics::NewProp_SculptInput_Underlying,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSculptInputInfo_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_TwistedGrounds,
		nullptr,
		&NewStructOps,
		"SculptInputInfo",
		sizeof(FSculptInputInfo),
		alignof(FSculptInputInfo),
		Z_Construct_UScriptStruct_FSculptInputInfo_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSculptInputInfo_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FSculptInputInfo_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSculptInputInfo_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSculptInputInfo()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FSculptInputInfo_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_TwistedGrounds();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("SculptInputInfo"), sizeof(FSculptInputInfo), Get_Z_Construct_UScriptStruct_FSculptInputInfo_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FSculptInputInfo_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FSculptInputInfo_Hash() { return 1095906242U; }
class UScriptStruct* FSculptSettings::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern TWISTEDGROUNDS_API uint32 Get_Z_Construct_UScriptStruct_FSculptSettings_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FSculptSettings, Z_Construct_UPackage__Script_TwistedGrounds(), TEXT("SculptSettings"), sizeof(FSculptSettings), Get_Z_Construct_UScriptStruct_FSculptSettings_Hash());
	}
	return Singleton;
}
template<> TWISTEDGROUNDS_API UScriptStruct* StaticStruct<FSculptSettings>()
{
	return FSculptSettings::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FSculptSettings(FSculptSettings::StaticStruct, TEXT("/Script/TwistedGrounds"), TEXT("SculptSettings"), false, nullptr, nullptr);
static struct FScriptStruct_TwistedGrounds_StaticRegisterNativesFSculptSettings
{
	FScriptStruct_TwistedGrounds_StaticRegisterNativesFSculptSettings()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("SculptSettings")),new UScriptStruct::TCppStructOps<FSculptSettings>);
	}
} ScriptStruct_TwistedGrounds_StaticRegisterNativesFSculptSettings;
	struct Z_Construct_UScriptStruct_FSculptSettings_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NoiseScale_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_NoiseScale;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ColorTargetLayerStrength_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ColorTargetLayerStrength;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bUseColorTargetLayer_MetaData[];
#endif
		static void NewProp_bUseColorTargetLayer_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bUseColorTargetLayer;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Color_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Color;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bUseUpdateQueue_MetaData[];
#endif
		static void NewProp_bUseUpdateQueue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bUseUpdateQueue;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Falloff_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Falloff;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ToolStrength_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ToolStrength;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SculptRadius_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_SculptRadius;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bInvertToolDirection_MetaData[];
#endif
		static void NewProp_bInvertToolDirection_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bInvertToolDirection;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SculptMode_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_SculptMode;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_SculptMode_Underlying;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSculptSettings_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "TerrainEditorStuff.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FSculptSettings_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSculptSettings>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_NoiseScale_MetaData[] = {
		{ "Category", "Sculpting" },
		{ "ClampMax", "500.0" },
		{ "ClampMin", "1.0" },
		{ "Comment", "// Lower values result in more dense noise\n" },
		{ "ModuleRelativePath", "TerrainEditorStuff.h" },
		{ "ToolTip", "Lower values result in more dense noise" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_NoiseScale = { "NoiseScale", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSculptSettings, NoiseScale), METADATA_PARAMS(Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_NoiseScale_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_NoiseScale_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_ColorTargetLayerStrength_MetaData[] = {
		{ "Category", "Sculpting" },
		{ "ClampMax", "255.0" },
		{ "ClampMin", "0.0" },
		{ "Comment", "// Limit layer strength Min = 0, Max = 255;\n" },
		{ "ModuleRelativePath", "TerrainEditorStuff.h" },
		{ "ToolTip", "Limit layer strength Min = 0, Max = 255;" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_ColorTargetLayerStrength = { "ColorTargetLayerStrength", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSculptSettings, ColorTargetLayerStrength), METADATA_PARAMS(Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_ColorTargetLayerStrength_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_ColorTargetLayerStrength_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_bUseColorTargetLayer_MetaData[] = {
		{ "Category", "Sculpting" },
		{ "Comment", "// Use Max Layer strength\n" },
		{ "ModuleRelativePath", "TerrainEditorStuff.h" },
		{ "ToolTip", "Use Max Layer strength" },
	};
#endif
	void Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_bUseColorTargetLayer_SetBit(void* Obj)
	{
		((FSculptSettings*)Obj)->bUseColorTargetLayer = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_bUseColorTargetLayer = { "bUseColorTargetLayer", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FSculptSettings), &Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_bUseColorTargetLayer_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_bUseColorTargetLayer_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_bUseColorTargetLayer_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_Color_MetaData[] = {
		{ "Category", "Sculpting" },
		{ "Comment", "// Vertex Color that will be painted when in paint mode\n" },
		{ "ModuleRelativePath", "TerrainEditorStuff.h" },
		{ "ToolTip", "Vertex Color that will be painted when in paint mode" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_Color = { "Color", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSculptSettings, Color), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_Color_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_Color_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_bUseUpdateQueue_MetaData[] = {
		{ "Category", "Sculpting" },
		{ "Comment", "// Using a Queue to update TerrainSection is more performant but causes gaps on borders\n" },
		{ "ModuleRelativePath", "TerrainEditorStuff.h" },
		{ "ToolTip", "Using a Queue to update TerrainSection is more performant but causes gaps on borders" },
	};
#endif
	void Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_bUseUpdateQueue_SetBit(void* Obj)
	{
		((FSculptSettings*)Obj)->bUseUpdateQueue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_bUseUpdateQueue = { "bUseUpdateQueue", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FSculptSettings), &Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_bUseUpdateQueue_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_bUseUpdateQueue_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_bUseUpdateQueue_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_Falloff_MetaData[] = {
		{ "Category", "Sculpting" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "Comment", "// Distance falloff from center of sculpt location\n" },
		{ "ModuleRelativePath", "TerrainEditorStuff.h" },
		{ "ToolTip", "Distance falloff from center of sculpt location" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_Falloff = { "Falloff", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSculptSettings, Falloff), METADATA_PARAMS(Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_Falloff_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_Falloff_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_ToolStrength_MetaData[] = {
		{ "Category", "Sculpting" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "Comment", "// Strength of the tool. 0 = min, 1 = max. (Max Value is defined in Terrain Generator)\n" },
		{ "ModuleRelativePath", "TerrainEditorStuff.h" },
		{ "ToolTip", "Strength of the tool. 0 = min, 1 = max. (Max Value is defined in Terrain Generator)" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_ToolStrength = { "ToolStrength", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSculptSettings, ToolStrength), METADATA_PARAMS(Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_ToolStrength_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_ToolStrength_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_SculptRadius_MetaData[] = {
		{ "Category", "Sculpting" },
		{ "Comment", "// Defines affected Vertices\n" },
		{ "ModuleRelativePath", "TerrainEditorStuff.h" },
		{ "ToolTip", "Defines affected Vertices" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_SculptRadius = { "SculptRadius", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSculptSettings, SculptRadius), METADATA_PARAMS(Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_SculptRadius_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_SculptRadius_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_bInvertToolDirection_MetaData[] = {
		{ "Category", "Sculpting" },
		{ "Comment", "// Invert direction for some tools (raise, lower).\n" },
		{ "ModuleRelativePath", "TerrainEditorStuff.h" },
		{ "ToolTip", "Invert direction for some tools (raise, lower)." },
	};
#endif
	void Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_bInvertToolDirection_SetBit(void* Obj)
	{
		((FSculptSettings*)Obj)->bInvertToolDirection = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_bInvertToolDirection = { "bInvertToolDirection", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FSculptSettings), &Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_bInvertToolDirection_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_bInvertToolDirection_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_bInvertToolDirection_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_SculptMode_MetaData[] = {
		{ "Category", "Sculpting" },
		{ "Comment", "// Select Tool\n" },
		{ "ModuleRelativePath", "TerrainEditorStuff.h" },
		{ "ToolTip", "Select Tool" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_SculptMode = { "SculptMode", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSculptSettings, SculptMode), Z_Construct_UEnum_TwistedGrounds_ESculptMode, METADATA_PARAMS(Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_SculptMode_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_SculptMode_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_SculptMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSculptSettings_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_NoiseScale,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_ColorTargetLayerStrength,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_bUseColorTargetLayer,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_Color,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_bUseUpdateQueue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_Falloff,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_ToolStrength,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_SculptRadius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_bInvertToolDirection,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_SculptMode,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSculptSettings_Statics::NewProp_SculptMode_Underlying,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSculptSettings_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_TwistedGrounds,
		nullptr,
		&NewStructOps,
		"SculptSettings",
		sizeof(FSculptSettings),
		alignof(FSculptSettings),
		Z_Construct_UScriptStruct_FSculptSettings_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSculptSettings_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FSculptSettings_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSculptSettings_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSculptSettings()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FSculptSettings_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_TwistedGrounds();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("SculptSettings"), sizeof(FSculptSettings), Get_Z_Construct_UScriptStruct_FSculptSettings_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FSculptSettings_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FSculptSettings_Hash() { return 950702583U; }
class UScriptStruct* FSectionProperties::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern TWISTEDGROUNDS_API uint32 Get_Z_Construct_UScriptStruct_FSectionProperties_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FSectionProperties, Z_Construct_UPackage__Script_TwistedGrounds(), TEXT("SectionProperties"), sizeof(FSectionProperties), Get_Z_Construct_UScriptStruct_FSectionProperties_Hash());
	}
	return Singleton;
}
template<> TWISTEDGROUNDS_API UScriptStruct* StaticStruct<FSectionProperties>()
{
	return FSectionProperties::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FSectionProperties(FSectionProperties::StaticStruct, TEXT("/Script/TwistedGrounds"), TEXT("SectionProperties"), false, nullptr, nullptr);
static struct FScriptStruct_TwistedGrounds_StaticRegisterNativesFSectionProperties
{
	FScriptStruct_TwistedGrounds_StaticRegisterNativesFSectionProperties()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("SectionProperties")),new UScriptStruct::TCppStructOps<FSectionProperties>);
	}
} ScriptStruct_TwistedGrounds_StaticRegisterNativesFSectionProperties;
	struct Z_Construct_UScriptStruct_FSectionProperties_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SectionPosition_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_SectionPosition;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_SectionPosition_Inner;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_SectionPosition_Inner_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Triangles_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Triangles;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Triangles_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VertexColors_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_VertexColors;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_VertexColors_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Normals_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Normals;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Normals_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_UV_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_UV;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_UV_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Vertices_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Vertices;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Vertices_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSectionProperties_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "// Struct that constains necessary Vertex information of a single section\n" },
		{ "ModuleRelativePath", "TerrainEditorStuff.h" },
		{ "ToolTip", "Struct that constains necessary Vertex information of a single section" },
	};
#endif
	void* Z_Construct_UScriptStruct_FSectionProperties_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSectionProperties>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSectionProperties_Statics::NewProp_SectionPosition_MetaData[] = {
		{ "Category", "Struct" },
		{ "ModuleRelativePath", "TerrainEditorStuff.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FSectionProperties_Statics::NewProp_SectionPosition = { "SectionPosition", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSectionProperties, SectionPosition), METADATA_PARAMS(Z_Construct_UScriptStruct_FSectionProperties_Statics::NewProp_SectionPosition_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSectionProperties_Statics::NewProp_SectionPosition_MetaData)) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FSectionProperties_Statics::NewProp_SectionPosition_Inner = { "SectionPosition", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UEnum_TwistedGrounds_ESectionPosition, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FSectionProperties_Statics::NewProp_SectionPosition_Inner_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSectionProperties_Statics::NewProp_Triangles_MetaData[] = {
		{ "Category", "Struct" },
		{ "ModuleRelativePath", "TerrainEditorStuff.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FSectionProperties_Statics::NewProp_Triangles = { "Triangles", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSectionProperties, Triangles), METADATA_PARAMS(Z_Construct_UScriptStruct_FSectionProperties_Statics::NewProp_Triangles_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSectionProperties_Statics::NewProp_Triangles_MetaData)) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSectionProperties_Statics::NewProp_Triangles_Inner = { "Triangles", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSectionProperties_Statics::NewProp_VertexColors_MetaData[] = {
		{ "Category", "Struct" },
		{ "Comment", "// TODO remember to store vertexcolor in global vert data\n" },
		{ "ModuleRelativePath", "TerrainEditorStuff.h" },
		{ "ToolTip", "TODO remember to store vertexcolor in global vert data" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FSectionProperties_Statics::NewProp_VertexColors = { "VertexColors", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSectionProperties, VertexColors), METADATA_PARAMS(Z_Construct_UScriptStruct_FSectionProperties_Statics::NewProp_VertexColors_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSectionProperties_Statics::NewProp_VertexColors_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSectionProperties_Statics::NewProp_VertexColors_Inner = { "VertexColors", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSectionProperties_Statics::NewProp_Normals_MetaData[] = {
		{ "Category", "Struct" },
		{ "ModuleRelativePath", "TerrainEditorStuff.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FSectionProperties_Statics::NewProp_Normals = { "Normals", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSectionProperties, Normals), METADATA_PARAMS(Z_Construct_UScriptStruct_FSectionProperties_Statics::NewProp_Normals_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSectionProperties_Statics::NewProp_Normals_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSectionProperties_Statics::NewProp_Normals_Inner = { "Normals", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSectionProperties_Statics::NewProp_UV_MetaData[] = {
		{ "Category", "Struct" },
		{ "ModuleRelativePath", "TerrainEditorStuff.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FSectionProperties_Statics::NewProp_UV = { "UV", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSectionProperties, UV), METADATA_PARAMS(Z_Construct_UScriptStruct_FSectionProperties_Statics::NewProp_UV_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSectionProperties_Statics::NewProp_UV_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSectionProperties_Statics::NewProp_UV_Inner = { "UV", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSectionProperties_Statics::NewProp_Vertices_MetaData[] = {
		{ "Category", "Struct" },
		{ "ModuleRelativePath", "TerrainEditorStuff.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FSectionProperties_Statics::NewProp_Vertices = { "Vertices", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSectionProperties, Vertices), METADATA_PARAMS(Z_Construct_UScriptStruct_FSectionProperties_Statics::NewProp_Vertices_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSectionProperties_Statics::NewProp_Vertices_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSectionProperties_Statics::NewProp_Vertices_Inner = { "Vertices", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSectionProperties_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSectionProperties_Statics::NewProp_SectionPosition,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSectionProperties_Statics::NewProp_SectionPosition_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSectionProperties_Statics::NewProp_SectionPosition_Inner_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSectionProperties_Statics::NewProp_Triangles,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSectionProperties_Statics::NewProp_Triangles_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSectionProperties_Statics::NewProp_VertexColors,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSectionProperties_Statics::NewProp_VertexColors_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSectionProperties_Statics::NewProp_Normals,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSectionProperties_Statics::NewProp_Normals_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSectionProperties_Statics::NewProp_UV,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSectionProperties_Statics::NewProp_UV_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSectionProperties_Statics::NewProp_Vertices,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSectionProperties_Statics::NewProp_Vertices_Inner,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSectionProperties_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_TwistedGrounds,
		nullptr,
		&NewStructOps,
		"SectionProperties",
		sizeof(FSectionProperties),
		alignof(FSectionProperties),
		Z_Construct_UScriptStruct_FSectionProperties_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSectionProperties_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FSectionProperties_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSectionProperties_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSectionProperties()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FSectionProperties_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_TwistedGrounds();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("SectionProperties"), sizeof(FSectionProperties), Get_Z_Construct_UScriptStruct_FSectionProperties_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FSectionProperties_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FSectionProperties_Hash() { return 1783178586U; }
class UScriptStruct* FVertexData::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern TWISTEDGROUNDS_API uint32 Get_Z_Construct_UScriptStruct_FVertexData_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FVertexData, Z_Construct_UPackage__Script_TwistedGrounds(), TEXT("VertexData"), sizeof(FVertexData), Get_Z_Construct_UScriptStruct_FVertexData_Hash());
	}
	return Singleton;
}
template<> TWISTEDGROUNDS_API UScriptStruct* StaticStruct<FVertexData>()
{
	return FVertexData::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FVertexData(FVertexData::StaticStruct, TEXT("/Script/TwistedGrounds"), TEXT("VertexData"), false, nullptr, nullptr);
static struct FScriptStruct_TwistedGrounds_StaticRegisterNativesFVertexData
{
	FScriptStruct_TwistedGrounds_StaticRegisterNativesFVertexData()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("VertexData")),new UScriptStruct::TCppStructOps<FVertexData>);
	}
} ScriptStruct_TwistedGrounds_StaticRegisterNativesFVertexData;
	struct Z_Construct_UScriptStruct_FVertexData_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VertexColor_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_VertexColor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Normals_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Normals;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_UV_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_UV;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Vertices_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Vertices;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVertexData_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "// Struct that constains global Vertex information\n" },
		{ "ModuleRelativePath", "TerrainEditorStuff.h" },
		{ "ToolTip", "Struct that constains global Vertex information" },
	};
#endif
	void* Z_Construct_UScriptStruct_FVertexData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FVertexData>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVertexData_Statics::NewProp_VertexColor_MetaData[] = {
		{ "Category", "Struct" },
		{ "ModuleRelativePath", "TerrainEditorStuff.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FVertexData_Statics::NewProp_VertexColor = { "VertexColor", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FVertexData, VertexColor), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(Z_Construct_UScriptStruct_FVertexData_Statics::NewProp_VertexColor_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVertexData_Statics::NewProp_VertexColor_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVertexData_Statics::NewProp_Normals_MetaData[] = {
		{ "Category", "Struct" },
		{ "ModuleRelativePath", "TerrainEditorStuff.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FVertexData_Statics::NewProp_Normals = { "Normals", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FVertexData, Normals), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FVertexData_Statics::NewProp_Normals_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVertexData_Statics::NewProp_Normals_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVertexData_Statics::NewProp_UV_MetaData[] = {
		{ "Category", "Struct" },
		{ "ModuleRelativePath", "TerrainEditorStuff.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FVertexData_Statics::NewProp_UV = { "UV", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FVertexData, UV), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UScriptStruct_FVertexData_Statics::NewProp_UV_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVertexData_Statics::NewProp_UV_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVertexData_Statics::NewProp_Vertices_MetaData[] = {
		{ "Category", "Struct" },
		{ "ModuleRelativePath", "TerrainEditorStuff.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FVertexData_Statics::NewProp_Vertices = { "Vertices", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FVertexData, Vertices), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FVertexData_Statics::NewProp_Vertices_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVertexData_Statics::NewProp_Vertices_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FVertexData_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVertexData_Statics::NewProp_VertexColor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVertexData_Statics::NewProp_Normals,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVertexData_Statics::NewProp_UV,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVertexData_Statics::NewProp_Vertices,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FVertexData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_TwistedGrounds,
		nullptr,
		&NewStructOps,
		"VertexData",
		sizeof(FVertexData),
		alignof(FVertexData),
		Z_Construct_UScriptStruct_FVertexData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVertexData_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FVertexData_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVertexData_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FVertexData()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FVertexData_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_TwistedGrounds();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("VertexData"), sizeof(FVertexData), Get_Z_Construct_UScriptStruct_FVertexData_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FVertexData_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FVertexData_Hash() { return 2561470748U; }
	void ATerrainEditorStuff::StaticRegisterNativesATerrainEditorStuff()
	{
	}
	UClass* Z_Construct_UClass_ATerrainEditorStuff_NoRegister()
	{
		return ATerrainEditorStuff::StaticClass();
	}
	struct Z_Construct_UClass_ATerrainEditorStuff_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATerrainEditorStuff_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_TwistedGrounds,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATerrainEditorStuff_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "TerrainEditorStuff.h" },
		{ "ModuleRelativePath", "TerrainEditorStuff.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATerrainEditorStuff_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATerrainEditorStuff>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ATerrainEditorStuff_Statics::ClassParams = {
		&ATerrainEditorStuff::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ATerrainEditorStuff_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ATerrainEditorStuff_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ATerrainEditorStuff()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ATerrainEditorStuff_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ATerrainEditorStuff, 3962124289);
	template<> TWISTEDGROUNDS_API UClass* StaticClass<ATerrainEditorStuff>()
	{
		return ATerrainEditorStuff::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ATerrainEditorStuff(Z_Construct_UClass_ATerrainEditorStuff, &ATerrainEditorStuff::StaticClass, TEXT("/Script/TwistedGrounds"), TEXT("ATerrainEditorStuff"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATerrainEditorStuff);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
