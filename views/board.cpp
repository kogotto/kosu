#include "board.hpp"

namespace ks {
namespace views {

namespace {

inline Size getCellSize(
        const Size& size,
        size_t rows,
        size_t cols) {
    return {
        size.x / rows,
        size.y / cols
    };
}

inline Position getCellPosition(
        const Position& origin,
        size_t row,
        size_t col,
        const Size& cellSize) {
    return {
        origin.x + row * cellSize.x,
        origin.y + col * cellSize.y
    };
}

Board::Cells createCells(
        const Position& position,
        const Size& size,
        const sf::Font& font) {
    constexpr auto rows = Board::Model().size();
    constexpr auto cols = Board::Model()[0].size();
    Board::Cells result;
    result.reserve(rows);
    const auto cellSize = getCellSize(size, rows, cols);
    for (size_t i = 0; i < rows; ++i) {
        Board::Cells::value_type row;
        row.reserve(cols);
        for (size_t j = 0; j < cols; ++j) {
            const auto cellPosition = getCellPosition(
                    position,
                    i,
                    j,
                    cellSize);
            row.emplace_back(cellPosition, cellSize, font);
        }
        result.push_back(std::move(row));
    }
    return result;
}

}

Board::Board(
        const Position& position,
        const Size& size,
        const sf::Font& font):
    position_(position),
    size_(size),
    cells_(createCells(position, size, font)) {}

void Board::drawOn(sf::RenderWindow& window,
        const Board::Model& board) const {
    drawTable(window);
    drawCells(window, board);
}

void Board::drawTable(sf::RenderWindow& window) const {
    sf::RectangleShape substrate(size_);
    substrate.setPosition(position_);
    substrate.setFillColor(sf::Color::Blue);

    window.draw(substrate);
}

void Board::drawCells(
        sf::RenderWindow& window,
        const Board::Model& board) const {
    constexpr auto rows = Board::Model().size();
    constexpr auto cols = Board::Model()[0].size();
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            cells_[i][j].drawOn(window, board[i][j]);
        }
    }
}

} // namespace views
} // namespace ks
