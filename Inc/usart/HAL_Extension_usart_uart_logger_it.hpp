#ifndef HAL_EXTENSION_USART_UART_LOGGER_IT_HPP
#define HAL_EXTENSION_USART_UART_LOGGER_IT_HPP

#ifndef CONFIG_DISABLE_MODULE_USART

#include "usart.h"
#include <string>
#include <queue>

class UART_Logger_IT {
private:
    UART_HandleTypeDef *huart;
    std::queue<std::string> buffer;
    bool isBusy = false;
    void checkBuffer() noexcept;

#ifndef CONFIG_DISABLE_EX_CALLBACK
    void itTxCallback() noexcept;
#endif // CONFIG_DISABLE_EX_CALLBACK
public:
    UART_Logger_IT();
    UART_Logger_IT(UART_HandleTypeDef &huart);
    void print(std::string text) noexcept;
    void print(const char* text) noexcept;
    void println(std::string text) noexcept;
    void println(const char* text) noexcept;

#ifdef CONFIG_DISABLE_EX_CALLBACK
    void itTxCallback(UART_HandleTypeDef *huart) noexcept;
#endif // CONFIG_DISABLE_EX_CALLBACK
};

#endif // CONFIG_DISABLE_MODULE_USART

#endif // HAL_EXTENSION_USART_UART_LOGGER_IT_HPP
