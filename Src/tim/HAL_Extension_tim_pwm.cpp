#ifndef CONFIG_DISABLE_MODULE_TIM

#include "tim/HAL_Extension_tim_pwm.hpp"

PWM::PWM(){}

PWM::PWM(TIM_HandleTypeDef &htim, uint32_t channel): htim(&htim), channel(channel){
}

void PWM::start() noexcept {
	HAL_TIM_PWM_Start(htim, channel);
}

void PWM::stop() noexcept {
	HAL_TIM_PWM_Stop(htim, channel);
}

bool PWM::setCompare(uint32_t compare) noexcept {
    if(getCounterPeriod() < compare){
        return false;
    } else {
        __HAL_TIM_SET_COMPARE(htim, channel, compare);
        return true;
    }
}

uint32_t PWM::getCounterPeriod() const noexcept {
	return htim->Init.Period;
}

#endif // CONFIG_DISABLE_MODULE_TIM
