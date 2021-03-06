#ifndef CONFIG_DISABLE_MODULE_ADC

#ifndef CONFIG_DISABLE_EX_CALLBACK

#include "adc/callback.hpp"
#include <map>
#include "util/function.hpp"

namespace halex {

namespace {
    std::map<ADC_HandleTypeDef *, std::function<void()>> adc_callback;
}

void setADCCallback(ADC_HandleTypeDef *hadc, std::function<void()> function) noexcept {
    adc_callback[hadc] = function;
}

void setADCCallback(ADC_HandleTypeDef &hadc, std::function<void()> function) noexcept {
    setADCCallback(&hadc, function);
}

} // namespace halex

#ifdef CONFIG_USE_HALF_CALLBACK_ADC
void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef* hadc) {
#else  // CONFIG_USE_HALF_CALLBACK_ADC
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc) {
#endif // CONFIG_USE_HALF_CALLBACK_ADC
    if(halex::map_contains(halex::adc_callback, hadc)) {
        halex::adc_callback[hadc]();
    }
}

#endif // CONFIG_DISABLE_EX_CALLBACK

#endif // CONFIG_DISABLE_MODULE_ADC
