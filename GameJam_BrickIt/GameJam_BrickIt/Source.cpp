#include <SFML/Graphics.hpp>
#include "FallingItem.h"
#include "Constants.h"
#include "Player.h"
#include "MainMenu.h"
#include "Game.h"
int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Main Menu");
    window.setFramerateLimit(FPS);
    MainMenu mainMenu;
    mainMenu.start();

    window.setMouseCursorVisible(flag);
    window.setMouseCursorGrabbed(!flag);

    bool isGameRunning = false;
    Game game;
    while (window.isOpen())
    {
        // Check for all window events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    flag = !flag;
                    window.setMouseCursorVisible(flag);
                    window.setMouseCursorGrabbed(!flag);
                }
            }
        }
        if (isGameRunning)
            isGameRunning = game.run(&window);
        else
            isGameRunning = mainMenu.loop(&window);
                
    }
    return 0;
}
