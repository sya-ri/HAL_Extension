#ifndef HAL_EXTENSION_UTIL_FUNCTION_MATH_ANGLE_HPP
#define HAL_EXTENSION_UTIL_FUNCTION_MATH_ANGLE_HPP

#include <cmath>
#include "angle_type.hpp"

namespace halex {

constexpr float deg2rad(float deg) {
    return deg * 2.0F * M_PI / 360.0F;
}

constexpr float rad2deg(float rad) {
    return rad / 2.0F / M_PI * 360.0F;
}

constexpr float angle2rad(float angle, AngleType angleType) {
    return (angleType == AngleType::Radian)? angle : deg2rad(angle);
}

constexpr float angle2deg(float angle, AngleType angleType) {
    return (angleType == AngleType::Degree)? angle : rad2deg(angle);
}

} // namespace halex

#endif // HAL_EXTENSION_UTIL_FUNCTION_MATH_ANGLE_HPP
