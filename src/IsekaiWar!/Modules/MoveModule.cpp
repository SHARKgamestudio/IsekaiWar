#include "MoveModule.h"

MoveModule::MoveModule(sf::Vector2f direction, float speed) {
	SetDirection(direction);
	SetSpeed(speed);
}

void MoveModule::SetDirection(sf::Vector2f direction) {
	this->direction = direction;
	float normalCoeff = sqrt(direction.x * direction.x + direction.y * direction.y);
	normalisedDirection = sf::Vector2f(direction.x / normalCoeff, direction.y / normalCoeff);
}

void MoveModule::SetSpeed(float speed) {
	this->speed = speed;
}