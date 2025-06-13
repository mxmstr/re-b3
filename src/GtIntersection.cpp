#include "GtIntersection.h"
#include "GtMath.h"
#include <cmath> // For std::sqrt, std::fabs, std::abs
#include <algorithm> // For std::min, std::max
#include <limits> // Required for std::numeric_limits
#include <type_traits> // Required for std::is_same

namespace Gt {

// Helper function to find the closest point on a line segment to a point
static GtMath::Vector3 ClosestPointOnSegment(const GtMath::Vector3& p, const GtMath::Vector3& a, const GtMath::Vector3& b) {
    GtMath::Vector3 ab = GtMath::subtract(b, a);
    GtMath::Vector3 ap = GtMath::subtract(p, a);
    float ab_len_sq = GtMath::dot_product(ab, ab);
    if (ab_len_sq < std::numeric_limits<float>::epsilon()) { // Avoid division by zero if a and b are the same
        return a;
    }
    float t = GtMath::dot_product(ap, ab) / ab_len_sq;
    t = std::max(0.0f, std::min(1.0f, t)); // Clamp t to [0,1]
    return GtMath::add(a, GtMath::multiply_scalar(ab, t));
}

// Helper function: Projects point p onto plane defined by normal n and point on_plane
static GtMath::Vector3 ProjectPointOnPlane(const GtMath::Vector3& p, const GtMath::Vector3& normal, const GtMath::Vector3& point_on_plane) {
    float dist_to_plane = GtMath::dot_product(GtMath::subtract(p, point_on_plane), normal);
    return GtMath::subtract(p, GtMath::multiply_scalar(normal, dist_to_plane));
}

// Helper: Is point P inside triangle defined by v0, v1, v2 (assuming P is on the plane of the triangle)
static bool IsPointInTriangle(const GtMath::Vector3& p, const GtMath::Vector3& v0, const GtMath::Vector3& v1, const GtMath::Vector3& v2) {
    // Compute vectors
    GtMath::Vector3 v0v1 = GtMath::subtract(v1, v0);
    GtMath::Vector3 v0v2 = GtMath::subtract(v2, v0);
    GtMath::Vector3 pv0 = GtMath::subtract(p, v0);

    // Compute dot products
    float dot00 = GtMath::dot_product(v0v1, v0v1);
    float dot01 = GtMath::dot_product(v0v1, v0v2);
    float dot02 = GtMath::dot_product(v0v1, pv0);
    float dot11 = GtMath::dot_product(v0v2, v0v2);
    float dot12 = GtMath::dot_product(v0v2, pv0);

    // Compute barycentric coordinates
    float invDenom = (dot00 * dot11 - dot01 * dot01);
    // Check if denominator is near zero (degenerate triangle)
    if (std::fabs(invDenom) < std::numeric_limits<float>::epsilon()) {
        // Degenerate triangle (collinear vertices).
        // Check if p lies on the segment formed by the longest side.
        // This is a simplified fallback. For true robustness, collinearity needs careful handling.
        float d_p_v0 = GtMath::length_squared(GtMath::subtract(p,v0));
        float d_p_v1 = GtMath::length_squared(GtMath::subtract(p,v1));
        float d_p_v2 = GtMath::length_squared(GtMath::subtract(p,v2));
        float d_v0_v1 = GtMath::length_squared(v0v1);
        float d_v0_v2 = GtMath::length_squared(v0v2);
        float d_v1_v2 = GtMath::length_squared(GtMath::subtract(v2,v1));

        if (d_v0_v1 > d_v0_v2 && d_v0_v1 > d_v1_v2) return GtMath::length_squared(GtMath::subtract(ClosestPointOnSegment(p,v0,v1),p)) < std::numeric_limits<float>::epsilon();
        if (d_v0_v2 > d_v1_v2) return GtMath::length_squared(GtMath::subtract(ClosestPointOnSegment(p,v0,v2),p)) < std::numeric_limits<float>::epsilon();
        return GtMath::length_squared(GtMath::subtract(ClosestPointOnSegment(p,v1,v2),p)) < std::numeric_limits<float>::epsilon();
    }
    invDenom = 1.0f / invDenom;

    float u = (dot11 * dot02 - dot01 * dot12) * invDenom;
    float v = (dot00 * dot12 - dot01 * dot02) * invDenom;

    // Check if point is in triangle (or on edge)
    return (u >= -std::numeric_limits<float>::epsilon()) && (v >= -std::numeric_limits<float>::epsilon()) && (u + v <= 1.0f + std::numeric_limits<float>::epsilon());
}


bool GtIntersection::IntersectSphereTriangle(
    const GtMath::Vector4& sphere,
    const GtMath::Vector3& p0,
    const GtMath::Vector3& p1,
    const GtMath::Vector3& p2,
    GtMath::Vector3* outIntersectionPoint) {

    GtMath::Vector3 sphere_center = {sphere.x, sphere.y, sphere.z};
    float sphere_radius = sphere.w;
    float radius_sq = sphere_radius * sphere_radius;

    if (radius_sq < 0) return false; // Invalid radius

    // 1. Find point P_plane on triangle plane closest to sphere center
    GtMath::Vector3 edge01 = GtMath::subtract(p1, p0);
    GtMath::Vector3 edge02 = GtMath::subtract(p2, p0);
    GtMath::Vector3 normal = GtMath::cross_product(edge01, edge02);

    float normal_len_sq = GtMath::length_squared(normal);
    if (normal_len_sq < std::numeric_limits<float>::epsilon()) { // Degenerate triangle (collinear vertices)
        // Fallback: check intersection with the three line segments of the triangle
        GtMath::Vector3 cp01 = ClosestPointOnSegment(sphere_center, p0, p1);
        if (GtMath::length_squared(GtMath::subtract(sphere_center, cp01)) <= radius_sq) {
            if (outIntersectionPoint) *outIntersectionPoint = cp01;
            return true;
        }
        GtMath::Vector3 cp12 = ClosestPointOnSegment(sphere_center, p1, p2);
        if (GtMath::length_squared(GtMath::subtract(sphere_center, cp12)) <= radius_sq) {
            if (outIntersectionPoint) *outIntersectionPoint = cp12;
            return true;
        }
        GtMath::Vector3 cp20 = ClosestPointOnSegment(sphere_center, p2, p0);
        if (GtMath::length_squared(GtMath::subtract(sphere_center, cp20)) <= radius_sq) {
            if (outIntersectionPoint) *outIntersectionPoint = cp20;
            return true;
        }
        return false;
    }
    normal = GtMath::normalize_unsafe(normal, std::sqrt(normal_len_sq));

    // Distance from p0 to sphere_center projected onto normal
    float dist_center_to_plane = GtMath::dot_product(GtMath::subtract(sphere_center, p0), normal);

    // Point P_plane on plane closest to sphere center
    GtMath::Vector3 P_plane = GtMath::subtract(sphere_center, GtMath::multiply_scalar(normal, dist_center_to_plane));

    GtMath::Vector3 closest_point_on_triangle;

    // 2. Check if P_plane is inside triangle (p0, p1, p2)
    if (IsPointInTriangle(P_plane, p0, p1, p2)) {
        closest_point_on_triangle = P_plane;
    } else {
        // 3. If P_plane is outside, the closest point is on an edge or vertex
        GtMath::Vector3 cp01 = ClosestPointOnSegment(sphere_center, p0, p1);
        float d_sq_cp01 = GtMath::length_squared(GtMath::subtract(sphere_center, cp01));

        GtMath::Vector3 cp12 = ClosestPointOnSegment(sphere_center, p1, p2);
        float d_sq_cp12 = GtMath::length_squared(GtMath::subtract(sphere_center, cp12));

        GtMath::Vector3 cp20 = ClosestPointOnSegment(sphere_center, p2, p0);
        float d_sq_cp20 = GtMath::length_squared(GtMath::subtract(sphere_center, cp20));

        if (d_sq_cp01 <= d_sq_cp12 && d_sq_cp01 <= d_sq_cp20) {
            closest_point_on_triangle = cp01;
        } else if (d_sq_cp12 <= d_sq_cp01 && d_sq_cp12 <= d_sq_cp20) {
            closest_point_on_triangle = cp12;
        } else {
            closest_point_on_triangle = cp20;
        }
    }

    // Final check: distance from sphere center to the closest point on triangle vs sphere radius
    if (GtMath::length_squared(GtMath::subtract(sphere_center, closest_point_on_triangle)) <= radius_sq) {
        if (outIntersectionPoint) {
            *outIntersectionPoint = closest_point_on_triangle;
        }
        return true;
    }

    return false; // No intersection
}

bool GtIntersection::IntersectLineTriangle(
    const GtLine& line,
    const GtMath::Vector3& v0,
    const GtMath::Vector3& v1,
    const GtMath::Vector3& v2,
    float* outT,
    float* outU,
    float* outV,
    GtMath::Vector3* outIntersectionPoint) {

    const float EPSILON = 1e-6f; // Small epsilon for floating point comparisons

    GtMath::Vector3 edge1 = GtMath::subtract(v1, v0);
    GtMath::Vector3 edge2 = GtMath::subtract(v2, v0);

    // Calculate determinant
    GtMath::Vector3 pvec = GtMath::cross_product(line.direction, edge2);
    float det = GtMath::dot_product(edge1, pvec);

    // If determinant is near zero, ray lies in plane of triangle or is parallel
    // Culling check: if det < EPSILON, ray intersects back face or is parallel
    // if (det < EPSILON) return false;
    // For two-sided intersection:
    if (std::abs(det) < EPSILON) {
        return false;
    }

    float invDet = 1.0f / det;

    // Calculate distance from v0 to ray origin
    GtMath::Vector3 tvec = GtMath::subtract(line.origin, v0);

    // Calculate u parameter and test bounds
    float u = GtMath::dot_product(tvec, pvec) * invDet;
    if (u < -EPSILON || u > 1.0f + EPSILON) { // Add tolerance for u
        return false;
    }

    // Prepare to test v parameter
    GtMath::Vector3 qvec = GtMath::cross_product(tvec, edge1);

    // Calculate v parameter and test bounds
    float v = GtMath::dot_product(line.direction, qvec) * invDet;
    if (v < -EPSILON || u + v > 1.0f + EPSILON) { // Add tolerance for v and u+v
        return false;
    }

    // Calculate t, ray intersects triangle
    float t = GtMath::dot_product(edge2, qvec) * invDet;

    // Check if the intersection point is behind the origin of the line (if t < 0)
    // Or beyond its length (if line.length is specified and positive)
    if (t < -EPSILON) { // Add tolerance for t
        return false;
    }
    if (line.length > 0.0f && t > line.length + EPSILON) { // Add tolerance for length check
        return false;
    }

    // Intersection occurred
    if (outT) {
        *outT = t;
    }
    if (outU) {
        *outU = u;
    }
    if (outV) {
        *outV = v;
    }
    if (outIntersectionPoint) {
        *outIntersectionPoint = GtMath::add(line.origin, GtMath::multiply_scalar(line.direction, t));
    }

    return true;
}

// Common helper logic for IntersectLineNearest
template<typename IndexType>
static bool IntersectLineNearestInternal(
    const GtLine& line,
    const GtPolygonSoupHeader& header,
    GtPolygonIntersectionResult* outResult) {

    if (!header.pIndexData || !header.pVertexData || header.numPolygons_or_stride <= 0) {
        if (outResult) { // Initialize t_value if outResult is provided
             outResult->intersection_t_value = std::numeric_limits<float>::max();
        }
        return false;
    }

    // Ensure outResult is valid before dereferencing
    if (!outResult) return false; // Or handle error appropriately

    outResult->intersection_t_value = std::numeric_limits<float>::max();
    bool foundIntersection = false;

    const auto* vertexDataBase = static_cast<const uint8_t*>(header.pVertexData);
    const auto* indexDataBase = static_cast<const IndexType*>(header.pIndexData);

    IndexType triangleMarker = (std::is_same<IndexType, uint8_t>::value) ? 255 :
                               (std::is_same<IndexType, uint16_t>::value) ? 0xFFFF :
                               static_cast<IndexType>(-1); // Fallback for other types if any

    // This assumes header.numPolygons_or_stride is the count of polygon entries.
    // And each entry is 4 indices.
    for (int i = 0; i < header.numPolygons_or_stride; ++i) {
        const IndexType* polyIndices = indexDataBase + (i * 4);

        IndexType idx0 = polyIndices[0];
        IndexType idx1 = polyIndices[1];
        IndexType idx2 = polyIndices[2];

        // Assuming pVertexData points to an array of GtMath::Vector3 structures.
        // Stride is assumed to be sizeof(GtMath::Vector3). This is a CRITICAL assumption.
        // If vertices are e.g. float x,y,z tightly packed, this will be wrong.
        const GtMath::Vector3& v0 = *reinterpret_cast<const GtMath::Vector3*>(vertexDataBase + idx0 * sizeof(GtMath::Vector3));
        const GtMath::Vector3& v1 = *reinterpret_cast<const GtMath::Vector3*>(vertexDataBase + idx1 * sizeof(GtMath::Vector3));
        const GtMath::Vector3& v2 = *reinterpret_cast<const GtMath::Vector3*>(vertexDataBase + idx2 * sizeof(GtMath::Vector3));

        float currentT, currentU, currentV;
        GtMath::Vector3 currentIntersectionPoint;

        if (GtIntersection::IntersectLineTriangle(line, v0, v1, v2, &currentT, &currentU, &currentV, &currentIntersectionPoint)) {
            if (currentT >= 0.0f && currentT < outResult->intersection_t_value) {
                foundIntersection = true;
                outResult->intersection_t_value = currentT;
                outResult->barycentric_u = currentU;
                outResult->barycentric_v = currentV;
                outResult->intersectionPoint.x = currentIntersectionPoint.x;
                outResult->intersectionPoint.y = currentIntersectionPoint.y;
                outResult->intersectionPoint.z = currentIntersectionPoint.z;
                outResult->intersectionPoint.w = currentT;

                GtMath::Vector3 edge01 = GtMath::subtract(v1,v0);
                GtMath::Vector3 edge02 = GtMath::subtract(v2,v0);
                GtMath::Vector3 normal = GtMath::normalize(GtMath::cross_product(edge01, edge02));
                outResult->surfaceNormal.x = normal.x;
                outResult->surfaceNormal.y = normal.y;
                outResult->surfaceNormal.z = normal.z;
                outResult->surfaceNormal.w = 0.0f;

                outResult->pPolygonIndices = polyIndices;
                outResult->subPolygonIndex = 0;
                outResult->pVertexBase = header.pVertexData;
            }
        }

        IndexType idx3 = polyIndices[3];
        if (idx3 != triangleMarker) {
            const GtMath::Vector3& v3 = *reinterpret_cast<const GtMath::Vector3*>(vertexDataBase + idx3 * sizeof(GtMath::Vector3));
            if (GtIntersection::IntersectLineTriangle(line, v0, v2, v3, &currentT, &currentU, &currentV, &currentIntersectionPoint)) {
                if (currentT >= 0.0f && currentT < outResult->intersection_t_value) {
                    foundIntersection = true;
                    outResult->intersection_t_value = currentT;
                    outResult->barycentric_u = currentU;
                    outResult->barycentric_v = currentV;
                    outResult->intersectionPoint.x = currentIntersectionPoint.x;
                    outResult->intersectionPoint.y = currentIntersectionPoint.y;
                    outResult->intersectionPoint.z = currentIntersectionPoint.z;
                    outResult->intersectionPoint.w = currentT;

                    GtMath::Vector3 edge02_q = GtMath::subtract(v2,v0); // Use different names to avoid redef
                    GtMath::Vector3 edge03_q = GtMath::subtract(v3,v0);
                    GtMath::Vector3 normal = GtMath::normalize(GtMath::cross_product(edge02_q, edge03_q));
                    outResult->surfaceNormal.x = normal.x;
                    outResult->surfaceNormal.y = normal.y;
                    outResult->surfaceNormal.z = normal.z;
                    outResult->surfaceNormal.w = 0.0f;

                    outResult->pPolygonIndices = polyIndices;
                    outResult->subPolygonIndex = 1;
                    outResult->pVertexBase = header.pVertexData;
                }
            }
        }
    }
    return foundIntersection;
}

bool GtIntersection::IntersectLineNearest(
    const GtLine& line,
    const GtPolygonSoup& polygonSoup,
    GtPolygonIntersectionResult* outResult) {

    if (!outResult) return false; // Early exit if no result struct provided
    return IntersectLineNearestInternal<uint8_t>(line, polygonSoup.header, outResult);
}

bool GtIntersection::IntersectLineNearest(
    const GtLine& line,
    const GtPolygonSoup16& polygonSoup16,
    GtPolygonIntersectionResult* outResult) {

    if (!outResult) return false; // Early exit if no result struct provided
    return IntersectLineNearestInternal<uint16_t>(line, polygonSoup16.header, outResult);
}

// Common helper logic for IntersectLine (with callback)
template<typename IndexType>
static bool IntersectLineInternal(
    const GtLine& line,
    const GtPolygonSoupHeader& header,
    GtIntersection::IntersectLineCallback callback, // Callback is part of GtIntersection class
    void* userData) {

    // Note: callback non-null check should be done by public callers
    if (!header.pIndexData || !header.pVertexData || header.numPolygons_or_stride <= 0) {
        return false;
    }

    bool anyHitOccurred = false;
    bool continueProcessing = true;

    const auto* vertexDataBase = static_cast<const uint8_t*>(header.pVertexData);
    const auto* indexDataBase = static_cast<const IndexType*>(header.pIndexData);

    IndexType triangleMarker = (std::is_same<IndexType, uint8_t>::value) ? 255 :
                               (std::is_same<IndexType, uint16_t>::value) ? 0xFFFF :
                               static_cast<IndexType>(-1);


    for (int i = 0; i < header.numPolygons_or_stride && continueProcessing; ++i) {
        const IndexType* polyIndices = indexDataBase + (i * 4);

        IndexType idx0 = polyIndices[0];
        IndexType idx1 = polyIndices[1];
        IndexType idx2 = polyIndices[2];

        const GtMath::Vector3& v0 = *reinterpret_cast<const GtMath::Vector3*>(vertexDataBase + idx0 * sizeof(GtMath::Vector3));
        const GtMath::Vector3& v1 = *reinterpret_cast<const GtMath::Vector3*>(vertexDataBase + idx1 * sizeof(GtMath::Vector3));
        const GtMath::Vector3& v2 = *reinterpret_cast<const GtMath::Vector3*>(vertexDataBase + idx2 * sizeof(GtMath::Vector3));

        float currentT, currentU, currentV;
        GtMath::Vector3 currentIntersectionPoint;
        GtPolygonIntersectionResult currentResult;

        if (GtIntersection::IntersectLineTriangle(line, v0, v1, v2, &currentT, &currentU, &currentV, &currentIntersectionPoint)) {
            // Check line.length constraint if t is valid
            bool length_ok = true;
            if (line.length > 0.0f && currentT > line.length + 1e-6f) { // Apply epsilon to length check
                length_ok = false;
            }

            if (currentT >= -1e-6f && length_ok) { // Apply epsilon to t >= 0 check
                anyHitOccurred = true;
                currentResult.intersection_t_value = currentT;
                currentResult.barycentric_u = currentU;
                currentResult.barycentric_v = currentV;
                currentResult.intersectionPoint.x = currentIntersectionPoint.x;
                currentResult.intersectionPoint.y = currentIntersectionPoint.y;
                currentResult.intersectionPoint.z = currentIntersectionPoint.z;
                currentResult.intersectionPoint.w = currentT;

                GtMath::Vector3 edge01 = GtMath::subtract(v1,v0);
                GtMath::Vector3 edge02 = GtMath::subtract(v2,v0);
                GtMath::Vector3 normal = GtMath::normalize(GtMath::cross_product(edge01, edge02));
                currentResult.surfaceNormal.x = normal.x;
                currentResult.surfaceNormal.y = normal.y;
                currentResult.surfaceNormal.z = normal.z;
                currentResult.surfaceNormal.w = 0.0f;

                currentResult.pPolygonIndices = polyIndices;
                currentResult.subPolygonIndex = 0;
                currentResult.pVertexBase = header.pVertexData;
                // currentResult.hit_tag and currentResult.unknown_data_area remain uninitialized

                if (!callback(currentResult, userData)) {
                    continueProcessing = false;
                }
            }
        }

        if (!continueProcessing) break;

        IndexType idx3 = polyIndices[3];
        if (idx3 != triangleMarker) {
            const GtMath::Vector3& v3 = *reinterpret_cast<const GtMath::Vector3*>(vertexDataBase + idx3 * sizeof(GtMath::Vector3));
            if (GtIntersection::IntersectLineTriangle(line, v0, v2, v3, &currentT, &currentU, &currentV, &currentIntersectionPoint)) {
                bool length_ok_q = true;
                if (line.length > 0.0f && currentT > line.length + 1e-6f) {
                    length_ok_q = false;
                }

                if (currentT >= -1e-6f && length_ok_q) {
                    anyHitOccurred = true;
                    // Repopulate currentResult for the second triangle
                    currentResult.intersection_t_value = currentT;
                    currentResult.barycentric_u = currentU;
                    currentResult.barycentric_v = currentV;
                    currentResult.intersectionPoint.x = currentIntersectionPoint.x;
                    currentResult.intersectionPoint.y = currentIntersectionPoint.y;
                    currentResult.intersectionPoint.z = currentIntersectionPoint.z;
                    currentResult.intersectionPoint.w = currentT;

                    GtMath::Vector3 edge02_q = GtMath::subtract(v2,v0);
                    GtMath::Vector3 edge03_q = GtMath::subtract(v3,v0);
                    GtMath::Vector3 normal_q = GtMath::normalize(GtMath::cross_product(edge02_q, edge03_q));
                    currentResult.surfaceNormal.x = normal_q.x;
                    currentResult.surfaceNormal.y = normal_q.y;
                    currentResult.surfaceNormal.z = normal_q.z;
                    currentResult.surfaceNormal.w = 0.0f;

                    currentResult.pPolygonIndices = polyIndices;
                    currentResult.subPolygonIndex = 1;
                    currentResult.pVertexBase = header.pVertexData;
                    // currentResult.hit_tag and currentResult.unknown_data_area remain uninitialized

                    if (!callback(currentResult, userData)) {
                        continueProcessing = false;
                    }
                }
            }
        }
    }
    return anyHitOccurred;
}

bool GtIntersection::IntersectLine(
    const GtLine& line,
    const GtPolygonSoup& polygonSoup,
    IntersectLineCallback callback,
    void* userData) {
    if (!callback) return false; // Crucial check
    return IntersectLineInternal<uint8_t>(line, polygonSoup.header, callback, userData);
}

bool GtIntersection::IntersectLine(
    const GtLine& line,
    const GtPolygonSoup16& polygonSoup16,
    IntersectLineCallback callback,
    void* userData) {
    if (!callback) return false; // Crucial check
    return IntersectLineInternal<uint16_t>(line, polygonSoup16.header, callback, userData);
}

bool GtIntersection::IntersectLineAABB(
    const GtLine& line,
    const GtMath::Vector3& boxMin,
    const GtMath::Vector3& boxMax,
    float* outEntryT,
    float* outExitT) {

    float tmin = -std::numeric_limits<float>::max();
    float tmax = std::numeric_limits<float>::max();

    const GtMath::Vector3& rayOrigin = line.origin;
    const GtMath::Vector3& rayDir = line.direction;
    const float epsilon = 1e-6f; // Epsilon for float comparisons

    // X slab
    if (std::abs(rayDir.x) < epsilon) {
        if (rayOrigin.x < boxMin.x - epsilon || rayOrigin.x > boxMax.x + epsilon) return false;
    } else {
        float ood = 1.0f / rayDir.x;
        float t1 = (boxMin.x - rayOrigin.x) * ood;
        float t2 = (boxMax.x - rayOrigin.x) * ood;
        if (t1 > t2) std::swap(t1, t2);
        tmin = std::max(tmin, t1);
        tmax = std::min(tmax, t2);
        if (tmin > tmax + epsilon) return false; // Add epsilon for tmin > tmax check
    }

    // Y slab
    if (std::abs(rayDir.y) < epsilon) {
        if (rayOrigin.y < boxMin.y - epsilon || rayOrigin.y > boxMax.y + epsilon) return false;
    } else {
        float ood = 1.0f / rayDir.y;
        float t1 = (boxMin.y - rayOrigin.y) * ood;
        float t2 = (boxMax.y - rayOrigin.y) * ood;
        if (t1 > t2) std::swap(t1, t2);
        tmin = std::max(tmin, t1);
        tmax = std::min(tmax, t2);
        if (tmin > tmax + epsilon) return false;
    }

    // Z slab
    if (std::abs(rayDir.z) < epsilon) {
        if (rayOrigin.z < boxMin.z - epsilon || rayOrigin.z > boxMax.z + epsilon) return false;
    } else {
        float ood = 1.0f / rayDir.z;
        float t1 = (boxMin.z - rayOrigin.z) * ood;
        float t2 = (boxMax.z - rayOrigin.z) * ood;
        if (t1 > t2) std::swap(t1, t2);
        tmin = std::max(tmin, t1);
        tmax = std::min(tmax, t2);
        if (tmin > tmax + epsilon) return false;
    }

    // Overall validity check:
    // The intersection interval [tmin, tmax] must overlap with line segment interval [0, line.length]
    // (or [0, infinity] if line.length <= 0)

    float effective_line_length = (line.length <= 0.0f) ? std::numeric_limits<float>::max() : line.length;

    // Check if the intersection is entirely "behind" the ray origin OR
    // if the "entry" into the box is already past the line's effective length.
    if (tmax < -epsilon || tmin > effective_line_length + epsilon) {
        return false;
    }

    // Clamp tmin to be at least 0 (can't start before ray origin)
    tmin = std::max(tmin, 0.0f);

    // If after clamping tmin, it's now greater than tmax, no valid segment.
    if (tmin > tmax + epsilon) { // Check again after clamping tmin
        return false;
    }

    // If tmin is now beyond line length after clamping, no valid intersection on segment
    if (tmin > effective_line_length + epsilon) {
        return false;
    }


    if (outEntryT) *outEntryT = tmin;
    if (outExitT) *outExitT = std::min(tmax, effective_line_length); // Exit T cannot exceed line length
    return true;
}

bool GtIntersection::IntersectSphereAABB(
    const GtMath::Vector4& sphere,
    const GtMath::Vector3& boxMin,
    const GtMath::Vector3& boxMax) {

    GtMath::Vector3 sphereCenter = {sphere.x, sphere.y, sphere.z};
    float sphereRadius = sphere.w;
    if (sphereRadius < 0.0f) return false; // Invalid radius, though radius squared handles it

    // Find the point on the AABB closest to the sphere center
    float closestX = std::max(boxMin.x, std::min(sphereCenter.x, boxMax.x));
    float closestY = std::max(boxMin.y, std::min(sphereCenter.y, boxMax.y));
    float closestZ = std::max(boxMin.z, std::min(sphereCenter.z, boxMax.z));

    GtMath::Vector3 closestPointOnBox = {closestX, closestY, closestZ};

    // Calculate squared distance between sphere center and closest point on box
    GtMath::Vector3 distVec = GtMath::subtract(sphereCenter, closestPointOnBox);
    float distSq = GtMath::length_squared(distVec);
    float radiusSq = sphereRadius * sphereRadius;

    return distSq <= radiusSq;
}

bool GtIntersection::IntersectSphereFrustum(
    const GtMath::Vector4& sphere, // x,y,z=center, w=radius
    const GtFrustum& frustum) {

    GtMath::Vector3 sphereCenter = {sphere.x, sphere.y, sphere.z};
    float sphereRadius = sphere.w;
    // It's generally good practice to check for negative radius,
    // though for distance checks, radius^2 is often used.
    // If radius is negative, it implies an invalid sphere.
    if (sphereRadius < 0.0f) return false;

    for (int i = 0; i < 6; ++i) {
        const GtMath::Plane& plane = frustum.planes[i];
        // Assuming GtMath::Plane stores normal components directly
        // and 'd' is such that N.X - d = 0 for a point X on the plane.
        // Normal components might be plane.x, plane.y, plane.z or plane.normal.x etc.
        // Based on GtMath.h structure, GtPlane has normal_x, normal_y, normal_z, d
        GtMath::Vector3 planeNormal = {plane.normal_x, plane.normal_y, plane.normal_z};

        // Distance from sphere center to plane: (Dot(Center, Normal) - plane.d)
        // This gives signed distance. Positive if on normal side, negative if on opposite.
        float distance = GtMath::dot_product(sphereCenter, planeNormal) - plane.d;

        // If the sphere center is further than its radius on the "outside" (positive distance)
        // side of the plane, then the sphere is entirely outside this plane and thus outside the frustum.
        if (distance > sphereRadius) {
            return false;
        }
        // Optional: A more complex check for "fully inside" would be:
        // if (distance < -sphereRadius) { /* sphere is fully on the "inside" of this plane */ }
        // But for simple intersection, we only need to check for the "outside" case.
    }

    // If the sphere is not outside any of the 6 planes, it is considered to be intersecting the frustum.
    // This includes cases where the sphere is fully contained within the frustum.
    return true;
}

// Common helper logic for IntersectSphere (with callback)
template<typename IndexType>
static bool IntersectSphereInternal(
    const GtMath::Vector4& sphereDesc, // x,y,z=center, w=radius
    const GtPolygonSoupHeader& header,
    GtIntersection::IntersectSphereCallback callback,
    void* userData) {

    // Callback non-null and valid radius checks are expected to be done by public callers
    if (!header.pIndexData || !header.pVertexData || header.numPolygons_or_stride <= 0 ) {
        return false;
    }

    bool anyHitOccurred = false;
    bool continueProcessing = true;

    const auto* vertexDataBase = static_cast<const uint8_t*>(header.pVertexData);
    const auto* indexDataBase = static_cast<const IndexType*>(header.pIndexData);

    IndexType triangleMarker = (std::is_same<IndexType, uint8_t>::value) ? 255 :
                               (std::is_same<IndexType, uint16_t>::value) ? 0xFFFF :
                               static_cast<IndexType>(-1);

    GtMath::Vector3 sphereCenter = {sphereDesc.x, sphereDesc.y, sphereDesc.z};
    float sphereRadius = sphereDesc.w;

    for (int i = 0; i < header.numPolygons_or_stride && continueProcessing; ++i) {
        const IndexType* polyIndices = indexDataBase + (i * 4);

        IndexType idx0 = polyIndices[0];
        IndexType idx1 = polyIndices[1];
        IndexType idx2 = polyIndices[2];

        const GtMath::Vector3& v0 = *reinterpret_cast<const GtMath::Vector3*>(vertexDataBase + idx0 * sizeof(GtMath::Vector3));
        const GtMath::Vector3& v1 = *reinterpret_cast<const GtMath::Vector3*>(vertexDataBase + idx1 * sizeof(GtMath::Vector3));
        const GtMath::Vector3& v2 = *reinterpret_cast<const GtMath::Vector3*>(vertexDataBase + idx2 * sizeof(GtMath::Vector3));

        GtPolygonIntersectionResult currentResult; // Initialize fields to ensure clean state
        std::memset(&currentResult, 0, sizeof(GtPolygonIntersectionResult)); // Zero out the struct
        GtMath::Vector3 contactPoint;

        if (GtIntersection::IntersectSphereTriangle(sphereDesc, v0, v1, v2, &contactPoint)) {
            anyHitOccurred = true;

            currentResult.intersectionPoint.x = contactPoint.x;
            currentResult.intersectionPoint.y = contactPoint.y;
            currentResult.intersectionPoint.z = contactPoint.z;
            currentResult.intersectionPoint.w = 0.0f; // Not a 't' distance for ray

            GtMath::Vector3 edge01 = GtMath::subtract(v1,v0);
            GtMath::Vector3 edge02 = GtMath::subtract(v2,v0);
            GtMath::Vector3 normal = GtMath::normalize_safe(GtMath::cross_product(edge01, edge02)); // Use safe normalize
            currentResult.surfaceNormal.x = normal.x;
            currentResult.surfaceNormal.y = normal.y;
            currentResult.surfaceNormal.z = normal.z;
            currentResult.surfaceNormal.w = 0.0f;

            float dist_to_contact = std::sqrt(GtMath::length_squared(GtMath::subtract(sphereCenter, contactPoint)));
            currentResult.intersection_t_value = sphereRadius - dist_to_contact; // Penetration depth

            // Barycentric coordinates u,v are not directly computed by IntersectSphereTriangle.
            // Setting them to 0 or a sentinel. For now, they are zeroed by memset.
            // currentResult.barycentric_u = 0.0f;
            // currentResult.barycentric_v = 0.0f;

            currentResult.pPolygonIndices = polyIndices;
            currentResult.subPolygonIndex = 0;
            currentResult.pVertexBase = header.pVertexData;
            // currentResult.unknown_data_area and currentResult.hit_tag are zeroed by memset.

            if (!callback(currentResult, userData)) {
                continueProcessing = false;
            }
        }

        if (!continueProcessing) break;

        IndexType idx3 = polyIndices[3];
        if (idx3 != triangleMarker) {
            const GtMath::Vector3& v3 = *reinterpret_cast<const GtMath::Vector3*>(vertexDataBase + idx3 * sizeof(GtMath::Vector3));
            // Reset part of currentResult for the new triangle, or re-initialize.
            std::memset(&currentResult, 0, sizeof(GtPolygonIntersectionResult));

            if (GtIntersection::IntersectSphereTriangle(sphereDesc, v0, v2, v3, &contactPoint)) {
                anyHitOccurred = true;

                currentResult.intersectionPoint.x = contactPoint.x;
                currentResult.intersectionPoint.y = contactPoint.y;
                currentResult.intersectionPoint.z = contactPoint.z;
                currentResult.intersectionPoint.w = 0.0f;

                GtMath::Vector3 edge02_q = GtMath::subtract(v2,v0);
                GtMath::Vector3 edge03_q = GtMath::subtract(v3,v0);
                GtMath::Vector3 normal_q = GtMath::normalize_safe(GtMath::cross_product(edge02_q, edge03_q)); // Safe normalize
                currentResult.surfaceNormal.x = normal_q.x;
                currentResult.surfaceNormal.y = normal_q.y;
                currentResult.surfaceNormal.z = normal_q.z;
                currentResult.surfaceNormal.w = 0.0f;

                float dist_to_contact_q = std::sqrt(GtMath::length_squared(GtMath::subtract(sphereCenter, contactPoint)));
                currentResult.intersection_t_value = sphereRadius - dist_to_contact_q; // Penetration depth

                currentResult.pPolygonIndices = polyIndices;
                currentResult.subPolygonIndex = 1; // Second triangle of the quad
                currentResult.pVertexBase = header.pVertexData;

                if (!callback(currentResult, userData)) {
                    continueProcessing = false;
                }
            }
        }
    }
    return anyHitOccurred;
}

bool GtIntersection::IntersectSphere(
    const GtMath::Vector4& sphere,
    const GtPolygonSoup& polygonSoup,
    IntersectSphereCallback callback,
    void* userData) {
    if (!callback || sphere.w < 0.0f) return false; // Check for valid radius
    return IntersectSphereInternal<uint8_t>(sphere, polygonSoup.header, callback, userData);
}

bool GtIntersection::IntersectSphere(
    const GtMath::Vector4& sphere,
    const GtPolygonSoup16& polygonSoup16,
    IntersectSphereCallback callback,
    void* userData) {
    if (!callback || sphere.w < 0.0f) return false; // Check for valid radius
    return IntersectSphereInternal<uint16_t>(sphere, polygonSoup16.header, callback, userData);
}

namespace { // Anonymous namespace for helpers

// Project polygon (defined by vertices) onto axis
void ProjectPolygon(const GtMath::Vector3* vertices, int numVertices, const GtMath::Vector3& axis, float& min, float& max) {
    if (numVertices == 0) {
        min = 0.f;
        max = 0.f;
        return;
    }
    min = GtMath::dot_product(vertices[0], axis);
    max = min;
    for (int i = 1; i < numVertices; ++i) {
        float projection = GtMath::dot_product(vertices[i], axis);
        if (projection < min) min = projection;
        if (projection > max) max = projection;
    }
}

// Helper to check if a box is outside a single plane.
// Returns true if the box is entirely outside (on the positive side of) the plane.
bool IsBoxOutsidePlane(const GtMath::Vector3* boxCorners, const GtMath::Plane& plane) {
    GtMath::Vector3 planeNormal = {plane.normal_x, plane.normal_y, plane.normal_z};
    for (int i = 0; i < 8; ++i) {
        // If any point is NOT outside (i.e., it's on or behind the plane),
        // then the box is not entirely outside this plane.
        if (GtMath::dot_product(boxCorners[i], planeNormal) - plane.d <= 1e-5f) { // Add epsilon
            return false;
        }
    }
    // All points are on the positive (outside) side of the plane.
    return true;
}

} // anonymous namespace

bool GtIntersection::IntersectFrustumSimpleOrientedBox(
    const GtFrustum& frustum,
    const GtSimpleOrientedBox& box) {

    // Simplified SAT:
    // 1. Test frustum planes: Check if the box is entirely outside any one of the frustum planes.
    for (int i = 0; i < 6; ++i) {
        if (IsBoxOutsidePlane(box.corners, frustum.planes[i])) {
            return false; // Box is outside this frustum plane, no intersection.
        }
    }

    // 2. Test box planes: Check if the frustum is entirely outside any one of the box planes.
    // This requires deriving box face normals and then projecting frustum vertices (or using frustum AABB projection).
    // Deriving box face normals from 8 corners:
    // Assuming a consistent corner ordering for GtSimpleOrientedBox, e.g.:
    //   3----2
    //  /|   /|
    // 7----6 |    (far face: 0,1,2,3; near face: 4,5,6,7 - example)
    // | 0--|-1    Y | /Z
    // |/   |/     |/--X
    // 4----5
    // This part is complex without a guaranteed corner order or more direct OBB representation (center, axes, extents).
    // For a true OBB defined by center, axes, extents, the 3 face normals are simply the axes.
    // Since GtSimpleOrientedBox only gives 8 corners, we'd have to derive face normals.
    // Example face normals (assuming specific corner indexing for box.corners):
    // Normal 1: from corners[0], corners[1], corners[2] (e.g. cross(c1-c0, c2-c0))
    // Normal 2: from corners[0], corners[3], corners[4] (e.g. cross(c3-c0, c4-c0))
    // Normal 3: from corners[0], corners[1], corners[4] (e.g. cross(c1-c0, c4-c0))
    // This sub-part (projecting frustum onto box normals) is deferred due to complexity of deriving frustum vertices
    // or robustly projecting frustum onto arbitrary axes.

    // 3. Cross product axes: Not implemented in this simplified version.

    // If no separating axis is found by the first test (box vs frustum planes),
    // this simplified implementation assumes an intersection.
    // This is an oversimplification and may lead to false positives.
    return true;
}

bool GtIntersection::IntersectFrustumOrthogonalBox(
    const GtFrustum& frustum,
    const GtOrthogonalBox& box) {

    GtSimpleOrientedBox obb; // To store the 8 corners
    GtMath::Vector3 xAxis = box.basisAxisX;
    GtMath::Vector3 yAxis = box.basisAxisY;
    // Ensure Z-axis is correctly calculated and normalized if not already.
    // Assuming basisAxisX and basisAxisY are orthonormal.
    GtMath::Vector3 zAxis = GtMath::normalize_safe(GtMath::cross_product(xAxis, yAxis));

    GtMath::Vector3 termX = GtMath::multiply_scalar(xAxis, box.halfExtents.x);
    GtMath::Vector3 termY = GtMath::multiply_scalar(yAxis, box.halfExtents.y);
    GtMath::Vector3 termZ = GtMath::multiply_scalar(zAxis, box.halfExtents.z);

    // Combinations of +/- termX, +/- termY, +/- termZ added to center
    obb.corners[0] = GtMath::add(GtMath::add(GtMath::add(box.center, GtMath::multiply_scalar(termX, -1.0f)), GtMath::multiply_scalar(termY, -1.0f)), GtMath::multiply_scalar(termZ, -1.0f));
    obb.corners[1] = GtMath::add(GtMath::add(GtMath::add(box.center, GtMath::multiply_scalar(termX,  1.0f)), GtMath::multiply_scalar(termY, -1.0f)), GtMath::multiply_scalar(termZ, -1.0f));
    obb.corners[2] = GtMath::add(GtMath::add(GtMath::add(box.center, GtMath::multiply_scalar(termX,  1.0f)), GtMath::multiply_scalar(termY,  1.0f)), GtMath::multiply_scalar(termZ, -1.0f));
    obb.corners[3] = GtMath::add(GtMath::add(GtMath::add(box.center, GtMath::multiply_scalar(termX, -1.0f)), GtMath::multiply_scalar(termY,  1.0f)), GtMath::multiply_scalar(termZ, -1.0f));
    obb.corners[4] = GtMath::add(GtMath::add(GtMath::add(box.center, GtMath::multiply_scalar(termX, -1.0f)), GtMath::multiply_scalar(termY, -1.0f)), GtMath::multiply_scalar(termZ,  1.0f));
    obb.corners[5] = GtMath::add(GtMath::add(GtMath::add(box.center, GtMath::multiply_scalar(termX,  1.0f)), GtMath::multiply_scalar(termY, -1.0f)), GtMath::multiply_scalar(termZ,  1.0f));
    obb.corners[6] = GtMath::add(GtMath::add(GtMath::add(box.center, GtMath::multiply_scalar(termX,  1.0f)), GtMath::multiply_scalar(termY,  1.0f)), GtMath::multiply_scalar(termZ,  1.0f));
    obb.corners[7] = GtMath::add(GtMath::add(GtMath::add(box.center, GtMath::multiply_scalar(termX, -1.0f)), GtMath::multiply_scalar(termY,  1.0f)), GtMath::multiply_scalar(termZ,  1.0f));

    return IntersectFrustumSimpleOrientedBox(frustum, obb);
}

bool GtIntersection::IntersectFrustumExtrudedBox(
    const GtFrustum& frustum,
    const GtExtrudedBox& extrudedBox) { // GtExtrudedBox is typedef'd or structured as GtSimpleOrientedBox

    // Assuming GtExtrudedBox provides its 8 corners directly,
    // identical to GtSimpleOrientedBox for the purpose of this function.
    // If GtExtrudedBox had a different structure (e.g., base + extrusion vector),
    // its 8 vertices would need to be computed here first.
    return IntersectFrustumSimpleOrientedBox(frustum, static_cast<const GtSimpleOrientedBox&>(extrudedBox));
}

int GtIntersection::ClipPolyWithConvexHull(
    const GtMath::Vector3* inputPolygonVertices,
    int numInputVertices,
    const GtConvexHull& convexHull,
    GtMath::Vector3* outputPolygonVerticesBuffer,
    int maxOutputVertices,
    GtMath::Vector3* outOptionalLastPlaneNormal) {

    if (!inputPolygonVertices || numInputVertices < 3 ||
        !convexHull.planes || convexHull.numPlanes == 0 ||
        !outputPolygonVerticesBuffer || maxOutputVertices < 3) {

        if (outOptionalLastPlaneNormal) {
            *outOptionalLastPlaneNormal = GtMath::Vector3(0.f, 0.f, 0.f, 0.f);
        }
        return 0;
    }

    // Initialize outOptionalLastPlaneNormal to zero. It will be updated if a clip occurs.
    if (outOptionalLastPlaneNormal) {
        *outOptionalLastPlaneNormal = GtMath::Vector3(0.f, 0.f, 0.f, 0.f);
    }
    bool anEffectiveClipOccurred = false; // Tracks if any plane actually modified the polygon

    // Use std::vector for dynamic resizing of vertex lists during clipping.
    // currentVertices holds the polygon vertices to be clipped by the current plane.
    // nextVertices holds the vertices resulting from clipping against the current plane.
    std::vector<GtMath::Vector3> currentVerticesVec;
    currentVerticesVec.assign(inputPolygonVertices, inputPolygonVertices + numInputVertices);

    std::vector<GtMath::Vector3> nextVerticesVec;
    // Reserve space: Max possible vertices after clipping a convex polygon with a plane is N+1.
    // Max output vertices is a hard cap.
    nextVerticesVec.reserve(std::max(static_cast<size_t>(numInputVertices + 1), static_cast<size_t>(maxOutputVertices)));


    for (int i = 0; i < convexHull.numPlanes; ++i) {
        if (currentVerticesVec.size() < 3) break; // Polygon degenerated

        const GtMath::Plane& clippingPlane = convexHull.planes[i];
        GtMath::Vector3 planeNormal = {clippingPlane.normal_x, clippingPlane.normal_y, clippingPlane.normal_z};
        float planeDist = clippingPlane.d;

        nextVerticesVec.clear();

        GtMath::Vector3 S = currentVerticesVec.back(); // Start with the last vertex

        for (size_t j = 0; j < currentVerticesVec.size(); ++j) {
            GtMath::Vector3 P = currentVerticesVec[j];

            // dist = dot(point, normal) - plane_d. Positive if outside, negative if inside.
            float distS = GtMath::dot_product(S, planeNormal) - planeDist;
            float distP = GtMath::dot_product(P, planeNormal) - planeDist;

            bool s_inside = distS <= 1e-5f; // Epsilon for robustness
            bool p_inside = distP <= 1e-5f;

            if (s_inside && p_inside) { // Case 1: Both S and P are inside. Add P.
                if (nextVerticesVec.size() < static_cast<size_t>(maxOutputVertices)) {
                    nextVerticesVec.push_back(P);
                }
            } else if (s_inside && !p_inside) { // Case 2: S is inside, P is outside. Add intersection.
                // Intersection I = S + t * (P - S)
                // t = distS / (distS - distP) (distS is effectively distance to plane, scaled by normal length)
                float t = 0.0f;
                if (std::abs(distS - distP) > 1e-6f) { // Avoid division by zero
                    t = distS / (distS - distP);
                } else { // Points likely very close or on the plane, or line is parallel
                    t = (distS <= 1e-5f) ? 0.0f : 1.0f; // Heuristic: if S is inside, use S; else use P
                }

                // Clamp t to [0,1] to be safe, though it should be if logic is correct
                t = std::max(0.0f, std::min(1.0f, t));
                GtMath::Vector3 intersectionPoint = GtMath::add(S, GtMath::multiply_scalar(GtMath::subtract(P, S), t));

                if (nextVerticesVec.size() < static_cast<size_t>(maxOutputVertices)) {
                    nextVerticesVec.push_back(intersectionPoint);
                }
                if (outOptionalLastPlaneNormal) *outOptionalLastPlaneNormal = planeNormal;
                anEffectiveClipOccurred = true;

            } else if (!s_inside && p_inside) { // Case 3: S is outside, P is inside. Add intersection, then P.
                float t = 0.0f;
                 if (std::abs(distS - distP) > 1e-6f) {
                    t = distS / (distS - distP);
                } else {
                    t = (distS <= 1e-5f) ? 0.0f : 1.0f;
                }
                t = std::max(0.0f, std::min(1.0f, t));
                GtMath::Vector3 intersectionPoint = GtMath::add(S, GtMath::multiply_scalar(GtMath::subtract(P, S), t));

                if (nextVerticesVec.size() < static_cast<size_t>(maxOutputVertices)) {
                    nextVerticesVec.push_back(intersectionPoint);
                }
                if (nextVerticesVec.size() < static_cast<size_t>(maxOutputVertices)) {
                    nextVerticesVec.push_back(P);
                }
                if (outOptionalLastPlaneNormal) *outOptionalLastPlaneNormal = planeNormal;
                anEffectiveClipOccurred = true;
            }
            // Case 4: Both S and P are outside. No points added.
            S = P;
        }
        currentVerticesVec.assign(nextVerticesVec.begin(), nextVerticesVec.end());

        // If polygon is fully clipped by this plane and no effective clip had been recorded yet
        // (e.g. first plane clips everything), this plane is significant.
        if (currentVerticesVec.empty() && outOptionalLastPlaneNormal && !anEffectiveClipOccurred) {
             *outOptionalLastPlaneNormal = planeNormal;
             anEffectiveClipOccurred = true; // Mark that this plane caused the full clip
        }
    }

    // If no effective clip occurred (polygon was entirely inside or input was invalid and handled earlier)
    // and a normal was requested, ensure it's zeroed.
    if (outOptionalLastPlaneNormal && !anEffectiveClipOccurred) {
        *outOptionalLastPlaneNormal = GtMath::Vector3(0.f, 0.f, 0.f, 0.f);
    }

    int numResultVertices = 0;
    if (currentVerticesVec.size() >= 3) {
        numResultVertices = std::min(static_cast<int>(currentVerticesVec.size()), maxOutputVertices);
        for (int k = 0; k < numResultVertices; ++k) {
            outputPolygonVerticesBuffer[k] = currentVerticesVec[k];
        }
    }

    return numResultVertices;
}

} // namespace Gt
