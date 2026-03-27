# Encoder

## 目次
- [コンストラクタ](#コンストラクタ)
  - [Encoder(TIM_HandleTypeDef)](#encoderencodertim_handletypedef)
- [関数](#関数)
  - [getHandle()](#encodergethandle)
  - [equals(TIM_HandleTypeDef*)](#encoderequalstim_handletypedef)
  - [equals(TIM_HandleTypeDef&)](#encoderequalstim_handletypedef-1)
  - [start()](#encoderstart)
  - [stop()](#encoderstop)
  - [update()](#encoderupdate)
  - [getCount()](#encodergetcount)
  - [setCount(int32_t)](#encodersetcountint32_t)
  - [resetCount()](#encoderresetcount)

## CubeMX
```yaml
TIMn:
  - Combined Channels を Encoder Mode に設定
  - Counter Period を好きな値に設定する
  - Encoder:
    - A相とB相があるエンコーダーの場合、Encoder Mode を TI1 and TI2 に設定してください
    - カウントアップとダウンの方向は Polarity で逆にすることができます
```

## コンストラクタ
##### Encoder::Encoder(TIM_HandleTypeDef)
> ```c++
> Encoder(
>     TIM_HandleTypeDef *htim
> );
> ```
> ```c++
> Encoder(
>     TIM_HandleTypeDef &htim
> );
> ```
> ピンを設定します  
> ```c++
> // 例
> Encoder encoder(&htim2);
> Encoder encoder(htim2);
> ```

## 関数
##### Encoder::getHandle()
> ```c++
> TIM_HandleTypeDef* getHandle() const noexcept;
> ```
> 設定されている TIM ハンドルを返します

##### Encoder::equals(TIM_HandleTypeDef*)
##### Encoder::equals(TIM_HandleTypeDef&)
> ```c++
> bool equals(
>     TIM_HandleTypeDef *htim
> ) const noexcept;
>
> bool equals(
>     TIM_HandleTypeDef &htim
> ) const noexcept;
> ```
> 渡した TIM ハンドルと同じインスタンスか判定します

##### Encoder::start()
> ```c++
> void start() noexcept;
> ```
> カウントを開始します  
> ```c++
> // 例
> encoder.start();
> ```

##### Encoder::stop()
> ```c++
> void stop() noexcept;
> ```
> カウントを停止します  
> ```c++
> // 例
> encoder.stop();
> ```

##### Encoder::update()
> ```c++
> void update() noexcept;
> ```
> カウントを更新します  
> ```c++
> // 例
> encoder.update();
> ```

##### Encoder::getCount()
> ```c++
> int32_t getCount() const noexcept;
> ```
> カウントを取得します  
> ```c++
> // 例
> encoder.getCount();
> ```

##### Encoder::setCount(int32_t)
> ```c++
> void setCount(
>     int32_t count
> ) noexcept;
> ```
> カウントを任意の値に変更します  
> ```c++
> // 例
> encoder.resetCount();
> ```

##### Encoder::resetCount()
> ```c++
> void resetCount() noexcept;
> ```
> カウントを 0 に変更します
> ```c++
> // 例
> encoder.resetCount();
> ```

[<< 戻る](../README.md)
