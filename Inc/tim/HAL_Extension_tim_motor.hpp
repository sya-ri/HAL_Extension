#ifndef HAL_EXTENSION_TIM_MOTOR_HPP
#define HAL_EXTENSION_TIM_MOTOR_HPP

#ifndef CONFIG_DISABLE_MODULE_TIM

#include "HAL_Extension_tim_pwm.hpp"

class Motor {
private:
    PWM positive;
    PWM negative;
public:
    Motor();
    Motor(PWM positive, PWM negative);
    Motor(TIM_HandleTypeDef &htimPos, uint32_t channelPos, TIM_HandleTypeDef &htimNeg, uint32_t channelNeg);
    void start();
    void stop();
    bool setSpeed(bool forward, uint32_t compare);
    bool setSpeed(int64_t speed);
};

#endif // CONFIG_DISABLE_MODULE_TIM

#endif // HAL_EXTENSION_TIM_MOTOR_HPP
