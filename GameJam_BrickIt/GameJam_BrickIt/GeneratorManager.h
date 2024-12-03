#pragma once
#include <SFML/Graphics.hpp>
#include "FallingItem.h"


class Generator
{
public:
	std::vector<FallingItem> items;
	Generator(float interv);
	void generate(sf::Texture* spritesheet);
    void generate(int asset, sf::Texture* spritesheet);

private:
	sf::Clock clock;
	float coolDowmInterval;

};

