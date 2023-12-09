#ifndef HAL_EXTENSION_TIM_MOTOR_HPP
#define HAL_EXTENSION_TIM_MOTOR_HPP

#if __has_include("tim.h")

#include "pwm.hpp"

namespace halex {

class Motor {
private:
    const PWM positive;
    const PWM negative;
public:
    Motor();
    Motor(const PWM &positive, const PWM &negative);
    Motor(TIM_HandleTypeDef *htimPos, uint32_t channelPos, TIM_HandleTypeDef *htimNeg, uint32_t channelNeg);
    Motor(TIM_HandleTypeDef &htimPos, uint32_t channelPos, TIM_HandleTypeDef &htimNeg, uint32_t channelNeg);
    void start() noexcept;
    void stop() noexcept;
    void setCompare(uint32_t comparePos, uint32_t compareNeg) noexcept;
    void setSpeed(bool forward, uint32_t compare) noexcept;
    void setSpeed(bool forward, uint16_t numerator, uint16_t denominator) noexcept;
    void setSpeed(int64_t speed) noexcept;
    void setSpeed(int16_t numerator, int16_t denominator) noexcept;
};

} // namespace halex

#endif // __has_include

#endif // HAL_EXTENSION_TIM_MOTOR_HPP
