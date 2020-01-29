# Hal_Extension - version 1.0

## define

> #### #define getTick() HAL_GetTick()
> HAL_GetTick() の短縮版です

> #### #define delay(__ms) HAL_Delay(__ms)
> HAL_Delay() の短縮版です

> #### #define gpioRead(GPIOx, GPIO_Pin) HAL_GPIO_ReadPin(GPIOx, GPIO_Pin)
> HAL_GPIO_ReadPin() の短縮版です

> #### #define gpioWrite(GPIOx, GPIO_Pin, PinState) HAL_GPIO_WritePin(GPIOx, GPIO_Pin, PinState)
> HAL_GPIO_WritePin() の短縮版です

> #### #define gpioToggle(GPIOx, GPIO_Pin) HAL_GPIO_TogglePin(GPIOx, GPIO_Pin)
> HAL_GPIO_TogglePin() の短縮版です

## class GPIO

### コンストラクタ
> ##### GPIO(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
> Read / Write をするピンを設定します  
> 例: `GPIO pa5(GPIOA, GPIO_PIN_5);`

### 関数
> ##### GPIO_PinState read()
> gpioRead() の結果を返します  
> 例: `pa5.read();`

> ##### void write(GPIO_PinState PinState)
> gpioWrite() を実行します  
> 例: `pa5.write(GPIO_PIN_SET);`  
> 例: `pa5.write(GPIO_PIN_RESET);`

> ##### void set()
> write(GPIO_PIN_SET) を実行します  
> 例: `pa5.set();`

> ##### void reset()
> write(GPIO_PIN_RESET) を実行します  
> 例: `pa5.reset();`

> ##### void toggle()
> gpioToggle() を実行します  
> 例: `pa5.toggle();`

## class UART

#### template\<class T\>

### コンストラクタ

> #### UART(UART_HandleTypeDef &huart)
> ピンを設定します  
> ※ UART<> の中に扱う変数の型を記述します  
> 例: `UART<uint16_t> uart(huart2);`

### 関数

> #### HAL_StatusTypeDef transmit(T &pData, uint32_t timeout)
> HAL_UART_Transmit() の結果を返します  
> 例: `uart.transmit(data, 0x0F);`

> #### HAL_StatusTypeDef receive(T &pData, uint32_t timeout)
> HAL_UART_Receive() の結果を返します  
> 例: `uart.receive(data, 0x0F);`

## class I2C 

#### template\<class T\>

### コンストラクタ
> #### I2C(I2C_HandleTypeDef &hi2c, uint8_t address)
> ピンと自局アドレスを設定します  
> ※ I2C<> の中に扱う変数の型を記述します  
> 例: `I2C<uint16_t> i2c(hi2c1, 0x01);`

### 関数
> #### void init()
> 自局アドレスを反映させます  
> 例: `i2c.init();`

> #### HAL_StatusTypeDef masterTransmit(uint8_t target, T &pData, uint32_t timeout)
> HAL_I2C_Master_Transmit() の結果を返します  
> 例: `i2c.masterTransmit(0x02, data, 0x0F);`

> #### HAL_StatusTypeDef masterReceive(uint8_t target, T &pData, uint32_t timeout)
> HAL_I2C_Master_Receive() の結果を返します  
> 例: `i2c.masterReceive(0x02, data, 0x0F);`

> #### HAL_StatusTypeDef slaveTransmit(T &pData, uint32_t timeout)
> HAL_I2C_Slave_Transmit() の結果を返します  
> 例: `i2c.slaveTransmit(data, 0x0F);`

> #### HAL_StatusTypeDef slaveReceive(T &pData, uint32_t timeout)
> HAL_I2C_Slave_Receive() の結果を返します  
> 例: `i2c.slaveReceive(data, 0x0F);`

## class PWM

### コンストラクタ
> #### PWM(TIM_HandleTypeDef &htim, uint32_t channel)
> ピンを設定します  
> 例: `PWM pwm(htim2, TIM_CHANNEL_1);`

### 関数
> #### void init()
> HAL_TIM_PWM_Start() を実行します  
> 例: `pwm.init();`

> #### bool setCompare(uint32_t compare)
> __HAL_TIM_SET_COMPARE() を実行します  
> compare が CounterPeriod より大きかった場合、正常に動作しないので設定がキャンセルされ、 false が返ります  
> 例: `pwm.setCompare(100);`

> #### uint32_t getCounterPeriod()
> CounterPeriod を返します  
> 例: `pwm.getCounterPeriod();`

## class Motor

### コンストラクタ
> #### Motor(PWM positive, PWM negative)
> 正転と逆転のPWMを設定します  
> 例: `Motor motor(posPwm, negPwm);`

> #### Motor(TIM_HandleTypeDef &htimPos, uint32_t channelPos, TIM_HandleTypeDef &htimNeg, uint32_t channelNeg)
> 正転と逆転のピンを設定します  
> 内部的にはPWMクラスに変換されています  
> 例: `Motor motor(htim2, TIM_CHANNEL_1, htim3, TIM_CHANNEL_1);`

### 関数
> #### bool setSpeed(bool forward, uint32_t compare)
> 正転・逆転 と compare を送ります  
> true が正転 / false が逆転 です  
> PWM::setCompare() の結果を返します  
> 例: `motor.setSpeed(true, 400);`

> #### bool setSpeed(int64_t speed)
> 正の数は正転 / 負の数は逆転  
> 絶対値が compare になります  
> 内部的には setSpeed(bool, uint32_t) を実行しています  
> 処理が多くなるので上記の関数を直接使うことを推奨します  
> 例: `motor.setSpeed(400);`