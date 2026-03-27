# ServoMotor

## 目次
- [CubeMX](#cubemx)
- [コンストラクタ](#コンストラクタ)
  - [ServoMotor(PWM)](#servomotorservomotorpwm)
  - [ServoMotor(TIM_HandleTypeDef, uint32_t)](#servomotorservomotortim_handletypedef-uint32_t)
- [関数](#関数)
  - [getHandle()](#servomotorgethandle)
  - [equals(TIM_HandleTypeDef*)](#servomotorequalstim_handletypedef)
  - [equals(TIM_HandleTypeDef&)](#servomotorequalstim_handletypedef-1)
  - [init(uint16_t)](#servomotorinituint16_t)
  - [start()](#servomotorstart)
  - [stop()](#servomotorstop)
  - [setPulseWidthRange(float, float, uint16_t, uint16_t)](#servomotorsetpulsewidthrangefloat-float-uint16_t-uint16_t)
  - [setAngle(float)](#servomotorsetanglefloat)
  - [setAngle(bool, float)](#servomotorsetanglebool-float)
  - [setRelativeAngle(float)](#servomotorsetrelativeanglefloat)
  - [setRelativeAngle(bool, float)](#servomotorsetrelativeanglebool-float)
  - [setAngleWithTime(float, uint32_t)](#servomotorsetanglewithtimefloat-uint32_t)
  - [setPulseWidth(uint16_t)](#servomotorsetpulsewidthuint16_t)
  - [getAngle()](#servomotorgetangle)
  - [getPulseWidth()](#servomotorgetpulsewidth)

## CubeMX
```yaml
PinOut: TIMn_CHm
TIMn:
  - Channelm を PWM Generation CHm に設定
  - Counter Period / Prescaler は init() で上書きされるのでデフォルトのままでよい
```

## コンストラクタ
##### ServoMotor::ServoMotor(PWM)
> ```c++
> ServoMotor(
>     const PWM &pwm
> );
> ```
> 使う PWM を設定します
> ```c++
> PWM pwm(&htim3, TIM_CHANNEL_1);
> ServoMotor servo(pwm);
> ```

##### ServoMotor::ServoMotor(TIM_HandleTypeDef, uint32_t)
> ```c++
> ServoMotor(
>     TIM_HandleTypeDef *htim,
>     uint32_t channel
> );
> ```
> ```c++
> ServoMotor(
>     TIM_HandleTypeDef &htim,
>     uint32_t channel
> );
> ```
> 使うタイマとチャンネルを設定します
> ```c++
> ServoMotor servo(&htim3, TIM_CHANNEL_1);
> ServoMotor servo(htim3, TIM_CHANNEL_1);
> ```

## 関数
##### ServoMotor::getHandle()
> ```c++
> TIM_HandleTypeDef* getHandle() const noexcept;
> ```
> 設定されている TIM ハンドルを返します

##### ServoMotor::equals(TIM_HandleTypeDef*)
##### ServoMotor::equals(TIM_HandleTypeDef&)
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

##### ServoMotor::init(uint16_t)
> ```c++
> void init(
>     uint16_t frequency
> ) noexcept;
> ```
> サーボ向け PWM 周波数になるように Counter Period と Prescaler を設定します
> ```c++
> servo.init(333);
> ```

##### ServoMotor::start()
> ```c++
> void start() const noexcept;
> ```
> `PWM::start` を実行します
> ```c++
> servo.start();
> ```

##### ServoMotor::stop()
> ```c++
> void stop() const noexcept;
> ```
> `PWM::stop` を実行します
> ```c++
> servo.stop();
> ```

##### ServoMotor::setPulseWidthRange(float, float, uint16_t, uint16_t)
> ```c++
> void setPulseWidthRange(
>     float minAngle,
>     float maxAngle,
>     uint16_t minPulseWidth,
>     uint16_t maxPulseWidth
> ) noexcept;
> ```
> 角度とパルス幅の対応範囲を設定します
> ```c++
> servo.setPulseWidthRange(0.0f, 180.0f, 1000, 2000);
> ```

##### ServoMotor::setAngle(float)
> ```c++
> void setAngle(
>     float angle
> ) noexcept;
> ```
> 指定角度へ移動します
> 範囲外の角度は `setPulseWidthRange` で設定した範囲に丸められます
> ```c++
> servo.setAngle(90.0f);
> ```

##### ServoMotor::setAngle(bool, float)
> ```c++
> void setAngle(
>     bool forward,
>     float angle
> ) noexcept;
> ```
> `forward == true` なら正方向, `false` なら負方向として角度を設定します

##### ServoMotor::setRelativeAngle(float)
> ```c++
> void setRelativeAngle(
>     float relativeAngle
> ) noexcept;
> ```
> 現在角度からの相対角度で移動します

##### ServoMotor::setRelativeAngle(bool, float)
> ```c++
> void setRelativeAngle(
>     bool forward,
>     float relativeAngle
> ) noexcept;
> ```
> `forward == true` なら正方向, `false` なら負方向として相対角度を設定します

##### ServoMotor::setAngleWithTime(float, uint32_t)
> ```c++
> void setAngleWithTime(
>     float angle,
>     uint32_t timeOfDistance
> ) noexcept;
> ```
> 指定時間をかけて目標角度へ移動します
> 同じ引数で繰り返し呼び出してください
> ```c++
> servo.setAngleWithTime(180.0f, 1000);
> ```

##### ServoMotor::setPulseWidth(uint16_t)
> ```c++
> void setPulseWidth(
>     uint16_t pulseWidth
> ) noexcept;
> ```
> パルス幅を直接設定します
> 範囲外の値は設定済みの可変範囲内に丸められます

##### ServoMotor::getAngle()
> ```c++
> float getAngle() const noexcept;
> ```
> 現在保持している角度を返します

##### ServoMotor::getPulseWidth()
> ```c++
> uint16_t getPulseWidth() const noexcept;
> ```
> 現在保持しているパルス幅を返します

[<< 戻る](../README.md)
