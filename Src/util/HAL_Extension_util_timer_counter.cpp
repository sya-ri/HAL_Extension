#include "util/HAL_Extension_util_timer_counter.hpp"

namespace halex {

TimerCounter::TimerCounter() {

}

void TimerCounter::start() noexcept {
    startTime = HAL_GetTick();
}

uint32_t TimerCounter::get() const noexcept {
    return HAL_GetTick() - startTime;
}

} // namespace halex