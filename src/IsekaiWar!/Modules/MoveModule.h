#pragma once

#pragma region External Dependencies

#include <SFML/Graphics.hpp>

#pragma endregion

class MoveModule {
protected:
	sf::Vector2f direction;
	sf::Vector2f normalisedDirection;
	float speed;

	MoveModule(sf::Vector2f direction, float speed);

	void virtual SetDirection(sf::Vector2f direction);
	void virtual SetSpeed(float speed);
	void virtual Move(float deltaTime) = 0;
};