# Inventory/Interaction System

##### Table of Contents  

[How It Works](#how-it-works)

[How To Test](#how-to-test)

# Summary
An inventory interaction system implemented using C++ and Blueprints. It also includes widgets for displaying inventory content and a tutorial dialogue within the map.

Features:
- Inventory System
- Dialogue Trigger
- Forget Note
- Inventory Drag-and-drop
- Inventory Item preview

# How It Works
[Common Framework](#common-framework)

[Inventory Component](#inventory-component)

[Interaction Trigger Component](#interaction-trigger-component)

# Common Framework
This is a C++ module that I made and reuse in my own projects. It basically contains C++ files that help reuse logic across games. The use case here was to help with widget manipulation.

For example, I created a WidgetDefinition for the player and added it to the WidgetCreator component. This way, I can define the default initialization settings and also set a layer. The concept of widget layers is a bit more advanced, but it essentially helps group widgets.

In this project, the widgets related to the player have their own layer. When you trigger a dialogue interaction, it hides the player widget layer, removing all the widgets from the screen to display only the dialogue. This is done using a Subsystem, which allows for flexibility in Blueprints.

The widgets also have their own tag, allowing you to retrieve them from the cached TMap and manipulate them.

![image](https://github.com/user-attachments/assets/8398b01d-8ee3-4223-809d-c309760754b0)

In this project, there's also a WidgetDefinition for the Dialogue Actor and the collectable items. In the case of the collectable items, they share the same WidgetDefinition, but the configuration is set to use a WidgetComponent instead of adding it to the viewport.

![image](https://github.com/user-attachments/assets/9df017f2-cfde-4ca6-a036-06207d3492ed)

![image](https://github.com/user-attachments/assets/e2f2c60b-52ae-4f89-b187-31c4a2f83450)

This allowed for a very easy implementation of widget display in combination with the [Interactable Interface](#interactable-interface) events.

# Inventory Component
UActorComponent that stores information about items collected by the Player. It has information about the maximum capacity and the Current Inventory Items stored in this component. This information is used to display the inventory widget. It also have events for when an item is added or removed.

# Interaction Trigger Component
UBoxComponent used to identify actors that implements the IInteractableInterface. It serves the purpose of sending events to the interactable object when it's focused and unfocused. These events are used to display widgets inside the world. When the interaction input is pressed, it starts the interaction with the 'Current Focused Interactable Actor'.

# Interactable Interface
This can be implemented by any Actor that you want to have some form of interaction. It receives events for when the object is focused, unfocused, and also when the player wants to interact with it. There are two types of interaction in this project: Dialogue and Collectable Item. They both use the same interface, implementing their own logic.

# Conclusion
These are essentially the core scripts of the project. There are additional scripts as well, and all of them are fully documented in the .h files. But I'll provide a quick description of each one here: 

ACollectableItem: An Actor that can be collected and added to another Actor's inventory. It serves as a base class that contains the item data and a default interaction implementation.

UDataAsset_Dialogue: A simple dialogue data asset that represents a unique character’s speech. It contains information about the character’s dialogue lines and includes helper methods.

UDataAsset_InventoryItem: Configuration data used by items for display in the inventory system. It also determines how an item should appear in the inventory preview.

IInventoryInterface: An interface used for retrieving inventory information.

The rest of the project features implementation was done using Blueprints, which are also fully documented using Blueprints comments.

# How To Test
You can move the character using the W-A-S-D keys, and use the 'E' key to interact with objects. To drag and drop items in the inventory, click and hold with Mouse1, then drag. To drop an item, simply release the mouse button. You can use the same drag operation to rotate the object in the inventory preview, and use the mouse wheel to zoom in and out.

![0](https://github.com/user-attachments/assets/f502021c-b92a-4f9f-870c-1e10f37a2fb9)


![1](https://github.com/user-attachments/assets/d7844f20-bffe-429d-86c2-2e114f79c144)


![2](https://github.com/user-attachments/assets/10750d4a-04cf-4f64-a859-a17dc85e54a9)


![3](https://github.com/user-attachments/assets/5b9c1357-71bb-48e9-abcf-b7809b05e92f)


