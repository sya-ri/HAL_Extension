#ifndef CONFIG_DISABLE_MODULE_TIM

#ifndef CONFIG_DISABLE_EX_CALLBACK

#include "tim/HAL_Extension_tim_callback.hpp"
#include <map>
#include "HAL_Extension_util.hpp"

namespace {
    std::map<TIM_HandleTypeDef *, std::function<void()>> tim_period_elapsed_callback;
}

void setTIMPeriodElapsedCallback(TIM_HandleTypeDef *htim, std::function<void()> function) noexcept {
    tim_period_elapsed_callback[htim] = function;
}

#ifdef CONFIG_TIM_USE_HALF_CALLBACK
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
#else  // CONFIG_TIM_USE_HALF_CALLBACK
void HAL_TIM_PeriodElapsedHalfCpltCallback(TIM_HandleTypeDef *htim){
#endif // CONFIG_TIM_USE_HALF_CALLBACK
    if(map_contains(tim_period_elapsed_callback, htim)){
        tim_period_elapsed_callback[htim]();
    }
}

#endif // CONFIG_DISABLE_EX_CALLBACK

#endif // CONFIG_DISABLE_MODULE_TIM
