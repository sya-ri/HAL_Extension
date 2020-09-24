#ifndef HAL_EXTENSION_GPIO_DYNAMIC_SEVEN_SEGMENT_HPP
#define HAL_EXTENSION_GPIO_DYNAMIC_SEVEN_SEGMENT_HPP

#ifndef CONFIG_DISABLE_MODULE_GPIO

#include <vector>
#include "HAL_Extension_gpio_seven_segment.hpp"

class DynamicSevenSegment {
private:
    const SevenSegment &sevenSegment;
    const uint8_t digitSystem;
    const bool zeroFill;
    const bool allowSign;
    std::vector<GPIO> digitList;
    mutable uint8_t digitCursor = 0;
    mutable std::vector<int8_t> splitNum;
    mutable bool isStop = true;
    mutable uint8_t point = 0;

    void update(int64_t num, uint8_t point) const noexcept;
public:
    DynamicSevenSegment();
    DynamicSevenSegment(const SevenSegment &sevenSegment, bool hex = false, bool zeroFill = false, bool allowSign = false);
    DynamicSevenSegment& add(GPIO gpio) noexcept;
    DynamicSevenSegment& add(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) noexcept;
    void update(int64_t num) const noexcept;
    void updateFixedPoint(float num, int8_t point) const noexcept;
    void updateFloatPoint(float num) const noexcept;
    void next() const noexcept;
    void clear() const noexcept;
};

#endif // CONFIG_DISABLE_MODULE_GPIO

#endif // HAL_EXTENSION_GPIO_DYNAMIC_SEVEN_SEGMENT_HPP
