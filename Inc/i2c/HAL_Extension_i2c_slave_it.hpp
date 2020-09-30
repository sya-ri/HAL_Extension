#ifndef HAL_EXTENSION_I2C_SLAVE_IT_HPP
#define HAL_EXTENSION_I2C_SLAVE_IT_HPP

#ifndef CONFIG_DISABLE_MODULE_I2C

#include "i2c.h"
#include "HAL_Extension_i2c_callback.hpp"
#include "HAL_Extension_i2c_function_slave_transmit.hpp"
#include "HAL_Extension_i2c_function_slave_receive.hpp"

namespace halex {

template<class T>
class I2C_Slave_IT {
private:
    I2C_HandleTypeDef* hi2c;
    uint8_t address;
public:
    I2C_Slave_IT(){}

    I2C_Slave_IT(I2C_HandleTypeDef *hi2c, uint8_t address = 0x00): hi2c(hi2c), address(address) {

    }

    I2C_Slave_IT(I2C_HandleTypeDef &hi2c, uint8_t address = 0x00): I2C_Slave_IT(&hi2c, address) {

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

    HAL_StatusTypeDef transmit(const T &data) const noexcept {
        return i2cSlaveTransmit_IT(hi2c, data);
    }

    HAL_StatusTypeDef receive(T &data) const noexcept {
        return i2cSlaveReceive_IT(hi2c, data);
    }

#ifndef CONFIG_DISABLE_EX_CALLBACK
    void setTxCallback(std::function<void()> function) noexcept {
        setI2CSlaveTxCallback(hi2c, function);
    }

    void setRxCallback(std::function<void()> function) noexcept {
        setI2CSlaveRxCallback(hi2c, function);
    }

    void setErrorCallback(std::function<void()> function) noexcept {
        setI2CErrorCallback(hi2c, function);
    }
#endif // CONFIG_DISABLE_EX_CALLBACK
};

} // namespace halex

#endif // CONFIG_DISABLE_MODULE_I2C

#endif // HAL_EXTENSION_I2C_SLAVE_IT_HPP
