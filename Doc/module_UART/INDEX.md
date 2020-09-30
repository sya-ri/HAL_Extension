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

[<< 戻る](../../INDEX.md)