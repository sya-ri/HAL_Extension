#ifndef CONFIG_DISABLE_MODULE_TIM

#include "tim/HAL_Extension_tim_pwm.hpp"

namespace halex {

PWM::PWM(){}

PWM::PWM(TIM_HandleTypeDef *htim, uint32_t channel): htim(htim), channel(channel) {

}

PWM::PWM(TIM_HandleTypeDef &htim, uint32_t channel): PWM(&htim, channel) {

}

void PWM::start() const noexcept {
	HAL_TIM_PWM_Start(htim, channel);
}

void PWM::stop() const noexcept {
	HAL_TIM_PWM_Stop(htim, channel);
}

void PWM::setCompare(uint32_t compare) const noexcept {
	__HAL_TIM_SET_COMPARE(htim, channel, compare);
}

void PWM::setCompare(uint16_t numerator, uint16_t denominator) const noexcept {
    if(denominator < numerator) return;
	setCompare(getCounterPeriod() * numerator / denominator);
}

uint32_t PWM::getCounterPeriod() const noexcept {
	return htim->Init.Period;
}

} // namespace halex

#endif // CONFIG_DISABLE_MODULE_TIM
