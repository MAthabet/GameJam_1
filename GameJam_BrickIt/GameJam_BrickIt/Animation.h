#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Animation
{
public:
	void Update(int row, float deltaTime);

	sf::IntRect uvRect;
    Animation();
	Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
    void updateAnimation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);

private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;
};

