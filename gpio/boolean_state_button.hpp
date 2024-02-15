#ifndef HAL_EXTENSION_GPIO_BOOLEAN_STATE_BUTTON_HPP_
#define HAL_EXTENSION_GPIO_BOOLEAN_STATE_BUTTON_HPP_

#if __has_include("gpio.h")

#include "button.hpp"

namespace halex {

class BooleanStateButton : Button{
private:
    bool holdState;
protected:
public:
    using Button::Button;
    void update();
    bool getState() override;
//    bool getRepeatedly(uint16_t outputPeriodTime, uint16_t waitingTim) override; //while the button is down
};

} // namespace halex

#endif // __has_include

#endif /* HAL_EXTENSION_GPIO_BOOLEAN_STATE_BUTTON_HPP_ */
