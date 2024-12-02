#include "MainMenu.h"

void MainMenu::start()
{
    if (!mainMenuTex.loadFromFile("./resources/MainMenu.png")) {
        printf("MainMenu.png can not be loaded");
        close();
        return;
    }
    if (!cursorTex.loadFromFile("./resources/Cursor.png")) {
        printf("Cursor.png can not be loaded");
        close();
        return;
    }
    mainMenu.setTexture(mainMenuTex);
    cursor.setTexture(cursorTex);
    mainMenu.setPosition(0,0);
    cursor.setRotation(CURSOR_ROTATION);
}

void MainMenu::loop(sf::RenderWindow* win)
{
    cursor.setPosition(sf::Mouse::getPosition(*win).x, sf::Mouse::getPosition(*win).y);

}

void MainMenu::close()
{
}

void MainMenu::draw(sf::RenderWindow* win)
{
    win->draw(mainMenu);
    win->draw(cursor);
}

MainMenu::~MainMenu()
{
}
