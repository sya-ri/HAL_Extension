# function ADC

## 目次
- [setADCCallback](#setadccallback)

## 関数
##### setADCCallback
> ```c++
> void setADCCallback(
>     ADC_HandleTypeDef *hadc,
>     std::function<void()> function
> ) noexcept;
> ```
> ```c++
> void setADCCallback(
>     ADC_HandleTypeDef &hadc,
>     std::function<void()> function
> ) noexcept;
> ```
> `HAL_ADC_ConvCpltCallback` や `HAL_ADC_ConvHalfCpltCallback` の処理を変更します

[<< 戻る](../INDEX.md)