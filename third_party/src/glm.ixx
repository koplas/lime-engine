module;
// c++ modules workaround
#include <locale>

#include <algorithm>
#include <cassert>
#include <cfloat>
#include <cmath>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <limits>
#include <ostream>
#include <string>
#include <type_traits>
#include <utility>

export module glm;

#define GLM_FORCE_DEPTH_ZERO_TO_ONE

export {

#include <glm/glm.hpp>

#include <glm/common.hpp>           // all the GLSL common functions: abs, min, mix, isnan, fma, etc.
#include <glm/exponential.hpp>      // all the GLSL exponential functions: pow, log, exp2, sqrt, etc.
#include <glm/geometric.hpp>        // all the GLSL geometry functions: dot, cross, reflect, etc.
#include <glm/integer.hpp>          // all the GLSL integer functions: findMSB, bitfieldExtract, etc.
#include <glm/mat2x2.hpp>           // mat2, dmat2
#include <glm/mat2x3.hpp>           // mat2x3, dmat2x3
#include <glm/mat2x4.hpp>           // mat2x4, dmat2x4
#include <glm/mat3x2.hpp>           // mat3x2, dmat3x2
#include <glm/mat3x3.hpp>           // mat3, dmat3
#include <glm/mat3x4.hpp>           // mat3x4, dmat2
#include <glm/mat4x2.hpp>           // mat4x2, dmat4x2
#include <glm/mat4x3.hpp>           // mat4x3, dmat4x3
#include <glm/mat4x4.hpp>           // mat4, dmat4
#include <glm/matrix.hpp>           // all the GLSL matrix functions: transpose, inverse, etc.
#include <glm/packing.hpp>          // all the GLSL packing functions: packUnorm4x8, unpackHalf2x16, etc.
#include <glm/trigonometric.hpp>    // all the GLSL trigonometric functions: radians, cos, asin, etc.
#include <glm/vec2.hpp>             // vec2, bvec2, dvec2, ivec2 and uvec2
#include <glm/vec3.hpp>             // vec3, bvec3, dvec3, ivec3 and uvec3
#include <glm/vec4.hpp>             // vec4, bvec4, dvec4, ivec4 and uvec4
#include <glm/vector_relational.hpp>// all the GLSL vector relational functions: equal, less, etc.
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/quaternion.hpp>
}