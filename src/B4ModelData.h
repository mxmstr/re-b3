#pragma once

#include <cstdint> // For intptr_t if needed, though char* arithmetic is used here.

namespace Burnout4 {

// Original C struct:
// struct __attribute__((packed)) B4ModelData::SubMeshData // sizeof=0x8
// {
//     int pVertices_offset;
//     int pIndices_offset;
// };
struct SubMeshData {
    int pVertices_offset; // Offset from the start of this SubMeshData instance to vertex data
    int pIndices_offset;  // Offset from the start of this SubMeshData instance to index data

    // Pointers to be resolved by FixUp.
    // These will point to the actual vertex and index data after FixUp.
    void* pVertices;
    void* pIndices;

    SubMeshData() : pVertices_offset(0), pIndices_offset(0), pVertices(nullptr), pIndices(nullptr) {}

    /**
     * Resolves internal offsets to pointers, assuming this SubMeshData instance is part of a data block.
     * @param baseOfThisStruct A pointer to the beginning of this SubMeshData instance.
     */
    void FixUp(char* baseOfThisStruct) {
        if (pVertices_offset != 0) {
            // The C code implies offsets are relative to the start of the struct itself.
            // e.g., vertex_data_ptr = (char*)this + this->pVertices_offset;
            pVertices = baseOfThisStruct + pVertices_offset;
        } else {
            pVertices = nullptr;
        }

        if (pIndices_offset != 0) {
            // e.g., index_data_ptr = (char*)this + this->pIndices_offset;
            pIndices = baseOfThisStruct + pIndices_offset;
        } else {
            pIndices = nullptr;
        }
    }
};

// Original C struct:
// struct __attribute__((packed)) B4ModelData // sizeof=0x10
// {
//     int numSubMeshes;
//     int pSubMeshes_offset;
//     struct B4ModelData::SubMeshData m_subMeshes[1]; // This was a flexible array member hint
// };
struct B4ModelData {
    int numSubMeshes;
    int pSubMeshes_offset; // Offset from the start of this B4ModelData instance to the array of SubMeshData

    // Pointer to an array of SubMeshData, to be resolved by FixUp.
    // This will point to the actual SubMeshData array after FixUp.
    SubMeshData* m_subMeshes;

    B4ModelData() : numSubMeshes(0), pSubMeshes_offset(0), m_subMeshes(nullptr) {}

    /**
     * Resolves internal offsets to pointers, assuming this B4ModelData instance is part of a data block.
     * @param baseOfThisStruct A pointer to the beginning of this B4ModelData instance.
     */
    void FixUp(char* baseOfThisStruct) {
        if (pSubMeshes_offset != 0) {
            // The C code implies pSubMeshes_offset is relative to the start of B4ModelData.
            // e.g., subMeshes_array_ptr = (SubMeshData*)((char*)this + this->pSubMeshes_offset);
            m_subMeshes = reinterpret_cast<SubMeshData*>(baseOfThisStruct + pSubMeshes_offset);

            // Now, FixUp each SubMeshData. Its offsets are relative to its own base.
            for (int i = 0; i < numSubMeshes; ++i) {
                m_subMeshes[i].FixUp(reinterpret_cast<char*>(&m_subMeshes[i]));
            }
        } else {
            m_subMeshes = nullptr;
        }
    }
};

} // namespace Burnout4
