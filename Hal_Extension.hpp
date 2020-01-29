//
// Created by @fly_in_pig on 2020/01/28.
// Version
// - 1.0 : 2020/01/29
//

#ifndef HAL_EXTENSION_HPP
#define HAL_EXTENSION_HPP

#include "main.h"

#ifdef __has_include // since C++ 17

#if __has_include("gpio.h")
#include "gpio.h"
#endif // __has_include("gpio.h")

#if __has_include("usart.h")
#include "usart.h"
#endif // __has_include("usart.h")

#if __has_include("i2c.h")
#include "i2c.h"
#endif // __has_include("i2c.h")

#if __has_include("tim.h")
#include "tim.h"
#endif // __has_include("tim.h")

#endif // __has_include

#define getTick() HAL_GetTick()
#define delay(__ms) HAL_Delay(__ms)
#define gpioRead(GPIOx, GPIO_Pin) HAL_GPIO_ReadPin(GPIOx, GPIO_Pin)
#define gpioWrite(GPIOx, GPIO_Pin, PinState) HAL_GPIO_WritePin(GPIOx, GPIO_Pin, PinState)
#define gpioToggle(GPIOx, GPIO_Pin) HAL_GPIO_TogglePin(GPIOx, GPIO_Pin)

#ifdef __gpio_H
class GPIO {
private:
    GPIO_TypeDef* GPIOx;
    uint16_t GPIO_Pin;
public:
    GPIO(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin): GPIOx(GPIOx), GPIO_Pin(GPIO_Pin){

    }

    GPIO_PinState read(){
        return gpioRead(GPIOx, GPIO_Pin);
    }

    void write(GPIO_PinState PinState){
        gpioWrite(GPIOx, GPIO_Pin, PinState);
    }

    void set(){
        write(GPIO_PIN_SET);
    }

    void reset(){
        write(GPIO_PIN_RESET);
    }

    void toggle(){
        gpioToggle(GPIOx, GPIO_Pin);
    }
};
#endif // __gpio_H

#ifdef __usart_H
template<class T>
class UART {
private:
    UART_HandleTypeDef *huart;
public:
    UART(UART_HandleTypeDef &huart): huart(&huart){

    }

    HAL_StatusTypeDef transmit(T &pData, uint32_t timeout){
        return HAL_UART_Transmit(huart, (uint8_t *) &pData, sizeof(T), timeout);
    }

    HAL_StatusTypeDef receive(T &pData, uint32_t timeout){
        return HAL_UART_Receive(huart, (uint8_t *) &pData, sizeof(T), timeout);
    }
};
#endif // __usart_H

#ifdef __i2c_H
template<class T>
class I2C {
private:
    I2C_HandleTypeDef *hi2c;
    uint8_t address;
public:
    I2C(I2C_HandleTypeDef &hi2c, uint8_t address): hi2c(&hi2c), address(address) {

    }

    void init(){
        HAL_I2C_DeInit(hi2c);
        hi2c->Init.OwnAddress1 = address << 1;
        HAL_I2C_Init(hi2c);
    }

    HAL_StatusTypeDef masterTransmit(uint8_t target, T &pData, uint32_t timeout){
        return HAL_I2C_Master_Transmit(hi2c, target << 1, (uint8_t *) &pData, sizeof(T), timeout);
    }

    HAL_StatusTypeDef masterReceive(uint8_t target, T &pData, uint32_t timeout){
        return HAL_I2C_Master_Receive(hi2c, target << 1, (uint8_t *) &pData, sizeof(T), timeout);
    }

    HAL_StatusTypeDef slaveTransmit(T &pData, uint32_t timeout){
        return HAL_I2C_Slave_Transmit(hi2c, (uint8_t *) &pData, sizeof(T), timeout);
    }

    HAL_StatusTypeDef slaveReceive(T &pData, uint32_t timeout){
        return HAL_I2C_Slave_Receive(hi2c, (uint8_t *) &pData, sizeof(T), timeout);
    }
};
#endif // __i2c_H

#ifdef __tim_H
class PWM {
private:
    TIM_HandleTypeDef &htim;
    uint32_t channel;
    uint32_t counterPeriod;
public:
    PWM(TIM_HandleTypeDef &htim, uint32_t channel): htim(htim), channel(channel){
        counterPeriod = htim.Init.Period;
    }

    void init(){
        HAL_TIM_PWM_Start(&htim, channel);
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

    bool setSpeed(bool forward, uint32_t compare){
        if(forward){
            return positive.setCompare(compare) && negative.setCompare(0);
        } else {
            return positive.setCompare(0) && negative.setCompare(compare);
        }
    }

    bool setSpeed(int64_t speed){
        bool back = speed < 0;
        if(back) speed *= -1;
        if(UINT32_MAX < speed) return false;
        return setSpeed(!back, (uint32_t) speed);
    }
};

#endif // __tim_H

#endif //HAL_EXTENSION_HPP
