#if __has_include("gpio.h")

#include "boolean_state_button.hpp"

namespace halex {

void BooleanStateButton::update() {
    Button::update();
    if(isPushed()){
        holdState = !holdState;
    }
}

bool BooleanStateButton::getState() {
    return holdState;
}

} // namespace halex

#endif // __has_include
