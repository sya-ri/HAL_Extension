#ifndef CONFIG_DISABLE_MODULE_GPIO

#include "gpio/HAL_Extension_gpio.hpp"
#include "HAL_Extension_util.hpp"

GPIO::GPIO(){}

GPIO::GPIO(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin): GPIOx(GPIOx), GPIO_Pin(GPIO_Pin){

}

GPIO_PinState GPIO::read() const noexcept {
    return HAL_GPIO_ReadPin(GPIOx, GPIO_Pin);
}

bool GPIO::isSet() const noexcept {
    return read() == GPIO_PIN_SET;
}

bool GPIO::isReset() const noexcept {
    return read() == GPIO_PIN_RESET;
}

void GPIO::write(GPIO_PinState PinState) const noexcept {
    HAL_GPIO_WritePin(GPIOx, GPIO_Pin, PinState);
}

void GPIO::set() const noexcept {
    write(GPIO_PIN_SET);
}

void GPIO::reset() const noexcept {
    write(GPIO_PIN_RESET);
}

void GPIO::toggle() const noexcept {
    HAL_GPIO_TogglePin(GPIOx, GPIO_Pin);
}

#endif // CONFIG_DISABLE_MODULE_GPIO
