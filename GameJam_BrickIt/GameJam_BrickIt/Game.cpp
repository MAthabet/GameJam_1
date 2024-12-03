#include "Game.h"
#include "GeneratorManager.h"
#include "CollisionManager.h"
#include "SFML/Audio.hpp"
#include "Player.h"
#include "Renderer.h"
#include "FallingItem.h"
#include "Animation.h"
#include "appConfjs.h"
#include "Constants.h"
#include "Assets.h"
#include "MainMenu.h"

bool Game::run(sf::RenderWindow* win)
{
    sf::SoundBuffer buffer;
    buffer.loadFromFile("./resources/Audio/gameStart.mp3");
    sf::Sound start;
    start.setBuffer(buffer);
    start.play();
	init(win);
	loop(win);
    if (end(win)) loop(win);
    return false;
}

void Game::init(sf::RenderWindow* win)
{
	win->setTitle("Game");
}

void Game::loop(sf::RenderWindow* win)
{
    sf::View camera(sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));
	srand(time(0));
	Generator generator(FOOD_COOLDOWN);
    Generator shroomGenerator(SHROOM_COOLDOWN);
	CollisionManager collisionMngr(&generator.items);
	Renderer renderer(&generator.items);

    sf::SoundBuffer buffer;
    buffer.loadFromFile("./resources/Audio/Bite.mp3");

    sf::Sound bite;
    bite.setBuffer(buffer);
    bite.setPlayingOffset(sf::seconds(1.2f));
    Player player;

    sf::Texture idle;
    if (!idle.loadFromFile(idle_path)) {
        printf("can not load animation sheet");
    }
    sf::Texture walking;
    if (!walking.loadFromFile(walking_path)) {
        printf("can not load walking animation sheet");
    }
    sf::Texture walkingFlipped;
    if (!walkingFlipped.loadFromFile(walkingFlipped_path)) {
        printf("can not load walking animation sheet");
    }
    sf::Texture idleFlipped;
    if (!idleFlipped.loadFromFile(idleFlipped_path)) {
        printf("can not load walking animation sheet");
    }

    player.frame = sf::RectangleShape (sf::Vector2f(idle.getSize().x / 8, idle.getSize().y / 1));
    player.frame.setTexture(&idle);
    
    player.frame.setOrigin(player.frame.getSize().x, player.frame.getSize().y);
    player.frame.setPosition(WINDOW_WIDTH/2-PLAYER_W/2, PLATFORM_POSITION-180);

    player.collider.initCollider
    (
        Vector2d(440, 500),
        Vector2d(440+PLAYER_W*2.5, 450+PLAYER_H*2.5)
    );

    player.collider.position = Vector2d(player.frame.getPosition().x, player.frame.getPosition().y);
    //player.updateCollider(player.frame.getPosition());

    Animation idleANim (&idle, sf::Vector2u(4, 1), 0.2*1.5);

    Animation walkingAnim(&walking, sf::Vector2u(8, 1), 0.2);

    Animation flipidleANim(&idleFlipped, sf::Vector2u(4, 1), 0.2 * 1.5);

    Animation flipwalkingAnim(&walkingFlipped, sf::Vector2u(8, 1), 0.2);

    float deltaTime;
    sf::Clock clock;
    sf::Texture BG;
    if (!BG.loadFromFile("./resources/bg.png")) { 
        printf("can not load bg.png");
    }
    sf::Sprite backGround(BG);


    sf::Texture spritesheet;
    if (!spritesheet.loadFromFile(spritesheet_path)) {
        printf("can not load sprites.png");
    }
    sf::Sprite empHeart(spritesheet,rectsData[EmpHearts]);
    sf::Sprite heart(spritesheet, rectsData[Hearts]);

    sf::Shader shader;
    if (!shader.loadFromFile("trippy_shader.frag", sf::Shader::Fragment)) {
        printf("can not load trippy_shader.frag");
    }

    sf::Clock tripClk;

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
        
        //shroomGenerator.generate(&spritesheet);
        generator.generate(rand() % 7, &spritesheet);
        shader.setUniform("time", clock.getElapsedTime().asSeconds());

        if (player.handleInput())
        {
                sf::Vector2f pos = player.frame.getPosition();
            if (!player.isFlibbed)
            {
                walkingAnim.Update(0, 1.0f/FPS);
                player.frame = sf::RectangleShape(sf::Vector2f(walking.getSize().x / 8, walking.getSize().y / 1));
                player.frame.setTexture(&walking);
                player.frame.setTextureRect(walkingAnim.uvRect);
                player.frame.setPosition(pos);
            }
            else
            {
                flipwalkingAnim.Update(0, 1.0f / FPS);
                player.frame = sf::RectangleShape(sf::Vector2f(walkingFlipped.getSize().x / 8, walkingFlipped.getSize().y / 1));
                player.frame.setTexture(&walkingFlipped);
                player.frame.setTextureRect(flipwalkingAnim.uvRect);
                player.frame.setPosition(pos);
            }
        }
        else
        {
                sf::Vector2f pos = player.frame.getPosition();
            if (!player.isFlibbed)
            {
                idleANim.Update(0, 1.0f / FPS);
                player.frame = sf::RectangleShape(sf::Vector2f(idle.getSize().x / 4, idle.getSize().y / 1));
                player.frame.setTexture(&idle);
                player.frame.setTextureRect(idleANim.uvRect);
                player.frame.setPosition(pos);
            }
            else
            {
                flipidleANim.Update(0, 1.0f / FPS);
                player.frame = sf::RectangleShape(sf::Vector2f(idleFlipped.getSize().x / 4, idleFlipped.getSize().y / 1));
                player.frame.setTexture(&idleFlipped);
                player.frame.setTextureRect(flipidleANim.uvRect);
                player.frame.setPosition(pos);
            }
        }

        collisionMngr.Update(1/FPS);

        switch (collisionMngr.checkCollisionWith(&player.collider))
        {
        case healthy:
            player.score += 10;
            bite.play();
            break;
        case junk:
            player.health--;
            bite.play();
            break;
        case shroom:
            player.isTripped = true;
            bite.play();
            player.score += 50;
            tripClk.restart();
            break;
        }
        if (player.health < 1)
            break;
        if (player.isTripped)
            if (tripClk.getElapsedTime().asSeconds() > 5)
                player.isTripped = false;
        float playerX = player.collider.lr.x;
        float cameraX = playerX;

        cameraX = std::max(cameraX,  WINDOW_HEIGHT / 2.0f);
        cameraX = std::min(cameraX, BG_W - WINDOW_WIDTH / 2.0f);

        camera.setCenter(cameraX, WINDOW_HEIGHT / 2.0f);
        win->setView(camera);
        win->clear();
        if(player.isTripped)
        win->draw(backGround, &shader);
        else
        win->draw(backGround);
        player.frame.setScale(PLAYER_SCALE, PLAYER_SCALE);
        win->draw(player.frame);
        for (int i = 0; i < player.health; i++)
        {
            win->draw(heart);
            heart.setPosition(0+i*20, 0);
        }
        for (int i = player.health; i < 5; i++)
        {
            empHeart.setPosition(player.health*20 + i * 20, 0);
            win->draw(empHeart);
        }
        renderer.Render(win);
            win->display();
            win->setView(camera);
        if (player.health >= 0)
        {
            return;
        }
    }
}

bool Game::end(sf::RenderWindow* win)
{
    sf::SoundBuffer buffer;
    buffer.loadFromFile("./resources/Audio/gameOver.mp3");
    sf::Sound gameOver;
    gameOver.setBuffer(buffer);

    gameOver.play();
    sf::sleep(sf::milliseconds(3000));
    return false;
}



