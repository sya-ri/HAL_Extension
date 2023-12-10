# I2C_Master_IT

## 目次
- [CubeMX](#cubemx)
- [クラステンプレート](#クラステンプレート)
- [コンストラクタ](#コンストラクタ)
  - [I2C_Master_IT(I2C_HandleTypeDef)](#i2c_master_iti2c_master_iti2c_handletypedef)
- [関数](#関数)
  - [init()](#i2c_master_itinit)
  - [transmit(uint8_t, T)](#i2c_master_ittransmituint8_t-t)
  - [receive(uint8_t, T)](#i2c_master_itreceiveuint8_t-t)

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
##### I2C_Master_IT::I2C_Master_IT(I2C_HandleTypeDef)
> ```c++
> I2C_Master_IT(
>     I2C_HandleTypeDef *hi2c
> );
> ```
> ```c++
> I2C_Master_IT(
>     I2C_HandleTypeDef &hi2c
> );
> ```
> ピンを設定します  
> ```c++
> // 例
> I2C_Master_IT<uint16_t> master(hi2c1);
> I2C_Master_IT<uint16_t> master(&hi2c1);
> ```

## 関数
##### I2C_Master_IT::init()
> ```c++
> void init() noexcept;
> ```
> 再初期化します  
> ```c++
> // 例
> master.init();
> ```

##### I2C_Master_IT::transmit(uint8_t, T)
> ```c++
> HAL_StatusTypeDef transmit(
>     uint8_t target,
>     const T &data
> ) const noexcept;
> ```
> HAL_I2C_Master_Transmit_IT() の結果を返します  
> ```c++
> // 例
> uint16_t data = 0xAC;
> master.transmit(0x02, data);
> master.transmit(0x02, 0x35); // 変数ではなくリテラルも使用可能
> ```

##### I2C_Master_IT::receive(uint8_t, T)
> ```c++
> HAL_StatusTypeDef receive(
>     uint8_t target,
>     T &data
> ) const noexcept;
> ```
> HAL_I2C_Master_Receive_IT() の結果を返します  
> ```c++
> // 例
> uint16_t data;
> master.receive(0x02, data);
> ```

##### I2C_Master_IT::setTxCallback(std::function<void()>)
> ```c++
> void setTxCallback(
>     std::function<void()> function
> ) noexcept;
> ```
> 送信完了時の割り込み関数を設定します  
> ```c++
> // 例
> master.setTxCallback([]{
>     logger.println("Tx\n");
> });
> ```

##### I2C_Master_IT::setRxCallback(std::function<void()>)
> ```c++
> void setRxCallback(
>     std::function<void()> function
> ) noexcept;
> ```
> 受信完了時の割り込み関数を設定します
> ```c++
> // 例
> master.setRxCallback([]{
>     logger.println("Rx\n");
> });
> ```

##### I2C_Master_IT::setErrorCallback(std::function<void()>)
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