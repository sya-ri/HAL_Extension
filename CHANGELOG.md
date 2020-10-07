# 変更履歴

## v4.0.2
- モジュールの有効化コンフィグを無効化コンフィグに変更

## v4.0.1
- モジュールの有効化コンフィグを追加
- 割り込み関数の自動定義を無効化するコンフィグを追加
- `GPIO::readBool` を削除
- `GPIO::isSet` `GPIO::isReset` を追加
- `ADC_DMA` の内部処理を変更  
  - `init` で一部の設定を `ENABLE` にする処理を削除
  - `get` の範囲外アクセスを許容するように変更
- `DynamicSevenSegment` の内部処理を変更  
桁数取得を `floorf` から `getNumberOfDigit` に変更
- `PWM` が出力されないバグを修正

## v4.0.0
- `Src/*.cpp` を追加
- 全てのクラスに空コンストラクタを追加

## v3.0.6
- コンパイルエラーを修正

## v3.0.5
- `FixedSevenSegment` のコンストラクタを変更
  - `flip` を追加

## v3.0.4
- `SevenSegment` の関数を仮想化

## v3.0.3
- `GPIO::readBool` の処理を変更  
`gpioRead` を `GPIO::read` に変更

## v3.0.2
- `ADC_DMA::get` の処理を変更  
例外を投げるのではなく `UINT16_MAX` を返すように変更
- クラス `ADC_DMA` に関数を追加
  - `get8`

## v3.0.1
- `__has_include` の外部でモジュールのインクルードをするように変更

## v3.0.0
- モジュール毎にファイル分け
  - `_util`
  - `_gpio`
  - `_usart`
  - `_i2c`
  - `_tim`
  - `_adc`

## v2.3.4
- `HAL_Extension.hpp` を `Inc` に移動
- `UART_Logger` の内部処理を変更  
`UART::transmit` を `HAL_UART_Transmit` に変更
- `UART_Logger_IT` の内部処理を変更  
`UART_IT::transmit` を `HAL_UART_Transmit_IT` に変更

## v2.3.3
- クラスを追加
  - `SevenSegment`
- クラス `GPIO` に関数を追加
  - `readBool`
- `static` 定義を無名名前空間に変更

## v2.3.2
- クラスを追加
  - `UART_Logger_IT`
- 引数に `const` を追加

## v2.3.1
- ファイル名を変更  
`Hal_Extension.hpp` → `HAL_Extension.hpp`

## v2.3
- クラスを追加
  - `UART_IT`
  - `I2C_Master_IT`
  - `I2C_Slave_IT`
  - `Encoder`

## v2.2
- `I2C_Slave_DMA` を変更  
送受信に使う変数をコンストラクタで渡すように変更

## v2.1
- クラスを追加
  - `UART_Logger`

## v2.0
- クラスを追加
  - `DIPSwitch`
  - `UART_DMA`
  - `I2C_Master`
  - `I2C_Slave`
  - `I2C_Master_DMA`
  - `I2C_Slave_DMA`
  - `ADC_DMA`
- クラスを削除
  - `I2C`

## v1.0
- 短縮関数を追加
  - `getTick`
  - `delay`
  - `gpioRead`
  - `gpioWrite`
  - `gpioToggle`
- クラスを追加
  - `GPIO`
  - `UART`
  - `I2C`
  - `PWM`
  - `Motor`