# UART_Logger_IT

## 目次
- [CubeMX](#cubemx)
- [コンストラクタ](#コンストラクタ)
  - [UART_Logger_IT(UART_HandleTypeDef)](#uart_logger_ituart_logger_ituart_handletypedef)
- [関数](#関数)
  - [print(std::string)](#uart_logger_itprintstdstring)
  - [print(const char*)](#uart_logger_itprintconst-char)
  - [println(std::string)](#uart_logger_itprintlnstdstring)
  - [println(const char*)](#uart_logger_itprintlnconst-char)
  - [itTxCallback(UART_HandleTypeDef*)](#uart_logger_itittxcallbackuart_handletypedef)

## CubeMX
```yaml
PinOut: USARTn_TX / USARTn_RX
Mode: Asynchronous
USARTn:
  NVIC Settings:
    USARTn global interrupt: Enable
```

## コンストラクタ
##### UART_Logger_IT::UART_Logger_IT(UART_HandleTypeDef)
> ```c++
> UART_Logger_IT(
>     UART_HandleTypeDef *huart
> );
> 
> UART_Logger_IT(
>     UART_HandleTypeDef &huart
> );
> ```
> ピンを設定します  
> UART_IT を使用しての送信になります  
> ```c++
> // 例
> UART_Logger_IT logger(&huart2);
> UART_Logger_IT logger(huart2);
> ```

## 関数
##### UART_Logger_IT::print(std::string)
##### UART_Logger_IT::print(const char*)
> ```c++
> void print(
>     std::string text
> ) const noexcept;
> 
> void print(
>     const char* text
> ) const noexcept;
> ```
> 送信します  
> ```c++
> // 例
> logger.print("Hello");
> ```

##### UART_Logger_IT::println(std::string)
##### UART_Logger_IT::println(const char*)
> ```c++
> void println(
>     std::string text
> ) const noexcept;
> 
> void println(
>     const char* text
> ) const noexcept;
> ```
> 末尾に `\r\n` を連結させて送信します  
> ```c++
> // 例
> logger.println("HelloWorld");
> ```

##### UART_Logger_IT::itTxCallback(UART_HandleTypeDef*)
> ```c++
> #ifdef CONFIG_DISABLE_EX_CALLBACK
>     void itTxCallback(UART_HandleTypeDef *huart) noexcept;
> #endif // CONFIG_DISABLE_EX_CALLBACK
> ```
> `CONFIG_DISABLE_EX_CALLBACK` を定義した時のみ定義されます
> ```c++
> // 例
> void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart) {
>     logger.itTxCallback(huart);
> }
> ```

[<< 戻る](../INDEX.md)