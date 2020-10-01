#ifndef HAL_EXTENSION_I2C_FUNCTION_SLAVE_TRANSMIT_HPP
#define HAL_EXTENSION_I2C_FUNCTION_SLAVE_TRANSMIT_HPP

#ifndef CONFIG_DISABLE_MODULE_I2C

#include "i2c.h"

namespace halex {

template <class T>
HAL_StatusTypeDef i2cSlaveTransmit(I2C_HandleTypeDef *hi2c, const T &data, uint32_t timeout) noexcept {
    return HAL_I2C_Slave_Transmit(hi2c, (uint8_t *) &data, sizeof(T), timeout);
}

template <class T>
HAL_StatusTypeDef i2cSlaveTransmit(I2C_HandleTypeDef &hi2c, const T &data, uint32_t timeout) noexcept {
    return i2cSlaveTransmit(&hi2c, data, timeout);
}

template <class T>
HAL_StatusTypeDef i2cSlaveTransmit_IT(I2C_HandleTypeDef *hi2c, const T &data) noexcept {
    return HAL_I2C_Slave_Transmit_IT(hi2c, (uint8_t *) &data, sizeof(T));
}

template <class T>
HAL_StatusTypeDef i2cSlaveTransmit_IT(I2C_HandleTypeDef &hi2c, const T &data) noexcept {
    return i2cSlaveTransmit_IT(&hi2c, data);
}

template <class T>
HAL_StatusTypeDef i2cSlaveTransmit_DMA(I2C_HandleTypeDef *hi2c, const T &data) noexcept {
    return HAL_I2C_Slave_Transmit_DMA(hi2c, (uint8_t *) &data, sizeof(T));
}

template <class T>
HAL_StatusTypeDef i2cSlaveTransmit_DMA(I2C_HandleTypeDef &hi2c, const T &data) noexcept {
    return i2cSlaveTransmit_DMA(&hi2c, data);
}

} // namespace halex

#endif // CONFIG_DISABLE_MODULE_I2C

#endif // HAL_EXTENSION_I2C_FUNCTION_SLAVE_TRANSMIT_HPP
