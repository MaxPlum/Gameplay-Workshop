// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Moving_Floor_Library.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Pawn.h"

// Raise or lower Moving Floor Component based on the current Player position
void UCPP_Moving_Floor_Library::UpdateMovingFloorComponent(UStaticMeshComponent* FloorComponent,
	const APawn* CurrentPlayerPawn,
	const float HeightMax,
	const float HeightMin,
	const float Range)
{
	// Get Moving Floor Component scale and location, as well as Player location
	FVector componentScale = FloorComponent->GetComponentScale();
	FVector loc = FloorComponent->GetComponentLocation();
	FVector playerLoc = CurrentPlayerPawn->GetActorLocation();

	// Set diff as the larger distance (in terms of X or Y) between the Player and Moving Floor Component locations
	float diff = ((abs(loc.X - playerLoc.X) > abs(loc.Y - playerLoc.Y)) ? abs(loc.X - playerLoc.X) : abs(loc.Y - playerLoc.Y));

	// Set the scale used later to the same axis as the diffed distance, then multiply by 50 to convert from scale to location units
	float scale = ((diff == abs(loc.X - playerLoc.X)) ? componentScale.X : componentScale.Y);
	scale *= 50.0f;

	/* Set the height of the Moving Floor Component; HeightMax if Player is on the component,
	   HeightMin if Player is out of Range, and lerp from HeightMax to HeightMin when within Range*/
	if (diff <= scale)
		FloorComponent->SetWorldScale3D(FVector(componentScale.X, componentScale.Y, HeightMax));
	else if (diff > (Range + scale))
		FloorComponent->SetWorldScale3D(FVector(componentScale.X, componentScale.Y, HeightMin));
	else
	{
		float height = ((((Range + scale) - diff) / Range) * (HeightMax - HeightMin)) + HeightMin;
		FloorComponent->SetWorldScale3D(FVector(componentScale.X, componentScale.Y, height));
	}
}