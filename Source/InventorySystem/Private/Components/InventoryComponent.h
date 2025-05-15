// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

class UDataAsset_InventoryItem;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInventoryItemSignature, const UDataAsset_InventoryItem*, InventoryItem);


/*
* Component that holds information about items being carried by an Actor, acting as an inventory.
* It also contains helper functions and events that can be used in blueprints.
*/
UCLASS(ClassGroup = (Inventory), meta = (BlueprintSpawnableComponent))
class UInventoryComponent final : public UActorComponent
{
	GENERATED_BODY()

public:
	UInventoryComponent();

	/**
	 * Attempt to add an inventory item.
	 * It first checks if the inventory is not full before adding the item.
	 * @param	Item: The item to be added.
	 * @return true if the item was added successfully
	 */
	bool TryAddInventoryItem(const UDataAsset_InventoryItem* Item);

	/* Removes the first item found using the specified item. */
	UFUNCTION(BlueprintCallable)
	void RemoveInventoryItem(const UDataAsset_InventoryItem* Item);

	/* Returns true if there's at least one free slot in the inventory */
	UFUNCTION(BlueprintCallable)
	bool HasSlotFree() const;

	/* Event triggered when an item is added to the inventory */
	UPROPERTY(BlueprintAssignable)
	FInventoryItemSignature OnAddedInventoryItem;

	/* Event triggered when an item is removed from the inventory */
	UPROPERTY(BlueprintAssignable)
	FInventoryItemSignature OnRemovedInventoryItem;

private:
	/* The maximum amount of different items we can carry. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess))
	int InventorySlotsCapacity;

	/* The current items that we have*/
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess))
	TArray<const UDataAsset_InventoryItem*> CurrentInventoryItems; //Simple array of items. In a more advanced project I recommend using a map with gameplay tags
};
