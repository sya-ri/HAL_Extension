#ifndef HAL_EXTENSION_UTIL_TIMER_COUNTER_HPP
#define HAL_EXTENSION_UTIL_TIMER_COUNTER_HPP

#include "main.h"

namespace halex {

class TimerCounter {
private:
    uint32_t startTime = 0;
public:
    TimerCounter();
    void start() noexcept;
    uint32_t get() const noexcept;
};

} // namespace halex

#endif // HAL_EXTENSION_UTIL_TIMER_COUNTER_HPP