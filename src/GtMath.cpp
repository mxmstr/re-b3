#include "GtMath.h"


// GtMathPs2 placeholder namespace and types
namespace GtMath {
    

    struct CGtLine { int type_placeholder; };
    //using CGtV4d = Vector4;

    Vector3 add(const Vector3& a, const Vector3& b) { return Vector3(a.x + b.x, a.y + b.y, a.z + b.z); }
    Vector3 multiply_scalar(const Vector3& v, float s) { return Vector3(v.x * s, v.y * s, v.z * s); }
    Matrix3x4 matrix_multiply_scalar(const Matrix3x4& M, float s) { Matrix3x4 r; for (int i = 0; i < 3; ++i) for (int j = 0; j < 4; ++j) r.mat[i][j] = M.mat[i][j] * s; return r; }
    Matrix3x4 matrix_add(const Matrix3x4& A, const Matrix3x4& B) { Matrix3x4 r; for (int i = 0; i < 3; ++i) for (int j = 0; j < 4; ++j) r.mat[i][j] = A.mat[i][j] + B.mat[i][j]; return r; }
    Vector3 transform_point(const Matrix3x4& M, const Vector3& p) { return Vector3(M.mat[0][0] * p.x + M.mat[0][1] * p.y + M.mat[0][2] * p.z + M.mat[0][3], M.mat[1][0] * p.x + M.mat[1][1] * p.y + M.mat[1][2] * p.z + M.mat[1][3], M.mat[2][0] * p.x + M.mat[2][1] * p.y + M.mat[2][2] * p.z + M.mat[2][3]); }
    Vector3 transform_normal(const Vector3& n, const Matrix3x4& M) { return Vector3(M.mat[0][0] * n.x + M.mat[0][1] * n.y + M.mat[0][2] * n.z, M.mat[1][0] * n.x + M.mat[1][1] * n.y + M.mat[1][2] * n.z, M.mat[2][0] * n.x + M.mat[2][1] * n.y + M.mat[2][2] * n.z); }
    Vector3 subtract(const Vector3& a, const Vector3& b) { return Vector3(a.x - b.x, a.y - b.y, a.z - b.z); }
    Vector3 cross_product(const Vector3& a, const Vector3& b) { return Vector3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x); }
    float dot_product(const Vector3& a, const Vector3& b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
    float length_squared(const Vector3& v) { return v.x * v.x + v.y * v.y + v.z * v.z; }
    Vector3 normalize(const Vector3& v) { float l = length_squared(v); if (l > 1e-6f) { float inv_l = 1.0f / sqrtf(l); return Vector3(v.x * inv_l, v.y * inv_l, v.z * inv_l); } return Vector3(0, 0, 0); }
    Vector4 load_vec4(const uint8_t* p) { const float* fp = reinterpret_cast<const float*>(p); return Vector4(fp[0], fp[1], fp[2], fp[3]); }
    void store_vec4(uint8_t* dest, const Vector4& vec) { float* fp = reinterpret_cast<float*>(dest); fp[0] = vec.x; fp[1] = vec.y; fp[2] = vec.z; fp[3] = vec.w; }
    void store_plane(uint8_t* p, const Vector3& normal, float d_val) { float* fp = reinterpret_cast<float*>(p); fp[0] = normal.x; fp[1] = normal.y; fp[2] = normal.z; fp[3] = d_val; }
    Plane load_plane(const uint8_t* p) { const float* fp = reinterpret_cast<const float*>(p); return Plane(fp[0], fp[1], fp[2], fp[3]); }
}