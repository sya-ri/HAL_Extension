#ifndef HAL_EXTENSION_TIM_SERVO_MOTOR_HPP
#define HAL_EXTENSION_TIM_SERVO_MOTOR_HPP

#if __has_include("tim.h")

#include "pwm.hpp"

namespace halex {

class ServoMotor {
private:
    PWM pwm;
    uint16_t minPulseWidth = 1000;
    float minAngle = 0.0f;
    uint16_t maxPulseWidth = 2000;
    float maxAngle = 180.0f;
    float angle = 0.0f;
    uint16_t pulseWidth = 1000;
    float angleOfFinal = 0.0f;
    float angleOfDistance = 0.0f;
    uint32_t timeOfFinal = 0;
    uint32_t timeOfDistance = 0;
public:
    ServoMotor();
    ServoMotor(const PWM &pwm);
    ServoMotor(TIM_HandleTypeDef *htim, uint32_t channel);
    ServoMotor(TIM_HandleTypeDef &htim, uint32_t channel);
    TIM_HandleTypeDef* getHandle() const noexcept { return pwm.getHandle(); }
    bool equals(TIM_HandleTypeDef *htim) const noexcept { return pwm.equals(htim); }
    bool equals(TIM_HandleTypeDef &htim) const noexcept { return equals(&htim); }
    void init(uint16_t frequency) noexcept;
    void start() const noexcept;
    void stop() const noexcept;
    void setPulseWidthRange(float minAngle, float maxAngle, uint16_t minPulseWidth, uint16_t maxPulseWidth) noexcept;
    void setAngle(float angle) noexcept;
    void setAngle(bool forward, float angle) noexcept;
    void setRelativeAngle(float relativeAngle) noexcept;
    void setRelativeAngle(bool forward, float relativeAngle) noexcept;
    void setAngleWithTime(float angle, uint32_t timeOfDistance) noexcept;
    void setPulseWidth(uint16_t pulseWidth) noexcept;
    float getAngle() const noexcept { return angle; }
    uint16_t getPulseWidth() const noexcept { return pulseWidth; }
};

} // namespace halex

#endif // __has_include

#endif // HAL_EXTENSION_TIM_SERVO_MOTOR_HPP
