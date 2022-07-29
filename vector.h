#pragma once

#include <stdbool.h>
#include "types.h"
#include <immintrin.h>

/* 2 element vector types */
#ifdef __clang__
#define vec2_shuf(x, y, a, b) (__builtin_shufflevector((x), (y), (a), (2+b)))
#else
#define vec2_shuf_mask(a, b) _MM_SHUFFLE2(a, b)
#define vec2_shuf(x, y, a, b) (__builtin_ia32_shufps((x), (y), vec2_shuf_mask((a),(b))))
#define vec2d_shuf_mask(a, b) _MM_SHUFFLE2(a, b) 
#define vec2d_shuf(x, y, a, b) (__builtin_ia32_shufpd((x), (y), vec2d_shuf_mask((a),(b))))
#endif

static inline vec2f vec2f_one(bool l, bool h) __attribute__((always_inline));
static inline vec2f vec2f_one(bool l, bool h) { return (vec2f){ l ? 1.0f : 0.0f, h ? 1.0f : 0.0f }; }
static inline vec2f vec2f_zero(void) __attribute__((always_inline));
static inline vec2f vec2f_zero(void) { return (vec2f){ 0.0f, 0.0f }; }
static inline vec2d vec2d_zero(void) __attribute__((always_inline));
static inline vec2d vec2d_zero(void) { return _mm_setzero_pd(); }
#if defined(__DOUBLE_PRECISION_SCALAR__)
#define vec2_one  vec2d_one
#define vec2_zero vec2d_zero
#else
#define vec2_one  vec2f_one
#define vec2_zero vec2f_zero
#endif

static inline void vec2_print(vec2 a) __attribute__((always_inline));
static inline void vec2_print(vec2 a)
{
	printf("%f %f\n", a[0], a[1]);
}

/* 4 element vector types */
#ifdef __clang__
#define vec4_shuf(x, y, a, b, c, d) (__builtin_shufflevector((x), (y), (a), (b), (4+c), (4+d)))
#else
#define vec4_shuf_mask(a, b, c, d) (((a) << 0) | ((b) << 2) | ((c) << 4) | ((d) << 6))
#define vec4_shuf(x, y, a, b, c, d) (__builtin_ia32_shufps((x), (y), vec4_shuf_mask((a),(b),(c),(d))))
#define vec4d_shuf_mask(a, b) _mm_shuffle2(a, b) 
#define vec4d_shuf(x, y, a, b) (__builtin_ia32_shufpd((x), (y), vec4d_shuf_mask((a),(b))))
#endif

static inline vec4f vec4f_one(bool A, bool B, bool C, bool D) __attribute__((always_inline));
static inline vec4f vec4f_one(bool A, bool B, bool C, bool D) { return _mm_setr_ps( A ? 1.0f : 0.0f, B ? 1.0f : 0.0f, C ? 1.0f : 0.0f, D ? 1.0f : 0.0f); }
static inline vec4f vec4f_zero(void) __attribute__((always_inline));
static inline vec4f vec4f_zero(void) { return _mm_setzero_ps(); }
static inline vec4d vec4d_zero(void) __attribute__((always_inline));
static inline vec4d vec4d_zero(void) { vec2d v[2] = { vec2d_zero(), vec2d_zero() }; return *(vec4d*)&v[0]; }

#if defined(__DOUBLE_PRECISION_SCALAR__)
#define vec4_one  vec4d_one
#define vec4_zero vec4d_zero
#else
#define vec4_one  vec4f_one
#define vec4_zero vec4f_zero
#endif

static inline void vec4_print(vec4 a) __attribute__((always_inline));
static inline void vec4_print(vec4 a)
{
	printf("%f %f %f %f\n", a[0], a[1], a[2], a[3]);
}

#define vec2_splat(v, x)   vec2_shuf((v), (v), (x), (x))
#define vec3_splat(v, x)   vec4_shuf((v), (v), (x), (x),  (x),  (x))
#define vec4_splat(v, x)   vec4_shuf((v), (v), (x), (x),  (x),  (x))

/* 4 element vector functions */
static inline vec4  vec4_xyz(vec4 x) __attribute__((always_inline));
static inline vec4  vec4_xyz(vec4 x) { return vec4_shuf(x, vec4_shuf(x, vec4_zero(), 2, 3, 0, 0), 0, 1, 0, 3); }
static inline vec4  vec4_xyz1(vec4 x) __attribute__((always_inline));
static inline vec4  vec4_xyz1(vec4 x) { return vec4_shuf(x, vec4_shuf(x, _mm_set_ss(1.0), 2, 2, 0, 1), 0, 1, 0, 2); }
static inline vec4d vec4d_xyz(vec4d x) __attribute__((always_inline));
static inline vec4d vec4d_xyz(vec4d x) { vec2d v[2] ={ *(vec2d*)&x[0], vec2d_shuf(*(vec2d*)&x[2], vec2d_shuf(*(vec2d*)&x[2], _mm_setzero_pd(), 1, 0), 1, 0) }; return *(vec4d*)&v[0]; }
static inline vec4d vec4d_xyz1(vec4 x) __attribute__((always_inline));
static inline vec4d vec4d_xyz1(vec4 x) { vec2d v[2] = { *(vec2d*)&x[0], vec2d_shuf(*(vec2d*)&x[2], vec2d_shuf(*(vec2d*)&x[2], _mm_set_sd(1.0), 1, 0), 1, 0) }; return *(vec4d*)&v[0]; }



