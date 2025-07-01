#pragma once

#pragma region Local Dependencies

#include "CollidableEntity.h"
#include "../Modules/MoveModule.h"

#pragma endregion

class PowerUpEntity : public CollidableEntity, public MoveModule {
public:
	PowerUpEntity(float x, float y, sf::Texture* texture, int columns, int rows, float radius, float attack, sf::Vector2f direction, float speed);
	PowerUpEntity(sf::Vector2f position, sf::Texture* texture, sf::Vector2i split, float radius, float attack, sf::Vector2f direction, float speed);

	void virtual Move(float deltaTime);
	void virtual Spawn();
	void virtual Action() = 0;
	void UpdateLogic(float deltaTime) override;
};