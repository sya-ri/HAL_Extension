#ifndef HAL_EXTENSION_TIM_HPP
#define HAL_EXTENSION_TIM_HPP
#ifdef __tim_H

#include <map>
#include <functional>

namespace {
    std::map<TIM_HandleTypeDef *, std::function<void()>> __tim__period_elapsed_callback;
}

class PWM {
private:
    TIM_HandleTypeDef &htim;
    uint32_t channel;
    uint32_t counterPeriod;
public:
    PWM(TIM_HandleTypeDef &htim, uint32_t channel): htim(htim), channel(channel){
        counterPeriod = htim.Init.Period;
    }

    void start(){
        HAL_TIM_PWM_Start(&htim, channel);
    }

    void stop(){
        HAL_TIM_PWM_Stop(&htim, channel);
    }

    bool setCompare(uint32_t compare){
        if(counterPeriod < compare){
            return false;
        } else {
            __HAL_TIM_SET_COMPARE(&htim, channel, compare);
            return true;
        }
    }

    uint32_t getCounterPeriod(){
        return counterPeriod;
    }
};

class Motor {
private:
    PWM positive;
    PWM negative;
public:
    Motor(PWM positive, PWM negative): positive(positive), negative(negative){

    }

    Motor(TIM_HandleTypeDef &htimPos, uint32_t channelPos, TIM_HandleTypeDef &htimNeg, uint32_t channelNeg): positive(PWM(htimPos, channelPos)), negative(PWM(htimNeg, channelNeg)){

    }

    void start(){
        positive.start();
        negative.start();
    }

    void stop(){
        positive.stop();
        negative.stop();
    }

    bool setSpeed(bool forward, uint32_t compare){
        if(forward){
            return positive.setCompare(compare) && negative.setCompare(0);
        } else {
            return positive.setCompare(0) && negative.setCompare(compare);
        }
    }

    bool setSpeed(int64_t speed){
        bool back = speed < 0;
        if(UINT32_MAX < speed) return false;
        return setSpeed(!back, (uint32_t) (back? -speed : speed);
    }
};

class Encoder {
private:
    TIM_HandleTypeDef *htim;
    uint32_t channel;
    bool isStart = false;
    uint16_t lastRawCount = 0;
    uint16_t rawCount = 0;
    int32_t count = 0;
public:
    Encoder(TIM_HandleTypeDef &htim, uint32_t channel = TIM_CHANNEL_ALL): htim(&htim), channel(channel){

    }

    void start(){
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

    void stop(){
        update();
        if(isStart){
            HAL_TIM_Encoder_Stop(htim, channel);
        }
        __HAL_TIM_CLEAR_FLAG(htim, channel);
        __HAL_TIM_SET_COUNTER(htim , 0);
        isStart = false;
    }

    void update(){
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

    int32_t getCount(){
        return count;
    }

    void resetCount(){
        update();
        count = 0;
    }
};

class TimerInterrupt {
private:
    TIM_HandleTypeDef *htim;
public:
    TimerInterrupt(TIM_HandleTypeDef &htim): htim(&htim){

    }

    bool start(uint32_t prescaler, uint32_t counterPeriod){
        if(0xFFFF < prescaler || 0xFFFF < counterPeriod){ // 0xFFFF == 65535
            return false;
        }
        stop();
        HAL_TIM_Base_DeInit(htim);
        htim->Init.Prescaler = prescaler;
        htim->Init.Period = counterPeriod;
        HAL_TIM_Base_Init(htim);
        return start();
    }

    bool start(){
        __HAL_TIM_SET_COUNTER(htim , 0);
        HAL_TIM_Base_Start_IT(htim);
        return true;
    }

    void stop(){
        HAL_TIM_Base_Stop_IT(htim);
    }

    void setCallback(std::function<void()> function){
        __tim__period_elapsed_callback[htim] = function;
    }
};

#ifdef CONFIG_TIM_USE_HALF_CALLBACK
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
#else  // CONFIG_TIM_USE_HALF_CALLBACK
void HAL_TIM_PeriodElapsedHalfCpltCallback(TIM_HandleTypeDef *htim){
#endif // CONFIG_TIM_USE_HALF_CALLBACK
    if(map_contains(__tim__period_elapsed_callback, htim)){
        __tim__period_elapsed_callback[htim]();
    }
}

#endif // __tim_H
#endif
