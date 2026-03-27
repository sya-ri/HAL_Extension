# CAN_Communication

## 目次
- [CubeMX](#cubemx)
- [コンストラクタ](#コンストラクタ)
  - [CAN_Communication(CAN_HandleTypeDef)](#can_communicationcan_communicationcan_handletypedef)
- [関数](#関数)
  - [init()](#can_communicationinit)
  - [start()](#can_communicationstart)
  - [setFilterConfig(CAN_FilterConfig)](#can_communicationsetfilterconfigcan_filterconfig)
  - [activateNotification(uint32_t)](#can_communicationactivatenotificationuint32_t)
  - [deactivateNotification(uint32_t)](#can_communicationdeactivatenotificationuint32_t)
  - [transmit(CAN_TransmitMessage, CAN_TransmitResult)](#can_communicationtransmitcan_transmitmessage-can_transmitresult)
  - [receive(uint32_t, CAN_ReceiveMessage)](#can_communicationreceiveuint32_t-can_receivemessage)

## CubeMX
```yaml
PinOut: CAN_RX / CAN_TX
```

## コンストラクタ
##### CAN_Communication::CAN_Communication(CAN_HandleTypeDef)
> ```c++
> CAN_Communication(
>     CAN_HandleTypeDef *hcan
> );
> ```
> ```c++
> CAN_Communication(
>     CAN_HandleTypeDef &hcan
> );
> ```
> 使用する CAN インスタンスを設定します
> ```c++
> // 例
> CAN_Communication can(&hcan);
> ```

## 関数
##### CAN_Communication::init()
> ```c++
> HAL_StatusTypeDef init();
> ```
> `HAL_CAN_DeInit()` の後に `HAL_CAN_Init()` を実行します
> ```c++
> // 例
> can.init();
> ```

##### CAN_Communication::start()
> ```c++
> HAL_StatusTypeDef start();
> ```
> `HAL_CAN_Start()` の結果を返します
> ```c++
> // 例
> can.start();
> ```

##### CAN_Communication::setFilterConfig(CAN_FilterConfig)
> ```c++
> HAL_StatusTypeDef setFilterConfig(
>     CAN_FilterConfig &config
> );
> ```
> 受信フィルタを設定します
> ```c++
> // 例
> CAN_FilterConfig filter;
> filter.setIdFilter(0x100);
> can.setFilterConfig(filter);
> ```

##### CAN_Communication::activateNotification(uint32_t)
> ```c++
> HAL_StatusTypeDef activateNotification(
>     uint32_t interrupts
> );
> ```
> 指定した CAN 割り込み通知を有効化します
> ```c++
> // 例
> can.activateNotification(CAN_IT_RX_FIFO0_MSG_PENDING);
> ```

##### CAN_Communication::deactivateNotification(uint32_t)
> ```c++
> HAL_StatusTypeDef deactivateNotification(
>     uint32_t interrupts
> );
> ```
> 指定した CAN 割り込み通知を無効化します
> ```c++
> // 例
> can.deactivateNotification(CAN_IT_RX_FIFO0_MSG_PENDING);
> ```

##### CAN_Communication::transmit(CAN_TransmitMessage, CAN_TransmitResult)
> ```c++
> HAL_StatusTypeDef transmit(
>     CAN_TransmitMessage &message,
>     CAN_TransmitResult &result
> );
> ```
> 送信要求を追加し、結果の状態を `result` に関連付けます
> ```c++
> // 例
> CAN_TransmitMessage message;
> CAN_TransmitResult result;
> uint8_t data[2] = {0x12, 0x34};
> message.setId(0x100);
> message.setData(data, 2);
> can.transmit(message, result);
> ```

##### CAN_Communication::receive(uint32_t, CAN_ReceiveMessage)
> ```c++
> HAL_StatusTypeDef receive(
>     uint32_t rxFifo,
>     CAN_ReceiveMessage &message
> );
> ```
> FIFO にメッセージがあれば受信し、なければ `HAL_OK` を返します
> ```c++
> // 例
> CAN_ReceiveMessage message;
> can.receive(CAN_RX_FIFO0, message);
> ```

[<< 戻る](../README.md)
