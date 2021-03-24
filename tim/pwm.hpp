#ifndef HAL_EXTENSION_TIM_PWM_HPP
#define HAL_EXTENSION_TIM_PWM_HPP

#ifndef CONFIG_DISABLE_MODULE_TIM

#include "tim.h"

namespace halex {

class PWM {
private:
    TIM_HandleTypeDef *htim;
    uint32_t channel;
public:
    PWM();
    PWM(TIM_HandleTypeDef *htim, uint32_t channel);
    PWM(TIM_HandleTypeDef &htim, uint32_t channel);
    void start() const noexcept;
    void stop() const noexcept;
    void setCompare(uint32_t compare) const noexcept;
    void setCompare(uint16_t numerator, uint16_t denominator) const noexcept;
    uint32_t getCounterPeriod() const noexcept;
};

} // namespace halex

#endif // CONFIG_DISABLE_MODULE_TIM

#endif // HAL_EXTENSION_TIM_PWM_HPP
