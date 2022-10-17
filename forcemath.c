#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

//#include "matrix.h"
//#include "rotation.h"
#include "types.hpp"

static inline void vec4_print(vec4 a) __attribute__((always_inline));
static inline void vec4_print(vec4 a)
{
	printf("%f %f %f %f\n", a[0], a[1], a[2], a[3]);
}

int main(int argc, char** argv)
{
//	vec2 b = vec2_one(true, false);
//	vec2_print(b);

	vec4 c = { 1.0f, 2.0, 3.0f, 4.0f };
	vec4_print(c);
//	mat4 a = quat4_to_mat_mmul(c);
//	mat4_print(a);

//	c = vec4_xyz(c);
//	vec4_print(c);

	exit(EXIT_SUCCESS);
}
