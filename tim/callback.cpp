#ifndef CONFIG_DISABLE_MODULE_TIM

#include "tim/callback.hpp"
#include <map>
#include "util/function.hpp"

namespace halex {

namespace {
    std::map<TIM_HandleTypeDef *, std::function<void()>> tim_period_elapsed_callback;
}

void setTIMPeriodElapsedCallback(TIM_HandleTypeDef *htim, std::function<void()> function) noexcept {
    tim_period_elapsed_callback[htim] = function;
}

void setTIMPeriodElapsedCallback(TIM_HandleTypeDef &htim, std::function<void()> function) noexcept {
    setTIMPeriodElapsedCallback(&htim, function);
}

void runTIMPeriodElapsedCallback(TIM_HandleTypeDef *htim) noexcept {
    if(halex::map_contains(halex::tim_period_elapsed_callback, htim)) {
        halex::tim_period_elapsed_callback[htim]();
    }
}

void runTIMPeriodElapsedCallback(TIM_HandleTypeDef &htim) noexcept {
    runTIMPeriodElapsedCallback(&htim);
}

} // namespace halex

#endif // CONFIG_DISABLE_MODULE_TIM
