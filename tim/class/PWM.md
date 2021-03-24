# PWM

## 目次
- [CubeMX](#cubemx)
- [コンストラクタ](#コンストラクタ)
  - [PWM(TIM_HandleTypeDef, uint32_t)](#pwmpwmtim_handletypedef-uint32_t)
- [関数](#関数)
  - [start()](#pwmstart)
  - [stop()](#pwmstop)
  - [setCompare(uint32_t)](#pwmsetcompareuint32_t)
  - [setCompare(uint16_t, uint16_t)](#pwmsetcompareuint16_t-uint16_t)
  - [getCounterPeriod()](#pwmgetcounterperiod)

## CubeMX
```yaml
PinOut: TIMn_CHm
TIMn:
  - Channelm を PWM Generation CHm に設定
  - Counter Period を好きな値に設定
    N 段階に設定したい場合 N-1 に設定してください
  - Prescaler を以下の式で得られた値に設定
    t = APB timer clocks (Clock Configurationで確認可能)
    f = 設定したい周波数 (低くなく高くなく。1kHzが目安)
    c = Counter Period
    Prescaler = t ÷ f ÷ c
```

## コンストラクタ
##### PWM::PWM(TIM_HandleTypeDef, uint32_t)
> ```c++
> PWM(
>     TIM_HandleTypeDef *htim,
>     uint32_t channel
> );
> ```
> ```c++
> PWM(
>     TIM_HandleTypeDef &htim,
>     uint32_t channel
> );
> ```
> ピンを設定します  
> ```c++
> // 例
> PWM pwm(&htim2, TIM_CHANNEL_1);
> PWM pwm(htim2, TIM_CHANNEL_1);
> ```

## 関数
##### PWM::start()
> ```c++
> void start() const noexcept;
> ```
> `HAL_TIM_PWM_Start()` を実行します  
> ```c++
> // 例
> pwm.start();
> ```

##### PWM::stop()
> ```c++
> void stop() const noexcept;
> ```
> `HAL_TIM_PWM_Stop()` を実行します  
> ```c++
> // 例
> pwm.stop();
> ```

##### PWM::setCompare(uint32_t)
> ```c++
> void setCompare(
>     uint32_t compare
> ) const noexcept;
> ```
> `__HAL_TIM_SET_COMPARE()` を実行します  
> ```c++
> // 例
> pwm.setCompare(100);
> ```

##### PWM::setCompare(uint16_t, uint16_t)
> ```c++
> void setCompare(
>     uint16_t numerator,
>     uint16_t denominator
> ) const noexcept;
> ```
> numerator: 分子, denominator: 分母 とした デューティ比で `setCompare(uint32_t)` を実行します
> 100% を超えている時は何もしません
> ```c++
> // 例
> pwm.setCompare(97, 100); // デューティー比: 97%
> pwm.setCompare(1, 2); // デューティー比: 50%
> ```

##### PWM::getCounterPeriod()
> ```c++
> uint32_t getCounterPeriod() const noexcept;
> ```
> CounterPeriod を返します  
> ```c++
> // 例
> uint32_t counterPeriod = pwm.getCounterPeriod();
> ```

[<< 戻る](../INDEX.md)