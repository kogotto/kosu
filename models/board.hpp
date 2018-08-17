#ifndef MODELS_BOARD_HPP
#define MODELS_BOARD_HPP


#include <array>

#include "cell.hpp"


namespace ks {
namespace models {

namespace models_detail {

using Row = std::array<Cell, 9>;

}

using Board = std::array<models_detail::Row, 9>;


} // namespace models
} // namespace ks


#endif // MODELS_BOARD_HPP
