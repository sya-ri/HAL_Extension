#ifndef HAL_EXTENSION_GPIO_DIP_SWITCH_HPP
#define HAL_EXTENSION_GPIO_DIP_SWITCH_HPP

#ifndef CONFIG_DISABLE_MODULE_GPIO

#include <vector>
#include "HAL_Extension_gpio.hpp"

namespace halex {

class DIPSwitch {
private:
    const bool flip;
    std::vector<GPIO> list;
public:
    DIPSwitch(bool flip = false);
    DIPSwitch& add(const GPIO &gpio) noexcept;
    DIPSwitch& add(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) noexcept;
    uint8_t getSize() const noexcept;
    uint8_t getAddress() const noexcept;
};

} // namespace halex

#endif // CONFIG_DISABLE_MODULE_GPIO

#endif // HAL_EXTENSION_GPIO_DIP_SWITCH_HPP
