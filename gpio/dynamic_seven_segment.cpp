#if __has_include("gpio.h")

#include "gpio/dynamic_seven_segment.hpp"

namespace halex {

namespace {
    uint8_t getNumberOfDigit(uint64_t num, uint64_t base) {
        uint64_t compare = base;
        uint8_t numberOfDigit = 1;
        while(compare <= num) {
            compare *= base;
            numberOfDigit ++;
        }
        return numberOfDigit;
    }
}

DynamicSevenSegment::DynamicSevenSegment(): DynamicSevenSegment(SevenSegment()) {}

DynamicSevenSegment::DynamicSevenSegment(
    const SevenSegment &sevenSegment
):
    sevenSegment(sevenSegment)
{

}

DynamicSevenSegment& DynamicSevenSegment::add(const GPIO &gpio) noexcept {
    digitList.push_back({gpio, -1});
    return *this;
}

DynamicSevenSegment& DynamicSevenSegment::add(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) noexcept {
    return add(GPIO(GPIOx, GPIO_Pin));
}

DynamicSevenSegment& DynamicSevenSegment::setZeroFill(bool enable) noexcept {
    zeroFill = enable;
    return *this;
}

DynamicSevenSegment& DynamicSevenSegment::setAllowSign(bool enable) noexcept {
    allowSign = enable;
    return *this;
}

DynamicSevenSegment& DynamicSevenSegment::setOverflowError(bool enable) noexcept {
    overflowError = enable;
    return *this;
}

void DynamicSevenSegment::start(int8_t point) const noexcept {
    digitCursor = 0;
    isStop = false;
    this->point = point;
}

void DynamicSevenSegment::update(int64_t num, int8_t point) const noexcept {
    bool isMinus = num < 0;
    if(isMinus) num *= -1;
    uint8_t digitListSize = digitList.size();
    uint8_t numberOfDigit = getNumberOfDigit(num, 10);
    if(digitListSize < numberOfDigit) return updateError();
    fillInt(0, numberOfDigit, num, 10);
    fillZeroOrEmpty(numberOfDigit, digitListSize);
    fillAll(numberOfDigit, point + 1, 0);
    if(allowSign && isMinus) {
        if(digitListSize == numberOfDigit) return updateError();
        digitList[zeroFill? (digitListSize - 1) : numberOfDigit].display = -1;
    }
    start(point);
}

void DynamicSevenSegment::updateError() const noexcept {
    for(auto& d : digitList) {
        d.display = -1;
    }
    start(-1);
}

void DynamicSevenSegment::fillInt(uint8_t from, uint8_t until, uint64_t num, int8_t base) const noexcept {
    for(uint8_t i = from; i < until; i++){
        digitList[i].display = (int8_t)(num % base);
        num /= base;
    }
}

void DynamicSevenSegment::fillAll(uint8_t from, uint8_t until, int8_t value) const noexcept {
    for(uint8_t i = from; i < until; i++){
        digitList[i].display = value;
    }
}

void DynamicSevenSegment::fillZeroOrEmpty(uint8_t from, uint8_t until) const noexcept {
    fillAll(from, until, zeroFill? 0 : Digit::unused_display);
}

void DynamicSevenSegment::update(int64_t num) const noexcept {
    update(num, -1);
}

void DynamicSevenSegment::updateFixedPoint(float num, int8_t point) const noexcept {
    for(uint8_t i = 0; i < point; i++) {
        num *= 10;
    }
    update((int64_t) num, point);
}

void DynamicSevenSegment::updateFloatPoint(float num) const noexcept {
    int8_t digitListSize = digitList.size();
    bool isMinus = num < 0;
    if(allowSign && isMinus) digitListSize --;
    int8_t point = digitListSize - getNumberOfDigit(isMinus? -num : num, 10);
    updateFixedPoint(num, point);
}

void DynamicSevenSegment::updateExp(float num) const noexcept {
    if(num == 0.0F) return updateFloatPoint(0);
    bool isMinusNum = num < 0;
    if(isMinusNum) num *= -1;
    int8_t exponent = 0;
    while(num < 1) {
        exponent --;
        num *= 10.0F;
    }
    while(10 <= num) {
        exponent ++;
        num /= 10.0F;
    }
    bool isMinusExponent = exponent < 0;
    uint8_t numberOfExponent = getNumberOfDigit(isMinusExponent? -exponent : exponent, 10);
    if(isMinusExponent) {
        numberOfExponent ++;
        exponent *= -1;
    }
    int8_t digitListSize = digitList.size();
    int8_t numberOfMantissa = digitListSize - numberOfExponent - 1;
    if(isMinusNum) numberOfMantissa --;
    if(numberOfMantissa < 0) return updateError();
    fillInt(0, numberOfExponent, exponent, 10);
    uint8_t i = numberOfExponent;
    if(isMinusExponent) {
        digitList[i].display = -1;
        i++;
    }
    digitList[i].display = 0xE;
    uint8_t mostDigitMantissa = digitListSize - 1;
    if(allowSign && isMinusNum) {
        digitList[mostDigitMantissa].display = -1;
        mostDigitMantissa --;
    }
    for(uint8_t j = mostDigitMantissa; i < j; j--) {
        digitList[j].display = (int8_t)((uint64_t)(num) % 10);
        num *= 10;
    }
    start(mostDigitMantissa);
}

void DynamicSevenSegment::updateHex(uint64_t num) const noexcept {
    uint8_t digitListSize = digitList.size();
    uint8_t numberOfDigit = getNumberOfDigit(num, 0x10);
    if(digitListSize < numberOfDigit) return updateError();
    fillInt(0, numberOfDigit, num, 0x10);
    fillZeroOrEmpty(numberOfDigit, digitListSize);
    start(-1);
}

void DynamicSevenSegment::next() const noexcept {
    if(isStop) return;
    digitList[digitCursor].select.reset();
    digitCursor ++;
    if(digitList.size() <= digitCursor) {
        digitCursor = 0;
    }
    if(digitList[digitCursor].display != Digit::unused_display) {
        sevenSegment.set(digitList[digitCursor].display, digitCursor == point);
        digitList[digitCursor].select.set();
    }
}

void DynamicSevenSegment::clear() const noexcept {
    isStop = true;
    sevenSegment.clear();
    digitList[digitCursor].select.reset();
}

} // namespace halex

#endif // __has_include