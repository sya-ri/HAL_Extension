# Encoder

## 目次
- [コンストラクタ](#コンストラクタ)
  - [Encoder(TIM_HandleTypeDef)](#encoderencodertim_handletypedef)
- [関数](#関数)
  - [start()](#encoderstart)
  - [stop()](#encoderstop)
  - [update()](#encoderupdate)
  - [getCount()](#encodergetcount)
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

##### Encoder::resetCount()
> ```c++
> void resetCount() noexcept;
> ```
> カウントを停止します  
> ```c++
> // 例
> encoder.resetCount();
> ```

[<< 戻る](../INDEX.md)