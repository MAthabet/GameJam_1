#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600), "Main Window");
    window.setFramerateLimit(60);
    // Load the sprite sheet

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
        window.clear();
    }

    return 0;
}