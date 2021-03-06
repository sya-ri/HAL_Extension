#ifndef HAL_EXTENSION_TIM_HPP
#define HAL_EXTENSION_TIM_HPP

#ifndef CONFIG_DISABLE_MODULE_TIM

#ifndef CONFIG_DISABLE_EX_CALLBACK

#include <functional>
#include "tim.h"

namespace halex {

void setTIMPeriodElapsedCallback(TIM_HandleTypeDef *htim, std::function<void()> function) noexcept;
void setTIMPeriodElapsedCallback(TIM_HandleTypeDef &htim, std::function<void()> function) noexcept;

} // namespace halex

#endif // CONFIG_DISABLE_EX_CALLBACK

#endif // CONFIG_DISABLE_MODULE_TIM

#endif // HAL_EXTENSION_TIM_HPP
