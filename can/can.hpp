#ifndef HAL_EXTENSION_CAN_HPP
#define HAL_EXTENSION_CAN_HPP

#if __has_include("can.h")

#include "can.h"
#include <array>
#include "can_class_setting_status.hpp"

namespace halex {

class Can {
private:
    CAN_HandleTypeDef *hcan;

    CAN_FilterTypeDef filterConfig;

    CAN_RxHeaderTypeDef rxHeader;
    CAN_TxHeaderTypeDef txHeader;

    uint32_t usedTxMailbox;

    std::array<uint32_t, 4> filterId = {0};
    std::array<uint32_t, 2> filterMask;

public:
    enum class IdentifierType : uint32_t {
        Standard = CAN_ID_STD,
        Extended = CAN_ID_EXT
    };

    Can(CAN_HandleTypeDef *hcan);

    HAL_StatusTypeDef setup();
    void disableFilter();
    void setFilterBank(uint32_t CAN2_filterBankNumber);
    void setStoreRxFifo(uint32_t rxFifo);

    // standard id only
    CAN_ClassSettingStatus setFourTypePathId(uint32_t id1, uint32_t id2, uint32_t id3, uint32_t id4);
    CAN_ClassSettingStatus setTwoTypePathIdGroup(uint32_t minId1, uint32_t maxId1, uint32_t minId2, uint32_t maxId2);

    // standard id and extend id
    CAN_ClassSettingStatus setTwoTypePathId(IdentifierType type1, uint32_t id1, IdentifierType type2, uint32_t id2);
    CAN_ClassSettingStatus setOneTypePathIdGroup(IdentifierType type, uint32_t minId, uint32_t maxId);

    HAL_StatusTypeDef setFilterConfig();

    void setId(uint32_t id);
    void setId(IdentifierType type, uint32_t id);
    void setDataFrame(uint32_t dataFrameType);

    bool isMailBoxPending(uint32_t txMailbox);
    HAL_StatusTypeDef transmit(uint8_t dataLength, uint8_t txData[]);
    uint32_t getUsedTxMailbox();

    HAL_StatusTypeDef receive(uint32_t rxFifo, uint8_t rxData[]);
    uint32_t getRxIdType();
    uint32_t getRxId();
    uint32_t getRxDataLength();

    HAL_StatusTypeDef abortTransmit(uint32_t txMailBox);

    HAL_CAN_StateTypeDef getState();
    uint32_t getFilterId(uint8_t idNum);
    uint32_t getMaskId(uint8_t maskNum);
};

} // namespace halex

#endif // __has_include

#endif // HAL_EXTENSION_CAN_HPP
