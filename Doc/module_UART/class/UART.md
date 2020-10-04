# UART

## 目次
- [CubeMX](#cubemx)
- [クラステンプレート](#クラステンプレート)
- [コンストラクタ](#コンストラクタ)
  - [UART(UART_HandleTypeDef)](#uartuartuart_handletypedef)
- [関数](#関数)
  - [transmit(T, uint32_t)](#uarttransmitt-uint32_t)
  - [receive(T, uint32_t)](#uartreceivet-uint32_t)

## CubeMX
```yaml
PinOut: USARTn_TX / USARTn_RX
Mode: Asynchronous
```

## クラステンプレート
```c++
template <class T>
```
```yaml
T: 送受信するデータ型
```

## コンストラクタ

##### UART::UART(UART_HandleTypeDef)
> ```c++
> UART(
>     UART_HandleTypeDef *huart
> );
> ```
> ```c++
> UART(
>     UART_HandleTypeDef &huart
> );
> ```
> ピンを設定します  
> ```c++
> // 例
> UART<uint16_t> uart(&huart2);
> UART<uint16_t> uart(huart2);
> ```

## 関数
##### UART::transmit(T, uint32_t)
> ```c++
> HAL_StatusTypeDef transmit(
>     const T &data,
>     uint32_t timeout
> ) const noexcept;
> ```
> HAL_UART_Transmit() の結果を返します  
> ```c++
> // 例
> uint16_t data = 0xAC;
> uart.transmit(data, 0x0F);
> uart.transmit(0x35, 0x0F); // 変数ではなくリテラルも使用可能
> ```

##### UART::receive(T, uint32_t)
> ```c++
> HAL_StatusTypeDef receive(
>     T &data,
>     uint32_t timeout
> ) const noexcept;
> ```
> HAL_UART_Receive() の結果を返します  
> ```c++
> // 例
> uint16_t data;
> uart.receive(data, 0x0F);
> ```

[<< 戻る](../INDEX.md)