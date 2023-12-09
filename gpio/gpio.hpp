#ifndef HAL_EXTENSION_GPIO_HPP
#define HAL_EXTENSION_GPIO_HPP

#if __has_include("gpio.h")

#include "gpio.h"

namespace halex {

class GPIO {
private:
    GPIO_TypeDef* GPIOx;
    uint16_t GPIO_Pin;
public:
    GPIO();
    GPIO(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
    GPIO_PinState read() const noexcept;
    bool isSet() const noexcept;
    bool isReset() const noexcept;
    void write(GPIO_PinState PinState) const noexcept;
    void set() const noexcept;
    void setIf(bool condition) const noexcept;
    void reset() const noexcept;
    void resetIf(bool condition) const noexcept;
    void toggle() const noexcept;
};

} // namespace halex

#endif // __has_include

#endif // HAL_EXTENSION_GPIO_HPP
