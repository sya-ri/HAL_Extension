# module UART

## コンフィグ

> #### CONFIG_DISABLE_MODULE_UART
> UART モジュールの無効化  
> 定義することでコンパイルされなくなります

> ##### CONFIG_USE_HALF_CALLBACK_UART
> UARTのコールバック関数をハーフに変更します

## 関数
- [uartTransmit](function.md#uarttransmit)
- [uartTransmit_IT](function.md#uarttransmit_it)
- [uartTransmit_DMA](function.md#uarttransmit_dma)
- [uartReceive](function.md#uartreceive)
- [uartReceive_IT](function.md#uartreceive_it)
- [uartReceive_DMA](function.md#uartreceive_dma)
- [setUARTTxCallback](function.md#setuarttxcallbackuart_handletypedef--stdfunctionvoid)
- [setUARTRxCallback](function.md#setuartrxcallbackuart_handletypedef--stdfunctionvoid)
- [setErrorCallback](function.md#setuarterrorcallbackuart_handletypedef--stdfunctionvoid)

[<< 戻る](../../INDEX.md)