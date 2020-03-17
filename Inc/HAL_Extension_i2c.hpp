#ifndef HAL_EXTENSION_I2C_HPP
#define HAL_EXTENSION_I2C_HPP
#ifdef __i2c_H

#include <map>
#include <functional>
#include "HAL_Extension_gpio.hpp"

namespace {
    std::map<I2C_HandleTypeDef *, std::function<void()>> __i2c_master_tx_callback;
    std::map<I2C_HandleTypeDef *, std::function<void()>> __i2c_master_rx_callback;
    std::map<I2C_HandleTypeDef *, std::function<void()>> __i2c_slave_tx_callback;
    std::map<I2C_HandleTypeDef *, std::function<void()>> __i2c_slave_rx_callback;
    std::map<I2C_HandleTypeDef *, std::function<void()>> __i2c_error_callback;
}

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

    HAL_StatusTypeDef transmit(uint8_t target, const T &data, uint32_t timeout){
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

    void init(const uint8_t address){
        this->address = address;
        init();
    }

#ifdef __gpio_H
    void init(DIPSwitch builder){
        init(builder.getAddress());
    }
#endif // __gpio_H

    HAL_StatusTypeDef transmit(const T &data, uint32_t timeout){
        return HAL_I2C_Slave_Transmit(hi2c, (uint8_t *) &data, sizeof(T), timeout);
    }

    HAL_StatusTypeDef receive(T &data, uint32_t timeout){
        return HAL_I2C_Slave_Receive(hi2c, (uint8_t *) &data, sizeof(T), timeout);
    }
};

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

    void setErrorCallback(std::function<void()> function){
        __i2c_error_callback[hi2c] = function;
    }
};

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

    void setErrorCallback(std::function<void()> function){
        __i2c_error_callback[hi2c] = function;
    }
};

template<class T>
class I2C_Master_IT {
private:
    I2C_HandleTypeDef* hi2c;
public:
    I2C_Master_IT(I2C_HandleTypeDef &hi2c): hi2c(&hi2c){

    }

    void init(){
        HAL_I2C_DeInit(hi2c);
        HAL_I2C_Init(hi2c);
    }

    HAL_StatusTypeDef transmit(uint8_t target, const T &data){
        return HAL_I2C_Master_Transmit_IT(hi2c, target << 1, (uint8_t *) &data, sizeof(T));
    }

    HAL_StatusTypeDef receive(uint8_t target, T &data){
        return HAL_I2C_Master_Receive_IT(hi2c, target << 1, (uint8_t *) &data, sizeof(T));
    }

    void setTxCallback(std::function<void()> function){
        __i2c_slave_tx_callback[hi2c] = function;
    }

    void setRxCallback(std::function<void()> function){
        __i2c_slave_rx_callback[hi2c] = function;
    }

    void setErrorCallback(std::function<void()> function){
        __i2c_error_callback[hi2c] = function;
    }
};

template<class T>
class I2C_Slave_IT {
private:
    I2C_HandleTypeDef* hi2c;
    uint8_t address;
public:
    I2C_Slave_IT(I2C_HandleTypeDef &hi2c, uint8_t address = 0x00): hi2c(&hi2c), address(address) {

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

    HAL_StatusTypeDef transmit(const T &data){
        return HAL_I2C_Slave_Transmit_IT(hi2c, (uint8_t *) &data, sizeof(T));
    }

    HAL_StatusTypeDef receive(T &data){
        return HAL_I2C_Slave_Receive_IT(hi2c, (uint8_t *) &data, sizeof(T));
    }

    void setTxCallback(std::function<void()> function){
        __i2c_slave_tx_callback[hi2c] = function;
    }

    void setRxCallback(std::function<void()> function){
        __i2c_slave_rx_callback[hi2c] = function;
    }

    void setErrorCallback(std::function<void()> function){
        __i2c_error_callback[hi2c] = function;
    }
};

void HAL_I2C_MasterTxCpltCallback(I2C_HandleTypeDef *hi2c){
    if(map_contains(__i2c_master_tx_callback, hi2c)){
        __i2c_master_tx_callback[hi2c]();
    }
}

void HAL_I2C_MasterRxCpltCallback(I2C_HandleTypeDef *hi2c){
    if(map_contains(__i2c_master_rx_callback, hi2c)){
        __i2c_master_rx_callback[hi2c]();
    }
}

void HAL_I2C_SlaveTxCpltCallback(I2C_HandleTypeDef *hi2c){
    if(map_contains(__i2c_slave_tx_callback, hi2c)){
        __i2c_slave_tx_callback[hi2c]();
    }
}

void HAL_I2C_SlaveRxCpltCallback(I2C_HandleTypeDef *hi2c){
    if(map_contains(__i2c_slave_rx_callback, hi2c)){
        __i2c_slave_rx_callback[hi2c]();
    }
}

void HAL_I2C_ErrorCallback(I2C_HandleTypeDef *hi2c){
    if(map_contains(__i2c_error_callback, hi2c)){
        __i2c_error_callback[hi2c]();
    }
}

#endif // __i2c_H
#endif
