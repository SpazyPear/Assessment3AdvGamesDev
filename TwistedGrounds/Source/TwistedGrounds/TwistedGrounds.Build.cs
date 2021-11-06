// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TwistedGrounds : ModuleRules
{
	public TwistedGrounds(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "ProceduralMeshComponent", "UMG" });

        PublicDependencyModuleNames.AddRange(new string[] { "RenderCore", "RHI" });

		MinFilesUsingPrecompiledHeaderOverride = 1;
		bFasterWithoutUnity = true;
	}
}
