#ifndef HAL_EXTENSION_CAN_TRANSMIT_MESSAGE_HPP
#define HAL_EXTENSION_CAN_TRANSMIT_MESSAGE_HPP

#if __has_include("can.h")

#include "can.h"
#include "can_identifier_type.hpp"
#include "can_remote_transmission_request.hpp"

namespace halex {

class CAN_TransmitMessage {
private:
    CAN_TxHeaderTypeDef header = {};
	uint8_t *data;
public:
    CAN_TxHeaderTypeDef* getHeader();
    uint8_t* getData();
    void setId(uint32_t id);
    void setId(CAN_IdentifierType type, uint32_t id);
    void setRemoteTransmissionRequest(CAN_RemoteTransmissionRequest value);
    void setData(uint8_t data[], uint32_t length);
};

} // namespace halex

#endif // __has_include

#endif // HAL_EXTENSION_CAN_TRANSMIT_MESSAGE_HPP
