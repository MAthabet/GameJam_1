#include "FallingItem.h"


FallingItem::FallingItem(ItemType type, sf::Sprite sprite)
	: objType(type), sprite(sprite) {}

void FallingItem::update(float deltaTime)
{
	particle.Update(deltaTime);
	sprite.setPosition(particle.postion);
}

void FallingItem::moveTo(Vector2d a)
{
	particle.moveTo(a);
	sprite.setPosition(particle.postion);
}

FallingItem::~FallingItem()
{
}

