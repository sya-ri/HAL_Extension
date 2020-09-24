#ifndef HAL_EXTENSION_I2C_MASTER_DMA_HPP
#define HAL_EXTENSION_I2C_MASTER_DMA_HPP

#ifndef CONFIG_DISABLE_MODULE_I2C

#include "i2c.h"
#include "HAL_Extension_i2c_callback.hpp"

template<class T>
class I2C_Master_DMA {
private:
    I2C_HandleTypeDef* hi2c;
    uint8_t target;
    T *data;
public:
    I2C_Master_DMA(){}

    I2C_Master_DMA(I2C_HandleTypeDef &hi2c, uint8_t target, T &data): hi2c(&hi2c), target(target), data(&data){

    }

    void init() noexcept {
        HAL_I2C_DeInit(hi2c);
        HAL_I2C_Init(hi2c);
    }

    HAL_StatusTypeDef startTransmit() noexcept {
        return HAL_I2C_Master_Transmit_DMA(hi2c, target << 1, (uint8_t *) &data, sizeof(T));
    }

    HAL_StatusTypeDef startReceive() noexcept {
        return HAL_I2C_Master_Receive_DMA(hi2c, target << 1, (uint8_t *) &data, sizeof(T));
    }

#ifndef CONFIG_DISABLE_EX_CALLBACK
    void setTxCallback(std::function<void()> function) noexcept {
        setI2CMasterTxCallback(hi2c, function);
    }

    void setRxCallback(std::function<void()> function) noexcept {
        setI2CMasterRxCallback(hi2c, function);
    }

    void setErrorCallback(std::function<void()> function) noexcept {
        setI2CErrorCallback(hi2c, function);
    }
#endif // CONFIG_DISABLE_EX_CALLBACK
};

#endif // CONFIG_DISABLE_MODULE_I2C

#endif // HAL_EXTENSION_I2C_MASTER_DMA_HPP
