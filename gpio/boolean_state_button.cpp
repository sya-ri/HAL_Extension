#if __has_include("gpio.h")

#include "boolean_state_button.hpp"

namespace halex {

void BooleanStateButton::update() {
    Button::update();
    if(isPushed()){
        //holdValueを反転
        holdState = !holdState;
    }

    if(getState()) { // これがそれぞれのクラスのgetstateを使ってくれているかわからない ここ消して問題なければ消す
        //long pressed
        pressedTime = HAL_GetTick();
    }
}

bool BooleanStateButton::getState() {
    return holdState;
}

//bool Button::getRepeatedly(uint16_t outputPeriodTime, uint16_t waitingTim){ //while the button is down
//    return (getState() && getPushingTime() > waitingTim && ( (getPushingTime() - waitingTim) % outputPeriodTime) == 0);
//}

} // namespace halex

#endif // __has_include
