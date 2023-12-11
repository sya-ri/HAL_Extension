#ifndef HAL_EXTENSION_CAN_TRANSMIT_RESULT_HPP
#define HAL_EXTENSION_CAN_TRANSMIT_RESULT_HPP

#if __has_include("can.h")

#include "can.h"

namespace halex {

class CAN_TransmitResult {
private:
    CAN_HandleTypeDef *hcan = nullptr;
	uint32_t mailBox = 0;
public:
	void setInstance(CAN_HandleTypeDef *hcan);
	uint32_t* getMailBox();
	bool isOk();
	HAL_StatusTypeDef abort();
	bool isPending();
};

} // namespace halex

#endif // __has_include

#endif // HAL_EXTENSION_CAN_TRANSMIT_RESULT_HPP
