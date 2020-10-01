#ifndef CONFIG_DISABLE_MODULE_ADC

#include "adc/HAL_Extension_adc_dma.hpp"
#include "adc/HAL_Extension_adc_callback.hpp"
#include "util/HAL_Extension_util_function.hpp"

namespace halex {

ADC_DMA::ADC_DMA() {}

ADC_DMA::ADC_DMA(ADC_HandleTypeDef *hadc, uint32_t adcBufLength): hadc(hadc), adcBufLength(adcBufLength) {
    adcBuf = new uint32_t[adcBufLength];
}

ADC_DMA::ADC_DMA(ADC_HandleTypeDef &hadc, uint32_t adcBufLength): ADC_DMA(&hadc, adcBufLength) {}

ADC_DMA::~ADC_DMA() {
    delete[] adcBuf;
}

void ADC_DMA::start() noexcept {
    HAL_ADC_Start_DMA(hadc, adcBuf, adcBufLength);
}

void ADC_DMA::stop() noexcept {
    HAL_ADC_Stop_DMA(hadc);
}

uint8_t ADC_DMA::get8(uint8_t index) const noexcept {
    return (uint8_t)(get(index) >> 4);
}

uint32_t ADC_DMA::get(uint8_t index) const noexcept {
    return adcBuf[index];
}

#ifndef CONFIG_DISABLE_EX_CALLBACK
void ADC_DMA::setCallback(std::function<void()> function) noexcept {
    setADCCallback(hadc, function);
}
#endif // CONFIG_DISABLE_EX_CALLBACK

} // namespace halex

#endif // CONFIG_DISABLE_MODULE_ADC
