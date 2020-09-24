#ifndef HAL_EXTENSION_ADC_CALLBACK_HPP
#define HAL_EXTENSION_ADC_CALLBACK_HPP

#ifndef CONFIG_DISABLE_MODULE_ADC

#ifndef CONFIG_DISABLE_EX_CALLBACK

#include <functional>
#include "adc.h"

void setADCCallback(ADC_HandleTypeDef *hadc, std::function<void()> function);

#endif // CONFIG_DISABLE_EX_CALLBACK

#endif // CONFIG_DISABLE_MODULE_ADC

#endif // HAL_EXTENSION_ADC_CALLBACK_HPP
