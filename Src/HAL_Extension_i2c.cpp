#include "HAL_Extension_i2c.hpp"
#include "HAL_Extension_util.hpp"

std::map<I2C_HandleTypeDef *, std::function<void()>> __i2c_master_tx_callback;
std::map<I2C_HandleTypeDef *, std::function<void()>> __i2c_master_rx_callback;
std::map<I2C_HandleTypeDef *, std::function<void()>> __i2c_slave_tx_callback;
std::map<I2C_HandleTypeDef *, std::function<void()>> __i2c_slave_rx_callback;
std::map<I2C_HandleTypeDef *, std::function<void()>> __i2c_error_callback;

void HAL_I2C_MasterTxCpltCallback(I2C_HandleTypeDef *hi2c){
    if(map_contains(__i2c_master_tx_callback, hi2c)){
        __i2c_master_tx_callback[hi2c]();
    }
}

void HAL_I2C_MasterRxCpltCallback(I2C_HandleTypeDef *hi2c){
    if(map_contains(__i2c_master_rx_callback, hi2c)){
        __i2c_master_rx_callback[hi2c]();
    }
}

void HAL_I2C_SlaveTxCpltCallback(I2C_HandleTypeDef *hi2c){
    if(map_contains(__i2c_slave_tx_callback, hi2c)){
        __i2c_slave_tx_callback[hi2c]();
    }
}

void HAL_I2C_SlaveRxCpltCallback(I2C_HandleTypeDef *hi2c){
    if(map_contains(__i2c_slave_rx_callback, hi2c)){
        __i2c_slave_rx_callback[hi2c]();
    }
}

void HAL_I2C_ErrorCallback(I2C_HandleTypeDef *hi2c){
    if(map_contains(__i2c_error_callback, hi2c)){
        __i2c_error_callback[hi2c]();
    }
}
