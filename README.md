# forcemath

SIMD math library based on @rikusalminen's (threcedee-simd)[http://github.com/rikusalminen/threedee-simd] for OpenGL 3D engine frameworks written in C

## Overview
	
### Types

	vec2 - 2 element scalar type based vector type
	vec4 - 4 element scalar type based vector type

	mat4 - matrix of 4 columns based on scalar vector type

### Functions

	vec2 vec2_one(bool low, bool high);
	vec2 vec2_zero();
	
	vec4 vec4_one(bool A, bool B, bool C, bool D);
	vec4 vec4_zero();

## Usage

```c
	#include <forcemath.h>
```

`gcc hello.c -lforcemath`

## Authors

Jon Daniel <jondaniel879@gmail.com>
