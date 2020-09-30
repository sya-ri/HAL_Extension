#ifndef HAL_EXTENSION_GPIO_HPP
#define HAL_EXTENSION_GPIO_HPP

#ifndef CONFIG_DISABLE_MODULE_GPIO

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
    void reset() const noexcept;
    void toggle() const noexcept;
};

} // namespace halex

#endif // CONFIG_DISABLE_MODULE_GPIO

#endif // HAL_EXTENSION_GPIO_HPP
