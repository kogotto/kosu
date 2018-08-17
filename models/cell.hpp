#ifndef MODELS_CELL_HPP
#define MODELS_CELL_HPP


#include <cstdint>
#include <optional>


namespace ks {
namespace models {


struct Cell {
    using Value = std::uint8_t;

    Cell() = default;
    Cell(Value value);

    void clear();

    std::optional<Value> value_{};
    const bool given_{false};
};


} // namespace models
} // namespace ks


#endif // MODELS_CELL_HPP
