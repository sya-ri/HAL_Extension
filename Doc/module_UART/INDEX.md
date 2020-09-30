# module UART

## コンフィグ

> #### CONFIG_DISABLE_MODULE_UART
> UART モジュールの無効化  
> 定義することでコンパイルされなくなります

> ##### CONFIG_USE_HALF_CALLBACK_UART
> UARTのコールバック関数をハーフに変更します

## 関数
- [uartTransmit](function/INDEX.md#uarttransmit)
- [uartTransmit_IT](function/INDEX.md#uarttransmit_it)
- [uartTransmit_DMA](function/INDEX.md#uarttransmit_dma)
- [uartReceive](function/INDEX.md#uartreceive)
- [uartReceive_IT](function/INDEX.md#uartreceive_it)
- [uartReceive_DMA](function/INDEX.md#uartreceive_dma)
- [setUARTTxCallback](function/INDEX.md#setuarttxcallbackuart_handletypedef-stdfunctionvoid)
- [setUARTRxCallback](function/INDEX.md#setuartrxcallbackuart_handletypedef-stdfunctionvoid)
- [setErrorCallback](function/INDEX.md#setuarterrorcallbackuart_handletypedef-stdfunctionvoid)

## クラス
- [UART](class/UART.md)
  - [CubeMX](class/UART.md#CubeMX)
  - [クラステンプレート](class/UART.md#クラステンプレート)
  - [コンストラクタ](class/UART.md#コンストラクタ)
    - [UART(UART_HandleTypeDef)](class/UART.md#uartuart_handletypedef)
  - [関数](class/UART.md#関数)
    - [transmit(T, uint32_t)](class/UART.md#uarttransmitt-uint32_t)
    - [receive(T, uint32_t)](class/UART.md#uartreceivet-uint32_t)
- [UART_IT](class/UART_IT.md)
  - [CubeMX](class/UART_IT.md#cubemx)
  - [クラステンプレート](class/UART_IT.md#クラステンプレート)
  - [コンストラクタ](class/UART_IT.md#コンストラクタ)
    - [UART_IT(UART_HandleTypeDef)](class/UART_IT.md#uartuart_handletypedef)
  - [関数](class/UART_IT.md#関数)
    - [transmit(T)](class/UART_IT.md#uarttransmitt)
    - [receive(T)](class/UART_IT.md#uart_itreceivet)
    - [setTxCallback(std::function<void()>)](class/UART_IT.md#uart_itsettxcallbackstdfunctionvoid)
    - [setRxCallback(std::function<void()>)](class/UART_IT.md#uart_itsetrxcallbackstdfunctionvoid)
    - [setErrorCallback(std::function<void()>)](class/UART_IT.md#uart_itseterrorcallbackstdfunctionvoid)

[<< 戻る](../../INDEX.md)