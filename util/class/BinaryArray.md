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
> 最下位ビットは `0`  
> 最上位ビットは `ARRAY_SIZE * 8 - 1`
> ```c++
> // 例
> BinaryArray<1> binaryArray;
> ```

## 関数

##### BinaryArray::set(uint8_t)
> ```c++
> void set(
>     uint8_t index
> ) noexcept;
> ```
> 指定したビットを `1` にします
> ```c++
> // 例
> binaryArray.set(0);
> ```

##### BinaryArray::reset(uint8_t)
> ```c++
> void reset(
>     uint8_t index
> ) noexcept;
> ```
> 指定したビットを `0` にします
> ```c++
> // 例
> binaryArray.reset(0);
> ```

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
> ```c++
> // 例
> binaryArray.write(0, true);
> binaryArray.write(0, false);
> ```

##### BinaryArray::read(uint8_t)
> ```c++
> bool read(
>     uint8_t index
> ) noexcept;
> ```
> 指定したビットが `1` であれば `true`  
> `0` であれば `false` を返します
> ```c++
> // 例
> if (binaryArray.read(0)) {
> 
> }
> ```

##### BinaryArray::get()
> ```c++
> const std::array<uint8_t, ARRAY_SIZE> get() const noexcept;
> ```
> 内部で定義しているビット配列をコピーします
> ```c++
> // 例
> binaryArray.get();
> ```

[<< 戻る](../README.md)