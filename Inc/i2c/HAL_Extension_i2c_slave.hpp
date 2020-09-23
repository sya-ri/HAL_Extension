#ifndef HAL_EXTENSION_I2C_SLAVE_HPP
#define HAL_EXTENSION_I2C_SLAVE_HPP

#ifndef CONFIG_DISABLE_MODULE_I2C

#include "i2c.h"

template<class T>
class I2C_Slave {
private:
    I2C_HandleTypeDef* hi2c;
    uint8_t address;
public:
    I2C_Slave(){}

    I2C_Slave(I2C_HandleTypeDef &hi2c, uint8_t address = 0x00): hi2c(&hi2c), address(address) {

    }

    void init(){
        HAL_I2C_DeInit(hi2c);
        hi2c->Init.OwnAddress1 = address << 1;
        HAL_I2C_Init(hi2c);
    }

    void init(const uint8_t address){
        this->address = address;
        init();
    }

#ifdef __gpio_H
    void init(DIPSwitch builder){
        init(builder.getAddress());
    }
#endif // __gpio_H

    HAL_StatusTypeDef transmit(const T &data, uint32_t timeout){
        return HAL_I2C_Slave_Transmit(hi2c, (uint8_t *) &data, sizeof(T), timeout);
    }

    HAL_StatusTypeDef receive(T &data, uint32_t timeout){
        return HAL_I2C_Slave_Receive(hi2c, (uint8_t *) &data, sizeof(T), timeout);
    }
};

#endif // CONFIG_DISABLE_MODULE_I2C

#endif // HAL_EXTENSION_I2C_SLAVE_HPP
