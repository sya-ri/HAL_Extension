# IWDG_Manger

## 目次
- [CubeMX](#cubemx)
- [定数](#定数)
  - [minTimeOut](#iwg_managermintimeout)
  - [maxTimeOut](#iwdg_managermaxtimeout)
- [列挙クラス](#列挙クラス)
  - [TimeUnit](#iwdg_managertimeunit)
- [コンストラクタ](#コンストラクタ)
  - [IWDG_Manager(float, TimeUnit)](#iwdg_manageriwdg_managerfloat-timeunit)
- [関数](#関数)
  - [available()](#iwdg_manageravailable)
  - [init()](#iwdg_managerinit)
  - [refresh()](#iwdg_managerrefresh)

## CubeMX
```yaml
System Core:
  IWDG: Activate
```

## 定数
##### IWG_Manager::minTimeOut
```c++
static constexpr float minTimeOut;
```
最小のタイムアウト時間です   
`LSI_VALUE` に依存します

| LSI_RC | LSI_VALUE | minTimeOut | time  |
|:------:|:---------:|:----------:|:-----:|
| 32kHz  | 32000     | 0.000125   | 125us |
| 40kHz  | 40000     | 0.0001     | 100us |

##### IWDG_Manager::maxTimeOut
```c++
static constexpr float maxTimeOut;
```
最大のタイムアウト時間です   
`LSI_VALUE` に依存します  

| LSI_RC | LSI_VALUE | minTimeOut | time    |
|:------:|:---------:|:----------:|:-------:|
| 32kHz  | 32000     | 32.76      | 32.76s  |
| 40kHz  | 40000     | 26.208     | 26.208s |

## 列挙クラス
##### IWDG_Manager::TimeUnit
```c++
enum class TimeUnit: uint32_t;
```

| Name | uint32_t |
|:----:|:--------:|
| s    | 1        |
| ms   | 1000     |
| us   | 1000000  |

## コンストラクタ
##### IWDG_Manager::IWDG_Manager(float, TimeUnit)
> ```c++
> constexpr IWDG_Manager(
>     float timeOut,
>     TimeUnit timeUnit
> );
> ```
> タイムアウト時間を設定します  
> `minTimeOut` ~ `maxTimeOut` でない場合、正常に動作しません
> ```c++
> // 例
> IWDG_Manager iwdg(0.5, IWDG_Manager::TimeUnit::s);
> ```

## 関数
##### IWDG_Manager::available()
> ```c++
> constexpr bool available();
> ```
> タイムアウト時間が `minTimeOut` ~ `maxTimeOut` であるか取得します
> ```c++
> // 例
> pa5.setIf(iwdg.available());
> ```

##### IWDG_Manager::init()
> ```c++
> constexpr void init();
> ```
> 設定の更新をします
> ```c++
> // 例
> iwdg.init();
> ```

##### IWDG_Manager::refresh()
> ```c++
> constexpr void refresh();
> ```
> タイマーをリフレッシュします  
> 実行しなければマイコンがリセットされます