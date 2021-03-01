# HAL_Extension - 5.4.1

```c++
#include "HAL_Extension.hpp
```

```c++
namespace halex
```

## 目次
- [General](Doc/General/INDEX.md)
  - [コンフィグ](Doc/General/INDEX.md#コンフィグ)
    - [CONFIG_DISABLE_EX_CALLBACK](Doc/General/INDEX.md#config_disable_ex_callback)
- [Util](Doc/Util/INDEX.md)
  - [関数](Doc/Util/INDEX.md#関数)
    - [std::map](Doc/Util/function/map.md)
    - [math_angle](Doc/Util/function/math_angle.md)
  - [列挙クラス](Doc/Util/INDEX.md#列挙クラス)
    - [AngleType](Doc/Util/enum/AngleType.md)
  - [クラス](Doc/Util/INDEX.md#クラス)
    - [StopWatch](Doc/Util/class/StopWatch.md)
    - [BinaryArray](Doc/Util/class/BinaryArray.md)
    - [BinaryArrayRef](Doc/Util/class/BinaryArrayRef.md)
- [GPIO](Doc/GPIO/INDEX.md)
  - [コンフィグ](Doc/GPIO/INDEX.md#コンフィグ)
    - [CONFIG_DISABLE_MODULE_GPIO](Doc/GPIO/INDEX.md#CONFIG_DISABLE_MODULE_GPIO)
  - [関数](Doc/GPIO/INDEX.md#関数)
    - [GPIO](Doc/GPIO/function/INDEX.md#gpio)
  - [クラス](Doc/GPIO/INDEX.md#クラス)
    - [GPIO](Doc/GPIO/class/GPIO.md)
    - [DIPSwitch](Doc/GPIO/class/DIPSwitch.md)
    - [SevenSegment](Doc/GPIO/class/SevenSegment.md)
    - [FixedSevenSegment](Doc/GPIO/class/FixedSevenSegment.md)
    - [DynamicSevenSegment](Doc/GPIO/class/DynamicSevenSegment.md)
- [UART](Doc/UART/INDEX.md)
  - [コンフィグ](Doc/UART/INDEX.md#コンフィグ)
    - [CONFIG_DISABLE_MODULE_UART](Doc/UART/INDEX.md#CONFIG_DISABLE_MODULE_UART)
    - [CONFIG_USE_HALF_CALLBACK_UART](Doc/UART/INDEX.md#CONFIG_USE_HALF_CALLBACK_UART)
  - [関数](Doc/UART/INDEX.md#関数)
    - [Transmit](Doc/UART/function/INDEX.md#transmit)
    - [Receive](Doc/UART/function/INDEX.md#receive)
    - [Callback](Doc/UART/function/INDEX.md#callback)
  - [クラス](Doc/UART/INDEX.md#クラス)
    - [UART](Doc/UART/class/UART.md)
    - [UART_IT](Doc/UART/class/UART_IT.md)
    - [UART_DMA](Doc/UART/class/UART_DMA.md)
    - [UART_Logger](Doc/UART/class/UART_Logger.md)
    - [UART_Logger_IT](Doc/UART/class/UART_Logger_IT.md)
- [I2C](Doc/I2C/INDEX.md)
  - [コンフィグ](Doc/I2C/INDEX.md#コンフィグ)
    - [CONFIG_DISABLE_MODULE_I2C](Doc/I2C/INDEX.md#config_disable_module_i2c)
  - [関数](Doc/I2C/INDEX.md#関数)
    - [MasterTransmit](Doc/I2C/function/INDEX.md#mastertransmit)
    - [MasterReceive](Doc/I2C/function/INDEX.md#masterreceive)
    - [SlaveTransmit](Doc/I2C/function/INDEX.md#slavetransmit)
    - [SlaveReceive](Doc/I2C/function/INDEX.md#slavereceive)
    - [Callback](Doc/I2C/function/INDEX.md#callback)
  - [クラス](Doc/I2C/INDEX.md#クラス)
    - [I2C_Master](Doc/I2C/class/I2C_Master.md)
    - [I2C_Master_IT](Doc/I2C/class/I2C_Master_IT.md)
    - [I2C_Master_DMA](Doc/I2C/class/I2C_Master_DMA.md)
    - [I2C_Slave](Doc/I2C/class/I2C_Slave.md)
    - [I2C_Slave_IT](Doc/I2C/class/I2C_Slave_IT.md)
    - [I2C_Slave_DMA](Doc/I2C/class/I2C_Slave_DMA.md)
- [TIM](Doc/TIM/INDEX.md)
  - [コンフィグ](Doc/TIM/INDEX.md#コンフィグ)
    - [CONFIG_DISABLE_MODULE_TIM](Doc/TIM/INDEX.md#config_disable_module_tim)
  - [関数](Doc/TIM/INDEX.md#関数)
    - [Callback](Doc/TIM/function/INDEX.md#callback)
  - [クラス](Doc/TIM/INDEX.md#クラス)
    - [PWM](Doc/TIM/class/PWM.md)
    - [Motor](Doc/TIM/class/Motor.md)
    - [Encoder](Doc/TIM/class/Encoder.md)
    - [TimerInterrupt](Doc/TIM/class/TimerInterrupt.md)
- [ADC](Doc/ADC/INDEX.md)
  - [コンフィグ](Doc/ADC/INDEX.md#コンフィグ)
    - [CONFIG_DISABLE_MODULE_ADC](Doc/ADC/INDEX.md#config_disable_module_adc)
    - [CONFIG_USE_HALF_CALLBACK_ADC](Doc/ADC/INDEX.md#config_use_half_callback_adc)
  - [関数](Doc/ADC/INDEX.md#関数)
    - [setADCCallback](Doc/ADC/function/INDEX.md#setadccallback)
  - [クラス](Doc/ADC/INDEX.md#クラス)
    - [ADC_DMA](Doc/ADC/class/ADC_DMA.md)
- [IWDG](Doc/IWDG/INDEX.md)
  - [コンフィグ](Doc/IWDG/INDEX.md#コンフィグ)
    - [CONFIG_DISABLE_MODULE_IWDG](Doc/IWDG/INDEX.md#config_disable_module_iwdg)
    - [CONFIG_DISABLE_IWDG_CONSTEXPR](Doc/IWDG/INDEX.md#config_disable_iwdg_constexpr)
  - [クラス](Doc/IWDG/INDEX.md#クラス)
    - [IWDG_Manager](Doc/IWDG/class/IWDG_Manager.md)