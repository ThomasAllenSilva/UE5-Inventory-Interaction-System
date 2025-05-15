// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractableInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInteractableInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface used for communication with interactable objects
 */
class IInteractableInterface
{
	GENERATED_BODY()

public:

	/* Called before an interaction happens to validate if it's a valid interaction or if the object is ready.
	 * @param	InteractionInstigator: The actor that is trying to interact with this object.
	 */
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	bool CanInteract(AActor* InteractionInstigator) const;

	/* 
	 * Called when this interactable object was focused by another actor (usually the player with the interaction trigger). 
	 * @param	InteractionInstigator: The actor that started focusing this object.
	 */
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void OnFocused(AActor* InteractionInstigator);

	/* 
	 * Called when this interactable object was focused by another actor (usually the player with the interaction trigger). 
	 * @param	InteractionInstigator: The actor stopped focusing this object.
	 */
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void OnUnfocused(AActor* InteractionInstigator);

	/**
	 * Called when an interaction is triggered by an actor.
	 * This function can be implemented in Blueprints to define specific interaction behavior.
	 * @param	InteractionInstigator: The actor that started the interaction.
	 */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Interact(AActor* InteractionInstigator);
};
