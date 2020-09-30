#ifndef HAL_EXTENSION_UTIL_HPP
#define HAL_EXTENSION_UTIL_HPP

#include <map>

namespace halex {

template <class K, class V>
constexpr bool map_contains(const std::map<K, V> &map, const K &key) {
    return map.find(key) != map.end();
}

} // namespace halex

#endif
