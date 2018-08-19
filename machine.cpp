#include "machine.hpp"
#include <cassert>

namespace ks {

Machine::Machine(const sf::Font& font):
    game(font) {}

Machine::Transition Machine::process(const sf::Event& event) {
    switch (currentState) {
    case state::menu:
        switch (menu.process(event)) {
        case MenuState::Transition::Stay:
            return Transition::Stay;
        case MenuState::Transition::ToGame:
            game.startNewGame();
            currentState = state::game;
            return Transition::Stay;
        case MenuState::Transition::Exit:
            return Transition::Exit;
        default:
            assert(false && "unknown MenuState::Transition");
        }
    case state::game:
        switch (game.process(event)) {
        case GameState::Transition::Stay:
            return Transition::Stay;
        case GameState::Transition::ToMenu:
            currentState = state::menu;
            return Transition::Stay;
        default:
            assert(false && "unknown GameState::Transition");
        }
    default:
        assert(false && "unknown state");
    }

}

void Machine::drawOn(sf::RenderWindow& window) const {
    switch (currentState) {
        case state::menu:
            menu.drawOn(window);
            break;
        case state::game:
            game.drawOn(window);
            break;
        default:
            assert(false && "unknown state");
    }
}

} // namespaxe ks
