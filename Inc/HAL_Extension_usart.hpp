#ifndef HAL_EXTENSION_UART_HPP
#define HAL_EXTENSION_UART_HPP

#ifndef CONFIG_DISABLE_MODULE_USART

#include "usart.h"
#include <map>
#include <functional>
#include <queue>

#ifndef CONFIG_DISABLE_EX_CALLBACK
extern std::map<UART_HandleTypeDef *, std::function<void()>> __uart_tx_callback;
extern std::map<UART_HandleTypeDef *, std::function<void()>> __uart_rx_callback;
extern std::map<UART_HandleTypeDef *, std::function<void()>> __uart_error_callback;
#endif // CONFIG_DISABLE_EX_CALLBACK

template<class T>
class UART {
private:
    UART_HandleTypeDef *huart;
public:
    UART(){}

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
    UART_IT(){}

    UART_IT(UART_HandleTypeDef &huart): huart(&huart){

    }

    HAL_StatusTypeDef transmit(const T &data){
        return HAL_UART_Transmit_IT(huart, (uint8_t *) &data, sizeof(T));
    }

    HAL_StatusTypeDef receive(T &data){
        return HAL_UART_Receive_IT(huart, (uint8_t *) &data, sizeof(T));
    }

#ifndef CONFIG_DISABLE_EX_CALLBACK
    void setTxCallback(std::function<void()> function){
        __uart_tx_callback[huart] = function;
    }

    void setRxCallback(std::function<void()> function){
        __uart_rx_callback[huart] = function;
    }

    void setErrorCallback(std::function<void()> function){
        __uart_error_callback[huart] = function;
    }
#endif // CONFIG_DISABLE_EX_CALLBACK
};

template<class T>
class UART_DMA {
private:
    UART_HandleTypeDef *huart;
    T *data;
public:
    UART_DMA(){}

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

#ifndef CONFIG_DISABLE_EX_CALLBACK
    void setTxCallback(std::function<void()> function){
        __uart_tx_callback[huart] = function;
    }

    void setRxCallback(std::function<void()> function){
        __uart_rx_callback[huart] = function;
    }

    void setErrorCallback(std::function<void()> function){
        __uart_error_callback[huart] = function;
    }
#endif // CONFIG_DISABLE_EX_CALLBACK
};

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

#endif // HAL_EXTENSION_UART_HPP
