# function GPIO

## 目次
- [GPIO](#gpio)
  - [gpioRead](#gpioread)
  - [gpioWrite](#gpiowrite)
  - [gpioToggle](#gpiotoggle)

## 関数

### GPIO

##### gpioRead
> ```c++
> inline GPIO_PinState gpioRead(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) noexcept;
> ```
> `HAL_GPIO_ReadPin` を実行します

##### gpioWrite
> ```c++
> inline void gpioWrite(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState) noexcept;
> ```
> `HAL_GPIO_WritePin` を実行します

##### gpioToggle
> ```c++
> inline void gpioToggle(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) noexcept;
> ```
> `HAL_GPIO_TogglePin` を実行します

[<< 戻る](../INDEX.md)