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
	bool repeatedlyState;
	bool longPushed;
	uint32_t chatteringTime = 0; // chatteringを判定する時間
	uint32_t rawChangeTime; // チャタリング処理前
protected:
    uint32_t pressedTime;
public:
	Button(GPIO_TypeDef * GPIOx, uint16_t GPIO_Pin, GPIO_PinState normalState);
    Button(GPIO_TypeDef * GPIOx, uint16_t GPIO_Pin);
	void init(uint32_t chatteringTime);
	void update();
	void setChatteringDelayTim(uint32_t tmpDelayTim);
	bool isPushed();
	bool isReleased();
	bool isPushing();
	bool isLongPushed(uint32_t longPushedTime);
	uint32_t getPushingTime();
	virtual bool getState();
    virtual bool getRepeatedly(uint16_t outputPeriodTime, uint16_t waitingTim); // state が true のとき，一定間隔で true を出力する
};

} // namespace halex

#endif // __has_include

#endif /* HAL_EXTENSION_BUTTON_HPP_ */
