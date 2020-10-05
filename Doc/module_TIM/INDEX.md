# module TIM

## コンフィグ
> #### CONFIG_DISABLE_MODULE_TIM
> TIM モジュールの無効化  
> 定義することでコンパイルされなくなります

## 関数
- [Callback](function/INDEX.md#callback)
  - [setTIMPeriodElapsedCallback](function/INDEX.md#settimperiodelapsedcallback)

## クラス
- [PWM](class/PWM.md)
  - [CubeMX](class/PWM.md#cubemx)
  - [コンストラクタ](class/PWM.md#コンストラクタ)
    - [PWM(TIM_HandleTypeDef, uint32_t)](class/PWM.md#pwmpwmtim_handletypedef-uint32_t)
  - [関数](class/PWM.md#関数)
    - [start()](class/PWM.md#pwmstart)
    - [stop()](class/PWM.md#pwmstop)
    - [setCompare(uint32_t)](class/PWM.md#pwmsetcompareuint32_t)
    - [setCompare(uint16_t, uint16_t)](class/PWM.md#pwmsetcompareuint16_t-uint16_t)
    - [getCounterPeriod()](class/PWM.md#pwmgetcounterperiod)
- [Motor](class/Motor.md)
  - [CubeMX](class/Motor.md#cubemx)
  - [コンストラクタ](class/Motor.md#コンストラクタ)
    - [Motor(PWM, PWM)](class/Motor.md#motormotorpwm-pwm)
    - [Motor(TIM_HandleTypeDef, uint32_t, TIM_HandleTypeDef, uint32_t)](class/Motor.md#motormotortim_handletypedef-uint32_t-tim_handletypedef-uint32_t)
  - [関数](class/Motor.md#関数)
    - [start()](class/Motor.md#motorstart)
    - [stop()](class/Motor.md#motorstop)
    - [setCompare(uint32_t, uint32_t)](class/Motor.md#motorsetcompareuint32_t-uint32_t)
    - [setSpeed(bool, uint32_t)](class/Motor.md#motorsetspeedbool-uint32_t)
    - [setSpeed(bool, uint16_t, uint16_t)](class/Motor.md#motorsetspeedbool-uint16_t-uint16_t)
    - [setSpeed(int64_t)](class/Motor.md#motorsetspeedint64_t)
    - [setSpeed(int16_t, int16_t)](class/Motor.md#motorsetspeedint16_t-int16_t)
- [Encoder](class/Encoder.md)
  - [コンストラクタ](class/Encoder.md#コンストラクタ)
    - [Encoder(TIM_HandleTypeDef)](class/Encoder.md#encoderencodertim_handletypedef)
  - [関数](class/Encoder.md#関数)
    - [start()](class/Encoder.md#encoderstart)
    - [stop()](class/Encoder.md#encoderstop)
    - [update()](class/Encoder.md#encoderupdate)
    - [getCount()](class/Encoder.md#encodergetcount)
    - [resetCount()](class/Encoder.md#encoderresetcount)
- [TimerInterrupt](class/TimerInterrupt.md)
  - [CubeMX](class/TimerInterrupt.md#cubemx)
  - [コンストラクタ](class/TimerInterrupt.md#コンストラクタ)
    - [TimerInterrupt(TIM_HandleTypeDef)](class/TimerInterrupt.md#timerinterrupttimerinterrupttim_handletypedef)
  - [関数](class/TimerInterrupt.md#関数)
    - [start()](class/TimerInterrupt.md#timerinterruptstart)
    - [start(uint16_t, uint16_t)](class/TimerInterrupt.md#timerinterruptstartuint16_t-uint16_t)
    - [stop()](class/TimerInterrupt.md#timerinterruptstop)
    - [setCount(uint32_t)](class/TimerInterrupt.md#timerinterruptsetcountuint32_t)
    - [resetCount()](class/TimerInterrupt.md#timerinterruptresetcount)
    - [setCallback(std::function<void()>)](class/TimerInterrupt.md#timerinterruptsetcallbackstdfunctionvoid)

[<< 戻る](../../README.md)