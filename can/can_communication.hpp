#ifndef HAL_EXTENSION_CAN_COMMUNICATION_HPP
#define HAL_EXTENSION_CAN_COMMUNICATION_HPP

#if __has_include("can.h")

#include "can.h"
#include "can_identifier_type.hpp"
#include "can_receive_data.hpp"
#include "can_remote_transmission_request.hpp"

namespace halex {

class CAN_Communication {
private:
    CAN_HandleTypeDef *hcan;
    CAN_FilterTypeDef filterConfig;
    CAN_TxHeaderTypeDef txHeader;
    uint32_t usedTxMailbox;
public:
    CAN_Communication(CAN_HandleTypeDef *hcan);
    CAN_Communication(CAN_HandleTypeDef &hcan);

    // Setup
    HAL_StatusTypeDef init();
    HAL_StatusTypeDef start();

    // Transmit config
    void setId(uint32_t id);
    void setId(CAN_IdentifierType type, uint32_t id);
    void setRemoteTransmissionRequest(CAN_RemoteTransmissionRequest value);

    // Filter config
    void setFilterFIFOAssignment(uint32_t value);
    void setFilterBank(uint32_t value);
    void setSlaveStartFilterBank(uint32_t value);

    // any one
    void setIdFilter(uint32_t id1);
    void setIdFilter(uint32_t id1, uint32_t id2);
    void setIdFilter(uint32_t id1, uint32_t id2, uint32_t id3);
    void setIdFilter(uint32_t id1, uint32_t id2, uint32_t id3, uint32_t id4);
    void setIdFilter(CAN_IdentifierType type1, uint32_t id1);
    void setIdFilter(CAN_IdentifierType type1, uint32_t id1, CAN_IdentifierType type2, uint32_t id2);
    void setIdMaskFilter(uint32_t id1, uint32_t mask1);
    void setIdMaskFilter(uint32_t id1, uint32_t mask1, uint32_t id2, uint32_t mask2);
    void setIdMaskFilter(CAN_IdentifierType type, uint32_t id, uint32_t mask);
    void setIdRangeFilter(uint32_t minId1, uint32_t maxId1);
    void setIdRangeFilter(uint32_t minId1, uint32_t maxId1, uint32_t minId2, uint32_t maxId2);
    void setIdRangeFilter(CAN_IdentifierType type, uint32_t minId, uint32_t maxId);
    void disableFilter();

    HAL_StatusTypeDef applyFilterConfig();

    // Transmit
    HAL_StatusTypeDef transmit(uint8_t data[], uint8_t dataLength);
    HAL_StatusTypeDef abortTransmit(uint32_t txMailBox);
    bool isTxMessagePending(uint32_t txMailbox);
    uint32_t getUsedTxMailbox();

    // Receive
    HAL_StatusTypeDef receive(uint32_t rxFifo, CAN_ReceiveData &data);
};

} // namespace halex

#endif // __has_include

#endif // HAL_EXTENSION_CAN_COMMUNICATION_HPP
