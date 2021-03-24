# I2C_Slave_DMA

## 目次
- [CubeMX](#cubemx)
- [クラステンプレート](#クラステンプレート)
- [コンストラクタ](#コンストラクタ)
  - [I2C_Slave_DMA(I2C_HandleTypeDef, T, uint8_t)](#i2c_slave_dmai2c_slave_dmai2c_handletypedef-t-uint8_t)
- [関数](#関数)
  - [init()](#i2c_slave_dmainit)
  - [init(uint8_t)](#i2c_slave_dmainituint8_t)
  - [init(DIPSwitch)](#i2c_slave_dmainitdipswitch)
  - [startTransmit()](#i2c_slave_dmastarttransmit)
  - [startReceive()](#i2c_slave_dmastartreceive)
  - [setTxCallback(std::function<void()>)](#i2c_slave_dmasettxcallbackstdfunctionvoid)
  - [setRxCallback(std::function<void()>)](#i2c_slave_dmasetrxcallbackstdfunctionvoid)
  - [setErrorCallback(std::function<void()>)](#i2c_slave_dmaseterrorcallbackstdfunctionvoid)

## CubeMX
```yaml
PinOut: I2Cn_SCL & I2Cn_SDA
I2Cn:
  DMA Settings:
  - Add して Tx/Rx の使うものを選択
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
##### I2C_Slave_DMA::I2C_Slave_DMA(I2C_HandleTypeDef, T, uint8_t)
> ```c++
> I2C_Slave_DMA(
>     I2C_HandleTypeDef *hi2c,
>     T &data,
>     uint8_t address = 0x00
> );
> ```
> ```c++
> I2C_Slave_DMA(
>     I2C_HandleTypeDef &hi2c,
>     T &data,
>     uint8_t address = 0x00
> );
> ```
> ピンと自局アドレス・連携させた変数を設定します  
> ```c++
> // 例
> uint16_t data;
> I2C_Slave_DMA<uint16_t> slave(hi2c1, data, 0x01);
> I2C_Slave_DMA<uint16_t> slave(&hi2c1, data, 0x01);
> ```

## 関数
##### I2C_Slave_DMA::init()
> ```c++
> void init() noexcept;
> ```
> 自局アドレスを反映させ、再初期化します  
> ```c++
> // 例
> slave.init();
> ```

##### I2C_Slave_DMA::init(uint8_t)
> ```c++
> void init(uint8_t address) noexcept;
> ```
> 自局アドレスを上書きし、再初期化します  
> ```c++
> // 例
> slave.init(0x01);
> ```

##### I2C_Slave_DMA::init(DIPSwitch)
> ```c++
> #ifndef CONFIG_DISABLE_MODULE_GPIO
> void init(
>     DIPSwitch builder
> ) noexcept;
> #endif // CONFIG_DISABLE_MODULE_GPIO
> ```
> 自局アドレスを上書きし、再初期化します  
> ```c++
> // 例
> slave.init(dip);
> ```

##### I2C_Slave_DMA::startTransmit()
> ```c++
> HAL_StatusTypeDef startTransmit() noexcept;
> ```
> HAL_I2C_Slave_Transmit_DMA() の結果を返します  
> ```c++
> // 例
> slave.startTransmit();
> ```

##### I2C_Slave_DMA::startReceive()
> ```c++
> HAL_StatusTypeDef startReceive() noexcept;
> ```
> HAL_I2C_Slave_Receive_DMA() の結果を返します  
> ```c++
> // 例
> slave.startReceive();
> ```

##### I2C_Slave_DMA::setTxCallback(std::function<void()>)
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
> slave.setTxCallback([]{
>     logger.println("Tx");
> });
> ```

##### I2C_Slave_DMA::setRxCallback(std::function<void()>)
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
> slave.setRxCallback([]{
>     logger.println("Rx");
> });
> ```

##### I2C_Slave_DMA::setErrorCallback(std::function<void()>)
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
> slave.setErrorCallback([]{
>     logger.println("Error");
> });
> ```

[<< 戻る](../README.md)