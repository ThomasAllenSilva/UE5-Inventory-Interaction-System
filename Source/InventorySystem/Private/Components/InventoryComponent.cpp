// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/InventoryComponent.h"
#include "Data/DataAsset_InventoryItem.h"

UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	PrimaryComponentTick.bStartWithTickEnabled = false;
}

bool UInventoryComponent::TryAddInventoryItem(const UDataAsset_InventoryItem* Item)
{
	if (HasSlotFree())
	{
		CurrentInventoryItems.Add(Item);

		OnAddedInventoryItem.Broadcast(Item);

		return true;
	}

	return false;
}

void UInventoryComponent::RemoveInventoryItem(const UDataAsset_InventoryItem* Item)
{
	int itemsCountRemoved = CurrentInventoryItems.RemoveSingle(Item);

	if (itemsCountRemoved > 0)
	{
		OnRemovedInventoryItem.Broadcast(Item);
	}
}

bool UInventoryComponent::HasSlotFree() const
{
	return CurrentInventoryItems.Num() < InventorySlotsCapacity;
}
