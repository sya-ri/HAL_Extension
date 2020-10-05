# ADC_DMA

## 目次
- [CubeMX](#cubemx)
- [コンストラクタ](#コンストラクタ)
  - [ADC_DMA(ADC_HandleTypeDef, uint8_t)](#adc_dmaadc_dmaadc_handletypedef-uint8_t)
- [関数](#関数)
  - [start()](#adc_dmastart)
  - [stop()](#adc_dmastop)
  - [get(uint8_t)](#adc_dmagetuint8_t)
  - [get8(uint8_t)](#adc_dmaget8uint8_t)
  - [setCallback(std::function<void()>)](#adc_dmasetcallbackstdfunctionvoid)
  
## CubeMX
```yaml
ADCn:
  Parameter Settings:
    ADC_Settings:
      Continuous Conversion Mode: Enabled
      DMA Continuous Requests: Enabled
      Overrun behaviour: (ある場合) Overrun data overwritten
    ADC_Regular_ConversionMode:
      Number Of Conversion: DMAする数
      Rank毎の設定:
      - チャンネルを割り当てる(Rank順にバッファに入る)
      - Sampling Time は 15Cycles 以上に設定
        少なすぎると他の処理が行われないので考慮する
  DMA Settings:
    - Add して ADCn を選択
    - Mode を Circular に設定
    - Data Width を Word に設定
```

## コンストラクタ
##### ADC_DMA::ADC_DMA(ADC_HandleTypeDef, uint8_t)
> ```c++
> ADC_DMA(
>     ADC_HandleTypeDef *hadc,
>     uint32_t adcBufLength
> );
> ```
> ```c++
> ADC_DMA(
>     ADC_HandleTypeDef &hadc,
>     uint32_t adcBufLength
> );
> ```
> ピンとバッファの大きさを設定します  
>　※ `Overrun behaviour` を `Overrun data overwritten` にした場合  
>    `Number Of Conversion` と同じ値にする
> ※ 上記の設定がなかった場合は Sampling Time を考慮して十分大きなバッファを確保する
>   オーバーランが発生すると処理が止まるので注意する
> ```c++
> // 例
> ADC_DMA adc(&hadc1, 2);
> ADC_DMA adc(hadc1, 2);
> ```

## 関数
##### ADC_DMA::start()
> ```c++
> void start() noexcept;
> ```
> ADCを開始します  
> ```c++
> // 例
> adc.start();
> ```

##### ADC_DMA::stop()
> ```c++
> void stop() noexcept;
> ```
> ADCを終了します  
> ```c++
> // 例
> adc.stop();
> ```

##### ADC_DMA::get(uint8_t)
> ```c++
> uint32_t get(
>     uint8_t index
> ) const noexcept;
> ```
> ADCバッファの値を返します  
> ```c++
> // 例
> adc.get(0);
> ```

##### ADC_DMA::get8(uint8_t)
> ```c++
> uint8_t get8(
>     uint8_t index
> ) const noexcept;
> ```
> ４ビット右シフトしてADCバッファを取得します
> ```c++
> // 例
> adc.get8(0);
> ```

##### ADC_DMA::setCallback(std::function<void()>)
> ```c++
> #ifndef CONFIG_DISABLE_EX_CALLBACK
> void setCallback(
>     std::function<void()> function
> ) noexcept;
> #endif // CONFIG_DISABLE_EX_CALLBACK
> ```
> ADC完了時の割り込み関数を設定します
> ```c++
> // 例
> adc.setCallback([]{
>     logger.println("Complete");
> });
> ```

[<< 戻る](../INDEX.md)