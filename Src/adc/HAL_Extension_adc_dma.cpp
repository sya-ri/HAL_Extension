#ifndef CONFIG_DISABLE_MODULE_ADC

#include "adc/HAL_Extension_adc_dma.hpp"
#include "HAL_Extension_util.hpp"

#ifndef CONFIG_DISABLE_EX_CALLBACK
namespace {
    std::map<ADC_HandleTypeDef *, std::function<void()>> __adc_callback;
}
#endif // CONFIG_DISABLE_EX_CALLBACK

ADC_DMA::ADC_DMA(){}

ADC_DMA::ADC_DMA(ADC_HandleTypeDef &hadc, uint32_t adcBufLength): hadc(&hadc), adcBufLength(adcBufLength){
    adcBuf = new uint32_t[adcBufLength];
}

ADC_DMA::~ADC_DMA(){
    delete[] adcBuf;
}

void ADC_DMA::start(){
    HAL_ADC_Start_DMA(hadc, adcBuf, adcBufLength);
}

void ADC_DMA::stop(){
    HAL_ADC_Stop_DMA(hadc);
}

uint8_t ADC_DMA::get8(uint8_t index) {
    return (uint8_t)(get(index) >> 4);
}

uint32_t ADC_DMA::get(uint8_t index) {
    return adcBuf[index];
}

#ifndef CONFIG_DISABLE_EX_CALLBACK
void ADC_DMA::setCallback(std::function<void()> function){
    __adc_callback[hadc] = function;
}

#ifdef CONFIG_ADC_USE_HALF_CALLBACK
void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef* hadc){
#else  // CONFIG_ADC_USE_HALF_CALLBACK
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc){
#endif // CONFIG_ADC_USE_HALF_CALLBACK
    if(map_contains(__adc_callback, hadc)){
        __adc_callback[hadc]();
    }
}
#endif // CONFIG_DISABLE_EX_CALLBACK

#endif // CONFIG_DISABLE_MODULE_ADC
