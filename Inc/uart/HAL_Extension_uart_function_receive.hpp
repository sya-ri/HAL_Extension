#ifndef HAL_EXTENSION_UART_FUNCTION_RECEIVE_HPP
#define HAL_EXTENSION_UART_FUNCTION_RECEIVE_HPP

#ifndef CONFIG_DISABLE_MODULE_UART

#include "usart.h"

template <class T>
HAL_StatusTypeDef uartReceive(UART_HandleTypeDef *huart, T &data, uint32_t timeout) noexcept {
    return HAL_UART_Receive(huart, (uint8_t *) &data, sizeof(T), timeout);
}

template <class T>
HAL_StatusTypeDef uartReceive(UART_HandleTypeDef &huart, T &data, uint32_t timeout) noexcept {
    return uartReceive(&huart, data, timeout);
}

template <class T>
HAL_StatusTypeDef uartReceive_IT(UART_HandleTypeDef *huart, T &data) noexcept {
    return HAL_UART_Receive_IT(huart, (uint8_t *) &data, sizeof(T));
}

template <class T>
HAL_StatusTypeDef uartReceive_IT(UART_HandleTypeDef &huart, T &data) noexcept {
    return uartReceive_IT(&huart, data);
}

template <class T>
HAL_StatusTypeDef uartReceive_DMA(UART_HandleTypeDef *huart, T &data) noexcept {
    return HAL_UART_Receive_DMA(huart, (uint8_t *) &data, sizeof(T));
}

template <class T>
HAL_StatusTypeDef uartReceive_DMA(UART_HandleTypeDef &huart, T &data) noexcept {
    return uartReceive_DMA(&huart, data);
}

#endif // CONFIG_DISABLE_MODULE_UART

#endif // HAL_EXTENSION_UART_FUNCTION_RECEIVE_HPP
