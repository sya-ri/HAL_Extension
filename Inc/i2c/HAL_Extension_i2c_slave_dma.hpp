#ifndef HAL_EXTENSION_I2C_SLAVE_DMA_HPP
#define HAL_EXTENSION_I2C_SLAVE_DMA_HPP

#ifndef CONFIG_DISABLE_MODULE_I2C

#include "i2c.h"
#include "HAL_Extension_i2c_callback.hpp"

template<class T>
class I2C_Slave_DMA {
private:
    I2C_HandleTypeDef* hi2c;
    uint8_t address;
    T *data;
public:
    I2C_Slave_DMA(){}

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

#ifndef CONFIG_DISABLE_EX_CALLBACK
    void setTxCallback(std::function<void()> function){
        setI2CSlaveTxCallback(hi2c, function);
    }

    void setRxCallback(std::function<void()> function){
        setI2CSlaveRxCallback(hi2c, function);
    }

    void setErrorCallback(std::function<void()> function){
        setI2CErrorCallback(hi2c, function);
    }
#endif // CONFIG_DISABLE_EX_CALLBACK
};

#endif // CONFIG_DISABLE_MODULE_I2C

#endif // HAL_EXTENSION_I2C_SLAVE_DMA_HPP
