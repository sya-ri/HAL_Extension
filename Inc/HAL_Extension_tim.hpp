#ifndef HAL_EXTENSION_TIM_HPP
#define HAL_EXTENSION_TIM_HPP

#include "HAL_Extension_util.hpp"
#include <map>
#include <functional>

class PWM {
private:
    TIM_HandleTypeDef *htim;
    uint32_t channel;
public:
    PWM();
    PWM(TIM_HandleTypeDef &htim, uint32_t channel);
    void start();
    void stop();
    bool setCompare(uint32_t compare);
    uint32_t getCounterPeriod();
};

class Motor {
private:
    PWM positive;
    PWM negative;
public:
    Motor();
    Motor(PWM positive, PWM negative);
    Motor(TIM_HandleTypeDef &htimPos, uint32_t channelPos, TIM_HandleTypeDef &htimNeg, uint32_t channelNeg);
    void start();
    void stop();
    bool setSpeed(bool forward, uint32_t compare);
    bool setSpeed(int64_t speed);
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
    Encoder();
    Encoder(TIM_HandleTypeDef &htim, uint32_t channel = TIM_CHANNEL_ALL);
    void start();
    void stop();
    void update();
    int32_t getCount();
    void resetCount();
};

class TimerInterrupt {
private:
    TIM_HandleTypeDef *htim;
public:
    TimerInterrupt();
    TimerInterrupt(TIM_HandleTypeDef &htim);
    bool start(uint32_t prescaler, uint32_t counterPeriod);
    bool start();
    void stop();
    void setCallback(std::function<void()> function);
};

#endif
