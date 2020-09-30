#ifndef HAL_EXTENSION_UART_DMA_HPP
#define HAL_EXTENSION_UART_DMA_HPP

#ifndef CONFIG_DISABLE_MODULE_UART

#include "usart.h"
#include "HAL_Extension_uart_callback.hpp"
#include "HAL_Extension_uart_function_transmit.hpp"
#include "HAL_Extension_uart_function_receive.hpp"

namespace halex {

template<class T>
class UART_DMA {
private:
    UART_HandleTypeDef *huart;
    T *data;
public:
    UART_DMA() {}

    UART_DMA(UART_HandleTypeDef &huart, T &data): huart(&huart), data(&data) {

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

#ifndef CONFIG_DISABLE_EX_CALLBACK
    void setTxCallback(std::function<void()> function) noexcept {
        setUARTTxCallback(huart, function);
    }

    void setRxCallback(std::function<void()> function) noexcept {
        setUARTRxCallback(huart, function);
    }

    void setErrorCallback(std::function<void()> function) noexcept {
        setErrorCallback(huart, function);
    }
#endif // CONFIG_DISABLE_EX_CALLBACK
};

} // namespace halex

#endif // CONFIG_DISABLE_MODULE_UART

#endif // HAL_EXTENSION_UART_DMA_HPP
