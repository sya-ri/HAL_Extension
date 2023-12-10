#if __has_include("usart.h")

#include "uart/uart_logger.hpp"

namespace halex {

UART_Logger::UART_Logger() {}

UART_Logger::UART_Logger(UART_HandleTypeDef *huart, uint32_t timeout): huart(huart), timeout(timeout) {

}

UART_Logger::UART_Logger(UART_HandleTypeDef &huart, uint32_t timeout): UART_Logger(&huart, timeout) {

}

void UART_Logger::print(std::string text) const noexcept {
    HAL_UART_Transmit(huart, (uint8_t *) text.c_str(), text.size(), timeout);
}

void UART_Logger::print(const char* text) const noexcept {
    print(std::string(text));
}

void UART_Logger::println(std::string text) const noexcept {
    text.append("\r\n");
    print(text);
}

void UART_Logger::println(const char* text) const noexcept {
    println(std::string(text));
}

} // namespace halex

#endif // __has_include
