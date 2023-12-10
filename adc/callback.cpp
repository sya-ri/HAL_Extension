#ifndef CONFIG_DISABLE_MODULE_ADC

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

void runADCCallback(ADC_HandleTypeDef *hadc) noexcept {
    if(halex::map_contains(halex::adc_callback, hadc)) {
        halex::adc_callback[hadc]();
    }
}

void runADCCallback(ADC_HandleTypeDef &hadc) noexcept {
    runADCCallback(&hadc);
}

} // namespace halex

#endif // CONFIG_DISABLE_MODULE_ADC
