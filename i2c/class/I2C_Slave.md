# I2C_Slave

## 目次
- [CubeMX](#cubemx)
- [クラステンプレート](#クラステンプレート)
- [コンストラクタ](#コンストラクタ)
  - [I2C_Slave(I2C_HandleTypeDef uint8_t)](#i2c_slavei2c_slavei2c_handletypedef-uint8_t)
- [関数](#関数)
  - [init()](#i2c_slaveinit)
  - [init(uint8_t)](#i2c_slaveinituint8_t)
  - [init(DIPSwitch)](#i2c_slaveinitdipswitch)
  - [transmit(T, uint32_t)](#i2c_slavetransmitt-uint32_t)
  - [receive(T, uint32_t)](#i2c_slavereceivet-uint32_t)
  
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
##### I2C_Slave::I2C_Slave(I2C_HandleTypeDef uint8_t)
> ```c++
> I2C_Slave(
>     I2C_HandleTypeDef *hi2c,
>     uint8_t address = 0x00
> );
> ```
> ```c++
> I2C_Slave(
>     I2C_HandleTypeDef &hi2c,
>     uint8_t address = 0x00
> );
> ```
> ピンと自局アドレスを設定します  
> 自局アドレスを省略することも可能です
> ```c++
> // 例
> I2C_Slave<uint8_t> slave(hi2c1, 0x01);
> I2C_Slave<uint8_t> slave(hi2c1);
> 
> I2C_Slave<uint8_t> slave(&hi2c1, 0x01);
> I2C_Slave<uint8_t> slave(&hi2c1);
> ```

## 関数
##### I2C_Slave::init()
> ```c++
> void init() noexcept;
> ```
> 自局アドレスを反映させ、再初期化します  
> ```c++
> // 例
> slave.init();
> ```

##### I2C_Slave::init(uint8_t)
> ```c++
> void init(
>     const uint8_t address
> ) noexcept;
> ```
> 自局アドレスを上書きし、再初期化します  
> ```c++
> // 例
> slave.init(0x01);
> ```

##### I2C_Slave::init(DIPSwitch)
> ```c++
> #ifndef CONFIG_DISABLE_MODULE_GPIO
> void init(
>     DIPSwitch builder
> ) noexcept;
> #endif // CONFIG_DISABLE_MODULE_GPIO
> ```
> 自局アドレスをDIPSwitch::getAddress()を使用して上書きし、再初期化します  
> ```c++
> // 例
> slave.init(dip);
> ```

##### I2C_Slave::transmit(T, uint32_t)
> ```c++
> HAL_StatusTypeDef transmit(
>     const T &data,
>     uint32_t timeout
> ) const noexcept;
> ```
> HAL_I2C_Slave_Transmit() の結果を返します  
> ```c++
> // 例
> uint8_t data = 0xAC;
> slave.transmit(data, 0x0F);
> slave.transmit(0x35, 0x0F); // 変数ではなくリテラルも使用可能
> ```

##### I2C_Slave::receive(T, uint32_t)
> ```c++
> HAL_StatusTypeDef receive(
>     T &data,
>     uint32_t timeout
> ) const noexcept;
> ```
> HAL_I2C_Slave_Receive() の結果を返します  
> ```c++
> // 例
> uint8_t data;
> slave.receive(data, 0x0F);
> ```

[<< 戻る](../README.md)