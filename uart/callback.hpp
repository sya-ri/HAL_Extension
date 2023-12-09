#ifndef HAL_EXTENSION_UART_CALLBACK_HPP
#define HAL_EXTENSION_UART_CALLBACK_HPP

#if __has_include("usart.h")

#include "usart.h"
#include <functional>

namespace halex {

void setUARTTxCallback(UART_HandleTypeDef *huart, std::function<void()> function);
void setUARTRxCallback(UART_HandleTypeDef *huart, std::function<void()> function);
void setUARTErrorCallback(UART_HandleTypeDef *huart, std::function<void()> function);
void setUARTTxCallback(UART_HandleTypeDef &huart, std::function<void()> function);
void setUARTRxCallback(UART_HandleTypeDef &huart, std::function<void()> function);
void setUARTErrorCallback(UART_HandleTypeDef &huart, std::function<void()> function);
void runUARTTxCallback(UART_HandleTypeDef *huart);
void runUARTRxCallback(UART_HandleTypeDef *huart);
void runUARTErrorCallback(UART_HandleTypeDef *huart);
void runUARTTxCallback(UART_HandleTypeDef &huart);
void runUARTRxCallback(UART_HandleTypeDef &huart);
void runUARTErrorCallback(UART_HandleTypeDef &huart);

} // namespace halex

#endif // __has_include

#endif // HAL_EXTENSION_UART_CALLBACK_HPP
