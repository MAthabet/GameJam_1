#include "Player.h"

void Player::move(float dt, int dir)
{
    frame.move(dir * PLAYER_SPEED * dt, 0);
    sf::Vector2f playerPos = frame.getPosition();
    playerPos.x = std::max(0.f, std::min(playerPos.x, BG_W - frame.getSize().x));
    frame.setPosition(playerPos);
    updateCollider(frame.getPosition());
}

bool Player::handleInput()
{
    if (isTripped)
    {
        return invertInput();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
		move(1 / FPS, 1);
        isFlibbed = true;
        return true;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
		move(1 / FPS, -1);
        isFlibbed = false;
        return true;
    }
    return false;
}

bool Player::invertInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        move(1 / FPS, -1);
        isFlibbed = false;
        return true;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
		move(1 / FPS, 1);
        isFlibbed = true;
        return true;
    }
    return false;
}

void Player::updateCollider(sf::Vector2f pos)
{
	collider.updatePosition(Vector2d(pos.x,pos.y));
}

