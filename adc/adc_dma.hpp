#ifndef HAL_EXTENSION_ADC_DMA_HPP
#define HAL_EXTENSION_ADC_DMA_HPP

#if __has_include("adc.h")

#include "adc.h"
#include <functional>

namespace halex {

class ADC_DMA {
private:
    ADC_HandleTypeDef *hadc;
    uint32_t *adcBuf;
    uint32_t adcBufLength;
public:
    ADC_DMA();
    ADC_DMA(ADC_HandleTypeDef *hadc, uint32_t adcBufLength);
    ADC_DMA(ADC_HandleTypeDef &hadc, uint32_t adcBufLength);
    ~ADC_DMA();
    void start() noexcept;
    void stop() noexcept;
    uint32_t get(uint8_t index) const noexcept;
    uint8_t get8(uint8_t index) const noexcept;
    void setCallback(std::function<void()> function) noexcept;
};

} // namespace halex

#endif // __has_include

#endif // HAL_EXTENSION_ADC_DMA_HPP
