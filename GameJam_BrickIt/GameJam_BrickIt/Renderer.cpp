#include "Renderer.h"

Renderer::Renderer(std::vector<FallingItem>* items)
{
	this->items = items;
}

//void Renderer::AddDrawable(sf::Sprite* drawable)
//{
//	drawables.push_back(drawable);
//}

void Renderer::Render(sf::RenderWindow* window)
{
	for (FallingItem item : *items)
	{
		window->draw(item.sprite);
	}
}
