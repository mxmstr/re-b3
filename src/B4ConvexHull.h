#pragma once

#include <cstdint>
#include <array>    // For std::array
#include "GtMath.h" // For GtMath::Vector3, GtMath::Matrix3x4, etc.

// Forward declarations like CB4DebugManager and SomeGraphicsNamespace are omitted
// as they are not part of this struct's definition.

// Enum from original file
enum class EB4HullShape {
    Box = 0,
    Cone = 1,
    Boat = 2
};

class B4ConvexHull {
public:
    // These fields store the 4-byte offsets as they would be in the C struct data.
    // These offsets are relative to the base of this B4ConvexHull instance.
    uint32_t m_offsetFaces_raw;
    uint32_t m_offsetPlanes_raw;
    uint32_t m_offsetVertices_raw;
    uint32_t m_offsetEdges_raw;
    uint32_t m_offsetDeformData_raw;

    uint32_t m_flags;
    uint8_t  m_numVertices;
    uint8_t  m_numPlanes;
    uint8_t  m_numEdges;
    uint8_t  m_padding_or_unused1B; // To match C struct's 0x1B byte

    // Embedded data arrays, matching the C struct's layout and size (0x340 total for B4ConvexHull)
    // Base offset for these arrays is 0x1C from the start of B4ConvexHull.
    std::array<uint8_t, 68>  m_faceData_embed;     // Offset 0x1C. Size 68 (0x44)
    std::array<uint8_t, 224> m_planeData_embed;    // Offset 0x60. Size 224 (0xE0)
    std::array<uint8_t, 256> m_vertexData_embed;   // Offset 0x140. Size 256 (0x100)
    std::array<uint8_t, 56>  m_edgeData_embed;     // Offset 0x240. Size 56 (0x38)
    std::array<uint8_t, 200> m_deformData_embed;   // Offset 0x278. Size 200 (0xC8)

    // Resolved pointers for C++ convenience (populated by FixUp).
    // These are not part of the 0x340 byte memory layout.
    uint8_t* pFaces;
    uint8_t* pPlanes;
    uint8_t* pVertices;
    uint8_t* pEdges;
    uint8_t* pDeformData;

    B4ConvexHull() :
        // Default raw offsets point to the embedded data arrays.
        // Start of embedded data is at offset 0x1C (28 decimal) from the base of B4ConvexHull.
        m_offsetFaces_raw(28),
        m_offsetPlanes_raw(28 + 68),
        m_offsetVertices_raw(28 + 68 + 224),
        m_offsetEdges_raw(28 + 68 + 224 + 256),
        m_offsetDeformData_raw(28 + 68 + 224 + 256 + 56),
        m_flags(0),
        m_numVertices(0), m_numPlanes(0), m_numEdges(0), m_padding_or_unused1B(0),
        pFaces(nullptr), pPlanes(nullptr), pVertices(nullptr), pEdges(nullptr), pDeformData(nullptr)
    {
        // std::array members are value-initialized (zeroed for uint8_t).
    }

    /**
     * Resolves raw offsets to pointers. Populates pFaces, pPlanes, etc.
     * The raw offsets are assumed to be relative to the base of this B4ConvexHull instance.
     * @param baseOfThisStruct A char pointer to the starting address of this B4ConvexHull instance.
     */
    void FixUp(char* baseOfThisStruct) {
        if (m_offsetFaces_raw != 0) pFaces = reinterpret_cast<uint8_t*>(baseOfThisStruct + m_offsetFaces_raw);
        else pFaces = nullptr;

        if (m_offsetPlanes_raw != 0) pPlanes = reinterpret_cast<uint8_t*>(baseOfThisStruct + m_offsetPlanes_raw);
        else pPlanes = nullptr;

        if (m_offsetVertices_raw != 0) pVertices = reinterpret_cast<uint8_t*>(baseOfThisStruct + m_offsetVertices_raw);
        else pVertices = nullptr;

        if (m_offsetEdges_raw != 0) pEdges = reinterpret_cast<uint8_t*>(baseOfThisStruct + m_offsetEdges_raw);
        else pEdges = nullptr;

        if (m_offsetDeformData_raw != 0) pDeformData = reinterpret_cast<uint8_t*>(baseOfThisStruct + m_offsetDeformData_raw);
        else pDeformData = nullptr;
    }

    // Declarations for other member functions from the existing B4ConvexHull.h.
    // These will be defined in B4ConvexHull.cpp and may need adaptation.
    int64_t CalculatePlaneData(int planeIndex); // Implementation will need to use 'pPlanes', 'pFaces', 'pVertices'
    void MakeBoxFromBoundingBox(const GtMath::Vector3& minBounds, const GtMath::Vector3& maxBounds); // Uses 'pVertices', 'pPlanes', 'pFaces', 'pEdges'
    void MakeFromBoundingBox(const GtMath::Vector3& minBounds, const GtMath::Vector3& maxBounds, EB4HullShape hullShape);
    void MakeConeFromBoundingBox(const GtMath::Vector3& minBounds, const GtMath::Vector3& maxBounds); // (TODO in original)
    void MakeBoatFromBoundingBox(const GtMath::Vector3& minBounds, const GtMath::Vector3& maxBounds); // (TODO in original)
    bool DeformHullVerts( // Uses 'pVertices', 'pDeformData'
        GtMath::Vector3* pOutAveragePos,
        const GtMath::Vector3& refPositionForAverageCalc,
        const GtMath::Matrix3x4& deformMatrix,
        const GtMath::Matrix3x4* pBoneMatrices,
        const B4ConvexHull& originalHull // originalHull.pVertices etc.
    );
    void MakePlanar(); // Uses 'pVertices', 'pPlanes'
    void DebugRenderEdges(const GtMath::Matrix3x4& worldTransform, bool drawText) const; // Uses 'pVertices', 'pEdges'
    void DebugRenderPlanes(const GtMath::Matrix3x4& worldTransform, bool drawText) const; // Uses 'pVertices', 'pPlanes', 'pFaces'
    void InitialiseVehicleHull(); // Will call FixUp((char*)this);
};

// Verify structure size:
// 5 * sizeof(uint32_t) for raw offsets = 20 bytes
// sizeof(uint32_t) for m_flags = 4 bytes
// 4 * sizeof(uint8_t) for counts/padding = 4 bytes
// std::array<uint8_t, 68> for m_faceData_embed = 68 bytes
// std::array<uint8_t, 224> for m_planeData_embed = 224 bytes
// std::array<uint8_t, 256> for m_vertexData_embed = 256 bytes
// std::array<uint8_t, 56> for m_edgeData_embed = 56 bytes
// std::array<uint8_t, 200> for m_deformData_embed = 200 bytes
// Total = 20 + 4 + 4 + 68 + 224 + 256 + 56 + 200 = 832 bytes (0x340).
// This matches the original C struct's sizeof.
// The pointer members (pFaces, pPlanes, etc.) do not contribute to this size calculation
// as they are for post-FixUp C++ access and are not part of the serialized layout.
