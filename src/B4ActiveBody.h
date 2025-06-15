#pragma once

#include <array> // For std::array
#include "GtMath.h" // For GtMath::Vector3
#include "B4PhysicsTypes.h" // For EActiveBodyType
#include "B4ConvexHull.h" // For B4ConvexHull (it's a return type)

class B4ActiveBody {
public:
    // Data members designed to match the memory layout after the vtable pointer
    // in the original PS2 C struct, assuming a 4-byte vtable pointer on PS2.
    // The C++ compiler will add its own vtable pointer (typically at the beginning).
    // The sum of sizes of these members is 44 bytes.
    // If the C++ vtable pointer is 4 bytes (e.g., on a 32-bit compilation target),
    // the total C++ class size would be 4 (vptr) + 44 (members) = 48 bytes (0x30), matching the original.

    std::array<unsigned char, 28> m_unknown_start_fields; // Original C struct offset: 0x04
    GtMath::Vector3* m_pBBoxMin;     // Original C struct offset: 0x20
    GtMath::Vector3* m_pBBoxMax;     // Original C struct offset: 0x24
    void*            m_pPhysicsData; // Original C struct offset: 0x28
    EActiveBodyType  m_eBodyType;    // Original C struct offset: 0x2C
    std::array<unsigned char, 3> m_padding; // Padding to make the total data member size 44 bytes.
                                            // Original C struct had padding here to reach sizeof 0x30.
public:
    B4ActiveBody();
    virtual ~B4ActiveBody();

    // Member functions corresponding to the decompiled C functions
    virtual GtMath::Vector3 GetPointVelocity(const GtMath::Vector3& point) const;
    virtual B4ConvexHull* GetConvexHull() const;
    virtual int GetNetworkCollBodyType() const;
    virtual bool CanFatalAgainst(const B4ActiveBody* other) const;
    virtual int GetInteractionTypeAgainst(const B4ActiveBody* other) const;
    virtual void GetIntervals();
    virtual void* GetEssentialParams() const;
    virtual float GetSpeedInMPS() const;
    virtual void* GetPhysicsData() const;
};

// A static_assert for sizeof(B4ActiveBody) could be placed in B4ActiveBody.cpp
// to verify against the expected size on the target platform.
// For example: static_assert(sizeof(B4ActiveBody) == 48, "B4ActiveBody size mismatch");
// (Assuming 4-byte vtable pointer)
