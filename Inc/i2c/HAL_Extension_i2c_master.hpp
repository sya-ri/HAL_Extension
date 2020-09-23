#ifndef HAL_EXTENSION_I2C_MASTER_HPP
#define HAL_EXTENSION_I2C_MASTER_HPP

#ifndef CONFIG_DISABLE_MODULE_I2C

#include "i2c.h"

template<class T>
class I2C_Master {
private:
    I2C_HandleTypeDef* hi2c;
public:
    I2C_Master(){}

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

#endif // CONFIG_DISABLE_MODULE_I2C

#endif // HAL_EXTENSION_I2C_MASTER_HPP
