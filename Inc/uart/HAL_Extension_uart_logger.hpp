#ifndef HAL_EXTENSION_UART_LOGGER_HPP
#define HAL_EXTENSION_UART_LOGGER_HPP

#ifndef CONFIG_DISABLE_MODULE_UART

#include "usart.h"
#include <string>

class UART_Logger {
private:
    UART_HandleTypeDef *huart;
    uint32_t timeout;
public:
    UART_Logger();
    UART_Logger(UART_HandleTypeDef &huart, uint32_t timeout = 0x0F);
    void print(std::string text) const noexcept;
    void print(const char* text) const noexcept;
    void println(std::string text) const noexcept;
    void println(const char* text) const noexcept;
};

#endif // CONFIG_DISABLE_MODULE_UART

#endif // HAL_EXTENSION_UART_LOGGER_HPP
