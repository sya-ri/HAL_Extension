#ifndef CONFIG_DISABLE_MODULE_UART

#include "uart/HAL_Extension_uart_logger_it.hpp"
#include "uart/HAL_Extension_uart_callback.hpp"

namespace halex {

UART_Logger_IT::UART_Logger_IT() {}

UART_Logger_IT::UART_Logger_IT(UART_HandleTypeDef *huart): huart(huart) {
#ifndef CONFIG_DISABLE_EX_CALLBACK
    setUARTTxCallback(huart, [this]{ itTxCallback(); });
#endif
}

UART_Logger_IT::UART_Logger_IT(UART_HandleTypeDef &huart): UART_Logger_IT(&huart) {

}

void UART_Logger_IT::checkBuffer() noexcept {
    auto front = buffer.front();
    buffer.pop();
    HAL_UART_Transmit_IT(huart, (uint8_t *) front.c_str(), front.size());
}

#ifndef CONFIG_DISABLE_EX_CALLBACK
void UART_Logger_IT::itTxCallback() noexcept {
#else
void UART_Logger_IT::itTxCallback(UART_HandleTypeDef *huart) noexcept {
	if(this->huart != huart) return;
#endif // CONFIG_DISABLE_EX_CALLBACK
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

#endif // CONFIG_DISABLE_MODULE_UART
