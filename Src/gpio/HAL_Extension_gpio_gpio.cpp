#ifndef CONFIG_DISABLE_MODULE_GPIO

#include "gpio/HAL_Extension_gpio_gpio.hpp"
#include "HAL_Extension_util.hpp"

GPIO::GPIO(){}

GPIO::GPIO(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin): GPIOx(GPIOx), GPIO_Pin(GPIO_Pin){

}

GPIO_PinState GPIO::read(){
    return gpioRead(GPIOx, GPIO_Pin);
}

bool GPIO::isSet(){
    return read() == GPIO_PIN_SET;
}

bool GPIO::isReset(){
    return read() == GPIO_PIN_RESET;
}

void GPIO::write(GPIO_PinState PinState){
    gpioWrite(GPIOx, GPIO_Pin, PinState);
}

void GPIO::set(){
    write(GPIO_PIN_SET);
}

void GPIO::reset(){
    write(GPIO_PIN_RESET);
}

void GPIO::toggle(){
    gpioToggle(GPIOx, GPIO_Pin);
}

#endif // CONFIG_DISABLE_MODULE_GPIO