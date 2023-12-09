#include "gpio/fixed_seven_segment.hpp"

namespace halex {

FixedSevenSegment::FixedSevenSegment(bool flip): flip(flip) {
    list.reserve(4);
}

FixedSevenSegment& FixedSevenSegment::add(const GPIO &gpio) noexcept {
    if(!isAvailable()) {
        list.push_back(gpio);
    } else if(!enablePoint) {
        pointGpio = gpio;
        enablePoint = true;
    }
    return *this;
}

FixedSevenSegment& FixedSevenSegment::add(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) noexcept {
    return add(GPIO(GPIOx, GPIO_Pin));
}

bool FixedSevenSegment::setLight(uint8_t lightData) const noexcept {
    return set(lightData & 0xF, lightData & 0x10);
}

bool FixedSevenSegment::set(int8_t hex, bool point) const noexcept {
    if(isAvailable()) {
        if(point && enablePoint) {
            pointGpio.set();
        }
        for(int i = 0; i < 4; i++) {
            uint8_t outData = hex & 1;
            list[i].write((GPIO_PinState) (flip? ~outData : outData));
            hex >>= 1;
        }
        return true;
    } else {
        return false;
    }
}

bool FixedSevenSegment::clear() const noexcept {
    return set(0);
}

bool FixedSevenSegment::isAvailable() const noexcept {
    return list.size() == 4;
}

} // namespace halex
