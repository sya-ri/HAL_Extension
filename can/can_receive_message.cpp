#if __has_include("can.h")

#include "can_receive_message.hpp"

namespace halex {

CAN_RxHeaderTypeDef* CAN_ReceiveMessage::getHeader() {
	return &header;
}

uint32_t CAN_ReceiveMessage::getId() {
	return getType() == CAN_IdentifierType::Standard ? header.StdId : header.ExtId;
}

CAN_RemoteTransmissionRequest CAN_ReceiveMessage::getRemoteTransmissionRequest() {
	return static_cast<CAN_RemoteTransmissionRequest>(header.RTR);
}

uint32_t CAN_ReceiveMessage::getLength() {
	return header.DLC;
}

uint8_t* CAN_ReceiveMessage::getData() {
	return data;
}

} // namespace halex

#endif // __has_include
