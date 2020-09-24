# DynamicSevenSegment

## 目次
- [CubeMX](#CubeMX)
- [コンストラクタ](#コンストラクタ)
  - [DynamicSevenSegment(SevenSegment, bool, bool, bool)](#dynamicsevensegmentsevensegment-bool-bool-bool)
- [関数](#関数)
  - [add(GPIO)](#dynamicsevensegmentaddgpio)
  - [add(GPIO_TypeDef*, uint16_t)](#dynamicsevensegmentaddgpio_typedef-uint16_t)
  - [update(int64_t)](#dynamicsevensegmentupdateint64_t)
  - [updateFixedPoint(float, int8_t)](#dynamicsevensegmentupdatefixedpointfloat-int8_t)
  - [updateFloatPoint(float)](#dynamicsevensegmentupdatefloatpointfloat)
  - [next()](#dynamicsevensegmentnext)
  - [clear()](#dynamicsevensegmentclear)

## CubeMX
```yaml
PinOut: GPIO_Output
```

## コンストラクタ
##### DynamicSevenSegment(SevenSegment, bool, bool, bool)
> ```c++
> DynamicSevenSegment(
>     const SevenSegment &sevenSegment,
>     bool hex = false,
>     bool zeroFill = false,
>     bool allowSign = false
> );
> ```
> ダイナミック点灯で使う７セグメントを指定します  
> 表示フォーマットの設定をします
> ```c++
> // 例
> DynamicSevenSegment dynamicSevenSegment(sevenSegment);
> DynamicSevenSegment dynamicSevenSegment(sevenSegment, true, true, true);
> ```

## 関数
##### DynamicSevenSegment::add(GPIO)
> ```c++
> DynamicSevenSegment& add(
>     GPIO gpio
> ) noexcept;
> ```
> 桁を追加します
> ```c++
> // 例
> dynamicSevenSegment.add(pb0)
>                    .add(pb1) // 以下省略
> ```

##### DynamicSevenSegment::add(GPIO_TypeDef*, uint16_t)
> ```c++
> DynamicSevenSegment& add(
>     GPIO_TypeDef* GPIOx,
>     uint16_t GPIO_Pin
> ) noexcept;
> ```
> `DynamicSevenSegment::add(GPIO)` を実行します
> ```c++
> // 例
> dynamicSevenSegment.add(GPIOB, GPIO_PIN_0)
>                    .add(GPIOB, GPIO_PIN_1) // 以下省略
> ```

##### DynamicSevenSegment::update(int64_t)
> ```c++
> void update(
>     int64_t num
> ) const noexcept;
> ```
> 表示する値を整数で変更します
> ```c++
> // 例
> dynamicSevenSegment.update(123);
> dynamicSevenSegment.update(-512);
> ```

##### DynamicSevenSegment::updateFixedPoint(float, int8_t)
> ```c++
> void updateFixedPoint(
>     float num,
>     int8_t point
> ) const noexcept;
> ```
> 表示する値を固定小数点で変更します
> ```c++
> // 例
> dynamicSevenSegment.updateFixedPoint(123, 1); // 123.0
> dynamicSevenSegment.updateFixedPoint(-151.225, 2); // -151.22
> ```

##### DynamicSevenSegment::updateFloatPoint(float)
> ```c++
> void updateFloatPoint(
>     float num
> ) const noexcept;
> ```
> 表示する値を浮動小数点で変更します
> ```c++
> // 例
> dynamicSevenSegment.updateFloatPoint(123); // 123.0000...
> dynamicSevenSegment.updateFloatPoint(-151.225); // -151.225...
> ```

##### DynamicSevenSegment::next()
> ```c++
> void next() const noexcept;
> ```
> 次の桁の表示に切り替えます ダイナミック点灯に必須です  
> タイマー割り込み や loop で呼び出してください
> ```c++
> // 例
> void loop(){
>     dynamicSevenSegment.next();
> }
> ```

##### DynamicSevenSegment::clear()
> ```c++
> void clear() const noexcept;
> ```
> 現在の表示を消します
> ```c++
> dynamicSevenSegment.clear();
> ```

[<< 戻る](../INDEX.md)