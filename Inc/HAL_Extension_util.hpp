#ifndef HAL_EXTENSION_UTIL_HPP
#define HAL_EXTENSION_UTIL_HPP

#include "main.h"

#define getTick() HAL_GetTick()
#define delay(__ms) HAL_Delay(__ms)
#define gpioToggle(GPIOx, GPIO_Pin) HAL_GPIO_TogglePin(GPIOx, GPIO_Pin)
#define map_contains(Map, Key) (Map.find(Key) != Map.end())

#endif
