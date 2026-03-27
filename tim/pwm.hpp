#ifndef HAL_EXTENSION_TIM_PWM_HPP
#define HAL_EXTENSION_TIM_PWM_HPP

#if __has_include("tim.h")

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
    TIM_HandleTypeDef* getHandle() const noexcept { return htim; }
    bool equals(TIM_HandleTypeDef *htim) const noexcept { return this->htim == htim; }
    bool equals(TIM_HandleTypeDef &htim) const noexcept { return equals(&htim); }
    void start() const noexcept;
    void stop() const noexcept;
    void setCompare(uint32_t compare) const noexcept;
    void setCompare(uint16_t numerator, uint16_t denominator) const noexcept;
    uint32_t getCounterPeriod() const noexcept;
};

} // namespace halex

#endif // __has_include

#endif // HAL_EXTENSION_TIM_PWM_HPP
