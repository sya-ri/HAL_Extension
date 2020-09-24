#ifndef HAL_EXTENSION_ADC_DMA_HPP
#define HAL_EXTENSION_ADC_DMA_HPP

#ifndef CONFIG_DISABLE_MODULE_ADC

#include "adc.h"
#include <functional>

class ADC_DMA {
private:
    ADC_HandleTypeDef *hadc;
    uint32_t *adcBuf;
    uint32_t adcBufLength;
public:
    ADC_DMA();
    ADC_DMA(ADC_HandleTypeDef &hadc, uint32_t adcBufLength);
    ~ADC_DMA();
    void start();
    void stop();
    uint8_t get8(uint8_t index);
    uint32_t get(uint8_t index);

#ifndef CONFIG_DISABLE_EX_CALLBACK
    void setCallback(std::function<void()> function);
#endif // CONFIG_DISABLE_EX_CALLBACK
};

#endif // CONFIG_DISABLE_MODULE_ADC

#endif // HAL_EXTENSION_ADC_DMA_HPP
