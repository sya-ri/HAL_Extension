#ifndef HAL_EXTENSION_UART_DMA_HPP
#define HAL_EXTENSION_UART_DMA_HPP

#if __has_include("usart.h")

#include "usart.h"
#include "callback.hpp"
#include "function_transmit.hpp"
#include "function_receive.hpp"

namespace halex {

template<class T>
class UART_DMA {
private:
    UART_HandleTypeDef *huart;
    T *data;
public:
    UART_DMA() {}

    UART_DMA(UART_HandleTypeDef *huart, T &data): huart(huart), data(&data) {

    }

    UART_DMA(UART_HandleTypeDef &huart, T &data): UART_DMA(&huart, data) {

    }

    HAL_StatusTypeDef startTransmit() noexcept {
        return uartTransmit_DMA(huart, data);
    }

    HAL_StatusTypeDef startReceive() noexcept {
        return uartReceive_DMA(huart, data);
    }

    HAL_StatusTypeDef pause() noexcept {
        return HAL_UART_DMAPause(huart);
    }

    HAL_StatusTypeDef resume() noexcept {
        return HAL_UART_DMAResume(huart);
    }

    HAL_StatusTypeDef stop() noexcept {
        return HAL_UART_DMAStop(huart);
    }

    void setTxCallback(std::function<void()> function) noexcept {
        setUARTTxCallback(huart, function);
    }

    void setRxCallback(std::function<void()> function) noexcept {
        setUARTRxCallback(huart, function);
    }

    void setErrorCallback(std::function<void()> function) noexcept {
        setErrorCallback(huart, function);
    }
};

} // namespace halex

#endif // __has_include

#endif // HAL_EXTENSION_UART_DMA_HPP
