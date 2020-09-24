#ifndef CONFIG_DISABLE_MODULE_TIM

#include "tim/HAL_Extension_tim_encoder.hpp"

Encoder::Encoder(){}

Encoder::Encoder(TIM_HandleTypeDef &htim, uint32_t channel): htim(&htim), channel(channel){

}

void Encoder::start() noexcept {
	int16_t lastCount = count;
	if(!isStart){
		HAL_TIM_Encoder_Start(htim, channel);
	}
	__HAL_TIM_CLEAR_FLAG(htim, channel);
	__HAL_TIM_SET_COUNTER(htim , 0);
	isStart = true;
	update();
	count = lastCount;
}

void Encoder::stop() noexcept {
	update();
	if(isStart){
		HAL_TIM_Encoder_Stop(htim, channel);
	}
	__HAL_TIM_CLEAR_FLAG(htim, channel);
	__HAL_TIM_SET_COUNTER(htim , 0);
	isStart = false;
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

void Encoder::resetCount() noexcept {
	update();
	count = 0;
}

#endif // CONFIG_DISABLE_MODULE_TIM
