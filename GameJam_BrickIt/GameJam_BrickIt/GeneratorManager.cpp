#include "GeneratorManager.h"
#include "Assets.h"
Generator::Generator(float interv)
{
	clock.restart();
	coolDowmInterval = interv;
}

void Generator::generate(sf::Texture* spritesheet)
{
	if (clock.getElapsedTime().asSeconds() > coolDowmInterval)
	{
		int i = rand() % 10;
		int x = rand() % WINDOW_WIDTH;
		sf::Sprite sprite(*spritesheet, rectsData[i]);
		items.push_back(FallingItem(ItemType(i%2), sprite));
		items[items.size() - 1].sprite.setOrigin(rectsData[i].width,rectsData[i].height);

		items[items.size() - 1].moveTo(Vector2d(x,-32));
		sprite = items[items.size() - 1].sprite;
		items[items.size() - 1].particle.collider.initCollider
		(
			Vector2d(sprite.getPosition().x - rectsData[i].width, sprite.getPosition().y - rectsData[i].height),
			Vector2d(sprite.getPosition().x, sprite.getPosition().y)
		);
		clock.restart();
	}
}
