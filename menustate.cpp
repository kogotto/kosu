#include "menustate.hpp"

#include <cassert>

namespace ks {

namespace {

MenuState::Transition toTransition(menu_detail::Item item) {
    switch (item) {
    case menu_detail::Item::NewGame:
        return MenuState::Transition::ToGame;
    case menu_detail::Item::Exit:
        return MenuState::Transition::Exit;
    default:
        assert(false && "unknown menu item");
    }
}

} // namespace

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
    if (key.code == sf::Keyboard::Enter) {
        return toTransition(currentItem);
    }

    if (key.code == sf::Keyboard::Up) {
        currentItem = prev(currentItem);
    }

    if (key.code == sf::Keyboard::Down) {
        currentItem = next(currentItem);
    }
    shape.setFillColor(currentItem == Item::NewGame?
            sf::Color::Green:
            sf::Color::Red);

    return Transition::Stay;
}

}
