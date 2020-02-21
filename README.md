# Hal_Extension - version 2.1

## define
> #### getTick()
> ###### ― HAL_GetTick()

> #### delay(__ms)
> ###### ― HAL_Delay(__ms)

> #### gpioRead(GPIOx, GPIO_Pin)
> ###### ― HAL_GPIO_ReadPin(GPIOx, GPIO_Pin)

> #### gpioWrite(GPIOx, GPIO_Pin, PinState)
> ###### ― HAL_GPIO_WritePin(GPIOx, GPIO_Pin, PinState)

> #### gpioToggle(GPIOx, GPIO_Pin)
> ###### ― HAL_GPIO_TogglePin(GPIOx, GPIO_Pin)

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

## class DIPSwitch

### コンストラクタ
> ##### DIPSwitch()
> 例: `DIPSwitch dip;`

### 関数
> ##### bool add(GPIO gpio)
> スイッチのピンを追加します  
> 最大登録数は7つです  
> 例: `dip.add(pa5);`

> ##### bool add(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
> `bool add(GPIO gpio)` の結果を返します   
> 例: `dip.add(GPIOA, GPIO_PIN_5);`

> ##### uint8_t getSize()
> 追加済みのスイッチ数を取得します  
> 例: `dip.getSize();`

> ##### uint8_t getAddress()
> 追加したスイッチを使用してアドレスを取得します  
> 例: `dip.getAddress();`

## class UART
#### template\<class T\>

### コンストラクタ

> #### UART(UART_HandleTypeDef &huart)
> ピンを設定します  
> 例: `UART<uint16_t> uart(huart2);`

### 関数

> #### HAL_StatusTypeDef transmit(T &pData, uint32_t timeout)
> HAL_UART_Transmit() の結果を返します  
> 例: `uart.transmit(data, 0x0F);`

> #### HAL_StatusTypeDef receive(T &pData, uint32_t timeout)
> HAL_UART_Receive() の結果を返します  
> 例: `uart.receive(data, 0x0F);`

## class UART_DMA
#### template\<class T\>

### コンフィグ
> ###### CONFIG_UART_USE_HALF_CALLBACK
> コールバック関数をハーフに変更します  
> 実行されない場合に定義してください

### コンストラクタ
> #### UART_DMA(UART_HandleTypeDef &huart, T &data)
> ピンと連携させる変数を設定します  
> 例: `UART_DMA<uint16_t> uart(huart2, data);`

### 関数
> #### HAL_StatusTypeDef startTransmit()
> 連携させた変数の値を使い、送信を始めます  
> HAL_UART_Transmit_DMA の結果を返します  
> 例: `uart.startTransmit();`

> #### HAL_StatusTypeDef startReceive()
> 受信を始めます  
> 連携させた変数の値が自動で変わります  
> HAL_UART_Receive_DMA の結果を返します  
> 例: `uart.startReceive();`

> #### HAL_StatusTypeDef pause()
> 送受信を一時停止します  
> HAL_UART_DMAPause の結果を返します  
> 例: `uart.pause();`

> #### HAL_StatusTypeDef resume()
> 送受信を再開します  
> HAL_UART_DMAResume の結果を返します  
> 例: `uart.resume();`

> #### HAL_StatusTypeDef stop()
> 送受信を終了します  
> HAL_UART_DMAStop の結果を返します  
> 例: `uart.stop();`

> #### void setTxCallback(std::function<void()> function)
> 送信完了時の割り込み関数を設定します  
> ```c++
> 例:
> uart.setTxCallback([]{
>     logger.println("Tx\n");
> });
> ```

> #### void setRxCallback(std::function<void()> function)
> 受信完了時の割り込み関数を設定します  
> ```c++
> 例:
> uart.setRxCallback([]{
>     logger.println("Rx\n");
> });
> ```

> #### void setErrorCallback(std::function<void()> function)
> エラー取得時の割り込み関数を設定します  
> ```c++
> 例:
> uart.setErrorCallback([]{
>     logger.println("Error\n");
> });
> ```

## class UART_Logger

### コンストラクタ
> ### UART_Logger(UART_HandleTypeDef &huart, uint32_t timeout = 0x0F)
> ピンとタイムアウト時間を設定します  
> 例: `UART_Logger logger(huart2);`

### 関数
> #### void print(const char* text)
> 一文字ずつ送信します  
> 例: `logger.print("Hello");`

> #### void println(const char* text)
> 送信後に改行します  
> 例: `logger.println("HelloWorld");`

## class I2C_Master 
#### template\<class T\>

### コンストラクタ
> #### I2C_Master(I2C_HandleTypeDef &hi2c)
> ピンを設定します  
> 例: `I2C_Master<uint16_t> master(hi2c1);`

### 関数
> #### void init()
> 再初期化します  
> 例: `master.init();`

> #### HAL_StatusTypeDef transmit(uint8_t target, T &pData, uint32_t timeout)
> HAL_I2C_Master_Transmit() の結果を返します  
> 例: `master.transmit(0x02, data, 0x0F);`

> #### HAL_StatusTypeDef receive(uint8_t target, T &pData, uint32_t timeout)
> HAL_I2C_Master_Receive() の結果を返します  
> 例: `master.receive(0x02, data, 0x0F);`

## class I2C_Slave 
#### template\<class T\>

### コンストラクタ
> #### I2C_Slave(I2C_HandleTypeDef &hi2c, uint8_t address = 0x00)
> ピンと自局アドレスを設定します  
> 例: `I2C_Slave<uint16_t> slave(hi2c1, 0x01);`

### 関数
> #### void init()
> 自局アドレスを反映させ、再初期化します  
> 例: `slave.init();`

> #### void init(uint8_t address)
> 自局アドレスを上書きし、再初期化します  
> 例: `slave.init(0x01);`

> #### void init(DIPSwitch builder)
> 自局アドレスを上書きし、再初期化します  
> 例: `slave.init(dip);`

> #### HAL_StatusTypeDef transmit(T &pData, uint32_t timeout)
> HAL_I2C_Slave_Transmit() の結果を返します  
> 例: `slave.transmit(data, 0x0F);`

> #### HAL_StatusTypeDef receive(T &pData, uint32_t timeout)
> HAL_I2C_Slave_Receive() の結果を返します  
> 例: `slave.receive(data, 0x0F);`

## class I2C_Master_DMA
#### template\<class T\>

### コンストラクタ
> #### I2C_Master_DMA(I2C_HandleTypeDef &hi2c, uint8_t target, T &data)
> ピンと送信先アドレス・連携させる変数を設定します  
> 例: `I2C_Master_DMA<uint16_t> master(hi2c1, 0x01, data);`

### 関数
> #### void init()
> 再初期化します  
> 例: `master.init();`

> #### HAL_StatusTypeDef startTransmit()
> HAL_I2C_Master_Transmit_DMA() の結果を返します  
> 例: `master.startTransmit();`

> #### HAL_StatusTypeDef startReceive()
> HAL_I2C_Master_Receive_DMA() の結果を返します  
> 例: `master.startReceive();`

> #### void setTxCallback(std::function<void()> function)
> 送信完了時の割り込み関数を設定します  
> ```c++
> 例:
> master.setTxCallback([]{
>     logger.println("Tx\n");
> });
> ```

> #### void setRxCallback(std::function<void()> function)
> 受信完了時の割り込み関数を設定します
> ```c++
> 例:
> master.setRxCallback([]{
>     logger.println("Rx\n");
> });
> ```

## class I2C_Slave_DMA

### コンストラクタ
> #### I2C_Slave_DMA(I2C_HandleTypeDef &hi2c, uint8_t address = 0x00, T &data)
> ピンと自局アドレス・連携させた変数を設定します  
> 例: `I2C_Slave_DMA<uint16_t> slave(hi2c1, 0x01, data);`

### 関数
> #### void init()
> 自局アドレスを反映させ、再初期化します  
> 例: `slave.init();`

> #### void init(uint8_t address)
> 自局アドレスを上書きし、再初期化します  
> 例: `slave.init(0x01);`

> #### void init(DIPSwitch builder)
> 自局アドレスを上書きし、再初期化します  
> 例: `slave.init(dip);`

> #### HAL_StatusTypeDef startTransmit()
> HAL_I2C_Slave_Transmit_DMA() の結果を返します  
> 例: `slave.startTransmit();`

> #### HAL_StatusTypeDef startReceive()
> HAL_I2C_Slave_Receive_DMA() の結果を返します  
> 例: `slave.startReceive();`

> #### void setTxCallback(std::function<void()> function)
> 送信完了時の割り込み関数を設定します  
> ```c++
> 例:
> slave.setTxCallback([]{
>     logger.println("Tx");
> });
> ```

> #### void setRxCallback(std::function<void()> function)
> 受信完了時の割り込み関数を設定します
> ```c++
> 例:
> slave.setRxCallback([]{
>     logger.println("Rx");
> });
> ```

## class PWM

### コンストラクタ
> #### PWM(TIM_HandleTypeDef &htim, uint32_t channel)
> ピンを設定します  
> 例: `PWM pwm(htim2, TIM_CHANNEL_1);`

### 関数
> #### void start()
> HAL_TIM_PWM_Start() を実行します  
> 例: `pwm.start();`

> #### void stop()
> HAL_TIM_PWM_Stop() を実行します  
> 例: `pwm.stop();`

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
> #### void start()
> PWM::start を実行します  
> 例: `motor.start();`

> #### void stop()
> PWM::stop を実行します  
> 例: `motor.stop();`

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

## class ADC_DMA

### コンフィグ
> ###### CONFIG_ADC_USE_HALF_CALLBACK
> コールバック関数をハーフに変更します  
> 実行されない場合に定義してください

### コンストラクタ
> #### ADC_DMA(ADC_HandleTypeDef &hadc, uint8_t numberOfConversions)
> ピンとDMAを行う数を設定します  
> 例: `ADC_DMA adc(hadc1, 2);`

### 関数
> #### void start()
> ADCを開始します  
> 例: `adc.start();`

> #### void stop()
> ADCを終了します  
> 例: `adc.stop();`

> #### uint32_t get(uint8_t index)
> ADCバッファの値を返します  
> index が numberOfConversions を超えている場合、  
> バッファの範囲外なので std::out_of_range が発生します
> 例: `adc.get(0);`

> #### void setCallback(std::function<void()> function)
> ADC完了時の割り込み関数を設定します
> ```c++
> 例:
> master.setCallback([]{
>     logger.println("Complete");
> });
> ```
