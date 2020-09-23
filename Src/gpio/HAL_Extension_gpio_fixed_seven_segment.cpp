#include "gpio/HAL_Extension_gpio_fixed_seven_segment.hpp"

FixedSevenSegment::FixedSevenSegment(bool flip): flip(flip) {
    list.reserve(4);
}

FixedSevenSegment& FixedSevenSegment::add(GPIO gpio) {
    if(!isAvailable()){
        list.push_back(gpio);
    } else if(!enablePoint) {
        pointGpio = gpio;
        enablePoint = true;
    }
    return *this;
}

FixedSevenSegment& FixedSevenSegment::add(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin){
    return add(GPIO(GPIOx, GPIO_Pin));
}

bool FixedSevenSegment::setLight(uint8_t lightData){
    return set(lightData & 0xF, lightData & 0x10);
}

bool FixedSevenSegment::set(int8_t hex, bool point){
    if(isAvailable()){
        if(point && enablePoint){
            pointGpio.set();
        }
        for(int i = 0; i < 4; i++){
            uint8_t outData = hex & 1;
            list[i].write((GPIO_PinState) (flip? ~outData : outData));
            hex >>= 1;
        }
        return true;
    } else {
        return false;
    }
}

bool FixedSevenSegment::clear(){
    return set(0);
}

bool FixedSevenSegment::isAvailable(){
    return list.size() == 4;
}