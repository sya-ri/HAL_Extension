#ifndef HAL_EXTENSION_GPIO_SEVEN_SEGMENT_HPP
#define HAL_EXTENSION_GPIO_SEVEN_SEGMENT_HPP

#ifndef CONFIG_DISABLE_MODULE_GPIO

#include <vector>
#include "HAL_Extension_gpio_gpio.hpp"

class SevenSegment {
private:
    std::vector<GPIO> list;
    bool flip;
    bool enablePoint = false;
    GPIO pointGpio;
public:
    SevenSegment(bool flip = false);
    virtual SevenSegment& add(GPIO gpio) noexcept;
    virtual SevenSegment& add(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) noexcept;
    virtual bool setLight(uint8_t lightData) const noexcept;
    virtual bool set(int8_t hex, bool point = false) const noexcept;
    virtual bool clear() const noexcept;
    virtual bool isAvailable() const noexcept;
};

#endif // CONFIG_DISABLE_MODULE_GPIO

#endif // HAL_EXTENSION_GPIO_SEVEN_SEGMENT_HPP
