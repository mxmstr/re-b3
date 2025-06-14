#pragma once

#include <cstdint> // For int32_t, uint32_t

namespace Burnout4 {

// Original C struct definition:
// struct __attribute__((packed)) B4VehiclePayloadSet // sizeof=0xC
// {
//     int m_payloadType;
//     int m_numAttachmentPoints;
//     void *pAttachmentPointsData_offset; // Offset from B4VehiclePayloadSet base
// };

struct B4VehiclePayloadSet {
    // These fields represent the on-disk or original memory layout.
    int32_t  m_payloadType;
    int32_t  m_numAttachmentPoints;
    uint32_t pAttachmentPointsData_offset_raw; // Raw 4-byte offset from the base of this struct

    // Resolved pointer for C++ convenience (populated by FixUp).
    // This is not part of the original 0xC byte data structure.
    void*    pAttachmentPointsData;

    B4VehiclePayloadSet() :
        m_payloadType(0),
        m_numAttachmentPoints(0),
        pAttachmentPointsData_offset_raw(0),
        pAttachmentPointsData(nullptr) {}

    /**
     * Resolves the internal offset (pAttachmentPointsData_offset_raw) to an actual pointer (pAttachmentPointsData).
     * This method assumes that pAttachmentPointsData_offset_raw has been loaded with
     * the raw 4-byte offset value from the game data.
     * @param baseOfThisStruct A char pointer to the starting address of this
     *                         B4VehiclePayloadSet instance in memory.
     */
    void FixUp(char* baseOfThisStruct) {
        if (pAttachmentPointsData_offset_raw != 0) {
            pAttachmentPointsData = reinterpret_cast<void*>(baseOfThisStruct + pAttachmentPointsData_offset_raw);
        } else {
            pAttachmentPointsData = nullptr;
        }
    }
};

// Verify that the part of the struct corresponding to the original C struct layout is 0xC bytes.
// sizeof(m_payloadType) (int32_t) = 4 bytes
// sizeof(m_numAttachmentPoints) (int32_t) = 4 bytes
// sizeof(pAttachmentPointsData_offset_raw) (uint32_t) = 4 bytes
// Total = 4 + 4 + 4 = 12 bytes (0xC).
// This matches the original sizeof.
// The pAttachmentPointsData pointer member is additional and does not affect this initial layout size.

} // namespace Burnout4
