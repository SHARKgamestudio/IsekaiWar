#pragma once

#pragma region Local Dependencies

#include "CollidableEntity.h"
#include "../Modules/AttackModule.h"
#include "../Modules/MoveModule.h"

#pragma endregion

class BulletEntity : public CollidableEntity, public AttackModule, public MoveModule {
public:
	BulletEntity(float x, float y, sf::Texture* texture, int columns, int rows, float radius, float attack, sf::Vector2f direction, float speed);
	BulletEntity(sf::Vector2f position, sf::Texture* texture, sf::Vector2i split, float radius, float attack, sf::Vector2f direction, float speed);

	void Move(float deltaTime);
	void virtual Spawn() = 0;
	virtual void UpdateLogic(float deltaTime) override;
};