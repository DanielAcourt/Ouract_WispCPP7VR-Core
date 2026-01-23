# Sovereign Tenant Framework (v1.0)

**Project State:** Architectural Pivot (Inheritance to Composition)

**Core Directive:** The world is composed of **Vessels** and **Souls**. A Soul can inhabit any Vessel, granting it identity, vitality, and the potential for interaction. This framework is designed to be modular, scalable, and intuitive for Blueprint developers.

---

### 1. The Core Definitions

#### The Soul (`USovereignSaveableEntityComponent`)
This is the single point of truth for any entity's existence and persistence. It is an `UActorComponent` that can be added to any `AActor`.

*   **Identity:** Manages the entity's unique `FGuid`, its core `GameplayTags`, and any dynamic meta-tags.
*   **Vitality:** Contains all core attributes, including Qi levels, Maturity progress, growth stages, and health. This component is the definitive source for an entity's state.
*   **Persistence:** Handles all data serialization for the save/load system. Any data that needs to be saved must reside within or be managed by the Soul.
*   **Lifecycle:** Manages the `VesselState` (e.g., `Alive`, `Dead`, `Dissolving`). It contains a "Heartbeat" timer that can be used for passive processes like growth, Qi decay, or corpse dissolution.

#### The Bridge (`ISovereignEntityInterface`)
This is the universal C++ "handshake" that allows any game system to communicate with a Sovereign entity without needing to know its specific class (`AActor`, `APawn`, or `ACharacter`).

To be considered a Sovereign entity, an Actor **must** implement this interface.

Key functions provided by the interface:
*   `GetSovereignSoul()`: Returns a pointer to the Soul component. This is the primary entry point for all interactions.
*   `GetPrimaryMesh()`: Returns a pointer to the entity's primary visual representation (`UMeshComponent`). This allows systems to apply visual effects (like highlighting) to both `UStaticMeshComponent` (a rock) and `USkeletalMeshComponent` (a wolf) without casting.
*   `OnPossessedByWisp()` / `OnUnpossessedByWisp()`: These functions form the "Input Bridge," allowing an entity to become controllable by the player, even if it is not a Pawn.

#### The Vessel
A Vessel is any `AActor` in the world that contains a "Soul" component and implements the "Bridge" interface. This design allows for three primary types of Vessels:

*   **`ASovereignBaseInteractable` (based on `AActor`):** For inanimate, non-mobile entities like rocks, seeds, trees, and items. They can be given a Soul and made interactive or even possessable.
*   **`ASovereignPawn` (based on `APawn`):** For simple, mobile entities that do not require complex humanoid animation. The player Wisp uses this as its base.
*   **`ASovereignBaseCharacter` (based on `ACharacter`):** For complex, sentient entities that require a `USkeletalMeshComponent` and the advanced features of the `UCharacterMovementComponent`.

---

### 2. Core Principles for Blueprint Developers

*   **Composition over Inheritance:** Don't ask "what does my object inherit from?"; ask "what components does my object have?" To make a simple static mesh a saveable, interactive entity, simply add the `USovereignSaveableEntityComponent` and implement the `ISovereignEntityInterface`.
*   **The Interface is Law:** All communication between game systems and entities should go through the `ISovereignEntityInterface`. The Wisp's possession trace, the save system, and any other global manager will use this interface to find and interact with entities.
*   **Dynamic Possession:** An object does not need to be a "Character" to be controlled. By implementing the `OnPossessedByWisp` function, even a simple `AActor` can define how it responds to player input, such as by dynamically adding a movement component. This allows for maximum creative freedom in defining how possessable objects behave.
*   **Data Lives in the Soul:** If a variable needs to be saved or is fundamental to the entity's identity (like its health or Qi), it belongs in the `USovereignSaveableEntityComponent`. This ensures data integrity and deterministic saving.
