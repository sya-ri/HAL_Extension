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
	    lastState = state;
		state = rawState;
	}
}

bool Button::isPushed() {
	return (lastState ^ state) & state;
}

bool Button::isReleased() {
	return (lastState ^ state) & lastState;
}

bool Button::getState() {
    return state;
}

} // namespace halex

#endif // __has_include
