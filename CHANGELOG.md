# 変更履歴

## v2.3
- クラスを追加
  - UART_IT
  - I2C_Master_IT
  - I2C_Slave_IT
  - Encoder

## v2.2
- I2C_Slave_DMA を変更  
送受信に使う変数をコンストラクタで渡すように変更

## v2.1
- クラスを追加
  - UART_Logger

## v2.0
- クラスを追加
  - DIPSwitch
  - UART_DMA
  - I2C_Master
  - I2C_Slave
  - I2C_Master_DMA
  - I2C_Slave_DMA
  - ADC_DMA
- クラスを削除
  - I2C

## v1.0
- 短縮関数を追加
  - getTick
  - delay
  - gpioRead
  - gpioWrite
  - gpioToggle
- クラスを追加
  - GPIO
  - UART
  - I2C
  - PWM
  - Motor