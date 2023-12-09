#ifndef HAL_EXTENSION_UART_FUNCTION_TRANSMIT_HPP
#define HAL_EXTENSION_UART_FUNCTION_TRANSMIT_HPP

#if __has_include("usart.h")

#include "usart.h"

namespace halex {

template <class T>
HAL_StatusTypeDef uartTransmit(UART_HandleTypeDef *huart, const T &data, uint32_t timeout) noexcept {
    return HAL_UART_Transmit(huart, (uint8_t *) &data, sizeof(T), timeout);
}

template <class T>
HAL_StatusTypeDef uartTransmit(UART_HandleTypeDef &huart, const T &data, uint32_t timeout) noexcept {
    return uartTransmit(&huart, data, timeout);
}

template <class T>
HAL_StatusTypeDef uartTransmit_IT(UART_HandleTypeDef *huart, const T &data) noexcept {
    return HAL_UART_Transmit_IT(huart, (uint8_t *) &data, sizeof(T));
}

template <class T>
HAL_StatusTypeDef uartTransmit_IT(UART_HandleTypeDef &huart, const T &data) noexcept {
    return uartTransmit_IT(&huart, data);
}

template <class T>
HAL_StatusTypeDef uartTransmit_DMA(UART_HandleTypeDef *huart, const T &data) noexcept {
    return HAL_UART_Transmit_DMA(huart, (uint8_t *) &data, sizeof(T));
}

template <class T>
HAL_StatusTypeDef uartTransmit_DMA(UART_HandleTypeDef &huart, const T &data) noexcept {
    return uartTransmit_DMA(&huart, data);
}

} // namespace halex

#endif // __has_include

#endif // HAL_EXTENSION_UART_FUNCTION_TRANSMIT_HPP
