#include <SFML/Graphics.hpp>
#include "FallingItem.h"
//#include "Constants.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Main Window");
    window.setFramerateLimit(60);
    sf::Clock clock;
    float deltaTime;
    // Load the sprite sheet
    FallingItem testObj(ItemType::junk, 100, 100);

    // Run the program as long as the window is open
    while (window.isOpen())
    {
        // Check for all window events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
            //TODO
        deltaTime = clock.restart().asSeconds();
        testObj.updateObjPosY(deltaTime);
        window.clear();
        testObj.draw(window, deltaTime);
        window.display();
    }

    return 0;
}