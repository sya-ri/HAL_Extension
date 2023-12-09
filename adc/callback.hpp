#ifndef HAL_EXTENSION_ADC_CALLBACK_HPP
#define HAL_EXTENSION_ADC_CALLBACK_HPP

#if __has_include("adc.h")

#include <functional>
#include "adc.h"

namespace halex {

void setADCCallback(ADC_HandleTypeDef *hadc, std::function<void()> function) noexcept;
void setADCCallback(ADC_HandleTypeDef &hadc, std::function<void()> function) noexcept;
void runADCCallback(ADC_HandleTypeDef *hadc) noexcept;
void runADCCallback(ADC_HandleTypeDef &hadc) noexcept;

} // namespace halex

#endif // __has_include

#endif // HAL_EXTENSION_ADC_CALLBACK_HPP
