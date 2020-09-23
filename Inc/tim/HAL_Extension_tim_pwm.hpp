#ifndef HAL_EXTENSION_TIM_PWM_HPP
#define HAL_EXTENSION_TIM_PWM_HPP

#ifndef CONFIG_DISABLE_MODULE_TIM

#include "tim.h"

class PWM {
private:
    TIM_HandleTypeDef *htim;
    uint32_t channel;
public:
    PWM();
    PWM(TIM_HandleTypeDef &htim, uint32_t channel);
    void start();
    void stop();
    bool setCompare(uint32_t compare);
    uint32_t getCounterPeriod();
};

#endif // CONFIG_DISABLE_MODULE_TIM

#endif // HAL_EXTENSION_TIM_PWM_HPP
