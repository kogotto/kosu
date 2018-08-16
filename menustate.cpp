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

    if (event.type == sf::Event::KeyReleased) {
        return processKeyRelease(event.key);
    }

    return Transition::Stay;
}

void MenuState::drawOn(sf::RenderWindow& window) const {
    window.draw(shape);
}

MenuState::Transition MenuState::processKeyRelease(
        const sf::Event::KeyEvent& key) {
    if (key.code == sf::Keyboard::Escape) {
        return Transition::Exit;
    }
    if (key.code == sf::Keyboard::Enter) {
        return Transition::ToGame;
    }
    return Transition::Stay;
}

}
