# Motor

## 目次
- [CubeMX](#cubemx)
- [コンストラクタ](#コンストラクタ)
  - [Motor(PWM, PWM)](#motormotorpwm-pwm)
  - [Motor(TIM_HandleTypeDef, uint32_t, TIM_HandleTypeDef, uint32_t)](#motormotortim_handletypedef-uint32_t-tim_handletypedef-uint32_t)
- [関数](#関数)
  - [start()](#motorstart)
  - [stop()](#motorstop)
  - [setCompare(uint32_t, uint32_t)](#motorsetcompareuint32_t-uint32_t)
  - [setSpeed(bool, uint32_t)](#motorsetspeedbool-uint32_t)
  - [setSpeed(bool, uint16_t, uint16_t)](#motorsetspeedbool-uint16_t-uint16_t)
  - [setSpeed(int64_t)](#motorsetspeedint64_t)
  - [setSpeed(int16_t, int16_t)](#motorsetspeedint16_t-int16_t)

## CubeMX
あらかじめ２つの [PWM](PWM.md) を設定してください

## コンストラクタ
##### Motor::Motor(PWM, PWM)
> ```c++
> Motor(
>     const PWM &positive,
>     const PWM &negative
> );
> ```
> 正転と逆転のPWMを設定します  
> ```c++
> // 例
> Motor motor(posPwm, negPwm);
> ```

##### Motor::Motor(TIM_HandleTypeDef, uint32_t, TIM_HandleTypeDef, uint32_t)
> ```c++
> Motor(
>     TIM_HandleTypeDef *htimPos,
>     uint32_t channelPos,
>     TIM_HandleTypeDef *htimNeg,
>     uint32_t channelNeg
> );
> ```
> ```c++
> Motor(
>     TIM_HandleTypeDef &htimPos,
>     uint32_t channelPos,
>     TIM_HandleTypeDef &htimNeg,
>     uint32_t channelNeg
> );
> ```
> 正転と逆転のピンを設定します  
> 内部的にはPWMクラスに変換されています  
> ```c++
> // 例
> Motor motor(&htim2, TIM_CHANNEL_1, &htim3, TIM_CHANNEL_1);
> Motor motor(htim2, TIM_CHANNEL_1, htim3, TIM_CHANNEL_1);
> ```

## 関数
##### Motor::start()
> ```c++
> void start() noexcept;
> ```
> `PWM::start` を実行します  
> ```c++
> // 例
> motor.start();
> ```

##### Motor::stop()
> ```c++
> void stop() noexcept;
> ```
> `PWM::stop` を実行します  
> ```c++
> // 例
> motor.stop();
> ```

##### Motor::setCompare(uint32_t, uint32_t)
> ```c++
> void setCompare(
>     uint32_t comparePos,
>     uint32_t compareNeg
> ) noexcept;
> ```
> `PWM::setCompare` を実行します
> ```c++
> // 例
> motor.setCompare(2000, 2000);
> ```

##### Motor::setSpeed(bool, uint32_t)
> ```c++
> void setSpeed(
>     bool forward,
>     uint32_t compare
> ) noexcept;
> ```
> 正転・逆転 と compare を引数とします  
> true が 正転 / false が 逆転 です  
> ```c++
> // 例
> motor.setSpeed(true, 400);
> motor.setSpeed(false, 400);
> ```

##### Motor::setSpeed(bool, uint16_t, uint16_t)
> ```c++
> void setSpeed(
>     bool forward,
>     uint16_t numerator,
>     uint16_t denominator
> ) noexcept;
> ```
> 正転・逆転 と numerator: 分子, denominator: 分母 とした デューティ比 を引数とします  
> 100% を超えている時は何もしません  
> true が 正転 / false が 逆転 です
> ```c++
> // 例
> motor.setSpeed(false, 97, 100);
> motor.setSpeed(true, 1, 2);
> ```

##### Motor::setSpeed(int64_t)
> ```c++
> void setSpeed(
>     int64_t speed
> ) noexcept;
> ```
> 正の数は正転 / 負の数は逆転 として `setSpeed(bool, uint32_t)` を実行します  
> 処理が多くなるので `setSpeed(bool, uint32_t)` を直接使うことを推奨します
> ```c++
> // 例
> motor.setSpeed(400);
> motor.setSpeed(-400);
> ```

##### Motor::setSpeed(int16_t, int16_t)
> ```c++
> void setSpeed(
>     int16_t numerator,
>     int16_t denominator
> ) noexcept;
> ```
> 正の数は正転 / 負の数は逆転 として `setSpeed(bool, uint16_t, uint16_t)` を実行します  
> 処理が多くなるので `setSpeed(bool, uint16_t, uint16_t)` を直接使うことを推奨します
> ```c++
> // 例
> motor.setSpeed(-97, 100);
> motor.setSpeed(97, -100);
> motor.setSpeed(1, 2);
> motor.setSpeed(-1, -2);
> ```

[<< 戻る](../README.md)