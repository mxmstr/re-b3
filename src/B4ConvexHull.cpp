#include "B4ConvexHull.h"
#include <cmath>
#include <vector> // Keep for local std::vector like worldSpaceVertices
#include <cstdint>
#include <cstring> // For std::memset, std::memcpy
#include <algorithm> // For std::min and std::max
#include <cstdio>    // For snprintf

// Placeholder/external dependencies - keep as is (likely commented out in original)
// class CB4DebugManager {
// public:
//    void DrawLine(const GtMath::Vector3& from, const GtMath::Vector3& to, const GtMath::Vector4& color) { (void)from; (void)to; (void)color; }
//    void DrawVectorText(const char* text, const GtMath::Vector3& pos, const GtMath::Matrix3x4& o, float s, const GtMath::Vector4& c) { (void)text;(void)pos;(void)o;(void)s;(void)c;}
// };
// CB4DebugManager gDebugManager; // Placeholder
// namespace SomeGraphicsNamespace { struct GraphicsManagerData {}; GraphicsManagerData gGraphicsManager; } // Placeholder


// B4ConvexHull::FixUp() is now defined in B4ConvexHull.h, so no definition here.

int64_t B4ConvexHull::CalculatePlaneData(int planeIndex) {
    if (!pFaces || !pVertices || !pPlanes || planeIndex < 0 || static_cast<uint8_t>(planeIndex) >= m_numPlanes) {
        return 0;
    }

    uint8_t* current_face_ptr = pFaces + planeIndex * 4;

    uint8_t v_idx0 = current_face_ptr[0];
    uint8_t v_idx1 = current_face_ptr[1];
    uint8_t v_idx2 = current_face_ptr[2];

    if (v_idx0 >= m_numVertices || v_idx1 >= m_numVertices || v_idx2 >= m_numVertices) {
        return reinterpret_cast<int64_t>(current_face_ptr);
    }

    GtMath::Vector4 v0_4d = GtMath::load_vec4(pVertices + v_idx0 * 16); GtMath::Vector3 p0 = {v0_4d.x, v0_4d.y, v0_4d.z};
    GtMath::Vector4 v1_4d = GtMath::load_vec4(pVertices + v_idx1 * 16); GtMath::Vector3 p1 = {v1_4d.x, v1_4d.y, v1_4d.z};
    GtMath::Vector4 v2_4d = GtMath::load_vec4(pVertices + v_idx2 * 16); GtMath::Vector3 p2 = {v2_4d.x, v2_4d.y, v2_4d.z};

    GtMath::Vector3 edge10 = GtMath::subtract(p1, p0);
    GtMath::Vector3 edge20 = GtMath::subtract(p2, p0);
    GtMath::Vector3 normal = GtMath::cross_product(edge10, edge20);
    float length_sq = GtMath::length_squared(normal);

    if (length_sq < 2.3283064e-10f) {
        return reinterpret_cast<int64_t>(current_face_ptr);
    } else {
        normal = GtMath::normalize(normal);
        float d_val = GtMath::dot_product(normal, p0);
        GtMath::store_plane(pPlanes + planeIndex * 16, normal, d_val);
        return reinterpret_cast<int64_t>(current_face_ptr);
    }
}

void B4ConvexHull::MakeBoxFromBoundingBox(const GtMath::Vector3& minB, const GtMath::Vector3& maxB) {
    // This function populates the embedded data arrays.
    // It assumes that this B4ConvexHull instance's embedded arrays will be used.
    // Call FixUp first to ensure pFaces, pVertices etc. point to the embedded arrays.
    InitialiseVehicleHull(); // This calls FixUp which sets p* to m_*_embed.data() using _raw offsets.

    if (!pVertices || !pPlanes || !pFaces || !pEdges) return; // Check if FixUp failed or pointers are null

    GtMath::Vector4 v[8];
    v[0] = {minB.x, minB.y, minB.z, 1.0f}; v[1] = {maxB.x, minB.y, minB.z, 1.0f};
    v[2] = {minB.x, maxB.y, minB.z, 1.0f}; v[3] = {maxB.x, maxB.y, minB.z, 1.0f};
    v[4] = {minB.x, minB.y, maxB.z, 1.0f}; v[5] = {maxB.x, minB.y, maxB.z, 1.0f};
    v[6] = {minB.x, maxB.y, maxB.z, 1.0f}; v[7] = {maxB.x, maxB.y, maxB.z, 1.0f};
    for (int i = 0; i < 8; ++i) GtMath::store_vec4(pVertices + i * 16, v[i]);
    m_numVertices = 8;

    GtMath::store_plane(pPlanes + 0 * 16, {0.0f, 0.0f, 1.0f}, maxB.z);
    GtMath::store_plane(pPlanes + 1 * 16, {0.0f, 0.0f, -1.0f}, -minB.z);
    GtMath::store_plane(pPlanes + 2 * 16, {0.0f, 1.0f, 0.0f}, maxB.y);
    GtMath::store_plane(pPlanes + 3 * 16, {0.0f, -1.0f, 0.0f}, -minB.y);
    GtMath::store_plane(pPlanes + 4 * 16, {1.0f, 0.0f, 0.0f}, maxB.x);
    GtMath::store_plane(pPlanes + 5 * 16, {-1.0f, 0.0f, 0.0f}, -minB.x);
    m_numPlanes = 6;

    uint8_t faces_init[] = {
        4,5,7,6,  // Front (+Z)
        0,2,3,1,  // Back (-Z)
        2,6,7,3,  // Top (+Y)
        0,1,5,4,  // Bottom (-Y)
        1,3,7,5,  // Right (+X)
        0,4,6,2   // Left (-X)
    };
    // Ensure pFaces points to m_faceData_embed and is large enough (68 bytes)
    if (sizeof(faces_init) <= m_faceData_embed.size()) {
       std::memcpy(pFaces, faces_init, sizeof(faces_init));
    }


    uint8_t edges_init[] = {
        0,1, 1,3, 3,2, 2,0,
        4,5, 5,7, 7,6, 6,4,
        0,4, 1,5, 2,6, 3,7
    };
    // Ensure pEdges points to m_edgeData_embed and is large enough (56 bytes)
    if (sizeof(edges_init) <= m_edgeData_embed.size()) {
       std::memcpy(pEdges, edges_init, sizeof(edges_init));
    }
    m_numEdges = 12;
    m_flags = 0;
}

void B4ConvexHull::MakeFromBoundingBox(const GtMath::Vector3& minB, const GtMath::Vector3& maxB, EB4HullShape shape) {
    if (shape == EB4HullShape::Cone) MakeConeFromBoundingBox(minB, maxB);
    else if (shape == EB4HullShape::Boat) MakeBoatFromBoundingBox(minB, maxB);
    else MakeBoxFromBoundingBox(minB, maxB);
}

void B4ConvexHull::MakeConeFromBoundingBox(const GtMath::Vector3& minB, const GtMath::Vector3& maxB) { (void)minB; (void)maxB; /*TODO*/ }
void B4ConvexHull::MakeBoatFromBoundingBox(const GtMath::Vector3& minB, const GtMath::Vector3& maxB) { (void)minB; (void)maxB; /*TODO*/ }

bool B4ConvexHull::DeformHullVerts(GtMath::Vector3* pAvgPos, const GtMath::Vector3& refPos, const GtMath::Matrix3x4& defM, const GtMath::Matrix3x4* boneMs, const B4ConvexHull& origHull) {
    if (!pVertices || !pDeformData || !origHull.pVertices || !boneMs) { // Added null check for boneMs
        return false;
    }
    if (!(m_flags & 2)) return false;

    m_numVertices = origHull.m_numVertices;
    m_numPlanes = origHull.m_numPlanes;
    m_numEdges = origHull.m_numEdges;

    for (uint8_t i = 0; i < m_numVertices; ++i) {
        GtMath::Matrix3x4 accumBoneM = {};
        float totalW = 0.0f;

        const uint8_t* curDeformEntry = pDeformData + i * 12;
        const float* Ws = reinterpret_cast<const float*>(curDeformEntry);
        const uint8_t* boneIs = curDeformEntry + 8;

        for (int j = 0; j < 2; ++j) {
            float w = Ws[j];
            if (w == 0.0f) continue;
            totalW += w;
            uint8_t bIdx = boneIs[j];
            // TODO: Add check for bIdx against number of available boneMs if that count is known
            const GtMath::Matrix3x4& bMRef = boneMs[bIdx];
            GtMath::Matrix3x4 weightedBM = GtMath::matrix_multiply_scalar(bMRef, w);
            accumBoneM = GtMath::matrix_add(accumBoneM, weightedBM);
        }

        float defMW = 1.0f - totalW;
        GtMath::Matrix3x4 finalM = accumBoneM; // Use default constructor for GtMatrix3x4 if it initializes to zero
        if (std::abs(defMW) > 1e-6f) { // Check if defMW is significantly non-zero
            GtMath::Matrix3x4 weightedDefM = GtMath::matrix_multiply_scalar(defM, defMW);
            if (totalW == 0.0f) { // If no bone weights, finalM is just weightedDefM
                finalM = weightedDefM;
            } else { // Else add to existing bone influences
                finalM = GtMath::matrix_add(finalM, weightedDefM);
            }
        } else if (totalW == 0.0f) { // No bone weights and no default matrix weight
             // finalM remains zero or identity depending on GtMatrix3x4 constructor.
             // If it should be identity for passthrough:
             // finalM = GtMath::Matrix3x4(true); // Assuming constructor for identity
        }


        GtMath::Vector4 oV4 = GtMath::load_vec4(origHull.pVertices + i * 16);
        GtMath::Vector3 oPos = {oV4.x, oV4.y, oV4.z};
        GtMath::Vector3 defPos = GtMath::transform_point(finalM, oPos);
        GtMath::Vector4 defV4 = {defPos.x, defPos.y, defPos.z, oV4.w};
        GtMath::store_vec4(pVertices + i * 16, defV4);
    }

    MakePlanar();

    if (pAvgPos) {
        pAvgPos->x = 0; pAvgPos->y = 0; pAvgPos->z = 0;
        if (m_numVertices > 0) {
            for (uint8_t i = 0; i < m_numVertices; ++i) {
                GtMath::Vector4 v4 = GtMath::load_vec4(pVertices + i * 16);
                pAvgPos->x += v4.x; pAvgPos->y += v4.y; pAvgPos->z += v4.z;
            }
            float invNumVerts = 1.0f / m_numVertices;
            pAvgPos->x *= invNumVerts; pAvgPos->y *= invNumVerts; pAvgPos->z *= invNumVerts;
        }
        (void)refPos;
    }
    return true;
}

void B4ConvexHull::MakePlanar() {
    if (!pVertices || !pPlanes) return;
    if (m_numVertices < 16) return;

    auto op = [&](int vA_idx, int vB_idx, int component_idx, bool use_min_op) {
        GtMath::Vector4 vA = GtMath::load_vec4(pVertices + vA_idx * 16);
        GtMath::Vector4 vB = GtMath::load_vec4(pVertices + vB_idx * 16);
        float* pValA = (component_idx == 0) ? &vA.x : (component_idx == 1) ? &vA.y : &vA.z;
        float* pValB = (component_idx == 0) ? &vB.x : (component_idx == 1) ? &vB.y : &vB.z;
        float result_val = use_min_op ? std::min(*pValA, *pValB) : std::max(*pValA, *pValB);
        *pValA = result_val; *pValB = result_val;
        GtMath::store_vec4(pVertices + vA_idx * 16, vA);
        GtMath::store_vec4(pVertices + vB_idx * 16, vB);
    };

    op(0,2,0,true); op(0,2,2,true); op(4,6,0,true); op(4,6,2,true);
    op(8,10,0,true); op(8,10,2,true); op(12,14,0,true); op(12,14,2,true);
    op(1,3,0,false); op(1,3,2,false); op(5,7,0,false); op(5,7,2,false);
    // Original C++ had op(9,11,2,true) and op(13,15,2,true); keeping 'true' for Z component
    op(9,11,0,false); op(9,11,2,true); op(13,15,0,false); op(13,15,2,true);
    op(0,1,1,false); op(4,5,1,false); op(8,9,1,false); op(12,13,1,false);
    op(2,3,1,true); op(6,7,1,true); op(10,11,1,true); op(14,15,1,true);

    if (m_numPlanes > 0) {
        for (uint8_t i = 0; i < m_numPlanes; ++i) {
            CalculatePlaneData(i);
        }
    }
}

void B4ConvexHull::DebugRenderEdges(const GtMath::Matrix3x4& worldTF, bool drawTxt) const {
    if (!pVertices || !pEdges || m_numVertices == 0 || m_numEdges == 0) return;

    std::vector<GtMath::Vector3> worldSpaceVertices(m_numVertices);
    for (uint8_t i = 0; i < m_numVertices; ++i) {
        GtMath::Vector4 localVert4 = GtMath::load_vec4(pVertices + i * 16);
        GtMath::Vector3 localPos = {localVert4.x, localVert4.y, localVert4.z};
        worldSpaceVertices[i] = GtMath::transform_point(worldTF, localPos);
    }

    /* // Debug rendering code using gDebugManager - keep commented if gDebugManager is not available
    for (uint8_t edgeIdx = 0; edgeIdx < m_numEdges; ++edgeIdx) {
        // Assuming pEdges stores pairs of uint8_t vertex indices
        uint8_t vIdx0 = pEdges[edgeIdx * 2 + 0];
        uint8_t vIdx1 = pEdges[edgeIdx * 2 + 1];

        if (vIdx0 >= m_numVertices || vIdx1 >= m_numVertices) continue;

        const auto& p1 = worldSpaceVertices[vIdx0];
        const auto& p2 = worldSpaceVertices[vIdx1];
        // gDebugManager.DrawLine(p1, p2, {1.0f, 1.0f, 0.0f, 1.0f});

        if (drawTxt) {
            char buf[64];
            std::snprintf(buf, sizeof(buf), "E%d V%d-V%d", edgeIdx, vIdx0, vIdx1);
            GtMath::Matrix3x4 dummyOrient(true);
            GtMath::Vector3 midPoint = GtMath::multiply_scalar(GtMath::add(p1, p2), 0.5f);
            // gDebugManager.DrawVectorText(buf, midPoint, dummyOrient, 0.1f, {1.0f, 1.0f, 1.0f, 1.0f});
        }
    }
    */
    (void)worldTF; (void)drawTxt;
}

void B4ConvexHull::DebugRenderPlanes(const GtMath::Matrix3x4& worldTF, bool drawTxt) const {
    if (!pVertices || !pPlanes || !pFaces || m_numVertices == 0 || m_numPlanes == 0) return;

    std::vector<GtMath::Vector3> worldSpaceVertices(m_numVertices);
    for (uint8_t i = 0; i < m_numVertices; ++i) {
        GtMath::Vector4 localVert4 = GtMath::load_vec4(pVertices + i * 16);
        GtMath::Vector3 localPos = {localVert4.x, localVert4.y, localVert4.z};
        worldSpaceVertices[i] = GtMath::transform_point(worldTF, localPos);
    }

    /* // Debug rendering code using gDebugManager
    for (uint8_t planeIdx = 0; planeIdx < m_numPlanes; ++planeIdx) {
        GtMath::Plane localPlane = GtMath::load_plane(pPlanes + planeIdx * 16);
        GtMath::Vector3 localNormal = {localPlane.normal_x, localPlane.normal_y, localPlane.normal_z};

        GtMath::Vector3 worldNormalUnnormalized = GtMath::transform_normal(localNormal, worldTF);
        GtMath::Vector3 worldNormal = GtMath::normalize(worldNormalUnnormalized);

        GtMath::Vector3 pointOnLocalPlane = GtMath::multiply_scalar(localNormal, localPlane.d);
        GtMath::Vector3 pointOnWorldPlane = GtMath::transform_point(worldTF, pointOnLocalPlane);
        float world_d = GtMath::dot_product(worldNormal, pointOnWorldPlane);

        GtMath::Vector3 faceCenterWorld = pointOnWorldPlane;
        uint8_t numFaceVerts = 0;
        const uint8_t* faceVertexIndices = pFaces + planeIdx * 4;
        GtMath::Vector3 tempFaceCenter = {0,0,0};
        for (int k = 0; k < 4; ++k) { // Assuming 4 vertices per face from pFaces
            if (faceVertexIndices[k] < m_numVertices) {
                tempFaceCenter = GtMath::add(tempFaceCenter, worldSpaceVertices[faceVertexIndices[k]]);
                numFaceVerts++;
            }
        }
        if (numFaceVerts > 0) {
            faceCenterWorld = GtMath::multiply_scalar(tempFaceCenter, 1.0f / numFaceVerts);
        }

        // gDebugManager.DrawLine(faceCenterWorld, GtMath::add(faceCenterWorld, GtMath::multiply_scalar(worldNormal, 0.5f)), {0.0f, 1.0f, 1.0f, 1.0f});

        if (drawTxt) {
            char buf[128];
            std::snprintf(buf, sizeof(buf), "P%d N(%.1f,%.1f,%.1f) D(%.1f)", planeIdx, worldNormal.x, worldNormal.y, worldNormal.z, world_d);
            GtMath::Matrix3x4 dummyOrient(true);
            // gDebugManager.DrawVectorText(buf, faceCenterWorld, dummyOrient, 0.1f, {1.0f, 1.0f, 1.0f, 1.0f});
        }
    }
    */
    (void)worldTF; (void)drawTxt;
}

void B4ConvexHull::InitialiseVehicleHull() {
    FixUp(reinterpret_cast<char*>(this));
}
