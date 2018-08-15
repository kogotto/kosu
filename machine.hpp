#ifndef MACHINE_HPP
#define MACHINE_HPP


#include <SFML/Graphics.hpp>


namespace ks {


class Machine {
public:
    Machine();
    void process(const sf::Event& event);
    void drawOn(sf::RenderWindow& window) const;
private:
    sf::CircleShape shape;
};


} // namespaxe ks
#endif //MACHINE_HPP
