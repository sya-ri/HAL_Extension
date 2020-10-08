# BinaryArrayRef

## 目次
- [コンストラクタ](#コンストラクタ)
  - [BinaryArrayRef(std::array<uint8_t, ARRAY_SIZE>)](#binaryarrayrefbinaryarrayrefstdarrayuint8_t-array_size)
- [関数](#関数)
  - [set(uint8_t)](#binaryarrayrefsetuint8_t)
  - [reset(uint8_t)](#binaryarrayrefresetuint8_t)
  - [write(uint8_t, bool)](#binaryarrayrefwriteuint8_t-bool)
  - [read(uint8_t)](#binaryarrayrefreaduint8_t)

## コンストラクタ
##### BinaryArrayRef::BinaryArrayRef(std::array<uint8_t, ARRAY_SIZE>)
> ```c++
> BinaryArrayRef(
>     std::array<uint8_t, ARRAY_SIZE> &array      
> );
> ```
> 参照先の配列を自動で変更します

## 関数

##### BinaryArrayRef::set(uint8_t)
> ```c++
> void set(
>     uint8_t index
> ) noexcept;
> ```
> 指定したビットを `1` にします

##### BinaryArrayRef::reset(uint8_t)
> ```c++
> void reset(
>     uint8_t index
> ) noexcept;
> ```
> 指定したビットを `0` にします

##### BinaryArrayRef::write(uint8_t, bool)
> ```c++
> void write(
>     uint8_t index,
>     bool state
> ) noexcept;
> ```
> 指定したビットを任意の値に変更します  
> `state` が `true` のとき `1`  
> `state` が `false` のとき `0`

##### BinaryArrayRef::read(uint8_t)
> ```c++
> bool read(
>     uint8_t index
> ) const noexcept;
> ```
> 指定したビットが `1` であれば `true`  
> `0` であれば `false` を返します

[<< 戻る](../INDEX.md)