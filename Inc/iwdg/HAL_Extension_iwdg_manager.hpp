#ifndef HAL_EXTENSION_IWDG_MANAGER_HPP
#define HAL_EXTENSION_IWDG_MANAGER_HPP

#ifndef CONFIG_DISABLE_MODULE_IWDG

#include "iwdg.h"
#include <array>
#include <limits>
#include <cmath>

namespace halex {

class IWDG_Manager {
public:
    enum class TimeUnit: uint32_t {
        s  = 1,
        ms = s * 1000,
        us = ms * 1000,
    };
private:
    struct Prescaler {
        uint32_t value;
        uint32_t export_constant;
    };

    struct InitOption {
        Prescaler prescaler;
        uint32_t reloadCount;
    };

    static constexpr std::array<Prescaler, 7> prescalers = {
        Prescaler{4, IWDG_PRESCALER_4},
        Prescaler{8, IWDG_PRESCALER_8},
        Prescaler{16, IWDG_PRESCALER_16},
        Prescaler{32, IWDG_PRESCALER_32},
        Prescaler{64, IWDG_PRESCALER_64},
        Prescaler{128, IWDG_PRESCALER_128},
        Prescaler{256, IWDG_PRESCALER_256}
    };

    static constexpr InitOption getInitOption(
        float timeOut,
        TimeUnit timeUnit
    ) {
        InitOption initOption{};
        float min_reloadCount_error = std::numeric_limits<float>::max();
        for (uint8_t i = 0; i < (sizeof(prescalers) / sizeof(prescalers[0])); i++) {
            float reloadCount = timeOut * LSI_VALUE / (static_cast<float>(prescalers[i].value) * static_cast<uint32_t>(timeUnit));
            uint32_t reloadCount_u32 = std::round(reloadCount);
            if (reloadCount_u32 < 1 || 4095 < reloadCount_u32) continue;
            float reloadCount_error = reloadCount - reloadCount_u32;
            if (reloadCount_error < min_reloadCount_error) {
                initOption.prescaler = prescalers[i];
                initOption.reloadCount = reloadCount_u32;
                min_reloadCount_error = reloadCount_error;
            }
        }
        return initOption;
    }

    const InitOption initOption;
public:
    static constexpr float minTimeOut = 4 / static_cast<float>(LSI_VALUE);
    static constexpr float maxTimeOut = 256 * 4095 / static_cast<float>(LSI_VALUE);

    constexpr IWDG_Manager(
        float timeOut,
        TimeUnit timeUnit
    ):
        initOption(getInitOption(timeOut, timeUnit))
    {

    }

    constexpr bool available() {
        return initOption.prescaler.value != 0;
    }

    constexpr void init() {
        if (available()) {
            hiwdg.Init.Prescaler = initOption.prescaler.export_constant;
            hiwdg.Init.Reload = initOption.reloadCount;
            HAL_IWDG_Init(&hiwdg);
        }
    }

    constexpr void refresh() {
        if (available()) {
            HAL_IWDG_Refresh(&hiwdg);
        }
    }
};

} // namespace halex

#endif // CONFIG_DISABLE_MODULE_IWDG

#endif // HAL_EXTENSION_IWDG_MANAGER_HPP
