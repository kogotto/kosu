#include <SFML/Graphics.hpp>

#include "machine.hpp"

int main()
{
    sf::sleep(sf::milliseconds(100));

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

    ks::Machine machine;

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
