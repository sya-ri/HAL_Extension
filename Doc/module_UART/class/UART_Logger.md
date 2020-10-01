# UART_Logger

## 目次
- [CubeMX](#cubemx)
- [コンストラクタ](#コンストラクタ)
  - [UART_Logger(UART_HandleTypeDef, uint32_t)](#uart_loggeruart_handletypedef-uint32_t)
- [関数](#関数)
  - [print(std::string)](#uart_loggerprintstdstring)
  - [print(const char*)](#uart_loggerprintconst-char)
  - [println(std::string)](#uart_loggerprintlnstdstring)
  - [println(const char*)](#uart_loggerprintlnconst-char)

## CubeMX
```yaml
PinOut: USARTn_TX / USARTn_RX
Mode: Asynchronous
```

## コンストラクタ
##### UART_Logger(UART_HandleTypeDef, uint32_t)
> ```c++
> UART_Logger(
>     UART_HandleTypeDef *huart,
>     uint32_t timeout = 0x0F
> );
> 
> UART_Logger(
>     UART_HandleTypeDef &huart,
>     uint32_t timeout = 0x0F
> );
> ```
> ピンとタイムアウト時間を設定します    
> UART を使用しての送信になります  
> ```c++
> // 例
> UART_Logger logger(&huart2); // タイムアウト時間は省略可能
> UART_Logger logger(&huart2, 0xFF);
> 
> UART_Logger logger(huart2); // タイムアウト時間は省略可能
> UART_Logger logger(huart2, 0xFF);
> ```

## 関数
##### UART_Logger::print(std::string)
##### UART_Logger::print(const char*)
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

##### UART_Logger::println(std::string)
##### UART_Logger::println(const char*)
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

[<< 戻る](../INDEX.md)