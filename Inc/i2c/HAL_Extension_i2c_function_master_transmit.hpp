#ifndef HAL_EXTENSION_I2C_FUNCTION_MASTER_TRANSMIT_HPP
#define HAL_EXTENSION_I2C_FUNCTION_MASTER_TRANSMIT_HPP

#ifndef CONFIG_DISABLE_MODULE_I2C

#include "i2c.h"

namespace halex {

template <class T>
HAL_StatusTypeDef i2cMasterTransmit(I2C_HandleTypeDef *hi2c, uint8_t target, const T &data, uint32_t timeout) noexcept {
    return HAL_I2C_Master_Transmit(hi2c, target << 1, (uint8_t *) &data, sizeof(T), timeout);
}

template <class T>
HAL_StatusTypeDef i2cMasterTransmit(I2C_HandleTypeDef &hi2c, uint8_t target, const T &data, uint32_t timeout) noexcept {
    return i2cMasterTransmit(hi2c, target, data, timeout);
}

template <class T>
HAL_StatusTypeDef i2cMasterTransmit_IT(I2C_HandleTypeDef *hi2c, uint8_t target, const T &data) noexcept {
    return HAL_I2C_Master_Transmit_IT(hi2c, target << 1, (uint8_t *) &data, sizeof(T));
}

template <class T>
HAL_StatusTypeDef i2cMasterTransmit_IT(I2C_HandleTypeDef &hi2c, uint8_t target, const T &data) noexcept {
    return i2cMasterTransmit_IT(hi2c, target, data);
}

template <class T>
HAL_StatusTypeDef i2cMasterTransmit_DMA(I2C_HandleTypeDef *hi2c, uint8_t target, const T &data) noexcept {
    return HAL_I2C_Master_Transmit_DMA(hi2c, target << 1, (uint8_t *) &data, sizeof(T));
}

template <class T>
HAL_StatusTypeDef i2cMasterTransmit_DMA(I2C_HandleTypeDef &hi2c, uint8_t target, const T &data) noexcept {
    return i2cMasterTransmit_DMA(hi2c, target, data);
}

} // namespace halex

#endif // CONFIG_DISABLE_MODULE_I2C

#endif // HAL_EXTENSION_I2C_FUNCTION_MASTER_TRANSMIT_HPP
