#ifndef HAL_EXTENSION_ADC_CALLBACK_HPP
#define HAL_EXTENSION_ADC_CALLBACK_HPP

#ifndef CONFIG_DISABLE_MODULE_ADC

#ifndef CONFIG_DISABLE_EX_CALLBACK

#include <functional>
#include "adc.h"

namespace halex {

void setADCCallback(ADC_HandleTypeDef *hadc, std::function<void()> function) noexcept;
void setADCCallback(ADC_HandleTypeDef &hadc, std::function<void()> function) noexcept;

} // namespace halex

#endif // CONFIG_DISABLE_EX_CALLBACK

#endif // CONFIG_DISABLE_MODULE_ADC

#endif // HAL_EXTENSION_ADC_CALLBACK_HPP
