#ifndef HAL_EXTENSION_UART_HPP
#define HAL_EXTENSION_UART_HPP

#if __has_include("usart.h")

#include "usart.h"
#include "function_transmit.hpp"
#include "function_receive.hpp"

namespace halex {

template<class T>
class UART {
private:
    UART_HandleTypeDef *huart;
public:
    UART() {}

    UART(UART_HandleTypeDef *huart): huart(huart) {

    }

    UART(UART_HandleTypeDef &huart): UART(&huart) {

    }

    HAL_StatusTypeDef transmit(const T &data, uint32_t timeout) const noexcept {
        return uartTransmit(huart, data, timeout);
    }

    HAL_StatusTypeDef receive(T &data, uint32_t timeout) const noexcept {
        return uartReceive(huart, data, timeout);
    }
};

} // namespace halex

#endif // __has_include

#endif // HAL_EXTENSION_UART_HPP
