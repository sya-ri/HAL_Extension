#ifndef HAL_EXTENSION_GPIO_GPIO_HPP
#define HAL_EXTENSION_GPIO_GPIO_HPP

#ifndef CONFIG_DISABLE_MODULE_GPIO

#include "gpio.h"

class GPIO {
private:
    GPIO_TypeDef* GPIOx;
    uint16_t GPIO_Pin;
public:
    GPIO();
    GPIO(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
    GPIO_PinState read();
    bool isSet();
    bool isReset();
    void write(GPIO_PinState PinState);
    void set();
    void reset();
    void toggle();
};

#endif // CONFIG_DISABLE_MODULE_GPIO

#endif // HAL_EXTENSION_GPIO_GPIO_HPP
