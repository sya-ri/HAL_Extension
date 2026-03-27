# Button

## 目次
- [CubeMX](#cubemx)
- [コンストラクタ](#コンストラクタ)
  - [Button(GPIO_TypeDef*, uint16_t, GPIO_PinState, uint32_t)](#buttonbuttongpio_typedef-uint16_t-gpio_pinstate-uint32_t)
  - [Button(GPIO_TypeDef*, uint16_t, GPIO_PinState)](#buttonbuttongpio_typedef-uint16_t-gpio_pinstate)
  - [Button(GPIO_TypeDef*, uint16_t)](#buttonbuttongpio_typedef-uint16_t)
- [関数](#関数)
  - [update()](#buttonupdate)
  - [isPushed()](#buttonispushed)
  - [isReleased()](#buttonisreleased)
  - [getState()](#buttongetstate)

## CubeMX
```yaml
PinOut: GPIO_Input
```

## コンストラクタ
##### Button::Button(GPIO_TypeDef*, uint16_t, GPIO_PinState, uint32_t)
> ```c++
> Button(
>     GPIO_TypeDef *GPIOx,
>     uint16_t GPIO_Pin,
>     GPIO_PinState normalState,
>     uint32_t chatteringTime
> );
> ```
> 通常時のピン状態とチャタリング判定時間を指定してボタンを設定します
> ```c++
> // 例
> Button button(GPIOC, GPIO_PIN_13, GPIO_PIN_SET, 20);
> ```

##### Button::Button(GPIO_TypeDef*, uint16_t, GPIO_PinState)
> ```c++
> Button(
>     GPIO_TypeDef *GPIOx,
>     uint16_t GPIO_Pin,
>     GPIO_PinState normalState
> );
> ```
> `chatteringTime = 0` でボタンを設定します
> ```c++
> // 例
> Button button(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
> ```

##### Button::Button(GPIO_TypeDef*, uint16_t)
> ```c++
> Button(
>     GPIO_TypeDef *GPIOx,
>     uint16_t GPIO_Pin
> );
> ```
> `normalState = GPIO_PIN_RESET` でボタンを設定します
> ```c++
> // 例
> Button button(GPIOC, GPIO_PIN_13);
> ```

## 関数
##### Button::update()
> ```c++
> void update();
> ```
> ピン状態を読み取り、チャタリングを考慮して内部状態を更新します  
> `loop` やタイマー割り込みで定期的に呼び出してください
> ```c++
> // 例
> void loop(){
>     button.update();
> }
> ```

##### Button::isPushed()
> ```c++
> bool isPushed();
> ```
> 押下された瞬間だけ `true` を返します
> ```c++
> // 例
> if(button.isPushed()){
>     led.toggle();
> }
> ```

##### Button::isReleased()
> ```c++
> bool isReleased();
> ```
> 離された瞬間だけ `true` を返します
> ```c++
> // 例
> if(button.isReleased()){
>     led.reset();
> }
> ```

##### Button::getState()
> ```c++
> virtual bool getState();
> ```
> 現在の押下状態を返します
> ```c++
> // 例
> if(button.getState()){
>     led.set();
> }
> ```

[<< 戻る](../README.md)
