#ifndef HAL_EXTENSION_UTIL_FUNCTION_MATH_ANGLE_HPP
#define HAL_EXTENSION_UTIL_FUNCTION_MATH_ANGLE_HPP

#include <cmath>

namespace halex {

constexpr float deg2rad(float deg) {
    return deg * 2.0F * M_PI / 360.0F;
}

constexpr float rad2deg(float rad) {
    return rad / 2.0F / M_PI * 360.0F;
}

} // namespace halex

#endif // HAL_EXTENSION_UTIL_FUNCTION_MATH_ANGLE_HPP
