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

extern float dot(vec4f *v, vec4f *u);
extern vec4f add(vec4f *v, vec4f *u);
extern vec4f sub(vec4f *v, vec4f *u);

#endif /* SAGE_MATH_H */
