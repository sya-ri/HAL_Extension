#ifndef HAL_EXTENSION_USART_HPP
#define HAL_EXTENSION_USART_HPP

#ifndef CONFIG_DISABLE_MODULE_USART

#include "usart.h"
#include <queue>


#ifndef CONFIG_DISABLE_EX_CALLBACK
class UART_Logger_IT {
private:
    UART_HandleTypeDef *huart;
    std::queue<std::string> buffer;
    bool isBusy = false;
    void checkBuffer();
public:
    UART_Logger_IT();
    UART_Logger_IT(UART_HandleTypeDef &huart);
    void print(std::string text);
    void print(const char* text);
    void println(std::string text);
    void println(const char* text);
};
#endif // CONFIG_DISABLE_EX_CALLBACK

#endif // CONFIG_DISABLE_MODULE_USART

#endif // HAL_EXTENSION_USART_HPP
