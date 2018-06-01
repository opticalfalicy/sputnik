#ifndef SAGE_MATH_H
#define SAGE_MATH_H

#include <xmmintrin.h>


/*
* Four component float vector
*
*/
typedef struct VEC4F {
    union {
        struct {
            float x;
            float y;    
            float z;
            float w;
        };
        __m128 m;
    };
} vec4f;

typedef struct MATRIX4F {
    union {
        struct {
            vec4f v0;
            vec4f v1;
            vec4f v2;
            vec4f v3;  
        };   
        struct {
            float m00;
            float m01;
            float m02;
            float m03;
            float m04;
            float m05;
            float m06;
            float m07;
            float m08;
            float m09;
            float m10;
            float m11;
            float m12;
            float m13;
            float m14;
            float m15;
        };
    };
} matrix4f;

extern float vec4f_dot(const vec4f *const v, const vec4f *const u);
extern vec4f vec4f_add(const vec4f *const v, const vec4f *const u);
extern vec4f vec4f_sub(const vec4f *const v, const vec4f *const u);

#define vec4f_mul(T, V) _Generic((T), const vec4f *const: vec4f_mul_v, float: vec4f_mul_s)(T, V)

extern vec4f vec4f_mul_v(const vec4f *const v, const vec4f *const u);
extern vec4f vec4f_mul_s(float s, const vec4f *const v);

#endif /* SAGE_MATH_H */
