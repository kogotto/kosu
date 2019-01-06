#include "gamestate.hpp"

namespace ks {

namespace {

inline  models::Board getDefaultBoard() noexcept {
    return {{
        {{6, 0, 0, 0, 0, 3, 0, 0, 4}},
        {{0, 0, 7, 0, 9, 0, 6, 0, 0}},
        {{4, 0, 0, 0, 6, 0, 1, 0, 0}},
        {{0, 1, 8, 7, 0, 0, 0, 4, 0}},
        {{0, 3, 0, 9, 0, 6, 0, 8, 0}},
        {{0, 4, 0, 0, 0, 8, 7, 9, 0}},
        {{0, 0, 9, 0, 8, 0, 0, 0, 3}},
        {{0, 0, 4, 0, 2, 0, 5, 0, 0}},
        {{5, 0, 0, 3, 0, 0, 0, 0, 8}}
    }};
}

}

GameState::GameState(const sf::Font& font):
    boardView_({0, 0}, {180, 180}, font) {}

void GameState::startNewGame() {
    boardModel_.emplace(getDefaultBoard());
}

GameState::Transition GameState::process(const sf::Event& event) {
    if (event.type == sf::Event::KeyReleased &&
        event.key.code == sf::Keyboard::Escape) {
        boardModel_.reset();
        return Transition::ToMenu;
    }

    return Transition::Stay;
}

void GameState::drawOn(sf::RenderWindow& window) const {
    boardView_.drawOn(window, *boardModel_);
}

}
