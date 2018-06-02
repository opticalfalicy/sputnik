#include "math.h"

#include <assert.h>

float vec4f_dot(const vec4f *const v, const vec4f *const u) 
{
	assert(v && u);
	return v->x * u->x + v->y * u->y + v->z * u->z;
}

vec4f vec4f_add(const vec4f *const v, const vec4f *const u) 
{
	assert(v && u);
	return (vec4f) {.m = _mm_add_ps(v->m, u->m)};
}

vec4f vec4f_sub(const vec4f *const v, const vec4f *const u) 
{
	assert(v && u);
	return (vec4f) {.m = _mm_sub_ps(v->m, u->m)};
}

vec4f __vec4f_mul_v(const vec4f *const v, const vec4f *const u)
{
    assert(v && u);
    return (vec4f) {.m = _mm_mul_ps(v->m, u->m)};
}

vec4f __vec4f_mul_s(float s, const vec4f *const v)
{
    assert(v);
    return (vec4f) {.m = _mm_mul_ps(v->m, _mm_load_ps1(&s))};
}

vec4f __vec4f_mul_m(const matrix4f *const m, const vec4f *const v)
{
    assert(v && m);
    return (vec4f) {
        .x = v->x * m->m00 + v->y * m->m04 + v->z * m->m08 + v->w * m->m12,
        .y = v->x * m->m01 + v->y * m->m05 + v->z * m->m09 + v->w * m->m13,
        .z = v->x * m->m02 + v->y * m->m06 + v->z * m->m10 + v->w * m->m14,
        .w = v->x * m->m03 + v->y * m->m07 + v->z * m->m11 + v->w * m->m15
    };
}
