#ifndef B4_CONVEX_HULL_H
#define B4_CONVEX_HULL_H

#include <cstdint>
#include <vector>
#include "GtMath.h"

// Forward declare Debug Manager (assuming it's a class)
class CB4DebugManager;
extern CB4DebugManager gDebugManager; // Assuming global instance

// Forward declare Graphics Manager related structures (highly speculative)
namespace SomeGraphicsNamespace { // Placeholder
    struct GraphicsManagerData {
        float someMatrixOrArray[16]; // Placeholder for whatever unknown_09+104 is
    };
    extern GraphicsManagerData gGraphicsManager; // Assuming global instance
}


enum class EB4HullShape {
    Box = 0,
    Cone = 1,
    Boat = 2
    // Future shapes might be added here
};

class B4ConvexHull {
public:
    // Pointer-like offsets
    uintptr_t m_offsetFaces;
    uintptr_t m_offsetPlanes;
    uintptr_t m_offsetVertices;
    uintptr_t m_offsetEdges;
    uintptr_t m_offsetDeformData;

    // Flags and counts
    uint32_t m_flags;
    uint8_t m_numVertices;
    uint8_t m_numPlanes;
    uint8_t m_numEdges;
    uint8_t m_padding_or_unused1B; // To maintain struct alignment/size

    // Data storage using std::vector<uint8_t> to represent byte arrays
    // Sizes are based on the C struct's char arrays
    std::vector<uint8_t> m_faceData;    // size 68 in C struct (B4Face[4])
    std::vector<uint8_t> m_planeData;   // size 224 in C struct (GtMath::Plane[14])
    std::vector<uint8_t> m_vertexData;  // size 256 in C struct (GtMath::Vector3[16])
    std::vector<uint8_t> m_edgeData;    // size 56 in C struct (B4Edge[14])
    std::vector<uint8_t> m_deformData;  // size 200 in C struct (B4Deform[10])

    // Constructor to initialize vectors with correct sizes
    B4ConvexHull() :
        m_offsetFaces(0),
        m_offsetPlanes(0),
        m_offsetVertices(0),
        m_offsetEdges(0),
        m_offsetDeformData(0),
        m_flags(0),
        m_numVertices(0),
        m_numPlanes(0),
        m_numEdges(0),
        m_padding_or_unused1B(0),
        m_faceData(68),
        m_planeData(224),
        m_vertexData(256),
        m_edgeData(56),
        m_deformData(200)
    {}

    // Member functions
    void Fixup();
    int64_t CalculatePlaneData(int planeIndex);
    void MakeBoxFromBoundingBox(const GtMath::Vector3& minBounds, const GtMath::Vector3& maxBounds);
    void MakeFromBoundingBox(const GtMath::Vector3& minBounds, const GtMath::Vector3& maxBounds, EB4HullShape hullShape);
    void MakeConeFromBoundingBox(const GtMath::Vector3& minBounds, const GtMath::Vector3& maxBounds);
    void MakeBoatFromBoundingBox(const GtMath::Vector3& minBounds, const GtMath::Vector3& maxBounds);
    bool DeformHullVerts(
        GtMath::Vector3* pOutAveragePos, // Can be nullptr
        const GtMath::Vector3& refPositionForAverageCalc,
        const GtMath::Matrix3x4& deformMatrix,
        const GtMath::Matrix3x4* pBoneMatrices, // Array of bone matrices
        const B4ConvexHull& originalHull      // Undeformed hull
    );
    void MakePlanar();
    void DebugRenderEdges(const GtMath::Matrix3x4& worldTransform, bool drawText) const;
    void DebugRenderPlanes(const GtMath::Matrix3x4& worldTransform, bool drawText) const;
    void InitialiseVehicleHull();

    // Placeholder for other member functions to be added later
    // For example:
    // const GtMath::Vector3* getVertices() const;
    // const GtMath::Plane* getPlanes() const;
    // ... other getters and utility functions
};

#endif // B4_CONVEX_HULL_H
