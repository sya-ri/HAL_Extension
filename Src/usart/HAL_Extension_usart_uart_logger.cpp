#ifndef CONFIG_DISABLE_MODULE_USART

#include "usart/HAL_Extension_usart_uart_logger.hpp"

UART_Logger::UART_Logger(){}

UART_Logger::UART_Logger(UART_HandleTypeDef &huart, uint32_t timeout): huart(&huart), timeout(timeout){

}

void UART_Logger::print(std::string text){
    HAL_UART_Transmit(huart, (uint8_t *) text.c_str(), text.size(), timeout);
}

void UART_Logger::print(const char* text){
    print(std::string(text));
}

void UART_Logger::println(std::string text){
    text.append("\r\n");
    print(text);
}

void UART_Logger::println(const char* text){
    println(text);
}

#endif // CONFIG_DISABLE_MODULE_USART