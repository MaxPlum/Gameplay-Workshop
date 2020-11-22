// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class Gameplay_WorkshopTarget : TargetRules
{
	public Gameplay_WorkshopTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "Gameplay_Workshop" } );
	}
}
