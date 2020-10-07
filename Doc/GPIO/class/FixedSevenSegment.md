# FixedSevenSegment

## 目次
- [CubeMX](#CubeMX)
- [コンストラクタ](#コンストラクタ)
  - [FixedSevenSegment(bool)](#fixedsevensegmentfixedsevensegmentbool)
- [関数](#関数)
  - [add(GPIO)](#fixedsevensegmentaddgpio)
  - [add(GPIO_TypeDef*, uint16_t)](#fixedsevensegmentaddgpio_typedef-uint16_t)
  - [setLight(uint8_t)](#fixedsevensegmentsetlightuint8_t)
  - [set(int8_t, bool)](#fixedsevensegmentsetint8_t-bool)
  - [clear()](#fixedsevensegmentclear)
  - [isAvailable()](#fixedsevensegmentisavailable)

## CubeMX
```yaml
PinOut: GPIO_Output
```

## コンストラクタ
##### FixedSevenSegment::FixedSevenSegment(bool)
> ```c++
> FixedSevenSegment(
>     bool flip = false
> );
> ```
> `flip` に応じて `GPIO_PIN_SET`, `GPIO_PIN_RESET` が逆になります  
> 外部で７セグデコーダがついている場合に使ってください
> ```c++
> // 例
> FixedSevenSegment sevenSegment;
> FixedSevenSegment sevenSegment(true);
> ```

## 関数
##### FixedSevenSegment::add(GPIO)
> ```c++
> FixedSevenSegment& add(
>     GPIO gpio
> ) noexcept override;
> ```
> セグメントのピンを追加します
> 登録順は 0ビット → 1 → 2 → 3 → point
> ```c++
> // 例
> sevenSegment.add(pa5)
>             .add(pa6) // 以下省略
> ```

##### FixedSevenSegment::add(GPIO_TypeDef*, uint16_t)
> ```c++
> FixedSevenSegment& add(
>     GPIO_TypeDef* GPIOx,
>     uint16_t GPIO_Pin
> ) noexcept override;
> ```
> `FixedSevenSegment::add(GPIO)` の結果を返します  
> ```c++
> // 例
> sevenSegment.add(GPIOA, GPIO_PIN_5)
>             .add(GPIOA, GPIO_PIN_6) // 以下省略
> ```

##### FixedSevenSegment::setLight(uint8_t)
> ```c++
> bool setLight(
>     uint8_t lightData
> ) const noexcept override;
> ```
> 下位４ビットが数字。その上位ビットを小数点として点灯します
> ```c++
> sevenSegment.setLight(0b10011);
> sevenSegment.setLight(0b01001);
> ```

##### FixedSevenSegment::set(int8_t, bool)
> ```c++
> bool set(
>     int8_t hex,
>     bool point = false
> ) const noexcept override;
> ```
> `hex` の下位４ビットが数字。`point` を小数点として点灯します
> ```c++
> sevenSegment.set(0b0011, true);
> sevenSegment.set(0b1001, false);
> ```

##### FixedSevenSegment::clear()
> ```c++
> bool clear() const noexcept override;
> ```
> 全てのセグメントを消灯します
> ```c++
> sevenSegment.clear();
> ```

##### FixedSevenSegment::isAvailable()
> ```c++
> bool isAvailable() const noexcept override;
> ```
> 登録数が4個であれば true を返します  
> ```c++
> sevenSegment.isAvailable();
> ```

[<< 戻る](../INDEX.md)