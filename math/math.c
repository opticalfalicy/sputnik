#include "math.h"

float dot(vec4f v, vec4f u) {
	return v.data.v.x * u.data.v.x + v.data.v.y * u.data.v.y + v.data.v.z * u.data.v.z;
}

vec4f add(vec4f v, vec4f u) {
	vec4f res = {.data.m = _mm_add_ps(v.data.m, u.data.m)};
	return res;
}
