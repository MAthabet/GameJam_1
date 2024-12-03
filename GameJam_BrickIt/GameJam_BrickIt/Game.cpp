#include "Game.h"
#include "GeneratorManager.h"
#include "CollisionManager.h"
#include "Player.h"
#include "Renderer.h"
#include "FallingItem.h"
#include "Animation.h"

#include "Constants.h"
#include "Assets.h"

//for debugging
void drawAABB(sf::RenderWindow& window, const sf::Vector2f& ul, const sf::Vector2f& lr) {
    sf::Vector2f size(lr.x - ul.x, lr.y - ul.y);

    sf::RectangleShape rectangle(size);
    rectangle.setPosition(ul);
    rectangle.setFillColor(sf::Color::Transparent);
    rectangle.setOutlineColor(sf::Color::Red);
    rectangle.setOutlineThickness(1.f);

    window.draw(rectangle);
}

bool Game::run(sf::RenderWindow* win)
{
	init(win);
	loop(win);
	end(win);
    return false;
}

void Game::init(sf::RenderWindow* win)
{
	win->setTitle("Game");
}

void Game::loop(sf::RenderWindow* win)
{
	srand(time(0));
	Generator generator(FOOD_COOLDOWN);
	CollisionManager collisionMngr(&generator.items);
	Renderer renderer(&generator.items);

    Player player;
    sf::Texture idle;
    if (!idle.loadFromFile("./resources/idle.png")) {
        printf("can not load animation sheet");
    }
    player.frame = sf::RectangleShape (sf::Vector2f(idle.getSize().x / 3, idle.getSize().y / 1));
    player.frame.setTexture(&idle);
    
    player.frame.setOrigin(player.frame.getSize().x, player.frame.getSize().y);
    player.frame.setPosition(WINDOW_WIDTH/2-PLAYER_W/2, PLATFORM_POSITION);

    player.collider.initCollider
    (
        Vector2d(130, 450),
        Vector2d(130+PLAYER_W*3, 450+PLAYER_H*3)
    );

    player.collider.position = Vector2d(player.frame.getPosition().x, player.frame.getPosition().y);
    //player.updateCollider(player.frame.getPosition());

    Animation idleANim (&idle, sf::Vector2u(3, 1), 1/FPS);
    float deltaTime;
    sf::Clock clock;
    sf::Texture BG;
    if (!BG.loadFromFile("./resources/bg.png")) { 
        printf("can not load bg.png");
    }
    sf::Sprite backGround(BG);
    sf::Texture spritesheet;
    if (!spritesheet.loadFromFile("./resources/sprites.png")) {
        printf("can not load sprites.png");
    }

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
        
        generator.generate(&spritesheet);

        player.handleInput();
        idleANim.Update(0, 1.0f/FPS);
        player.frame.setTextureRect(idleANim.uvRect);
        collisionMngr.Update(1/FPS);
        switch (collisionMngr.checkCollisionWith(&player.collider))
        {
        case healthy:
            player.score += 10;
            break;
        case junk:
            player.health--;;
            break;
        }
        if (player.health < 1)
            break;
        win->clear();
        win->draw(backGround);
        renderer.Render(win);
        //to be deleted
        drawAABB(*win, player.collider.ul, player.collider.lr);
        player.frame.setScale(3,3);
        win->draw(player.frame);
        win->display();
    }
}

void Game::end(sf::RenderWindow* win)
{
   
}

void Game::draw(sf::RenderWindow* win)
{
}

