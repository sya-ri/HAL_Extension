#if __has_include("can.h")

#include "can_transmit_message.hpp"

namespace halex {

CAN_TxHeaderTypeDef* CAN_TransmitMessage::getHeader() {
    return &header;
}

uint8_t* CAN_TransmitMessage::getData() {
    return data;
}

void CAN_TransmitMessage::setId(uint32_t id) {
    setId(CAN_IdentifierType::Standard, id);
}

void CAN_TransmitMessage::setId(CAN_IdentifierType type, uint32_t id) {
    header.IDE = static_cast<uint32_t>(type);

    if (type == CAN_IdentifierType::Standard) {
        header.StdId = id;
    } else {
        header.ExtId = id;
    }
}

void CAN_TransmitMessage::setRemoteTransmissionRequest(CAN_RemoteTransmissionRequest value) {
    header.RTR = static_cast<uint32_t>(value);
}

void CAN_TransmitMessage::setData(uint8_t data[], uint32_t length) {
    this->data = data;
    header.DLC = length;
}

} // namespace halex

#endif // __has_include
