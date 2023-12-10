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

void CAN_Communication::setRemoteTransmissionRequest(RemoteTransmissionRequest value) {
    txHeader.RTR = static_cast<uint32_t>(value);
}

void CAN_Communication::setFilterFIFOAssignment(uint32_t value) {
    filterConfig.FilterFIFOAssignment = value;
}

void CAN_Communication::setFilterBank(uint32_t value) {
    filterConfig.FilterBank = value;
}

void CAN_Communication::setSlaveStartFilterBank(uint32_t value) {
    filterConfig.SlaveStartFilterBank = value;
}

void CAN_Communication::setIdFilter(uint32_t id1) {
    setIdFilter(id1, id1);
}

void CAN_Communication::setIdFilter(uint32_t id1, uint32_t id2) {
    setIdFilter(id1, id2, id2);
}

void CAN_Communication::setIdFilter(uint32_t id1, uint32_t id2, uint32_t id3) {
    setIdFilter(id1, id2, id3, id3);
}

void CAN_Communication::setIdFilter(uint32_t id1, uint32_t id2, uint32_t id3, uint32_t id4) {
    filterConfig.FilterActivation = CAN_FILTER_ENABLE;
    filterConfig.FilterMode = CAN_FILTERMODE_IDLIST;
    filterConfig.FilterScale = CAN_FILTERSCALE_16BIT;

    filterConfig.FilterIdHigh = id1 << 5;
    filterConfig.FilterIdLow = id2 << 5;
    filterConfig.FilterMaskIdHigh = id3 << 5;
    filterConfig.FilterMaskIdLow = id4 << 5;
}

void CAN_Communication::setIdFilter(IdentifierType type1, uint32_t id1) {
    setIdFilter(type1, id1, type1, id1);
}

void CAN_Communication::setIdFilter(IdentifierType type1, uint32_t id1, IdentifierType type2, uint32_t id2) {
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

void CAN_Communication::setIdMaskFilter(uint32_t id1, uint32_t mask1) {
    setIdMaskFilter(id1, mask1, id1, mask1);
}

void CAN_Communication::setIdMaskFilter(uint32_t id1, uint32_t mask1, uint32_t id2, uint32_t mask2) {
    filterConfig.FilterActivation = CAN_FILTER_ENABLE;
    filterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
    filterConfig.FilterScale = CAN_FILTERSCALE_16BIT;

    filterConfig.FilterIdHigh = id1 << 5;
    filterConfig.FilterIdLow = id2 << 5;
    filterConfig.FilterMaskIdHigh = mask1 << 5;
    filterConfig.FilterMaskIdLow = mask2 << 5;
}

void CAN_Communication::setIdMaskFilter(IdentifierType type, uint32_t id, uint32_t mask) {
    filterConfig.FilterActivation = CAN_FILTER_ENABLE;
    filterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
    filterConfig.FilterScale = CAN_FILTERSCALE_32BIT;

    uint32_t filterId = type == IdentifierType::Standard ? id << 21 : (id << 3) | 0x4;
    uint32_t filterMask = type == IdentifierType::Standard ? mask << 21 : (mask << 3) | 0x4;

    filterConfig.FilterIdHigh = filterId >> 16;
    filterConfig.FilterIdLow = filterId;
    filterConfig.FilterMaskIdHigh = filterMask >> 16;
    filterConfig.FilterMaskIdLow = filterMask;
}

void CAN_Communication::setIdRangeFilter(uint32_t minId1, uint32_t maxId1) {
    setIdRangeFilter(minId1, maxId1, minId1, maxId1);
}

void CAN_Communication::setIdRangeFilter(uint32_t minId1, uint32_t maxId1, uint32_t minId2, uint32_t maxId2) {
    uint32_t mask21bit = 0b111111111111111111111;
    setIdMaskFilter(minId1, (~(minId1 ^ maxId1)) & mask21bit, minId2, (~(minId2 ^ maxId2)) & mask21bit);
}

void CAN_Communication::setIdRangeFilter(IdentifierType type, uint32_t minId, uint32_t maxId) {
    uint32_t mask21bit = 0b111111111111111111111;
    setIdMaskFilter(type, minId, (~(minId ^ maxId)) & mask21bit);
}

void CAN_Communication::disableFilter() {
    filterConfig.FilterActivation = CAN_FILTER_DISABLE;
}

HAL_StatusTypeDef CAN_Communication::applyFilterConfig() {
    return HAL_CAN_ConfigFilter(hcan, &filterConfig);
}

HAL_StatusTypeDef CAN_Communication::transmit(uint8_t dataLength, uint8_t txData[]) {
    txHeader.DLC = dataLength;
    return HAL_CAN_AddTxMessage(hcan, &txHeader, txData, &usedTxMailbox);
}

HAL_StatusTypeDef CAN_Communication::abortTransmit(uint32_t txMailBox) {
    if (isTxMessagePending(txMailBox)) {
        return HAL_CAN_AbortTxRequest(hcan, txMailBox);
    }
    return HAL_StatusTypeDef::HAL_OK;
}

bool CAN_Communication::isTxMessagePending(uint32_t txMailbox) {
    return HAL_CAN_IsTxMessagePending(hcan, txMailbox) != 0;
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

HAL_CAN_StateTypeDef CAN_Communication::getState() {
    return hcan->State;
}

} // namespace halex

#endif // __has_include
