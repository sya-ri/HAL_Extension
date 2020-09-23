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
    DIPSwitch& add(GPIO gpio);
    DIPSwitch& add(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
    uint8_t getSize();
    uint8_t getAddress();
};

#endif // CONFIG_DISABLE_MODULE_GPIO

#endif // HAL_EXTENSION_GPIO_DIP_SWITCH_HPP
