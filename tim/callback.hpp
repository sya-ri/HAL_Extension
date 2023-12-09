#ifndef HAL_EXTENSION_TIM_HPP
#define HAL_EXTENSION_TIM_HPP

#if __has_include("tim.h")

#include <functional>
#include "tim.h"

namespace halex {

void setTIMPeriodElapsedCallback(TIM_HandleTypeDef *htim, std::function<void()> function) noexcept;
void setTIMPeriodElapsedCallback(TIM_HandleTypeDef &htim, std::function<void()> function) noexcept;
void runTIMPeriodElapsedCallback(TIM_HandleTypeDef *htim) noexcept;
void runTIMPeriodElapsedCallback(TIM_HandleTypeDef &htim) noexcept;

} // namespace halex

#endif // __has_include

#endif // HAL_EXTENSION_TIM_HPP
