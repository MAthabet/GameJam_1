#pragma once
#include <SFML/Graphics.hpp>

enum Assets
{
    Pizza, burger, Hotdog, Carrot, Cucumber, Tomato, Shroom, Hearts, EmpHearts
};

const float PLAYER_W = 32;
const float PLAYER_H = 32;

const sf::IntRect rectsData[] =
{
sf::IntRect(0,   0, 30, 44),
sf::IntRect(30+1,  0, 41, 40),
sf::IntRect(71+2,  0, 37, 36),
sf::IntRect(108+2, 0, 40, 38),
sf::IntRect(148 + 4, 0, 41, 31),
sf::IntRect(189 + 5, 0, 33, 29),
sf::IntRect(222 + 6, 0, 14, 16),
sf::IntRect(236 + 10, 0, 20, 17),
sf::IntRect(256 + 12, 0, 20, 17)
};