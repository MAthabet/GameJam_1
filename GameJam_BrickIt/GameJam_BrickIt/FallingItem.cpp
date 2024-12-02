#include "FallingItem.h"

void FallingItem::initVariables() {
	objPositionY = FallingItemStartingPosition_Y;
	particle = nullptr;
	shape.setFillColor(sf::Color::White);
	shape.setPosition(objPositionX, objPositionY);
	shape.setSize(sf::Vector2f(30, 30));
}

FallingItem::FallingItem() {
	initVariables();
}

FallingItem::FallingItem(ItemType type, float X_Position, float speed/*, sf::Sprite* temp*/) {
	initVariables();
	objPositionX = X_Position;
	objType = type;
	//particle = temp;
	this->speed = speed;
}

void FallingItem::setObjPositionX(float x_pos) {
	objPositionX = x_pos;
}

float FallingItem::getObjPositionX() {
	return objPositionX;
}

float FallingItem::getObjPositionY() {
	return objPositionY;
}

bool FallingItem::getDestroyedStatus() const {
	return destroyed;
}

FallingItem::~FallingItem() {
	if (particle) {
		delete particle;
	}
}

void FallingItem::updateObjPosY(float deltaTime) {
	objPositionY += speed * deltaTime;
	//particle->setPosition(objPositionX, objPositionY);
	shape.setPosition(objPositionX, objPositionY);
	std::cout << shape.getPosition().x << ", " << shape.getPosition().y << '\n';
}

void FallingItem::draw(sf::RenderWindow& window, float deltaTime) {
	if (particle) {
	}
	//updateObjPosY(deltaTime);
	window.draw(shape);
}

void FallingItem::checkCollision() {
	if (shape.getPosition().y >= PLATFORM_POSITION) {

	}
}
