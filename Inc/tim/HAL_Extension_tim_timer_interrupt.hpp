#ifndef HAL_EXTENSION_TIM_TIMER_INTERRUPT_HPP
#define HAL_EXTENSION_TIM_TIMER_INTERRUPT_HPP

#ifndef CONFIG_DISABLE_MODULE_TIM

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
    void start() noexcept;
    void start(uint16_t prescaler, uint16_t counterPeriod) noexcept;
    void stop() noexcept;
    void setCount(uint32_t count) noexcept;
    void resetCount() noexcept;
#ifndef CONFIG_DISABLE_EX_CALLBACK
    void setCallback(std::function<void()> function) noexcept;
#endif // CONFIG_DISABLE_EX_CALLBACK
};

} // namespace halex

#endif // CONFIG_DISABLE_MODULE_TIM

#endif // HAL_EXTENSION_TIM_TIMER_INTERRUPT_HPP
