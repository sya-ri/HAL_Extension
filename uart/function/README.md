# function UART

## 目次
- [Transmit](#transmit)
  - [uartTransmit](#uarttransmit)
  - [uartTransmit_IT](#uarttransmit_it)
  - [uartTransmit_DMA](#uarttransmit_dma)
- [Receive](#receive)
  - [uartReceive](#uartreceive)
  - [uartReceive_IT](#uartreceive_it)
  - [uartReceive_DMA](#uartreceive_dma)
- [Callback](#callback)
  - [setUARTTxCallback](#setuarttxcallback)
  - [setUARTRxCallback](#setuartrxcallback)
  - [setErrorCallback](#setuarterrorcallback)

## 関数

### Transmit

##### uartTransmit
> ```c++
> template <class T>
> HAL_StatusTypeDef uartTransmit(
>     UART_HandleTypeDef *huart,
>     const T &data,
>     uint32_t timeout
> ) noexcept;
> ```
> ```c++
> template <class T>
> HAL_StatusTypeDef uartTransmit(
>     UART_HandleTypeDef &huart,
>     const T &data,
>     uint32_t timeout
> ) noexcept;
> ```
> `HAL_UART_Transmit` を実行します

##### uartTransmit_IT
> ```c++
> template <class T>
> HAL_StatusTypeDef uartTransmit_IT(
>     UART_HandleTypeDef *huart,
>     const T &data
> ) noexcept;
> ```
> ```c++
> template <class T>
> HAL_StatusTypeDef uartTransmit_IT(
>     UART_HandleTypeDef &huart,
>     const T &data
> ) noexcept;
> ```
> `HAL_UART_Transmit_IT` を実行します

##### uartTransmit_DMA
> ```c++
> template <class T>
> HAL_StatusTypeDef uartTransmit_DMA(
>     UART_HandleTypeDef *huart,
>     const T &data
> ) noexcept;
> ```
> ```c++
> template <class T>
> HAL_StatusTypeDef uartTransmit_DMA(
>     UART_HandleTypeDef &huart,
>     const T &data
> ) noexcept;
> ```
> `HAL_UART_Transmit_DMA` を実行します

### Receive

##### uartReceive
> ```c++
> template <class T>
> HAL_StatusTypeDef uartReceive(
>     UART_HandleTypeDef *huart,
>     T &data,
>     uint32_t timeout
> ) noexcept;
> ```
> ```c++
> template <class T>
> HAL_StatusTypeDef uartReceive(
>     UART_HandleTypeDef &huart,
>     T &data,
>     uint32_t timeout
> ) noexcept;
> ```
> `HAL_UART_Receive` を実行します

##### uartReceive_IT
> ```c++
> template <class T>
> HAL_StatusTypeDef uartReceive_IT(
>     UART_HandleTypeDef *huart,
>     T &data
> ) noexcept;
> ```
> ```c++
> template <class T>
> HAL_StatusTypeDef uartReceive_IT(
>     UART_HandleTypeDef &huart,
>     T &data
> ) noexcept;
> ```
> `HAL_UART_Receive_IT` を実行します

##### uartReceive_DMA
> ```c++
> template <class T>
> HAL_StatusTypeDef uartReceive_DMA(
>     UART_HandleTypeDef *huart,
>     T &data
> ) noexcept;
> ```
> ```c++
> template <class T>
> HAL_StatusTypeDef uartReceive_DMA(
>     UART_HandleTypeDef &huart,
>     T &data
> ) noexcept;
> ```
> `HAL_UART_Receive_DMA` を実行します

### Callback

##### setUARTTxCallback
> ```c++
> void setUARTTxCallback(
>     UART_HandleTypeDef *huart,
>     std::function<void()> function
> );
> ```
> ```c++
> void setUARTTxCallback(
>     UART_HandleTypeDef &huart,
>     std::function<void()> function
> );
> ```
> `HAL_UART_TxCpltCallback` や `HAL_UART_TxHalfCpltCallback` の処理を変更します

##### setUARTRxCallback
> ```c++
> void setUARTRxCallback(
>     UART_HandleTypeDef *huart,
>     std::function<void()> function
> );
> ```
> ```c++
> void setUARTRxCallback(
>     UART_HandleTypeDef &huart,
>     std::function<void()> function
> );
> ```
> `HAL_UART_RxCpltCallback` や `HAL_UART_RxHalfCpltCallback` の処理を変更します

##### setUARTErrorCallback
> ```c++
> void setUARTErrorCallback(
>     UART_HandleTypeDef *huart,
>     std::function<void()> function
> );
> ```
> ```c++
> void setUARTErrorCallback(
>     UART_HandleTypeDef &huart,
>     std::function<void()> function
> );
> ```
> `HAL_UART_ErrorCallback` の処理を変更します

[<< 戻る](../README.md)