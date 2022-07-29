#pragma once

#include "types.h"
#include "vector.h"

static inline void mat4_print(mat4 a) __attribute__((always_inline));
static inline void mat4_print(mat4 a)
{
	vec4_print(a.cols[0]);
	vec4_print(a.cols[1]);
	vec4_print(a.cols[2]);
	vec4_print(a.cols[3]);
}

static inline mat4 mat4_identity() __attribute__((always_inline));
static inline mat4 mat4_identity()
{
    vec4 one = _mm_set_ss(1.0);
    vec4 row0 = vec4_shuf(one, one, 0, 1, 1, 1);
    vec4 row1 = vec4_shuf(one, one, 1, 0, 1, 1);
    vec4 row2 = vec4_shuf(one, one, 1, 1, 0, 1);
    vec4 row3 = vec4_shuf(one, one, 1, 1, 1, 0);
    mat4 identity = {{ row0, row1, row2, row3 }};
    return identity;
}

static inline mat4 mat4_zero() __attribute__((always_inline));
static inline mat4 mat4_zero()
{
    mat4 zero = {{ vec4_zero(), vec4_zero(), vec4_zero(), vec4_zero() }};
    return zero;
}
