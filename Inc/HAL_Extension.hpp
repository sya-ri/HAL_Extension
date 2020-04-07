//
// Hal_Extension 3.0.7
//

#ifndef HAL_EXTENSION_HPP
#define HAL_EXTENSION_HPP

#include "HAL_Extension_util.hpp"

#ifdef __has_include // since C++ 17

#if __has_include("gpio.h")
#include "gpio.h"
#endif // __has_include("gpio.h")

#if __has_include("usart.h")
#include "usart.h"
#endif // __has_include("usart.h")

#if __has_include("i2c.h")
#include "i2c.h"
#endif // __has_include("i2c.h")

#if __has_include("tim.h")
#include "tim.h"
#endif // __has_include("tim.h")

#if __has_include("adc.h")
#include "adc.h"
#endif // __has_include("adc.h")

#endif // __has_include

#include "HAL_Extension_gpio.hpp"
#include "HAL_Extension_usart.hpp"
#include "HAL_Extension_i2c.hpp"
#include "HAL_Extension_tim.hpp"
#include "HAL_Extension_adc.hpp"

#endif //HAL_EXTENSION_HPP
