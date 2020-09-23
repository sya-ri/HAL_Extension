#ifndef HAL_EXTENSION_USART_UART_IT_HPP
#define HAL_EXTENSION_USART_UART_IT_HPP

#ifndef CONFIG_DISABLE_MODULE_USART

#include "usart.h"
#include "HAL_Extension_usart_callback.hpp"

template<class T>
class UART_IT {
private:
    UART_HandleTypeDef *huart;
public:
    UART_IT(){}

    UART_IT(UART_HandleTypeDef &huart): huart(&huart){

    }

    HAL_StatusTypeDef transmit(const T &data){
        return HAL_UART_Transmit_IT(huart, (uint8_t *) &data, sizeof(T));
    }

    HAL_StatusTypeDef receive(T &data){
        return HAL_UART_Receive_IT(huart, (uint8_t *) &data, sizeof(T));
    }

#ifndef CONFIG_DISABLE_EX_CALLBACK
    void setTxCallback(std::function<void()> function){
        setUARTTxCallback(huart, function);
    }

    void setRxCallback(std::function<void()> function){
        setUARTRxCallback(huart, function);
    }

    void setErrorCallback(std::function<void()> function){
        setErrorCallback(huart, function);
    }
#endif // CONFIG_DISABLE_EX_CALLBACK
};

#endif // HAL_EXTENSION_USART_UART_IT_HPP
