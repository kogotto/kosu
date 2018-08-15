#ifndef MACHINE_HPP
#define MACHINE_HPP


#include <SFML/Graphics.hpp>

#include "menustate.hpp"


namespace ks {


class Machine {
public:
    Machine() = default;
    void process(const sf::Event& event);
    void drawOn(sf::RenderWindow& window) const;
private:
    MenuState menu;
};


} // namespaxe ks
#endif //MACHINE_HPP
