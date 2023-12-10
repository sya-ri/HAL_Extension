# I2C_Slave_IT

## 目次
- [CubeMX](#cubemx)
- [クラステンプレート](#クラステンプレート)
- [コンストラクタ](#コンストラクタ)
  - [I2C_Slave_IT(I2C_HandleTypeDef, uint8_t)](#i2c_slave_iti2c_slave_iti2c_handletypedef-uint8_t)
- [関数](#関数)
  - [init()](#i2c_slave_itinit)
  - [init(uint8_t)](#i2c_slave_itinituint8_t)
  - [init(DIPSwitch)](#i2c_slave_itinitdipswitch)
  - [transmit(T)](#i2c_slave_ittransmitt)
  - [receive(T)](#i2c_slave_itreceivet)
  - [setTxCallback(std::function<void()>)](#i2c_slave_itsettxcallbackstdfunctionvoid)
  - [setRxCallback(std::function<void()>)](#i2c_slave_itsetrxcallbackstdfunctionvoid)
  - [setErrorCallback(std::function<void()>)](#i2c_slave_itseterrorcallbackstdfunctionvoid)

## CubeMX
```yaml
PinOut: I2Cn_SCL & I2Cn_SDA
NVIC Settings:
  I2Cn interrupt: Enable
```

## クラステンプレート
```c++
template <class T>
```
```yaml
T: 送受信するデータ型
```

## コンストラクタ
##### I2C_Slave_IT::I2C_Slave_IT(I2C_HandleTypeDef, uint8_t)
> ```c++
> I2C_Slave_IT(
>     I2C_HandleTypeDef *hi2c,
>     uint8_t address = 0x00
> );
> ```
> ```c++
> I2C_Slave_IT(
>     I2C_HandleTypeDef &hi2c,
>     uint8_t address = 0x00
> );
> ```
> ピンと自局アドレスを設定します  
> ```c++
> // 例
> I2C_Slave_IT<uint16_t> slave(hi2c1, 0x01);
> I2C_Slave_IT<uint16_t> slave(&hi2c1, 0x01);
> ```

## 関数
##### I2C_Slave_IT::init()
> ```c++
> void init() noexcept;
> ```
> 自局アドレスを反映させ、再初期化します  
> ```c++
> // 例
> slave.init();
> ```

##### I2C_Slave_IT::init(uint8_t)
> ```c++
> void init(
>     uint8_t address
> ) noexcept;
> ```
> 自局アドレスを上書きし、再初期化します  
> ```c++
> // 例
> slave.init(0x01);
> ```

##### I2C_Slave_IT::init(DIPSwitch)
> ```c++
> #ifndef CONFIG_DISABLE_MODULE_GPIO
> void init(DIPSwitch builder);
> #endif // CONFIG_DISABLE_MODULE_GPIO
> ```
> 自局アドレスを上書きし、再初期化します  
> ```c++
> // 例
> slave.init(dip);
> ```

##### I2C_Slave_IT::transmit(T)
> ```c++
> HAL_StatusTypeDef transmit(
>     const T &data
> ) const noexcept;
> ```
> HAL_I2C_Slave_Transmit_IT() の結果を返します  
> ```c++
> // 例
> uint16_t data = 0xAC;
> slave.transmit(data);
> slave.transmit(0x35); // 変数ではなくリテラルも使用可能
> ```

##### I2C_Slave_IT::receive(T)
> ```c++
> HAL_StatusTypeDef receive(
>     T &data
> ) const noexcept;
> ```
> HAL_I2C_Slave_Receive_IT() の結果を返します  
> ```c++
> // 例
> uint16_t data;
> slave.receive(data);
> ```

##### I2C_Slave_IT::setTxCallback(std::function<void()>)
> ```c++
> void setTxCallback(
>     std::function<void()> function
> ) noexcept;
> ```
> 送信完了時の割り込み関数を設定します  
> ```c++
> // 例
> slave.setTxCallback([]{
>     logger.println("Tx");
> });
> ```

##### I2C_Slave_IT::setRxCallback(std::function<void()>)
> ```c++
> void setRxCallback(
>     std::function<void()> function
> ) noexcept;
> ```
> 受信完了時の割り込み関数を設定します
> ```c++
> // 例
> slave.setRxCallback([]{
>     logger.println("Rx");
> });
> ```

##### I2C_Slave_IT::setErrorCallback(std::function<void()>)
> ```c++
> void setErrorCallback(
>     std::function<void()> function
> ) noexcept;
> ```
> エラー取得時の割り込み関数を設定します
> ```c++
> // 例
> slave.setErrorCallback([]{
>     logger.println("Error");
> });
> ```

[<< 戻る](../README.md)