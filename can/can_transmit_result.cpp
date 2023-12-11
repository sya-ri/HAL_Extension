#if __has_include("can.h")

#include "can_transmit_result.hpp"

namespace halex {

void CAN_TransmitResult::setInstance(CAN_HandleTypeDef *hcan) {
    this->hcan = hcan;
}

uint32_t* CAN_TransmitResult::getMailBox() {
    return &mailBox;
}

bool CAN_TransmitResult::isOk() {
    return hcan != nullptr && mailBox != 0;
}

HAL_StatusTypeDef CAN_TransmitResult::abort() {
    if (isPending()) {
        return HAL_CAN_AbortTxRequest(hcan, mailBox);
    }
    return HAL_StatusTypeDef::HAL_OK;
}

bool CAN_TransmitResult::isPending() {
    return HAL_CAN_IsTxMessagePending(hcan, mailBox) != 0;
}

} // namespace halex

#endif // __has_include
