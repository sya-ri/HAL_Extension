# UART_DMA

## 目次
- [CubeMX](#cubemx)
- [クラステンプレート](#クラステンプレート)
- [コンストラクタ](#コンストラクタ)
  - [UART_DMA(UART_HandleTypeDef, T)](#uart_dmauart_dmauart_handletypedef-t)
- [関数](#関数)
  - [startTransmit()](#uart_dmastartreceive)
  - [startReceive()](#uart_dmastartreceive)
  - [pause()](#uart_dmapause)
  - [resume()](#uart_dmaresume)
  - [stop()](#uart_dmastop)
  - [setTxCallback(std::function<void()>)](#uart_dmasettxcallbackstdfunctionvoid)
  - [setRxCallback(std::function<void()>)](#uart_dmasetrxcallbackstdfunctionvoid)
  - [setErrorCallback(std::function<void()>)](#uart_dmaseterrorcallbackstdfunctionvoid)

## CubeMX
```yaml
PinOut: USARTn_TX / USARTn_RX
Mode: Asynchronous
USARTn:
  DMA Settings:
  - Add して Tx/Rx を選択
  - Mode を Circular に設定
  - Data Width を Word に設定
```

## クラステンプレート
```c++
template <class T>
```
```yaml
T: 送受信するデータ型
```

## コンストラクタ
##### UART_DMA::UART_DMA(UART_HandleTypeDef, T)
> ```c++
> UART_DMA(
>     UART_HandleTypeDef *huart,
>     T &data
> );
> ```
> ```c++
> UART_DMA(
>     UART_HandleTypeDef &huart,
>     T &data
> );
> ```
> ピンと連携させる変数を設定します  
> ```c++
> // 例
> uint16_t data;
> UART_DMA<uint16_t> uart(&huart2, data);
> UART_DMA<uint16_t> uart(huart2, data);
> ```

## 関数
##### UART_DMA::startTransmit()
> ```c++
> HAL_StatusTypeDef startTransmit() noexcept;
> ```
> 送信を始めます  
> 連携させた変数の値を自動で送信します  
> HAL_UART_Transmit_DMA の結果を返します  
> ```c++
> // 例
> uart.startTransmit();
> ```

##### UART_DMA::startReceive()
> ```c++
> HAL_StatusTypeDef startReceive() noexcept;
> ```
> 受信を始めます  
> 連携させた変数の値が自動で変わります  
> HAL_UART_Receive_DMA の結果を返します  
> ```c++
> // 例
> uart.startReceive();
> ```

##### UART_DMA::pause()
> ```c++
> HAL_StatusTypeDef pause() noexcept;
> ```
> 送受信を中断します  
> HAL_UART_DMAPause の結果を返します  
> ```c++
> // 例
> uart.pause();
> ```

##### UART_DMA::resume()
> ```c++
> HAL_StatusTypeDef resume() noexcept;
> ```
> 送受信を再開します  
> HAL_UART_DMAResume の結果を返します  
> ```c++
> // 例
> uart.resume();
> ```

##### UART_DMA::stop()
> ```c++
> HAL_StatusTypeDef stop() noexcept;
> ```
> 送受信を終了します  
> HAL_UART_DMAStop の結果を返します  
> ```c++
> // 例
> uart.stop();
> ```

##### UART_DMA::setTxCallback(std::function<void()>)
> ```c++
> #ifndef CONFIG_DISABLE_EX_CALLBACK
> void setTxCallback(
>     std::function<void()> function
> ) noexcept;
> #endif // CONFIG_DISABLE_EX_CALLBACK
> ```
> 送信完了時の割り込み関数を設定します  
> ```c++
> // 例
> uart.setTxCallback([]{
>     logger.println("Tx\n");
> });
> ```

##### UART_DMA::setRxCallback(std::function<void()>)
> ```c++
> #ifndef CONFIG_DISABLE_EX_CALLBACK
> void setRxCallback(
>     std::function<void()> function
> ) noexcept;
> #endif // CONFIG_DISABLE_EX_CALLBACK
> ```
> 受信完了時の割り込み関数を設定します  
> ```c++
> // 例
> uart.setRxCallback([]{
>     logger.println("Rx\n");
> });
> ```

##### UART_DMA::setErrorCallback(std::function<void()>)
> ```c++
> #ifndef CONFIG_DISABLE_EX_CALLBACK
> void setErrorCallback(
>     std::function<void()> function
> ) noexcept;
> #endif // CONFIG_DISABLE_EX_CALLBACK
> ```
> エラー取得時の割り込み関数を設定します  
> ```c++
> // 例
> uart.setErrorCallback([]{
>     logger.println("Error\n");
> });
> ```

[<< 戻る](../README.md)