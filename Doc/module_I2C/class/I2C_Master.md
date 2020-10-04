# I2C_Master

## CubeMX
```yaml
PinOut: I2Cn_SCL & I2Cn_SDA
```

## クラステンプレート
```c++
template <class T>
```
```yaml
T: 送受信するデータ型
```

## コンストラクタ
##### I2C_Master::I2C_Master(I2C_HandleTypeDef)
> ```c++
> I2C_Master(
>     I2C_HandleTypeDef *hi2c
> );
> 
> I2C_Master(
>     I2C_HandleTypeDef &hi2c
> );
> ```
> ピンを設定します  
> ```c++
> // 例
> I2C_Master<uint8_t> master(&hi2c1);
> I2C_Master<uint8_t> master(hi2c1);
> ```

## 関数
##### I2C_Master::init()
> ```c++
> void init() noexcept;
> ```
> 再初期化します  
> ```c++
> // 例
> master.init();
> ```

##### I2C_Master::transmit(uint8_t, T, uint32_t)
> ```c++
> HAL_StatusTypeDef transmit(
>     uint8_t target,
>     const T &data,
>     uint32_t timeout
> ) const noexcept;
> ```
> HAL_I2C_Master_Transmit() の結果を返します  
> ```c++
> // 例
> uint8_t data = 0xAC;
> master.transmit(0x02, data, 0x0F);
> master.transmit(0x02, 0x35, 0x0F); // 変数ではなくリテラルも使用可能
> ```

##### I2C_Master::receive(uint8_t, T, uint32_t)
> ```c++
> HAL_StatusTypeDef receive(
>     uint8_t target,
>     T &data,
>     uint32_t timeout
> ) const noexcept
> ```
> HAL_I2C_Master_Receive() の結果を返します  
> ```c++
> // 例
> uint8_t data;
> master.receive(0x02, data, 0x0F);
> ```

[<< 戻る](../INDEX.md)