# CAN_TransmitResult

## 目次
- [関数](#関数)
  - [setInstance(CAN_HandleTypeDef*)](#can_transmitresultsetinstancecan_handletypedef)
  - [getMailBox()](#can_transmitresultgetmailbox)
  - [isOk()](#can_transmitresultisok)
  - [abort()](#can_transmitresultabort)
  - [isPending()](#can_transmitresultispending)

## 関数
##### CAN_TransmitResult::setInstance(CAN_HandleTypeDef*)
> ```c++
> void setInstance(
>     CAN_HandleTypeDef *hcan
> );
> ```
> 関連付ける CAN インスタンスを設定します

##### CAN_TransmitResult::getMailBox()
> ```c++
> uint32_t* getMailBox();
> ```
> 送信に使われたメールボックス番号へのポインタを返します

##### CAN_TransmitResult::isOk()
> ```c++
> bool isOk();
> ```
> インスタンスが設定され、メールボックス番号が有効なら `true` を返します

##### CAN_TransmitResult::abort()
> ```c++
> HAL_StatusTypeDef abort();
> ```
> 保留中の送信要求があれば中断します

##### CAN_TransmitResult::isPending()
> ```c++
> bool isPending();
> ```
> 送信要求が保留中なら `true` を返します

[<< 戻る](../README.md)
