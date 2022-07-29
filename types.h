#pragma once

#include <stdint.h>
#include <stddef.h>

#if defined(__DOUBLE_PRECISION_SCALAR__)
typedef double scalar;
#else
typedef float scalar;
#endif

/* alignment of vector type */
#if ! ((defined __sun__ || defined __VXWORKS__) && defined __i386__)
#define REQUIRED_ALIGNMENT (uint8_t)(4 * sizeof(scalar) < __alignof__(max_align_t) ? 4 * sizeof(scalar) : __alignof__(max_align_t))
#else
#define REQUIRED_ALIGNMENT (uint8_t)(4 * sizeof(scalar))
#endif
#define SCALAR_SUFFIX s

/* single precision vector types */
typedef float vec2f   __attribute__((vector_size( sizeof(float) * 2 )));
typedef float vec3f[3];
typedef float vec4f   __attribute__((vector_size( sizeof(float) * 4 )));

/* double precision vector types */
typedef double vec2d   __attribute__((vector_size( sizeof(double) * 2 )));
typedef double vec3d[3];
typedef double vec4d   __attribute__((vector_size( sizeof(double) * 4 )));

/* default precision vector types */
#if defined(__DOUBLE_PRECISION_SCALAR__)
typedef vec2d  vec2;
typedef vec3d  vec3;
typedef vec4d  vec4;
#else
typedef vec2f  vec2;
typedef vec3f  vec3;
typedef vec4f  vec4;
#endif

/* matrix type */
struct mat4_t
{
    vec4 cols[4];
} __attribute__((aligned( REQUIRED_ALIGNMENT )));

/* single precision matrix type */
struct mat4f_t
{
    vec4f cols[4];
} __attribute__((aligned( REQUIRED_ALIGNMENT )));

/* double precision matrix type */
struct mat4d_t
{
    vec4d cols[4];
} __attribute__((aligned( REQUIRED_ALIGNMENT )));

typedef struct mat4_t mat4;
typedef struct mat4f_t mat4f;
typedef struct mat4d_t mat4d;
typedef struct mat4ld_t mat4ld;

