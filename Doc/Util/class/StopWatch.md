# StopWatch

## 目次
- [コンストラクタ](#コンストラクタ)
  - [StopWatch()](#stopwatchstopwatch)
- [関数](#関数)
  - [start()](#stopwatchstart)
  - [get()](#stopwatchget)

## コンストラクタ
##### StopWatch::StopWatch()
> ```c++
> StopWatch();
> ```

## 関数

##### StopWatch::start()
> ```c++
> void start() noexcept;
> ```
> 開始時間を更新します

##### StopWatch::get()
> ```c++
> uint32_t get() const noexcept;
> ```
> 開始時間と現在時間との差を返します

[<< 戻る](../INDEX.md)