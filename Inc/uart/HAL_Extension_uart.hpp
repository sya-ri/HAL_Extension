#ifndef HAL_EXTENSION_UART_HPP
#define HAL_EXTENSION_UART_HPP

#ifndef CONFIG_DISABLE_MODULE_UART

#include "usart.h"
#include "HAL_Extension_uart_function_transmit.hpp"
#include "HAL_Extension_uart_function_receive.hpp"

namespace halex {

template<class T>
class UART {
private:
    UART_HandleTypeDef *huart;
public:
    UART(){}

    UART(UART_HandleTypeDef &huart): huart(&huart){

    }

    HAL_StatusTypeDef transmit(const T &data, uint32_t timeout) const noexcept {
        return uartTransmit(huart, data, timeout);
    }

    HAL_StatusTypeDef receive(T &data, uint32_t timeout) const noexcept {
        return uartReceive(huart, data, timeout);
    }
};

} // namespace halex

#endif // CONFIG_DISABLE_MODULE_UART

#endif // HAL_EXTENSION_UART_HPP
