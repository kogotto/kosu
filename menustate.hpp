#ifndef MENU_STATE_HPP
#define MENU_STATE_HPP


#include <SFML/Graphics.hpp>


namespace ks {


class MenuState {
public:
    enum class Transition {
        Stay,
        ToGame,
        Exit
    };

    MenuState();

    Transition process(const sf::Event& event);
    void drawOn(sf::RenderWindow& window) const;
private:
    Transition processKeyRelease(const sf::Event::KeyEvent& key);

    sf::CircleShape shape;
};


}
#endif // MENU_STATE_HPP
