#ifndef HAL_EXTENSION_I2C_SLAVE_DMA_HPP
#define HAL_EXTENSION_I2C_SLAVE_DMA_HPP

#ifndef CONFIG_DISABLE_MODULE_I2C

#include "i2c.h"
#include "callback.hpp"
#include "function_slave_transmit.hpp"
#include "function_slave_receive.hpp"

namespace halex {

template<class T>
class I2C_Slave_DMA {
private:
    I2C_HandleTypeDef* hi2c;
    uint8_t address;
    T *data;
public:
    I2C_Slave_DMA() {}

    I2C_Slave_DMA(I2C_HandleTypeDef *hi2c, T &data, uint8_t address = 0x00): hi2c(hi2c), data(&data), address(address) {

    }

    I2C_Slave_DMA(I2C_HandleTypeDef &hi2c, T &data, uint8_t address = 0x00): I2C_Slave_DMA(&hi2c, data, address) {

    }

    void init() noexcept {
        HAL_I2C_DeInit(hi2c);
        hi2c->Init.OwnAddress1 = address << 1;
        HAL_I2C_Init(hi2c);
    }

    void init(uint8_t address) noexcept {
        this->address = address;
        init();
    }

#ifndef CONFIG_DISABLE_MODULE_GPIO
    void init(DIPSwitch builder) noexcept {
        init(builder.getAddress());
    }
#endif // CONFIG_DISABLE_MODULE_GPIO

    HAL_StatusTypeDef startTransmit() noexcept {
        return i2cSlaveTransmit_DMA(hi2c, data);
    }

    HAL_StatusTypeDef startReceive() noexcept {
        return i2cSlaveReceive_DMA(hi2c, data);
    }

    void setTxCallback(std::function<void()> function) noexcept {
        setI2CSlaveTxCallback(hi2c, function);
    }

    void setRxCallback(std::function<void()> function) noexcept {
        setI2CSlaveRxCallback(hi2c, function);
    }

    void setErrorCallback(std::function<void()> function) noexcept {
        setI2CErrorCallback(hi2c, function);
    }
};

} // namespace halex

#endif // CONFIG_DISABLE_MODULE_I2C

#endif // HAL_EXTENSION_I2C_SLAVE_DMA_HPP
