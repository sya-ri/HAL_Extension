#ifndef HAL_EXTENSION_I2C_FUNCTION_SLAVE_RECEIVE_HPP
#define HAL_EXTENSION_I2C_FUNCTION_SLAVE_RECEIVE_HPP

#ifndef CONFIG_DISABLE_MODULE_I2C

#include "i2c.h"

namespace halex {

template <class T>
inline HAL_StatusTypeDef i2cSlaveReceive(I2C_HandleTypeDef *hi2c, T &data, uint32_t timeout) noexcept {
    return HAL_I2C_Slave_Receive(hi2c, (uint8_t *) &data, sizeof(T), timeout);
}

template <class T>
inline HAL_StatusTypeDef i2cSlaveReceive(I2C_HandleTypeDef &hi2c, T &data, uint32_t timeout) noexcept {
    return i2cSlaveReceive(&hi2c, data, timeout);
}

template <class T>
inline HAL_StatusTypeDef i2cSlaveReceive_IT(I2C_HandleTypeDef *hi2c, T &data) noexcept {
    return HAL_I2C_Slave_Receive_IT(hi2c, (uint8_t *) &data, sizeof(T));
}

template <class T>
inline HAL_StatusTypeDef i2cSlaveReceive_IT(I2C_HandleTypeDef &hi2c, T &data) noexcept {
    return i2cSlaveReceive_IT(&hi2c, data);
}

template <class T>
inline HAL_StatusTypeDef i2cSlaveReceive_DMA(I2C_HandleTypeDef *hi2c, T &data) noexcept {
    return HAL_I2C_Slave_Receive_DMA(hi2c, (uint8_t *) &data, sizeof(T));
}

template <class T>
inline HAL_StatusTypeDef i2cSlaveReceive_DMA(I2C_HandleTypeDef &hi2c, T &data) noexcept {
    return i2cSlaveReceive_DMA(&hi2c, data);
}

} // namespace halex

#endif // CONFIG_DISABLE_MODULE_I2C

#endif // HAL_EXTENSION_I2C_FUNCTION_SLAVE_RECEIVE_HPP
