#include "menustate.hpp"


namespace ks {

MenuState::MenuState():
    shape(100.f) {
    shape.setFillColor(sf::Color::Green);
}

MenuState::Transition MenuState::process(const sf::Event& event) {
    return Transition::Stay;
}

void MenuState::drawOn(sf::RenderWindow& window) const {
    window.draw(shape);
}

}
