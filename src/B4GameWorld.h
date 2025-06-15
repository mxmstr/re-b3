#pragma once

// Placeholder for whatever is at offset 11272 in the original player car structure
// For now, let's assume it's some kind of identifiable pointer or value.
// The actual structure of PlayerCar is unknown.
struct PlayerCarPlaceholder {
    // This is a placeholder for the data that GetNetworkCollBodyType expects to compare.
    // It was originally accessed like `gWorld.m_aPlayerCars[0][11272]`
    // This might be a pointer to some physics object or a unique ID.
    // Let's use void* as a generic placeholder type.
    void* pPhysicsObjectIdentifier; // Placeholder for the value compared

    // Add a large buffer to represent other potential data, to make the offset valid if it were direct.
    // However, the [0][11272] is more likely a pointer dereference then offset.
    // For now, this field isn't directly used by B4ActiveBody, only pPhysicsObjectIdentifier is.
    // char other_data[12000]; // This might not be the correct way to model it.

    PlayerCarPlaceholder() : pPhysicsObjectIdentifier(nullptr) {}
};

struct GameWorld {
    long long m_CrashScore[2048]; // Accessed up to index 1048
    PlayerCarPlaceholder m_aPlayerCars[2]; // Accessed indices 0 and 1

    GameWorld() {
        for(int i = 0; i < 2048; ++i) m_CrashScore[i] = 0;
        // m_aPlayerCars will be default constructed
    }
};

extern GameWorld gWorld;
