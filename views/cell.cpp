#include "cell.hpp"

namespace ks {
namespace views {

namespace {

inline constexpr char toChar(Cell::Model::Value value) noexcept {
    return '0' + value;
}

} // namespace

Cell::Cell(const Cell::Position& position, const sf::Font& font):
    position_(position),
    font_(font) {}

void Cell::drawOn(
        sf::RenderWindow& window,
        const Model& cell) const {
    if (!cell.value_) {
        return;
    }

    const auto text = getText(*cell.value_);
    window.draw(text);
}

sf::Text Cell::getText(Cell::Model::Value value) const {
    return {
        toChar(value),
        font_
    };
}

} // namespace views
} // namespace ks