# HAL_Extension - 6.0.0

```c++
#include "HAL_Extension.hpp
```

```c++
namespace halex
```

```yaml
SourcePath: HAL_Extension/ # フォルダ直下
IncludePath: HAL_Extension/ # フォルダ直下
```

## 目次
- [General](general/README.md)
  - [コンフィグ](general/README.md#コンフィグ)
    - [CONFIG_DISABLE_EX_CALLBACK](general/README.md#config_disable_ex_callback)
- [Util](util/README.md)
  - [関数](util/README.md#関数)
    - [std::map](util/function/map.md)
    - [math_angle](util/function/math_angle.md)
  - [列挙クラス](util/README.md#列挙クラス)
    - [AngleType](util/enum/AngleType.md)
  - [クラス](util/README.md#クラス)
    - [StopWatch](util/class/StopWatch.md)
    - [BinaryArray](util/class/BinaryArray.md)
    - [BinaryArrayRef](util/class/BinaryArrayRef.md)
- [GPIO](gpio/README.md)
  - [コンフィグ](gpio/README.md#コンフィグ)
    - [CONFIG_DISABLE_MODULE_GPIO](gpio/README.md#CONFIG_DISABLE_MODULE_GPIO)
  - [関数](gpio/README.md#関数)
    - [GPIO](gpio/function/README.md#gpio)
  - [クラス](gpio/README.md#クラス)
    - [GPIO](gpio/class/GPIO.md)
    - [DIPSwitch](gpio/class/DIPSwitch.md)
    - [SevenSegment](gpio/class/SevenSegment.md)
    - [FixedSevenSegment](gpio/class/FixedSevenSegment.md)
    - [DynamicSevenSegment](gpio/class/DynamicSevenSegment.md)
- [UART](uart/README.md)
  - [コンフィグ](uart/README.md#コンフィグ)
    - [CONFIG_DISABLE_MODULE_UART](uart/README.md#CONFIG_DISABLE_MODULE_UART)
    - [CONFIG_USE_HALF_CALLBACK_UART](uart/README.md#CONFIG_USE_HALF_CALLBACK_UART)
  - [関数](uart/README.md#関数)
    - [Transmit](uart/function/README.md#transmit)
    - [Receive](uart/function/README.md#receive)
    - [Callback](uart/function/README.md#callback)
  - [クラス](uart/README.md#クラス)
    - [UART](uart/class/UART.md)
    - [UART_IT](uart/class/UART_IT.md)
    - [UART_DMA](uart/class/UART_DMA.md)
    - [UART_Logger](uart/class/UART_Logger.md)
    - [UART_Logger_IT](uart/class/UART_Logger_IT.md)
- [I2C](i2c/README.md)
  - [コンフィグ](i2c/README.md#コンフィグ)
    - [CONFIG_DISABLE_MODULE_I2C](i2c/README.md#config_disable_module_i2c)
  - [関数](i2c/README.md#関数)
    - [MasterTransmit](i2c/function/README.md#mastertransmit)
    - [MasterReceive](i2c/function/README.md#masterreceive)
    - [SlaveTransmit](i2c/function/README.md#slavetransmit)
    - [SlaveReceive](i2c/function/README.md#slavereceive)
    - [Callback](i2c/function/README.md#callback)
  - [クラス](i2c/README.md#クラス)
    - [I2C_Master](i2c/class/I2C_Master.md)
    - [I2C_Master_IT](i2c/class/I2C_Master_IT.md)
    - [I2C_Master_DMA](i2c/class/I2C_Master_DMA.md)
    - [I2C_Slave](i2c/class/I2C_Slave.md)
    - [I2C_Slave_IT](i2c/class/I2C_Slave_IT.md)
    - [I2C_Slave_DMA](i2c/class/I2C_Slave_DMA.md)
- [TIM](tim/README.md)
  - [コンフィグ](tim/README.md#コンフィグ)
    - [CONFIG_DISABLE_MODULE_TIM](tim/README.md#config_disable_module_tim)
  - [関数](tim/README.md#関数)
    - [Callback](tim/function/README.md#callback)
  - [クラス](tim/README.md#クラス)
    - [PWM](tim/class/PWM.md)
    - [Motor](tim/class/Motor.md)
    - [Encoder](tim/class/Encoder.md)
    - [TimerInterrupt](tim/class/TimerInterrupt.md)
- [ADC](adc/README.md)
  - [コンフィグ](adc/README.md#コンフィグ)
    - [CONFIG_DISABLE_MODULE_ADC](adc/README.md#config_disable_module_adc)
    - [CONFIG_USE_HALF_CALLBACK_ADC](adc/README.md#config_use_half_callback_adc)
  - [関数](adc/README.md#関数)
    - [setADCCallback](adc/function/README.md#setadccallback)
  - [クラス](adc/README.md#クラス)
    - [ADC_DMA](adc/class/ADC_DMA.md)
- [IWDG](iwdg/README.md)
  - [コンフィグ](iwdg/README.md#コンフィグ)
    - [CONFIG_DISABLE_MODULE_IWDG](iwdg/README.md#config_disable_module_iwdg)
    - [CONFIG_DISABLE_IWDG_CONSTEXPR](iwdg/README.md#config_disable_iwdg_constexpr)
  - [クラス](iwdg/README.md#クラス)
    - [IWDG_Manager](iwdg/class/IWDG_Manager.md)