#pragma once

#include "B4ModelData.h" // For Burnout4::B4ModelData
#include <cstdint>       // For uint32_t

namespace Burnout4 {

// Original C struct definition:
// struct __attribute__((packed)) B4VehicleLODDataBase // sizeof=0x30
// {
//     B4ModelData *pMainModel_offset;    // Expected to be a 4-byte offset
//     B4ModelData *pWheelModels_offset[8]; // Expected to be 4-byte offsets
//     B4ModelData *pGlassModels_offset[3]; // Expected to be 4-byte offsets
// };
// Total size in C: 4 (for pMainModel_offset) + 8*4 (for pWheelModels_offset) + 3*4 (for pGlassModels_offset) = 48 bytes (0x30).

struct B4VehicleLODDataBase {
    // These fields represent the on-disk or original memory layout.
    // They store 4-byte offsets relative to the beginning of this struct.
    uint32_t mainModelOffset;
    uint32_t wheelModelsOffset[8];
    uint32_t glassModelsOffset[3];

    // These pointers are for C++ convenience after FixUp has been called.
    // They are not part of the original 0x30 byte data structure.
    B4ModelData* pMainModel;
    B4ModelData* pWheelModels[8];
    B4ModelData* pGlassModels[3];

    B4VehicleLODDataBase() :
        mainModelOffset(0),
        pMainModel(nullptr) {

        for (int i = 0; i < 8; ++i) {
            wheelModelsOffset[i] = 0;
            pWheelModels[i] = nullptr;
        }
        for (int i = 0; i < 3; ++i) {
            glassModelsOffset[i] = 0;
            pGlassModels[i] = nullptr;
        }
    }

    /**
     * Resolves the stored offsets and populates the B4ModelData pointers.
     * This method assumes that the '*Offset' fields have been loaded with
     * the raw 4-byte offset values from the game data.
     * @param baseOfThisStruct A char pointer to the starting address of this
     *                         B4VehicleLODDataBase instance in memory.
     */
    void FixUp(char* baseOfThisStruct) {
        // Resolve main model
        if (mainModelOffset != 0) {
            // Calculate the actual address of the main model
            pMainModel = reinterpret_cast<B4ModelData*>(baseOfThisStruct + mainModelOffset);
            // Call FixUp on the main model, its offsets are relative to its own address
            pMainModel->FixUp(reinterpret_cast<char*>(pMainModel));
        } else {
            pMainModel = nullptr;
        }

        // Resolve wheel models
        for (int i = 0; i < 8; ++i) {
            if (wheelModelsOffset[i] != 0) {
                pWheelModels[i] = reinterpret_cast<B4ModelData*>(baseOfThisStruct + wheelModelsOffset[i]);
                pWheelModels[i]->FixUp(reinterpret_cast<char*>(pWheelModels[i]));
            } else {
                pWheelModels[i] = nullptr;
            }
        }

        // Resolve glass models
        for (int i = 0; i < 3; ++i) {
            if (glassModelsOffset[i] != 0) {
                pGlassModels[i] = reinterpret_cast<B4ModelData*>(baseOfThisStruct + glassModelsOffset[i]);
                pGlassModels[i]->FixUp(reinterpret_cast<char*>(pGlassModels[i]));
            } else {
                pGlassModels[i] = nullptr;
            }
        }
    }
};

// Verify that the part of the struct corresponding to the original C struct layout is 0x30 bytes.
// sizeof(uint32_t) + sizeof(uint32_t[8]) + sizeof(uint32_t[3])
// = 4 + (8 * 4) + (3 * 4) = 4 + 32 + 12 = 48 bytes.
// This matches the original sizeof=0x30.
// The B4ModelData* members are additional and do not affect this initial layout size.

} // namespace Burnout4
