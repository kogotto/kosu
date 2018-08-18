#ifndef VIEWS_CELL_HPP
#define VIEWS_CELL_HPP


#include <SFML/Graphics.hpp>
#include "models/cell.hpp"


namespace ks {
namespace views {


class Cell {
public:
    using Position = sf::Vector2i;
    using Model = ks::models::Cell;
    Cell(const Position& position, const sf::Font& font);

    void drawOn(
            sf::RenderWindow& window,
            const Model& cell) const;
private:
    sf::Text getText(Model::Value value) const;

    Position position_;
    const sf::Font& font_;
};


} // namespace views
} // namespace ks


#endif // VIEWS_CELL_HPP
