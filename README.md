# HAL_Extension - 7.0.0

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
  - [関数](gpio/README.md#関数)
    - [GPIO](gpio/function/README.md#gpio)
  - [クラス](gpio/README.md#クラス)
    - [GPIO](gpio/class/GPIO.md)
    - [DIPSwitch](gpio/class/DIPSwitch.md)
    - [SevenSegment](gpio/class/SevenSegment.md)
    - [FixedSevenSegment](gpio/class/FixedSevenSegment.md)
    - [DynamicSevenSegment](gpio/class/DynamicSevenSegment.md)
- [UART](uart/README.md)
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
  - [関数](tim/README.md#関数)
    - [Callback](tim/function/README.md#callback)
  - [クラス](tim/README.md#クラス)
    - [PWM](tim/class/PWM.md)
    - [Motor](tim/class/Motor.md)
    - [Encoder](tim/class/Encoder.md)
    - [TimerInterrupt](tim/class/TimerInterrupt.md)
- [ADC](adc/README.md)
  - [関数](adc/README.md#関数)
    - [setADCCallback](adc/function/README.md#setadccallback)
  - [クラス](adc/README.md#クラス)
    - [ADC_DMA](adc/class/ADC_DMA.md)
- [IWDG](iwdg/README.md)
  - [クラス](iwdg/README.md#クラス)
    - [IWDG_Manager](iwdg/class/IWDG_Manager.md)
