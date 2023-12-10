#ifndef HAL_EXTENSION_I2C_FUNCTION_MASTER_RECEIVE_HPP
#define HAL_EXTENSION_I2C_FUNCTION_MASTER_RECEIVE_HPP

#if __has_include("i2c.h")

#include "i2c.h"

namespace halex {

template <class T>
inline HAL_StatusTypeDef i2cMasterReceive(I2C_HandleTypeDef *hi2c, uint8_t target, T &data, uint32_t timeout) noexcept {
    return HAL_I2C_Master_Receive(hi2c, target << 1, (uint8_t *) &data, sizeof(T), timeout);
}

template <class T>
inline HAL_StatusTypeDef i2cMasterReceive(I2C_HandleTypeDef &hi2c, uint8_t target, T &data, uint32_t timeout) noexcept {
    return i2cMasterReceive(&hi2c, target, data, timeout);
}

template <class T>
inline HAL_StatusTypeDef i2cMasterReceive_IT(I2C_HandleTypeDef *hi2c, uint8_t target, T &data) noexcept {
    return HAL_I2C_Master_Receive_IT(hi2c, target << 1, (uint8_t *) &data, sizeof(T));
}

template <class T>
inline HAL_StatusTypeDef i2cMasterReceive_IT(I2C_HandleTypeDef &hi2c, uint8_t target, T &data) noexcept {
    return i2cMasterReceive_IT(&hi2c, target, data);
}

template <class T>
inline HAL_StatusTypeDef i2cMasterReceive_DMA(I2C_HandleTypeDef *hi2c, uint8_t target, T &data) noexcept {
    return HAL_I2C_Master_Receive_DMA(hi2c, target << 1, (uint8_t *) &data, sizeof(T));
}

template <class T>
inline HAL_StatusTypeDef i2cMasterReceive_DMA(I2C_HandleTypeDef &hi2c, uint8_t target, T &data) noexcept {
    return i2cMasterReceive_DMA(&hi2c, target, data);
}

} // namespace halex

#endif // __has_include

#endif // HAL_EXTENSION_I2C_FUNCTION_MASTER_RECEIVE_HPP
