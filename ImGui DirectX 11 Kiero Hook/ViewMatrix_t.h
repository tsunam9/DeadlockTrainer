#pragma once
#pragma once
// used: sse2 intrinsics
#include <xmmintrin.h>
// used: bit_cast
#include <bit>
#include "helper.h"


struct ViewMatrix_t
{
    float arrData[4][4]; // Declare arrData as a 4x4 array of floats

    ViewMatrix_t() = default;

    constexpr ViewMatrix_t(
        const float m00, const float m01, const float m02, const float m03,
        const float m10, const float m11, const float m12, const float m13,
        const float m20, const float m21, const float m22, const float m23,
        const float m30, const float m31, const float m32, const float m33)
    {
        arrData[0][0] = m00;
        arrData[0][1] = m01;
        arrData[0][2] = m02;
        arrData[0][3] = m03;
        arrData[1][0] = m10;
        arrData[1][1] = m11;
        arrData[1][2] = m12;
        arrData[1][3] = m13;
        arrData[2][0] = m20;
        arrData[2][1] = m21;
        arrData[2][2] = m22;
        arrData[2][3] = m23;
        arrData[3][0] = m30;
        arrData[3][1] = m31;
        arrData[3][2] = m32;
        arrData[3][3] = m33;
    }
};