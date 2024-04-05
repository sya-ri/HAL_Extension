#ifndef HAL_EXTENSION_BUTTON_HPP_
#define HAL_EXTENSION_BUTTON_HPP_

#if __has_include("gpio.h")

#include "gpio.h"
#include "gpio.hpp"

namespace halex {

class Button {
private:
    GPIO gpio;
    GPIO_PinState normalyState;
	bool state;
    bool lastState;
	bool rawState;
	bool lastRawState;
    uint32_t chatteringTime = 0; // チャタリング判定時間
	uint32_t rawChangeTime;
public:
	Button(GPIO_TypeDef * GPIOx, uint16_t GPIO_Pin, GPIO_PinState normalState, uint32_t chatteringTime);
	Button(GPIO_TypeDef * GPIOx, uint16_t GPIO_Pin, GPIO_PinState normalState);
    Button(GPIO_TypeDef * GPIOx, uint16_t GPIO_Pin);
	void init(uint32_t chatteringTime);
	void update();
	bool isPushed();
	bool isReleased();
	virtual bool getState();
};

} // namespace halex

#endif // __has_include

#endif /* HAL_EXTENSION_BUTTON_HPP_ */
