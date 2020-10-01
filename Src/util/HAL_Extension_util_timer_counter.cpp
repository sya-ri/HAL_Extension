#include "util/HAL_Extension_util_timer_counter.hpp"

TimerCounter::TimerCounter() {

}

void TimerCounter::start() noexcept {
    startTime = HAL_GetTick();
}

void TimerCounter::stop() noexcept {
    stopTime = HAL_GetTick();
}

uint32_t TimerCounter::get() const noexcept {
    return stopTime - startTime;
}