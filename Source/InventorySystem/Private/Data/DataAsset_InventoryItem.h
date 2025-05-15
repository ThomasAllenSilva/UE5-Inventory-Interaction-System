// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_InventoryItem.generated.h"

/**
* Defines a preview type for this item to be used in the inventory system
*/
UENUM(BlueprintType)
enum class EItemPreviewType : uint8
{
	//  It will display a 2D preview
	Texture,

	//  It will display a 3D Model, allowing it to rotate and zoom in
	Model
};

/**
 * Configurations used by the item to be displayed in the inventory system
 */
UCLASS(BlueprintType)
class UDataAsset_InventoryItem final : public UDataAsset
{
	GENERATED_BODY()
	
private:
	/* The display name of this item. This is the name the player will see in the inventory. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess))
	FName Name;

	/* Defines how this item should be previewed inside the inventory window. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess))
	EItemPreviewType SlotPreviewType = EItemPreviewType::Texture;

	/* The texture used to display this item inside the inventory slot. NOTE: If the 'SlotPreviewType' is set to 'Texture' it will use this variable value to display the item preview. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess))
	TObjectPtr<UTexture2D> Texture;

	/* The Mesh used to display this item inside the inventory slot as a 3D Model. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess, EditCondition = "SlotPreviewType == EItemPreviewType::Model"))
	TObjectPtr<USkeletalMesh> SkeletalMeshPreview;
};
