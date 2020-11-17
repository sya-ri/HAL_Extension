#ifndef HAL_EXTENSION_GPIO_DYNAMIC_SEVEN_SEGMENT_HPP
#define HAL_EXTENSION_GPIO_DYNAMIC_SEVEN_SEGMENT_HPP

#ifndef CONFIG_DISABLE_MODULE_GPIO

#include <vector>
#include "HAL_Extension_gpio_seven_segment.hpp"

namespace halex {

class DynamicSevenSegment {
private:
    const SevenSegment &sevenSegment;
    const bool zeroFill;
    const bool allowSign;
    const bool overflowError;
    std::vector<GPIO> digitList;
    mutable uint8_t digitCursor = 0;
    mutable std::vector<int8_t> splitNum;
    mutable bool isStop = true;
    mutable uint8_t point = 0;

    void update(int64_t num, uint8_t point) const noexcept;
    void updateError() const noexcept;
    void updateZeroFill() const noexcept;
public:
    DynamicSevenSegment();
    DynamicSevenSegment(const SevenSegment &sevenSegment, bool zeroFill = false, bool allowSign = false, bool overflowError = true);
    DynamicSevenSegment& add(const GPIO &gpio) noexcept;
    DynamicSevenSegment& add(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) noexcept;
    void update(int64_t num) const noexcept;
    void updateFixedPoint(float num, int8_t point) const noexcept;
    void updateFloatPoint(float num) const noexcept;
    void updateHex(uint64_t num) const noexcept;
    void next() const noexcept;
    void clear() const noexcept;
};

} // namespace halex

#endif // CONFIG_DISABLE_MODULE_GPIO

#endif // HAL_EXTENSION_GPIO_DYNAMIC_SEVEN_SEGMENT_HPP
