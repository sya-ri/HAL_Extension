#ifndef HAL_EXTENSION_UART_LOGGER_IT_HPP
#define HAL_EXTENSION_UART_LOGGER_IT_HPP

#if __has_include("usart.h")

#include "usart.h"
#include <string>
#include <queue>

namespace halex {

class UART_Logger_IT {
private:
    UART_HandleTypeDef *huart;
    std::queue<std::string> buffer;
    bool isBusy = false;
    void checkBuffer() noexcept;
    void itTxCallback() noexcept;
public:
    UART_Logger_IT();
    UART_Logger_IT(UART_HandleTypeDef *huart);
    UART_Logger_IT(UART_HandleTypeDef &huart);
    void print(std::string text) noexcept;
    void print(const char* text) noexcept;
    void println(std::string text) noexcept;
    void println(const char* text) noexcept;
};

} // namespace halex

#endif // __has_include

#endif // HAL_EXTENSION_UART_LOGGER_IT_HPP
