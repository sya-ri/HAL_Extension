#ifndef HAL_EXTENSION_GPIO_BOOLEAN_STATE_BUTTON_HPP_
#define HAL_EXTENSION_GPIO_BOOLEAN_STATE_BUTTON_HPP_

#if __has_include("gpio.h")

#include "button.hpp"

namespace halex {

class BooleanStateButton : public Button{
private:
    bool holdState;
public:
    using Button::Button;
    void update();
    bool getState() override;
};

} // namespace halex

#endif // __has_include

#endif /* HAL_EXTENSION_GPIO_BOOLEAN_STATE_BUTTON_HPP_ */
