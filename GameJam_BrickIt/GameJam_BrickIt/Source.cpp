#include <SFML/Graphics.hpp>
#include "FallingItem.h"
#include "Constants.h"
#include "Player.h"
#include "MainMenu.h"
#include "Game.h"
#include <SFML/Audio.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Main Menu");
    window.setFramerateLimit(FPS);
    sf::View defView = window.getDefaultView();
    MainMenu mainMenu;
    mainMenu.start();

    sf::SoundBuffer buffer;

            
    buffer.loadFromFile("./resources/Audio/loop.mp3");
    sf::Sound loop;
    loop.setBuffer(buffer);
    loop.setLoop(true);
    loop.play();
    loop.setVolume(50);
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
        {
            isGameRunning = game.run(&window);
            if (isGameRunning == false)
            {
                mainMenu.gameOver(&window, &defView);
            }
        }
        else
            isGameRunning = mainMenu.loop(&window);
    }
    return 0;
}
