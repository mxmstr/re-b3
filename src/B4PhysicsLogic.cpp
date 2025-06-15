#include "B4PhysicsTypes.h"

// Define the global lookup tables
// Dimensions are based on analysis of decompiled code:
// kaabCanFatal accessed as [10 * type1 + type2], max type is 9 -> 10*9+9 = 99. Size 100.
// kaaePhysicsType accessed as [40 * type1 + 4 * type2], max type is 9 -> 40*9 + 4*9 = 360+36 = 396. Size 400.

bool kaabCanFatal[100];      // Initialized to all false by default for global/static storage
int  kaaePhysicsType[400];   // Initialized to all zero by default for global/static storage

// TODO: These tables should be populated with actual game data.
// For now, they are zero-initialized.
// Example of how one might initialize them if data were known:
// struct Initializer {
//     Initializer() {
//         // kaabCanFatal[10 * static_cast<int>(EActiveBodyType::TypeX) + static_cast<int>(EActiveBodyType::TypeY)] = true;
//         // kaaePhysicsType[40 * static_cast<int>(EActiveBodyType::TypeA) + 4 * static_cast<int>(EActiveBodyType::TypeB)] = SomeInteractionValue;
//     }
// };
// static Initializer run_initializer; // To run code at startup if needed for complex init.
