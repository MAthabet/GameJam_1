#pragma once
enum ItemType {
	healthy, junk
};
const unsigned int WINDOW_WIDTH = 800;
const unsigned int WINDOW_HEIGHT = 600;
const float PLATFORM_POSITION = WINDOW_HEIGHT - 10;
const float FALLING_ITEM_STARTING_POSITION_Y = -1.f;
const float CURSOR_ROTATION = -28.5;
const float FOOD_COOLDOWN = 1.5f;

const float PLAYER_SPEED = 100;
const float FPS = 60;
const float FALLING_SPEED = 10;
static bool flag = false;