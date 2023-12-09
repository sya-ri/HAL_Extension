#ifndef HAL_EXTENSION_GPIO_FIXED_SEVEN_SEGMENT_HPP
#define HAL_EXTENSION_GPIO_FIXED_SEVEN_SEGMENT_HPP

#if __has_include("gpio.h")

#include <vector>
#include "seven_segment.hpp"

namespace halex {

class FixedSevenSegment: public SevenSegment {
private:
    const bool flip;
    std::vector<GPIO> list;
    bool enablePoint = false;
    GPIO pointGpio;
public:
    FixedSevenSegment(bool flip = false);
    FixedSevenSegment& add(const GPIO &gpio) noexcept override;
    FixedSevenSegment& add(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) noexcept override;
    bool setLight(uint8_t lightData) const noexcept override;
    bool set(int8_t hex, bool point = false) const noexcept override;
    bool clear() const noexcept override;
    bool isAvailable() const noexcept override;
};

} // namespace halex

#endif // __has_include

#endif // HAL_EXTENSION_GPIO_FIXED_SEVEN_SEGMENT_HPP
