#ifndef HAL_EXTENSION_TIM_MOTOR_HPP
#define HAL_EXTENSION_TIM_MOTOR_HPP

#ifndef CONFIG_DISABLE_MODULE_TIM

#include "HAL_Extension_tim_pwm.hpp"

namespace halex {

class Motor {
private:
    const PWM &positive;
    const PWM &negative;
public:
    Motor();
    Motor(const PWM &positive, const PWM &negative);
    Motor(TIM_HandleTypeDef *htimPos, uint32_t channelPos, TIM_HandleTypeDef *htimNeg, uint32_t channelNeg);
    Motor(TIM_HandleTypeDef &htimPos, uint32_t channelPos, TIM_HandleTypeDef &htimNeg, uint32_t channelNeg);
    void start() noexcept;
    void stop() noexcept ;
    void setSpeed(bool forward, uint32_t compare) noexcept;
    void setSpeed(bool forward, uint16_t numerator, uint16_t denominator) noexcept;
    void setSpeed(int64_t speed) noexcept;
    void setSpeed(int16_t numerator, int16_t denominator) noexcept;
};

} // namespace halex

#endif // CONFIG_DISABLE_MODULE_TIM

#endif // HAL_EXTENSION_TIM_MOTOR_HPP
