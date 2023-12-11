#if __has_include("can.h")

#include "can_receive_data.hpp"

namespace halex {

CAN_RxHeaderTypeDef* CAN_ReceiveData::getHeader() {
	return &header;
}

uint32_t CAN_ReceiveData::getId() {
	return getType() == CAN_IdentifierType::Standard ? header.StdId : header.ExtId;
}

CAN_RemoteTransmissionRequest CAN_ReceiveData::getRemoteTransmissionRequest() {
	return static_cast<CAN_RemoteTransmissionRequest>(header.RTR);
}

uint32_t CAN_ReceiveData::getLength() {
	return header.DLC;
}

uint8_t* CAN_ReceiveData::get() {
	return data;
}

} // namespace halex

#endif // __has_include
