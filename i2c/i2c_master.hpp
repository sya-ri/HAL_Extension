#ifndef HAL_EXTENSION_I2C_MASTER_HPP
#define HAL_EXTENSION_I2C_MASTER_HPP

#if __has_include("i2c.h")

#include "i2c.h"
#include "function_master_transmit.hpp"
#include "function_master_receive.hpp"

namespace halex {

template<class T>
class I2C_Master {
private:
    I2C_HandleTypeDef* hi2c;
public:
    I2C_Master() {}

    I2C_Master(I2C_HandleTypeDef *hi2c): hi2c(hi2c) {

    }

    I2C_Master(I2C_HandleTypeDef &hi2c): I2C_Master(&hi2c) {

    }

    void init() noexcept {
        HAL_I2C_DeInit(hi2c);
        HAL_I2C_Init(hi2c);
    }

    HAL_StatusTypeDef transmit(uint8_t target, const T &data, uint32_t timeout) const noexcept {
        return i2cMasterTransmit(hi2c, target, data, timeout);
    }

    HAL_StatusTypeDef receive(uint8_t target, T &data, uint32_t timeout) const noexcept {
        return i2cMasterReceive(hi2c, target, data, timeout);
    }
};

} // namespace halex

#endif // __has_include

#endif // HAL_EXTENSION_I2C_MASTER_HPP
