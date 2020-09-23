#ifndef HAL_EXTENSION_USART_UART_HPP
#define HAL_EXTENSION_USART_UART_HPP

#ifndef CONFIG_DISABLE_MODULE_USART

#include "usart.h"

template<class T>
class UART {
private:
    UART_HandleTypeDef *huart;
public:
    UART(){}

    UART(UART_HandleTypeDef &huart): huart(&huart){

    }

    HAL_StatusTypeDef transmit(const T &data, uint32_t timeout){
        return HAL_UART_Transmit(huart, (uint8_t *) &data, sizeof(T), timeout);
    }

    HAL_StatusTypeDef receive(T &data, uint32_t timeout){
        return HAL_UART_Receive(huart, (uint8_t *) &data, sizeof(T), timeout);
    }
};

#endif // CONFIG_DISABLE_MODULE_USART

#endif // HAL_EXTENSION_USART_UART_HPP
