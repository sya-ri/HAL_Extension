#ifndef CONFIG_DISABLE_MODULE_GPIO

#include "gpio/HAL_Extension_gpio_dynamic_seven_segment.hpp"

namespace halex {

namespace {
    uint8_t getNumberOfDigit(float num) {
        uint64_t numAsUInt = (uint64_t) ((num < 0)? -num : num);
        uint64_t compare = 10;
        uint8_t numberOfDigit = 1;
        while(!(numAsUInt < compare)) {
            compare *= 10;
            numberOfDigit ++;
        }
        return numberOfDigit;
    }
}

DynamicSevenSegment::DynamicSevenSegment(): DynamicSevenSegment(SevenSegment()) {}

DynamicSevenSegment::DynamicSevenSegment(
	const SevenSegment &sevenSegment,
	bool hex,
	bool zeroFill,
	bool allowSign
):
	sevenSegment(sevenSegment),
	digitSystem(hex? 16 : 10),
	zeroFill(zeroFill),
	allowSign(allowSign)
{

}

DynamicSevenSegment& DynamicSevenSegment::add(const GPIO &gpio) noexcept {
    digitList.push_back(gpio);
    return *this;
}

DynamicSevenSegment& DynamicSevenSegment::add(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) noexcept {
    return add(GPIO(GPIOx, GPIO_Pin));
}

void DynamicSevenSegment::update(int64_t num, uint8_t point) const noexcept {
    splitNum.clear();
    bool isMinus = num < 0;
    if(isMinus) {
        num *= -1;
    }
    do {
        splitNum.push_back((int8_t)(num % digitSystem));
        num /= digitSystem;
    } while(0 < num);
    if(zeroFill) {
        int8_t fillNumber = digitList.size() - splitNum.size();
        if(allowSign) {
            fillNumber --;
        }
        while(0 < fillNumber) {
            splitNum.push_back(0);
            fillNumber --;
        }
    }
    if(allowSign && isMinus) {
        splitNum.push_back(-1);
    }
    uint8_t numSize = splitNum.size();
    if(numSize != 0) {
        digitCursor = numSize - 1;
        isStop = false;
    } else {
        isStop = true;
    }
    this->point = point;
}

void DynamicSevenSegment::update(int64_t num) const noexcept {
    update(num, -1);
}

void DynamicSevenSegment::updateFixedPoint(float num, int8_t point) const noexcept {
    for(uint8_t i = 0; i < point; i++) {
        num *= 10;
    }
    update((int64_t) num, digitList.size() - point);
}

void DynamicSevenSegment::updateFloatPoint(float num) const noexcept {
    updateFixedPoint(num, getNumberOfDigit(num));
}

void DynamicSevenSegment::next() const noexcept {
    if(isStop) return;
    digitList[digitCursor].reset();
    digitCursor ++;
    if(splitNum.size() <= digitCursor || digitList.size() <= digitCursor) {
        digitCursor = 0;
    }
    sevenSegment.set(splitNum[digitCursor], digitCursor == point);
    digitList[digitCursor].set();
}

void DynamicSevenSegment::clear() const noexcept {
    isStop = true;
    sevenSegment.clear();
    digitList[digitCursor].reset();
}

} // namespace halex

#endif // CONFIG_DISABLE_MODULE_GPIO
