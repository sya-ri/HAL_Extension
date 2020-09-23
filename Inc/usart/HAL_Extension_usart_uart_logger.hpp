#ifndef HAL_EXTENSION_USART_UART_LOGGER_HPP
#define HAL_EXTENSION_USART_UART_LOGGER_HPP

#ifndef CONFIG_DISABLE_MODULE_USART

#include "usart.h"
#include <string>

class UART_Logger {
private:
    UART_HandleTypeDef *huart;
    uint32_t timeout;
public:
    UART_Logger();
    UART_Logger(UART_HandleTypeDef &huart, uint32_t timeout = 0x0F);
    void print(std::string text);
    void print(const char* text);
    void println(std::string text);
    void println(const char* text);
};

#endif // CONFIG_DISABLE_MODULE_USART

#endif // HAL_EXTENSION_USART_UART_LOGGER_HPP
