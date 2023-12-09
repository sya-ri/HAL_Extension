#include "gpio/gpio.hpp"
#include "gpio/function.hpp"
#include "util/function.hpp"

namespace halex {

GPIO::GPIO() {}

GPIO::GPIO(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin): GPIOx(GPIOx), GPIO_Pin(GPIO_Pin) {

}

GPIO_PinState GPIO::read() const noexcept {
    return gpioRead(GPIOx, GPIO_Pin);
}

bool GPIO::isSet() const noexcept {
    return read() == GPIO_PIN_SET;
}

bool GPIO::isReset() const noexcept {
    return read() == GPIO_PIN_RESET;
}

void GPIO::write(GPIO_PinState PinState) const noexcept {
    gpioWrite(GPIOx, GPIO_Pin, PinState);
}

void GPIO::set() const noexcept {
    write(GPIO_PIN_SET);
}

void GPIO::setIf(bool condition) const noexcept {
    if (condition) {
        set();
    } else {
        reset();
    }
}

void GPIO::reset() const noexcept {
    write(GPIO_PIN_RESET);
}

void GPIO::resetIf(bool condition) const noexcept {
    setIf(!condition);
}

void GPIO::toggle() const noexcept {
    gpioToggle(GPIOx, GPIO_Pin);
}

} // namespace halex
