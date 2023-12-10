#ifndef CONFIG_DISABLE_MODULE_I2C

#include "i2c/callback.hpp"
#include <map>
#include "util/function.hpp"

namespace halex {

namespace {
    std::map<I2C_HandleTypeDef *, std::function<void()>> i2c_master_tx_callback;
    std::map<I2C_HandleTypeDef *, std::function<void()>> i2c_master_rx_callback;
    std::map<I2C_HandleTypeDef *, std::function<void()>> i2c_slave_tx_callback;
    std::map<I2C_HandleTypeDef *, std::function<void()>> i2c_slave_rx_callback;
    std::map<I2C_HandleTypeDef *, std::function<void()>> i2c_error_callback;
}

void setI2CMasterTxCallback(I2C_HandleTypeDef *hi2c, std::function<void()> function) noexcept {
    i2c_master_tx_callback[hi2c] = function;
}

void setI2CMasterRxCallback(I2C_HandleTypeDef *hi2c, std::function<void()> function) noexcept {
    i2c_master_rx_callback[hi2c] = function;
}

void setI2CSlaveTxCallback(I2C_HandleTypeDef *hi2c, std::function<void()> function) noexcept {
    i2c_slave_tx_callback[hi2c] = function;
}

void setI2CSlaveRxCallback(I2C_HandleTypeDef *hi2c, std::function<void()> function) noexcept {
    i2c_slave_rx_callback[hi2c] = function;
}

void setI2CErrorCallback(I2C_HandleTypeDef *hi2c, std::function<void()> function) noexcept {
    i2c_error_callback[hi2c] = function;
}

void setI2CMasterTxCallback(I2C_HandleTypeDef &hi2c, std::function<void()> function) noexcept {
    setI2CMasterTxCallback(&hi2c, function);
}

void setI2CMasterRxCallback(I2C_HandleTypeDef &hi2c, std::function<void()> function) noexcept {
    setI2CMasterRxCallback(&hi2c, function);
}

void setI2CSlaveTxCallback(I2C_HandleTypeDef &hi2c, std::function<void()> function) noexcept {
    setI2CSlaveTxCallback(&hi2c, function);
}

void setI2CSlaveRxCallback(I2C_HandleTypeDef &hi2c, std::function<void()> function) noexcept {
    setI2CSlaveRxCallback(&hi2c, function);
}

void setI2CErrorCallback(I2C_HandleTypeDef &hi2c, std::function<void()> function) noexcept {
    setI2CErrorCallback(&hi2c, function);
}

void runI2CMasterTxCallback(I2C_HandleTypeDef *hi2c) noexcept {
    if(halex::map_contains(halex::i2c_master_tx_callback, hi2c)) {
        halex::i2c_master_tx_callback[hi2c]();
    }
}

void runI2CMasterRxCallback(I2C_HandleTypeDef *hi2c) noexcept {
    if(halex::map_contains(halex::i2c_master_rx_callback, hi2c)) {
        halex::i2c_master_rx_callback[hi2c]();
    }
}

void runI2CSlaveTxCallback(I2C_HandleTypeDef *hi2c) noexcept {
    if(halex::map_contains(halex::i2c_slave_tx_callback, hi2c)) {
        halex::i2c_slave_tx_callback[hi2c]();
    }
}

void runI2CSlaveRxCallback(I2C_HandleTypeDef *hi2c) noexcept {
    if(halex::map_contains(halex::i2c_slave_rx_callback, hi2c)) {
        halex::i2c_slave_rx_callback[hi2c]();
    }
}

void runI2CErrorCallback(I2C_HandleTypeDef *hi2c) noexcept {
    if(halex::map_contains(halex::i2c_error_callback, hi2c)) {
        halex::i2c_error_callback[hi2c]();
    }
}

void runI2CMasterTxCallback(I2C_HandleTypeDef &hi2c) noexcept {
    runI2CMasterTxCallback(&hi2c);
}

void runI2CMasterRxCallback(I2C_HandleTypeDef &hi2c) noexcept {
    runI2CMasterRxCallback(&hi2c);
}

void runI2CSlaveTxCallback(I2C_HandleTypeDef &hi2c) noexcept {
    runI2CSlaveTxCallback(&hi2c);
}

void runI2CSlaveRxCallback(I2C_HandleTypeDef &hi2c) noexcept {
    runI2CSlaveRxCallback(&hi2c);
}

void runI2CErrorCallback(I2C_HandleTypeDef &hi2c) noexcept {
    runI2CErrorCallback(&hi2c);
}

} // namespace halex

#endif // CONFIG_DISABLE_MODULE_I2C
