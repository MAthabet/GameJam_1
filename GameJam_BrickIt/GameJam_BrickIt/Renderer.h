#pragma once
#include <SFML/Graphics.hpp>
#include "FallingItem.h"

class Renderer
{
private:
	std::vector<FallingItem>* items;
public:
	Renderer(std::vector<FallingItem>* items);
	//void AddDrawable(sf::Sprite* sprite);
	void Render(sf::RenderWindow* window);
};
