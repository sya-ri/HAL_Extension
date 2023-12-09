#ifndef HAL_EXTENSION_GPIO_FUNCTION_HPP
#define HAL_EXTENSION_GPIO_FUNCTION_HPP

#if __has_include("gpio.h")

#include "gpio.h"

namespace halex {

inline GPIO_PinState gpioRead(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) noexcept {
    return HAL_GPIO_ReadPin(GPIOx, GPIO_Pin);
}

inline void gpioWrite(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState) noexcept {
    HAL_GPIO_WritePin(GPIOx, GPIO_Pin, PinState);
}

inline void gpioToggle(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) noexcept {
    HAL_GPIO_TogglePin(GPIOx, GPIO_Pin);
}

} // namespace halex

#endif // __has_include

#endif // HAL_EXTENSION_GPIO_FUNCTION_HPP
