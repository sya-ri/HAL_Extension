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

## なぜクラスを使うのか
STM32 HAL は C のライブラリなので、1つ1つの操作を関数として直接呼ぶ形になります。  
一方でロボット制御では、「左モータ」「右モータ」「このエンコーダ」「このサーボ」のように、部品ごとに状態と操作をまとめて扱いたい場面が多くあります。

このライブラリでは、周辺機器や制御対象をクラスとして表現することで、オブジェクト指向を取り入れやすくしています。  
これにより、ロボットを配線や HAL 関数の集まりとしてではなく、役割を持ったパーツの集まりとして考えやすくなります。

例えば `Motor` クラスなら、正転用と逆転用の PWM をひとまとめにして、「モータを回す」という単位で扱えます。

```c++
halex::Motor leftMotor(&htim2, TIM_CHANNEL_1, &htim2, TIM_CHANNEL_2);
halex::Motor rightMotor(&htim3, TIM_CHANNEL_1, &htim3, TIM_CHANNEL_2);

leftMotor.start();
rightMotor.start();

leftMotor.setSpeed(true, 500);
rightMotor.setSpeed(true, 500);
```

HAL を直接使うこと自体を否定するものではありませんが、クラスにすることで次のような利点があります。
- 部品ごとに責務を分けて考えやすい
- 状態と操作を同じ場所にまとめられる
- 初期化や設定の再利用がしやすい
- ロボット全体をパーツの組み合わせとして設計しやすい

HAL_Extension は、STM32 HAL の上に薄くクラスを重ねることで、組み込みでもオブジェクト指向を使いやすくすることを目的としています。

## 目次
- [Util](util/README.md)
  - [関数](util/README.md#関数)
    - [General](util/function/general.md)
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
    - [Button](gpio/class/Button.md)
    - [BooleanStateButton](gpio/class/BooleanStateButton.md)
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
- [CAN](can/README.md)
  - [列挙クラス](can/README.md#列挙クラス)
    - [CAN_IdentifierType](can/enum/CAN_IdentifierType.md)
    - [CAN_RemoteTransmissionRequest](can/enum/CAN_RemoteTransmissionRequest.md)
  - [クラス](can/README.md#クラス)
    - [CAN_Communication](can/class/CAN_Communication.md)
    - [CAN_FilterConfig](can/class/CAN_FilterConfig.md)
    - [CAN_TransmitMessage](can/class/CAN_TransmitMessage.md)
    - [CAN_TransmitResult](can/class/CAN_TransmitResult.md)
    - [CAN_ReceiveMessage](can/class/CAN_ReceiveMessage.md)
- [TIM](tim/README.md)
  - [関数](tim/README.md#関数)
    - [Callback](tim/function/README.md#callback)
  - [クラス](tim/README.md#クラス)
    - [PWM](tim/class/PWM.md)
    - [ServoMotor](tim/class/ServoMotor.md)
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
