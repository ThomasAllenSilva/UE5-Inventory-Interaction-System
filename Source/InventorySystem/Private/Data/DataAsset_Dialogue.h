// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_Dialogue.generated.h"

/**
 * Simple dialogue data that represents a unique character speech
 */
UCLASS(BlueprintType)
class UDataAsset_Dialogue final : public UDataAsset
{
	GENERATED_BODY()
	
public: 
	/* Returns the dialogue text located inside the array index */
	UFUNCTION(BlueprintCallable)
	FText GetDialogueAtIndex(const int Index) const;

	UFUNCTION(BlueprintCallable)
	bool IsFinalDialogue(const int Index) const;

private:
	/* The character name to be displayed. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess))
	FText CharacterName;

	/* All the character dialogues. It will be displayed using this array order. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess))
	TArray<FText> Dialogues;
};
