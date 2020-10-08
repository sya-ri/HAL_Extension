# BinaryArray

## 目次
- [クラステンプレート](#クラステンプレート)
- [コンストラクタ](#コンストラクタ)
  - [BinaryArray()](#binaryarraybinaryarray)
- [関数](#関数)
  - [set(uint8_t)](#binaryarraysetuint8_t)
  - [reset(uint8_t)](#binaryarrayresetuint8_t)
  - [write(uint8_t, bool)](#binaryarraywriteuint8_t-bool)
  - [read(uint8_t)](#binaryarrayreaduint8_t)
  - [get()](#binaryarrayget)

## クラステンプレート
```c++
template <std::size_t ARRAY_SIZE>
```
```yaml
ARRAY_SIZE: ビット配列の要素数
```

## コンストラクタ
##### BinaryArray::BinaryArray()
> ```c++
> BinaryArray();
> ```
> 配列を内部で定義し、`BinaryArrayRef` を使用します

## 関数

##### BinaryArray::set(uint8_t)
> ```c++
> void set(
>     uint8_t index
> ) noexcept;
> ```
> 指定したビットを `1` にします

##### BinaryArray::reset(uint8_t)
> ```c++
> void reset(
>     uint8_t index
> ) noexcept;
> ```
> 指定したビットを `0` にします

##### BinaryArray::write(uint8_t, bool)
> ```c++
> void write(
>     uint8_t index,
>     bool state
> ) noexcept;
> ```
> 指定したビットを任意の値に変更します  
> `state` が `true` のとき `1`  
> `state` が `false` のとき `0`

##### BinaryArray::read(uint8_t)
> ```c++
> bool read(
>     uint8_t index
> ) const noexcept;
> ```
> 指定したビットが `1` であれば `true`  
> `0` であれば `false` を返します

##### BinaryArray::get()
> ```c++
> const std::array<uint8_t, ARRAY_SIZE> get() const noexcept;
> ```
> 内部で定義しているビット配列をコピーします

[<< 戻る](../INDEX.md)