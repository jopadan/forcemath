#pragma once
#include <cstdlib>
#include <cstdio>
#include <experimental/simd>
#include <mmintrin.h>
#include <limits>
#include <GL/glcorearb.h>
#include <experimental/simd>
#include <mmintrin.h>

/* fixed point scalar types */
template <typename _int_type, typename _float_type, 
_int_type   DECIMAL_BITS   = (_int_type)std::numeric_limits<_int_type>::digits / 2, 
_int_type   FRACTION_BITS  = (_int_type)std::numeric_limits<_int_type>::digits - DECIMAL_BITS, 
_int_type   SCALE          = (_int_type)1 << FRACTION_BITS, 
_float_type PRECISION      = (_float_type)1.0 / SCALE, 
_float_type ACCURACY       = (_float_type)(PRECISION/2.0), 
_int_type   DECIMAL_MAX    = (_int_type)1 << DECIMAL_BITS, 
_int_type   DECIMAL_MIN    = (_int_type)-1 << DECIMAL_BITS, 
_float_type FRACTIONAL_MAX = (_float_type)DECIMAL_MAX + (_float_type)(1.0 - PRECISION), 
_float_type FRACTIONAL_MIN = (_float_type)DECIMAL_MIN>
struct fixed
{
	_int_type _value;

	fixed(_float_type f) { _value = from_float(f); }
	_int_type from_float(_float_type f) { return (_int_type)round(f * (_float_type)SCALE); }
	operator _int_type() const { return (_int_type)(_value * PRECISION); }
	operator _float_type() const { return (_float_type)(_value * PRECISION); }
	constexpr friend fixed& operator+=(fixed lhs, const fixed& rhs) { lhs._value += rhs._value; return lhs; } 
	constexpr friend fixed& operator-=(fixed lhs, const fixed& rhs) { lhs._value -= rhs._value; return lhs; } 
	constexpr friend fixed& operator+(fixed lhs, const fixed& rhs) { lhs += rhs; return lhs; } 
	constexpr friend fixed& operator-(fixed lhs, const fixed& rhs) { lhs -= rhs; return lhs; }

};

/* fixed point vector types */
using vec2fi  = std::array<fixed<int,float,16,16>, 2>;
using vec3fi  = std::array<fixed<int,float,16,16>, 3>;
using vec4fi  = std::array<fixed<int,float,16,16>, 4>;

/* floating point types */
using vec2f = std::array<GLfloat, 2>;
using vec3f = std::array<GLfloat, 3>;
using vec4f = std::array<GLfloat, 4>;

using vec2d = std::array<GLdouble, 2>;
using vec3d = std::array<GLdouble, 3>;
using vec4d = std::array<GLdouble, 4>;

/* integer vector types */
using vec2si = std::array<khronos_int32_t, 2>;
using vec2ui = std::array<khronos_uint32_t, 2>;
using vec2sq = std::array<khronos_int64_t, 2>;
using vec2uq = std::array<khronos_uint64_t, 2>;

using vec3si = std::array<khronos_int32_t, 3>;
using vec3ui = std::array<khronos_uint32_t, 3>;
using vec3sq = std::array<khronos_int64_t, 3>;
using vec3uq = std::array<khronos_uint64_t, 3>;

using vec4si = std::array<khronos_int32_t, 4>;
using vec4ui = std::array<khronos_uint32_t, 4>;
using vec4sq = std::array<khronos_int64_t, 4>;
using vec4uq = std::array<khronos_uint64_t, 4>;

/* floating point matrix types */
using mat4f  = std::array<vec4f, 4>;
using mat4d  = std::array<vec4d, 4>;

/* integer matrix types */
using mat2si = std::array<vec2si, 2>;
using mat2ui = std::array<vec2ui, 2>;
using mat2sq = std::array<vec2sq, 2>;
using mat2uq = std::array<vec2uq, 2>;

using mat4si = std::array<vec4si, 4>;
using mat4ui = std::array<vec4ui, 4>;
using mat4sq = std::array<vec4sq, 4>;
using mat4uq = std::array<vec4uq, 4>;

/* standard types */
using vec2 = vec2f;
using vec3 = vec3f;
using vec4 = vec4f;
