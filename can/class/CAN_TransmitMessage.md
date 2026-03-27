# CAN_TransmitMessage

## 目次
- [関数](#関数)
  - [getHeader()](#can_transmitmessagegetheader)
  - [getData()](#can_transmitmessagegetdata)
  - [setId(uint32_t)](#can_transmitmessagesetiduint32_t)
  - [setId(CAN_IdentifierType, uint32_t)](#can_transmitmessagesetidcan_identifiertype-uint32_t)
  - [setRemoteTransmissionRequest(CAN_RemoteTransmissionRequest)](#can_transmitmessagesetremotetransmissionrequestcan_remotetransmissionrequest)
  - [setData(uint8_t[], uint32_t)](#can_transmitmessagesetdatauint8_t-uint32_t)

## 関数
##### CAN_TransmitMessage::getHeader()
> ```c++
> CAN_TxHeaderTypeDef* getHeader();
> ```
> 送信用ヘッダへのポインタを返します

##### CAN_TransmitMessage::getData()
> ```c++
> uint8_t* getData();
> ```
> 送信データへのポインタを返します

##### CAN_TransmitMessage::setId(uint32_t)
> ```c++
> void setId(
>     uint32_t id
> );
> ```
> 標準 ID を設定します
> ```c++
> // 例
> message.setId(0x100);
> ```

##### CAN_TransmitMessage::setId(CAN_IdentifierType, uint32_t)
> ```c++
> void setId(
>     CAN_IdentifierType type,
>     uint32_t id
> );
> ```
> 標準 ID / 拡張 ID を指定して設定します
> ```c++
> // 例
> message.setId(CAN_IdentifierType::Extended, 0x18FF50E5);
> ```

##### CAN_TransmitMessage::setRemoteTransmissionRequest(CAN_RemoteTransmissionRequest)
> ```c++
> void setRemoteTransmissionRequest(
>     CAN_RemoteTransmissionRequest value
> );
> ```
> データフレームかリモートフレームかを設定します

##### CAN_TransmitMessage::setData(uint8_t[], uint32_t)
> ```c++
> void setData(
>     uint8_t data[],
>     uint32_t length
> );
> ```
> データポインタと DLC を設定します
> ```c++
> // 例
> uint8_t data[8] = {1, 2, 3, 4};
> message.setData(data, 4);
> ```

[<< 戻る](../README.md)
