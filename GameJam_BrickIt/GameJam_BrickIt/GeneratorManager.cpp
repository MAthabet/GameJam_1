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
		int i = Shroom;
		int x = rand() % 801 + 200;
		sf::Sprite sprite(*spritesheet, rectsData[i]);
        ItemType a;
        if (i < 3) a = junk;
        else if (i < 6) a = healthy;
        else a = shroom;
		items.push_back(FallingItem(a, sprite));
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

void Generator::generate(int asset, sf::Texture* spritesheet)
{
    if (clock.getElapsedTime().asSeconds() > coolDowmInterval)
    {
        int x = rand() % 801 + 200;
        sf::Sprite sprite(*spritesheet, rectsData[asset]);
        ItemType a;
        if (asset < 3) a = junk;
        else if (asset < 6) a = healthy;
        else a = shroom;
        items.push_back(FallingItem(a, sprite));
        items[items.size() - 1].sprite.setOrigin(rectsData[asset].width, rectsData[asset].height);

        items[items.size() - 1].moveTo(Vector2d(x, -32));
        sprite = items[items.size() - 1].sprite;
        items[items.size() - 1].particle.collider.initCollider
        (
            Vector2d(sprite.getPosition().x - rectsData[asset].width, sprite.getPosition().y - rectsData[asset].height),
            Vector2d(sprite.getPosition().x, sprite.getPosition().y)
        );
        clock.restart();
    }
}
