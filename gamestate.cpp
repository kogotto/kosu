#include "gamestate.hpp"

namespace ks {

GameState::GameState():
    shape({100, 100}) {
    shape.setFillColor(sf::Color::Blue);
}

GameState::Transition GameState::process(const sf::Event& event) {
    if (event.type == sf::Event::KeyReleased &&
        event.key.code == sf::Keyboard::Escape) {
        return Transition::ToMenu;
    }

    return Transition::Stay;
}

void GameState::drawOn(sf::RenderWindow& window) const {
    window.draw(shape);
}

}
