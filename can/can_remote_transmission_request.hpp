#ifndef HAL_EXTENSION_CAN_REMOTE_TRANSMISSION_REQUEST_HPP
#define HAL_EXTENSION_CAN_REMOTE_TRANSMISSION_REQUEST_HPP

#if __has_include("can.h")

#include "can.h"

namespace halex {

enum class CAN_RemoteTransmissionRequest : uint32_t {
    Data = CAN_RTR_DATA,
    Remote = CAN_RTR_REMOTE
};

} // namespace halex

#endif // __has_include

#endif // HAL_EXTENSION_CAN_REMOTE_TRANSMISSION_REQUEST_HPP
