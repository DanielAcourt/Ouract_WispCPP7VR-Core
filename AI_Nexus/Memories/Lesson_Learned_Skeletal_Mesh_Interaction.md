// Copyright (c) 2013-2025 Daniel Acourt. Version 36.4.7. Licensed under GPLv3 (See LICENSE). Last Updated: 2025-06-03
# Lesson Learned: Skeletal Mesh Interaction & Possession

## 🔍 The Problem
Skeletal Meshes (used in `ASovereignBaseCharacter` and children like Dragons/Orcs) often appear "un-interactable" to the Wisp's traces, even if they implement the `IInteractionInterface`.

## 🛠️ The Root Causes (Physical Truth)
1.  **Missing Physics Asset:** Unlike Static Meshes (which have built-in simple collision), Skeletal Meshes rely on a **Physics Asset (.phys)** to define their hitboxes. If no Physics Asset is assigned, the Wisp's `LineTrace` or `SphereTrace` passes right through the bones.
2.  **Collision Channel Mismatch:** The Wisp typically traces on the `Visibility` or `Pawn` channels. Many Skeletal Meshes default to "CharacterMesh" collision, which might ignore these channels.
3.  **Root Component Shadowing:** If the `CapsuleComponent` is too large, it might "block" the trace before it ever reaches the mesh, or if the Mesh is not set to "Query," it won't return a hit.

## 📐 The "How-To" for Blueprints
To make a Skeletal Mesh interactable/possessable:

1.  **Assign a Physics Asset:** Open the Skeletal Mesh and ensure a Physics Asset is created and assigned. This creates the "Collision Bodies" for the bones.
2.  **Set Collision Profile:** On the Mesh component in the Blueprint:
    *   Set **Collision Presets** to `Custom`.
    *   Set **Collision Enabled** to `Query Only` (or `Query and Physics`).
    *   Ensure **Visibility** and **Pawn** channels are set to `Block`.
3.  **Interface Implementation:**
    *   Ensure the Blueprint Class Settings include `IInteractionInterface`.
    *   Implement `CanBePossessed` (returning true).
    *   Implement `GetPossessionAttachmentComponent` (returning the Mesh component).
4.  **Trace Verification:** Use `DrawDebugTrace` on the Wisp to see if the red/green hit sphere is actually stopping on the mesh.

## 🎖️ The Sovereign Standard
All "Master Vessels" using skeletal meshes must undergo a **Physics Audit** during creation to ensure the spirit can find a surface to inhabit.
