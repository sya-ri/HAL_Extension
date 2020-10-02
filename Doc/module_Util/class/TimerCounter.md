# TimerCounter

## 目次
- [コンストラクタ](#コンストラクタ)
  - [TimerCounter()](#timercountertimercounter)
- [関数](#関数)
  - [start()](#timercounterstart)
  - [get()](#timercounterget)

## コンストラクタ
##### TimerCounter::TimerCounter()
> ```c++
> TimerCounter();
> ```

## 関数

##### TimerCounter::start()
> ```c++
> void start() noexcept;
> ```
> 開始時間を更新します

##### TimerCounter::get()
> ```c++
> uint32_t get() const noexcept;
> ```
> 開始時間と現在時間との差を返します

[<< 戻る](../INDEX.md)