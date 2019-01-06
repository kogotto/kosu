#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP


#include <optional>
#include <SFML/Graphics.hpp>
#include "models/board.hpp"
#include "views/board.hpp"


namespace ks {


class GameState {
public:
    enum class Transition {
        Stay,
        ToMenu
    };

    GameState(const sf::Font& font);

    void startNewGame();

    Transition process(const sf::Event& event);
    void drawOn(sf::RenderWindow & window) const;
private:
    views::Board boardView_;
    std::optional<models::Board> boardModel_;
};


}


#endif // GAME_STATE_HPP
