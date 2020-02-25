# HAL_Extension - 2.3.2

### 目次
[#define](#define)  
[class GPIO](#class-gpio)  
[class DIPSwitch](#class-dipswitch)  
[class UART](#class-uart)  
[class UART_DMA](#class-uart_dma)  
[class UART_IT](#class-uart_it)  
[class UART_Logger](#class-uart_logger)  
[class UART_Logger_IT](#class-uart_logger_it)  
[class I2C_Master](#class-i2c_master)  
[class I2C_Slave](#class-i2c_slave)  
[class I2C_Master_DMA](#class-i2c_master_dma)  
[class I2C_Slave_DMA](#class-i2c_slave_dma)  
[class I2C_Master_IT](#class-i2c_master_it)  
[class I2C_Slave_IT](#class-i2c_slave_it)  
[class PWM](#class-pwm)  
[class Motor](#class-motor)  
[class Encoder](#class-encoder)  
[class ADC_DMA](#class-adc_dma)  

## define
#### 関数の短縮
> ##### getTick()
> **HAL_GetTick()**

> ##### delay(__ms)
> **HAL_Delay(__ms)**

> ##### gpioRead(GPIOx, GPIO_Pin)
> **HAL_GPIO_ReadPin(GPIOx, GPIO_Pin)**

> ##### gpioWrite(GPIOx, GPIO_Pin, PinState)
> **HAL_GPIO_WritePin(GPIOx, GPIO_Pin, PinState)**

> ##### gpioToggle(GPIOx, GPIO_Pin)
> **HAL_GPIO_TogglePin(GPIOx, GPIO_Pin)**

#### コンフィグ
> ##### CONFIG_UART_USE_HALF_CALLBACK
> UARTのコールバック関数をハーフに変更します  
> 実行されない場合に定義してください

> ##### CONFIG_ADC_USE_HALF_CALLBACK
> ADCのコールバック関数をハーフに変更します  
> 実行されない場合に定義してください

## class GPIO
### CubeMX
```
PinOut: GPIO_Input / GPIO_Output
```

### コンストラクタ
> ##### GPIO(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
> Read / Write をするピンを設定します  
> ```c++
> 例:
> GPIO pa5(GPIOA, GPIO_PIN_5);
> ```

### 関数
> ##### GPIO_PinState read()
> gpioRead() の結果を返します  
> ```c++
> 例:
> pa5.read();
> ```

> ##### void write(GPIO_PinState PinState)
> gpioWrite() を実行します  
> ```c++
> 例:
> pa5.write(GPIO_PIN_SET);
> pa5.write(GPIO_PIN_RESET);
> ```

> ##### void set()
> write(GPIO_PIN_SET) を実行します  
> ```c++
> 例:
> pa5.set();
> ```

> ##### void reset()
> write(GPIO_PIN_RESET) を実行します  
> ```c++
> 例:
> pa5.reset();
> ```

> ##### void toggle()
> gpioToggle() を実行します  
> ```c++
> 例:
> pa5.toggle();
> ```

## class DIPSwitch
### CubeMX
```
PinOut: GPIO_Input
```

### コンストラクタ
> ##### DIPSwitch(bool flip = false)
> ```c++
> 例:
> DIPSwitch dip;
> DIPSwitch dip(true);
> ```

### 関数
> ##### bool add(GPIO gpio)
> スイッチのピンを追加します  
> 最大登録数は7つです  
> ```c++
> 例:
> dip.add(pa5);
> ```

> ##### bool add(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
> `bool add(GPIO gpio)` の結果を返します  
> ```c++
> 例:
> dip.add(GPIOA, GPIO_PIN_5);
> ```

> ##### uint8_t getSize()
> 追加済みのスイッチ数を取得します  
> ```c++
> 例:
> uint8_t size = dip.getSize();
> ```

> ##### uint8_t getAddress()
> 追加したスイッチを使用してアドレスを取得します  
> flip を有効にしておくと 全ビット反転された結果が出力されます  
> ```c++
> 例:
> uint8_t address = dip.getAddress();
> ```

## class UART
#### template\<class T\>

### CubeMX
```
PinOut: USARTn_TX / USARTn_RX
```

### コンストラクタ
> #### UART(UART_HandleTypeDef &huart)
> ピンを設定します  
> ```c++
> 例:
> UART<uint16_t> uart(huart2);
> ```

### 関数
> #### HAL_StatusTypeDef transmit(const T &data, uint32_t timeout)
> HAL_UART_Transmit() の結果を返します  
> ```c++
> 例:
> uint16_t data = 0xAC;
> uart.transmit(data, 0x0F);
> uart.transmit(0x35, 0x0F); // 変数ではなくリテラルも使用可能
> ```

> #### HAL_StatusTypeDef receive(T &data, uint32_t timeout)
> HAL_UART_Receive() の結果を返します  
> ```c++
> 例:
> uint16_t data;
> uart.receive(data, 0x0F);
> ```

## class UART_DMA
#### template\<class T\>

### CubeMX
```
PinOut: USARTn_TX / USARTn_RX
USARTn
 → DMA Settings
  → Add して Tx/Rx の使うものを選択
   → Mode を Circular に設定
   → Data Width を Word に設定
```

### コンフィグ
[CONFIG_UART_USE_HALF_CALLBACK](#config_uart_use_half_callback)

### コンストラクタ
> #### UART_DMA(UART_HandleTypeDef &huart, T &data)
> ピンと連携させる変数を設定します  
> ```c++
> 例:
> uint16_t data;
> UART_DMA<uint16_t> uart(huart2, data);
> ```

### 関数
> #### HAL_StatusTypeDef startTransmit()
> 連携させた変数の値を使い、送信を始めます  
> HAL_UART_Transmit_DMA の結果を返します  
> ```c++
> 例:
> uart.startTransmit();
> ```

> #### HAL_StatusTypeDef startReceive()
> 受信を始めます  
> 連携させた変数の値が自動で変わります  
> HAL_UART_Receive_DMA の結果を返します  
> ```c++
> 例:
> uart.startReceive();
> ```

> #### HAL_StatusTypeDef pause()
> 送受信を一時停止します  
> HAL_UART_DMAPause の結果を返します  
> ```c++
> 例:
> uart.pause();
> ```

> #### HAL_StatusTypeDef resume()
> 送受信を再開します  
> HAL_UART_DMAResume の結果を返します  
> ```c++
> 例:
> uart.resume();
> ```

> #### HAL_StatusTypeDef stop()
> 送受信を終了します  
> HAL_UART_DMAStop の結果を返します  
> ```c++
> 例:
> uart.stop();
> ```

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

## class UART_IT
#### template\<class T\>

### CubeMX
```
USARTn  
 → NVIC Settings  
  → USARTn global interrupt  
   → Enable にチェック
```

### コンフィグ
[CONFIG_UART_USE_HALF_CALLBACK](#config_uart_use_half_callback)

### コンストラクタ
> #### UART_IT(UART_HandleTypeDef &huart)
> ピンを設定します  
> ```c++
> 例:
> UART_IT<uint16_t> uart(huart2);
> ```

### 関数
> #### HAL_StatusTypeDef transmit(const T &data)
> HAL_UART_Transmit_IT() の結果を返します  
> ```c++
> 例:
> uart.transmit(data);
> uart.transmit(0x35); // 変数ではなくリテラルも使用可能
> ```

> #### HAL_StatusTypeDef receive(T &data)
> HAL_UART_Receive_IT() の結果を返します  
> ```c++
> 例:
> uart.receive(data);
> ```

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
### CubeMX
[class UART](#class-uart)　を参照してください

### コンストラクタ
> ### UART_Logger(UART_HandleTypeDef &huart, uint32_t timeout = 0x0F)
> ピンとタイムアウト時間を設定します    
> UART を使用しての送信になります  
> ```c++
> 例:
> UART_Logger logger(huart2); // タイムアウト時間は省略可能
> UART_Logger logger(huart2, 0xFF);
> ```

### 関数
> #### void print(const char* text)
> 一文字ずつ送信します  
> ```c++
> 例:
> logger.print("Hello");
> ```

> #### void println(const char* text)
> 送信後に改行します  
> ```c++
> 例:
> logger.println("HelloWorld");
> ```

## class UART_Logger_IT

### CubeMX
[class UART_IT](#class-uart_it)　を参照してください

### コンフィグ
[CONFIG_UART_USE_HALF_CALLBACK](#config_uart_use_half_callback)

### コンストラクタ
> ### UART_Logger_IT(UART_HandleTypeDef &huart)
> ピンを設定します  
> UART_IT を使用しての送信になります  
> ```c++
> 例:
> UART_Logger logger(huart2);
> ```

### 関数
> #### void print(const char* text)
> 一文字ずつ送信します  
> ```c++
> 例:
> logger.print("Hello");
> ```

> #### void println(const char* text)
> 送信後に改行します  
> ```c++
> 例:
> logger.println("HelloWorld");
> ```

## class I2C_Master
#### template\<class T\>

### CubeMX
```
PinOut: I2Cn_SCL & I2Cn_SDA
```

### コンストラクタ
> #### I2C_Master(I2C_HandleTypeDef &hi2c)
> ピンを設定します  
> ```c++
> 例:
> I2C_Master<uint8_t> master(hi2c1);
> ```

### 関数
> #### void init()
> 再初期化します  
> ```c++
> 例:
> master.init();
> ```

> #### HAL_StatusTypeDef transmit(uint8_t target, const T &data, uint32_t timeout)
> HAL_I2C_Master_Transmit() の結果を返します  
> ```c++
> 例:
> uint8_t data = 0xAC;
> master.transmit(0x02, data, 0x0F);
> master.transmit(0x02, 0x35, 0x0F); // 変数ではなくリテラルも使用可能
> ```

> #### HAL_StatusTypeDef receive(uint8_t target, T &data, uint32_t timeout)
> HAL_I2C_Master_Receive() の結果を返します  
> ```c++
> 例:
> uint8_t data;
> master.receive(0x02, data, 0x0F);
> ```

## class I2C_Slave
#### template\<class T\>

### CubeMX
```
PinOut: I2Cn_SCL & I2Cn_SDA
```

### コンストラクタ
> #### I2C_Slave(I2C_HandleTypeDef &hi2c, uint8_t address = 0x00)
> ピンと自局アドレスを設定します  
> 自局アドレスを省略することも可能です
> ```c++
> 例:
> I2C_Slave<uint8_t> slave(hi2c1, 0x01);
> I2C_Slave<uint8_t> slave(hi2c1);
> ```

### 関数
> #### void init()
> 自局アドレスを反映させ、再初期化します  
> ```c++
> 例:
> slave.init();
> ```

> #### void init(uint8_t address)
> 自局アドレスを上書きし、再初期化します  
> ```c++
> 例:
> slave.init(0x01);
> ```

> #### void init(DIPSwitch builder)
> 自局アドレスをDIPSwitch::getAddress()を使用して上書きし、再初期化します  
> ```c++
> 例:
> slave.init(dip);
> ```

> #### HAL_StatusTypeDef transmit(const T &data, uint32_t timeout)
> HAL_I2C_Slave_Transmit() の結果を返します  
> ```c++
> 例:
> uint8_t data = 0xAC;
> slave.transmit(data, 0x0F);
> slave.transmit(0x35, 0x0F); // 変数ではなくリテラルも使用可能
> ```

> #### HAL_StatusTypeDef receive(T &data, uint32_t timeout)
> HAL_I2C_Slave_Receive() の結果を返します  
> ```c++
> 例:
> uint8_t data;
> slave.receive(data, 0x0F);
> ```

## class I2C_Master_DMA
#### template\<class T\>

### CubeMX
```
PinOut: I2Cn_SCL & I2Cn_SDA
I2Cn
 → DMA Settings
  → Add して Tx/Rx の使うものを選択
   → Mode を Circular に設定
   → Data Width を Word に設定
```

### コンストラクタ
> #### I2C_Master_DMA(I2C_HandleTypeDef &hi2c, uint8_t target, T &data)
> ピンと送信先アドレス・連携させる変数を設定します  
> ```c++
> 例:
> uint16_t data;
> I2C_Master_DMA<uint16_t> master(hi2c1, 0x01, data);
> ```

### 関数
> #### void init()
> 再初期化します  
> ```c++
> 例:
> master.init();
> ```

> #### HAL_StatusTypeDef startTransmit()
> HAL_I2C_Master_Transmit_DMA() の結果を返します  
> ```c++
> 例:
> master.startTransmit();
> ```

> #### HAL_StatusTypeDef startReceive()
> HAL_I2C_Master_Receive_DMA() の結果を返します  
> ```c++
> 例:
> master.startReceive();
> ```

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

> #### void setErrorCallback(std::function<void()> function)
> エラー取得時の割り込み関数を設定します
> ```c++
> 例:
> slave.setErrorCallback([]{
>     logger.println("Error");
> });
> ```

## class I2C_Slave_DMA
### CubeMX
```
PinOut: I2Cn_SCL & I2Cn_SDA
I2Cn
 → DMA Settings
  → Add して Tx/Rx の使うものを選択
   → Mode を Circular に設定
   → Data Width を Word に設定
```

### コンストラクタ
> #### I2C_Slave_DMA(I2C_HandleTypeDef &hi2c, T &data, uint8_t address = 0x00)
> ピンと自局アドレス・連携させた変数を設定します  
> ```c++
> 例:
> uint16_t data;
> I2C_Slave_DMA<uint16_t> slave(hi2c1, data, 0x01);
> ```

### 関数
> #### void init()
> 自局アドレスを反映させ、再初期化します  
> ```c++
> 例:
> slave.init();
> ```

> #### void init(uint8_t address)
> 自局アドレスを上書きし、再初期化します  
> ```c++
> 例:
> slave.init(0x01);
> ```

> #### void init(DIPSwitch builder)
> 自局アドレスを上書きし、再初期化します  
> ```c++
> 例:
> slave.init(dip);
> ```

> #### HAL_StatusTypeDef startTransmit()
> HAL_I2C_Slave_Transmit_DMA() の結果を返します  
> ```c++
> 例:
> slave.startTransmit();
> ```

> #### HAL_StatusTypeDef startReceive()
> HAL_I2C_Slave_Receive_DMA() の結果を返します  
> ```c++
> 例:
> slave.startReceive();
> ```

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

> #### void setErrorCallback(std::function<void()> function)
> エラー取得時の割り込み関数を設定します
> ```c++
> 例:
> slave.setErrorCallback([]{
>     logger.println("Error");
> });
> ```

## class I2C_Master_IT
#### template\<class T\>

### CubeMX
```
PinOut: I2Cn_SCL & I2Cn_SDA
NVIC Settings
 → I2Cn interrupt の Enable にチェック
```

### コンストラクタ
> #### I2C_Master_IT(I2C_HandleTypeDef &hi2c)
> ピンを設定します  
> ```c++
> 例:
> I2C_Master_IT<uint16_t> master(hi2c1);
> ```

### 関数
> #### void init()
> 再初期化します  
> ```c++
> 例:
> master.init();
> ```

> #### HAL_StatusTypeDef transmit(uint8_t target, const T &data)
> HAL_I2C_Master_Transmit_IT() の結果を返します  
> ```c++
> 例:
> uint16_t data = 0xAC;
> master.transmit(0x02, data);
> master.transmit(0x02, 0x35); // 変数ではなくリテラルも使用可能
> ```

> #### HAL_StatusTypeDef receive(uint8_t target, T &data)
> HAL_I2C_Master_Receive_IT() の結果を返します  
> ```c++
> 例:
> uint16_t data;
> master.receive(0x02, data);
> ```

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

> #### void setErrorCallback(std::function<void()> function)
> エラー取得時の割り込み関数を設定します
> ```c++
> 例:
> slave.setErrorCallback([]{
>     logger.println("Error");
> });
> ```

## class I2C_Slave_IT
#### template\<class T\>

### CubeMX
```
PinOut: I2Cn_SCL & I2Cn_SDA
NVIC Settings
 → I2Cn interrupt の Enable にチェック
```

### コンストラクタ
> #### I2C_Slave_IT(I2C_HandleTypeDef &hi2c, uint8_t address = 0x00)
> ピンと自局アドレスを設定します  
> ```c++
> 例:
> I2C_Slave_IT<uint16_t> slave(hi2c1, 0x01);
> ```

### 関数
> #### void init()
> 自局アドレスを反映させ、再初期化します  
> ```c++
> 例:
> slave.init();
> ```

> #### void init(uint8_t address)
> 自局アドレスを上書きし、再初期化します  
> ```c++
> 例:
> slave.init(0x01);
> ```

> #### void init(DIPSwitch builder)
> 自局アドレスを上書きし、再初期化します  
> ```c++
> 例:
> slave.init(dip);
> ```

> #### HAL_StatusTypeDef transmit(const T &data)
> HAL_I2C_Slave_Transmit_IT() の結果を返します  
> ```c++
> 例:
> uint16_t data = 0xAC;
> slave.transmit(data);
> slave.transmit(0x35); // 変数ではなくリテラルも使用可能
> ```

> #### HAL_StatusTypeDef receive(T &data)
> HAL_I2C_Slave_Receive_IT() の結果を返します  
> ```c++
> 例:
> uint16_t data;
> slave.receive(data);
> ```

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

> #### void setErrorCallback(std::function<void()> function)
> エラー取得時の割り込み関数を設定します
> ```c++
> 例:
> slave.setErrorCallback([]{
>     logger.println("Error");
> });
> ```

## class PWM
### CubeMX
```
PinOut: TIMn_CHm
TIMn
 → Channelm を PWM Generation CHm に設定
  → Counter Period を好きな値に設定
    N 段階に設定したい場合 N-1 に設定してください
  → Prescaler を以下の式で得られた値に設定
    t = APB timer clocks (Clock Configurationで確認可能)
    f = 設定したい周波数 (少なすぎるとMDがお釈迦になる 1kHzが目安)
    c = Counter Period
    Prescaler = t ÷ f ÷ c
```

### コンストラクタ
> #### PWM(TIM_HandleTypeDef &htim, uint32_t channel)
> ピンを設定します  
> ```c++
> 例:
> PWM pwm(htim2, TIM_CHANNEL_1);
> ```

### 関数
> #### void start()
> HAL_TIM_PWM_Start() を実行します  
> ```c++
> 例:
> pwm.start();
> ```

> #### void stop()
> HAL_TIM_PWM_Stop() を実行します  
> ```c++
> 例:
> pwm.stop();
> ```

> #### bool setCompare(uint32_t compare)
> __HAL_TIM_SET_COMPARE() を実行します  
> compare が CounterPeriod より大きかった場合、設定がキャンセルされ、 false が返ります  
> ```c++
> 例:
> pwm.setCompare(100);
> ```

> #### uint32_t getCounterPeriod()
> CounterPeriod を返します  
> ```c++
> 例:
> uint32_t counterPeriod = pwm.getCounterPeriod();
> ```

## class Motor
### CubeMX
あらかじめ2つの [PWM](#class-pwm) を設定してください

### コンストラクタ
> #### Motor(PWM positive, PWM negative)
> 正転と逆転のPWMを設定します  
> ```c++
> 例:
> Motor motor(posPwm, negPwm);
> ```

> #### Motor(TIM_HandleTypeDef &htimPos, uint32_t channelPos, TIM_HandleTypeDef &htimNeg, uint32_t channelNeg)
> 正転と逆転のピンを設定します  
> 内部的にはPWMクラスに変換されています  
> ```c++
> 例:
> Motor motor(htim2, TIM_CHANNEL_1, htim3, TIM_CHANNEL_1);
> ```

### 関数
> #### void start()
> PWM::start を実行します  
> ```c++
> 例:
> motor.start();
> ```

> #### void stop()
> PWM::stop を実行します  
> ```c++
> 例:
> motor.stop();
> ```

> #### bool setSpeed(bool forward, uint32_t compare)
> 正転・逆転 と compare を送ります  
> true が正転 / false が逆転 です  
> PWM::setCompare() の結果を返します  
> ```c++
> 例:
> motor.setSpeed(true, 400);
> motor.setSpeed(false, 400);
> ```

> #### bool setSpeed(int64_t speed)
> 正の数は正転 / 負の数は逆転  
> 絶対値が compare になります  
> 内部的には setSpeed(bool, uint32_t) を実行しています  
> 処理が多くなるので上記の関数を直接使うことを推奨します  
> ```c++
> 例:
> motor.setSpeed(400);
> motor.setSpeed(-400);
> ```

## class Encoder
### CubeMX
```
TIMn
 → Combined Channels を Encoder Mode に設定
  → Counter Period を好きな値に設定する
   → Encoder
    → A相とB相があるエンコーダーの場合、
      Encoder Mode を TI1 and TI2 に設定してください
    → カウントアップとダウンの方向は Polarity で逆にすることができます
```

### コンストラクタ
> #### Encoder(TIM_HandleTypeDef &htim, uint32_t channel = TIM_CHANNEL_ALL)
> ピンを設定します  
> channel は何もなければ省略し  
> 他のCHを別の目的で使用する時のみ記述してください
> ```c++
> 例:
> Encoder encoder(htim2);
> Encoder encoder(htim2, TIM_CHANNEL_1|TIM_CHANNEL_2);
> ```

### 関数
> #### void start()
> カウントを開始します  
> ```c++
> 例:
> encoder.start();
> ```

> #### void stop()
> カウントを停止します  
> ```c++
> 例:
> encoder.stop();
> ```

> #### void update()
> カウントを更新します  
> ```c++
> 例:
> encoder.update();
> ```

> #### int32_t getCount()
> カウントを取得します  
> ```c++
> 例:
> encoder.getCount();
> ```

> #### void resetCount()
> カウントを停止します  
> ```c++
> 例:
> encoder.resetCount();
> ```

## class ADC_DMA
### CubeMX
```
ADCn:
 → Parameter Settings
  → ADC_Settings
   → Continuous Conversion Mode を Enabled に設定
   → DMA Continuous Requests を Enabled に設定
  → ADC_Regular_ConversionMode
   → Number Of Conversion を DMAする数に設定
    → Rank毎の設定
     → チャンネルを割り当てる(Rank順にバッファに入る)
     → Sampling Time は 15Cycles 以上に設定
       少なすぎると他の処理が行われないので考慮する
 → DMA Settings
  → Add して ADCn を選択
    → Mode を Circular に設定
    → Data Width を Word に設定
```

### コンフィグ
[CONFIG_ADC_USE_HALF_CALLBACK](#config_adc_use_half_callback)

### コンストラクタ
> #### ADC_DMA(ADC_HandleTypeDef &hadc, uint8_t numberOfConversions)
> ピンとDMAを行う数を設定します  
> ```c++
> 例:
> ADC_DMA adc(hadc1, 2);
> ```

### 関数
> #### void start()
> ADCを開始します  
> ```c++
> 例:
> adc.start();
> ```

> #### void stop()
> ADCを終了します  
> ```c++
> 例:
> adc.stop();
> ```

> #### uint32_t get(uint8_t index)
> ADCバッファの値を返します  
> index が numberOfConversions を超えている場合、  
> バッファの範囲外なので std::out_of_range が発生します  
> ```c++
> 例:
> adc.get(0);
> ```

> #### void setCallback(std::function<void()> function)
> ADC完了時の割り込み関数を設定します
> ```c++
> 例:
> master.setCallback([]{
>     logger.println("Complete");
> });
> ```
