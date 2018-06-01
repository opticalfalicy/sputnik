#include "math.h"

#include <assert.h>

float dot(vec4f *v, vec4f *u) 
{
	assert(v && u);
	return v->x * u->x + v->y * u->y + v->z * u->z;
}

vec4f add(vec4f *v, vec4f *u) 
{
	assert(v && u);
	return (vec4f) {.m = _mm_add_ps(v->m, u->m)};
}

vec4f sub(vec4f *v, vec4f *u) 
{
	assert(v && u);
	return (vec4f) {.m = _mm_sub_ps(v->m, u->m)};
}
