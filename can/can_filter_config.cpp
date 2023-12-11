#if __has_include("can.h")

#include "can_filter_config.hpp"

namespace halex {

void CAN_FilterConfig::setFilterFIFOAssignment(uint32_t value) {
    config.FilterFIFOAssignment = value;
}

void CAN_FilterConfig::setFilterBank(uint32_t value) {
    config.FilterBank = value;
}

void CAN_FilterConfig::setSlaveStartFilterBank(uint32_t value) {
    config.SlaveStartFilterBank = value;
}

void CAN_FilterConfig::setIdFilter(uint32_t id1) {
    setIdFilter(id1, id1);
}

void CAN_FilterConfig::setIdFilter(uint32_t id1, uint32_t id2) {
    setIdFilter(id1, id2, id2);
}

void CAN_FilterConfig::setIdFilter(uint32_t id1, uint32_t id2, uint32_t id3) {
    setIdFilter(id1, id2, id3, id3);
}

void CAN_FilterConfig::setIdFilter(uint32_t id1, uint32_t id2, uint32_t id3, uint32_t id4) {
    config.FilterActivation = CAN_FILTER_ENABLE;
    config.FilterMode = CAN_FILTERMODE_IDLIST;
    config.FilterScale = CAN_FILTERSCALE_16BIT;

    config.FilterIdHigh = id1 << 5;
    config.FilterIdLow = id2 << 5;
    config.FilterMaskIdHigh = id3 << 5;
    config.FilterMaskIdLow = id4 << 5;
}

void CAN_FilterConfig::setIdFilter(CAN_IdentifierType type1, uint32_t id1) {
    setIdFilter(type1, id1, type1, id1);
}

void CAN_FilterConfig::setIdFilter(CAN_IdentifierType type1, uint32_t id1, CAN_IdentifierType type2, uint32_t id2) {
    config.FilterActivation = CAN_FILTER_ENABLE;
    config.FilterMode = CAN_FILTERMODE_IDLIST;
    config.FilterScale = CAN_FILTERSCALE_32BIT;

    uint32_t filterId = type1 == CAN_IdentifierType::Standard ? id1 << 21 : (id1 << 3) | 0x4;
    uint32_t filterMask = type2 == CAN_IdentifierType::Standard ? id2 << 21 : (id2 << 3) | 0x4;

    config.FilterIdHigh = filterId >> 16;
    config.FilterIdLow = filterId;
    config.FilterMaskIdHigh = filterMask >> 16;
    config.FilterMaskIdLow = filterMask;
}

void CAN_FilterConfig::setIdMaskFilter(uint32_t id1, uint32_t mask1) {
    setIdMaskFilter(id1, mask1, id1, mask1);
}

void CAN_FilterConfig::setIdMaskFilter(uint32_t id1, uint32_t mask1, uint32_t id2, uint32_t mask2) {
    config.FilterActivation = CAN_FILTER_ENABLE;
    config.FilterMode = CAN_FILTERMODE_IDMASK;
    config.FilterScale = CAN_FILTERSCALE_16BIT;

    config.FilterIdHigh = id1 << 5;
    config.FilterIdLow = id2 << 5;
    config.FilterMaskIdHigh = mask1 << 5;
    config.FilterMaskIdLow = mask2 << 5;
}

void CAN_FilterConfig::setIdMaskFilter(CAN_IdentifierType type, uint32_t id, uint32_t mask) {
    config.FilterActivation = CAN_FILTER_ENABLE;
    config.FilterMode = CAN_FILTERMODE_IDMASK;
    config.FilterScale = CAN_FILTERSCALE_32BIT;

    uint32_t filterId = type == CAN_IdentifierType::Standard ? id << 21 : (id << 3) | 0x4;
    uint32_t filterMask = type == CAN_IdentifierType::Standard ? mask << 21 : (mask << 3) | 0x4;

    config.FilterIdHigh = filterId >> 16;
    config.FilterIdLow = filterId;
    config.FilterMaskIdHigh = filterMask >> 16;
    config.FilterMaskIdLow = filterMask;
}

void CAN_FilterConfig::setIdRangeFilter(uint32_t minId1, uint32_t maxId1) {
    setIdRangeFilter(minId1, maxId1, minId1, maxId1);
}

void CAN_FilterConfig::setIdRangeFilter(uint32_t minId1, uint32_t maxId1, uint32_t minId2, uint32_t maxId2) {
    uint32_t mask21bit = 0b111111111111111111111;
    setIdMaskFilter(minId1, (~(minId1 ^ maxId1)) & mask21bit, minId2, (~(minId2 ^ maxId2)) & mask21bit);
}

void CAN_FilterConfig::setIdRangeFilter(CAN_IdentifierType type, uint32_t minId, uint32_t maxId) {
    uint32_t mask21bit = 0b111111111111111111111;
    setIdMaskFilter(type, minId, (~(minId ^ maxId)) & mask21bit);
}

void CAN_FilterConfig::disableFilter() {
    config.FilterActivation = CAN_FILTER_DISABLE;
}

CAN_FilterTypeDef* CAN_FilterConfig::get() {
    return &config;
}

} // namespace halex

#endif // __has_include
