#include "machine.hpp"

namespace ks {

Machine::Machine():
    shape(100.f) {
    shape.setFillColor(sf::Color::Green);
}

void Machine::process(const sf::Event& event) {
}

void Machine::drawOn(sf::RenderWindow& window) const {
    window.draw(shape);
}

} // namespaxe ks
