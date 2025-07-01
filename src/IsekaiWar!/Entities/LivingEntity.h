#pragma once

#pragma region Local Dependencies

#include "CollidableEntity.h"
#include "../Modules/HealthModule.h"

#pragma endregion

class LivingEntity : public CollidableEntity, public HealthModule {
public:
	LivingEntity(float x, float y, sf::Texture* texture, int columns = 1, int rows = 1, float radius = 8, float health = 1);
	LivingEntity(sf::Vector2f position, sf::Texture* texture, sf::Vector2i split = sf::Vector2i(1, 1), float radius = 8, float health = 1);

	void virtual UpdateLogic(float deltaTime) override;
};