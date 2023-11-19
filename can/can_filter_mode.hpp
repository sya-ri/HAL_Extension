#ifndef HAL_EXTENSION_CAN_FILTER_MODE_HPP
#define HAL_EXTENSION_CAN_FILTER_MODE_HPP

#include "main.h"

namespace halex {

enum class CAN_FilterMode: uint8_t {
    PATH_ONE_TYPE_STD_OR_EXT_ID_GROUP = 0x10,
    PATH_TWO_TYPE_STD_OR_EXT_ID       = 0x12,
    PATH_TWO_TYPE_STD_ID_GROUP        = 0x13,
    PATH_FOUR_TYPE_STD_ID             = 0x14,
    PATH_ALL_ID                       = 0x15
};

} // namespace halex

#endif // HAL_EXTENSION_CAN_FILTER_MODE_HPP
