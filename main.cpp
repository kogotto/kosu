#include <SFML/Graphics.hpp>

#include "machine.hpp"

int main()
{
    sf::sleep(sf::milliseconds(100));

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        return 666;
    }

    ks::Machine machine(font);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (machine.process(event) ==
                            ks::Machine::Transition::Exit) {
                window.close();
            }
        }

        window.clear();

        machine.drawOn(window);

        window.display();
    }

    return 0;
}
