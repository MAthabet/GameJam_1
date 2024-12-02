#include <SFML/Graphics.hpp>
#include "FallingItem.h"
#include "Constants.h"
#include "Player.h"
#include "MainMenu.h"
int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Main Window");
    window.setFramerateLimit(60);
    sf::Clock clock;
    float deltaTime;
   
    MainMenu mainMenu;
    mainMenu.start();
    bool flag = false;
    window.setMouseCursorVisible(flag);
    window.setMouseCursorGrabbed(!flag);
    sf::Vector2i clkPos;
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
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                clkPos = sf::Mouse::getPosition(window);
            }
        }
        mainMenu.loop(&window);
        //TODO
        deltaTime = clock.restart().asSeconds();
        
        window.clear();

        mainMenu.draw(&window);

        window.display();
    }
    return 0;
}

//int main()
//{
//    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Main Window");
//    window.setFramerateLimit(60);
//    sf::Clock clock;
//    float deltaTime;
//    // Load the sprite sheet
//    FallingItem testObj(ItemType::junk, 100, 100);
//    Player player;
//    player.initVariables();
//    // Run the program as long as the window is open
//    while (window.isOpen())
//    {
//        // Check for all window events
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//        //TODO
//        deltaTime = clock.restart().asSeconds();
//        player.move(deltaTime,-10);
//        window.clear();
//        window.draw(player.shape);
//        testObj.draw(window, deltaTime);
//        window.display();
//    }
//    //start
//    //loop
//    //game loop
//
//    return 0;
//}