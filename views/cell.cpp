#include "cell.hpp"

namespace ks {
namespace views {

namespace {

inline constexpr char toChar(Cell::Model::Value value) noexcept {
    return '0' + value;
}

} // namespace

Cell::Cell(
        const Position& position,
        const Size& size,
        const sf::Font& font):
    position_(position),
    size_(size),
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
    sf::Text text {
        toChar(value),
        font_
    };
    text.setFillColor(sf::Color::White);
    text.setPosition(position_);
    return text;
}

} // namespace views
} // namespace ks
