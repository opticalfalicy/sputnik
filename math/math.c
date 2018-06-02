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
