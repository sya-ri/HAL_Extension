#ifndef HAL_EXTENSION_GPIO_SEVEN_SEGMENT_HPP
#define HAL_EXTENSION_GPIO_SEVEN_SEGMENT_HPP

#if __has_include("gpio.h")

#include <vector>
#include "gpio.hpp"

namespace halex {

class SevenSegment {
private:
    const bool flip;
    std::vector<GPIO> list;
    bool enablePoint = false;
    GPIO pointGpio;
public:
    SevenSegment(bool flip = false);
    virtual SevenSegment& add(const GPIO &gpio) noexcept;
    virtual SevenSegment& add(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) noexcept;
    virtual bool setLight(uint8_t lightData) const noexcept;
    virtual bool set(int8_t hex, bool point = false) const noexcept;
    virtual bool clear() const noexcept;
    virtual bool isAvailable() const noexcept;
};

} // namespace halex

#endif // __has_include

#endif // HAL_EXTENSION_GPIO_SEVEN_SEGMENT_HPP
