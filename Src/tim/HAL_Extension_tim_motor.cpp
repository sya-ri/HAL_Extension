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

void Motor::setSpeed(bool forward, uint32_t compare){
	if(forward){
		positive.setCompare(compare);
		negative.setCompare(0);
	} else {
		positive.setCompare(0);
		negative.setCompare(compare);
	}
}

void Motor::setSpeed(bool forward, uint16_t numerator, uint16_t denominator){
	if(forward){
		positive.setCompare(numerator, denominator);
		negative.setCompare(0);
	} else {
		positive.setCompare(0);
		negative.setCompare(numerator, denominator);
	}
}

void Motor::setSpeed(int64_t speed){
	bool back = speed < 0;
	setSpeed(!back, (uint32_t) (back? -speed : speed));
}

void Motor::setSpeed(int16_t numerator, int16_t denominator){
	bool forward = true;
	uint16_t abs_numerator;
	if(numerator < 0){
		abs_numerator = (uint16_t) -numerator;
		forward = !forward;
	} else {
		abs_numerator = (uint16_t) numerator;
	}
	uint16_t abs_denominator;
	if(denominator < 0){
		abs_denominator = (uint16_t) -denominator;
		forward = !forward;
	} else {
		abs_denominator = (uint16_t) denominator;
	}
	setSpeed(forward, abs_numerator, abs_denominator);
}

#endif // CONFIG_DISABLE_MODULE_TIM
