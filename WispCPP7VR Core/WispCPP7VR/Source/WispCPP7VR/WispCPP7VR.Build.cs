// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class WispCPP7VR : ModuleRules
{
	public WispCPP7VR(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

	
		PublicDependencyModuleNames.AddRange(new string[] {  "Core",
                "CoreUObject",
                "Engine",
                "InputCore",
                "EnhancedInput",
                "Json",
                "JsonUtilities",
                "GameplayTags",
                "Niagara",           // <--- ADD THIS
                "NavigationSystem",  // Recommended for your AI/Dragons
                "AIModule",           // Recommended for your Entity logic
                "UMG", });

        // Modules that should ONLY be included when building for the Editor
        if (Target.Type == TargetType.Editor)
        {
            PublicDependencyModuleNames.AddRange(
                new string[]
                {
                    "AssetTools",
                    "UnrealEd"
                }
            );
        }
	}
}
