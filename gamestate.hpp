#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP


#include <SFML/Graphics.hpp>


namespace ks {


class GameState {
public:
    enum class Transition {
        Stay,
        ToMenu
    };

    GameState();

    Transition process(const sf::Event& event);
    void drawOn(sf::RenderWindow & window) const;
private:
    sf::RectangleShape shape;
};


}


#endif // GAME_STATE_HPP
