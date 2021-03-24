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
> ストップウォッチを定義しますs
> ```c++
> // 例
> StopWatch stopWatch;
> ```

## 関数

##### StopWatch::start()
> ```c++
> void start() noexcept;
> ```
> 開始時間を更新します
> ```c++
> // 例
> stopWatch.start();
> ```

##### StopWatch::get()
> ```c++
> uint32_t get() const noexcept;
> ```
> 開始時間と現在時間との差を返します
> ```c++
> // 例
> uint32_t elapsed_time = stopWatch.get();
> ```

[<< 戻る](../README.md)