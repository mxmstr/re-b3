#include "B4ConvexHull.h"
#include <cmath>
#include <vector>
#include <cstdint>
#include <cstring> // For std::memset
#include <algorithm> // For std::min and std::max
#include <cstdio>    // For snprintf
// #include <iostream> // For debug std::cout, commented out for submission

// Placeholder for actual alignment macro
#ifndef ALIGNED_DECL
#define ALIGNED_DECL(N) alignas(N)
#endif

// GtMathPs2 placeholder namespace and types
namespace GtMathPs2 {
    struct ALIGNED_DECL(16) Vector3 {
        float x, y, z, w_pad;
        Vector3(float _x = 0.f, float _y = 0.f, float _z = 0.f, float _w = 0.f) : x(_x), y(_y), z(_z), w_pad(_w) {}
    };

    struct ALIGNED_DECL(16) Vector4 {
        float x, y, z, w;
        Vector4(float _x = 0.f, float _y = 0.f, float _z = 0.f, float _w = 0.f) : x(_x), y(_y), z(_z), w(_w) {}
    };

    struct ALIGNED_DECL(16) Plane {
        float normal_x, normal_y, normal_z, d;
        Plane(float nx=0.f, float ny=0.f, float nz=0.f, float _d=0.f) : normal_x(nx), normal_y(ny), normal_z(nz), d(_d) {}
    };

    struct ALIGNED_DECL(16) Matrix3x4 {
        float mat[3][4];
        Matrix3x4() { std::memset(mat, 0, sizeof(mat)); }
        Matrix3x4(bool identity) {
            std::memset(mat, 0, sizeof(mat));
            if (identity) {
                mat[0][0] = 1.0f; mat[1][1] = 1.0f; mat[2][2] = 1.0f;
            }
        }
        Vector3 get_col(int c) const { return {mat[0][c], mat[1][c], mat[2][c]}; }
        void set_col(int c, const Vector3& v) { mat[0][c]=v.x; mat[1][c]=v.y; mat[2][c]=v.z; }
        Vector3 get_translation() const { return {mat[0][3], mat[1][3], mat[2][3]}; }
        void set_translation(const Vector3& t) { mat[0][3]=t.x; mat[1][3]=t.y; mat[2][3]=t.z; }
    };

    struct CGtLine { int type_placeholder; };
    using CGtV4d = Vector4;

    Vector3 add(const Vector3& a, const Vector3& b) { return Vector3(a.x + b.x, a.y + b.y, a.z + b.z); }
    Vector3 multiply_scalar(const Vector3& v, float s) { return Vector3(v.x * s, v.y * s, v.z * s); }
    Matrix3x4 matrix_multiply_scalar(const Matrix3x4& M, float s) { Matrix3x4 r; for (int i=0;i<3;++i) for (int j=0;j<4;++j) r.mat[i][j]=M.mat[i][j]*s; return r; }
    Matrix3x4 matrix_add(const Matrix3x4& A, const Matrix3x4& B) { Matrix3x4 r; for (int i=0;i<3;++i) for (int j=0;j<4;++j) r.mat[i][j]=A.mat[i][j]+B.mat[i][j]; return r; }
    Vector3 transform_point(const Matrix3x4& M, const Vector3& p) { return Vector3( M.mat[0][0]*p.x + M.mat[0][1]*p.y + M.mat[0][2]*p.z + M.mat[0][3], M.mat[1][0]*p.x + M.mat[1][1]*p.y + M.mat[1][2]*p.z + M.mat[1][3], M.mat[2][0]*p.x + M.mat[2][1]*p.y + M.mat[2][2]*p.z + M.mat[2][3] ); }
    Vector3 transform_normal(const Vector3& n, const Matrix3x4& M) { return Vector3( M.mat[0][0]*n.x + M.mat[0][1]*n.y + M.mat[0][2]*n.z, M.mat[1][0]*n.x + M.mat[1][1]*n.y + M.mat[1][2]*n.z, M.mat[2][0]*n.x + M.mat[2][1]*n.y + M.mat[2][2]*n.z ); }
    const Vector3 kBodyFront = {0.0f, 0.0f, 1.0f};
    const Vector3 kBodyBack = {0.0f, 0.0f, -1.0f};
    const Vector3 kBodyTop = {0.0f, 1.0f, 0.0f};
    const Vector3 kBodyBottom = {0.0f, -1.0f, 0.0f};
    const Vector3 kBodyRight = {1.0f, 0.0f, 0.0f};
    const Vector3 kBodyLeft = {-1.0f, 0.0f, 0.0f};
    Vector3 subtract(const Vector3& a, const Vector3& b) { return Vector3(a.x - b.x, a.y - b.y, a.z - b.z); }
    Vector3 cross_product(const Vector3& a, const Vector3& b) { return Vector3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x); }
    float dot_product(const Vector3& a, const Vector3& b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
    float length_squared(const Vector3& v) { return v.x * v.x + v.y * v.y + v.z * v.z; }
    Vector3 normalize(const Vector3& v) { float l = length_squared(v); if (l > 1e-6f) { float inv_l = 1.0f / sqrtf(l); return Vector3(v.x * inv_l, v.y * inv_l, v.z * inv_l); } return Vector3(0,0,0); }
    Vector4 load_vec4(const uint8_t* p) { const float* fp = reinterpret_cast<const float*>(p); return Vector4(fp[0], fp[1], fp[2], fp[3]); }
    void store_vec4(uint8_t* dest, const Vector4& vec) { float* fp = reinterpret_cast<float*>(dest); fp[0]=vec.x; fp[1]=vec.y; fp[2]=vec.z; fp[3]=vec.w; }
    void store_plane(uint8_t* p, const Vector3& normal, float d_val) { float* fp = reinterpret_cast<float*>(p); fp[0]=normal.x; fp[1]=normal.y; fp[2]=normal.z; fp[3]=d_val; }
    Plane load_plane(const uint8_t* p) { const float* fp = reinterpret_cast<const float*>(p); return Plane(fp[0], fp[1], fp[2], fp[3]); }
}

class CB4DebugManager {
public:
    void DrawLine(const GtMathPs2::Vector3& from, const GtMathPs2::Vector3& to, const GtMathPs2::Vector4& color) { (void)from; (void)to; (void)color; }
    void DrawVectorText(const char* text, const GtMathPs2::Vector3& pos, const GtMathPs2::Matrix3x4& o, float s, const GtMathPs2::Vector4& c) { (void)text;(void)pos;(void)o;(void)s;(void)c;}
};
CB4DebugManager gDebugManager;
namespace SomeGraphicsNamespace { GraphicsManagerData gGraphicsManager; }

B4ConvexHull::B4ConvexHull() {
    // Constructor in .h initializes vectors and basic members
}

void B4ConvexHull::Fixup() {
    if (!m_faceData.empty()) m_offsetFaces = reinterpret_cast<uintptr_t>(m_faceData.data()); else m_offsetFaces = 0;
    if (!m_planeData.empty()) m_offsetPlanes = reinterpret_cast<uintptr_t>(m_planeData.data()); else m_offsetPlanes = 0;
    if (!m_vertexData.empty()) m_offsetVertices = reinterpret_cast<uintptr_t>(m_vertexData.data()); else m_offsetVertices = 0;
    if (!m_edgeData.empty()) m_offsetEdges = reinterpret_cast<uintptr_t>(m_edgeData.data()); else m_offsetEdges = 0;
    if (!m_deformData.empty()) m_offsetDeformData = reinterpret_cast<uintptr_t>(m_deformData.data()); else m_offsetDeformData = 0;
}

int64_t B4ConvexHull::CalculatePlaneData(int planeIndex) {
    if (m_planeData.size() < static_cast<size_t>((planeIndex + 1) * 16)) { return reinterpret_cast<int64_t>(m_faceData.data() + planeIndex * 4); }
    if (m_faceData.size() < static_cast<size_t>((planeIndex + 1) * 4)) { return reinterpret_cast<int64_t>(m_faceData.data() + planeIndex * 4); }

    uint8_t* raw_faces_base = m_faceData.data();
    uint8_t* raw_vertices_base = m_vertexData.data();
    uint8_t* raw_planes_base = m_planeData.data();
    uint8_t* current_face_ptr = raw_faces_base + planeIndex * 4;

    uint8_t v_idx0 = current_face_ptr[0]; uint8_t v_idx1 = current_face_ptr[1];
    uint8_t v_idx2 = current_face_ptr[2]; uint8_t v_idx3 = current_face_ptr[3];

    if (v_idx0 >= m_numVertices || v_idx1 >= m_numVertices || v_idx2 >= m_numVertices || v_idx3 >= m_numVertices) { return reinterpret_cast<int64_t>(current_face_ptr); }
    if (m_vertexData.size() < (std::max({v_idx0, v_idx1, v_idx2, v_idx3}) + 1) * 16) { return reinterpret_cast<int64_t>(current_face_ptr); }

    GtMathPs2::Vector4 v0_4d=GtMathPs2::load_vec4(raw_vertices_base+v_idx0*16); GtMathPs2::Vector3 p0={v0_4d.x,v0_4d.y,v0_4d.z};
    GtMathPs2::Vector4 v1_4d=GtMathPs2::load_vec4(raw_vertices_base+v_idx1*16); GtMathPs2::Vector3 p1={v1_4d.x,v1_4d.y,v1_4d.z};
    GtMathPs2::Vector4 v2_4d=GtMathPs2::load_vec4(raw_vertices_base+v_idx2*16); GtMathPs2::Vector3 p2={v2_4d.x,v2_4d.y,v2_4d.z};
    GtMathPs2::Vector4 v3_4d=GtMathPs2::load_vec4(raw_vertices_base+v_idx3*16); GtMathPs2::Vector3 p3={v3_4d.x,v3_4d.y,v3_4d.z};

    GtMathPs2::Vector3 edge02 = GtMathPs2::subtract(p0, p2); GtMathPs2::Vector3 edge31 = GtMathPs2::subtract(p3, p1);
    GtMathPs2::Vector3 normal = GtMathPs2::cross_product(edge02, edge31);
    float length_sq = GtMathPs2::length_squared(normal);

    if (length_sq < 2.3283064e-10f) { return reinterpret_cast<int64_t>(current_face_ptr); }
    else {
        normal = GtMathPs2::normalize(normal);
        float d_val = GtMathPs2::dot_product(normal, p0);
        GtMathPs2::store_plane(raw_planes_base + planeIndex * 16, normal, d_val);
        return reinterpret_cast<int64_t>(current_face_ptr);
    }
}

void B4ConvexHull::MakeBoxFromBoundingBox(const GtMathPs2::Vector3& minB, const GtMathPs2::Vector3& maxB) {
    uint8_t* raw_verts = m_vertexData.data(); uint8_t* raw_planes = m_planeData.data();
    uint8_t* raw_faces = m_faceData.data(); uint8_t* raw_edges = m_edgeData.data();
    GtMathPs2::Vector4 v[8];
    v[0]={minB.x,minB.y,minB.z,1}; v[1]={maxB.x,minB.y,minB.z,1}; v[2]={minB.x,maxB.y,minB.z,1}; v[3]={maxB.x,maxB.y,minB.z,1};
    v[4]={minB.x,minB.y,maxB.z,1}; v[5]={maxB.x,minB.y,maxB.z,1}; v[6]={minB.x,maxB.y,maxB.z,1}; v[7]={maxB.x,maxB.y,maxB.z,1};
    for(int i=0;i<8;++i) GtMathPs2::store_vec4(raw_verts+i*16,v[i]);
    m_numVertices=8;
    GtMathPs2::store_plane(raw_planes+0*16,GtMathPs2::kBodyFront,GtMathPs2::kBodyFront.z*maxB.z);
    GtMathPs2::store_plane(raw_planes+1*16,GtMathPs2::kBodyBack,GtMathPs2::kBodyBack.z*minB.z);
    GtMathPs2::store_plane(raw_planes+2*16,GtMathPs2::kBodyTop,GtMathPs2::kBodyTop.y*maxB.y);
    GtMathPs2::store_plane(raw_planes+3*16,GtMathPs2::kBodyBottom,GtMathPs2::kBodyBottom.y*minB.y);
    GtMathPs2::store_plane(raw_planes+4*16,GtMathPs2::kBodyRight,GtMathPs2::kBodyRight.x*maxB.x);
    GtMathPs2::store_plane(raw_planes+5*16,GtMathPs2::kBodyLeft,GtMathPs2::kBodyLeft.x*minB.x);
    m_numPlanes=6;
    raw_faces[0]=0;raw_faces[1]=2;raw_faces[2]=3;raw_faces[3]=1; raw_faces[4]=4;raw_faces[5]=0;raw_faces[6]=1;raw_faces[7]=5;
    raw_faces[8]=4;raw_faces[9]=6;raw_faces[10]=2;raw_faces[11]=0; raw_faces[12]=1;raw_faces[13]=3;raw_faces[14]=7;raw_faces[15]=5;
    raw_faces[16]=2;raw_faces[17]=6;raw_faces[18]=7;raw_faces[19]=3; raw_faces[20]=5;raw_faces[21]=7;raw_faces[22]=6;raw_faces[23]=4;
    uint8_t edges_init[] = {0,1,4,5,0,4,5,1,2,3,6,7,2,6,7,3,2,0,3,1,4,6,5,7}; // Matched subtask list
    std::memcpy(raw_edges, edges_init, sizeof(edges_init));
    m_numEdges=12; m_flags=0;
}

void B4ConvexHull::MakeFromBoundingBox(const GtMathPs2::Vector3& minB, const GtMathPs2::Vector3& maxB, EB4HullShape shape) {
    if(shape==EB4HullShape::Cone) MakeConeFromBoundingBox(minB,maxB);
    else if(shape==EB4HullShape::Boat) MakeBoatFromBoundingBox(minB,maxB);
    else MakeBoxFromBoundingBox(minB,maxB);
}

void B4ConvexHull::MakeConeFromBoundingBox(const GtMathPs2::Vector3& minB, const GtMathPs2::Vector3& maxB) {(void)minB;(void)maxB;/*TODO*/}
void B4ConvexHull::MakeBoatFromBoundingBox(const GtMathPs2::Vector3& minB, const GtMathPs2::Vector3& maxB) {(void)minB;(void)maxB;/*TODO*/}

bool B4ConvexHull::DeformHullVerts(GtMathPs2::Vector3* pAvgPos, const GtMathPs2::Vector3& refPos, const GtMathPs2::Matrix3x4& defM, const GtMathPs2::Matrix3x4* boneMs, const B4ConvexHull& origHull) {
    if(!(m_flags&2))return false;
    if(origHull.m_vertexData.size()<origHull.m_numVertices*16)return false;
    if(m_vertexData.size()<origHull.m_numVertices*16)return false;
    if(m_deformData.size()<origHull.m_numVertices*12)return false;
    uint8_t* defVertsPtr=m_vertexData.data(); const uint8_t* origVertsPtr=origHull.m_vertexData.data();
    const uint8_t* deformDataPtr=m_deformData.data(); m_numVertices=origHull.m_numVertices;
    for(uint8_t i=0;i<m_numVertices;++i){
        GtMathPs2::Matrix3x4 accumBoneM; float totalW=0.0f;
        const uint8_t* curDeformEntry=deformDataPtr+i*12;
        const float* Ws=reinterpret_cast<const float*>(curDeformEntry);
        const uint8_t* boneIs=curDeformEntry+8;
        for(int j=0;j<2;++j){
            float w=Ws[j]; if(w==0.0f)continue; totalW+=w; uint8_t bIdx=boneIs[j];
            const GtMathPs2::Matrix3x4&bMRef=boneMs[bIdx];
            GtMathPs2::Matrix3x4 weightedBM=GtMathPs2::matrix_multiply_scalar(bMRef,w);
            accumBoneM=GtMathPs2::matrix_add(accumBoneM,weightedBM);
        }
        float defMW=1.0f-totalW; GtMathPs2::Matrix3x4 finalM=accumBoneM;
        if(defMW>1e-6f){
            GtMathPs2::Matrix3x4 weightedDefM=GtMathPs2::matrix_multiply_scalar(defM,defMW);
            finalM=GtMathPs2::matrix_add(finalM,weightedDefM);
        }
        GtMathPs2::Vector4 oV4=GtMathPs2::load_vec4(origVertsPtr+i*16); GtMathPs2::Vector3 oPos={oV4.x,oV4.y,oV4.z};
        GtMathPs2::Vector3 defPos=GtMathPs2::transform_point(finalM,oPos);
        GtMathPs2::Vector4 defV4={defPos.x,defPos.y,defPos.z,oV4.w};
        GtMathPs2::store_vec4(defVertsPtr+i*16,defV4);
    }
    MakePlanar();
    if(pAvgPos){pAvgPos->x=0;pAvgPos->y=0;pAvgPos->z=0;(void)refPos;}
    return true;
}

void B4ConvexHull::MakePlanar() {
    if(m_numVertices<16||m_vertexData.size()<16*16)return;
    uint8_t*rawVerts=m_vertexData.data();
    auto op=[&](int vA,int vB,int comp,bool minOp){
        GtMathPs2::Vector4 va=GtMathPs2::load_vec4(rawVerts+vA*16); GtMathPs2::Vector4 vb=GtMathPs2::load_vec4(rawVerts+vB*16);
        float*pA=(comp==0)?&va.x:(comp==1)?&va.y:&va.z; float*pB=(comp==0)?&vb.x:(comp==1)?&vb.y:&vb.z;
        float res=minOp?std::min(*pA,*pB):std::max(*pA,*pB); *pA=res;*pB=res;
        GtMathPs2::store_vec4(rawVerts+vA*16,va); GtMathPs2::store_vec4(rawVerts+vB*16,vb);
    };
    op(0,2,0,1);op(0,2,2,1); op(4,6,0,1);op(4,6,2,1); op(8,10,0,1);op(8,10,2,1); op(12,14,0,1);op(12,14,2,1);
    op(1,3,0,0);op(1,3,2,0); op(5,7,0,0);op(5,7,2,0); op(9,11,0,0);op(9,11,2,1); op(13,15,0,0);op(13,15,2,1);
    op(0,1,1,0); op(4,5,1,0); op(8,9,1,0); op(12,13,1,0);
    op(2,3,1,1); op(6,7,1,1); op(10,11,1,1); op(14,15,1,1);
    if(m_numPlanes>0){for(uint8_t i=0;i<m_numPlanes;++i)CalculatePlaneData(i);}
}

void B4ConvexHull::DebugRenderEdges(const GtMathPs2::Matrix3x4& worldTF, bool drawTxt) const {
    if(m_numVertices==0||m_numEdges==0)return;
    std::vector<GtMathPs2::Vector3> worldV(m_numVertices);
    const uint8_t*localVPtr=m_vertexData.data();
    for(uint8_t i=0;i<m_numVertices;++i){
        GtMathPs2::Vector4 lV4=GtMathPs2::load_vec4(localVPtr+i*16); GtMathPs2::Vector3 lPos={lV4.x,lV4.y,lV4.z};
        worldV[i]=GtMathPs2::transform_point(worldTF,lPos);
    }
    const uint8_t*edgeDPtr=m_edgeData.data();
    for(uint8_t eIdx=0;eIdx<m_numEdges;++eIdx){
        uint8_t vIdx0=edgeDPtr[eIdx*2+0]; uint8_t vIdx1=edgeDPtr[eIdx*2+1];
        if(vIdx0>=m_numVertices||vIdx1>=m_numVertices)continue;
        const auto&p1=worldV[vIdx0]; const auto&p2=worldV[vIdx1];
        gDebugManager.DrawLine(p1,p2,{1,1,0,1});
        if(drawTxt){char buf[64];std::snprintf(buf,sizeof(buf),"E%d V%d-V%d",eIdx,vIdx0,vIdx1);
            GtMathPs2::Matrix3x4 dummyOrient(true); GtMathPs2::Vector3 mid=GtMathPs2::multiply_scalar(GtMathPs2::add(p1,p2),0.5f);
            gDebugManager.DrawVectorText(buf,mid,dummyOrient,0.1f,{1,1,1,1});}
    }
}

void B4ConvexHull::DebugRenderPlanes(const GtMathPs2::Matrix3x4& worldTF, bool drawTxt) const {
    if(m_numVertices==0||m_numPlanes==0)return;
    std::vector<GtMathPs2::Vector3> worldV(m_numVertices);
    const uint8_t*localVPtr=m_vertexData.data();
    for(uint8_t i=0;i<m_numVertices;++i){
        GtMathPs2::Vector4 lV4=GtMathPs2::load_vec4(localVPtr+i*16); GtMathPs2::Vector3 lPos={lV4.x,lV4.y,lV4.z};
        worldV[i]=GtMathPs2::transform_point(worldTF,lPos);
    }
    const uint8_t*planeDPtr=m_planeData.data(); const uint8_t*faceDPtr=m_faceData.data();
    for(uint8_t pIdx=0;pIdx<m_numPlanes;++pIdx){
        GtMathPs2::Plane lPlane=GtMathPs2::load_plane(planeDPtr+pIdx*16);
        GtMathPs2::Vector3 nl={lPlane.normal_x,lPlane.normal_y,lPlane.normal_z}; float dl=lPlane.d;
        GtMathPs2::Vector3 nwUnnorm=GtMathPs2::transform_normal(nl,worldTF); GtMathPs2::Vector3 nw=GtMathPs2::normalize(nwUnnorm);
        GtMathPs2::Vector3 pLocalOnPlane=GtMathPs2::multiply_scalar(nl,dl);
        GtMathPs2::Vector3 pWorldOnPlane=GtMathPs2::transform_point(worldTF,pLocalOnPlane);
        float dw=GtMathPs2::dot_product(nw,pWorldOnPlane);
        GtMathPs2::Vector3 faceCenter={0,0,0}; uint8_t numFaceV=0;
        if(m_faceData.size()>=(pIdx+1)*4){
            const uint8_t*faceVIdxs=faceDPtr+pIdx*4;
            for(int k=0;k<4;++k){if(faceVIdxs[k]<m_numVertices){faceCenter=GtMathPs2::add(faceCenter,worldV[faceVIdxs[k]]);numFaceV++;}}
        }
        if(numFaceV>0)faceCenter=GtMathPs2::multiply_scalar(faceCenter,1.0f/numFaceV); else faceCenter=pWorldOnPlane;
        gDebugManager.DrawLine(faceCenter,GtMathPs2::add(faceCenter,GtMathPs2::multiply_scalar(nw,0.5f)),{0,1,1,1});
        if(drawTxt){char buf[128];std::snprintf(buf,sizeof(buf),"P%d N(%.1f,%.1f,%.1f) D(%.1f)",pIdx,nw.x,nw.y,nw.z,dw);
            GtMathPs2::Matrix3x4 dummyOrient(true);
            gDebugManager.DrawVectorText(buf,faceCenter,dummyOrient,0.1f,{1,1,1,1});}
    }
}

void B4ConvexHull::InitialiseVehicleHull() {
    // This function in C sets the m_offset* members to point to the
    // embedded data arrays (m_faceData, m_planeData, etc.) within the struct.
    // Our Fixup() method achieves the same goal for the C++ class structure,
    // where m_offset* members (uintptr_t) are set to the .data() addresses
    // of their corresponding std::vector members.
    this->Fixup();
}
