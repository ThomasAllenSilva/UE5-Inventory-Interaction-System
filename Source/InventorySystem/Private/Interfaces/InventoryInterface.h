// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InventoryInterface.generated.h"

class UInventoryComponent;

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInventoryInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface used for retrieving inventory information
 */
class IInventoryInterface
{
	GENERATED_BODY()

public:

	/* Returns the inventory component from the actor that implements this interface. */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	UInventoryComponent* GetInventoryComponent() const;
};
