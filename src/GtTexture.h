#pragma once

#include <cstdint> // For uint32_t, uint8_t
#include <vector>  // Potentially for std::vector if we store resolved arrays

namespace Burnout4 {

// Forward declaration for GtTexture if GtTextureSubDefinition needs it (not in this case)
// struct GtTexture;

// Original C struct:
// struct __attribute__((packed)) GtTextureSubDefinition // sizeof=0x10
// {
//     unsigned int sub_def_flags;
//     void *pPixelDataForSubDef_offset; // Offset from GtTexture base
//     unsigned __int8 sub_def_padding[8];
// };
struct GtTextureSubDefinition {
    uint32_t sub_def_flags; // If this is the first sub-definition in an array pointed to by GtTexture, this holds the count. Otherwise, flags.
    uint32_t pPixelDataForSubDef_offset; // Offset from the base of the parent GtTexture struct
    uint8_t  sub_def_padding[8];

    // Resolved pointer (populated by FixUp)
    void*    pPixelDataForSubDef;

    GtTextureSubDefinition() :
        sub_def_flags(0),
        pPixelDataForSubDef_offset(0),
        pPixelDataForSubDef(nullptr) {
        for(int i = 0; i < 8; ++i) {
            sub_def_padding[i] = 0;
        }
    }

    /**
     * Resolves the internal offset to an actual pointer.
     * @param baseOfParentGtTexture A char pointer to the starting address of the parent GtTexture instance.
     */
    void FixUp(char* baseOfParentGtTexture) {
        if (pPixelDataForSubDef_offset != 0) {
            pPixelDataForSubDef = baseOfParentGtTexture + pPixelDataForSubDef_offset;
        } else {
            pPixelDataForSubDef = nullptr;
        }
        // sub_def_flags is a value, not an offset to be fixed up.
    }
};
// Size of GtTextureSubDefinition's data part: 4 (flags) + 4 (offset) + 8 (padding) = 16 bytes (0x10).

// Original C struct:
// struct __attribute__((packed)) GtTexture // sizeof=0xA8
// {
//     void *pPixelData_offset;
//     void *pClutData_offset;
//     void *pMipmapData_offset;
//     unsigned __int8 unknown_data_0C_to_23[24];
//     GtTextureSubDefinition *pSubDefinitions_offset;
//     unsigned __int8 unknown_data_0x28_to_0x6B[68];
//     char *pTextureName_offset;
//     void *pGsRamClutPtrs_offset[7];
//     char pad_8C[24];
//     void *unk_A4; // Note: C struct uses unk_A4, implies it's an offset field
// };
struct GtTexture {
    // These fields represent the on-disk or original memory layout (0xA8 bytes).
    // All offsets are relative to the beginning of this GtTexture struct.
    uint32_t pPixelData_offset;
    uint32_t pClutData_offset;
    uint32_t pMipmapData_offset;
    uint8_t  unknown_data_0C_to_23[24];
    uint32_t pSubDefinitions_offset;         // Offset to an array of GtTextureSubDefinition
    uint8_t  unknown_data_0x28_to_0x6B[68];
    uint32_t pTextureName_offset;
    uint32_t pGsRamClutPtrs_offset[7];
    uint8_t  pad_8C[24];
    uint32_t unk_A4_offset;                  // Named consistently as an offset

    // Resolved Pointers (for C++ convenience, not part of the 0xA8 layout)
    void*                   pPixelData;
    void*                   pClutData;
    void*                   pMipmapData;
    GtTextureSubDefinition* pSubDefinitions; // Points to an array after FixUp
    char*                   pTextureName;
    void*                   pGsRamClutPtrs[7];
    void*                   unk_A4;

    uint32_t numSubDefinitions; // Stores the count of sub-definitions

    GtTexture() :
        pPixelData_offset(0), pClutData_offset(0), pMipmapData_offset(0),
        pSubDefinitions_offset(0), pTextureName_offset(0), unk_A4_offset(0),
        pPixelData(nullptr), pClutData(nullptr), pMipmapData(nullptr),
        pSubDefinitions(nullptr), pTextureName(nullptr), unk_A4(nullptr),
        numSubDefinitions(0) {

        for(int i = 0; i < 24; ++i) unknown_data_0C_to_23[i] = 0;
        for(int i = 0; i < 68; ++i) unknown_data_0x28_to_0x6B[i] = 0;
        for(int i = 0; i < 7; ++i) {
            pGsRamClutPtrs_offset[i] = 0;
            pGsRamClutPtrs[i] = nullptr;
        }
        for(int i = 0; i < 24; ++i) pad_8C[i] = 0;
    }

    /**
     * Resolves all internal offsets to actual pointers.
     * @param baseOfThisStruct A char pointer to the starting address of this GtTexture instance.
     */
    void FixUp(char* baseOfThisStruct) {
        if (pPixelData_offset != 0) pPixelData = baseOfThisStruct + pPixelData_offset;
        else pPixelData = nullptr;

        if (pClutData_offset != 0) pClutData = baseOfThisStruct + pClutData_offset;
        else pClutData = nullptr;

        if (pMipmapData_offset != 0) pMipmapData = baseOfThisStruct + pMipmapData_offset;
        else pMipmapData = nullptr;

        if (pTextureName_offset != 0) pTextureName = reinterpret_cast<char*>(baseOfThisStruct + pTextureName_offset);
        else pTextureName = nullptr;

        if (unk_A4_offset != 0) unk_A4 = baseOfThisStruct + unk_A4_offset;
        else unk_A4 = nullptr;

        for (int i = 0; i < 7; ++i) {
            if (pGsRamClutPtrs_offset[i] != 0) {
                pGsRamClutPtrs[i] = baseOfThisStruct + pGsRamClutPtrs_offset[i];
            } else {
                pGsRamClutPtrs[i] = nullptr;
            }
        }

        if (pSubDefinitions_offset != 0) {
            pSubDefinitions = reinterpret_cast<GtTextureSubDefinition*>(baseOfThisStruct + pSubDefinitions_offset);

            // According to original FixUp: "recordCount = pTexture->pSubDefinitions_offset->sub_def_flags;"
            // This means the sub_def_flags of the *first* GtTextureSubDefinition object in the array holds the count.
            if (pSubDefinitions) { // Check if the pointer is valid after resolving offset
                numSubDefinitions = pSubDefinitions[0].sub_def_flags;

                // Now FixUp each GtTextureSubDefinition in the array.
                // Their pPixelDataForSubDef_offset is relative to the base of this GtTexture.
                for (uint32_t i = 0; i < numSubDefinitions; ++i) {
                    pSubDefinitions[i].FixUp(baseOfThisStruct);
                }
            } else {
                // Should not happen if pSubDefinitions_offset was non-zero, but defensive.
                numSubDefinitions = 0;
            }
        } else {
            pSubDefinitions = nullptr;
            numSubDefinitions = 0;
        }
    }
};

// Verify GtTexture's data part size:
// uint32_t fields: pPixelData_offset (4), pClutData_offset (4), pMipmapData_offset (4),
//                   pSubDefinitions_offset (4), pTextureName_offset (4),
//                   pGsRamClutPtrs_offset[7] (28), unk_A4_offset (4)
// uint8_t arrays: unknown_data_0C_to_23[24] (24), unknown_data_0x28_to_0x6B[68] (68), pad_8C[24] (24)
// Total = 4+4+4+24+4+68+4+28+24+4 = 168 bytes (0xA8). Matches original sizeof.
} // namespace Burnout4
