#ifndef HAL_EXTENSION_UTIL_FUNCTION_GENERAL_HPP
#define HAL_EXTENSION_UTIL_FUNCTION_GENERAL_HPP

#include "main.h"

namespace halex {

inline uint32_t getTick() noexcept {
    return HAL_GetTick();
}

inline void delay(uint32_t ms) noexcept {
    HAL_Delay(ms);
}

} // namespace halex

#endif // HAL_EXTENSION_UTIL_FUNCTION_GENERAL_HPP
