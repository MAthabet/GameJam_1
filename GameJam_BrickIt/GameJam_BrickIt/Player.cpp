#include "Player.h"

void Player::move(float dt, int dir)
{
	position.x = position.x + (dt * dir);
	position.y = position.y;
	shape.setPosition(position);
}



void Player::updateHealth(bool isCollided) {
	if (isCollided) {
		if (health > 0) {

			health -= 1;
		}
		else {
			died = true;
		}
	}
}

bool Player::isFlipping(int dir)
{
	if (dir == 1) {
		return false;
	}
	else
	{
		return true;
	}
}
