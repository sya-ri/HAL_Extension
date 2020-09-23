#ifndef HAL_EXTENSION_GPIO_FIXED_SEVEN_SEGMENT_HPP
#define HAL_EXTENSION_GPIO_FIXED_SEVEN_SEGMENT_HPP

#ifndef CONFIG_DISABLE_MODULE_GPIO

#include <vector>
#include "HAL_Extension_gpio_seven_segment.hpp"

class FixedSevenSegment: public SevenSegment {
private:
    std::vector<GPIO> list;
    bool flip;
    bool enablePoint = false;
    GPIO pointGpio;
public:
    FixedSevenSegment(bool flip = false);
    FixedSevenSegment& add(GPIO gpio);
    FixedSevenSegment& add(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) override;
    bool setLight(uint8_t lightData) override;
    bool set(int8_t hex, bool point = false) override;
    bool clear() override;
    bool isAvailable() override;
};

#endif // CONFIG_DISABLE_MODULE_GPIO

#endif // HAL_EXTENSION_GPIO_FIXED_SEVEN_SEGMENT_HPP
