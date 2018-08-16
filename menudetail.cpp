#include "menudetail.hpp"

namespace ks {
namespace menu_detail {

namespace {

inline constexpr auto toInt(Item item) {
    return static_cast<int>(item);
}
inline constexpr auto toItem(int item) {
    return static_cast<Item>(item);
}

constexpr auto count = toInt(Item::Count);

}

Item prev(Item item) {
    const auto result = (toInt(item) + count - 1) % count;
    return toItem(result);
}

Item next(Item item) {
    const auto result = (toInt(item) + 1) % count;
    return toItem(result);
}


} // namespace menu_detail
} // namespace ks
