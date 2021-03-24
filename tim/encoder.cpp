#ifndef CONFIG_DISABLE_MODULE_TIM

#include "tim/encoder.hpp"

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
        if (__HAL_TIM_IS_TIM_COUNTING_DOWN(htim)) {
            count -= __HAL_TIM_GET_AUTORELOAD(htim);
        } else {
            count += __HAL_TIM_GET_AUTORELOAD(htim);
        }
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
