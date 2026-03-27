#ifndef HAL_EXTENSION_TIM_TIMER_INTERRUPT_HPP
#define HAL_EXTENSION_TIM_TIMER_INTERRUPT_HPP

#if __has_include("tim.h")

#include "tim.h"
#include <functional>

namespace halex {

class TimerInterrupt {
private:
    TIM_HandleTypeDef *htim;
public:
    TimerInterrupt();
    TimerInterrupt(TIM_HandleTypeDef *htim);
    TimerInterrupt(TIM_HandleTypeDef &htim);
    TIM_HandleTypeDef* getHandle() const noexcept { return htim; }
    bool equals(TIM_HandleTypeDef *htim) const noexcept { return this->htim == htim; }
    bool equals(TIM_HandleTypeDef &htim) const noexcept { return equals(&htim); }
    void start() noexcept;
    void start(uint16_t prescaler, uint16_t counterPeriod) noexcept;
    void stop() noexcept;
    void setCount(uint32_t count) noexcept;
    void resetCount() noexcept;
    void setCallback(std::function<void()> function) noexcept;
};

} // namespace halex

#endif // __has_include

#endif // HAL_EXTENSION_TIM_TIMER_INTERRUPT_HPP
