#ifndef HAL_EXTENSION_TIM_TIMER_INTERRUPT_HPP
#define HAL_EXTENSION_TIM_TIMER_INTERRUPT_HPP

#ifndef CONFIG_DISABLE_MODULE_TIM

#include "tim.h"
#include <functional>

class TimerInterrupt {
private:
    TIM_HandleTypeDef *htim;
public:
    TimerInterrupt();
    TimerInterrupt(TIM_HandleTypeDef &htim);
    bool start(uint32_t prescaler, uint32_t counterPeriod) noexcept;
    bool start() noexcept;
    void stop() noexcept;
    void setCount(uint32_t count) noexcept;
    void resetCount() noexcept;
#ifndef CONFIG_DISABLE_EX_CALLBACK
    void setCallback(std::function<void()> function) noexcept;
#endif // CONFIG_DISABLE_EX_CALLBACK
};

#endif // CONFIG_DISABLE_MODULE_TIM

#endif // HAL_EXTENSION_TIM_TIMER_INTERRUPT_HPP
