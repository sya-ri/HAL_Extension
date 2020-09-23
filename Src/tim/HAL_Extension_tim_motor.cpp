#ifndef CONFIG_DISABLE_MODULE_TIM

#include "tim/HAL_Extension_tim_motor.hpp"

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

#endif // CONFIG_DISABLE_MODULE_TIM
