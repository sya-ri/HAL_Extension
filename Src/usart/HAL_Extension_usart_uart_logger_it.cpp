#ifndef CONFIG_DISABLE_MODULE_USART

#ifndef CONFIG_DISABLE_EX_CALLBACK

#include "usart/HAL_Extension_usart_uart_logger_it.hpp"
#include "usart/HAL_Extension_usart_callback.hpp"

UART_Logger_IT::UART_Logger_IT(){}

UART_Logger_IT::UART_Logger_IT(UART_HandleTypeDef &huart): huart(&huart){
    setUARTTxCallback(&huart, [this]{
        if (buffer.empty()) {
            isBusy = false;
        } else {
            checkBuffer();
        }
    });
}

void UART_Logger_IT::checkBuffer(){
    auto front = buffer.front();
    buffer.pop();
    HAL_UART_Transmit_IT(huart, (uint8_t *) front.c_str(), front.size());
}

void UART_Logger_IT::print(std::string text){
    buffer.push(text);
    if(isBusy) return;
    checkBuffer();
    isBusy = true;
}

void UART_Logger_IT::print(const char* text){
    print(std::string(text));
}

void UART_Logger_IT::println(std::string text){
    text.append("\r\n");
    print(text);
}

void UART_Logger_IT::println(const char* text){
    println(std::string(text));
}

#endif // CONFIG_DISABLE_EX_CALLBACK

#endif // CONFIG_DISABLE_MODULE_USART