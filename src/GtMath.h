#pragma once
#include <cstring> // For std::memset
#include <cstdint>
#include <cmath>   // For sqrtf

// Placeholder for actual alignment macro
#ifndef ALIGNED_DECL
#define ALIGNED_DECL(N) alignas(N)
#endif

// Forward declarations for GtMathPs2 types (if needed for future member functions)
namespace GtMath {
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
        Plane(float nx = 0.f, float ny = 0.f, float nz = 0.f, float _d = 0.f) : normal_x(nx), normal_y(ny), normal_z(nz), d(_d) {}
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
        Vector3 get_col(int c) const { return { mat[0][c], mat[1][c], mat[2][c] }; }
        void set_col(int c, const Vector3 & v) { mat[0][c] = v.x; mat[1][c] = v.y; mat[2][c] = v.z; }
        Vector3 get_translation() const { return { mat[0][3], mat[1][3], mat[2][3] }; }
        void set_translation(const Vector3 & t) { mat[0][3] = t.x; mat[1][3] = t.y; mat[2][3] = t.z; }
    };

    const Vector3 kBodyFront = { 0.0f, 0.0f, 1.0f };
    const Vector3 kBodyBack = { 0.0f, 0.0f, -1.0f };
    const Vector3 kBodyTop = { 0.0f, 1.0f, 0.0f };
    const Vector3 kBodyBottom = { 0.0f, -1.0f, 0.0f };
    const Vector3 kBodyRight = { 1.0f, 0.0f, 0.0f };
    const Vector3 kBodyLeft = { -1.0f, 0.0f, 0.0f };

    struct CGtLine; // Placeholder for line drawing parameters
    struct CGtV4d;  // Placeholder for color or text parameters (Vector4 double?)

    Vector3 add(const Vector3& a, const Vector3& b);
    Vector3 multiply_scalar(const Vector3& v, float s);
    Matrix3x4 matrix_multiply_scalar(const Matrix3x4& M, float s);
    Matrix3x4 matrix_add(const Matrix3x4& A, const Matrix3x4& B);
    Vector3 transform_point(const Matrix3x4& M, const Vector3& p);
    Vector3 transform_normal(const Vector3& n, const Matrix3x4& M);
    
    Vector3 subtract(const Vector3& a, const Vector3& b);
    Vector3 cross_product(const Vector3& a, const Vector3& b);
    float dot_product(const Vector3& a, const Vector3& b);
    float length_squared(const Vector3& v);
    Vector3 normalize(const Vector3& v);
    Vector4 load_vec4(const uint8_t* p);
    void store_vec4(uint8_t* dest, const Vector4& vec);
    void store_plane(uint8_t* p, const Vector3& normal, float d_val);
    Plane load_plane(const uint8_t* p);
}