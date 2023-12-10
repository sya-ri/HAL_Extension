#ifndef CONFIG_DISABLE_MODULE_UART

#include "uart/callback.hpp"
#include <map>
#include "util/function.hpp"

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

void runUARTTxCallback(UART_HandleTypeDef *huart) {
    if(halex::map_contains(halex::uart_tx_callback, huart)) {
        halex::uart_tx_callback[huart]();
    }
}

void runUARTRxCallback(UART_HandleTypeDef *huart) {
    if(halex::map_contains(halex::uart_rx_callback, huart)) {
        halex::uart_rx_callback[huart]();
    }
}

void runUARTErrorCallback(UART_HandleTypeDef *huart) {
    if(halex::map_contains(halex::uart_error_callback, huart)) {
        halex::uart_error_callback[huart]();
    }
}

void runUARTTxCallback(UART_HandleTypeDef &huart) {
    runUARTTxCallback(&huart);
}

void runUARTRxCallback(UART_HandleTypeDef &huart) {
    runUARTRxCallback(&huart);
}

void runUARTErrorCallback(UART_HandleTypeDef &huart) {
    runUARTErrorCallback(&huart);
}

} // namespace halex

#endif // CONFIG_DISABLE_MODULE_UART
