#include "menustate.hpp"


namespace ks {

MenuState::MenuState():
    shape(100.f) {
    shape.setFillColor(sf::Color::Green);
}

MenuState::Transition MenuState::process(const sf::Event& event) {
    if (event.type == sf::Event::Closed) {
        return Transition::Exit;
    }
    if (event.type == sf::Event::KeyReleased &&
        event.key.code == sf::Keyboard::Escape) {
        return Transition::Exit;
    }

    if (event.type == sf::Event::KeyReleased &&
        event.key.code == sf::Keyboard::Enter) {
        return Transition::ToGame;
    }

    return Transition::Stay;
}

void MenuState::drawOn(sf::RenderWindow& window) const {
    window.draw(shape);
}

}
