// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "InteractionTriggerComponent.generated.h"

class IInteractableInterface;

/**
 * Used to identify and trigger interactions
 */
UCLASS(Blueprintable)
class UInteractionTriggerComponent final : public UBoxComponent
{
	GENERATED_BODY()
	
public:
	//~ Begin UObject Interface.

	virtual void BeginDestroy() override;

	virtual void BeginPlay() override;

	//~ End UObject Interface.

private:
    UFUNCTION()
	void OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    UFUNCTION()
	void OnTriggerEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

private:
	/* The current overlaped available interactable actor that we can interacted with */
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess))
	TObjectPtr<AActor> CurrentFocusedInteractableActor;
};
