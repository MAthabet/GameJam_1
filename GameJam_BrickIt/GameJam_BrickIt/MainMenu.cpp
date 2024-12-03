#include "MainMenu.h"

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
}

bool MainMenu::loop(sf::RenderWindow* win)
{
    cursor.setPosition(sf::Mouse::getPosition(*win).x, sf::Mouse::getPosition(*win).y);
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2i pixelPos = sf::Mouse::getPosition(*win);
        sf::Vector2f localPos = win->mapPixelToCoords(pixelPos);
        switch (buttonIsPressed(localPos))
        {
        case Start:
            return true;
        case Shop:
            //TODO
            break;
        case Exit:
            close(win);
            return false;
        default:
            break;

        }
    }
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

void MainMenu::draw(sf::RenderWindow* win)
{
    win->draw(mainMenu);
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
