#if __has_include("gpio.h")

#include "button.hpp"

namespace halex {

Button::Button(GPIO_TypeDef * GPIOx, uint16_t GPIO_Pin, GPIO_PinState normalyState) : normalyState(normalyState) {
    gpio = GPIO(GPIOx, GPIO_Pin);
}

Button::Button(GPIO_TypeDef * GPIOx, uint16_t GPIO_Pin) {
    Button(GPIOx, GPIO_Pin, GPIO_PIN_RESET);
}

void Button::update() {
	lastRawState = rawState;
	if(normalyState == GPIO_PIN_RESET) {
	    rawState = gpio.isSet();
	}else {
	    rawState = gpio.isReset();
	}

	// チャタリング防止
	if(lastRawState != rawState) {
	    rawChangeTime = HAL_GetTick();
	}
	if( HAL_GetTick() - rawChangeTime >= chatteringTime ) {
		state = rawState;
	}

    if(getState()) { // todo これがそれぞれのクラスのgetstateを使ってくれているかわからない
        //long pressed
        pressedTime = HAL_GetTick();
    }
}

void Button::setChatteringDelayTim(uint32_t chatteringTime) {
	this->chatteringTime = chatteringTime;
}

bool Button::isPushed() {
	return (lastState ^ state) & state;
}

bool Button::isReleased() {
	return (lastState ^ state) & lastState;
}

bool Button::isPushing() {
	return state;
}

bool Button::isLongPushed(uint32_t longPushingTime) {
    return (pressedTime + longPushingTime < HAL_GetTick());
}

uint32_t Button::getPushingTime() {
    return HAL_GetTick() - pressedTime;
}

bool Button::getState() {
    return isPushing();
}

bool Button::getRepeatedly(uint16_t outputPeriodTime, uint16_t waitingTim) {
    return (getState() && getPushingTime() > waitingTim && ( (getPushingTime() - waitingTim) % outputPeriodTime) == 0);
}

} // namespace halex

#endif // __has_include
