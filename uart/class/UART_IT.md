# UART_IT

## 目次
- [CubeMX](#cubemx)
- [クラステンプレート](#クラステンプレート)
- [コンストラクタ](#コンストラクタ)
  - [UART_IT(UART_HandleTypeDef)](#uart_ituart_ituart_handletypedef)
- [関数](#関数)
  - [getHandle()](#uart_itgethandle)
  - [equals(UART_HandleTypeDef*)](#uart_itequalsuart_handletypedef)
  - [equals(UART_HandleTypeDef&)](#uart_itequalsuart_handletypedef-1)
  - [transmit(T)](#uarttransmitt)
  - [receive(T)](#uart_itreceivet)
  - [setTxCallback(std::function<void()>)](#uart_itsettxcallbackstdfunctionvoid)
  - [setRxCallback(std::function<void()>)](#uart_itsetrxcallbackstdfunctionvoid)
  - [setErrorCallback(std::function<void()>)](#uart_itseterrorcallbackstdfunctionvoid)

## CubeMX
```yaml
PinOut: USARTn_TX / USARTn_RX
Mode: Asynchronous
USARTn:
  NVIC Settings:
    USARTn global interrupt: Enable
```

## クラステンプレート
```c++
template <class T>
```
```yaml
T: 送受信するデータ型
```

## コンストラクタ

##### UART_IT::UART_IT(UART_HandleTypeDef)
> ```c++
> UART_IT(
>     UART_HandleTypeDef *huart
> );
> ```
> ```c++
> UART_IT(
>     UART_HandleTypeDef &huart
> );
> ```
> ピンを設定します  
> ```c++
> // 例
> UART_IT<uint16_t> uart(&huart2);
> UART_IT<uint16_t> uart(huart2);
> ```

## 関数
##### UART_IT::getHandle()
> ```c++
> UART_HandleTypeDef* getHandle() const noexcept;
> ```
> 設定されている UART ハンドルを返します

##### UART_IT::equals(UART_HandleTypeDef*)
##### UART_IT::equals(UART_HandleTypeDef&)
> ```c++
> bool equals(
>     UART_HandleTypeDef *huart
> ) const noexcept;
>
> bool equals(
>     UART_HandleTypeDef &huart
> ) const noexcept;
> ```
> 渡した UART ハンドルと同じインスタンスか判定します

##### UART::transmit(T)
> ```c++
> HAL_StatusTypeDef transmit(
>     const T &data
> ) const noexcept;
> ```
> HAL_UART_Transmit_IT() の結果を返します  
> ```c++
> // 例
> uint16_t data = 0xAC;
> uart.transmit(data);
> uart.transmit(0x35); // 変数ではなくリテラルも使用可能
> ```

##### UART_IT::receive(T)
> ```c++
> HAL_StatusTypeDef receive(
>     T &data
> ) const noexcept;
> ```
> HAL_UART_Receive_IT() の結果を返します  
> ```c++
> // 例
> uint16_t data;
> uart.receive(data);
> ```

##### UART_IT::setTxCallback(std::function<void()>)
> ```c++
> void setTxCallback(
>     std::function<void()> function
> ) noexcept;
> ```
> 送信完了時の割り込み関数を設定します  
> ```c++
> // 例
> uart.setTxCallback([]{
>     logger.println("Tx");
> });
> ```

##### UART_IT::setRxCallback(std::function<void()>)
> ```c++
> void setRxCallback(
>     std::function<void()> function
> ) noexcept;
> ```
> 受信完了時の割り込み関数を設定します  
> ```c++
> // 例
> uart.setRxCallback([]{
>     logger.println("Rx");
> });
> ```

##### UART_IT::setErrorCallback(std::function<void()>)
> ```c++
> void setErrorCallback(
>     std::function<void()> function
> ) noexcept;
> ```
> エラー取得時の割り込み関数を設定します  
> ```c++
> // 例
> uart.setErrorCallback([]{
>     logger.println("Error");
> });
> ```

[<< 戻る](../README.md)
