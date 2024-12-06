#include "MainMenu.h"
#include "shop.cpp"

#include <SFML/Audio.hpp>
void MainMenu::start()
{
    if (!mainMenuTex.loadFromFile("./resources/MainMenu.png")) {
        printf("MainMenu.png can not be loaded");
        return;
    }
    if (!cursorTex.loadFromFile("./resources/Cursor.png")) {
        printf("Cursor.png can not be loaded");
        return;
    }
    mainMenu.setTexture(mainMenuTex);
    mainMenu.setPosition(0,0);

    cursor.setTexture(cursorTex);
    cursor.setScale(2,2);
    cursor.setRotation(CURSOR_ROTATION);
    cursor.setOrigin(2,2);

    idle.loadFromFile("./resources/Sheets/idle_mm.png");

    frame = sf::RectangleShape(sf::Vector2f(idle.getSize().x / 4, idle.getSize().y / 1));

    idleAnim.updateAnimation(&idle, sf::Vector2u(4, 1), 0.2 * 1.5);

    frame.setTexture(&idle);
}

bool MainMenu::loop(sf::RenderWindow* win)
{
    cursor.setPosition(sf::Mouse::getPosition(*win).x-40, sf::Mouse::getPosition(*win).y+5);
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2i pixelPos = sf::Mouse::getPosition(*win);
        sf::Vector2f localPos = win->mapPixelToCoords(pixelPos);
        switch (buttonIsPressed(localPos))
        {
        case Start:
            return true;
        case Shop:
            renderShop(*win, shopImagePath, coinsFile);
            break;
        case Exit:
            close(win);
            return false;
        default:
            break;

        }
    }
    idleAnim.Update(0, 1.0f / FPS);
    frame.setTextureRect(idleAnim.uvRect);
    frame.setPosition(500, 150);
    frame.setScale(2.5, 2.4);
    win->clear();
    draw(win);
    win->display();

    return false;
}

void MainMenu::close(sf::RenderWindow* win)
{
    win->close();
    //this->~MainMenu();
}

bool MainMenu::gameOver(sf::RenderWindow* win, sf::View* defView)
{
    sf::SoundBuffer buffer;
    buffer.loadFromFile("./resources/Audio/gameOver.mp3");
    sf::Sound gameover;
    gameover.setBuffer(buffer);

    gameover.play();

    win->setView(*defView);
    sf::Texture gameOver;
    if (!gameOver.loadFromFile(gameOver_path)) 
    {
        printf("can not load gameOver sheet");
    }
    sf::Sprite gameoverWin(gameOver);
    gameoverWin.setTexture(gameOver);
    gameoverWin.setPosition(0, 0);
    
    while (win->isOpen())
    {
        // Check for all window events
        sf::Event event;
        while (win->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                win->close();
            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    flag = !flag;
                    win->setMouseCursorVisible(flag);
                    win->setMouseCursorGrabbed(!flag);
                }
            }
        }
        cursor.setPosition(sf::Mouse::getPosition(*win).x, sf::Mouse::getPosition(*win).y);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i pixelPos = sf::Mouse::getPosition(*win);
            sf::Vector2f localPos = win->mapPixelToCoords(pixelPos);
            switch (buttonIsPressed(localPos, true))
            {
            case Start:
                return true;
            case Exit:
                return false;
            default:
                break;
            }
        }
        win->clear();
        win->draw(gameoverWin);
        win->draw(cursor);
        win->display();
    }
}

void MainMenu::draw(sf::RenderWindow* win)
{
    win->draw(mainMenu);
    win->draw(frame);
    win->draw(cursor);
}

MainMenu::~MainMenu()
{

}

Buttons MainMenu::buttonIsPressed(sf::Vector2f clkPos)
{
    if (clkPos.x >= MIN_X && clkPos.x <= MAX_X)
    {
        for (int i = 0; i < Buttons::None; i++)
        {
            if (clkPos.y >= BUTTONS_Y[i] && clkPos.y <= BUTTONS_Y[i] + BUTTON_H)
                return (Buttons)i;
        }
    }
    return None;
}
Buttons MainMenu::buttonIsPressed(sf::Vector2f clkPos, bool a)
{
    if (clkPos.y >= MIN_Y && clkPos.y <= MAX_Y)
    {
        for (int i = 0; i < 2; i++)
        {
            if (clkPos.x >= BUTTONS_X[i] && clkPos.x <= BUTTONS_X[i] + BUTTON_W)
                return i > 0 ? (Buttons)2 : (Buttons)0;
        }
    }
    return None;
}
