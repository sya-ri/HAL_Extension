#ifndef HAL_EXTENSION_GPIO_DIP_SWITCH_HPP
#define HAL_EXTENSION_GPIO_DIP_SWITCH_HPP

#ifndef CONFIG_DISABLE_MODULE_GPIO

#include <vector>
#include "HAL_Extension_gpio_gpio.hpp"

class DIPSwitch {
private:
    std::vector<GPIO> list;
    bool flip;
public:
    DIPSwitch(bool flip = false);
    DIPSwitch& add(GPIO gpio) noexcept;
    DIPSwitch& add(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) noexcept;
    uint8_t getSize() const noexcept;
    uint8_t getAddress() const noexcept;
};

#endif // CONFIG_DISABLE_MODULE_GPIO

#endif // HAL_EXTENSION_GPIO_DIP_SWITCH_HPP
