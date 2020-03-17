#ifndef HAL_EXTENSION_ADC_HPP
#define HAL_EXTENSION_ADC_HPP
#ifdef __adc_H

#include <map>
#include <functional>

namespace {
   std::map<ADC_HandleTypeDef *, std::function<void()>> __adc_callback;
}

class ADC_DMA {
private:
    ADC_HandleTypeDef *hadc;
    uint32_t *adcBuf;
    uint8_t numberOfConversions;
public:
    ADC_DMA(ADC_HandleTypeDef &hadc, uint8_t numberOfConversions): hadc(&hadc), numberOfConversions(numberOfConversions){
        adcBuf = new uint32_t[numberOfConversions];
    }

    ~ADC_DMA(){
        delete[] adcBuf;
    }

    void start(){
    	if(hadc.Init.ContinuousConvMode != ENABLE || hadc.Init.DMAContinuousRequests != ENABLE){
    		HAL_ADC_DeInit(&hadc);
    		hadc.Init.ContinuousConvMode = ENABLE;
    		hadc.Init.DMAContinuousRequests = ENABLE;
    		HAL_ADC_Init(&hadc);
    	}
        HAL_ADC_Start_DMA(hadc, adcBuf, numberOfConversions);
    }

    void stop(){
        HAL_ADC_Stop_DMA(hadc);
    }

    uint32_t get(uint8_t index) {
        if (index < numberOfConversions) {
            return adcBuf[index];
        }
        throw std::out_of_range("Over NumberOfConversions");
    }

    void setCallback(std::function<void()> function){
        __adc_callback[hadc] = function;
    }
};

#ifdef CONFIG_ADC_USE_HALF_CALLBACK
void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef* hadc){
#else  // CONFIG_ADC_USE_HALF_CALLBACK
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc){
#endif // CONFIG_ADC_USE_HALF_CALLBACK
    if(__map_contains(__adc_callback, hadc)){
        __adc_callback[hadc]();
    }
}

#endif // __adc_H
#endif
