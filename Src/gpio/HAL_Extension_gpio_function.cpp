#ifndef CONFIG_DISABLE_MODULE_GPIO

#include "gpio/HAL_Extension_gpio_function.hpp"

namespace halex {

GPIO_PinState gpioRead(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) noexcept {
    return HAL_GPIO_ReadPin(GPIOx, GPIO_Pin);
}

void gpioWrite(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState) noexcept {
    HAL_GPIO_WritePin(GPIOx, GPIO_Pin, PinState);
}

void gpioToggle(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) noexcept {
    HAL_GPIO_TogglePin(GPIOx, GPIO_Pin);
}

} // namespace halex

#endif // CONFIG_DISABLE_MODULE_GPIO
