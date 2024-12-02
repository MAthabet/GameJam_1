#pragma once
#include <SFML/Graphics.hpp>
#include "FallingItem.h"

class Generator
{
public:
	Generator(float interv, std::vector<FallingItem>* items);
	void generate(FallingItem item, float i, float j);

private:
	sf::Clock clock;
	float coolDowmInterval;
};

