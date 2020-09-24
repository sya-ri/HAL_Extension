# SevenSegment
## CubeMX
```yaml
PinOut: GPIO_Output
```

## コンストラクタ
##### SevenSegment(bool)
> ```c++
> SevenSegment(bool flip = false);
> ```
> `flip` に応じて `GPIO_PIN_SET`, `GPIO_PIN_RESET` が逆になります
> ```c++
> // 例
> SevenSegment sevenSegment;
> SevenSegment sevenSegment(true);
> ```

## 関数
##### SevenSegment::add(GPIO)
> ```c++
> virtual SevenSegment& add(GPIO gpio) noexcept;
> ```
> セグメントのピンを追加します  
> 登録順は a → b → ... f → g → point
> ```c++
> // 例
> sevenSegment.add(pa5)
>             .add(pa6) // 以下省略
> ```

##### SevenSegment::add(GPIO_TypeDef*, uint16_t)
> ```c++
> virtual SevenSegment& add(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) noexcept;
> ```
> `SevenSegment::add(GPIO)` の結果を返します  
> ```c++
> // 例
> sevenSegment.add(GPIOA, GPIO_PIN_5)
>             .add(GPIOA, GPIO_PIN_6) // 以下省略
> ```

##### SevenSegment::setLight(uint8_t)
> ```c++
> virtual bool setLight(uint8_t lightData) const noexcept;
> ```
> ビット単位で7セグの設定をします  
> 各ビットに対応してセグメントが点灯します
> ```c++
> // 例
> sevenSegment.setLight(0b01101101);
> ```

##### SevenSegment::set(uint8_t, bool)
> ```c++
> virtual bool set(int8_t hex, bool point = false) const noexcept;
> ```
> 16進数で7セグの設定をします  
> point を true にすると小数点が光ります
> ```c++
> // 例
> sevenSegment.set(0xC); // false は省略可能
> sevenSegment.set(0xC, true);
> ```

##### SevenSegment::clear()
> ```c++
> virtual bool clear() const noexcept;
> ```
> 全てのセグメントを消灯します
> ```c++
> // 例
> sevenSegment.clear();
> ```

##### SevenSegment::isAvailable()
> ```c++
> virtual bool isAvailable() const noexcept;
> ```
> 登録数が7個であれば true を返します  
> ```c++
> sevenSegment.isAvailable();
> ```

[<< 戻る](../INDEX.md)