#if __has_include("can.h")

#include "can_communication.hpp"

namespace halex {

CAN_Communication::CAN_Communication(CAN_HandleTypeDef *hcan) : hcan(hcan) {

}

CAN_Communication::CAN_Communication(CAN_HandleTypeDef &hcan) : CAN_Communication(&hcan) {

}

HAL_StatusTypeDef CAN_Communication::init() {
    HAL_CAN_DeInit(hcan);
    return HAL_CAN_Init(hcan);
}

HAL_StatusTypeDef CAN_Communication::start() {
    return HAL_CAN_Start(hcan);
}

HAL_StatusTypeDef CAN_Communication::setFilterConfig(CAN_FilterConfig &config) {
    return HAL_CAN_ConfigFilter(hcan, config.get());
}

HAL_StatusTypeDef CAN_Communication::transmit(CAN_TransmitMessage &message, CAN_TransmitResult &result) {
    result.setInstance(hcan);
    return HAL_CAN_AddTxMessage(hcan, message.getHeader(), message.getData(), result.getMailBox());
}

HAL_StatusTypeDef CAN_Communication::receive(uint32_t rxFifo, CAN_ReceiveMessage &message) {
    if (HAL_CAN_GetRxFifoFillLevel(hcan, rxFifo) == 0) {
        return HAL_StatusTypeDef::HAL_OK;
    }
    return HAL_CAN_GetRxMessage(hcan, rxFifo, message.getHeader(), message.getData());
}

} // namespace halex

#endif // __has_include
