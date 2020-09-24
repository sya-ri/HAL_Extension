#ifndef CONFIG_DISABLE_MODULE_GPIO

#include "gpio/HAL_Extension_gpio_dip_switch.hpp"

DIPSwitch::DIPSwitch(bool flip): flip(flip) {
    list.reserve(8);
}

DIPSwitch& DIPSwitch::add(GPIO gpio) noexcept {
    if(getSize() < 8){
        list.push_back(gpio);
    }
    return *this;
}

DIPSwitch& DIPSwitch::add(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) noexcept {
    return add(GPIO(GPIOx, GPIO_Pin));
}

uint8_t DIPSwitch::getSize() const noexcept {
    return list.size();
}

uint8_t DIPSwitch::getAddress() const noexcept {
    uint8_t builder = 0;
    for(int i = 0; i < getSize(); i++){
        builder |= list[i].read() << i;
    }
    return flip? ~builder : builder;
}

#endif // CONFIG_DISABLE_MODULE_GPIO
