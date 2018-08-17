#include "cell.hpp"

#include <cassert>


namespace ks {
namespace models {

namespace {

inline std::optional<Cell::Value> valueFrom(Cell::Value v) {
    if (v == 0) {
        return {};
    }

    if ((0 < v) && (v <= 9)) {
        return v;
    }

    assert(false && "cell must contain only 1-9 numbers or nothing");
}

inline bool givenFrom(Cell::Value v) {
    if (v == 0) {
        return false;
    }

    if ((0 < v) && (v <= 9)) {
        return true;
    }

    assert(false && "cell must contain only 1-9 numbers or nothing");
}

} // namespace


Cell::Cell(Cell::Value value):
    value_(valueFrom(value)),
    given_(givenFrom(value)) {}

void Cell::clear() {
    if (!given_) value_.reset();
}


} // namespace models
} // namespace ks
