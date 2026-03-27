#if __has_include("tim.h")

#include "tim/servo_motor.hpp"

#include <cmath>

namespace halex {
namespace {

constexpr uint32_t MicrosecondsPerSecond = 1000 * 1000;

bool isOnAPB2(const TIM_TypeDef *instance) noexcept {
#ifdef TIM1
    if(instance == TIM1) return true;
#endif
#ifdef TIM8
    if(instance == TIM8) return true;
#endif
#ifdef TIM9
    if(instance == TIM9) return true;
#endif
#ifdef TIM10
    if(instance == TIM10) return true;
#endif
#ifdef TIM11
    if(instance == TIM11) return true;
#endif
#ifdef TIM15
    if(instance == TIM15) return true;
#endif
#ifdef TIM16
    if(instance == TIM16) return true;
#endif
#ifdef TIM17
    if(instance == TIM17) return true;
#endif
#ifdef TIM20
    if(instance == TIM20) return true;
#endif
    return false;
}

uint32_t getTimerClock(TIM_HandleTypeDef *htim) noexcept {
    RCC_ClkInitTypeDef clockConfig{};
    uint32_t flashLatency = 0;
    HAL_RCC_GetClockConfig(&clockConfig, &flashLatency);

    const bool apb2 = isOnAPB2(htim->Instance);
    const uint32_t pclk = apb2 ? HAL_RCC_GetPCLK2Freq() : HAL_RCC_GetPCLK1Freq();
    const uint32_t divider = apb2 ? clockConfig.APB2CLKDivider : clockConfig.APB1CLKDivider;
    return divider == RCC_HCLK_DIV1 ? pclk : pclk * 2U;
}

float clamp(float value, float min, float max) noexcept {
    if(value < min) return min;
    if(max < value) return max;
    return value;
}

} // namespace

ServoMotor::ServoMotor(): ServoMotor(PWM()) {}

ServoMotor::ServoMotor(const PWM &pwm): pwm(pwm) {}

ServoMotor::ServoMotor(TIM_HandleTypeDef *htim, uint32_t channel): ServoMotor(PWM(htim, channel)) {}

ServoMotor::ServoMotor(TIM_HandleTypeDef &htim, uint32_t channel): ServoMotor(&htim, channel) {}

void ServoMotor::init(uint16_t frequency) noexcept {
    if(frequency == 0) return;

    const uint32_t counterPeriod = (uint32_t) std::lround((float) MicrosecondsPerSecond / frequency);
    if(counterPeriod == 0) return;

    TIM_HandleTypeDef *htim = getHandle();
    const uint32_t prescaler = (uint32_t) std::lround((float) getTimerClock(htim) / MicrosecondsPerSecond);
    if(prescaler == 0) return;

    htim->Init.Period = counterPeriod - 1U;
    htim->Init.Prescaler = prescaler - 1U;
    __HAL_TIM_SET_AUTORELOAD(htim, htim->Init.Period);
    __HAL_TIM_SET_PRESCALER(htim, htim->Init.Prescaler);

    if(pulseWidth > counterPeriod - 1U) {
        pulseWidth = (uint16_t) (counterPeriod - 1U);
    }
    setPulseWidth(pulseWidth);
}

void ServoMotor::start() const noexcept {
    pwm.start();
}

void ServoMotor::stop() const noexcept {
    pwm.stop();
}

void ServoMotor::setPulseWidthRange(float minAngle, float maxAngle, uint16_t minPulseWidth, uint16_t maxPulseWidth) noexcept {
    if(maxAngle <= minAngle || maxPulseWidth < minPulseWidth) return;
    if(pwm.getCounterPeriod() < maxPulseWidth) return;

    this->minAngle = minAngle;
    this->maxAngle = maxAngle;
    this->minPulseWidth = minPulseWidth;
    this->maxPulseWidth = maxPulseWidth;
    setAngle(angle);
}

void ServoMotor::setAngle(float angle) noexcept {
    const float clampedAngle = clamp(angle, minAngle, maxAngle);
    this->angle = clampedAngle;

    const float angleRange = maxAngle - minAngle;
    const float pulseRange = (float) (maxPulseWidth - minPulseWidth);
    const float ratio = (clampedAngle - minAngle) / angleRange;
    const uint16_t mappedPulseWidth = (uint16_t) std::lround(minPulseWidth + pulseRange * ratio);
    setPulseWidth(mappedPulseWidth);
}

void ServoMotor::setAngle(bool forward, float angle) noexcept {
    setAngle(forward ? angle : -angle);
}

void ServoMotor::setRelativeAngle(float relativeAngle) noexcept {
    setAngle(angle + relativeAngle);
}

void ServoMotor::setRelativeAngle(bool forward, float relativeAngle) noexcept {
    setRelativeAngle(forward ? relativeAngle : -relativeAngle);
}

void ServoMotor::setAngleWithTime(float angle, uint32_t timeOfDistance) noexcept {
    const float clampedAngle = clamp(angle, minAngle, maxAngle);
    if(this->angleOfFinal != clampedAngle || this->timeOfDistance != timeOfDistance) {
        angleOfFinal = clampedAngle;
        this->timeOfDistance = timeOfDistance;
        timeOfFinal = HAL_GetTick() + timeOfDistance;
        angleOfDistance = angleOfFinal - this->angle;
    }

    if(timeOfDistance == 0) {
        setAngle(angleOfFinal);
        return;
    }

    const uint32_t now = HAL_GetTick();
    if(timeOfFinal <= now) {
        setAngle(angleOfFinal);
        return;
    }

    const uint32_t remainingTime = timeOfFinal - now;
    setAngle(angleOfFinal - remainingTime * angleOfDistance / timeOfDistance);
}

void ServoMotor::setPulseWidth(uint16_t pulseWidth) noexcept {
    const uint32_t counterPeriod = pwm.getCounterPeriod();
    uint32_t allowedMaxPulseWidth = maxPulseWidth;
    if(allowedMaxPulseWidth > counterPeriod) {
        allowedMaxPulseWidth = counterPeriod;
    }

    uint32_t allowedMinPulseWidth = minPulseWidth;
    if(allowedMaxPulseWidth < allowedMinPulseWidth) {
        allowedMinPulseWidth = allowedMaxPulseWidth;
    }

    if(pulseWidth < allowedMinPulseWidth) {
        this->pulseWidth = (uint16_t) allowedMinPulseWidth;
    } else if(allowedMaxPulseWidth < pulseWidth) {
        this->pulseWidth = (uint16_t) allowedMaxPulseWidth;
    } else {
        this->pulseWidth = pulseWidth;
    }

    pwm.setCompare(this->pulseWidth);
}

} // namespace halex

#endif // __has_include
