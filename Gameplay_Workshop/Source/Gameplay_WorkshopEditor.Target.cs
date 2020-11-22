// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class Gameplay_WorkshopEditorTarget : TargetRules
{
	public Gameplay_WorkshopEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "Gameplay_Workshop" } );
	}
}
