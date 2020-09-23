#ifndef CONFIG_DISABLE_MODULE_TIM

#include "tim/HAL_Extension_tim_timer_interrupt.hpp"
#include "tim/HAL_Extension_tim_callback.hpp"

TimerInterrupt::TimerInterrupt(){}

TimerInterrupt::TimerInterrupt(TIM_HandleTypeDef &htim): htim(&htim){

}

bool TimerInterrupt::start(uint32_t prescaler, uint32_t counterPeriod){
	if(0xFFFF < prescaler || 0xFFFF < counterPeriod){ // 0xFFFF == 65535
		return false;
	}
	stop();
	HAL_TIM_Base_DeInit(htim);
	htim->Init.Prescaler = prescaler;
	htim->Init.Period = counterPeriod;
	HAL_TIM_Base_Init(htim);
	return start();
}

bool TimerInterrupt::start(){
	resetCount();
	HAL_TIM_Base_Start_IT(htim);
	return true;
}

void TimerInterrupt::stop(){
	HAL_TIM_Base_Stop_IT(htim);
}

void TimerInterrupt::setCount(uint32_t count){
	__HAL_TIM_SET_COUNTER(htim , count);
}

void TimerInterrupt::resetCount(){
	setCount(0);
}

#ifndef CONFIG_DISABLE_EX_CALLBACK
void TimerInterrupt::setCallback(std::function<void()> function){
    setTIMPeriodElapsedCallback(htim, function);
}
#endif // CONFIG_DISABLE_EX_CALLBACK

#endif // CONFIG_DISABLE_MODULE_TIM
