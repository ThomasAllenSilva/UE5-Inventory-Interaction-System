// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/CollectableItem.h"
#include "Components/InventoryComponent.h"
#include "Interfaces/InventoryInterface.h"

ACollectableItem::ACollectableItem()
{
	PrimaryActorTick.bCanEverTick = true;

	PrimaryActorTick.bStartWithTickEnabled = false;
}

void ACollectableItem::Interact_Implementation(AActor* InteractionInstigator)
{
	UInventoryComponent* InventoryComponent = IInventoryInterface::Execute_GetInventoryComponent(InteractionInstigator);

	bool bAddedSuccessfully = InventoryComponent->TryAddInventoryItem(ItemData);

	if (bAddedSuccessfully)
	{
		Destroy();
	}
}
