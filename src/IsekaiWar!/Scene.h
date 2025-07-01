#pragma once

#pragma region External Dependencies

#include <SFML/Graphics.hpp>

#pragma endregion

class Event;

class Scene {
public:

	void virtual Load();
	void virtual UpdateLogic(float dt);
	void virtual Draw(sf::RenderWindow& window);
};