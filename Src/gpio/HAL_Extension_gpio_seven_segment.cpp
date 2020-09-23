#ifndef CONFIG_DISABLE_MODULE_GPIO

#include "gpio/HAL_Extension_gpio_seven_segment.hpp"
#include <array>

namespace {
    const std::array<const uint8_t, 17> lightDataTable = {
            0b0111111, // 0x0
            0b0000110, // 0x1
            0b1011011, // 0x2
            0b1001111, // 0x3
            0b1100110, // 0x4
            0b1101101, // 0x5
            0b1111101, // 0x6
            0b0000111, // 0x7
            0b1111111, // 0x8
            0b1101111, // 0x9
            0b1110111, // 0xA
            0b1111100, // 0xB
            0b0111001, // 0xC
            0b1011110, // 0xD
            0b1111001, // 0xE
            0b1110001, // 0xF
            0b1000000  //  -
    };
}

SevenSegment::SevenSegment(bool flip): flip(flip) {
    list.reserve(7);
}

SevenSegment& SevenSegment::add(GPIO gpio){
    if(!isAvailable()){
        list.push_back(gpio);
    } else if(!enablePoint) {
        pointGpio = gpio;
        enablePoint = true;
    }
    return *this;
}

SevenSegment& SevenSegment::add(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin){
    return add(GPIO(GPIOx, GPIO_Pin));
}

bool SevenSegment::setLight(uint8_t lightData){
    if(!isAvailable()) return false;
    uint8_t mask = 1;
    for(auto segment : list){
        uint8_t outData = lightData & mask;
        segment.write((GPIO_PinState) (flip? ~outData : outData));
        mask <<= 1;
    }
    if(enablePoint){
        uint8_t outData = lightData & mask;
        pointGpio.write((GPIO_PinState) (flip? ~outData : outData));
    }
    return true;
}

bool SevenSegment::set(int8_t hex, bool point){
    uint8_t lightData;
    if(hex < 0){
        lightData = lightDataTable[16];
    } else {
        lightData = lightDataTable[hex & 0xF];
    }
    if(point){
        lightData |= 1 << 7;
    }
    return setLight(lightData);
}

bool SevenSegment::clear(){
    return setLight(0);
}

bool SevenSegment::isAvailable(){
    return list.size() == 7;
}

#endif // CONFIG_DISABLE_MODULE_GPIO