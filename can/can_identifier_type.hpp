#ifndef HAL_EXTENSION_CAN_IDENTIFIER_TYPE_HPP
#define HAL_EXTENSION_CAN_IDENTIFIER_TYPE_HPP

#if __has_include("can.h")

#include "can.h"

namespace halex {

enum class CAN_IdentifierType : uint32_t {
    Standard = CAN_ID_STD,
    Extended = CAN_ID_EXT
};

} // namespace halex

#endif // __has_include

#endif // HAL_EXTENSION_CAN_IDENTIFIER_TYPE_HPP
