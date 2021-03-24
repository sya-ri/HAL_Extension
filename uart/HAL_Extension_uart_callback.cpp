#ifndef CONFIG_DISABLE_MODULE_UART

#ifndef CONFIG_DISABLE_EX_CALLBACK

#include "uart/HAL_Extension_uart_callback.hpp"
#include <map>
#include "util/HAL_Extension_util_function.hpp"

namespace halex {

namespace {
    std::map<UART_HandleTypeDef *, std::function<void()>> uart_tx_callback;
    std::map<UART_HandleTypeDef *, std::function<void()>> uart_rx_callback;
    std::map<UART_HandleTypeDef *, std::function<void()>> uart_error_callback;
}

void setUARTTxCallback(UART_HandleTypeDef *huart, std::function<void()> function) {
    uart_tx_callback[huart] = function;
}

void setUARTRxCallback(UART_HandleTypeDef *huart, std::function<void()> function) {
    uart_rx_callback[huart] = function;
}

void setUARTErrorCallback(UART_HandleTypeDef *huart, std::function<void()> function) {
    uart_error_callback[huart] = function;
}

void setUARTTxCallback(UART_HandleTypeDef &huart, std::function<void()> function) {
    setUARTTxCallback(&huart, function);
}

void setUARTRxCallback(UART_HandleTypeDef &huart, std::function<void()> function) {
    setUARTRxCallback(&huart, function);
}

void setUARTErrorCallback(UART_HandleTypeDef &huart, std::function<void()> function) {
    setUARTErrorCallback(&huart, function);
}

} // namespace halex

#ifdef CONFIG_USE_HALF_CALLBACK_UART
void HAL_UART_TxHalfCpltCallback(UART_HandleTypeDef *huart) {
#else  // CONFIG_USE_HALF_CALLBACK_UART
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart) {
#endif // CONFIG_USE_HALF_CALLBACK_UART
    if(halex::map_contains(halex::uart_tx_callback, huart)) {
        halex::uart_tx_callback[huart]();
    }
}

#ifdef CONFIG_USE_HALF_CALLBACK_UART
void HAL_UART_RxHalfCpltCallback(UART_HandleTypeDef *huart) {
#else  // CONFIG_USE_HALF_CALLBACK_UART
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
#endif // CONFIG_USE_HALF_CALLBACK_UART
    if(halex::map_contains(halex::uart_rx_callback, huart)) {
        halex::uart_rx_callback[huart]();
    }
}

void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart) {
    if(halex::map_contains(halex::uart_error_callback, huart)) {
        halex::uart_error_callback[huart]();
    }
}
#endif // CONFIG_DISABLE_EX_CALLBACK

#endif // CONFIG_DISABLE_MODULE_UART
