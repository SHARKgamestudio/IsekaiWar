#include "TravellingModule.h"

#pragma region External Dependencies

#include <math.h>

#pragma endregion

TravellingModule::TravellingModule(sf::Vector2f direction, float speed) {
	SetDirection(direction);
	SetSpeed(speed);

	u = 0; v = 0;
}

void TravellingModule::SetDirection(sf::Vector2f direction) {
	this->direction = direction;

	float normalCoeff = sqrt(direction.x * direction.x + direction.y * direction.y);
	normalisedDirection = sf::Vector2f(direction.x / normalCoeff, direction.y / normalCoeff);
}

void TravellingModule::SetSpeed(float speed) {
	this->speed = speed;
}