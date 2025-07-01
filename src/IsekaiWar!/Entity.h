#pragma once

#pragma region External Dependencies

#include <SFML/Graphics.hpp>
#include "Rendering/Spritesheet.h"

#pragma endregion

class Entity : public sf::Transformable, public sf::Drawable {
protected:
	Spritesheet spritesheet;
	bool toDisable;
	bool toDestroy;

public:
	Entity(float x, float y, sf::Texture* texture, int columns = 1, int rows = 1);
	Entity(sf::Vector2f position, sf::Texture* texture, sf::Vector2i split = sf::Vector2i(1, 1));
	
	
	void virtual Die();
	bool ToDestroy();
	void virtual UpdateLogic(float deltaTime);
	void virtual draw(sf::RenderTarget& target, sf::RenderStates states) const;
};