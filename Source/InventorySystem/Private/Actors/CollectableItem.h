// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/InteractableInterface.h"

#include "CollectableItem.generated.h"

class UDataAsset_InventoryItem;

/*
* An Actor that can be collected and added to another Actor's inventory
*/
UCLASS()
class ACollectableItem final : public AActor, public IInteractableInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACollectableItem();

	//~ Begin Interactable Interface

	void Interact_Implementation(AActor* InteractionInstigator);

	//~ End of Interactable Interface

private:

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UDataAsset_InventoryItem> ItemData;
};
