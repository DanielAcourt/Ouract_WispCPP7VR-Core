# Blueprint Migration Guide for the Sovereign Soul Architecture

This guide outlines the necessary steps to migrate existing Blueprints and C++ classes from the old inheritance-based system to the new composition-based "Sovereign Soul" architecture. This is a one-time process that is essential for ensuring all entities in the world are compatible with the new, more flexible system.

---

### Phase 1: Migrating Inanimate Objects (Rocks, Seeds, Items, etc.)

These are Blueprints that represent static or simple interactive objects. They should no longer be based on `ACharacter`.

**New Base Class:** `ASovereignBaseInteractable`

**Checklist for each Blueprint:**

1.  **Open the Blueprint.**
2.  **Go to File -> Reparent Blueprint.**
3.  **Select `SovereignBaseInteractable` as the new parent class.**
4.  **Delete the old `SovereignSaveableEntityComponent`:** In the Components tab, find the old `SovereignSaveableEntityComponent` and delete it. The new base class already includes the "Soul" component.
5.  **Remove the Skeletal Mesh Component:** If the Blueprint has a `SkeletalMeshComponent`, delete it.
6.  **Add a `StaticMeshComponent`:** If the Blueprint does not already have a `StaticMeshComponent`, add one now. This will be the primary visual representation of the object.
7.  **Compile and Save.**

---

### Phase 2: Migrating the Player Wisp

The player Wisp has a new, more lightweight base class.

**New Base Class:** `ASovereignPawn`

**Checklist for the Wisp Blueprint:**

1.  **Open the Wisp Blueprint.**
2.  **Go to File -> Reparent Blueprint.**
3.  **Select `SovereignPawn` as the new parent class.**
4.  **Delete the old `SovereignSaveableEntityComponent`:** The new base class already includes the "Soul" component.
5.  **Configure the `FloatingPawnMovement` component:** The new base class has a `FloatingPawnMovement` component. You will need to adjust its settings (e.g., `MaxSpeed`, `Acceleration`, `Deceleration`) to match the desired feel of the Wisp's movement.
6.  **Compile and Save.**

---

### Phase 3: Migrating Characters (Animals, NPCs, etc.)

These are Blueprints that represent sentient, mobile entities. They will remain based on `ACharacter`, but we need to update them to use the new "Soul" component.

**Base Class:** `ASovereignBaseCharacter` (No change)

**Checklist for each C++ Character Class:**

1.  **Open the `.h` file.**
2.  **Change the base class from `ASovereignBaseInteractable` to `ACharacter`.**
3.  **Add `ISovereignEntityInterface` to the class declaration.**
4.  **Remove the old component pointers (`USovereignAttributeComponent`, `USovereignQiComponent`, etc.).**
5.  **Add a `USovereignSaveableEntityComponent* SovereignSoul;`**
6.  **Declare the `ISovereignEntityInterface` functions:**
    ```cpp
    virtual USovereignSaveableEntityComponent* GetSovereignSoul() const override;
    virtual UMeshComponent* GetPrimaryMesh() const override;
    virtual void OnPossessedByWisp(AController* WispController) override;
    virtual void OnUnpossessedByWisp() override;
    ```
7.  **Open the `.cpp` file.**
8.  **Update the constructor to create the `SovereignSoul` component.**
9.  **Implement the `ISovereignEntityInterface` functions.**

**Checklist for each Character Blueprint:**

1.  **Open the Blueprint.**
2.  **Delete the old `SovereignSaveableEntityComponent`:** The C++ base class now includes the "Soul" component, so the old one can be removed from the Blueprint.
3.  **Compile and Save.**

---

**Important Notes:**

*   **Backup your project before beginning this process.**
*   **Migrate one Blueprint at a time and test it to ensure it is working correctly before moving on to the next one.**
*   **If you encounter any issues, refer to the `Sovereign_Tenant.md` document for a detailed explanation of the new architecture.**
