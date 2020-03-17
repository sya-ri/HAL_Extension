#ifndef HAL_EXTENSION_UART_HPP
#define HAL_EXTENSION_UART_HPP
#ifdef __usart_H

#include <map>
#include <functional>
#include <queue>

namespace {
    std::map<UART_HandleTypeDef *, std::function<void()>> __uart_tx_callback;
    std::map<UART_HandleTypeDef *, std::function<void()>> __uart_rx_callback;
    std::map<UART_HandleTypeDef *, std::function<void()>> __uart_error_callback;
}

template<class T>
class UART {
private:
    UART_HandleTypeDef *huart;
public:
    UART(UART_HandleTypeDef &huart): huart(&huart){

    }

    HAL_StatusTypeDef transmit(const T &data, uint32_t timeout){
        return HAL_UART_Transmit(huart, (uint8_t *) &data, sizeof(T), timeout);
    }

    HAL_StatusTypeDef receive(T &data, uint32_t timeout){
        return HAL_UART_Receive(huart, (uint8_t *) &data, sizeof(T), timeout);
    }
};

template<class T>
class UART_IT {
private:
    UART_HandleTypeDef *huart;
public:
    UART_IT(UART_HandleTypeDef &huart): huart(&huart){

    }

    HAL_StatusTypeDef transmit(const T &data){
        return HAL_UART_Transmit_IT(huart, (uint8_t *) &data, sizeof(T));
    }

    HAL_StatusTypeDef receive(T &data){
        return HAL_UART_Receive_IT(huart, (uint8_t *) &data, sizeof(T));
    }

    void setTxCallback(std::function<void()> function){
        __uart_tx_callback[huart] = function;
    }

    void setRxCallback(std::function<void()> function){
        __uart_rx_callback[huart] = function;
    }

    void setErrorCallback(std::function<void()> function){
        __uart_error_callback[huart] = function;
    }
};

template<class T>
class UART_DMA {
private:
    UART_HandleTypeDef *huart;
    T *data;
public:
    UART_DMA(UART_HandleTypeDef &huart, T &data): huart(&huart), data(&data){

    }

    HAL_StatusTypeDef startTransmit(){
        return HAL_UART_Transmit_DMA(huart, (uint8_t *) data, sizeof(T));
    }

    HAL_StatusTypeDef startReceive(){
        return HAL_UART_Receive_DMA(huart, (uint8_t *) data, sizeof(T));
    }

    HAL_StatusTypeDef pause(){
        return HAL_UART_DMAPause(huart);
    }

    HAL_StatusTypeDef resume(){
        return HAL_UART_DMAResume(huart);
    }

    HAL_StatusTypeDef stop(){
        return HAL_UART_DMAStop(huart);
    }

    void setTxCallback(std::function<void()> function){
        __uart_tx_callback[huart] = function;
    }

    void setRxCallback(std::function<void()> function){
        __uart_rx_callback[huart] = function;
    }

    void setErrorCallback(std::function<void()> function){
        __uart_error_callback[huart] = function;
    }
};

class UART_Logger {
private:
    UART_HandleTypeDef *huart;
    uint32_t timeout;
public:
    UART_Logger(UART_HandleTypeDef &huart, uint32_t timeout = 0x0F): huart(&huart), timeout(timeout){

    }

    void print(std::string text){
        HAL_UART_Transmit(huart, (uint8_t *) text.c_str(), text.size(), timeout);
    }

    void print(const char* text){
        print(std::string(text));
    }

    void println(std::string text){
        text.append("\r\n");
        print(text);
    }

    void println(const char* text){
        println(text);
    }
};

class UART_Logger_IT {
private:
    UART_HandleTypeDef *huart;
    std::queue<std::string> buffer;
    bool isBusy = false;

    void checkBuffer(){
        auto front = buffer.front();
        buffer.pop();
        HAL_UART_Transmit_IT(huart, (uint8_t *) front.c_str(), front.size());
    }
public:
    UART_Logger_IT(UART_HandleTypeDef &huart): huart(&huart){
        __uart_tx_callback[&huart] = [this]{
            if (buffer.empty()) {
                isBusy = false;
            } else {
                checkBuffer();
            }
        };
    }

    void print(std::string text){
        buffer.push(text);
        if(isBusy) return;
        checkBuffer();
        isBusy = true;
    }

    void print(const char* text){
        print(std::string(text));
    }

    void println(std::string text){
        text.append("\r\n");
        print(text);
    }

    void println(const char* text){
        println(std::string(text));
    }
};

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

#endif // __usart_H
#endif
