// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CPP_Moving_Floor_Library.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPLAY_WORKSHOP_API UCPP_Moving_Floor_Library : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	// Raise or lower Moving Floor Component based on the current Player position
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CPP Update Component"), Category = "BP_Moving_Floor_Component_Actor")
	static void UpdateMovingFloorComponent(UStaticMeshComponent* FloorComponent,
		const APawn* CurrentPlayerPawn,
		const float HeightMax,
		const float HeightMin,
		const float Range);
};
