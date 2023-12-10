#if __has_include("tim.h")

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
    if (((int32_t) (lastRawCount - rawCount)) > ((int32_t) (__HAL_TIM_GET_AUTORELOAD(htim) / 2))) { // overflow
        count += __HAL_TIM_GET_AUTORELOAD(htim);
    } else if (((int32_t) (rawCount - lastRawCount)) > ((int32_t) (__HAL_TIM_GET_AUTORELOAD(htim) / 2))) { // underflow
        count -= __HAL_TIM_GET_AUTORELOAD(htim);
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

#endif // __has_include
