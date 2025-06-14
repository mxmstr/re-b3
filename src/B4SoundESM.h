#pragma once

#include <cstdint> // For int32_t, uint32_t, uint8_t
#include <array>   // For std::array if fixed-size arrays are preferred for unknown_data

namespace Burnout4 {

// Original C struct:
// struct B4SoundESMGraphStruct // sizeof=0x8
// {
//     float *pGraphDataPoints_offset; // Offset from B4SoundESMGraphStruct base
//     int numDataPoints;
// };
struct B4SoundESMGraphStruct {
    uint32_t pGraphDataPoints_offset_raw; // Raw 4-byte offset from the base of this struct
    int32_t  numDataPoints;

    // Resolved pointer (populated by FixUp)
    float*   pGraphDataPoints;

    B4SoundESMGraphStruct() :
        pGraphDataPoints_offset_raw(0),
        numDataPoints(0),
        pGraphDataPoints(nullptr) {}

    /**
     * Resolves the internal offset to an actual pointer.
     * @param baseOfThisStruct A char pointer to the starting address of this B4SoundESMGraphStruct instance.
     */
    void FixUp(char* baseOfThisStruct) {
        if (pGraphDataPoints_offset_raw != 0) {
            // Offset is relative to the start of this B4SoundESMGraphStruct instance
            pGraphDataPoints = reinterpret_cast<float*>(baseOfThisStruct + pGraphDataPoints_offset_raw);
        } else {
            pGraphDataPoints = nullptr;
        }
    }
};
// Size of data part: 4 (offset_raw) + 4 (numDataPoints) = 8 bytes. Matches.

// Forward declaration for recursive structures if split across files (not needed here)
// struct B4SoundESMGraphStruct;

// Original C struct:
// struct B4SoundESMPartialStruct // sizeof=0x10
// {
//     unsigned __int8 unknown_partial_data[8];
//     B4SoundESMGraphStruct *pGraphs_offset; // Offset from B4SoundESMPartialStruct base
//     unsigned __int8 numGraphs;
//     unsigned __int8 unk_D;
//     unsigned __int8 unk_E;
//     unsigned __int8 unk_F;
// };
struct B4SoundESMPartialStruct {
    std::array<uint8_t, 8> unknown_partial_data; // Using std::array for fixed size
    uint32_t pGraphs_offset_raw; // Raw 4-byte offset from the base of this struct to an array of B4SoundESMGraphStruct
    uint8_t  numGraphs;
    uint8_t  unk_D;
    uint8_t  unk_E;
    uint8_t  unk_F;

    // Resolved pointer (populated by FixUp)
    B4SoundESMGraphStruct* pGraphs;

    B4SoundESMPartialStruct() :
        pGraphs_offset_raw(0),
        numGraphs(0),
        unk_D(0),
        unk_E(0),
        unk_F(0),
        pGraphs(nullptr) {
        unknown_partial_data.fill(0);
    }

    /**
     * Resolves internal offsets and calls FixUp on nested structures.
     * @param baseOfThisStruct A char pointer to the starting address of this B4SoundESMPartialStruct instance.
     */
    void FixUp(char* baseOfThisStruct) {
        if (pGraphs_offset_raw != 0) {
            // Offset is relative to the start of this B4SoundESMPartialStruct instance
            pGraphs = reinterpret_cast<B4SoundESMGraphStruct*>(baseOfThisStruct + pGraphs_offset_raw);
            for (uint8_t i = 0; i < numGraphs; ++i) {
                // Each B4SoundESMGraphStruct's FixUp is relative to its own base address
                pGraphs[i].FixUp(reinterpret_cast<char*>(&pGraphs[i]));
            }
        } else {
            pGraphs = nullptr;
        }
    }
};
// Size of data part: 8 (unknown_data) + 4 (offset_raw) + 1 (numGraphs) + 1 (unk_D) + 1 (unk_E) + 1 (unk_F) = 16 bytes. Matches.

// struct B4SoundESMPartialStruct; // Forward declaration

// Original C struct:
// struct __attribute__((packed)) B4SoundESMStruct // sizeof=0x44
// {
//     unsigned __int8 unknown_header_data[60]; // 0x3C bytes
//     B4SoundESMPartialStruct *pPartials_offset; // Offset from B4SoundESMStruct base
//     unsigned __int8 numPartials;
//     unsigned __int8 unk_41;
//     unsigned __int8 unk_42;
//     unsigned __int8 unk_43;
// };
struct B4SoundESMStruct {
    std::array<uint8_t, 60> unknown_header_data; // Using std::array
    uint32_t pPartials_offset_raw; // Raw 4-byte offset from the base of this struct to an array of B4SoundESMPartialStruct
    uint8_t  numPartials;
    uint8_t  unk_41;
    uint8_t  unk_42;
    uint8_t  unk_43;

    // Resolved pointer (populated by FixUp)
    B4SoundESMPartialStruct* pPartials;

    B4SoundESMStruct() :
        pPartials_offset_raw(0),
        numPartials(0),
        unk_41(0),
        unk_42(0),
        unk_43(0),
        pPartials(nullptr) {
        unknown_header_data.fill(0);
    }

    /**
     * Resolves internal offsets and calls FixUp on nested structures.
     * @param baseOfThisStruct A char pointer to the starting address of this B4SoundESMStruct instance.
     */
    void FixUp(char* baseOfThisStruct) {
        if (pPartials_offset_raw != 0) {
            // Offset is relative to the start of this B4SoundESMStruct instance
            pPartials = reinterpret_cast<B4SoundESMPartialStruct*>(baseOfThisStruct + pPartials_offset_raw);
            for (uint8_t i = 0; i < numPartials; ++i) {
                // Each B4SoundESMPartialStruct's FixUp is relative to its own base address
                pPartials[i].FixUp(reinterpret_cast<char*>(&pPartials[i]));
            }
        } else {
            pPartials = nullptr;
        }
    }
};
// Size of data part: 60 (unknown_data) + 4 (offset_raw) + 1 (numPartials) + 1 (unk_41) + 1 (unk_42) + 1 (unk_43) = 68 bytes (0x44). Matches.

} // namespace Burnout4
