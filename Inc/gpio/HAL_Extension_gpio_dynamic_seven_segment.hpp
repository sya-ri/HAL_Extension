#ifndef HAL_EXTENSION_GPIO_DYNAMIC_SEVEN_SEGMENT_HPP
#define HAL_EXTENSION_GPIO_DYNAMIC_SEVEN_SEGMENT_HPP

#ifndef CONFIG_DISABLE_MODULE_GPIO

#include <vector>
#include "HAL_Extension_gpio_seven_segment.hpp"

class DynamicSevenSegment {
private:
    SevenSegment sevenSegment;
    std::vector<GPIO> digitList;
    uint8_t digitCursor = 0;
    std::vector<int8_t> splitNum;
    uint8_t digitSystem;
    bool zeroFill;
    bool allowSign;
    bool isStop = true;
    uint8_t point = 0;
    void update(int64_t num, uint8_t point);
public:
    DynamicSevenSegment();
    DynamicSevenSegment(SevenSegment sevenSegment, bool hex = false, bool zeroFill = false, bool allowSign = false);
    DynamicSevenSegment& add(GPIO gpio);
    DynamicSevenSegment& add(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
    void update(int64_t num);
    void updateFixedPoint(float num, uint8_t point);
    void updateFloatPoint(float num);
    void next();
    void stop();
};

#endif // CONFIG_DISABLE_MODULE_GPIO

#endif // HAL_EXTENSION_GPIO_DYNAMIC_SEVEN_SEGMENT_HPP
