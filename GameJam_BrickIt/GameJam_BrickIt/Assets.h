#pragma once
#include <SFML/Graphics.hpp>

enum Assets
{
    h1, junk1, h2, j2, h3, j3, h4, j4, h5, j5
};

const float PIXIL_L = 32;
const float PLAYER_W = 26;
const float PLAYER_H = 39;

const sf::IntRect rectsData[] =
{
sf::IntRect(4 * PIXIL_L, 3 * PIXIL_L, PIXIL_L, PIXIL_L),
sf::IntRect(1 * PIXIL_L, 3 * PIXIL_L, PIXIL_L, PIXIL_L),
sf::IntRect(3 * PIXIL_L, 3 * PIXIL_L, PIXIL_L, PIXIL_L),
sf::IntRect(2 * PIXIL_L, 3 * PIXIL_L, PIXIL_L, PIXIL_L),
sf::IntRect(5 * PIXIL_L, 3 * PIXIL_L, PIXIL_L, PIXIL_L),

sf::IntRect(10 * PIXIL_L, 2 * PIXIL_L, PIXIL_L, PIXIL_L),
sf::IntRect(9 * PIXIL_L, 2 * PIXIL_L, PIXIL_L, PIXIL_L),
sf::IntRect(8 * PIXIL_L, 2 * PIXIL_L, PIXIL_L, PIXIL_L),
sf::IntRect(7 * PIXIL_L, 2 * PIXIL_L, PIXIL_L, PIXIL_L),
sf::IntRect(12 * PIXIL_L, 0 * PIXIL_L, PIXIL_L, PIXIL_L)
};