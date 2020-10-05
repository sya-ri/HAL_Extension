# ADC

## コンフィグ

##### CONFIG_DISABLE_MODULE_ADC
> ADC モジュールの無効化  
> 定義することでコンパイルされなくなります

##### CONFIG_USE_HALF_CALLBACK_ADC
> ADCのコールバック関数をハーフに変更します

## 関数
- [setADCCallback](function/INDEX.md#setadccallback)

## クラス
- [ADC_DMA](class/ADC_DMA.md)
  - [CubeMX](class/ADC_DMA.md#cubemx)
  - [コンストラクタ](class/ADC_DMA.md#コンストラクタ)
    - [ADC_DMA(ADC_HandleTypeDef, uint8_t)](class/ADC_DMA.md#adc_dmaadc_dmaadc_handletypedef-uint8_t)
  - [関数](class/ADC_DMA.md#関数)
    - [start()](class/ADC_DMA.md#adc_dmastart)
    - [stop()](class/ADC_DMA.md#adc_dmastop)
    - [get(uint8_t)](class/ADC_DMA.md#adc_dmagetuint8_t)
    - [get8(uint8_t)](class/ADC_DMA.md#adc_dmaget8uint8_t)
    - [setCallback(std::function<void()>)](class/ADC_DMA.md#adc_dmasetcallbackstdfunctionvoid)

[<< 戻る](../../README.md)