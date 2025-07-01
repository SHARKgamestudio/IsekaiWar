#pragma once

#pragma region External Dependencies

#include <SFML/Graphics.hpp>

#pragma endregion

class TravellingModule {
protected:
	sf::Vector2f direction;
	sf::Vector2f normalisedDirection;
	float u, v;
	float speed;

	TravellingModule(sf::Vector2f direction, float speed);

	void virtual SetDirection(sf::Vector2f direction);
	void virtual SetSpeed(float speed);
	void virtual Traveling(float deltaTime) = 0;
};