#ifndef HAL_EXTENSION_ADC_HPP
#define HAL_EXTENSION_ADC_HPP

#include "adc.h"
#include <map>
#include <functional>

class ADC_DMA {
private:
    ADC_HandleTypeDef *hadc;
    uint32_t *adcBuf;
    uint8_t numberOfConversions;
public:
    ADC_DMA();
    ADC_DMA(ADC_HandleTypeDef &hadc, uint8_t numberOfConversions);
    ~ADC_DMA();
    void start();
    void stop();
    uint8_t get8(uint8_t index);
    uint16_t get(uint8_t index);
    void setCallback(std::function<void()> function);
};

#endif
