#pragma once

#pragma region External Dependencies

#include <SFML/Graphics.hpp>

#pragma endregion

#pragma region Local Dependencies

#include "../Entity.h"
#include "../Modules/HitboxModule.h"

#pragma endregion

class CollidableEntity : public Entity, public HitboxModule {
public:
	CollidableEntity(float x, float y, sf::Texture* texture, int columns = 1, int rows = 1, float radius = 8);
	CollidableEntity(sf::Vector2f position, sf::Texture* texture, sf::Vector2i split = sf::Vector2i(1, 1), float radius = 8);
	void virtual UpdateLogic(float deltaTime) override;
	void virtual draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};