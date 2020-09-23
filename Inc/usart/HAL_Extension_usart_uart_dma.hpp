#ifndef HAL_EXTENSION_USART_UART_DMA_HPP
#define HAL_EXTENSION_USART_UART_DMA_HPP

#ifndef CONFIG_DISABLE_MODULE_USART

#include "usart.h"
#include "HAL_Extension_usart_callback.hpp"

template<class T>
class UART_DMA {
private:
    UART_HandleTypeDef *huart;
    T *data;
public:
    UART_DMA(){}

    UART_DMA(UART_HandleTypeDef &huart, T &data): huart(&huart), data(&data){

    }

    HAL_StatusTypeDef startTransmit(){
        return HAL_UART_Transmit_DMA(huart, (uint8_t *) data, sizeof(T));
    }

    HAL_StatusTypeDef startReceive(){
        return HAL_UART_Receive_DMA(huart, (uint8_t *) data, sizeof(T));
    }

    HAL_StatusTypeDef pause(){
        return HAL_UART_DMAPause(huart);
    }

    HAL_StatusTypeDef resume(){
        return HAL_UART_DMAResume(huart);
    }

    HAL_StatusTypeDef stop(){
        return HAL_UART_DMAStop(huart);
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

#endif // CONFIG_DISABLE_MODULE_USART

#endif // HAL_EXTENSION_USART_UART_DMA_HPP
