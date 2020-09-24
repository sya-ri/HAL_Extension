#ifndef HAL_EXTENSION_TIM_ENCODER_HPP
#define HAL_EXTENSION_TIM_ENCODER_HPP

#ifndef CONFIG_DISABLE_MODULE_TIM

#include "tim.h"

class Encoder {
private:
    TIM_HandleTypeDef *htim;
    uint32_t channel;
    bool isStart = false;
    uint16_t lastRawCount = 0;
    uint16_t rawCount = 0;
    int32_t count = 0;
public:
    Encoder();
    Encoder(TIM_HandleTypeDef &htim, uint32_t channel = TIM_CHANNEL_ALL);
    void start() noexcept;
    void stop() noexcept;
    void update() noexcept;
    int32_t getCount() const noexcept;
    void resetCount() noexcept;
};

#endif // CONFIG_DISABLE_MODULE_TIM

#endif // HAL_EXTENSION_TIM_ENCODER_HPP
