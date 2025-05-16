# Inventory/Interaction System

##### Table of Contents  

[How It Works](#how-it-works)

[How To Test](#how-to-test)

# How It Works
[Common Framework](#common-framework)

[Inventory Component](#inventory-component)

[Interaction Trigger Component](#interaction-trigger-component)

# Common Framework
This is a C++ plugin that I made and reuse in my own projects. It basically contains C++ files that help reuse logic across games. The use case here was to help with widget manipulation.

For example, I created a WidgetDefinition for the player and added it to the WidgetCreator component. This way, I can define the default initialization settings and also set a layer. The concept of widget layers is a bit more advanced, but it essentially helps group widgets.

In this project, the widgets related to the player have their own layer. When you trigger a dialogue interaction, it hides the player widget layer, removing all the widgets from the screen to display only the dialogue. This is done using a Subsystem, which allows for flexibility in Blueprints.

The widgets also have their own tag, allowing you to retrieve them from the cached TMap and manipulate them.

![image](https://github.com/user-attachments/assets/8398b01d-8ee3-4223-809d-c309760754b0)

# Inventory Component
UActorComponent that stores information about items collected by the Player. It has information about the maximum capacity and the Current Inventory Items stored in this component. This information is used to display the inventory widget. It also have events for when an item is added or removed.

# Interaction Trigger Component
UBoxComponent used to identify actors that implements the IInteractableInterface. It serves the purpose of sending events to the interactable object when it's focused and unfocused. These events are used to display widgets inside the world. When the interaction input is pressed, it starts the interaction with the 'Current Focused Interactable Actor'.

# Interactable Interface
This can be implemented by any Actor that you wish to have a sort of interaction. There's two interactions type in this project: Dialogue & Collectable Item. They both use this same interface, implementing their own logic.

# How To Test
Test2
