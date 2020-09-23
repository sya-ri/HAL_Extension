#ifndef HAL_EXTENSION_USART_CALLBACK_HPP
#define HAL_EXTENSION_USART_CALLBACK_HPP

#ifndef CONFIG_DISABLE_MODULE_USART

#include "usart.h"
#include <functional>

#ifndef CONFIG_DISABLE_EX_CALLBACK
void setUARTTxCallback(UART_HandleTypeDef *huart, std::function<void()> function);
void setUARTRxCallback(UART_HandleTypeDef *huart, std::function<void()> function);
void setUARTErrorCallback(UART_HandleTypeDef *huart, std::function<void()> function);
#endif // CONFIG_DISABLE_EX_CALLBACK

#endif // CONFIG_DISABLE_MODULE_USART

#endif // HAL_EXTENSION_USART_CALLBACK_HPP
