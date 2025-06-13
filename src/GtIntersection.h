#ifndef GT_INTERSECTION_H
#define GT_INTERSECTION_H

#include <cstdint>
#include <vector> // Placeholder, might remove later if not needed
#include "GtMath.h"

// Assuming ALIGNED_DECL is defined elsewhere, e.g., GtMath.h or a common types header
// If not, it would be: #define ALIGNED_DECL(x) __attribute__((aligned(x))) on GCC/Clang
// or __declspec(align(x)) on MSVC.
// For now, we'll assume it's available.

namespace Gt {

struct ALIGNED_DECL(16) GtPolygonSoupHeader {
    const void* pIndexData;    // Pointer to index data for polygons
    const void* pVertexData;   // Pointer to vertex data
    int32_t unknown_offset_8;  // Placeholder
    int32_t unknown_offset_C;  // Placeholder
    int32_t unknown_offset_10; // Placeholder
    int32_t unknown_offset_14; // Placeholder
    int32_t unknown_offset_18; // Placeholder
    int32_t unknown_offset_1C; // Placeholder
    int32_t unknown_offset_20; // Placeholder
    int32_t unknown_offset_24; // Placeholder
    float boundingBoxMinX;
    float boundingBoxMinY;
    float boundingBoxMinZ;
    // In GtPolygonSoup (from PS2):
    // 0x2C: numPolygons (int32_t)
    // 0x30: numVertices (int32_t) -> this seems to be total vertices in the pool
    // 0x34: unknown_or_vertex_type_flags (int32_t)
    // 0x38: unknown_or_padding (int32_t)
    // The C decompilation implies these might be interpreted differently or are part of a larger context.
    // For now, using names from the plan that are more generic.
    int32_t numPolygons_or_stride;
    int32_t numVertices_or_count;
    int32_t flags_or_type;         // Placeholder based on common struct patterns
    int32_t padding_or_reserved;   // Placeholder
}; // Target sizeof=0x3C (60 bytes)

struct ALIGNED_DECL(16) GtPolygonSoup { // Target sizeof=0x3C
    GtPolygonSoupHeader header;
};

struct ALIGNED_DECL(16) GtPolygonSoup16 { // Target sizeof=0x3C
    GtPolygonSoupHeader header; // Assuming same header structure for now
};

struct ALIGNED_DECL(16) GtPolygonIntersectionResult { // Target sizeof=0x6C (108 bytes)
    GtMath::Vector4 intersectionPoint;
    GtMath::Vector4 surfaceNormal;
    // Original decomp has:
    // 0x00: intersectionPoint.x, y, z, t (float t for ray)
    // 0x10: surfaceNormal.x, y, z, w (w might be unused or sign for normal direction)
    // 0x20 - 0x4F: 48 bytes of unknown data, possibly related to material, texture coords, etc.
    // For now, using a simple padding array.
    uint8_t unknown_data_area[48];
    float intersection_t_value; // Renamed to avoid conflict with point.w if that's used for t
    float barycentric_u;
    float barycentric_v;
    uint32_t hit_tag;           // Placeholder, often collision systems have tags/IDs for hits
    const void* pPolygonIndices;
    int32_t subPolygonIndex;    // (e.g. triangle 0 or 1 if quad)
    const void* pVertexBase;    // Base pointer for vertex data for this polygon
    // Total size: 16 (point) + 16 (normal) + 48 (unknown) + 4(t) + 4(u) + 4(v) + 4(tag) + 8(pPoly) + 4(subIdx) + 8(pVert) = 108 bytes
};

struct GtLine {
    GtMath::Vector3 origin;
    GtMath::Vector3 direction; // Should be normalized if using t as distance
    float length;

    // Default constructor
    GtLine() : origin({0,0,0}), direction({0,0,1}), length(-1.0f) {}

    GtLine(const GtMath::Vector3& o, const GtMath::Vector3& d, float l = -1.0f)
        : origin(o), direction(d), length(l) {}
};

// Assuming GtMath::Plane is defined in GtMath.h and has a structure like:
// struct Plane { float normal_x, normal_y, normal_z, d; };
// where N.X - d = 0 for a point X on the plane.
struct GtFrustum { // sizeof=0x60 (6 planes * 16 bytes/plane if Plane is Vector4-like)
    GtMath::Plane planes[6]; // Standard: Left, Right, Bottom, Top, Near, Far
};

struct GtSimpleOrientedBox { // sizeof=0x80
    GtMath::Vector3 corners[8]; // 8 corners of the oriented box
};

struct GtOrthogonalBox { // sizeof=0x40 (Center + 2 Axes + HalfExtents = 4*16 = 64 bytes)
    GtMath::Vector3 center;
    GtMath::Vector3 basisAxisX; // Normalized local X axis
    GtMath::Vector3 basisAxisY; // Normalized local Y axis
    // Z-axis is derived: cross(basisAxisX, basisAxisY)
    GtMath::Vector3 halfExtents; // Half-lengths along own basis axes (X, Y, Z)
};

// For GtExtrudedBox, to fit a general intersection routine based on vertices,
// we will assume it's also represented by 8 corners, similar to GtSimpleOrientedBox.
// This implies the caller pre-computes the vertices of the extruded shape.
// This is a simplification as the true structure might be more complex (e.g., base + extrusion vector).
// Size matches GtSimpleOrientedBox if it holds 8 GtMath::Vector3 (8 * 16 = 128 bytes = 0x80).
// The original C struct GtExtrudedBox was 0x40. This definition deviates due to chosen testing strategy.
// If GtExtrudedBox truly is 0x40, it cannot hold 8 general corners.
// Let's define it based on the C struct size and common interpretation:
// A base (defined by a center and two edges/extents) and an extrusion vector.
// This would be:
// GtMath::Vector3 base_corner_or_center;
// GtMath::Vector3 base_edge1_or_extent1;
// GtMath::Vector3 base_edge2_or_extent2;
// GtMath::Vector3 extrusion_vector_and_length;
// This still implies the test function needs to generate 8 vertices.
// For now, to align with the plan's later use of IntersectFrustumSimpleOrientedBox,
// I'll define GtExtrudedBox AS GtSimpleOrientedBox. This is a known simplification/deviation.
struct GtExtrudedBox { // sizeof=0x80 (assuming 8 corners for testing purposes)
    GtMath::Vector3 corners[8];
};

// Simplified GtConvexHull for clipping purposes.
// Assumes it provides access to an array of planes defining the hull.
struct GtConvexHull {
    const GtMath::Plane* planes; // Array of planes forming the convex hull
    int numPlanes;               // Number of planes in the array

    // Constructor for convenience
    GtConvexHull(const GtMath::Plane* p = nullptr, int n = 0) : planes(p), numPlanes(n) {}
};


class GtIntersection {
public:
    static bool IntersectSphereTriangle(
        const GtMath::Vector4& sphere, // x,y,z = center, w = radius
        const GtMath::Vector3& p0,
        const GtMath::Vector3& p1,
        const GtMath::Vector3& p2,
        GtMath::Vector3* outIntersectionPoint // Optional: point of intersection
    );

    static bool IntersectLineTriangle(
        const GtLine& line,
        const GtMath::Vector3& v0,
        const GtMath::Vector3& v1,
        const GtMath::Vector3& v2,
        float* outT,                      // Output: distance along the line's direction
        float* outU,                      // Output: barycentric U
        float* outV,                      // Output: barycentric V
        GtMath::Vector3* outIntersectionPoint // Optional output: point of intersection
    );

    static bool IntersectLineNearest(
        const GtLine& line,
        const GtPolygonSoup& polygonSoup,
        GtPolygonIntersectionResult* outResult
    );

    static bool IntersectLineNearest(
        const GtLine& line,
        const GtPolygonSoup16& polygonSoup16,
        GtPolygonIntersectionResult* outResult
    );

    // Callback function type definition
    typedef bool (*IntersectLineCallback)(
        const GtPolygonIntersectionResult& intersectionResult,
        void* userData
    );

    static bool IntersectLine(
        const GtLine& line,
        const GtPolygonSoup& polygonSoup,
        IntersectLineCallback callback,
        void* userData
    );

    static bool IntersectLine(
        const GtLine& line,
        const GtPolygonSoup16& polygonSoup16,
        IntersectLineCallback callback,
        void* userData
    );

    static bool IntersectLineAABB(
        const GtLine& line,
        const GtMath::Vector3& boxMin,
        const GtMath::Vector3& boxMax,
        float* outEntryT, // Optional: entry t-value
        float* outExitT   // Optional: exit t-value
    );

    static bool IntersectSphereAABB(
        const GtMath::Vector4& sphere, // x,y,z=center, w=radius
        const GtMath::Vector3& boxMin,
        const GtMath::Vector3& boxMax
    );

    static bool IntersectSphereFrustum(
        const GtMath::Vector4& sphere, // x,y,z=center, w=radius
        const GtFrustum& frustum
    );
    // Static methods will be declared here

    // Callback function type specifically for sphere intersections
    typedef bool (*IntersectSphereCallback)(
        const GtPolygonIntersectionResult& intersectionResult, // Re-using this struct
        void* userData
    );

    static bool IntersectSphere(
        const GtMath::Vector4& sphere, // x,y,z=center, w=radius
        const GtPolygonSoup& polygonSoup,
        IntersectSphereCallback callback,
        void* userData
    );

    static bool IntersectSphere(
        const GtMath::Vector4& sphere, // x,y,z=center, w=radius
        const GtPolygonSoup16& polygonSoup16,
        IntersectSphereCallback callback,
        void* userData
    );

    // Frustum vs Box intersection functions
    static bool IntersectFrustumSimpleOrientedBox(
        const GtFrustum& frustum,
        const GtSimpleOrientedBox& box
    );

    static bool IntersectFrustumOrthogonalBox(
        const GtFrustum& frustum,
        const GtOrthogonalBox& box
    );

    static bool IntersectFrustumExtrudedBox(
        const GtFrustum& frustum,
        const GtExtrudedBox& extrudedBox // Assumed to be 8 corners like GtSimpleOrientedBox
    );

    static int ClipPolyWithConvexHull(
        const GtMath::Vector3* inputPolygonVertices, // Input polygon
        int numInputVertices,
        const GtConvexHull& convexHull,             // Hull to clip against
        GtMath::Vector3* outputPolygonVerticesBuffer, // Buffer for clipped vertices
        int maxOutputVertices,                      // Max size of output buffer
        GtMath::Vector3* outOptionalLastPlaneNormal // Optional: Normal of a significant clipping plane
    );
};

} // namespace Gt

#endif // GT_INTERSECTION_H
