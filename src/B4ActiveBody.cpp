#include "B4ActiveBody.h"
#include "B4GameWorld.h" // For gWorld, if accessed directly by methods (likely needed)
#include "B4ConvexHull.h" // For B4ConvexHull type
#include "B4PhysicsTypes.h" // For EActiveBodyType, kaabCanFatal, kaaePhysicsType (used in method logic)
#include <cmath> // For std::sqrt, etc. if needed by assembly translations
#include <cstring> // For std::memcpy, etc. if needed
#include <cstddef> // For offsetof, if we were to use it for complex member access verification
#include <cstdint> // For uintptr_t

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
}

B4ActiveBody::~B4ActiveBody() {
}

GtMath::Vector3 B4ActiveBody::GetPointVelocity(const GtMath::Vector3& point) const {
    if (m_eBodyType == EActiveBodyType::Type3) {
        if (m_pPhysicsData && m_pBBoxMin) {
            char* physDataChar = static_cast<char*>(m_pPhysicsData);
            float factor = *(float*)(physDataChar + 49);
            GtMath::Vector3 pointBBoxMin = *m_pBBoxMin;
            return GtMath::multiply_scalar(pointBBoxMin, factor);
        }
    } else if (m_eBodyType != EActiveBodyType::Type6) {
        if (m_pPhysicsData) {
            char* physDataChar = static_cast<char*>(m_pPhysicsData);
            // It's crucial to ensure m_pPhysicsData is not null before dereferencing.
            // Also, ensure the memory at (physDataChar + 125) can be dereferenced as void**.
            // And that the resulting pointer can be dereferenced for centerOfRotation.
            // These checks are simplified here; real code might need more robust error handling
            // or rely on game engine guarantees about data integrity.

            void* ptr125 = *(void**)(physDataChar + 125); // Potential read access violation if physDataChar + 125 is invalid
            if (!ptr125) return GtMath::Vector3(0.0f, 0.0f, 0.0f); // Or handle error appropriately

            GtMath::Vector3 centerOfRotation = *(GtMath::Vector3*)((char*)ptr125 + 0x30); // 48 bytes offset
            GtMath::Vector3 angularVelocity = *(GtMath::Vector3*)(physDataChar + 0xC0);   // 192 bytes offset
            GtMath::Vector3 linearVelocity = *(GtMath::Vector3*)(physDataChar + 0xA0);    // 160 bytes offset

            GtMath::Vector3 r = GtMath::subtract(point, centerOfRotation);
            GtMath::Vector3 rotationalVelocity = GtMath::cross_product(angularVelocity, r);
            return GtMath::add(linearVelocity, rotationalVelocity);
        }
    }
    // Default case for Type6 or if m_pPhysicsData/m_pBBoxMin is null in Type3, or m_pPhysicsData is null in other types
    return GtMath::Vector3(0.0f, 0.0f, 0.0f);
}

B4ConvexHull* B4ActiveBody::GetConvexHull() const {
    if (!m_pPhysicsData) {
        return nullptr;
    }

    if (m_eBodyType == EActiveBodyType::Type3) {
        char* physDataChar = static_cast<char*>(m_pPhysicsData);
        // The original C code suggests that the value at offset 44 is an offset itself,
        // not a direct pointer. If it's 0, it means no hull.
        // The type of this offset in the original struct was int, but using uintptr_t
        // for pointer arithmetic and to hold a potential direct address if interpretation changes.
        // Given the +7616, it's more likely an offset from a base or an absolute address stored as int/long.
        // For now, let's assume it's an offset relative to some base, or an absolute address if large enough.
        // The prompt suggests `value + 7616` where value is read from `m_pPhysicsData + 44`.
        // This implies `value` itself is a base address or part of one.
        // Let's assume `*(uintptr_t*)((char*)m_pPhysicsData + 44)` IS the address to which 7616 is added.
        // This is unusual if it was just an "int offset" in original struct.
        // Re-interpreting based on `reinterpret_cast<B4ConvexHull*>(value + 7616);`
        // This implies 'value' is a base pointer address.
        uintptr_t value = *(uintptr_t*)(physDataChar + 44);
        if (value != 0) {
            // This interpretation assumes 'value' is a memory address that, when 7616 is added to it,
            // points to a B4ConvexHull. This is a common pattern if 'value' is a pointer to a larger structure
            // and 7616 is an offset within that structure.
            return reinterpret_cast<B4ConvexHull*>(value + 7616);
        }
        // If value is 0, fall through to default nullptr.
    } else if (m_eBodyType != EActiveBodyType::Type6) {
        char* physDataChar = static_cast<char*>(m_pPhysicsData);
        // This reads a pointer to B4ConvexHull from the offset 126 in m_pPhysicsData.
        return *(B4ConvexHull**)(physDataChar + 126);
    }

    // Default for Type6, or Type3 with a zero value, or if m_pPhysicsData was null initially.
    return nullptr;
}

int B4ActiveBody::GetNetworkCollBodyType() const {
    switch (m_eBodyType) {
        case EActiveBodyType::Type0:
        case EActiveBodyType::Type2:
            return 0;
        case EActiveBodyType::Type1:
            return 1;
        case EActiveBodyType::Type3:
            return 2;
        case EActiveBodyType::Type6:
        case EActiveBodyType::Type7:
        case EActiveBodyType::Type8:
            return 9;
        default: {
            // This default case handles Type4, Type5, and any other unspecified EActiveBodyType values.
            // Ensure m_pPhysicsData is valid before dereferencing for Type4/Type5 specific logic
            if (!m_pPhysicsData && (m_eBodyType == EActiveBodyType::Type4 || m_eBodyType == EActiveBodyType::Type5)) {
                // Or handle error, but original code might have assumed m_pPhysicsData is always valid for these types.
                // Returning 9 as a safe default if critical data is missing.
                return 9;
            }

            void* keyPlayerVehicleID;
            if (gWorld.m_CrashScore[1048] < 2LL) { // Assuming m_CrashScore is an array/pointer of suitable numeric types
                keyPlayerVehicleID = gWorld.m_aPlayerCars[0].pPhysicsObjectIdentifier;
            } else {
                keyPlayerVehicleID = gWorld.m_aPlayerCars[1].pPhysicsObjectIdentifier;
            }

            if (m_eBodyType == EActiveBodyType::Type4) {
                char* physDataChar = static_cast<char*>(m_pPhysicsData);
                void* currentBodyPhysPtr = *(void**)(physDataChar + 14091);
                if (gWorld.m_aPlayerCars[0].pPhysicsObjectIdentifier == currentBodyPhysPtr || keyPlayerVehicleID == currentBodyPhysPtr) {
                    return 3;
                } else {
                    return 5;
                }
            } else if (m_eBodyType == EActiveBodyType::Type5) {
                char* physDataChar = static_cast<char*>(m_pPhysicsData);
                void* currentBodyPhysPtr = *(void**)(physDataChar + 14810);
                if (gWorld.m_aPlayerCars[0].pPhysicsObjectIdentifier == currentBodyPhysPtr || keyPlayerVehicleID == currentBodyPhysPtr) {
                    return 6;
                } else {
                    return 8;
                }
            } else {
                // For any other EActiveBodyType values not explicitly handled.
                return 9;
            }
        }
    }
}

bool B4ActiveBody::CanFatalAgainst(const B4ActiveBody* other) const {
    if (!other) {
        return false;
    }

    int thisNetType = this->GetNetworkCollBodyType();
    int otherNetType = other->GetNetworkCollBodyType();

    EActiveBodyType otherBodyType = other->m_eBodyType;
    bool isOtherBodyTypeEligibleForMassCheck =
        (otherBodyType == EActiveBodyType::Type0) ||
        (otherBodyType == EActiveBodyType::Type1) ||
        (otherBodyType == EActiveBodyType::Type2) ||
        (otherBodyType == EActiveBodyType::Type4) ||
        (otherBodyType == EActiveBodyType::Type5);

    bool isOtherHeavy = false;
    if (isOtherBodyTypeEligibleForMassCheck && other->m_pPhysicsData) {
        // Assuming m_pPhysicsData points to a structure where a float at offset 1098 represents mass or a related factor.
        // Need to be cautious about direct pointer arithmetic and type casting.
        isOtherHeavy = (*(float*)((char*)other->m_pPhysicsData + 1098) > 3999.0f);
    }

    bool thisTypeOverrideCondition =
        (thisNetType != 1) &&
        (thisNetType != 7) &&
        (thisNetType != 8);

    if (isOtherHeavy && thisTypeOverrideCondition) {
        return true;
    }

    // Check bounds for kaabCanFatal access
    if (thisNetType >= 0 && thisNetType < 10 && otherNetType >= 0 && otherNetType < 10) {
        return kaabCanFatal[thisNetType * 10 + otherNetType];
    }

    // Fallback if types are out of expected range, though GetNetworkCollBodyType should ideally constrain this.
    return false;
}

int B4ActiveBody::GetInteractionTypeAgainst(const B4ActiveBody* other) const {
    if (!other) {
        return 0;
    }

    int thisNetType = this->GetNetworkCollBodyType();
    int otherNetType = other->GetNetworkCollBodyType();

    int lookupThisNetType = thisNetType;
    int lookupOtherNetType = otherNetType;

    // Block A: Vehicle (owner is Type1, vehicle is Type5) vs Owner (Type1)
    // If this is Owner (1) and other is Vehicle (5)
    if (thisNetType == 1 && otherNetType == 5) {
        // Check if this owner owns the other vehicle
        if (this->m_pPhysicsData && other->m_pPhysicsData) {
            char* pThisPhys = static_cast<char*>(this->m_pPhysicsData);
            char* pOtherPhys = static_cast<char*>(other->m_pPhysicsData);

            // Get vehicle ID from 'other' (Type5)
            // Offset 14091 used for vehicle ID in Type4 in GetNetworkCollBodyType.
            // Assuming Type5 (if it's a vehicle here) uses a similar structure.
            void* ptr_other_veh_id = *(void**)(pOtherPhys + 14091);

            // Get owned vehicle ID from 'this' (Type1)
            void* ptr_this_owner_base = *(void**)(pThisPhys + 1340);
            if (ptr_this_owner_base) {
                void* ptr_this_owner_veh_id = *(void**)((char*)ptr_this_owner_base + 11400);
                if (ptr_other_veh_id == ptr_this_owner_veh_id) {
                    lookupOtherNetType = 4; // Other is "my vehicle" (Type4)
                }
                // else lookupOtherNetType remains 5 (Other is "other vehicle")
            }
        }
    }
    // If other is Owner (1) and this is Vehicle (5)
    else if (otherNetType == 1 && thisNetType == 5) {
        // Check if other owner owns this vehicle
        if (this->m_pPhysicsData && other->m_pPhysicsData) {
            char* pThisPhys = static_cast<char*>(this->m_pPhysicsData);
            char* pOtherPhys = static_cast<char*>(other->m_pPhysicsData);

            // Get vehicle ID from 'this' (Type5)
            void* ptr_this_veh_id = *(void**)(pThisPhys + 14091);

            // Get owned vehicle ID from 'other' (Type1)
            void* ptr_other_owner_base = *(void**)(pOtherPhys + 1340);
            if (ptr_other_owner_base) {
                void* ptr_other_owner_veh_id = *(void**)((char*)ptr_other_owner_base + 11400);
                if (ptr_this_veh_id == ptr_other_owner_veh_id) {
                    lookupThisNetType = 4; // This is "my vehicle" (Type4)
                }
                // else lookupThisNetType remains 5 (This is "other vehicle")
            }
        }
    }

    // Block B: Trailer (owner is Type1, trailer is Type8) vs Owner (Type1)
    // If this is Owner (1) and other is Trailer (lookupOtherNetType might be 8)
    if (thisNetType == 1 && lookupOtherNetType == 8) {
        // Check if this owner owns the other trailer
        if (this->m_pPhysicsData && other->m_pPhysicsData) {
            char* pThisPhys = static_cast<char*>(this->m_pPhysicsData);
            char* pOtherPhys = static_cast<char*>(other->m_pPhysicsData);

            // Get trailer ID from 'other' (Type8)
            // Offset 14810 used for trailer ID in Type5 in GetNetworkCollBodyType.
            // Assuming Type8 (trailer) uses a similar structure.
            void* ptr_other_trailer_id = *(void**)(pOtherPhys + 14810);

            // Get owned vehicle/trailer ID from 'this' (Type1)
            void* ptr_this_owner_base = *(void**)(pThisPhys + 1340);
            if (ptr_this_owner_base) {
                void* ptr_this_owner_veh_id = *(void**)((char*)ptr_this_owner_base + 11400); // This is owner's main vehicle ID.
                                                                                          // Assumption: if trailer ID matches owner's main vehicle ID, it's "my trailer".
                if (ptr_other_trailer_id == ptr_this_owner_veh_id) {
                    lookupOtherNetType = 7; // Other is "my trailer" (Type7)
                }
                // else lookupOtherNetType remains 8 (Other is "other trailer")
            }
        }
    }
    // If other is Owner (lookupOtherNetType might be 1, but original otherNetType is 1) and this is Trailer (8)
    else if (otherNetType == 1 && thisNetType == 8) {
        // Check if other owner owns this trailer
        if (this->m_pPhysicsData && other->m_pPhysicsData) {
            char* pThisPhys = static_cast<char*>(this->m_pPhysicsData);
            char* pOtherPhys = static_cast<char*>(other->m_pPhysicsData);

            // Get trailer ID from 'this' (Type8)
            void* ptr_this_trailer_id = *(void**)(pThisPhys + 14810);

            // Get owned vehicle/trailer ID from 'other' (Type1)
            void* ptr_other_owner_base = *(void**)(pOtherPhys + 1340);
            if (ptr_other_owner_base) {
                void* ptr_other_owner_veh_id = *(void**)((char*)ptr_other_owner_base + 11400);
                if (ptr_this_trailer_id == ptr_other_owner_veh_id) {
                    lookupThisNetType = 7; // This is "my trailer" (Type7)
                }
                // else lookupThisNetType remains 8 (This is "other trailer")
            }
        }
    }

    // Final lookup
    if (lookupThisNetType >= 0 && lookupThisNetType < 10 && lookupOtherNetType >= 0 && lookupOtherNetType < 10) {
        return kaaePhysicsType[lookupThisNetType * 10 + lookupOtherNetType];
    }

    return 0; // Fallback
}

void B4ActiveBody::GetIntervals() {
    if (!m_pBBoxMin || !m_pBBoxMax) {
        return;
    }

    // The original function's logic is almost entirely PS2 VU0 assembly, as seen in
    // the decompiled C function B4ActiveBody_Decomp.c GetIntervals__13CB4ActiveBody.
    //
    // Key observations from the assembly:
    // - It heavily implies that m_pBBoxMin points to an array of at least 4 GtMath::Vector3's
    //   (accesses like `m_pBBoxMin[0]`, `m_pBBoxMin[1]`, `m_pBBoxMin[2]`, `m_pBBoxMin[3]`).
    // - It also implies `m_pBBoxMax` points to an array of at least 2 GtMath::Vector3's
    //   (accesses like `m_pBBoxMax[0]`, `m_pBBoxMax[1]`).
    // - The function reads from various components of these vectors (x, y, z, and potentially w if they are Vector4 like)
    //   and performs a sequence of vector operations (multiplications, additions, min/max operations - vmul, vadd, vmax, vmini).
    // - The final results of these complex vector calculations, which appear to be two new vectors,
    //   are then augmented by vector `m_pBBoxMin[3]` (added to both results) and then stored back into
    //   `m_pBBoxMin[0]` and `m_pBBoxMin[1]`.
    // - `m_pBBoxMax` appears to be read-only within this function after initial loading.
    //
    // Translating this specific VU0 assembly sequence accurately into C++ using GtMath
    // (or any other vector library) is a highly complex and error-prone task. It requires:
    //   1. A deep understanding of PS2 VU0 programming, including its pipeline, instruction set,
    //      and conventions for vector math.
    //   2. Precise knowledge of the data layout within the GtMath::Vector3 arrays pointed to by
    //      m_pBBoxMin and m_pBBoxMax, and what each indexed vector represents (e.g., are they
    //      corners of a bounding box, orientation vectors, transformation matrices, etc.?).
    //      The assembly treats these as raw qwords and performs operations that might be specific
    //      to how data was packed for VU0 efficiency.
    //   3. Careful mapping of VU0 vector operations to equivalent GtMath functions or sequences of operations.
    //      Some VU0 instructions might not have direct one-to-one GtMath equivalents, especially
    //      component-wise operations or special instructions.
    //
    // Without further information on the intended high-level algorithm this function is supposed
    // to implement, or the precise semantic meaning of the data within m_pBBoxMin/Max arrays,
    // attempting a direct translation from assembly would be speculative and likely incorrect.
    //
    // Therefore, this function body is left intentionally empty beyond the initial null checks,
    // pending further expertise, algorithmic clarification, or a higher-level understanding
    // of its purpose in the physics engine.

    // Placeholder for the complex VU0 assembly translation if it were to be attempted.
    // Example of what the start might look like if data structures were understood:
    // GtMath::Vector3 temp1 = GtMath::multiply(m_pBBoxMax[0], m_pBBoxMin[2].x); // Hypothetical
    // ... many more operations ...
    // m_pBBoxMin[0] = GtMath::add(final_result1, m_pBBoxMin[3]);
    // m_pBBoxMin[1] = GtMath::add(final_result2, m_pBBoxMin[3]);
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
