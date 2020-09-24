#ifndef CONFIG_DISABLE_MODULE_ADC

#ifndef CONFIG_DISABLE_EX_CALLBACK

#include "adc/HAL_Extension_adc_callback.hpp"
#include <map>
#include "HAL_Extension_util.hpp"

namespace {
    std::map<ADC_HandleTypeDef *, std::function<void()>> adc_callback;
}

void setADCCallback(ADC_HandleTypeDef *hadc, std::function<void()> function){
    adc_callback[hadc] = function;
}

#ifdef CONFIG_ADC_USE_HALF_CALLBACK
void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef* hadc){
#else  // CONFIG_ADC_USE_HALF_CALLBACK
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc){
#endif // CONFIG_ADC_USE_HALF_CALLBACK
    if(map_contains(adc_callback, hadc)){
        adc_callback[hadc]();
    }
}

#endif // CONFIG_DISABLE_EX_CALLBACK

#endif // CONFIG_DISABLE_MODULE_ADC
