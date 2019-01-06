#ifndef MACHINE_HPP
#define MACHINE_HPP


#include <SFML/Graphics.hpp>

#include "menustate.hpp"
#include "gamestate.hpp"


namespace ks {


class Machine {
public:
    enum class Transition {
        Stay,
        Exit
    };

    Machine(const sf::Font& font);

    Transition process(const sf::Event& event);
    void drawOn(sf::RenderWindow& window) const;
private:
    MenuState menu;
    GameState game;

    enum class state {
        menu,
        game
    } currentState = state::menu;
};


} // namespaxe ks
#endif //MACHINE_HPP
