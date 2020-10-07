#ifndef HAL_EXTENSION_UTIL_STOP_WATCH_HPP
#define HAL_EXTENSION_UTIL_STOP_WATCH_HPP

#include "main.h"

namespace halex {

class StopWatch {
private:
    uint32_t startTime = 0;
public:
    StopWatch();
    void start() noexcept;
    uint32_t get() const noexcept;
};

} // namespace halex

#endif // HAL_EXTENSION_UTIL_STOP_WATCH_HPP