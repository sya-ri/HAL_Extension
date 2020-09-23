#ifndef CONFIG_DISABLE_MODULE_I2C

#ifndef CONFIG_DISABLE_EX_CALLBACK

#include "i2c/HAL_Extension_i2c_callback.hpp"
#include <map>
#include "HAL_Extension_util.hpp"

namespace {
    std::map<I2C_HandleTypeDef *, std::function<void()>> i2c_master_tx_callback;
    std::map<I2C_HandleTypeDef *, std::function<void()>> i2c_master_rx_callback;
    std::map<I2C_HandleTypeDef *, std::function<void()>> i2c_slave_tx_callback;
    std::map<I2C_HandleTypeDef *, std::function<void()>> i2c_slave_rx_callback;
    std::map<I2C_HandleTypeDef *, std::function<void()>> i2c_error_callback;
}

void setI2CMasterTxCallback(I2C_HandleTypeDef *hi2c, std::function<void()> function){
    i2c_master_tx_callback[hi2c] = function;
}

void setI2CMasterRxCallback(I2C_HandleTypeDef *hi2c, std::function<void()> function){
    i2c_master_rx_callback[hi2c] = function;
}

void setI2CSlaveTxCallback(I2C_HandleTypeDef *hi2c, std::function<void()> function){
    i2c_slave_tx_callback[hi2c] = function;
}

void setI2CSlaveRxCallback(I2C_HandleTypeDef *hi2c, std::function<void()> function){
    i2c_slave_rx_callback[hi2c] = function;
}

void setI2CErrorCallback(I2C_HandleTypeDef *hi2c, std::function<void()> function){
    i2c_error_callback[hi2c] = function;
}

void HAL_I2C_MasterTxCpltCallback(I2C_HandleTypeDef *hi2c){
    if(map_contains(i2c_master_tx_callback, hi2c)){
        i2c_master_tx_callback[hi2c]();
    }
}

void HAL_I2C_MasterRxCpltCallback(I2C_HandleTypeDef *hi2c){
    if(map_contains(i2c_master_rx_callback, hi2c)){
        i2c_master_rx_callback[hi2c]();
    }
}

void HAL_I2C_SlaveTxCpltCallback(I2C_HandleTypeDef *hi2c){
    if(map_contains(i2c_slave_tx_callback, hi2c)){
        i2c_slave_tx_callback[hi2c]();
    }
}

void HAL_I2C_SlaveRxCpltCallback(I2C_HandleTypeDef *hi2c){
    if(map_contains(i2c_slave_rx_callback, hi2c)){
        i2c_slave_rx_callback[hi2c]();
    }
}

void HAL_I2C_ErrorCallback(I2C_HandleTypeDef *hi2c){
    if(map_contains(i2c_error_callback, hi2c)){
        i2c_error_callback[hi2c]();
    }
}
#endif // CONFIG_DISABLE_EX_CALLBACK

#endif // CONFIG_DISABLE_MODULE_I2C
