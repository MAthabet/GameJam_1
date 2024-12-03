#include "Player.h"

void Player::move(float dt, int dir)
{
	frame.move(dir * PLAYER_SPEED * dt, 0);
	sf::Vector2f playerPos = frame.getPosition();
	//playerPos.x = std::clamp(playerPos.x, 0.0f, BG_W - 26*3);
    playerPos.x = std::max(frame.getSize().x, std::min(playerPos.x, BG_W));
	frame.setPosition(playerPos);
	updateCollider(frame.getPosition());
}

void Player::handleInput()
{
    if (isTripped)
    {
        invertInput();
        return;
    }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		move(1 / FPS, 1);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		move(1 / FPS, -1);
}

void Player::invertInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		move(1 / FPS, -1);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		move(1 / FPS, 1);
}

void Player::updateCollider(sf::Vector2f pos)
{
	collider.updatePosition(Vector2d(pos.x,pos.y));
}

