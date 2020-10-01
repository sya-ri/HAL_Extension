#ifndef HAL_EXTENSION_GPIO_FUNCTION_HPP
#define HAL_EXTENSION_GPIO_FUNCTION_HPP

#ifndef CONFIG_DISABLE_MODULE_GPIO

#include "gpio.h"

namespace halex {

GPIO_PinState gpioRead(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) noexcept;
void gpioWrite(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState) noexcept;
void gpioToggle(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) noexcept;

} // namespace halex

#endif // CONFIG_DISABLE_MODULE_GPIO

#endif // HAL_EXTENSION_GPIO_FUNCTION_HPP
