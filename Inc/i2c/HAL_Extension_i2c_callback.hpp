#ifndef HAL_EXTENSION_I2C_CALLBACK_HPP
#define HAL_EXTENSION_I2C_CALLBACK_HPP

#ifndef CONFIG_DISABLE_MODULE_I2C

#include "i2c.h"
#include <functional>

namespace halex {

#ifndef CONFIG_DISABLE_EX_CALLBACK
void setI2CMasterTxCallback(I2C_HandleTypeDef *hi2c, std::function<void()> function);
void setI2CMasterRxCallback(I2C_HandleTypeDef *hi2c, std::function<void()> function);
void setI2CSlaveTxCallback(I2C_HandleTypeDef *hi2c, std::function<void()> function);
void setI2CSlaveRxCallback(I2C_HandleTypeDef *hi2c, std::function<void()> function);
void setI2CErrorCallback(I2C_HandleTypeDef *hi2c, std::function<void()> function);
void setI2CMasterTxCallback(I2C_HandleTypeDef &hi2c, std::function<void()> function);
void setI2CMasterRxCallback(I2C_HandleTypeDef &hi2c, std::function<void()> function);
void setI2CSlaveTxCallback(I2C_HandleTypeDef &hi2c, std::function<void()> function);
void setI2CSlaveRxCallback(I2C_HandleTypeDef &hi2c, std::function<void()> function);
void setI2CErrorCallback(I2C_HandleTypeDef &hi2c, std::function<void()> function);
#endif // CONFIG_DISABLE_EX_CALLBACK

} // namespace halex

#endif // CONFIG_DISABLE_MODULE_I2C

#endif // HAL_EXTENSION_I2C_CALLBACK_HPP
