# BooleanStateButton

## 目次
- [CubeMX](#cubemx)
- [コンストラクタ](#コンストラクタ)
  - [BooleanStateButton(GPIO_TypeDef*, uint16_t, GPIO_PinState, uint32_t)](#booleanstatebuttonbooleanstatebuttongpio_typedef-uint16_t-gpio_pinstate-uint32_t)
  - [BooleanStateButton(GPIO_TypeDef*, uint16_t, GPIO_PinState)](#booleanstatebuttonbooleanstatebuttongpio_typedef-uint16_t-gpio_pinstate)
  - [BooleanStateButton(GPIO_TypeDef*, uint16_t)](#booleanstatebuttonbooleanstatebuttongpio_typedef-uint16_t)
- [関数](#関数)
  - [update()](#booleanstatebuttonupdate)
  - [getState()](#booleanstatebuttongetstate)

## CubeMX
```yaml
PinOut: GPIO_Input
```

## コンストラクタ
##### BooleanStateButton::BooleanStateButton(GPIO_TypeDef*, uint16_t, GPIO_PinState, uint32_t)
> ```c++
> BooleanStateButton(
>     GPIO_TypeDef *GPIOx,
>     uint16_t GPIO_Pin,
>     GPIO_PinState normalState,
>     uint32_t chatteringTime
> );
> ```
> `Button` と同じ引数で設定します
> ```c++
> // 例
> BooleanStateButton button(GPIOC, GPIO_PIN_13, GPIO_PIN_SET, 20);
> ```

##### BooleanStateButton::BooleanStateButton(GPIO_TypeDef*, uint16_t, GPIO_PinState)
> ```c++
> BooleanStateButton(
>     GPIO_TypeDef *GPIOx,
>     uint16_t GPIO_Pin,
>     GPIO_PinState normalState
> );
> ```
> `Button` と同じ引数で設定します
> ```c++
> // 例
> BooleanStateButton button(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
> ```

##### BooleanStateButton::BooleanStateButton(GPIO_TypeDef*, uint16_t)
> ```c++
> BooleanStateButton(
>     GPIO_TypeDef *GPIOx,
>     uint16_t GPIO_Pin
> );
> ```
> `Button` と同じ引数で設定します
> ```c++
> // 例
> BooleanStateButton button(GPIOC, GPIO_PIN_13);
> ```

## 関数
##### BooleanStateButton::update()
> ```c++
> void update();
> ```
> `Button::update()` を実行し、押下された瞬間に保持状態を反転します
> ```c++
> // 例
> void loop(){
>     button.update();
> }
> ```

##### BooleanStateButton::getState()
> ```c++
> bool getState() override;
> ```
> 押下のたびに反転する保持状態を返します
> ```c++
> // 例
> led.setIf(button.getState());
> ```

[<< 戻る](../README.md)
