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

extern float vec4f_dot(const vec4f *const v, const vec4f *const u);
extern vec4f vec4f_add(const vec4f *const v, const vec4f *const u);
extern vec4f vec4f_sub(const vec4f *const v, const vec4f *const u);
extern vec4f vec4f_mul_v(const vec4f *const v, const vec4f *const u);
extern vec4f vec4f_mul_s(float s, const vec4f *const v);

#endif /* SAGE_MATH_H */
