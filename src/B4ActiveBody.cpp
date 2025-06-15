#include "B4ActiveBody.h"
#include "B4GameWorld.h" // For gWorld, if accessed directly by methods (likely needed)
#include "B4ConvexHull.h" // For B4ConvexHull type
#include "B4PhysicsTypes.h" // For EActiveBodyType, kaabCanFatal, kaaePhysicsType (used in method logic)
#include <cmath> // For std::sqrt, etc. if needed by assembly translations
#include <cstring> // For std::memcpy, etc. if needed
#include <cstddef> // For offsetof, if we were to use it for complex member access verification

// Assuming a target environment where vtable pointers are 4 bytes (e.g., 32-bit)
// The data members sum to 44 bytes. vptr (4) + members (44) = 48 bytes (0x30).
#if defined(__i386__) || defined(_M_IX86) || defined(__arm__) || defined(__MIPSEL__) || defined(__MIPSEB__) // Common 32-bit archs + MIPS for PS2
static_assert(sizeof(B4ActiveBody) == 48, "B4ActiveBody size mismatch on 32-bit target. Expected 44 (data) + 4 (vptr) = 48 bytes.");
#elif defined(__x86_64__) || defined(_M_X64) || defined(__aarch64__) // Common 64-bit archs
// On 64-bit, vtable pointer is 8 bytes. m_pBBoxMin, m_pBBoxMax, m_pPhysicsData are pointers.
// std::array<unsigned char, 28> m_unknown_start_fields; -> 28
// GtMath::Vector3* m_pBBoxMin; -> 8
// GtMath::Vector3* m_pBBoxMax; -> 8
// void*            m_pPhysicsData; -> 8
// EActiveBodyType  m_eBodyType; -> 1
// std::array<unsigned char, 3> m_padding; -> 3
// Total data = 28 + 8 + 8 + 8 + 1 + 3 = 56 bytes.
// Add 8 for vtable pointer = 64 bytes.
// The provided example expected 56 bytes for 64-bit. Let's re-verify the packing and pointer sizes.
// If GtMath::Vector3* are 8 bytes, m_pPhysicsData is 8 bytes:
// m_unknown_start_fields (28)
// m_pBBoxMin (8)
// m_pBBoxMax (8)
// m_pPhysicsData (8)
// m_eBodyType (1)
// m_padding (3)
// Sum of members = 28 + 8 + 8 + 8 + 1 + 3 = 56 bytes.
// Vtable pointer (8) + Members (56) = 64 bytes.
// The original comment said "expected 44 data + 8 vptr = 52", this seems wrong if pointers become 8 bytes.
// The 44 bytes was specific to 4-byte pointers.
// For 64-bit:
// m_unknown_start_fields: 28
// m_pBBoxMin: 8
// m_pBBoxMax: 8
// m_pPhysicsData: 8
// m_eBodyType: 1 (char)
// m_padding: 3 (char)
// Total size of members (natural packing, no specific alignment directives): 28+8+8+8+1+3 = 56 bytes.
// So sizeof(B4ActiveBody) should be 56 (members) + 8 (vptr) = 64 bytes.
// The original prompt's 64-bit expectation of 56 total might assume members are packed tighter or vptr is different.
// Let's stick to the calculation: 56 (data) + 8 (vptr) = 64.
// If the original calculation of 44 bytes for data members assumed 4-byte pointers for m_pBBoxMin, m_pBBoxMax, m_pPhysicsData:
// 28 (unknown) + 4 (pBBoxMin) + 4 (pBBoxMax) + 4 (pPhysicsData) + 1 (eBodyType) + 3 (padding) = 44. This is correct for 32-bit.
static_assert(sizeof(B4ActiveBody) == 64, "B4ActiveBody size mismatch on 64-bit target. Expected 56 (data) + 8 (vptr) = 64 bytes.");
#else
// Warn if no specific architecture match, but don't fail build.
// Consider adding a default assumption or a specific error if target is unknown.
// For now, let's assume 32-bit if not explicitly 64-bit, for closer match to PS2.
// However, typical desktop development might be 64-bit by default.
// static_assert(sizeof(B4ActiveBody) == 48, "B4ActiveBody size mismatch on unknown target, assuming 32-bit default");
#pragma message("Warning: B4ActiveBody sizeof check skipped for this architecture. Assuming 4-byte vtable and pointers for safety, check manually.")
// A safer bet for unknown arch might be to not assert, or assert false with a message.
// For now, let's only assert on known common ones.
#endif


B4ActiveBody::B4ActiveBody() : m_pBBoxMin(nullptr), m_pBBoxMax(nullptr), m_pPhysicsData(nullptr), m_eBodyType(EActiveBodyType::Type0) {
    m_unknown_start_fields.fill(0);
    m_padding.fill(0);
    // TODO: Initialize members based on actual game logic if needed
}

B4ActiveBody::~B4ActiveBody() {
    // TODO: Clean up resources if any are owned
}

GtMath::Vector3 B4ActiveBody::GetPointVelocity(const GtMath::Vector3& /*point*/) const {
    // TODO: Implement logic from decompiled B4ActiveBody_Decomp.c GetPointVelocity__13CB4ActiveBodyGQ29GtMathPs26CGtV3d
    // This involves PS2 VU0 assembly for vector math.
    // Example:
    // if (m_eBodyType == EActiveBodyType::Type3) {
    //    // ... logic involving m_pPhysicsData, m_pBBoxMin, point ...
    // } else if (m_eBodyType != EActiveBodyType::Type6) {
    //    // ... different logic ...
    // }
    return GtMath::Vector3(0.0f, 0.0f, 0.0f);
}

B4ConvexHull* B4ActiveBody::GetConvexHull() const {
    // TODO: Implement logic from decompiled B4ActiveBody_Decomp.c GetConvexHull__13CB4ActiveBody
    // Example:
    // if (m_eBodyType == EActiveBodyType::Type3) {
    //     // char* physData = static_cast<char*>(m_pPhysicsData);
    //     // int offset = *(int*)(physData + 44);
    //     // if (offset) return reinterpret_cast<B4ConvexHull*>(physData_base_or_some_global_ptr + offset + 7616);
    // } else if (m_eBodyType != EActiveBodyType::Type6) {
    //     // char* physData = static_cast<char*>(m_pPhysicsData);
    //     // return *(B4ConvexHull**)(physData + 126); // This is more likely an offset to a pointer or struct containing pointer
    // }
    return nullptr;
}

int B4ActiveBody::GetNetworkCollBodyType() const {
    // TODO: Implement logic from decompiled B4ActiveBody_Decomp.c GetNetworkCollBodyType__C13CB4ActiveBody
    // This involves gWorld.m_CrashScore and gWorld.m_aPlayerCars.
    // switch (m_eBodyType) {
    // case EActiveBodyType::Type0: case EActiveBodyType::Type2: return 0;
    // ... etc. ...
    // case EActiveBodyType::Type4:
    //     // void* pCarPhysicsData = *(void**)((char*)m_pPhysicsData + 14091); // Example of offset access
    //     // if (gWorld.m_aPlayerCars[0].pPhysicsObjectIdentifier == pCarPhysicsData || ... ) return 3;
    //     // else return 5;
    // ... etc. ...
    // }

    // Example stub that accesses gWorld (demonstrating include)
    if (gWorld.m_aPlayerCars[0].pPhysicsObjectIdentifier != nullptr) {
        // Some logic
    }
    return 9; // Default from original if no cases match before final checks
}

bool B4ActiveBody::CanFatalAgainst(const B4ActiveBody* other) const {
    // TODO: Implement logic from decompiled B4ActiveBody_Decomp.c CanFatalAgainst__C13CB4ActiveBodyP13CB4ActiveBody
    // This involves GetNetworkCollBodyType() for self and other, and kaabCanFatal array.
    // int thisType = this->GetNetworkCollBodyType();
    // int otherType = other->GetNetworkCollBodyType();
    // ... logic for specific m_eBodyType checks ...
    // return kaabCanFatal[10 * thisType + otherType];
    if (!other) return false;

    // Example stub that accesses kaabCanFatal (demonstrating include B4PhysicsTypes.h for data)
    // int thisNetType = GetNetworkCollBodyType();
    // int otherNetType = other->GetNetworkCollBodyType();
    // if (thisNetType >=0 && thisNetType < 10 && otherNetType >=0 && otherNetType < 10) {
    //     return kaabCanFatal[10 * thisNetType + otherNetType];
    // }
    return false;
}

int B4ActiveBody::GetInteractionTypeAgainst(const B4ActiveBody* other) const {
    // TODO: Implement logic from decompiled B4ActiveBody_Decomp.c GetInteractionTypeAgainst__C13CB4ActiveBodyP13CB4ActiveBody
    // This involves GetNetworkCollBodyType() for self and other, and kaaePhysicsType array.
    // Also direct m_pPhysicsData accesses with large offsets.
    if (!other) return 0;

    // Example stub that accesses kaaePhysicsType
    // int thisNetType = GetNetworkCollBodyType();
    // int otherNetType = other->GetNetworkCollBodyType();
    // if (thisNetType >=0 && thisNetType < 10 && otherNetType >=0 && otherNetType < 10) {
    //     return kaaePhysicsType[40 * thisNetType + 4 * otherNetType];
    // }
    return 0;
}

void B4ActiveBody::GetIntervals() {
    // TODO: Implement logic from decompiled B4ActiveBody_Decomp.c GetIntervals__13CB4ActiveBody
    // This function is very heavy on PS2 VU0 assembly.
    // It seems to read from m_pBBoxMin, m_pBBoxMax and then write back to m_pBBoxMin, m_pBBoxMax.
    // Requires careful translation of vector math operations (vmul, vadd, vmax, vmini etc.)
    // using GtMath equivalents or new GtMath functions.
    // The function signature in C had only 'this' pointer.
    // It likely modifies m_pBBoxMin and m_pBBoxMax in place.
    if (m_pBBoxMin && m_pBBoxMax) {
        // Example: m_pBBoxMin->x = m_pBBoxMin->x * 1.0f; // No-op
    }
}

void* B4ActiveBody::GetEssentialParams() const {
    // TODO: Implement logic from decompiled B4ActiveBody_Decomp.c GetEssentialParams__C13CB4ActiveBody
    // if (m_eBodyType == EActiveBodyType::Type3) {
    //     return static_cast<char*>(m_pPhysicsData) + 112;
    // }
    // if (m_eBodyType >= EActiveBodyType::Type6 && m_eBodyType <= EActiveBodyType::Type8) { // (m_eBodyType - 6) < 3
    //     return nullptr;
    // }
    // return *static_cast<void**>(static_cast<char*>(m_pPhysicsData) + 637*sizeof(void*)); // Example, if it's an array of pointers
    // The C code is `*(m_pPhysicsData + 637)`, which means if m_pPhysicsData is e.g. SomeStruct*, it's `m_pPhysicsData[637]`.
    // If it's char*, it's `(char*)m_pPhysicsData + 637`. The type of m_pPhysicsData is key here.
    // Decompiled: `*(pActiveBody->m_pPhysicsData + 637)` implies `m_pPhysicsData` points to an array of some type, and we want the 637th element's address.
    // Or, `m_pPhysicsData` is a base pointer and 637 is an offset to a POINTER.
    // `return *( (void**)( (char*)m_pPhysicsData + offset_to_the_pointer_array_or_struct_field ) + 637 )` - this is complex.
    // Let's assume `return (void*)(((char*)m_pPhysicsData) + SOME_OFFSET_TO_ESSENTIAL_PARAMS_POINTER_ARRAY_OR_STRUCT_FIELD);`
    // And then from that, an element is picked.
    // The C `*(base + index)` is `base[index]`. If `m_pPhysicsData` points to an array of `Whatever*`, then `*(m_pPhysicsData + 637)` would be `m_pPhysicsData[637]` which is a `Whatever*`.
    // Let's assume it's `void** physics_ptr_array = (void**)m_pPhysicsData; return physics_ptr_array[637];` for non-Type3.
    return nullptr;
}

float B4ActiveBody::GetSpeedInMPS() const {
    // TODO: Implement logic from decompiled B4ActiveBody_Decomp.c GetSpeedInMPS__C13CB4ActiveBody
    // switch (m_eBodyType) {
    // case EActiveBodyType::Type0: case EActiveBodyType::Type1: case EActiveBodyType::Type2:
    // case EActiveBodyType::Type4: case EActiveBodyType::Type5:
    //     // return *(*(m_pPhysicsData + 637) + 84);
    //     // This implies m_pPhysicsData points to an array of pointers (or structs containing pointers).
    //     // void** essential_params_ptr_loc = (void**)((char*)m_pPhysicsData + OFFSET_TO_ESSENTIAL_PARAMS_POINTER);
    //     // void* essential_params = *essential_params_ptr_loc; // or essential_params_ptr_loc[637] from above
    //     // return *(float*)((char*)essential_params + 84);
    //     break;
    // case EActiveBodyType::Type3:
    //     // return *(float*)((char*)m_pPhysicsData + 49);
    //     break;
    // default: return 0.0f;
    // }
    return 0.0f;
}

void* B4ActiveBody::GetPhysicsData() const {
    // TODO: Implement logic from decompiled B4ActiveBody_Decomp.c GetPhysicsData__C13CB4ActiveBody
    return m_pPhysicsData;
}
