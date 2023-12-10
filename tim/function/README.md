# function TIM

## 目次
- [Callback](#callback)
  - [setTIMPeriodElapsedCallback](#settimperiodelapsedcallback)

## 関数

### Callback

##### setTIMPeriodElapsedCallback
> ```c++
> void setTIMPeriodElapsedCallback(
>     TIM_HandleTypeDef *htim,
>     std::function<void()> function
> ) noexcept;
> ```
> ```c++
> void setTIMPeriodElapsedCallback(
>     TIM_HandleTypeDef &htim,
>     std::function<void()> function
> ) noexcept;
> ```
> `HAL_TIM_PeriodElapsedCallback` や `HAL_TIM_PeriodElapsedHalfCpltCallback` の処理を変更します

##### runTIMPeriodElapsedCallback
> ```c++
> void runTIMPeriodElapsedCallback(
>     TIM_HandleTypeDef *htim
> ) noexcept;
> ```
> ```c++
> void runTIMPeriodElapsedCallback(
>     TIM_HandleTypeDef &htim
> ) noexcept;
> ```
> `HAL_TIM_PeriodElapsedCallback` や `HAL_TIM_PeriodElapsedHalfCpltCallback` の中で呼び出すことで設定されているコールバックの処理を実行できます

[<< 戻る](../README.md)