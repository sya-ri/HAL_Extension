#ifndef CONFIG_DISABLE_MODULE_TIM

#include "tim/encoder.hpp"
#include <cmath>

namespace halex {

Encoder::Encoder() {}

Encoder::Encoder(TIM_HandleTypeDef *htim): htim(htim) {

}

Encoder::Encoder(TIM_HandleTypeDef &htim): Encoder(&htim) {

}

void Encoder::start() noexcept {
    __HAL_TIM_SET_COUNTER(htim , 0);
    __HAL_TIM_CLEAR_FLAG(htim, TIM_FLAG_UPDATE);
    if(!isStart) {
        HAL_TIM_Encoder_Start(htim, TIM_CHANNEL_ALL);
        isStart = true;
    }
}

void Encoder::stop() noexcept {
    if(isStart) {
        HAL_TIM_Encoder_Stop(htim, TIM_CHANNEL_ALL);
        isStart = false;
    }
    __HAL_TIM_SET_COUNTER(htim , 0);
    __HAL_TIM_CLEAR_FLAG(htim, TIM_FLAG_UPDATE);
}

void Encoder::update() noexcept {
    if(!isStart) return;
    lastRawCount = rawCount;
    rawCount = __HAL_TIM_GET_COUNTER(htim);
    count += rawCount - lastRawCount;
    if (__HAL_TIM_GET_FLAG(htim, TIM_FLAG_UPDATE)) {
        __HAL_TIM_CLEAR_FLAG(htim, TIM_FLAG_UPDATE);
        // FLAGが立った時、counter period の倍数を今回値から引いて、修正する
        count -= __HAL_TIM_GET_AUTORELOAD(htim) * std::round((float)(rawCount - lastRawCount)/__HAL_TIM_GET_AUTORELOAD(htim));
    }
}

int32_t Encoder::getCount() const noexcept {
    return count;
}

void Encoder::setCount(int32_t count) noexcept {
    __HAL_TIM_CLEAR_FLAG(htim, TIM_FLAG_UPDATE);
    this->count = count;
}

void Encoder::resetCount() noexcept {
    setCount(0);
}

} // namespace halex

#endif // CONFIG_DISABLE_MODULE_TIM
