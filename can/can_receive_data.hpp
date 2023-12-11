#ifndef HAL_EXTENSION_CAN_RECEIVE_DATA_HPP
#define HAL_EXTENSION_CAN_RECEIVE_DATA_HPP

#if __has_include("can.h")

#include "can.h"
#include "can_identifier_type.hpp"
#include "can_remote_transmission_request.hpp"

namespace halex {

class CAN_ReceiveData {
private:
    CAN_RxHeaderTypeDef header = {};
	uint8_t data[8] = {};
public:
	CAN_RxHeaderTypeDef* getHeader();
	uint32_t getId();
	CAN_IdentifierType getType();
	CAN_RemoteTransmissionRequest getRemoteTransmissionRequest();
	uint32_t getLength();
	uint8_t* get();
};

} // namespace halex

#endif // __has_include

#endif // HAL_EXTENSION_CAN_RECEIVE_DATA_HPP
