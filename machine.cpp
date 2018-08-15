#include "machine.hpp"

namespace ks {

void Machine::process(const sf::Event& event) {
    menu.process(event);
}

void Machine::drawOn(sf::RenderWindow& window) const {
    menu.drawOn(window);
}

} // namespaxe ks
