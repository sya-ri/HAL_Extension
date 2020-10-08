# BinaryArrayRef

## 目次
- [クラステンプレート](#クラステンプレート)
- [コンストラクタ](#コンストラクタ)
  - [BinaryArrayRef(std::array<uint8_t, ARRAY_SIZE>)](#binaryarrayrefbinaryarrayrefstdarrayuint8_t-array_size)
- [関数](#関数)
  - [set(uint8_t)](#binaryarrayrefsetuint8_t)
  - [reset(uint8_t)](#binaryarrayrefresetuint8_t)
  - [write(uint8_t, bool)](#binaryarrayrefwriteuint8_t-bool)
  - [read(uint8_t)](#binaryarrayrefreaduint8_t)

## クラステンプレート
```c++
template <std::size_t ARRAY_SIZE>
```
```yaml
ARRAY_SIZE: ビット配列の要素数
```

## コンストラクタ
##### BinaryArrayRef::BinaryArrayRef(std::array<uint8_t, ARRAY_SIZE>)
> ```c++
> BinaryArrayRef(
>     std::array<uint8_t, ARRAY_SIZE> &array      
> );
> ```
> 参照先の配列を自動で変更します  
> 最下位ビットは `0`  
> 最上位ビットは `ARRAY_SIZE * 8 - 1`
> ```c++
> // 例
> BinaryArrayRef<1> binaryArray(array);
> ```


## 関数

##### BinaryArrayRef::set(uint8_t)
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

##### BinaryArrayRef::reset(uint8_t)
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
> ```c++
> // 例
> binaryArray.write(0, true);
> binaryArray.write(0, false);
> ```

##### BinaryArrayRef::read(uint8_t)
> ```c++
> bool read(
>     uint8_t index
> ) const noexcept;
> ```
> 指定したビットが `1` であれば `true`  
> `0` であれば `false` を返します
> ```c++
> // 例
> if (binaryArray.read(0)) {
> 
> }
> ```

[<< 戻る](../INDEX.md)