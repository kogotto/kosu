#ifndef MACHINE_HPP
#define MACHINE_HPP


#include <SFML/Graphics.hpp>

#include "menustate.hpp"


namespace ks {


class Machine {
public:
    enum class Transition {
        Stay,
        Exit
    };

    Machine() = default;

    Transition process(const sf::Event& event);
    void drawOn(sf::RenderWindow& window) const;
private:
    MenuState menu;
};


} // namespaxe ks
#endif //MACHINE_HPP
