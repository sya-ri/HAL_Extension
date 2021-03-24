#ifndef HAL_EXTENSION_GPIO_DYNAMIC_SEVEN_SEGMENT_HPP
#define HAL_EXTENSION_GPIO_DYNAMIC_SEVEN_SEGMENT_HPP

#ifndef CONFIG_DISABLE_MODULE_GPIO

#include <vector>
#include "HAL_Extension_gpio_seven_segment.hpp"

namespace halex {

class DynamicSevenSegment {
private:
    struct Digit {
        GPIO select;
        mutable int8_t display;

        static constexpr int8_t unused_display = -127;
    };

    const SevenSegment &sevenSegment;
    bool zeroFill = true;
    bool allowSign = true;
    bool overflowError = true;
    std::vector<Digit> digitList;
    mutable uint8_t digitCursor = 0;
    mutable bool isStop = true;
    mutable uint8_t point = 0;

    void start(int8_t point) const noexcept;
    void update(int64_t num, int8_t point) const noexcept;
    void updateError() const noexcept;
    void fillInt(uint8_t from, uint8_t until, uint64_t num, int8_t base) const noexcept;
    void fillAll(uint8_t from, uint8_t until, int8_t value) const noexcept;
    void fillZeroOrEmpty(uint8_t from, uint8_t until) const noexcept;
public:
    DynamicSevenSegment();
    DynamicSevenSegment(const SevenSegment &sevenSegment);
    DynamicSevenSegment& add(const GPIO &gpio) noexcept;
    DynamicSevenSegment& add(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) noexcept;
    DynamicSevenSegment& setZeroFill(bool enable) noexcept;
    DynamicSevenSegment& setAllowSign(bool enable) noexcept;
    DynamicSevenSegment& setOverflowError(bool enable) noexcept;
    void update(int64_t num) const noexcept;
    void updateFixedPoint(float num, int8_t point) const noexcept;
    void updateFloatPoint(float num) const noexcept;
    void updateExp(float num) const noexcept;
    void updateHex(uint64_t num) const noexcept;
    void next() const noexcept;
    void clear() const noexcept;
};

} // namespace halex

#endif // CONFIG_DISABLE_MODULE_GPIO

#endif // HAL_EXTENSION_GPIO_DYNAMIC_SEVEN_SEGMENT_HPP
