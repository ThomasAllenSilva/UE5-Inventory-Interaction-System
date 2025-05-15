// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/InteractionTriggerComponent.h"
#include "Interfaces/InteractableInterface.h"

void UInteractionTriggerComponent::BeginPlay()
{
	Super::BeginPlay();

	OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnTriggerBeginOverlap);

	OnComponentEndOverlap.AddDynamic(this, &ThisClass::OnTriggerEndOverlap);
}

void UInteractionTriggerComponent::BeginDestroy()
{
	Super::BeginDestroy();
	
	OnComponentBeginOverlap.RemoveDynamic(this, &ThisClass::OnTriggerBeginOverlap);

	OnComponentEndOverlap.RemoveDynamic(this, &ThisClass::OnTriggerEndOverlap);
}

void UInteractionTriggerComponent::OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->GetClass()->ImplementsInterface(UInteractableInterface::StaticClass()))
	{
		CurrentFocusedInteractableActor = OtherActor;

		IInteractableInterface::Execute_OnFocused(CurrentFocusedInteractableActor, GetOwner());
	}
}

void UInteractionTriggerComponent::OnTriggerEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor->GetClass()->ImplementsInterface(UInteractableInterface::StaticClass()))
	{
		if (CurrentFocusedInteractableActor == OtherActor)
		{
			CurrentFocusedInteractableActor = nullptr;
		}

		IInteractableInterface::Execute_OnUnfocused(OtherActor, GetOwner());
	}
}
