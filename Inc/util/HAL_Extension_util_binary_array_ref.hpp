#ifndef HAL_EXTENSION_UTIL_BINARY_ARRAY_REF_HPP
#define HAL_EXTENSION_UTIL_BINARY_ARRAY_REF_HPP

#include <array>
#include "main.h"

namespace halex {

template <std::size_t ARRAY_SIZE>
class BinaryArrayRef {
private:
    std::array<uint8_t, ARRAY_SIZE> &array;
public:
    BinaryArrayRef(std::array<uint8_t, ARRAY_SIZE> &array): array(array) {

    }

    void set(uint8_t index) noexcept {
        array[index / 8] |= (1 << (index % 8));
    }

    void reset(uint8_t index) noexcept {
        array[index / 8] &= ~(1 << (index % 8));
    }

    void write(uint8_t index, bool state) noexcept {
        if (state) {
            set(index);
        } else {
            reset(index);
        }
    }

    bool read(uint8_t index) noexcept {
        return array[index / 8] & (1 << (index % 8));
    }
};

} // namespace halex

#endif // HAL_EXTENSION_UTIL_BINARY_ARRAY_REF_HPP
