#if __has_include("gpio.h")

#include "button.hpp"

namespace halex {

Button::Button(GPIO_TypeDef * GPIOx, uint16_t GPIO_Pin, GPIO_PinState normalyState, uint32_t chatteringTime) :
        gpio(GPIO(GPIOx, GPIO_Pin)),
        normalyState(normalyState),
        chatteringTime(chatteringTime)
{
}


Button::Button(GPIO_TypeDef * GPIOx, uint16_t GPIO_Pin, GPIO_PinState normalyState) :
        Button(GPIOx, GPIO_Pin, normalyState, 0)
{
}

Button::Button(GPIO_TypeDef * GPIOx, uint16_t GPIO_Pin) :
        Button(GPIOx, GPIO_Pin, GPIO_PIN_RESET)
{
}

void Button::update() {
	lastRawState = rawState;
	if (normalyState == GPIO_PinState::GPIO_PIN_RESET) {
	    rawState = gpio.isSet();
	} else {
	    rawState = gpio.isReset();
	}

	// チャタリング防止
	if (lastRawState != rawState) {
	    rawChangeTime = HAL_GetTick();
	}
	if (chatteringTime <= (HAL_GetTick() - rawChangeTime)) {
	    lastState = state;
		state = rawState;
	}
}

bool Button::isPushed() {
    return state && lastState != state;
}

bool Button::isReleased() {
    return !state && lastState != state;
}

bool Button::getState() {
    return state;
}

} // namespace halex

#endif // __has_include
