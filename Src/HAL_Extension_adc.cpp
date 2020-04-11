#include "HAL_Extension_adc.hpp"
#include "HAL_Extension_util.hpp"

namespace {
   std::map<ADC_HandleTypeDef *, std::function<void()>> __adc_callback;
}

ADC_DMA::ADC_DMA(){}

ADC_DMA::ADC_DMA(ADC_HandleTypeDef &hadc, uint8_t numberOfConversions): hadc(&hadc), numberOfConversions(numberOfConversions){
	adcBuf = new uint32_t[numberOfConversions];
}

ADC_DMA::~ADC_DMA(){
	delete[] adcBuf;
}

void ADC_DMA::start(){
	if(hadc->Init.ContinuousConvMode != ENABLE || hadc->Init.DMAContinuousRequests != ENABLE){
		HAL_ADC_DeInit(hadc);
		hadc->Init.ContinuousConvMode = ENABLE;
		hadc->Init.DMAContinuousRequests = ENABLE;
		HAL_ADC_Init(hadc);
	}
	HAL_ADC_Start_DMA(hadc, adcBuf, numberOfConversions);
}

void ADC_DMA::stop(){
	HAL_ADC_Stop_DMA(hadc);
}

uint8_t ADC_DMA::get8(uint8_t index) {
	return (uint8_t)(get(index) >> 4);
}

uint16_t ADC_DMA::get(uint8_t index) {
	if (index < numberOfConversions) {
		return (uint16_t) adcBuf[index];
	}
	return UINT16_MAX;
}

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
