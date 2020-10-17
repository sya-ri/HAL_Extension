#ifndef CONFIG_DISABLE_MODULE_TIM

#include "tim/HAL_Extension_tim_encoder.hpp"

namespace halex {

Encoder::Encoder() {}

Encoder::Encoder(TIM_HandleTypeDef *htim): htim(htim) {

}

Encoder::Encoder(TIM_HandleTypeDef &htim): Encoder(&htim) {

}

void Encoder::start() noexcept {
    __HAL_TIM_SET_COUNTER(htim , 0);
    __HAL_TIM_CLEAR_FLAG(htim, TIM_CHANNEL_ALL);
    if(!isStart) {
        HAL_TIM_Encoder_Start(htim, TIM_CHANNEL_ALL);
        isStart = true;
    }
}

void Encoder::stop() noexcept {
    update();
    if(isStart) {
        HAL_TIM_Encoder_Stop(htim, TIM_CHANNEL_ALL);
        isStart = false;
    }
    __HAL_TIM_SET_COUNTER(htim , 0);
    __HAL_TIM_CLEAR_FLAG(htim, TIM_CHANNEL_ALL);
}

void Encoder::update() noexcept {
    if(!isStart) return;
    lastRawCount = rawCount;
    if (__HAL_TIM_GET_FLAG(htim, TIM_FLAG_UPDATE)) {
        rawCount = __HAL_TIM_GET_COUNTER(htim);
        if (rawCount > lastRawCount) {
            count += (rawCount - __HAL_TIM_GET_AUTORELOAD(htim)) - lastRawCount;
        } else {
            count += rawCount - (lastRawCount - __HAL_TIM_GET_AUTORELOAD(htim));
        }
        __HAL_TIM_CLEAR_FLAG(htim, TIM_FLAG_UPDATE);
    } else {
        rawCount = __HAL_TIM_GET_COUNTER(htim);
        count += rawCount - lastRawCount;
    }
}

int32_t Encoder::getCount() const noexcept {
    return count;
}

void Encoder::setCount(int32_t count) noexcept {
    update();
    this->count = count;
}

void Encoder::resetCount() noexcept {
    setCount(0);
}

} // namespace halex

#endif // CONFIG_DISABLE_MODULE_TIM
