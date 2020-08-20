#include "HAL_Extension_usart.hpp"
#include "HAL_Extension_util.hpp"

#ifndef CONFIG_DISABLE_EX_CALLBACK
std::map<UART_HandleTypeDef *, std::function<void()>> __uart_tx_callback;
std::map<UART_HandleTypeDef *, std::function<void()>> __uart_rx_callback;
std::map<UART_HandleTypeDef *, std::function<void()>> __uart_error_callback;
#endif // CONFIG_DISABLE_EX_CALLBACK

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

#ifndef CONFIG_DISABLE_EX_CALLBACK
UART_Logger_IT::UART_Logger_IT(){}

UART_Logger_IT::UART_Logger_IT(UART_HandleTypeDef &huart): huart(&huart){
    __uart_tx_callback[&huart] = [this]{
        if (buffer.empty()) {
            isBusy = false;
        } else {
            checkBuffer();
        }
    };
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

#ifdef CONFIG_UART_USE_HALF_CALLBACK
void HAL_UART_TxHalfCpltCallback(UART_HandleTypeDef *huart){
#else  // CONFIG_UART_USE_HALF_CALLBACK
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
#endif // CONFIG_UART_USE_HALF_CALLBACK
    if(map_contains(__uart_tx_callback, huart)){
        __uart_tx_callback[huart]();
    }
}

#ifdef CONFIG_UART_USE_HALF_CALLBACK
void HAL_UART_RxHalfCpltCallback(UART_HandleTypeDef *huart){
#else  // CONFIG_UART_USE_HALF_CALLBACK
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
#endif // CONFIG_UART_USE_HALF_CALLBACK
    if(map_contains(__uart_rx_callback, huart)){
        __uart_rx_callback[huart]();
    }
}

void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart){
    if(map_contains(__uart_error_callback, huart)){
        __uart_error_callback[huart]();
    }
}
#endif // CONFIG_DISABLE_EX_CALLBACK