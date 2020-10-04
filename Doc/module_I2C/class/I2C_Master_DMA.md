# I2C_Master_DMA

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
##### I2C_Master_DMA::I2C_Master_DMA(I2C_HandleTypeDef, uint8_t, T)
> ```c++
> I2C_Master_DMA(
>     I2C_HandleTypeDef *hi2c,
>     uint8_t target,
>     T &data
> );
> ```
> ```c++
> I2C_Master_DMA(
>     I2C_HandleTypeDef &hi2c,
>     uint8_t target,
>     T &data
> );
> ```
> ピンと送信先アドレス・連携させる変数を設定します  
> ```c++
> // 例
> uint16_t data;
> I2C_Master_DMA<uint16_t> master(hi2c1, 0x01, data);
> I2C_Master_DMA<uint16_t> master(&hi2c1, 0x01, data);
> ```

## 関数
##### I2C_Master_DMA::init()
> ```c++
> void init() noexcept;
> ```
> 再初期化します  
> ```c++
> // 例
> master.init();
> ```

##### I2C_Master_DMA::startTransmit()
> ```c++
> HAL_StatusTypeDef startTransmit() noexcept;
> ```
> HAL_I2C_Master_Transmit_DMA() の結果を返します  
> ```c++
> // 例
> master.startTransmit();
> ```

##### I2C_Master_DMA::startReceive()
> ```c++
> HAL_StatusTypeDef startReceive() noexcept;
> ```
> HAL_I2C_Master_Receive_DMA() の結果を返します  
> ```c++
> // 例
> master.startReceive();
> ```

##### I2C_Master_DMA::setTxCallback(std::function<void()>)
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
> master.setTxCallback([]{
>     logger.println("Tx\n");
> });
> ```

##### I2C_Master_DMA::setRxCallback(std::function<void()>)
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
> master.setRxCallback([]{
>     logger.println("Rx\n");
> });
> ```

##### I2C_Master_DMA::setErrorCallback(std::function<void()>)
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

[<< 戻る](../INDEX.md)