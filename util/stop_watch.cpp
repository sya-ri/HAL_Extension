#include "util/stop_watch.hpp"

namespace halex {

StopWatch::StopWatch() {

}

void StopWatch::start() noexcept {
    startTime = HAL_GetTick();
}

uint32_t StopWatch::get() const noexcept {
    return HAL_GetTick() - startTime;
}

} // namespace halex