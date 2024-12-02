#include "GeneratorManager.h"

Generator::Generator(float interv, std::vector<FallingItem>* items)
{
	clock.restart();
	coolDowmInterval = interv;
}

void Generator::generate(FallingItem item, float i, float j)
{
	if (clock.getElapsedTime().asSeconds() > coolDowmInterval)
	{
		item.particle->setPosition(i,j);
		clock.restart();
	}
}
