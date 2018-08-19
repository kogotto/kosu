#ifndef VIEWS_BOARD_HPP
#define VIEWS_BOARD_HPP


#include <SFML/Graphics.hpp>
#include "models/board.hpp"
#include "views/common.hpp"
#include "views/cell.hpp"


namespace ks {
namespace views {


class Board {
public:
    using Model = ks::models::Board;
    using Cells = std::vector<std::vector<Cell>>;

    Board(const Position& position,
            const Size& size,
            const sf::Font& font);

    void drawOn(
            sf::RenderWindow& window,
            const Model& board) const;
private:
    void drawTable(sf::RenderWindow& window) const;
    void drawCells(sf::RenderWindow& window, const Model& board) const;

    Position position_;
    Size size_;
    Cells cells_;
};


} // namespace views
} // namespace ks


#endif // VIEWS_BOARD_HPP
