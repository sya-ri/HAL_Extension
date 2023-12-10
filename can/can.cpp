#if __has_include("can.h")

#include "can.hpp"

namespace halex {

Can::Can(CAN_HandleTypeDef *hcan) : hcan(hcan) {

}

CAN_StatusType Can::setup() {
    if (HAL_CAN_Init(hcan) != HAL_OK) {
        return CAN_StatusType::CAN_Fail_Init;
    }
    return static_cast<CAN_StatusType>(HAL_CAN_Start(hcan));
}

void Can::disableFilter() {
    filterConfig.FilterActivation = CAN_FILTER_DISABLE;
}

void Can::setFilterBank(uint32_t CAN2_filterBankNumber) {
    filterConfig.FilterBank = 0;
    filterConfig.SlaveStartFilterBank = CAN2_filterBankNumber;
}

void Can::setStoreRxFifo(uint32_t rxFifo) {
    filterConfig.FilterFIFOAssignment = rxFifo;
}

CAN_ClassSettingStatus Can::setFourTypePathId(uint32_t id1, uint32_t id2, uint32_t id3, uint32_t id4) {
    filterConfig.FilterActivation = CAN_FILTER_ENABLE;
    filterConfig.FilterMode = CAN_FILTERMODE_IDLIST;
    filterConfig.FilterScale = CAN_FILTERSCALE_16BIT;

    filterConfig.FilterIdHigh = id1 << 5;
    filterConfig.FilterIdLow = id2 << 5;
    filterConfig.FilterMaskIdHigh = id3 << 5;
    filterConfig.FilterMaskIdLow = id4 << 5;

    return CAN_ClassSettingStatus::NON_ERROR;
}

CAN_ClassSettingStatus Can::setTwoTypePathIdGroup(uint32_t minId1, uint32_t maxId1, uint32_t minId2, uint32_t maxId2) {
    filterConfig.FilterActivation = CAN_FILTER_ENABLE;
    filterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
    filterConfig.FilterScale = CAN_FILTERSCALE_16BIT;

    uint32_t mask21bit = 0b111111111111111111111;
    filterConfig.FilterIdHigh = minId1 << 5;
    filterConfig.FilterIdLow = minId2 << 5;
    filterConfig.FilterMaskIdHigh = ((~(minId1 ^ maxId1)) & mask21bit) << 5;
    filterConfig.FilterMaskIdLow = ((~(minId2 ^ maxId2)) & mask21bit) << 5;

    return CAN_ClassSettingStatus::NON_ERROR;
}

CAN_ClassSettingStatus Can::setTwoTypePathId(IdentifierType type1, uint32_t id1, IdentifierType type2, uint32_t id2) {
    filterConfig.FilterActivation = CAN_FILTER_ENABLE;
    filterConfig.FilterMode = CAN_FILTERMODE_IDLIST;
    filterConfig.FilterScale = CAN_FILTERSCALE_32BIT;

    if (type1 == IdentifierType::Standard) {
        filterId[0] = id1 << 21;
    } else {
        filterId[0] = (id1 << 3) | 0x4;
    }

    if (type2 == IdentifierType::Standard) {
        filterId[1] = id2 << 21;
    } else {
        filterId[1] = (id2 << 3) | 0x4;
    }

    filterConfig.FilterIdHigh = filterId[0] >> 16;
    filterConfig.FilterIdLow = filterId[0];

    filterConfig.FilterMaskIdHigh = filterId[1] >> 16;
    filterConfig.FilterMaskIdLow = filterId[1];

    return CAN_ClassSettingStatus::NON_ERROR;
}

CAN_ClassSettingStatus Can::setOneTypePathIdGroup(IdentifierType type, uint32_t minId, uint32_t maxId) {
    filterConfig.FilterActivation = CAN_FILTER_ENABLE;
    filterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
    filterConfig.FilterScale = CAN_FILTERSCALE_32BIT;

    std::array<uint8_t, 2> bitShift;
    if (type == IdentifierType::Standard) {
        bitShift[0] = 21;
    } else {
        bitShift[0] = 3;
    }

    filterId[0] = minId << bitShift[0];

    minId <<= 21;
    maxId <<= 21;
    filterMask[0] = ((~(minId ^ maxId)) >> 21);
    filterMask[0] <<= bitShift[0];

    filterConfig.FilterIdHigh = filterId[0] >> 16;
    filterConfig.FilterIdLow = filterId[0];

    filterConfig.FilterMaskIdHigh = filterMask[0] >> 16;
    filterConfig.FilterMaskIdLow = filterMask[0];

    return CAN_ClassSettingStatus::NON_ERROR;
}

CAN_StatusType Can::setFilterConfig() {
    return static_cast<CAN_StatusType>(HAL_CAN_ConfigFilter(hcan, &filterConfig));
}

void Can::setId(uint32_t id) {
    setId(IdentifierType::Standard, id);
}

void Can::setId(IdentifierType type, uint32_t id) {
    txHeader.IDE = static_cast<uint32_t>(type);

    if (type == IdentifierType::Standard) {
        txHeader.StdId = id;
    } else {
        txHeader.ExtId = id;
    }
}

void Can::setDataFrame(uint32_t dataFrameType) {
    txHeader.RTR = dataFrameType;
}

bool Can::isMailBoxPending(uint32_t txMailbox) {
    if (HAL_CAN_IsTxMessagePending(hcan, txMailbox) != 0) {
        return true;
    }
    return false;
}

CAN_StatusType Can::transmit(uint8_t dataLength, uint8_t txData[]) {
    txHeader.DLC = dataLength;
    return static_cast<CAN_StatusType>(HAL_CAN_AddTxMessage(hcan, &txHeader, txData, &usedTxMailbox));
}

uint32_t Can::getUsedTxMailbox() {
    return usedTxMailbox;
}

CAN_StatusType Can::receive(uint32_t rxFifo, uint8_t rxData[]) {
    if (HAL_CAN_GetRxFifoFillLevel(hcan, rxFifo) == 0) {
        return CAN_StatusType::CAN_Rx_FIFO_Empty;
    }
    return static_cast<CAN_StatusType>(HAL_CAN_GetRxMessage(hcan, rxFifo, &rxHeader, rxData));
}

uint32_t Can::getRxIdType() {
    return rxHeader.IDE;
}

uint32_t Can::getRxId() {
    if (rxHeader.IDE == CAN_ID_STD) {
        return rxHeader.StdId;
    } else if (rxHeader.IDE == CAN_ID_EXT) {
        return rxHeader.ExtId;
    } else {
        return static_cast<uint32_t>(CAN_StatusType::HAL_ERROR);
    }
}

uint32_t Can::getRxDataLength() {
    return rxHeader.DLC;
}

HAL_StatusTypeDef Can::abortTransmit(uint32_t txMailBox) {
    if (HAL_CAN_IsTxMessagePending(hcan, txMailBox) != 1) {
        return HAL_StatusTypeDef::HAL_OK;
    }
    return HAL_CAN_AbortTxRequest(hcan, txMailBox);
}

HAL_CAN_StateTypeDef Can::getState() {
    return hcan->State;
}

uint32_t Can::getFilterId(uint8_t idNum) {
    return filterId[idNum];
}

uint32_t Can::getMaskId(uint8_t maskNum) {
    return filterMask[maskNum];
}

} // namespace halex

#endif // __has_include
