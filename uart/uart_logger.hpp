#ifndef HAL_EXTENSION_UART_LOGGER_HPP
#define HAL_EXTENSION_UART_LOGGER_HPP

#if __has_include("usart.h")

#include "usart.h"
#include <string>

namespace halex {

class UART_Logger {
private:
    UART_HandleTypeDef *huart;
    uint32_t timeout;
public:
    UART_Logger();
    UART_Logger(UART_HandleTypeDef *huart, uint32_t timeout = 0x0F);
    UART_Logger(UART_HandleTypeDef &huart, uint32_t timeout = 0x0F);
    void print(std::string text) const noexcept;
    void print(const char* text) const noexcept;
    void println(std::string text) const noexcept;
    void println(const char* text) const noexcept;
};

} // namespace halex

#endif // __has_include

#endif // HAL_EXTENSION_UART_LOGGER_HPP
