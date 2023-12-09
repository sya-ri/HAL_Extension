#include "uart/uart_logger_it.hpp"
#include "uart/callback.hpp"

namespace halex {

UART_Logger_IT::UART_Logger_IT() {}

UART_Logger_IT::UART_Logger_IT(UART_HandleTypeDef *huart): huart(huart) {
    setUARTTxCallback(huart, [this]{ itTxCallback(); });
}

UART_Logger_IT::UART_Logger_IT(UART_HandleTypeDef &huart): UART_Logger_IT(&huart) {
d
}

void UART_Logger_IT::checkBuffer() noexcept {
    auto front = buffer.front();
    buffer.pop();
    HAL_UART_Transmit_IT(huart, (uint8_t *) front.c_str(), front.size());
}

void UART_Logger_IT::itTxCallback() noexcept {
    if (buffer.empty()) {
        isBusy = false;
    } else {
        checkBuffer();
    }
}

void UART_Logger_IT::print(std::string text) noexcept {
    buffer.push(text);
    if(isBusy) return;
    checkBuffer();
    isBusy = true;
}

void UART_Logger_IT::print(const char* text) noexcept {
    print(std::string(text));
}

void UART_Logger_IT::println(std::string text) noexcept {
    text.append("\r\n");
    print(text);
}

void UART_Logger_IT::println(const char* text) noexcept {
    println(std::string(text));
}

} // namespace halex
