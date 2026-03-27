# CAN_ReceiveMessage

## 目次
- [関数](#関数)
  - [getHeader()](#can_receivemessagegetheader)
  - [getId()](#can_receivemessagegetid)
  - [getType()](#can_receivemessagegettype)
  - [getRemoteTransmissionRequest()](#can_receivemessagegetremotetransmissionrequest)
  - [getLength()](#can_receivemessagegetlength)
  - [getData()](#can_receivemessagegetdata)

## 関数
##### CAN_ReceiveMessage::getHeader()
> ```c++
> CAN_RxHeaderTypeDef* getHeader();
> ```
> 受信用ヘッダへのポインタを返します

##### CAN_ReceiveMessage::getId()
> ```c++
> uint32_t getId();
> ```
> 受信した標準 ID または拡張 ID を返します

##### CAN_ReceiveMessage::getType()
> ```c++
> CAN_IdentifierType getType();
> ```
> 識別子種別を返します

##### CAN_ReceiveMessage::getRemoteTransmissionRequest()
> ```c++
> CAN_RemoteTransmissionRequest getRemoteTransmissionRequest();
> ```
> データフレームかリモートフレームかを返します

##### CAN_ReceiveMessage::getLength()
> ```c++
> uint32_t getLength();
> ```
> DLC を返します

##### CAN_ReceiveMessage::getData()
> ```c++
> uint8_t* getData();
> ```
> 受信データへのポインタを返します

[<< 戻る](../README.md)
