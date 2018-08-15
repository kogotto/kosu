#include "machine.hpp"

namespace ks {

Machine::Transition Machine::process(const sf::Event& event) {
    switch (menu.process(event)) {
    case MenuState::Transition::Stay:
        // Do nothig;
        break;
    case MenuState::Transition::ToGame:
        // Switch to game, not implemented yet
        break;
    case MenuState::Transition::Exit:
        return Transition::Exit;
    }
    return Transition::Stay;
}

void Machine::drawOn(sf::RenderWindow& window) const {
    menu.drawOn(window);
}

} // namespaxe ks
