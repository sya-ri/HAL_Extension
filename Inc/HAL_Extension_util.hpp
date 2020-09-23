#ifndef HAL_EXTENSION_UTIL_HPP
#define HAL_EXTENSION_UTIL_HPP

#include "main.h"

#define delay(__ms) HAL_Delay(__ms)
#define map_contains(Map, Key) (Map.find(Key) != Map.end())

#endif
