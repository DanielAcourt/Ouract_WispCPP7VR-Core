#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SovereignEntityInterface.generated.h"

//Forward Declaration
class USovereignSaveableEntityComponent;
//class UStaticMeshComponent;

// 1. The U-Class (The Engine's "Social Security Number" for the interface)
//UINTERFACE(MinimalAPI, Blueprintable)
class  USovereignEntityInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 2. The I-Class (The actual Contract/Interface)
 * This is where you define the functions.
 */

class WISPCPP7VR_API ISovereignEntityInterface
{
	GENERATED_BODY()

public:

	/** * Returns the "Sovereign Soul" component.
		 * This is the 'One Sense of Simulated Truth' for ID and Tags.
		 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Sovereign|Interface")
	USovereignSaveableEntityComponent* GetSovereignSoul() const;

	/** * Universal Interaction Command.
	 * Replaces the old InteractionInterface logic.
	 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Sovereign|Interface")
	void OnSovereignInteract(AActor* Interactor);

	/** * Handshake for Possession.
	 * Allows the Wisp to 'inhabit' any AActor that has this interface.
	 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Sovereign|Interface")
	void OnWispPossess(AController* WispController);

	/** Handshake for Unpossession. */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Sovereign|Interface")
	void OnWispUnpossess();

	//Function For pickup

	//Function For consume?

	//Function for Equip

};


//Context for this Interface
/*What is the Interaction Interface?
Think of the Interface as a "Universal Plug."

In your garden, you have many different types of objects:

Rocks (Static Mesh)

Flowers (Emitters/Physics)

Erisis/Player (An NPC/Skeletal Mesh)

Tools (Equippable items)

Without an interface, your Player Character would have to ask a million questions: "Are you a rock? If so, run the PickUp function. Are you Erisis? If so, run the Talk function." This makes your code messy and hard to maintain.

With the Interaction Interface, the Player just says: "I am touching this Actor. If it speaks the Interaction Language, run the OnInteract function." The Player doesn't care what the object is; they only care that it can be interacted with.

Why is it Header-Only?
Unreal Engine Interfaces are split into two parts within that single .h file:

UInteractionInterface (The Engine Part): This is just metadata for Unreal. It lets the Editor know this interface exists so you can see it in Blueprints.

IInteractionInterface (The C++ Part): This is a list of function signatures.

It defines what the function looks like (e.g., void OnInteract(AActor* Interactor)).

It does not define what the function does.

Because there is no "default" behavior for interacting (interacting with a bomb is different than interacting with a sandwich), there is no code to put in a .cpp. The "definition" is written inside the Actors that implement the interface (like your ABaseInteractable).*/
/*
Intro to your InteractionInterface.h
When you open this file, you should see three main sections:

1. The Generated Include
#include "InteractionInterface.generated.h" This is where the Unreal Header Tool (UHT) injects the "magic" that allows this interface to work with Blueprints and the _Implementation suffix.

2. The UINTERFACE Macro
This marks the class for the engine's reflection system. You almost never touch the code inside this block.

3. The "I" Class (The Contract)
This is where you live. Any function you put in here is a new "word" in your game's language. By adding OnInteract here, you are officially telling your game: "Interaction is now a fundamental rule of this world."

The Big Picture for your 2025 System
Since you are handling unknown tags and a new meta-system, this interface is your "Safe Zone." Even if you create a brand new type of magical plant in six months that the system has never seen before, as long as that plant has this interface, your player will be able to touch it and trigger logic immediately.
*/

