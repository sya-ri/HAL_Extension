#ifndef CONFIG_DISABLE_MODULE_TIM

#include "tim/timer_interrupt.hpp"
#include "tim/callback.hpp"

namespace halex {

TimerInterrupt::TimerInterrupt() {}

TimerInterrupt::TimerInterrupt(TIM_HandleTypeDef *htim): htim(htim) {

}

TimerInterrupt::TimerInterrupt(TIM_HandleTypeDef &htim): TimerInterrupt(&htim) {

}

void TimerInterrupt::start() noexcept {
    resetCount();
    __HAL_TIM_CLEAR_FLAG(htim, TIM_FLAG_UPDATE);
    HAL_TIM_Base_Start_IT(htim);
}

void TimerInterrupt::start(uint16_t prescaler, uint16_t counterPeriod) noexcept {
    stop();
    HAL_TIM_Base_DeInit(htim);
    htim->Init.Prescaler = prescaler;
    htim->Init.Period = counterPeriod;
    HAL_TIM_Base_Init(htim);
    start();
}

void TimerInterrupt::stop() noexcept {
    HAL_TIM_Base_Stop_IT(htim);
}

void TimerInterrupt::setCount(uint32_t count) noexcept {
    __HAL_TIM_SET_COUNTER(htim , count);
}

void TimerInterrupt::resetCount() noexcept {
    setCount(0);
}

void TimerInterrupt::setCallback(std::function<void()> function) noexcept {
    setTIMPeriodElapsedCallback(htim, function);
}

} // namespace halex

#endif // CONFIG_DISABLE_MODULE_TIM
