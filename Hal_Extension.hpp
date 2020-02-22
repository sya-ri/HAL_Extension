// Hal_Extension
// Version:
// - 1.0 : 2020/01/29 @fly_in_pig
// - 2.0 : 2020/02/21 @fly_in_pig
// - 2.1 : 2020/02/21 @fly_in_pig
// - 2.2 : 2020/02/22 @fly_in_pig
//

#ifndef HAL_EXTENSION_HPP
#define HAL_EXTENSION_HPP

#include "main.h"
#include <map>
#include <vector>
#include <functional>

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

#if __has_include("adc.h")
#include "adc.h"
#endif // __has_include("adc.h")

#endif // __has_include

#define getTick() HAL_GetTick()
#define delay(__ms) HAL_Delay(__ms)
#define gpioRead(GPIOx, GPIO_Pin) HAL_GPIO_ReadPin(GPIOx, GPIO_Pin)
#define gpioWrite(GPIOx, GPIO_Pin, PinState) HAL_GPIO_WritePin(GPIOx, GPIO_Pin, PinState)
#define gpioToggle(GPIOx, GPIO_Pin) HAL_GPIO_TogglePin(GPIOx, GPIO_Pin)

#define __function_map(Key) std::map<Key, std::function<void()>>
#define __map_contains(Map, Key) (Map.find(Key) != Map.end())

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

class DIPSwitch {
private:
    std::vector<GPIO> list;
public:
    DIPSwitch() {

    }

    bool add(GPIO gpio){
        if(getSize() == 7){
            return false;
        }
        list.push_back(gpio);
        return true;
    }

    bool add(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin){
        return add(GPIO(GPIOx, GPIO_Pin));
    }

    uint8_t getSize(){
        return list.size();
    }

    uint8_t getAddress(){
        uint8_t builder = 0;
        for(int i = 0; i < getSize(); i++){
            builder |= list[i].read() << i;
        }
        return builder;
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

    HAL_StatusTypeDef transmit(T &data, uint32_t timeout){
        return HAL_UART_Transmit(huart, (uint8_t *) &data, sizeof(T), timeout);
    }

    HAL_StatusTypeDef receive(T &data, uint32_t timeout){
        return HAL_UART_Receive(huart, (uint8_t *) &data, sizeof(T), timeout);
    }
};

static __function_map(UART_HandleTypeDef *) __uart_tx_callback;
static __function_map(UART_HandleTypeDef *) __uart_rx_callback;
static __function_map(UART_HandleTypeDef *) __uart_error_callback;

template<class T>
class UART_DMA {
private:
    UART_HandleTypeDef *huart;
    T *data;
public:
    UART_DMA(UART_HandleTypeDef &huart, T &data): huart(&huart), data(&data){

    }

    HAL_StatusTypeDef startTransmit(){
        return HAL_UART_Transmit_DMA(huart, (uint8_t *) data, sizeof(T));
    }

    HAL_StatusTypeDef startReceive(){
        return HAL_UART_Receive_DMA(huart, (uint8_t *) data, sizeof(T));
    }

    HAL_StatusTypeDef pause(){
        return HAL_UART_DMAPause(huart);
    }

    HAL_StatusTypeDef resume(){
        return HAL_UART_DMAResume(huart);
    }

    HAL_StatusTypeDef stop(){
        return HAL_UART_DMAStop(huart);
    }

    void setTxCallback(std::function<void()> function){
        __uart_tx_callback[huart] = function;
    }

    void setRxCallback(std::function<void()> function){
        __uart_rx_callback[huart] = function;
    }

    void setErrorCallback(std::function<void()> function){
        __uart_error_callback[huart] = function;
    }
};

#ifdef CONFIG_UART_USE_HALF_CALLBACK
void HAL_UART_TxHalfCpltCallback(UART_HandleTypeDef *huart){
#else  // CONFIG_UART_USE_HALF_CALLBACK
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
#endif // CONFIG_UART_USE_HALF_CALLBACK
    if(__map_contains(__uart_tx_callback, huart)){
        __uart_tx_callback[huart]();
    }
}

#ifdef CONFIG_UART_USE_HALF_CALLBACK
void HAL_UART_RxHalfCpltCallback(UART_HandleTypeDef *huart){
#else  // CONFIG_UART_USE_HALF_CALLBACK
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
#endif // CONFIG_UART_USE_HALF_CALLBACK
    if(__map_contains(__uart_rx_callback, huart)){
        __uart_rx_callback[huart]();
    }
}

void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart){
    if(__map_contains(__uart_error_callback, huart)){
        __uart_error_callback[huart]();
    }
}

class UART_Logger {
private:
    UART<const char> uart;
    uint32_t timeout;
public:
    UART_Logger(UART_HandleTypeDef &huart, uint32_t timeout = 0x0F): uart(UART<const char>(huart)), timeout(timeout){

    }

    void print(const char* text){
        do {
            uart.transmit(*text++, timeout);
        } while(*text);
    }

    void println(const char* text){
        print(text);
        uart.transmit('\r', timeout);
        uart.transmit('\n', timeout);
    }
};

#endif // __usart_H

#ifdef __i2c_H
template<class T>
class I2C_Master {
private:
    I2C_HandleTypeDef* hi2c;
public:
    I2C_Master(I2C_HandleTypeDef &hi2c): hi2c(&hi2c){

    }

    void init(){
        HAL_I2C_DeInit(hi2c);
        HAL_I2C_Init(hi2c);
    }

    HAL_StatusTypeDef transmit(uint8_t target, T &data, uint32_t timeout){
        return HAL_I2C_Master_Transmit(hi2c, target << 1, (uint8_t *) &data, sizeof(T), timeout);
    }

    HAL_StatusTypeDef receive(uint8_t target, T &data, uint32_t timeout){
        return HAL_I2C_Master_Receive(hi2c, target << 1, (uint8_t *) &data, sizeof(T), timeout);
    }
};

template<class T>
class I2C_Slave {
private:
    I2C_HandleTypeDef* hi2c;
    uint8_t address;
public:
    I2C_Slave(I2C_HandleTypeDef &hi2c, uint8_t address = 0x00): hi2c(&hi2c), address(address) {

    }

    void init(){
        HAL_I2C_DeInit(hi2c);
        hi2c->Init.OwnAddress1 = address << 1;
        HAL_I2C_Init(hi2c);
    }

    void init(uint8_t address){
        this->address = address;
        init();
    }

#ifdef __gpio_H
    void init(DIPSwitch builder){
        init(builder.getAddress());
    }
#endif // __gpio_H

    HAL_StatusTypeDef transmit(T &data, uint32_t timeout){
        return HAL_I2C_Slave_Transmit(hi2c, (uint8_t *) &data, sizeof(T), timeout);
    }

    HAL_StatusTypeDef receive(T &data, uint32_t timeout){
        return HAL_I2C_Slave_Receive(hi2c, (uint8_t *) &data, sizeof(T), timeout);
    }
};

static __function_map(I2C_HandleTypeDef *) __i2c_master_tx_callback;
static __function_map(I2C_HandleTypeDef *) __i2c_master_rx_callback;

template<class T>
class I2C_Master_DMA {
private:
    I2C_HandleTypeDef* hi2c;
    uint8_t target;
    T *data;
public:
    I2C_Master_DMA(I2C_HandleTypeDef &hi2c, uint8_t target, T &data): hi2c(&hi2c), target(target), data(&data){

    }

    void init(){
        HAL_I2C_DeInit(hi2c);
        HAL_I2C_Init(hi2c);
    }

    HAL_StatusTypeDef startTransmit(){
        return HAL_I2C_Master_Transmit_DMA(hi2c, target << 1, (uint8_t *) &data, sizeof(T));
    }

    HAL_StatusTypeDef startReceive(){
        return HAL_I2C_Master_Receive_DMA(hi2c, target << 1, (uint8_t *) &data, sizeof(T));
    }

    void setTxCallback(std::function<void()> function){
        __i2c_master_tx_callback[hi2c] = function;
    }

    void setRxCallback(std::function<void()> function){
        __i2c_master_rx_callback[hi2c] = function;
    }
};

void HAL_I2C_MasterTxCpltCallback(I2C_HandleTypeDef *hi2c){
    if(__map_contains(__i2c_master_tx_callback, hi2c)){
        __i2c_master_tx_callback[hi2c]();
    }
}

void HAL_I2C_MasterRxCpltCallback(I2C_HandleTypeDef *hi2c){
    if(__map_contains(__i2c_master_rx_callback, hi2c)){
        __i2c_master_rx_callback[hi2c]();
    }
}

static __function_map(I2C_HandleTypeDef *) __i2c_slave_tx_callback;
static __function_map(I2C_HandleTypeDef *) __i2c_slave_rx_callback;

template<class T>
class I2C_Slave_DMA {
private:
    I2C_HandleTypeDef* hi2c;
    uint8_t address;
    T *data;
public:
    I2C_Slave_DMA(I2C_HandleTypeDef &hi2c, T &data, uint8_t address = 0x00): hi2c(&hi2c), data(&data), address(address) {

    }

    void init(){
        HAL_I2C_DeInit(hi2c);
        hi2c->Init.OwnAddress1 = address << 1;
        HAL_I2C_Init(hi2c);
    }

    void init(uint8_t address){
        this->address = address;
        init();
    }

#ifdef __gpio_H
    void init(DIPSwitch builder){
        init(builder.getAddress());
    }
#endif // __gpio_H

    HAL_StatusTypeDef startTransmit(){
        return HAL_I2C_Slave_Transmit_DMA(hi2c, (uint8_t *) &data, sizeof(T));
    }

    HAL_StatusTypeDef startReceive(){
        return HAL_I2C_Slave_Receive_DMA(hi2c, (uint8_t *) &data, sizeof(T));
    }

    void setTxCallback(std::function<void()> function){
        __i2c_slave_tx_callback[hi2c] = function;
    }

    void setRxCallback(std::function<void()> function){
        __i2c_slave_rx_callback[hi2c] = function;
    }
};

void HAL_I2C_SlaveTxCpltCallback(I2C_HandleTypeDef *hi2c){
    if(__map_contains(__i2c_slave_tx_callback, hi2c)){
        __i2c_slave_tx_callback[hi2c]();
    }
}

void HAL_I2C_SlaveRxCpltCallback(I2C_HandleTypeDef *hi2c){
    if(__map_contains(__i2c_slave_rx_callback, hi2c)){
        __i2c_slave_rx_callback[hi2c]();
    }
}


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
        if(back) speed *= -1;
        if(UINT32_MAX < speed) return false;
        return setSpeed(!back, (uint32_t) speed);
    }
};

#endif // __tim_H

#ifdef __adc_H

static __function_map(ADC_HandleTypeDef *) __adc_callback;

class ADC_DMA {
private:
    ADC_HandleTypeDef *hadc;
    uint32_t *adcBuf;
    uint8_t numberOfConversions;
public:
    ADC_DMA(ADC_HandleTypeDef &hadc, uint8_t numberOfConversions): hadc(&hadc), numberOfConversions(numberOfConversions){
        adcBuf = new uint32_t[numberOfConversions];
    }

    ~ADC_DMA(){
        delete[] adcBuf;
    }

    void start(){
        HAL_ADC_Start_DMA(hadc, adcBuf, numberOfConversions);
    }

    void stop(){
        HAL_ADC_Stop_DMA(hadc);
    }

    uint32_t get(uint8_t index) {
        if (index < numberOfConversions) {
            return adcBuf[index];
        }
        throw std::out_of_range("Over NumberOfConversions");
    }

    void setCallback(std::function<void()> function){
        __adc_callback[hadc] = function;
    }
};

#ifdef CONFIG_ADC_USE_HALF_CALLBACK
void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef* hadc){
#else  // CONFIG_ADC_USE_HALF_CALLBACK
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc){
#endif // CONFIG_ADC_USE_HALF_CALLBACK
    if(__map_contains(__adc_callback, hadc)){
        __adc_callback[hadc]();
    }
}

#endif // __adc_H

#undef __function_map
#undef __map_contains

#endif //HAL_EXTENSION_HPP
