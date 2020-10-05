# GPIO

## 目次
- [CubeMX](#cubemx)
- [コンストラクタ](#コンストラクタ)
  - [GPIO(GPIO_TypeDef*, uint16_t)](#gpiogpiogpio_typedef-uint16_t)
- [関数](#関数)
  - [read()](#gpioread)
  - [isSet()](#gpioisset)
  - [isReset()](#gpioisreset)
  - [write(GPIO_PinState)](#gpiowritegpio_pinstate)
  - [set()](#gpioset)
  - [setIf(bool)](#gpiosetifbool)
  - [reset()](#gpioreset)
  - [resetIf(bool)](#gpioresetifbool)
  - [toggle()](#gpiotoggle)

## CubeMX
```yaml
PinOut: GPIO_Input / GPIO_Output
```

## コンストラクタ
##### GPIO::GPIO(GPIO_TypeDef*, uint16_t)
> ```c++
> GPIO(
>     GPIO_TypeDef* GPIOx,
>     uint16_t GPIO_Pin
> );
> ```
> Read / Write をするピンを設定します  
> ```c++
> // 例
> GPIO pa5(GPIOA, GPIO_PIN_5);
> ```

## 関数
##### GPIO::read()
> ```c++
> GPIO_PinState read() const noexcept;
> ```
> `HAL_GPIO_ReadPin()` の結果を返します  
> ```c++
> // 例
> pa5.read();
> ```

##### GPIO::isSet()
> ```c++
> GPIO_PinState isSet() const noexcept;
> ```
> `GPIO::read()` の結果が `GPIO_PIN_SET` であれば `true` を返します 
> ```c++
> // 例
> pa5.isSet();
> ```

##### GPIO::isReset()
> ```c++
> GPIO_PinState isReset() const noexcept;
> ```
> `GPIO::read()` の結果が `GPIO_PIN_RESET` であれば `true` を返します 
> ```c++
> // 例
> pa5.isReset();
> ```

##### GPIO::write(GPIO_PinState)
> ```c++
> void write(
>     GPIO_PinState PinState
> ) const noexcept;
> ```
> `HAL_GPIO_WritePin()` を実行します  
> ```c++
> // 例
> pa5.write(GPIO_PIN_SET);
> pa5.write(GPIO_PIN_RESET);
> pa5.write(pc13.read());
> ```

##### GPIO::set()
> ```c++
> void set() const noexcept;
> ```
> `GPIO::write(GPIO_PIN_SET)` を実行します  
> ```c++
> // 例
> pa5.set();
> ```

##### GPIO::setIf(bool)
> ```c++
> void setIf(
>     bool condition
> ) const noexcept;
> ```
> `condition` が `true` の時に `set()`  
> `false` の時に `reset()` を実行します  
> ```c++
> // 例
> pa5.setIf(pc13.isReset());
> ```

##### GPIO::reset()
> ```c++
> void reset() const noexcept;
> ```
> `GPIO::write(GPIO_PIN_RESET)` を実行します  
> ```c++
> // 例
> pa5.reset();
> ```

##### GPIO::resetIf(bool)
> ```c++
> void resetIf(
>     bool condition
> ) const noexcept;
> ```
> `condition` が `true` の時に `reset()`  
> `false` の時に `set()` を実行します  
> ```c++
> // 例
> pa5.resetIf(pc13.isSet());
> ```

##### GPIO::toggle()
> ```c++
> void toggle() const noexcept;
> ```
> `HAL_GPIO_TogglePin()` を実行します  
> ```c++
> // 例
> pa5.toggle();
> ```

[<< 戻る](../INDEX.md)