#ifndef HAL_EXTENSION_CAN_STATUS_TYPE_HPP
#define HAL_EXTENSION_CAN_STATUS_TYPE_HPP

#include "main.h"

namespace halex {

enum class CAN_StatusType : uint8_t {
    HAL_OK              = 0x00U,
    HAL_ERROR           = 0x01U,
    CAN_Fail_Init       = 0x04, // 初期化失敗
    CAN_Tx_Pending      = 0x05, // 送信保留中
    CAN_Tx_Not_Pending  = 0x06, // 送信保留なし
    CAN_Rx_FIFO_Empty   = 0x07, // 受信残データ有り
};

} // namespace halex

#endif // HAL_EXTENSION_CAN_STATUS_TYPE_HPP
