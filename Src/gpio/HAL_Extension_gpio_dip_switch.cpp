#include "gpio/HAL_Extension_gpio_dip_switch.hpp"

DIPSwitch::DIPSwitch(bool flip): flip(flip) {
    list.reserve(7);
}

DIPSwitch& DIPSwitch::add(GPIO gpio){
    if(getSize() < 7){
        list.push_back(gpio);
    }
    return *this;
}

DIPSwitch& DIPSwitch::add(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin){
    return add(GPIO(GPIOx, GPIO_Pin));
}

uint8_t DIPSwitch::getSize(){
    return list.size();
}

uint8_t DIPSwitch::getAddress(){
    uint8_t builder = 0;
    for(int i = 0; i < getSize(); i++){
        builder |= list[i].read() << i;
    }
    return flip? ~builder : builder;
}