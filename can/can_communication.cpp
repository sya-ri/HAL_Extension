#if __has_include("can.h")

#include "can_communication.hpp"

namespace halex {

CAN_Communication::CAN_Communication(CAN_HandleTypeDef *hcan) : hcan(hcan) {

}

CAN_Communication::CAN_Communication(CAN_HandleTypeDef &hcan) : CAN_Communication(&hcan) {

}

HAL_StatusTypeDef CAN_Communication::setup() {
    HAL_StatusTypeDef init = HAL_CAN_Init(hcan);
    if (init != HAL_OK) {
        return init;
    }
    return HAL_CAN_Start(hcan);
}

void CAN_Communication::disableFilter() {
    filterConfig.FilterActivation = CAN_FILTER_DISABLE;
}

void CAN_Communication::setFilterBank(uint32_t CAN2_filterBankNumber) {
    filterConfig.FilterBank = 0;
    filterConfig.SlaveStartFilterBank = CAN2_filterBankNumber;
}

void CAN_Communication::setStoreRxFifo(uint32_t rxFifo) {
    filterConfig.FilterFIFOAssignment = rxFifo;
}

void CAN_Communication::setFourTypePathId(uint32_t id1, uint32_t id2, uint32_t id3, uint32_t id4) {
    filterConfig.FilterActivation = CAN_FILTER_ENABLE;
    filterConfig.FilterMode = CAN_FILTERMODE_IDLIST;
    filterConfig.FilterScale = CAN_FILTERSCALE_16BIT;

    filterConfig.FilterIdHigh = id1 << 5;
    filterConfig.FilterIdLow = id2 << 5;
    filterConfig.FilterMaskIdHigh = id3 << 5;
    filterConfig.FilterMaskIdLow = id4 << 5;
}

void CAN_Communication::setTwoTypePathIdGroup(uint32_t minId1, uint32_t maxId1, uint32_t minId2, uint32_t maxId2) {
    filterConfig.FilterActivation = CAN_FILTER_ENABLE;
    filterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
    filterConfig.FilterScale = CAN_FILTERSCALE_16BIT;

    uint32_t mask21bit = 0b111111111111111111111;
    filterConfig.FilterIdHigh = minId1 << 5;
    filterConfig.FilterIdLow = minId2 << 5;
    filterConfig.FilterMaskIdHigh = ((~(minId1 ^ maxId1)) & mask21bit) << 5;
    filterConfig.FilterMaskIdLow = ((~(minId2 ^ maxId2)) & mask21bit) << 5;
}

void CAN_Communication::setTwoTypePathId(IdentifierType type1, uint32_t id1, IdentifierType type2, uint32_t id2) {
    filterConfig.FilterActivation = CAN_FILTER_ENABLE;
    filterConfig.FilterMode = CAN_FILTERMODE_IDLIST;
    filterConfig.FilterScale = CAN_FILTERSCALE_32BIT;

    uint32_t filterId = type1 == IdentifierType::Standard ? id1 << 21 : (id1 << 3) | 0x4;
    uint32_t filterMask = type2 == IdentifierType::Standard ? id2 << 21 : (id2 << 3) | 0x4;

    filterConfig.FilterIdHigh = filterId >> 16;
    filterConfig.FilterIdLow = filterId;
    filterConfig.FilterMaskIdHigh = filterMask >> 16;
    filterConfig.FilterMaskIdLow = filterMask;
}

void CAN_Communication::setOneTypePathIdGroup(IdentifierType type, uint32_t minId, uint32_t maxId) {
    filterConfig.FilterActivation = CAN_FILTER_ENABLE;
    filterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
    filterConfig.FilterScale = CAN_FILTERSCALE_32BIT;

    uint32_t mask21bit = 0b111111111111111111111;
    uint32_t bitShift = type == IdentifierType::Standard ? 21 : 3;
    uint32_t filterId = minId << bitShift;
    uint32_t filterMask = ((~(minId ^ maxId)) & mask21bit) << bitShift;

    filterConfig.FilterIdHigh = filterId >> 16;
    filterConfig.FilterIdLow = filterId;
    filterConfig.FilterMaskIdHigh = filterMask >> 16;
    filterConfig.FilterMaskIdLow = filterMask;
}

HAL_StatusTypeDef CAN_Communication::applyFilterConfig() {
    return HAL_CAN_ConfigFilter(hcan, &filterConfig);
}

void CAN_Communication::setId(uint32_t id) {
    setId(IdentifierType::Standard, id);
}

void CAN_Communication::setId(IdentifierType type, uint32_t id) {
    txHeader.IDE = static_cast<uint32_t>(type);

    if (type == IdentifierType::Standard) {
        txHeader.StdId = id;
    } else {
        txHeader.ExtId = id;
    }
}

void CAN_Communication::setDataFrame(uint32_t dataFrameType) {
    txHeader.RTR = dataFrameType;
}

bool CAN_Communication::isTxMessagePending(uint32_t txMailbox) {
    return HAL_CAN_IsTxMessagePending(hcan, txMailbox) != 0;
}

HAL_StatusTypeDef CAN_Communication::transmit(uint8_t dataLength, uint8_t txData[]) {
    txHeader.DLC = dataLength;
    return HAL_CAN_AddTxMessage(hcan, &txHeader, txData, &usedTxMailbox);
}

uint32_t CAN_Communication::getUsedTxMailbox() {
    return usedTxMailbox;
}

HAL_StatusTypeDef CAN_Communication::receive(uint32_t rxFifo, uint8_t rxData[]) {
    if (HAL_CAN_GetRxFifoFillLevel(hcan, rxFifo) == 0) {
        return HAL_StatusTypeDef::HAL_OK;
    }
    return HAL_CAN_GetRxMessage(hcan, rxFifo, &rxHeader, rxData);
}

uint32_t CAN_Communication::getRxIdType() {
    return rxHeader.IDE;
}

uint32_t CAN_Communication::getRxId() {
    if (rxHeader.IDE == CAN_ID_STD) {
        return rxHeader.StdId;
    } else {
        return rxHeader.ExtId;
    }
}

uint32_t CAN_Communication::getRxDataLength() {
    return rxHeader.DLC;
}

HAL_StatusTypeDef CAN_Communication::abortTransmit(uint32_t txMailBox) {
    if (isMailBoxPending(txMailBox)) {
        return HAL_CAN_AbortTxRequest(hcan, txMailBox);
    }
    return HAL_StatusTypeDef::HAL_OK;
}

HAL_CAN_StateTypeDef CAN_Communication::getState() {
    return hcan->State;
}

} // namespace halex

#endif // __has_include
