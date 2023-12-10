# TimerInterrupt

## 目次
- [CubeMX](#cubemx)
- [コンストラクタ](#コンストラクタ)
  - [TimerInterrupt(TIM_HandleTypeDef)](#timerinterrupttimerinterrupttim_handletypedef)
- [関数](#関数)
  - [start()](#timerinterruptstart)
  - [start(uint16_t, uint16_t)](#timerinterruptstartuint16_t-uint16_t)
  - [stop()](#timerinterruptstop)
  - [setCount(uint32_t)](#timerinterruptsetcountuint32_t)
  - [resetCount()](#timerinterruptresetcount)
  - [setCallback(std::function<void()>)](#timerinterruptsetcallbackstdfunctionvoid)

## CubeMX
```yaml
PinOut: TIMを有効にする
NVIC Settings:
  TIMn global interrupt: Enable
```

## コンストラクタ
##### TimerInterrupt::TimerInterrupt(TIM_HandleTypeDef)
> ```c++
> TimerInterrupt(
>     TIM_HandleTypeDef *htim
> );
> ```
> ```c++
> TimerInterrupt(
>     TIM_HandleTypeDef &htim
> );
> ```
> 使うタイマーを設定する
> ```c++
> TimerInterrupt timerInterrupt(&htim15);
> TimerInterrupt timerInterrupt(htim15);
> ```

## 関数
##### TimerInterrupt::start()
> ```c++
> void start() noexcept;
> ```
> タイマーを動かします
> ```c++
> timerInterrupt.start();
> ```

##### TimerInterrupt::start(uint16_t, uint16_t)
> ```c++
> void start(
>     uint16_t prescaler,
>     uint16_t counterPeriod
> ) noexcept;
> ```
> prescaler と counterPeriod を再設定してスタートする
> ```c++
> timerInterrupt.start(1000, 64000);
> ```

##### TimerInterrupt::stop()
> ```c++
> void stop() noexcept;
> ```
> タイマーを止めます
> ```c++
> timerInterrupt.stop();
> ```

##### TimerInterrupt::setCount(uint32_t)
> ```c++
> void setCount(
>     uint32_t count
> ) noexcept;
> ```
> タイマーのカウントを設定します
> ```c++
> timerInterrupt.setCount(0);
> ```

##### TimerInterrupt::resetCount()
> ```c++
> void resetCount() noexcept;
> ```
> タイマーのカウントを０にします
> ```c++
> timerInterrupt.resetCount();
> ```

##### TimerInterrupt::setCallback(std::function<void()>)
> ```c++
> void setCallback(
>     std::function<void()> function
> ) noexcept;
> ```
> タイマ割り込みの処理を設定します
> ```c++
> timerInterrupt.setCallback([]{
>     logger.println("TimerInterrupt");
> });
> ```

[<< 戻る](../README.md)