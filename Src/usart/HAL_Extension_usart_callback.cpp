#ifndef CONFIG_DISABLE_MODULE_USART

#ifndef CONFIG_DISABLE_EX_CALLBACK

#include "usart/HAL_Extension_usart_callback.hpp"
#include <map>
#include "HAL_Extension_util.hpp"

namespace {
    std::map<UART_HandleTypeDef *, std::function<void()>> uart_tx_callback;
    std::map<UART_HandleTypeDef *, std::function<void()>> uart_rx_callback;
    std::map<UART_HandleTypeDef *, std::function<void()>> uart_error_callback;
}

void setUARTTxCallback(UART_HandleTypeDef *huart, std::function<void()> function){
    uart_tx_callback[huart] = function;
}

void setUARTRxCallback(UART_HandleTypeDef *huart, std::function<void()> function){
    uart_rx_callback[huart] = function;
}

void setUARTErrorCallback(UART_HandleTypeDef *huart, std::function<void()> function){
    uart_error_callback[huart] = function;
}

#ifdef CONFIG_UART_USE_HALF_CALLBACK
void HAL_UART_TxHalfCpltCallback(UART_HandleTypeDef *huart){
#else  // CONFIG_UART_USE_HALF_CALLBACK
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
#endif // CONFIG_UART_USE_HALF_CALLBACK
    if(map_contains(uart_tx_callback, huart)){
        uart_tx_callback[huart]();
    }
}

#ifdef CONFIG_UART_USE_HALF_CALLBACK
void HAL_UART_RxHalfCpltCallback(UART_HandleTypeDef *huart){
#else  // CONFIG_UART_USE_HALF_CALLBACK
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
#endif // CONFIG_UART_USE_HALF_CALLBACK
    if(map_contains(uart_rx_callback, huart)){
        uart_rx_callback[huart]();
    }
}

void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart){
    if(map_contains(uart_error_callback, huart)){
        uart_error_callback[huart]();
    }
}
#endif // CONFIG_DISABLE_EX_CALLBACK

#endif // CONFIG_DISABLE_MODULE_USART