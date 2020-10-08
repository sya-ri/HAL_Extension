#ifndef HAL_EXTENSION_UTIL_BINARY_ARRAY_HPP
#define HAL_EXTENSION_UTIL_BINARY_ARRAY_HPP

#include <array>
#include "main.h"
#include "HAL_Extension_util_binary_array_ref.hpp"

namespace halex {

template <std::size_t ARRAY_SIZE>
class BinaryArray{
private:
    std::array<uint8_t, ARRAY_SIZE> array{};
    BinaryArrayRef<ARRAY_SIZE> internalBinaryArray{array};
public:
    BinaryArray() {

    }

    void set(uint8_t index) noexcept {
        internalBinaryArray.set(index);
    }

    void reset(uint8_t index) noexcept {
        internalBinaryArray.reset(index);
    }

    void write(uint8_t index, bool state) noexcept {
        internalBinaryArray.write(index, state);
    }

    bool read(uint8_t index) const noexcept {
        return internalBinaryArray.read(index);
    }

    const std::array<uint8_t, ARRAY_SIZE> get() const noexcept {
        return array;
    }
};

} // namespace halex

#endif // HAL_EXTENSION_UTIL_BINARY_ARRAY_HPP
