#ifndef HAL_EXTENSION_I2C_SLAVE_HPP
#define HAL_EXTENSION_I2C_SLAVE_HPP

#ifndef CONFIG_DISABLE_MODULE_I2C

#include "i2c.h"
#include "HAL_Extension_i2c_function_slave_transmit.hpp"
#include "HAL_Extension_i2c_function_slave_receive.hpp"

namespace halex {

template<class T>
class I2C_Slave {
private:
    I2C_HandleTypeDef* hi2c;
    uint8_t address;
public:
    I2C_Slave(){}

    I2C_Slave(I2C_HandleTypeDef &hi2c, uint8_t address = 0x00): hi2c(&hi2c), address(address) {

    }

    void init() noexcept {
        HAL_I2C_DeInit(hi2c);
        hi2c->Init.OwnAddress1 = address << 1;
        HAL_I2C_Init(hi2c);
    }

    void init(const uint8_t address) noexcept {
        this->address = address;
        init();
    }

#ifndef CONFIG_DISABLE_MODULE_GPIO
    void init(DIPSwitch builder) noexcept {
        init(builder.getAddress());
    }
#endif // CONFIG_DISABLE_MODULE_GPIO

    HAL_StatusTypeDef transmit(const T &data, uint32_t timeout) const noexcept {
        return i2cSlaveTransmit(hi2c, data, timeout);
    }

    HAL_StatusTypeDef receive(T &data, uint32_t timeout) const noexcept {
        return i2cSlaveReceive(hi2c, data, timeout);
    }
};

} // namespace halex

#endif // CONFIG_DISABLE_MODULE_I2C

#endif // HAL_EXTENSION_I2C_SLAVE_HPP
