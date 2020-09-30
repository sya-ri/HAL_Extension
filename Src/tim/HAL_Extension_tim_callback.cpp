#ifndef CONFIG_DISABLE_MODULE_TIM

#ifndef CONFIG_DISABLE_EX_CALLBACK

#include "tim/HAL_Extension_tim_callback.hpp"
#include <map>
#include "HAL_Extension_util.hpp"

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

} // namespace halex

#ifdef CONFIG_TIM_USE_HALF_CALLBACK
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
#else  // CONFIG_TIM_USE_HALF_CALLBACK
void HAL_TIM_PeriodElapsedHalfCpltCallback(TIM_HandleTypeDef *htim) {
#endif // CONFIG_TIM_USE_HALF_CALLBACK
    if(halex::map_contains(halex::tim_period_elapsed_callback, htim)) {
    	halex::tim_period_elapsed_callback[htim]();
    }
}

#endif // CONFIG_DISABLE_EX_CALLBACK

#endif // CONFIG_DISABLE_MODULE_TIM
