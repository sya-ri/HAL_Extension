#ifndef HAL_EXTENSION_CAN_COMMUNICATION_HPP
#define HAL_EXTENSION_CAN_COMMUNICATION_HPP

#if __has_include("can.h")

#include "can.h"
#include "can_filter_config.hpp"
#include "can_receive_message.hpp"
#include "can_transmit_message.hpp"
#include "can_transmit_result.hpp"

namespace halex {

class CAN_Communication {
private:
    CAN_HandleTypeDef *hcan;
public:
    CAN_Communication(CAN_HandleTypeDef *hcan);
    CAN_Communication(CAN_HandleTypeDef &hcan);
    HAL_StatusTypeDef init();
    HAL_StatusTypeDef start();
    HAL_StatusTypeDef setFilterConfig(CAN_FilterConfig &config);
    HAL_StatusTypeDef transmit(CAN_TransmitMessage &message, CAN_TransmitResult &result);
    HAL_StatusTypeDef receive(uint32_t rxFifo, CAN_ReceiveMessage &data);
};

} // namespace halex

#endif // __has_include

#endif // HAL_EXTENSION_CAN_COMMUNICATION_HPP
