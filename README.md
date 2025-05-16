# Inventory/Interaction System

##### Table of Contents  

[How It Works](#how-it-works)

[How To Test](#how-to-test)

# How It Works
[Inventory Component](#inventory-component)

[Interaction Trigger Component](#interaction-trigger-component)

# Inventory Component
UActorComponent that stores info about items collected by the [Interaction Trigger Component](#interaction-trigger-component). It has information about the maximum capacity and the Current Inventory Items stored in this component. This information is used to display the inventory widget. It also have events for when an item is added or removed.

# Interaction Trigger Component
UBoxComponent used to identify actors that implements the IInteractableInterface. It serves the purpose of sending events to the interactable object when it's focused and unfocused. These events are used to display widgets inside the world. When the interaction input is pressed, it starts the interaction with the 'Current Focused Interactable Actor'.

# Interactable Interface


# How To Test
Test2
