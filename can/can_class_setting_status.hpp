#ifndef HAL_EXTENSION_CAN_CLASS_SETTING_STATUS_HPP
#define HAL_EXTENSION_CAN_CLASS_SETTING_STATUS_HPP

#include "main.h"

namespace halex {

enum class CAN_ClassSettingStatus: uint8_t {
    WRONG_SET_PATH_ID_FUNCTION_USED = 0x20,
    ALL_ID_PATH                     = 0x21,
    NON_ERROR                       = 0x00
};

} // namespace halex

#endif // HAL_EXTENSION_CAN_CLASS_SETTING_STATUS_HPP
