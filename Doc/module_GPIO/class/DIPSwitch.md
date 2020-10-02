# DIPSwitch

## 目次
- [CubeMX](#cubemx)
- [コンストラクタ](#コンストラクタ)
  - [DIPSwitch(bool)](#dipswitchdipswitchbool)
- [関数](#関数)
  - [add(GPIO)](#dipswitchaddgpio)
  - [add(GPIO_TypeDef*, uint16_t)](#dipswitchaddgpio_typedef-uint16_t)
  - [getSize()](#dipswitchgetsize)
  - [getAddress()](#dipswitchgetaddress)

## CubeMX
```yaml
PinOut: GPIO_Input
```

## コンストラクタ
##### DIPSwitch::DIPSwitch(bool)
> ```c++
> DIPSwitch(
>     bool flip = false
> );
> ```
> `flip: true` で `DIPSwitch::getAddress()` で  
> 全ビット反転された結果が出力されます
> ```c++
> // 例
> DIPSwitch dip;
> DIPSwitch dip(true);
> ```

## 関数
##### DIPSwitch::add(GPIO)
> ```c++
> DIPSwitch& add(
>     GPIO gpio
> ) noexcept;
> ```
> スイッチのピンを追加します  
> 最大登録数は8つです  
> ```c++
> // 例
> dip.add(pa5)
>    .add(pa6) // 以下省略
> ```

##### DIPSwitch::add(GPIO_TypeDef*, uint16_t)
> ```c++
> DIPSwitch& add(
>     GPIO_TypeDef* GPIOx,
>     uint16_t GPIO_Pin
> ) noexcept;
> ```
> `DIPSwitch::add(GPIO)` の結果を返します  
> ```c++
> // 例
> dip.add(GPIOA, GPIO_PIN_5)
>    .add(GPIOA, GPIO_PIN_6) // 以下省略
> ```

##### DIPSwitch::getSize()
> ```c++
> uint8_t getSize() const noexcept;
> ```
> 追加済みのスイッチ数を取得します  
> ```c++
> // 例
> uint8_t size = dip.getSize();
> ```

##### DIPSwitch::getAddress()
> ```c++
> uint8_t getAddress() const noexcept;
> ```
> 追加したスイッチを使用してアドレスを取得します  
> ```c++
> // 例
> uint8_t address = dip.getAddress();
> ```

[<< 戻る](../INDEX.md)