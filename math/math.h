#ifndef SAGE_MATH_H
#define SAGE_MATH_H

#include <xmmintrin.h>

typedef struct VEC4F {
	union DATA {
		struct VEC {
			float x;
			float y;	
			float z;
			float w;
		} v;
		__m128 m;
	} data;
} vec4f;

extern float dot(vec4f v, vec4f u);
extern vec4f add(vec4f v, vec4f u);


#endif /* SAGE_MATH_H */
