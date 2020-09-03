#ifndef CONFIG_DISABLE_MODULE_TIM

#include "HAL_Extension_tim.hpp"

#ifndef CONFIG_DISABLE_EX_CALLBACK
std::map<TIM_HandleTypeDef *, std::function<void()>> __tim__period_elapsed_callback;
#endif // CONFIG_DISABLE_EX_CALLBACK

PWM::PWM(){}

PWM::PWM(TIM_HandleTypeDef &htim, uint32_t channel): htim(&htim), channel(channel){
}

void PWM::start(){
	HAL_TIM_PWM_Start(htim, channel);
}

void PWM::stop(){
	HAL_TIM_PWM_Stop(htim, channel);
}

bool PWM::setCompare(uint32_t compare){
	if(getCounterPeriod() < compare){
		return false;
	} else {
		__HAL_TIM_SET_COMPARE(htim, channel, compare);
		return true;
	}
}

uint32_t PWM::getCounterPeriod(){
	return htim->Init.Period;
}

Motor::Motor(){}

Motor::Motor(PWM positive, PWM negative): positive(positive), negative(negative){

}

Motor::Motor(TIM_HandleTypeDef &htimPos, uint32_t channelPos, TIM_HandleTypeDef &htimNeg, uint32_t channelNeg): positive(PWM(htimPos, channelPos)), negative(PWM(htimNeg, channelNeg)){

}

void Motor::start(){
	positive.start();
	negative.start();
}

void Motor::stop(){
	positive.stop();
	negative.stop();
}

bool Motor::setSpeed(bool forward, uint32_t compare){
	if(forward){
		return positive.setCompare(compare) && negative.setCompare(0);
	} else {
		return positive.setCompare(0) && negative.setCompare(compare);
	}
}

bool Motor::setSpeed(int64_t speed){
	bool back = speed < 0;
	if(UINT32_MAX < speed) return false;
	return setSpeed(!back, (uint32_t) (back? -speed : speed));
}

Encoder::Encoder(){}

Encoder::Encoder(TIM_HandleTypeDef &htim, uint32_t channel): htim(&htim), channel(channel){

}

void Encoder::start(){
	int16_t lastCount = count;
	if(!isStart){
		HAL_TIM_Encoder_Start(htim, channel);
	}
	__HAL_TIM_CLEAR_FLAG(htim, channel);
	__HAL_TIM_SET_COUNTER(htim , 0);
	isStart = true;
	update();
	count = lastCount;
}

void Encoder::stop(){
	update();
	if(isStart){
		HAL_TIM_Encoder_Stop(htim, channel);
	}
	__HAL_TIM_CLEAR_FLAG(htim, channel);
	__HAL_TIM_SET_COUNTER(htim , 0);
	isStart = false;
}

void Encoder::update(){
	if(!isStart) return;
	lastRawCount = rawCount;
	if (__HAL_TIM_GET_FLAG(htim, TIM_FLAG_UPDATE)) {
		rawCount = __HAL_TIM_GET_COUNTER(htim);
		if (rawCount > lastRawCount) {
			count += (rawCount - __HAL_TIM_GET_AUTORELOAD(htim)) - lastRawCount;
		} else {
			count += rawCount - (lastRawCount - __HAL_TIM_GET_AUTORELOAD(htim));
		}
		__HAL_TIM_CLEAR_FLAG(htim, TIM_FLAG_UPDATE);
	} else {
		rawCount = __HAL_TIM_GET_COUNTER(htim);
		count += rawCount - lastRawCount;
	}
}

int32_t Encoder::getCount(){
	return count;
}

void Encoder::resetCount(){
	update();
	count = 0;
}

#ifndef CONFIG_DISABLE_EX_CALLBACK
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
	__HAL_TIM_SET_COUNTER(htim , 0);
	HAL_TIM_Base_Start_IT(htim);
	return true;
}

void TimerInterrupt::stop(){
	HAL_TIM_Base_Stop_IT(htim);
}

void TimerInterrupt::setCallback(std::function<void()> function){
	__tim__period_elapsed_callback[htim] = function;
}

#ifdef CONFIG_TIM_USE_HALF_CALLBACK
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
#else  // CONFIG_TIM_USE_HALF_CALLBACK
void HAL_TIM_PeriodElapsedHalfCpltCallback(TIM_HandleTypeDef *htim){
#endif // CONFIG_TIM_USE_HALF_CALLBACK
    if(map_contains(__tim__period_elapsed_callback, htim)){
        __tim__period_elapsed_callback[htim]();
    }
}
#endif // CONFIG_DISABLE_EX_CALLBACK

#endif // CONFIG_DISABLE_MODULE_TIM
