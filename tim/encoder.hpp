#ifndef HAL_EXTENSION_TIM_ENCODER_HPP
#define HAL_EXTENSION_TIM_ENCODER_HPP

#ifndef CONFIG_DISABLE_MODULE_TIM

#include "tim.h"

namespace halex {

class Encoder {
private:
    TIM_HandleTypeDef *htim;
    bool isStart = false;
    uint16_t lastRawCount = 0;
    uint16_t rawCount = 0;
    int32_t count = 0;
public:
    Encoder();
    Encoder(TIM_HandleTypeDef *htim);
    Encoder(TIM_HandleTypeDef &htim);
    void start() noexcept;
    void stop() noexcept;
    void update() noexcept;
    int32_t getCount() const noexcept;
    void setCount(int32_t count) noexcept;
    void resetCount() noexcept;
};

} // namespace halex

#endif // CONFIG_DISABLE_MODULE_TIM

#endif // HAL_EXTENSION_TIM_ENCODER_HPP
