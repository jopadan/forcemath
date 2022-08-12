# forcemath

SIMD math library based on @rikusalminen's [threedee-simd](http://github.com/rikusalminen/threedee-simd) for OpenGL 3D engine frameworks written in C

## Overview
	
### Types

	scalar - single or double precision floating point scalar type

	vec2 - 2 element scalar type based vector type
	vec4 - 4 element scalar type based vector type

	mat4 - matrix of 4 columns based on scalar vector type

### Functions

	vec2 vec2_one(bool low, bool high);
	vec2 vec2_zero();
	vec2 vec2_xyz(vec2 v);
	vec2 vec2_xyz1(vec2 v);
	vec2 vec2_splat(vec2 v, uint8_t x);
	
	vec4 vec4_one(bool A, bool B, bool C, bool D);
	vec4 vec4_zero();
	vec4 vec4_xyz(vec4 v);
	vec4 vec4_xyz1(vec4 v);
	vec4 vec4_splat(vec4 v, uint8_t x);

	mat4 mat4_identity();
## Usage

```c
	#include <forcemath.h>
```

`gcc hello.c -lforcemath`

## Authors

Jon Daniel <jondaniel879@gmail.com>
