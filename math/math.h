#ifndef SAGE_MATH_H
#define SAGE_MATH_H

typedef struct VEC4F {
	float x;
	float y;
	float z;
	float w;
} vec4f;

extern float dot(vec4f v, vec4f u);

#endif /* SAGE_MATH_H */
